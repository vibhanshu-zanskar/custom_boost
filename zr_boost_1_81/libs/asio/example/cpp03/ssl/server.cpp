//
// server.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdlib>
#include <iostream>
#include <boost/bind/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

typedef zr_boost_1_81::asio::ssl::stream<zr_boost_1_81::asio::ip::tcp::socket> ssl_socket;

class session
{
public:
  session(zr_boost_1_81::asio::io_context& io_context,
      zr_boost_1_81::asio::ssl::context& context)
    : socket_(io_context, context)
  {
  }

  ssl_socket::lowest_layer_type& socket()
  {
    return socket_.lowest_layer();
  }

  void start()
  {
    socket_.async_handshake(zr_boost_1_81::asio::ssl::stream_base::server,
        zr_boost_1_81::bind(&session::handle_handshake, this,
          zr_boost_1_81::asio::placeholders::error));
  }

  void handle_handshake(const zr_boost_1_81::system::error_code& error)
  {
    if (!error)
    {
      socket_.async_read_some(zr_boost_1_81::asio::buffer(data_, max_length),
          zr_boost_1_81::bind(&session::handle_read, this,
            zr_boost_1_81::asio::placeholders::error,
            zr_boost_1_81::asio::placeholders::bytes_transferred));
    }
    else
    {
      delete this;
    }
  }

  void handle_read(const zr_boost_1_81::system::error_code& error,
      size_t bytes_transferred)
  {
    if (!error)
    {
      zr_boost_1_81::asio::async_write(socket_,
          zr_boost_1_81::asio::buffer(data_, bytes_transferred),
          zr_boost_1_81::bind(&session::handle_write, this,
            zr_boost_1_81::asio::placeholders::error));
    }
    else
    {
      delete this;
    }
  }

  void handle_write(const zr_boost_1_81::system::error_code& error)
  {
    if (!error)
    {
      socket_.async_read_some(zr_boost_1_81::asio::buffer(data_, max_length),
          zr_boost_1_81::bind(&session::handle_read, this,
            zr_boost_1_81::asio::placeholders::error,
            zr_boost_1_81::asio::placeholders::bytes_transferred));
    }
    else
    {
      delete this;
    }
  }

private:
  ssl_socket socket_;
  enum { max_length = 1024 };
  char data_[max_length];
};

class server
{
public:
  server(zr_boost_1_81::asio::io_context& io_context, unsigned short port)
    : io_context_(io_context),
      acceptor_(io_context,
          zr_boost_1_81::asio::ip::tcp::endpoint(zr_boost_1_81::asio::ip::tcp::v4(), port)),
      context_(zr_boost_1_81::asio::ssl::context::sslv23)
  {
    context_.set_options(
        zr_boost_1_81::asio::ssl::context::default_workarounds
        | zr_boost_1_81::asio::ssl::context::no_sslv2
        | zr_boost_1_81::asio::ssl::context::single_dh_use);
    context_.set_password_callback(zr_boost_1_81::bind(&server::get_password, this));
    context_.use_certificate_chain_file("server.pem");
    context_.use_private_key_file("server.pem", zr_boost_1_81::asio::ssl::context::pem);
    context_.use_tmp_dh_file("dh4096.pem");

    start_accept();
  }

  std::string get_password() const
  {
    return "test";
  }

  void start_accept()
  {
    session* new_session = new session(io_context_, context_);
    acceptor_.async_accept(new_session->socket(),
        zr_boost_1_81::bind(&server::handle_accept, this, new_session,
          zr_boost_1_81::asio::placeholders::error));
  }

  void handle_accept(session* new_session,
      const zr_boost_1_81::system::error_code& error)
  {
    if (!error)
    {
      new_session->start();
    }
    else
    {
      delete new_session;
    }

    start_accept();
  }

private:
  zr_boost_1_81::asio::io_context& io_context_;
  zr_boost_1_81::asio::ip::tcp::acceptor acceptor_;
  zr_boost_1_81::asio::ssl::context context_;
};

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      std::cerr << "Usage: server <port>\n";
      return 1;
    }

    zr_boost_1_81::asio::io_context io_context;

    using namespace std; // For atoi.
    server s(io_context, atoi(argv[1]));

    io_context.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}
