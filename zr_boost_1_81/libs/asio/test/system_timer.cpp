//
// system_timer.cpp
// ~~~~~~~~~~~~~~~~
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
#include <boost/asio/system_timer.hpp>

#include "unit_test.hpp"

#if defined(BOOST_ASIO_HAS_STD_CHRONO)

#include <boost/asio/bind_cancellation_slot.hpp>
#include <boost/asio/cancellation_signal.hpp>
#include <boost/asio/executor_work_guard.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/detail/thread.hpp>

#if defined(BOOST_ASIO_HAS_BOOST_BIND)
# include <boost/bind/bind.hpp>
#else // defined(BOOST_ASIO_HAS_BOOST_BIND)
# include <functional>
#endif // defined(BOOST_ASIO_HAS_BOOST_BIND)

#if defined(BOOST_ASIO_HAS_BOOST_BIND)
namespace bindns = zr_boost_1_81;
#else // defined(BOOST_ASIO_HAS_BOOST_BIND)
namespace bindns = std;
#endif // defined(BOOST_ASIO_HAS_BOOST_BIND)

void increment(int* count)
{
  ++(*count);
}

void decrement_to_zero(zr_boost_1_81::asio::system_timer* t, int* count)
{
  if (*count > 0)
  {
    --(*count);

    int before_value = *count;

    t->expires_at(t->expiry() + zr_boost_1_81::asio::chrono::seconds(1));
    t->async_wait(bindns::bind(decrement_to_zero, t, count));

    // Completion cannot nest, so count value should remain unchanged.
    BOOST_ASIO_CHECK(*count == before_value);
  }
}

void increment_if_not_cancelled(int* count,
    const zr_boost_1_81::system::error_code& ec)
{
  if (!ec)
    ++(*count);
}

void cancel_timer(zr_boost_1_81::asio::system_timer* t)
{
  std::size_t num_cancelled = t->cancel();
  BOOST_ASIO_CHECK(num_cancelled == 1);
}

void cancel_one_timer(zr_boost_1_81::asio::system_timer* t)
{
  std::size_t num_cancelled = t->cancel_one();
  BOOST_ASIO_CHECK(num_cancelled == 1);
}

zr_boost_1_81::asio::system_timer::time_point now()
{
  return zr_boost_1_81::asio::system_timer::clock_type::now();
}

