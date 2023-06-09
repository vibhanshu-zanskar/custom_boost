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

class printer
{
public:
  printer(zr_boost_1_81::asio::io_context& io)
    : timer_(io, zr_boost_1_81::asio::chrono::seconds(1)),
      count_(0)
  {
    timer_.async_wait(zr_boost_1_81::bind(&printer::print, this));
  }

  ~printer()
  {
    std::cout << "Final count is " << count_ << std::endl;
  }

  void print()
  {
    if (count_ < 5)
    {
      std::cout << count_ << std::endl;
      ++count_;

      timer_.expires_at(timer_.expiry() + zr_boost_1_81::asio::chrono::seconds(1));
      timer_.async_wait(zr_boost_1_81::bind(&printer::print, this));
    }
  }

private:
  zr_boost_1_81::asio::steady_timer timer_;
  int count_;
};

int main()
{
  zr_boost_1_81::asio::io_context io;
  printer p(io);
  io.run();

  return 0;
}
