//
// deferred_2.cpp
// ~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <boost/asio.hpp>
#include <iostream>

using zr_boost_1_81::asio::deferred;

int main()
{
  zr_boost_1_81::asio::io_context ctx;

  zr_boost_1_81::asio::steady_timer timer(ctx);
  timer.expires_after(std::chrono::seconds(1));

  auto deferred_op = timer.async_wait(
      deferred(
        [&](zr_boost_1_81::system::error_code ec)
        {
          std::cout << "first timer wait finished: " << ec.message() << "\n";
          timer.expires_after(std::chrono::seconds(1));
          return timer.async_wait(deferred);
        }
      )
    );

  std::move(deferred_op)(
      [](zr_boost_1_81::system::error_code ec)
      {
        std::cout << "second timer wait finished: " << ec.message() << "\n";
      }
    );

  ctx.run();

  return 0;
}
