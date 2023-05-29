//
// blocking_tcp_echo_server.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdlib>
#include <iostream>
#include <thread>
#include <utility>
#include <boost/asio.hpp>

using zr_boost_1_81::asio::ip::tcp;

const int max_length = 1024;

void session(tcp::socket sock)
{
  try
  {
    for (;;)
    {
      char data[max_length];

      zr_boost_1_81::system::error_code error;
      size_t length = sock.read_some(zr_boost_1_81::asio::buffer(data), error);
      if (error == zr_boost_1_81::asio::error::eof)
        break; // Connection closed cleanly by peer.
      else if (error)
        throw zr_boost_1_81::system::system_error(error); // Some other error.

      zr_boost_1_81::asio::write(sock, zr_boost_1_81::asio::buffer(data, length));
    }
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception in thread: " << e.what() << "\n";
  }
}

void server(zr_boost_1_81::asio::io_context& io_context, unsigned short port)
{
  tcp::acceptor a(io_context, tcp::endpoint(tcp::v4(), port));
  for (;;)
  {
    std::thread(session, a.accept()).detach();
  }
}

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      std::cerr << "Usage: blocking_tcp_echo_server <port>\n";
      return 1;
    }

    zr_boost_1_81::asio::io_context io_context;

    server(io_context, std::atoi(argv[1]));
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}
