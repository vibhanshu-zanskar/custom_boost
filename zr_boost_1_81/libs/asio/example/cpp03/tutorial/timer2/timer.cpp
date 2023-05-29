//
// timer.cpp
// ~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <boost/asio.hpp>

void print(const zr_boost_1_81::system::error_code& /*e*/)
{
  std::cout << "Hello, world!" << std::endl;
}

int main()
{
  zr_boost_1_81::asio::io_context io;

  zr_boost_1_81::asio::steady_timer t(io, zr_boost_1_81::asio::chrono::seconds(5));
  t.async_wait(&print);

  io.run();

  return 0;
}
