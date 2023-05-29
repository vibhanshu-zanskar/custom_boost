//
// ranged_wait_for_all.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <boost/asio.hpp>
#include <boost/asio/experimental/parallel_group.hpp>
#include <iostream>
#include <vector>

#ifdef BOOST_ASIO_HAS_POSIX_STREAM_DESCRIPTOR

int main()
{
  zr_boost_1_81::asio::io_context ctx;

  zr_boost_1_81::asio::posix::stream_descriptor out(ctx, ::dup(STDOUT_FILENO));
  zr_boost_1_81::asio::posix::stream_descriptor err(ctx, ::dup(STDERR_FILENO));

  using op_type = decltype(
      out.async_write_some(
        zr_boost_1_81::asio::buffer("", 0),
        zr_boost_1_81::asio::deferred
      )
    );

  std::vector<op_type> ops;

  ops.push_back(
      out.async_write_some(
        zr_boost_1_81::asio::buffer("first\r\n", 7),
        zr_boost_1_81::asio::deferred
      )
    );

  ops.push_back(
      err.async_write_some(
        zr_boost_1_81::asio::buffer("second\r\n", 8),
        zr_boost_1_81::asio::deferred
      )
    );

  zr_boost_1_81::asio::experimental::make_parallel_group(ops).async_wait(
      zr_boost_1_81::asio::experimental::wait_for_all(),
      [](
          std::vector<std::size_t> completion_order,
          std::vector<zr_boost_1_81::system::error_code> ec,
          std::vector<std::size_t> n
      )
      {
        for (std::size_t i = 0; i < completion_order.size(); ++i)
        {
          std::size_t idx = completion_order[i];
          std::cout << "operation " << idx << " finished: ";
          std::cout << ec[idx] << ", " << n[idx] << "\n";
        }
      }
    );

  ctx.run();
}

#else // defined(BOOST_ASIO_HAS_POSIX_STREAM_DESCRIPTOR)
int main() {}
#endif // defined(BOOST_ASIO_HAS_POSIX_STREAM_DESCRIPTOR)
