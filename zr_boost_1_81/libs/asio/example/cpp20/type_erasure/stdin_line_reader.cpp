//
// stdin_line_reader.cpp
// ~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include "stdin_line_reader.hpp"
#include <boost/asio/deferred.hpp>
#include <boost/asio/read_until.hpp>
#include <iostream>

stdin_line_reader::stdin_line_reader(zr_boost_1_81::asio::any_io_executor ex)
  : stdin_(ex, ::dup(STDIN_FILENO))
{
}

void stdin_line_reader::async_read_line_impl(std::string prompt,
    zr_boost_1_81::asio::any_completion_handler<void(zr_boost_1_81::system::error_code, std::string)> handler)
{
  std::cout << prompt;
  std::cout.flush();

  zr_boost_1_81::asio::async_read_until(stdin_, zr_boost_1_81::asio::dynamic_buffer(buffer_), '\n',
      zr_boost_1_81::asio::deferred(
        [this](zr_boost_1_81::system::error_code ec, std::size_t n)
        {
          if (!ec)
          {
            std::string result = buffer_.substr(0, n);
            buffer_.erase(0, n);
            return zr_boost_1_81::asio::deferred.values(ec, std::move(result));
          }
          else
          {
            return zr_boost_1_81::asio::deferred.values(ec, std::string{});
          }
        }
      )
    )(std::move(handler));
}
