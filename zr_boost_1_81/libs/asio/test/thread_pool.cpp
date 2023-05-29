//
// thread_pool.cpp
// ~~~~~~~~~~~~~~~
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

// Test that header file is self-contained.
#include <boost/asio/thread_pool.hpp>

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

void increment(int* count)
{
  ++(*count);
}

void decrement_to_zero(thread_pool* pool, int* count)
{
  if (*count > 0)
  {
    --(*count);

    int before_value = *count;
    zr_boost_1_81::asio::post(*pool, bindns::bind(decrement_to_zero, pool, count));

    // Handler execution cannot nest, so count value should remain unchanged.
    BOOST_ASIO_CHECK(*count == before_value);
  }
}

void nested_decrement_to_zero(thread_pool* pool, int* count)
{
  if (*count > 0)
  {
    --(*count);

    zr_boost_1_81::asio::dispatch(*pool,
        bindns::bind(nested_decrement_to_zero, pool, count));

    // Handler execution is nested, so count value should now be zero.
    BOOST_ASIO_CHECK(*count == 0);
  }
}

void thread_pool_test()
{
  thread_pool pool(1);

  int count1 = 0;
  zr_boost_1_81::asio::post(pool, bindns::bind(increment, &count1));

  int count2 = 10;
  zr_boost_1_81::asio::post(pool, bindns::bind(decrement_to_zero, &pool, &count2));

  int count3 = 10;
  zr_boost_1_81::asio::post(pool, bindns::bind(nested_decrement_to_zero, &pool, &count3));

  pool.wait();

  BOOST_ASIO_CHECK(count1 == 1);
  BOOST_ASIO_CHECK(count2 == 0);
  BOOST_ASIO_CHECK(count3 == 0);
}

class test_service : public zr_boost_1_81::asio::execution_context::service
{
public:
#if defined(BOOST_ASIO_NO_TYPEID)
  static zr_boost_1_81::asio::execution_context::id id;
#endif // defined(BOOST_ASIO_NO_TYPEID)

  typedef test_service key_type;

  test_service(zr_boost_1_81::asio::execution_context& ctx)
    : zr_boost_1_81::asio::execution_context::service(ctx)
  {
  }

private:
  virtual void shutdown() {}
};

#if defined(BOOST_ASIO_NO_TYPEID)
zr_boost_1_81::asio::execution_context::id test_service::id;
#endif // defined(BOOST_ASIO_NO_TYPEID)

void thread_pool_service_test()
{
  zr_boost_1_81::asio::thread_pool pool1(1);
  zr_boost_1_81::asio::thread_pool pool2(1);
  zr_boost_1_81::asio::thread_pool pool3(1);

  // Implicit service registration.

  zr_boost_1_81::asio::use_service<test_service>(pool1);

  BOOST_ASIO_CHECK(zr_boost_1_81::asio::has_service<test_service>(pool1));

  test_service* svc1 = new test_service(pool1);
  try
  {
    zr_boost_1_81::asio::add_service(pool1, svc1);
    BOOST_ASIO_ERROR("add_service did not throw");
  }
  catch (zr_boost_1_81::asio::service_already_exists&)
  {
  }
  delete svc1;

  // Explicit service registration.

  test_service& svc2 = zr_boost_1_81::asio::make_service<test_service>(pool2);

  BOOST_ASIO_CHECK(zr_boost_1_81::asio::has_service<test_service>(pool2));
  BOOST_ASIO_CHECK(&zr_boost_1_81::asio::use_service<test_service>(pool2) == &svc2);

  test_service* svc3 = new test_service(pool2);
  try
  {
    zr_boost_1_81::asio::add_service(pool2, svc3);
    BOOST_ASIO_ERROR("add_service did not throw");
  }
  catch (zr_boost_1_81::asio::service_already_exists&)
  {
  }
  delete svc3;

  // Explicit registration with invalid owner.

  test_service* svc4 = new test_service(pool2);
  try
  {
    zr_boost_1_81::asio::add_service(pool3, svc4);
    BOOST_ASIO_ERROR("add_service did not throw");
  }
  catch (zr_boost_1_81::asio::invalid_service_owner&)
  {
  }
  delete svc4;

  BOOST_ASIO_CHECK(!zr_boost_1_81::asio::has_service<test_service>(pool3));
}

