//
// server.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

using zr_boost_1_81::asio::ip::tcp;
using zr_boost_1_81::asio::ip::udp;

std::string make_daytime_string()
{
  using namespace std; // For time_t, time and ctime;
  time_t now = time(0);
  return ctime(&now);
}

class tcp_connection
  : public zr_boost_1_81::enable_shared_from_this<tcp_connection>
{
public:
  typedef zr_boost_1_81::shared_ptr<tcp_connection> pointer;

  static pointer create(zr_boost_1_81::asio::io_context& io_context)
  {
    return pointer(new tcp_connection(io_context));
  }

  tcp::socket& socket()
  {
    return socket_;
  }

  void start()
  {
    message_ = make_daytime_string();

    zr_boost_1_81::asio::async_write(socket_, zr_boost_1_81::asio::buffer(message_),
        zr_boost_1_81::bind(&tcp_connection::handle_write, shared_from_this()));
  }

private:
  tcp_connection(zr_boost_1_81::asio::io_context& io_context)
    : socket_(io_context)
  {
  }

  void handle_write()
  {
  }

  tcp::socket socket_;
  std::string message_;
};

class tcp_server
{
public:
  tcp_server(zr_boost_1_81::asio::io_context& io_context)
    : io_context_(io_context),
      acceptor_(io_context, tcp::endpoint(tcp::v4(), 13))
  {
    start_accept();
  }

private:
  void start_accept()
  {
    tcp_connection::pointer new_connection =
      tcp_connection::create(io_context_);

    acceptor_.async_accept(new_connection->socket(),
        zr_boost_1_81::bind(&tcp_server::handle_accept, this, new_connection,
          zr_boost_1_81::asio::placeholders::error));
  }

  void handle_accept(tcp_connection::pointer new_connection,
      const zr_boost_1_81::system::error_code& error)
  {
    if (!error)
    {
      new_connection->start();
    }

    start_accept();
  }

  zr_boost_1_81::asio::io_context& io_context_;
  tcp::acceptor acceptor_;
};

class udp_server
{
public:
  udp_server(zr_boost_1_81::asio::io_context& io_context)
    : socket_(io_context, udp::endpoint(udp::v4(), 13))
  {
    start_receive();
  }

private:
  void start_receive()
  {
    socket_.async_receive_from(
        zr_boost_1_81::asio::buffer(recv_buffer_), remote_endpoint_,
        zr_boost_1_81::bind(&udp_server::handle_receive, this,
          zr_boost_1_81::asio::placeholders::error));
  }

  void handle_receive(const zr_boost_1_81::system::error_code& error)
  {
    if (!error)
    {
      zr_boost_1_81::shared_ptr<std::string> message(
          new std::string(make_daytime_string()));

      socket_.async_send_to(zr_boost_1_81::asio::buffer(*message), remote_endpoint_,
          zr_boost_1_81::bind(&udp_server::handle_send, this, message));

      start_receive();
    }
  }

  void handle_send(zr_boost_1_81::shared_ptr<std::string> /*message*/)
  {
  }

  udp::socket socket_;
  udp::endpoint remote_endpoint_;
  zr_boost_1_81::array<char, 1> recv_buffer_;
};

int main()
{
  try
  {
    zr_boost_1_81::asio::io_context io_context;
    tcp_server server1(io_context);
    udp_server server2(io_context);
    io_context.run();
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
