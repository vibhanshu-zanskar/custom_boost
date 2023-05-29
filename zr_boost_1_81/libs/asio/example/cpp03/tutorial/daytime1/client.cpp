//
// client.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using zr_boost_1_81::asio::ip::tcp;

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      std::cerr << "Usage: client <host>" << std::endl;
      return 1;
    }

    zr_boost_1_81::asio::io_context io_context;

    tcp::resolver resolver(io_context);
    tcp::resolver::results_type endpoints =
      resolver.resolve(argv[1], "daytime");

    tcp::socket socket(io_context);
    zr_boost_1_81::asio::connect(socket, endpoints);

    for (;;)
    {
      zr_boost_1_81::array<char, 128> buf;
      zr_boost_1_81::system::error_code error;

      size_t len = socket.read_some(zr_boost_1_81::asio::buffer(buf), error);

      if (error == zr_boost_1_81::asio::error::eof)
        break; // Connection closed cleanly by peer.
      else if (error)
        throw zr_boost_1_81::system::system_error(error); // Some other error.

      std::cout.write(buf.data(), len);
    }
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