void thread_pool_executor_query_test()
{
  thread_pool pool(1);

  BOOST_ASIO_CHECK(
      &zr_boost_1_81::asio::query(pool.executor(),
        zr_boost_1_81::asio::execution::context)
      == &pool);

  BOOST_ASIO_CHECK(
      zr_boost_1_81::asio::query(pool.executor(),
        zr_boost_1_81::asio::execution::blocking)
      == zr_boost_1_81::asio::execution::blocking.possibly);

  BOOST_ASIO_CHECK(
      zr_boost_1_81::asio::query(pool.executor(),
        zr_boost_1_81::asio::execution::blocking.possibly)
      == zr_boost_1_81::asio::execution::blocking.possibly);

  BOOST_ASIO_CHECK(
      zr_boost_1_81::asio::query(pool.executor(),
        zr_boost_1_81::asio::execution::outstanding_work)
      == zr_boost_1_81::asio::execution::outstanding_work.untracked);

  BOOST_ASIO_CHECK(
      zr_boost_1_81::asio::query(pool.executor(),
        zr_boost_1_81::asio::execution::outstanding_work.untracked)
      == zr_boost_1_81::asio::execution::outstanding_work.untracked);

  BOOST_ASIO_CHECK(
      zr_boost_1_81::asio::query(pool.executor(),
        zr_boost_1_81::asio::execution::relationship)
      == zr_boost_1_81::asio::execution::relationship.fork);

  BOOST_ASIO_CHECK(
      zr_boost_1_81::asio::query(pool.executor(),
        zr_boost_1_81::asio::execution::relationship.fork)
      == zr_boost_1_81::asio::execution::relationship.fork);

#if !defined(BOOST_ASIO_NO_DEPRECATED)
  BOOST_ASIO_CHECK(
      zr_boost_1_81::asio::query(pool.executor(),
        zr_boost_1_81::asio::execution::bulk_guarantee)
      == zr_boost_1_81::asio::execution::bulk_guarantee.parallel);
#endif // !defined(BOOST_ASIO_NO_DEPRECATED)

  BOOST_ASIO_CHECK(
      zr_boost_1_81::asio::query(pool.executor(),
        zr_boost_1_81::asio::execution::mapping)
      == zr_boost_1_81::asio::execution::mapping.thread);

  BOOST_ASIO_CHECK(
      zr_boost_1_81::asio::query(pool.executor(),
        zr_boost_1_81::asio::execution::allocator)
      == std::allocator<void>());

  BOOST_ASIO_CHECK(
      zr_boost_1_81::asio::query(pool.executor(),
        zr_boost_1_81::asio::execution::occupancy)
      == 1);
}

void thread_pool_executor_execute_test()
{
  int count = 0;
  thread_pool pool(1);

  pool.executor().execute(bindns::bind(increment, &count));

  zr_boost_1_81::asio::require(pool.executor(),
      zr_boost_1_81::asio::execution::blocking.possibly
    ).execute(bindns::bind(increment, &count));

  zr_boost_1_81::asio::require(pool.executor(),
      zr_boost_1_81::asio::execution::blocking.always
    ).execute(bindns::bind(increment, &count));

  zr_boost_1_81::asio::require(pool.executor(),
      zr_boost_1_81::asio::execution::blocking.never
    ).execute(bindns::bind(increment, &count));

  zr_boost_1_81::asio::require(pool.executor(),
      zr_boost_1_81::asio::execution::blocking.never,
      zr_boost_1_81::asio::execution::outstanding_work.tracked
    ).execute(bindns::bind(increment, &count));

  zr_boost_1_81::asio::require(pool.executor(),
      zr_boost_1_81::asio::execution::blocking.never,
      zr_boost_1_81::asio::execution::outstanding_work.untracked
    ).execute(bindns::bind(increment, &count));

  zr_boost_1_81::asio::require(pool.executor(),
      zr_boost_1_81::asio::execution::blocking.never,
      zr_boost_1_81::asio::execution::outstanding_work.untracked,
      zr_boost_1_81::asio::execution::relationship.fork
    ).execute(bindns::bind(increment, &count));

  zr_boost_1_81::asio::require(pool.executor(),
      zr_boost_1_81::asio::execution::blocking.never,
      zr_boost_1_81::asio::execution::outstanding_work.untracked,
      zr_boost_1_81::asio::execution::relationship.continuation
    ).execute(bindns::bind(increment, &count));

  zr_boost_1_81::asio::prefer(
      zr_boost_1_81::asio::require(pool.executor(),
        zr_boost_1_81::asio::execution::blocking.never,
        zr_boost_1_81::asio::execution::outstanding_work.untracked,
        zr_boost_1_81::asio::execution::relationship.continuation),
      zr_boost_1_81::asio::execution::allocator(std::allocator<void>())
    ).execute(bindns::bind(increment, &count));

  zr_boost_1_81::asio::prefer(
      zr_boost_1_81::asio::require(pool.executor(),
        zr_boost_1_81::asio::execution::blocking.never,
        zr_boost_1_81::asio::execution::outstanding_work.untracked,
        zr_boost_1_81::asio::execution::relationship.continuation),
      zr_boost_1_81::asio::execution::allocator
    ).execute(bindns::bind(increment, &count));

  pool.wait();

  BOOST_ASIO_CHECK(count == 10);
}