void system_timer_test()
{
  using zr_boost_1_81::asio::chrono::seconds;
  using zr_boost_1_81::asio::chrono::microseconds;
  using bindns::placeholders::_1;
  using bindns::placeholders::_2;

  zr_boost_1_81::asio::io_context ioc;
  const zr_boost_1_81::asio::io_context::executor_type ioc_ex = ioc.get_executor();
  int count = 0;

  zr_boost_1_81::asio::system_timer::time_point start = now();

  zr_boost_1_81::asio::system_timer t1(ioc, seconds(1));
  t1.wait();

  // The timer must block until after its expiry time.
  zr_boost_1_81::asio::system_timer::time_point end = now();
  zr_boost_1_81::asio::system_timer::time_point expected_end = start + seconds(1);
  BOOST_ASIO_CHECK(expected_end < end || expected_end == end);

  start = now();

  zr_boost_1_81::asio::system_timer t2(ioc_ex, seconds(1) + microseconds(500000));
  t2.wait();

  // The timer must block until after its expiry time.
  end = now();
  expected_end = start + seconds(1) + microseconds(500000);
  BOOST_ASIO_CHECK(expected_end < end || expected_end == end);

  t2.expires_at(t2.expiry() + seconds(1));
  t2.wait();

  // The timer must block until after its expiry time.
  end = now();
  expected_end += seconds(1);
  BOOST_ASIO_CHECK(expected_end < end || expected_end == end);

  start = now();

  t2.expires_after(seconds(1) + microseconds(200000));
  t2.wait();

  // The timer must block until after its expiry time.
  end = now();
  expected_end = start + seconds(1) + microseconds(200000);
  BOOST_ASIO_CHECK(expected_end < end || expected_end == end);

  start = now();

  zr_boost_1_81::asio::system_timer t3(ioc, seconds(5));
  t3.async_wait(bindns::bind(increment, &count));

  // No completions can be delivered until run() is called.
  BOOST_ASIO_CHECK(count == 0);

  ioc.run();

  // The run() call will not return until all operations have finished, and
  // this should not be until after the timer's expiry time.
  BOOST_ASIO_CHECK(count == 1);
  end = now();
  expected_end = start + seconds(1);
  BOOST_ASIO_CHECK(expected_end < end || expected_end == end);

  count = 3;
  start = now();

  zr_boost_1_81::asio::system_timer t4(ioc, seconds(1));
  t4.async_wait(bindns::bind(decrement_to_zero, &t4, &count));

  // No completions can be delivered until run() is called.
  BOOST_ASIO_CHECK(count == 3);

  ioc.restart();
  ioc.run();

  // The run() call will not return until all operations have finished, and
  // this should not be until after the timer's final expiry time.
  BOOST_ASIO_CHECK(count == 0);
  end = now();
  expected_end = start + seconds(3);
  BOOST_ASIO_CHECK(expected_end < end || expected_end == end);

  count = 0;
  start = now();

  zr_boost_1_81::asio::system_timer t5(ioc, seconds(10));
  t5.async_wait(bindns::bind(increment_if_not_cancelled, &count, _1));
  zr_boost_1_81::asio::system_timer t6(ioc, seconds(1));
  t6.async_wait(bindns::bind(cancel_timer, &t5));

  // No completions can be delivered until run() is called.
  BOOST_ASIO_CHECK(count == 0);

  ioc.restart();
  ioc.run();

  // The timer should have been cancelled, so count should not have changed.
  // The total run time should not have been much more than 1 second (and
  // certainly far less than 10 seconds).
  BOOST_ASIO_CHECK(count == 0);
  end = now();
  expected_end = start + seconds(2);
  BOOST_ASIO_CHECK(end < expected_end);

  // Wait on the timer again without cancelling it. This time the asynchronous
  // wait should run to completion and increment the counter.
  t5.async_wait(bindns::bind(increment_if_not_cancelled, &count, _1));

  ioc.restart();
  ioc.run();

  // The timer should not have been cancelled, so count should have changed.
  // The total time since the timer was created should be more than 10 seconds.
  BOOST_ASIO_CHECK(count == 1);
  end = now();
  expected_end = start + seconds(10);
  BOOST_ASIO_CHECK(expected_end < end || expected_end == end);

  count = 0;
  start = now();

  // Start two waits on a timer, one of which will be cancelled. The one
  // which is not cancelled should still run to completion and increment the
  // counter.
  zr_boost_1_81::asio::system_timer t7(ioc, seconds(3));
  t7.async_wait(bindns::bind(increment_if_not_cancelled, &count, _1));
  t7.async_wait(bindns::bind(increment_if_not_cancelled, &count, _1));
  zr_boost_1_81::asio::system_timer t8(ioc, seconds(1));
  t8.async_wait(bindns::bind(cancel_one_timer, &t7));

  ioc.restart();
  ioc.run();

  // One of the waits should not have been cancelled, so count should have
  // changed. The total time since the timer was created should be more than 3
  // seconds.
  BOOST_ASIO_CHECK(count == 1);
  end = now();
  expected_end = start + seconds(3);
  BOOST_ASIO_CHECK(expected_end < end || expected_end == end);
}

struct timer_handler
{
  timer_handler() {}
  void operator()(const zr_boost_1_81::system::error_code&) {}
#if defined(BOOST_ASIO_HAS_MOVE)
  timer_handler(timer_handler&&) {}
private:
  timer_handler(const timer_handler&);
#endif // defined(BOOST_ASIO_HAS_MOVE)
};

