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
#include <boost/bind/bind.hpp>

void print(const zr_boost_1_81::system::error_code& /*e*/,
    zr_boost_1_81::asio::steady_timer* t, int* count)
{
  if (*count < 5)
  {
    std::cout << *count << std::endl;
    ++(*count);

    t->expires_at(t->expiry() + zr_boost_1_81::asio::chrono::seconds(1));
    t->async_wait(zr_boost_1_81::bind(print,
          zr_boost_1_81::asio::placeholders::error, t, count));
  }
}

int main()
{
  zr_boost_1_81::asio::io_context io;

  int count = 0;
  zr_boost_1_81::asio::steady_timer t(io, zr_boost_1_81::asio::chrono::seconds(1));
  t.async_wait(zr_boost_1_81::bind(print,
        zr_boost_1_81::asio::placeholders::error, &t, &count));

  io.run();

  std::cout << "Final count is " << count << std::endl;

  return 0;
}
