//
// chat_client.cpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdlib>
#include <deque>
#include <iostream>
#include <boost/bind/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include "chat_message.hpp"

using zr_boost_1_81::asio::ip::tcp;

typedef std::deque<chat_message> chat_message_queue;

class chat_client
{
public:
  chat_client(zr_boost_1_81::asio::io_context& io_context,
      const tcp::resolver::results_type& endpoints)
    : io_context_(io_context),
      socket_(io_context)
  {
    zr_boost_1_81::asio::async_connect(socket_, endpoints,
        zr_boost_1_81::bind(&chat_client::handle_connect, this,
          zr_boost_1_81::asio::placeholders::error));
  }

  void write(const chat_message& msg)
  {
    zr_boost_1_81::asio::post(io_context_,
        zr_boost_1_81::bind(&chat_client::do_write, this, msg));
  }

  void close()
  {
    zr_boost_1_81::asio::post(io_context_,
        zr_boost_1_81::bind(&chat_client::do_close, this));
  }

private:

  void handle_connect(const zr_boost_1_81::system::error_code& error)
  {
    if (!error)
    {
      zr_boost_1_81::asio::async_read(socket_,
          zr_boost_1_81::asio::buffer(read_msg_.data(), chat_message::header_length),
          zr_boost_1_81::bind(&chat_client::handle_read_header, this,
            zr_boost_1_81::asio::placeholders::error));
    }
  }

  void handle_read_header(const zr_boost_1_81::system::error_code& error)
  {
    if (!error && read_msg_.decode_header())
    {
      zr_boost_1_81::asio::async_read(socket_,
          zr_boost_1_81::asio::buffer(read_msg_.body(), read_msg_.body_length()),
          zr_boost_1_81::bind(&chat_client::handle_read_body, this,
            zr_boost_1_81::asio::placeholders::error));
    }
    else
    {
      do_close();
    }
  }

  void handle_read_body(const zr_boost_1_81::system::error_code& error)
  {
    if (!error)
    {
      std::cout.write(read_msg_.body(), read_msg_.body_length());
      std::cout << "\n";
      zr_boost_1_81::asio::async_read(socket_,
          zr_boost_1_81::asio::buffer(read_msg_.data(), chat_message::header_length),
          zr_boost_1_81::bind(&chat_client::handle_read_header, this,
            zr_boost_1_81::asio::placeholders::error));
    }
    else
    {
      do_close();
    }
  }

  void do_write(chat_message msg)
  {
    bool write_in_progress = !write_msgs_.empty();
    write_msgs_.push_back(msg);
    if (!write_in_progress)
    {
      zr_boost_1_81::asio::async_write(socket_,
          zr_boost_1_81::asio::buffer(write_msgs_.front().data(),
            write_msgs_.front().length()),
          zr_boost_1_81::bind(&chat_client::handle_write, this,
            zr_boost_1_81::asio::placeholders::error));
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
            zr_boost_1_81::bind(&chat_client::handle_write, this,
              zr_boost_1_81::asio::placeholders::error));
      }
    }
    else
    {
      do_close();
    }
  }

  void do_close()
  {
    socket_.close();
  }

private:
  zr_boost_1_81::asio::io_context& io_context_;
  tcp::socket socket_;
  chat_message read_msg_;
  chat_message_queue write_msgs_;
};

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 3)
    {
      std::cerr << "Usage: chat_client <host> <port>\n";
      return 1;
    }

    zr_boost_1_81::asio::io_context io_context;

    tcp::resolver resolver(io_context);
    tcp::resolver::results_type endpoints = resolver.resolve(argv[1], argv[2]);

    chat_client c(io_context, endpoints);

    zr_boost_1_81::thread t(zr_boost_1_81::bind(&zr_boost_1_81::asio::io_context::run, &io_context));

    char line[chat_message::max_body_length + 1];
    while (std::cin.getline(line, chat_message::max_body_length + 1))
    {
      using namespace std; // For strlen and memcpy.
      chat_message msg;
      msg.body_length(strlen(line));
      memcpy(msg.body(), line, msg.body_length());
      msg.encode_header();
      c.write(msg);
    }

    c.close();
    t.join();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}