void system_timer_cancel_test()
{
  static zr_boost_1_81::asio::io_context io_context;
  struct timer
  {
    zr_boost_1_81::asio::system_timer t;
    timer() : t(io_context)
    {
      t.expires_at((zr_boost_1_81::asio::system_timer::time_point::max)());
    }
  } timers[50];

  timers[2].t.async_wait(timer_handler());
  timers[41].t.async_wait(timer_handler());
  for (int i = 10; i < 20; ++i)
    timers[i].t.async_wait(timer_handler());

  BOOST_ASIO_CHECK(timers[2].t.cancel() == 1);
  BOOST_ASIO_CHECK(timers[41].t.cancel() == 1);
  for (int i = 10; i < 20; ++i)
    BOOST_ASIO_CHECK(timers[i].t.cancel() == 1);
}

struct custom_allocation_timer_handler
{
  custom_allocation_timer_handler(int* count) : count_(count) {}
  void operator()(const zr_boost_1_81::system::error_code&) {}
  int* count_;

  template <typename T>
  struct allocator
  {
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T value_type;

    template <typename U>
    struct rebind
    {
      typedef allocator<U> other;
    };

    explicit allocator(int* count) BOOST_ASIO_NOEXCEPT
      : count_(count)
    {
    }

    allocator(const allocator& other) BOOST_ASIO_NOEXCEPT
      : count_(other.count_)
    {
    }

    template <typename U>
    allocator(const allocator<U>& other) BOOST_ASIO_NOEXCEPT
      : count_(other.count_)
    {
    }

    pointer allocate(size_type n, const void* = 0)
    {
      ++(*count_);
      return static_cast<T*>(::operator new(sizeof(T) * n));
    }

    void deallocate(pointer p, size_type)
    {
      --(*count_);
      ::operator delete(p);
    }

    size_type max_size() const
    {
      return ~size_type(0);
    }

    void construct(pointer p, const T& v)
    {
      new (p) T(v);
    }

    void destroy(pointer p)
    {
      p->~T();
    }

    int* count_;
  };

  typedef allocator<int> allocator_type;

  allocator_type get_allocator() const BOOST_ASIO_NOEXCEPT
  {
    return allocator_type(count_);
  }
};

void system_timer_custom_allocation_test()
{
  static zr_boost_1_81::asio::io_context io_context;
  struct timer
  {
    zr_boost_1_81::asio::system_timer t;
    timer() : t(io_context) {}
  } timers[100];

  int allocation_count = 0;

  for (int i = 0; i < 50; ++i)
  {
    timers[i].t.expires_at((zr_boost_1_81::asio::system_timer::time_point::max)());
    timers[i].t.async_wait(custom_allocation_timer_handler(&allocation_count));
  }

  for (int i = 50; i < 100; ++i)
  {
    timers[i].t.expires_at((zr_boost_1_81::asio::system_timer::time_point::min)());
    timers[i].t.async_wait(custom_allocation_timer_handler(&allocation_count));
  }

  for (int i = 0; i < 50; ++i)
    timers[i].t.cancel();

  io_context.run();

  BOOST_ASIO_CHECK(allocation_count == 0);
}

void io_context_run(zr_boost_1_81::asio::io_context* ioc)
{
  ioc->run();
}

void system_timer_thread_test()
{
  zr_boost_1_81::asio::io_context ioc;
  zr_boost_1_81::asio::executor_work_guard<zr_boost_1_81::asio::io_context::executor_type> work
    = zr_boost_1_81::asio::make_work_guard(ioc);
  zr_boost_1_81::asio::system_timer t1(ioc);
  zr_boost_1_81::asio::system_timer t2(ioc);
  int count = 0;

  zr_boost_1_81::asio::detail::thread th(bindns::bind(io_context_run, &ioc));

  t2.expires_after(zr_boost_1_81::asio::chrono::seconds(2));
  t2.wait();

  t1.expires_after(zr_boost_1_81::asio::chrono::seconds(2));
  t1.async_wait(bindns::bind(increment, &count));

  t2.expires_after(zr_boost_1_81::asio::chrono::seconds(4));
  t2.wait();

  ioc.stop();
  th.join();

  BOOST_ASIO_CHECK(count == 1);
}

