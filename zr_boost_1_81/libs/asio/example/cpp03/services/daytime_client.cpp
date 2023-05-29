//
// daytime_client.cpp
// ~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <iostream>
#include "logger.hpp"

using zr_boost_1_81::asio::ip::tcp;

char read_buffer[1024];

void read_handler(const zr_boost_1_81::system::error_code& e,
    std::size_t bytes_transferred, tcp::socket* s)
{
  if (!e)
  {
    std::cout.write(read_buffer, bytes_transferred);

    s->async_read_some(zr_boost_1_81::asio::buffer(read_buffer),
        zr_boost_1_81::bind(read_handler, zr_boost_1_81::asio::placeholders::error,
          zr_boost_1_81::asio::placeholders::bytes_transferred, s));
  }
  else
  {
    zr_boost_1_81::asio::execution_context& context = zr_boost_1_81::asio::query(
        s->get_executor(), zr_boost_1_81::asio::execution::context);
    services::logger logger(context, "read_handler");

    std::string msg = "Read error: ";
    msg += e.message();
    logger.log(msg);
  }
}

void connect_handler(const zr_boost_1_81::system::error_code& e, tcp::socket* s)
{
  zr_boost_1_81::asio::execution_context& context = zr_boost_1_81::asio::query(
      s->get_executor(), zr_boost_1_81::asio::execution::context);
  services::logger logger(context, "connect_handler");

  if (!e)
  {
    logger.log("Connection established");

    s->async_read_some(zr_boost_1_81::asio::buffer(read_buffer),
        zr_boost_1_81::bind(read_handler, zr_boost_1_81::asio::placeholders::error,
          zr_boost_1_81::asio::placeholders::bytes_transferred, s));
  }
  else
  {
    std::string msg = "Unable to establish connection: ";
    msg += e.message();
    logger.log(msg);
  }
}

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      std::cerr << "Usage: daytime_client <host>" << std::endl;
      return 1;
    }

    zr_boost_1_81::asio::io_context io_context;

    // Set the name of the file that all logger instances will use.
    services::logger logger(io_context, "");
    logger.use_file("log.txt");

    // Resolve the address corresponding to the given host.
    tcp::resolver resolver(io_context);
    tcp::resolver::results_type endpoints =
      resolver.resolve(argv[1], "daytime");

    // Start an asynchronous connect.
    tcp::socket socket(io_context);
    zr_boost_1_81::asio::async_connect(socket, endpoints,
        zr_boost_1_81::bind(connect_handler,
          zr_boost_1_81::asio::placeholders::error, &socket));

    // Run the io_context until all operations have finished.
    io_context.run();
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
