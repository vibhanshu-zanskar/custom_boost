//
// sleep.hpp
// ~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef SLEEP_HPP
#define SLEEP_HPP

#include <boost/asio/any_completion_handler.hpp>
#include <boost/asio/any_io_executor.hpp>
#include <boost/asio/async_result.hpp>
#include <boost/asio/error.hpp>
#include <chrono>

void async_sleep_impl(
    zr_boost_1_81::asio::any_completion_handler<void(zr_boost_1_81::system::error_code)> handler,
    zr_boost_1_81::asio::any_io_executor ex, std::chrono::nanoseconds duration);

template <typename CompletionToken>
inline auto async_sleep(zr_boost_1_81::asio::any_io_executor ex,
    std::chrono::nanoseconds duration, CompletionToken&& token)
{
  return zr_boost_1_81::asio::async_initiate<CompletionToken, void(zr_boost_1_81::system::error_code)>(
      async_sleep_impl, token, std::move(ex), duration);
}

#endif // SLEEP_HPP
