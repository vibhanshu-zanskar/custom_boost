//
// system_executor.cpp
// ~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

// Disable autolinking for unit tests.
#if !defined(BOOST_ALL_NO_LIB)
#define BOOST_ALL_NO_LIB 1
#endif // !defined(BOOST_ALL_NO_LIB)

// Prevent link dependency on the Boost.System library.
#if !defined(BOOST_SYSTEM_NO_DEPRECATED)
#define BOOST_SYSTEM_NO_DEPRECATED
#endif // !defined(BOOST_SYSTEM_NO_DEPRECATED)

// Test that header file is self-contained.
#include <boost/asio/system_executor.hpp>

#include <boost/asio/dispatch.hpp>
#include <boost/asio/post.hpp>
#include "unit_test.hpp"

#if defined(BOOST_ASIO_HAS_BOOST_BIND)
# include <boost/bind/bind.hpp>
#else // defined(BOOST_ASIO_HAS_BOOST_BIND)
# include <functional>
#endif // defined(BOOST_ASIO_HAS_BOOST_BIND)

using namespace zr_boost_1_81::asio;

#if defined(BOOST_ASIO_HAS_BOOST_BIND)
namespace bindns = zr_boost_1_81;
#else // defined(BOOST_ASIO_HAS_BOOST_BIND)
namespace bindns = std;
#endif

void increment(zr_boost_1_81::asio::detail::atomic_count* count)
{
  ++(*count);
}

void system_executor_query_test()
{
  BOOST_ASIO_CHECK(
      &zr_boost_1_81::asio::query(system_executor(),
        zr_boost_1_81::asio::execution::context)
      != static_cast<const system_context*>(0));

  BOOST_ASIO_CHECK(
      zr_boost_1_81::asio::query(system_executor(),
        zr_boost_1_81::asio::execution::blocking)
      == zr_boost_1_81::asio::execution::blocking.possibly);

  BOOST_ASIO_CHECK(
      zr_boost_1_81::asio::query(system_executor(),
        zr_boost_1_81::asio::execution::blocking.possibly)
      == zr_boost_1_81::asio::execution::blocking.possibly);

  BOOST_ASIO_CHECK(
      zr_boost_1_81::asio::query(system_executor(),
        zr_boost_1_81::asio::execution::outstanding_work)
      == zr_boost_1_81::asio::execution::outstanding_work.untracked);

  BOOST_ASIO_CHECK(
      zr_boost_1_81::asio::query(system_executor(),
        zr_boost_1_81::asio::execution::outstanding_work.untracked)
      == zr_boost_1_81::asio::execution::outstanding_work.untracked);

  BOOST_ASIO_CHECK(
      zr_boost_1_81::asio::query(system_executor(),
        zr_boost_1_81::asio::execution::relationship)
      == zr_boost_1_81::asio::execution::relationship.fork);

  BOOST_ASIO_CHECK(
      zr_boost_1_81::asio::query(system_executor(),
        zr_boost_1_81::asio::execution::relationship.fork)
      == zr_boost_1_81::asio::execution::relationship.fork);

#if !defined(BOOST_ASIO_NO_DEPRECATED)
  BOOST_ASIO_CHECK(
      zr_boost_1_81::asio::query(system_executor(),
        zr_boost_1_81::asio::execution::bulk_guarantee)
      == zr_boost_1_81::asio::execution::bulk_guarantee.unsequenced);
#endif // !defined(BOOST_ASIO_NO_DEPRECATED)

  BOOST_ASIO_CHECK(
      zr_boost_1_81::asio::query(system_executor(),
        zr_boost_1_81::asio::execution::mapping)
      == zr_boost_1_81::asio::execution::mapping.thread);

  BOOST_ASIO_CHECK(
      zr_boost_1_81::asio::query(system_executor(),
        zr_boost_1_81::asio::execution::allocator)
      == std::allocator<void>());
}

void system_executor_execute_test()
{
  zr_boost_1_81::asio::detail::atomic_count count(0);

  system_executor().execute(bindns::bind(increment, &count));

  zr_boost_1_81::asio::require(system_executor(),
      zr_boost_1_81::asio::execution::blocking.possibly
    ).execute(bindns::bind(increment, &count));

  zr_boost_1_81::asio::require(system_executor(),
      zr_boost_1_81::asio::execution::blocking.always
    ).execute(bindns::bind(increment, &count));

  zr_boost_1_81::asio::require(system_executor(),
      zr_boost_1_81::asio::execution::blocking.never
    ).execute(bindns::bind(increment, &count));

  zr_boost_1_81::asio::require(system_executor(),
      zr_boost_1_81::asio::execution::blocking.never,
      zr_boost_1_81::asio::execution::outstanding_work.untracked
    ).execute(bindns::bind(increment, &count));

  zr_boost_1_81::asio::require(system_executor(),
      zr_boost_1_81::asio::execution::blocking.never,
      zr_boost_1_81::asio::execution::outstanding_work.untracked,
      zr_boost_1_81::asio::execution::relationship.fork
    ).execute(bindns::bind(increment, &count));

  zr_boost_1_81::asio::require(system_executor(),
      zr_boost_1_81::asio::execution::blocking.never,
      zr_boost_1_81::asio::execution::outstanding_work.untracked,
      zr_boost_1_81::asio::execution::relationship.continuation
    ).execute(bindns::bind(increment, &count));

  zr_boost_1_81::asio::prefer(
      zr_boost_1_81::asio::require(system_executor(),
        zr_boost_1_81::asio::execution::blocking.never,
        zr_boost_1_81::asio::execution::outstanding_work.untracked,
        zr_boost_1_81::asio::execution::relationship.continuation),
      zr_boost_1_81::asio::execution::allocator(std::allocator<void>())
    ).execute(bindns::bind(increment, &count));

  zr_boost_1_81::asio::prefer(
      zr_boost_1_81::asio::require(system_executor(),
        zr_boost_1_81::asio::execution::blocking.never,
        zr_boost_1_81::asio::execution::outstanding_work.untracked,
        zr_boost_1_81::asio::execution::relationship.continuation),
      zr_boost_1_81::asio::execution::allocator
    ).execute(bindns::bind(increment, &count));

  zr_boost_1_81::asio::query(system_executor(), execution::context).join();

  BOOST_ASIO_CHECK(count == 9);
}

BOOST_ASIO_TEST_SUITE
(
  "system_executor",
  BOOST_ASIO_TEST_CASE(system_executor_query_test)
  BOOST_ASIO_TEST_CASE(system_executor_execute_test)
)