#if !defined(BOOST_ASIO_NO_DEPRECATED)

struct receiver
{
  int* count_;

  receiver(int* count)
    : count_(count)
  {
  }

  receiver(const receiver& other) BOOST_ASIO_NOEXCEPT
    : count_(other.count_)
  {
  }

#if defined(BOOST_ASIO_HAS_MOVE)
  receiver(receiver&& other) BOOST_ASIO_NOEXCEPT
    : count_(other.count_)
  {
    other.count_ = 0;
  }
#endif // defined(BOOST_ASIO_HAS_MOVE)

  void set_value() BOOST_ASIO_NOEXCEPT
  {
    ++(*count_);
  }

  template <typename E>
  void set_error(BOOST_ASIO_MOVE_ARG(E) e) BOOST_ASIO_NOEXCEPT
  {
    (void)e;
  }

  void set_done() BOOST_ASIO_NOEXCEPT
  {
  }
};

namespace zr_boost_1_81 {
namespace asio {
namespace traits {

#if !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_MEMBER_TRAIT)

template <>
struct set_value_member<receiver, void()>
{
  BOOST_ASIO_STATIC_CONSTEXPR(bool, is_valid = true);
  BOOST_ASIO_STATIC_CONSTEXPR(bool, is_noexcept = true);
  typedef void result_type;
};

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_MEMBER_TRAIT)

#if !defined(BOOST_ASIO_HAS_DEDUCED_SET_ERROR_MEMBER_TRAIT)

template <typename E>
struct set_error_member<receiver, E>
{
  BOOST_ASIO_STATIC_CONSTEXPR(bool, is_valid = true);
  BOOST_ASIO_STATIC_CONSTEXPR(bool, is_noexcept = true);
  typedef void result_type;
};

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_SET_ERROR_MEMBER_TRAIT)

#if !defined(BOOST_ASIO_HAS_DEDUCED_SET_DONE_MEMBER_TRAIT)

template <>
struct set_done_member<receiver>
{
  BOOST_ASIO_STATIC_CONSTEXPR(bool, is_valid = true);
  BOOST_ASIO_STATIC_CONSTEXPR(bool, is_noexcept = true);
  typedef void result_type;
};

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_SET_DONE_MEMBER_TRAIT)

} // namespace traits
} // namespace asio
} // namespace zr_boost_1_81

void thread_pool_scheduler_test()
{
  int count = 0;
  receiver r(&count);
  thread_pool pool(1);

  zr_boost_1_81::asio::execution::submit(
    zr_boost_1_81::asio::execution::schedule(pool.scheduler()), r);

  zr_boost_1_81::asio::execution::submit(
      zr_boost_1_81::asio::require(
        zr_boost_1_81::asio::execution::schedule(pool.executor()),
        zr_boost_1_81::asio::execution::blocking.possibly), r);

  zr_boost_1_81::asio::execution::submit(
      zr_boost_1_81::asio::require(
        zr_boost_1_81::asio::execution::schedule(pool.executor()),
        zr_boost_1_81::asio::execution::blocking.always), r);

  zr_boost_1_81::asio::execution::submit(
      zr_boost_1_81::asio::require(
        zr_boost_1_81::asio::execution::schedule(pool.executor()),
        zr_boost_1_81::asio::execution::blocking.never), r);

  zr_boost_1_81::asio::execution::submit(
      zr_boost_1_81::asio::require(
        zr_boost_1_81::asio::execution::schedule(pool.executor()),
        zr_boost_1_81::asio::execution::blocking.never,
        zr_boost_1_81::asio::execution::outstanding_work.tracked), r);

  zr_boost_1_81::asio::execution::submit(
      zr_boost_1_81::asio::require(
        zr_boost_1_81::asio::execution::schedule(pool.executor()),
        zr_boost_1_81::asio::execution::blocking.never,
        zr_boost_1_81::asio::execution::outstanding_work.untracked), r);

  zr_boost_1_81::asio::execution::submit(
      zr_boost_1_81::asio::require(
        zr_boost_1_81::asio::execution::schedule(pool.executor()),
        zr_boost_1_81::asio::execution::blocking.never,
        zr_boost_1_81::asio::execution::outstanding_work.untracked,
        zr_boost_1_81::asio::execution::relationship.fork), r);

  zr_boost_1_81::asio::execution::submit(
      zr_boost_1_81::asio::require(
        zr_boost_1_81::asio::execution::schedule(pool.executor()),
        zr_boost_1_81::asio::execution::blocking.never,
        zr_boost_1_81::asio::execution::outstanding_work.untracked,
        zr_boost_1_81::asio::execution::relationship.continuation), r);

  zr_boost_1_81::asio::execution::submit(
      zr_boost_1_81::asio::prefer(
        zr_boost_1_81::asio::require(
          zr_boost_1_81::asio::execution::schedule(pool.executor()),
          zr_boost_1_81::asio::execution::blocking.never,
          zr_boost_1_81::asio::execution::outstanding_work.untracked,
          zr_boost_1_81::asio::execution::relationship.continuation),
        zr_boost_1_81::asio::execution::allocator(std::allocator<void>())), r);

  zr_boost_1_81::asio::execution::submit(
      zr_boost_1_81::asio::prefer(
        zr_boost_1_81::asio::require(
          zr_boost_1_81::asio::execution::schedule(pool.executor()),
          zr_boost_1_81::asio::execution::blocking.never,
          zr_boost_1_81::asio::execution::outstanding_work.untracked,
          zr_boost_1_81::asio::execution::relationship.continuation),
        zr_boost_1_81::asio::execution::allocator), r);

  pool.wait();

  BOOST_ASIO_CHECK(count == 10);
}

