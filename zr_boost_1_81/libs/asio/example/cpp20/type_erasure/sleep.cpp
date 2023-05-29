//
// sleep.cpp
// ~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include "sleep.hpp"
#include <boost/asio/consign.hpp>
#include <boost/asio/steady_timer.hpp>
#include <memory>

void async_sleep_impl(
    zr_boost_1_81::asio::any_completion_handler<void(zr_boost_1_81::system::error_code)> handler,
    zr_boost_1_81::asio::any_io_executor ex, std::chrono::nanoseconds duration)
{
  auto timer = std::make_shared<zr_boost_1_81::asio::steady_timer>(ex, duration);
  timer->async_wait(zr_boost_1_81::asio::consign(std::move(handler), timer));
}
