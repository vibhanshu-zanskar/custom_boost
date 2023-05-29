//
// stream_server.cpp
// ~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdio>
#include <iostream>
#include <boost/array.hpp>
#include <boost/bind/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>

#if defined(BOOST_ASIO_HAS_LOCAL_SOCKETS)

using zr_boost_1_81::asio::local::stream_protocol;

class session
  : public zr_boost_1_81::enable_shared_from_this<session>
{
public:
  session(zr_boost_1_81::asio::io_context& io_context)
    : socket_(io_context)
  {
  }

  stream_protocol::socket& socket()
  {
    return socket_;
  }

  void start()
  {
    socket_.async_read_some(zr_boost_1_81::asio::buffer(data_),
        zr_boost_1_81::bind(&session::handle_read,
          shared_from_this(),
          zr_boost_1_81::asio::placeholders::error,
          zr_boost_1_81::asio::placeholders::bytes_transferred));
  }

  void handle_read(const zr_boost_1_81::system::error_code& error,
      size_t bytes_transferred)
  {
    if (!error)
    {
      zr_boost_1_81::asio::async_write(socket_,
          zr_boost_1_81::asio::buffer(data_, bytes_transferred),
          zr_boost_1_81::bind(&session::handle_write,
            shared_from_this(),
            zr_boost_1_81::asio::placeholders::error));
    }
  }

  void handle_write(const zr_boost_1_81::system::error_code& error)
  {
    if (!error)
    {
      socket_.async_read_some(zr_boost_1_81::asio::buffer(data_),
          zr_boost_1_81::bind(&session::handle_read,
            shared_from_this(),
            zr_boost_1_81::asio::placeholders::error,
            zr_boost_1_81::asio::placeholders::bytes_transferred));
    }
  }

private:
  // The socket used to communicate with the client.
  stream_protocol::socket socket_;

  // Buffer used to store data received from the client.
  zr_boost_1_81::array<char, 1024> data_;
};

typedef zr_boost_1_81::shared_ptr<session> session_ptr;

class server
{
public:
  server(zr_boost_1_81::asio::io_context& io_context, const std::string& file)
    : io_context_(io_context),
      acceptor_(io_context, stream_protocol::endpoint(file))
  {
    session_ptr new_session(new session(io_context_));
    acceptor_.async_accept(new_session->socket(),
        zr_boost_1_81::bind(&server::handle_accept, this, new_session,
          zr_boost_1_81::asio::placeholders::error));
  }

  void handle_accept(session_ptr new_session,
      const zr_boost_1_81::system::error_code& error)
  {
    if (!error)
    {
      new_session->start();
    }

    new_session.reset(new session(io_context_));
    acceptor_.async_accept(new_session->socket(),
        zr_boost_1_81::bind(&server::handle_accept, this, new_session,
          zr_boost_1_81::asio::placeholders::error));
  }

private:
  zr_boost_1_81::asio::io_context& io_context_;
  stream_protocol::acceptor acceptor_;
};

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      std::cerr << "Usage: stream_server <file>\n";
      std::cerr << "*** WARNING: existing file is removed ***\n";
      return 1;
    }

    zr_boost_1_81::asio::io_context io_context;

    std::remove(argv[1]);
    server s(io_context, argv[1]);

    io_context.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}

#else // defined(BOOST_ASIO_HAS_LOCAL_SOCKETS)
# error Local sockets not available on this platform.
#endif // defined(BOOST_ASIO_HAS_LOCAL_SOCKETS)