void thread_pool_executor_bulk_execute_test()
{
  int count = 0;
  thread_pool pool(1);

  pool.executor().bulk_execute(
      bindns::bind(increment, &count), 2);

  zr_boost_1_81::asio::require(pool.executor(),
    zr_boost_1_81::asio::execution::blocking.possibly).bulk_execute(
      bindns::bind(increment, &count), 2);

  zr_boost_1_81::asio::require(pool.executor(),
    zr_boost_1_81::asio::execution::blocking.always).bulk_execute(
      bindns::bind(increment, &count), 2);

  zr_boost_1_81::asio::require(pool.executor(),
    zr_boost_1_81::asio::execution::blocking.never).bulk_execute(
      bindns::bind(increment, &count), 2);

  zr_boost_1_81::asio::require(pool.executor(),
    zr_boost_1_81::asio::execution::blocking.never,
    zr_boost_1_81::asio::execution::outstanding_work.tracked).bulk_execute(
      bindns::bind(increment, &count), 2);

  zr_boost_1_81::asio::require(pool.executor(),
    zr_boost_1_81::asio::execution::blocking.never,
    zr_boost_1_81::asio::execution::outstanding_work.untracked).bulk_execute(
      bindns::bind(increment, &count), 2);

  zr_boost_1_81::asio::require(pool.executor(),
    zr_boost_1_81::asio::execution::blocking.never,
    zr_boost_1_81::asio::execution::outstanding_work.untracked,
    zr_boost_1_81::asio::execution::relationship.fork).bulk_execute(
      bindns::bind(increment, &count), 2);

  zr_boost_1_81::asio::require(pool.executor(),
    zr_boost_1_81::asio::execution::blocking.never,
    zr_boost_1_81::asio::execution::outstanding_work.untracked,
    zr_boost_1_81::asio::execution::relationship.continuation).bulk_execute(
      bindns::bind(increment, &count), 2);

  zr_boost_1_81::asio::prefer(
    zr_boost_1_81::asio::require(pool.executor(),
      zr_boost_1_81::asio::execution::blocking.never,
      zr_boost_1_81::asio::execution::outstanding_work.untracked,
      zr_boost_1_81::asio::execution::relationship.continuation),
    zr_boost_1_81::asio::execution::allocator(std::allocator<void>())).bulk_execute(
      bindns::bind(increment, &count), 2);

  zr_boost_1_81::asio::prefer(
    zr_boost_1_81::asio::require(pool.executor(),
      zr_boost_1_81::asio::execution::blocking.never,
      zr_boost_1_81::asio::execution::outstanding_work.untracked,
      zr_boost_1_81::asio::execution::relationship.continuation),
    zr_boost_1_81::asio::execution::allocator).bulk_execute(
      bindns::bind(increment, &count), 2);

  pool.wait();

  BOOST_ASIO_CHECK(count == 20);
}

#else // !defined(BOOST_ASIO_NO_DEPRECATED)

void thread_pool_scheduler_test() {}
void thread_pool_executor_bulk_execute_test() {}

#endif // !defined(BOOST_ASIO_NO_DEPRECATED)

BOOST_ASIO_TEST_SUITE
(
  "thread_pool",
  BOOST_ASIO_TEST_CASE(thread_pool_test)
  BOOST_ASIO_TEST_CASE(thread_pool_service_test)
  BOOST_ASIO_TEST_CASE(thread_pool_executor_query_test)
  BOOST_ASIO_TEST_CASE(thread_pool_executor_execute_test)
  BOOST_ASIO_TEST_CASE(thread_pool_scheduler_test)
  BOOST_ASIO_TEST_CASE(thread_pool_executor_bulk_execute_test)
)