#if defined(BOOST_ASIO_HAS_MOVE)
zr_boost_1_81::asio::system_timer make_timer(zr_boost_1_81::asio::io_context& ioc, int* count)
{
  zr_boost_1_81::asio::system_timer t(ioc);
  t.expires_after(zr_boost_1_81::asio::chrono::seconds(1));
  t.async_wait(bindns::bind(increment, count));
  return t;
}

typedef zr_boost_1_81::asio::basic_waitable_timer<
    zr_boost_1_81::asio::system_timer::clock_type,
    zr_boost_1_81::asio::system_timer::traits_type,
    zr_boost_1_81::asio::io_context::executor_type> io_context_system_timer;

io_context_system_timer make_convertible_timer(zr_boost_1_81::asio::io_context& ioc, int* count)
{
  io_context_system_timer t(ioc);
  t.expires_after(zr_boost_1_81::asio::chrono::seconds(1));
  t.async_wait(bindns::bind(increment, count));
  return t;
}
#endif

void system_timer_move_test()
{
#if defined(BOOST_ASIO_HAS_MOVE)
  zr_boost_1_81::asio::io_context io_context1;
  zr_boost_1_81::asio::io_context io_context2;
  int count = 0;

  zr_boost_1_81::asio::system_timer t1 = make_timer(io_context1, &count);
  zr_boost_1_81::asio::system_timer t2 = make_timer(io_context2, &count);
  zr_boost_1_81::asio::system_timer t3 = std::move(t1);

  t2 = std::move(t1);

  io_context2.run();

  BOOST_ASIO_CHECK(count == 1);

  io_context1.run();

  BOOST_ASIO_CHECK(count == 2);

  zr_boost_1_81::asio::system_timer t4 = make_convertible_timer(io_context1, &count);
  zr_boost_1_81::asio::system_timer t5 = make_convertible_timer(io_context2, &count);
  zr_boost_1_81::asio::system_timer t6 = std::move(t4);

  t2 = std::move(t4);

  io_context2.restart();
  io_context2.run();

  BOOST_ASIO_CHECK(count == 3);

  io_context1.restart();
  io_context1.run();

  BOOST_ASIO_CHECK(count == 4);
#endif // defined(BOOST_ASIO_HAS_MOVE)
}

void system_timer_op_cancel_test()
{
  zr_boost_1_81::asio::cancellation_signal cancel_signal;
  zr_boost_1_81::asio::io_context ioc;
  int count = 0;

  zr_boost_1_81::asio::system_timer timer(ioc, zr_boost_1_81::asio::chrono::seconds(10));

  timer.async_wait(bindns::bind(increment, &count));

  timer.async_wait(
      zr_boost_1_81::asio::bind_cancellation_slot(
        cancel_signal.slot(),
        bindns::bind(increment, &count)));

  timer.async_wait(bindns::bind(increment, &count));

  ioc.poll();

  BOOST_ASIO_CHECK(count == 0);
  BOOST_ASIO_CHECK(!ioc.stopped());

  cancel_signal.emit(zr_boost_1_81::asio::cancellation_type::all);

  ioc.run_one();
  ioc.poll();

  BOOST_ASIO_CHECK(count == 1);
  BOOST_ASIO_CHECK(!ioc.stopped());

  timer.cancel();

  ioc.run();

  BOOST_ASIO_CHECK(count == 3);
  BOOST_ASIO_CHECK(ioc.stopped());
}

BOOST_ASIO_TEST_SUITE
(
  "system_timer",
  BOOST_ASIO_TEST_CASE(system_timer_test)
  BOOST_ASIO_TEST_CASE(system_timer_cancel_test)
  BOOST_ASIO_TEST_CASE(system_timer_custom_allocation_test)
  BOOST_ASIO_TEST_CASE(system_timer_thread_test)
  BOOST_ASIO_TEST_CASE(system_timer_move_test)
  BOOST_ASIO_TEST_CASE(system_timer_op_cancel_test)
)
#else // defined(BOOST_ASIO_HAS_STD_CHRONO)
BOOST_ASIO_TEST_SUITE
(
  "system_timer",
  BOOST_ASIO_TEST_CASE(null_test)
)
#endif // defined(BOOST_ASIO_HAS_STD_CHRONO)