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
#include <boost/thread/thread.hpp>
#include <boost/bind/bind.hpp>

class printer
{
public:
  printer(zr_boost_1_81::asio::io_context& io)
    : strand_(zr_boost_1_81::asio::make_strand(io)),
      timer1_(io, zr_boost_1_81::asio::chrono::seconds(1)),
      timer2_(io, zr_boost_1_81::asio::chrono::seconds(1)),
      count_(0)
  {
    timer1_.async_wait(zr_boost_1_81::asio::bind_executor(strand_,
          zr_boost_1_81::bind(&printer::print1, this)));

    timer2_.async_wait(zr_boost_1_81::asio::bind_executor(strand_,
          zr_boost_1_81::bind(&printer::print2, this)));
  }

  ~printer()
  {
    std::cout << "Final count is " << count_ << std::endl;
  }

  void print1()
  {
    if (count_ < 10)
    {
      std::cout << "Timer 1: " << count_ << std::endl;
      ++count_;

      timer1_.expires_at(timer1_.expiry() + zr_boost_1_81::asio::chrono::seconds(1));

      timer1_.async_wait(zr_boost_1_81::asio::bind_executor(strand_,
            zr_boost_1_81::bind(&printer::print1, this)));
    }
  }

  void print2()
  {
    if (count_ < 10)
    {
      std::cout << "Timer 2: " << count_ << std::endl;
      ++count_;

      timer2_.expires_at(timer2_.expiry() + zr_boost_1_81::asio::chrono::seconds(1));

      timer2_.async_wait(zr_boost_1_81::asio::bind_executor(strand_,
            zr_boost_1_81::bind(&printer::print2, this)));
    }
  }

private:
  zr_boost_1_81::asio::strand<zr_boost_1_81::asio::io_context::executor_type> strand_;
  zr_boost_1_81::asio::steady_timer timer1_;
  zr_boost_1_81::asio::steady_timer timer2_;
  int count_;
};

int main()
{
  zr_boost_1_81::asio::io_context io;
  printer p(io);
  zr_boost_1_81::thread t(zr_boost_1_81::bind(&zr_boost_1_81::asio::io_context::run, &io));
  io.run();
  t.join();

  return 0;
}
