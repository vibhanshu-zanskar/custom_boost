//
// chat_server.cpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <set>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include "chat_message.hpp"

using zr_boost_1_81::asio::ip::tcp;

//----------------------------------------------------------------------

typedef std::deque<chat_message> chat_message_queue;

//----------------------------------------------------------------------

class chat_participant
{
public:
  virtual ~chat_participant() {}
  virtual void deliver(const chat_message& msg) = 0;
};

typedef zr_boost_1_81::shared_ptr<chat_participant> chat_participant_ptr;

//----------------------------------------------------------------------

class chat_room
{
public:
  void join(chat_participant_ptr participant)
  {
    participants_.insert(participant);
    std::for_each(recent_msgs_.begin(), recent_msgs_.end(),
        zr_boost_1_81::bind(&chat_participant::deliver,
          participant, zr_boost_1_81::placeholders::_1));
  }

  void leave(chat_participant_ptr participant)
  {
    participants_.erase(participant);
  }

  void deliver(const chat_message& msg)
  {
    recent_msgs_.push_back(msg);
    while (recent_msgs_.size() > max_recent_msgs)
      recent_msgs_.pop_front();

    std::for_each(participants_.begin(), participants_.end(),
        zr_boost_1_81::bind(&chat_participant::deliver,
          zr_boost_1_81::placeholders::_1, zr_boost_1_81::ref(msg)));
  }

private:
  std::set<chat_participant_ptr> participants_;
  enum { max_recent_msgs = 100 };
  chat_message_queue recent_msgs_;
};

//----------------------------------------------------------------------

class chat_session
  : public chat_participant,
    public zr_boost_1_81::enable_shared_from_this<chat_session>
{
public:
  chat_session(zr_boost_1_81::asio::io_context& io_context, chat_room& room)
    : socket_(io_context),
      room_(room)
  {
  }

  tcp::socket& socket()
  {
    return socket_;
  }

  void start()
  {
    room_.join(shared_from_this());
    zr_boost_1_81::asio::async_read(socket_,
        zr_boost_1_81::asio::buffer(read_msg_.data(), chat_message::header_length),
        zr_boost_1_81::bind(
          &chat_session::handle_read_header, shared_from_this(),
          zr_boost_1_81::asio::placeholders::error));
  }

  void deliver(const chat_message& msg)
  {
    bool write_in_progress = !write_msgs_.empty();
    write_msgs_.push_back(msg);
    if (!write_in_progress)
    {
      zr_boost_1_81::asio::async_write(socket_,
          zr_boost_1_81::asio::buffer(write_msgs_.front().data(),
            write_msgs_.front().length()),
          zr_boost_1_81::bind(&chat_session::handle_write, shared_from_this(),
            zr_boost_1_81::asio::placeholders::error));
    }
  }

  void handle_read_header(const zr_boost_1_81::system::error_code& error)
  {
    if (!error && read_msg_.decode_header())
    {
      zr_boost_1_81::asio::async_read(socket_,
          zr_boost_1_81::asio::buffer(read_msg_.body(), read_msg_.body_length()),
          zr_boost_1_81::bind(&chat_session::handle_read_body, shared_from_this(),
            zr_boost_1_81::asio::placeholders::error));
    }
    else
    {
      room_.leave(shared_from_this());
    }
  }

  void handle_read_body(const zr_boost_1_81::system::error_code& error)
  {
    if (!error)
    {
      room_.deliver(read_msg_);
      zr_boost_1_81::asio::async_read(socket_,
          zr_boost_1_81::asio::buffer(read_msg_.data(), chat_message::header_length),
          zr_boost_1_81::bind(&chat_session::handle_read_header, shared_from_this(),
            zr_boost_1_81::asio::placeholders::error));
    }
    else
    {
      room_.leave(shared_from_this());
    }
  }

  void handle_write(const zr_boost_1_81::system::error_code& error)
  {
    if (!error)
    {
      write_msgs_.pop_front();
      if (!write_msgs_.empty())
      {
        zr_boost_1_81::asio::async_write(socket_,
            zr_boost_1_81::asio::buffer(write_msgs_.front().data(),
              write_msgs_.front().length()),
            zr_boost_1_81::bind(&chat_session::handle_write, shared_from_this(),
              zr_boost_1_81::asio::placeholders::error));
      }
    }
    else
    {
      room_.leave(shared_from_this());
    }
  }

private:
  tcp::socket socket_;
  chat_room& room_;
  chat_message read_msg_;
  chat_message_queue write_msgs_;
};

typedef zr_boost_1_81::shared_ptr<chat_session> chat_session_ptr;

//----------------------------------------------------------------------

class chat_server
{
public:
  chat_server(zr_boost_1_81::asio::io_context& io_context,
      const tcp::endpoint& endpoint)
    : io_context_(io_context),
      acceptor_(io_context, endpoint)
  {
    start_accept();
  }

  void start_accept()
  {
    chat_session_ptr new_session(new chat_session(io_context_, room_));
    acceptor_.async_accept(new_session->socket(),
        zr_boost_1_81::bind(&chat_server::handle_accept, this, new_session,
          zr_boost_1_81::asio::placeholders::error));
  }

  void handle_accept(chat_session_ptr session,
      const zr_boost_1_81::system::error_code& error)
  {
    if (!error)
    {
      session->start();
    }

    start_accept();
  }

private:
  zr_boost_1_81::asio::io_context& io_context_;
  tcp::acceptor acceptor_;
  chat_room room_;
};

typedef zr_boost_1_81::shared_ptr<chat_server> chat_server_ptr;
typedef std::list<chat_server_ptr> chat_server_list;

//----------------------------------------------------------------------

int main(int argc, char* argv[])
{
  try
  {
    if (argc < 2)
    {
      std::cerr << "Usage: chat_server <port> [<port> ...]\n";
      return 1;
    }

    zr_boost_1_81::asio::io_context io_context;

    chat_server_list servers;
    for (int i = 1; i < argc; ++i)
    {
      using namespace std; // For atoi.
      tcp::endpoint endpoint(tcp::v4(), atoi(argv[i]));
      chat_server_ptr server(new chat_server(io_context, endpoint));
      servers.push_back(server);
    }

    io_context.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}
