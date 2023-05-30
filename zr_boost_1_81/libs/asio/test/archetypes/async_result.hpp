//
// async_result.hpp
// ~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef ARCHETYPES_ASYNC_RESULT_HPP
#define ARCHETYPES_ASYNC_RESULT_HPP

#include <boost/asio/async_result.hpp>

namespace archetypes {

struct lazy_handler
{
};

template <typename Signature>
struct concrete_handler;

template <typename R, typename Arg1>
struct concrete_handler<R(Arg1)>
{
  concrete_handler(lazy_handler)
  {
  }

  void operator()(typename zr_boost_1_81::asio::decay<Arg1>::type)
  {
  }

#if defined(BOOST_ASIO_HAS_MOVE)
  concrete_handler(concrete_handler&&) {}
private:
  concrete_handler(const concrete_handler&);
#endif // defined(BOOST_ASIO_HAS_MOVE)
};

template <typename R, typename Arg1, typename Arg2>
struct concrete_handler<R(Arg1, Arg2)>
{
  concrete_handler(lazy_handler)
  {
  }

  void operator()(typename zr_boost_1_81::asio::decay<Arg1>::type, typename zr_boost_1_81::asio::decay<Arg2>::type)
  {
  }

#if defined(BOOST_ASIO_HAS_MOVE)
  concrete_handler(concrete_handler&&) {}
private:
  concrete_handler(const concrete_handler&);
#endif // defined(BOOST_ASIO_HAS_MOVE)
};

} // namespace archetypes

namespace zr_boost_1_81 {
namespace asio {

template <typename Signature>
class async_result<archetypes::lazy_handler, Signature>
{
public:
  // The concrete completion handler type.
  typedef archetypes::concrete_handler<Signature> completion_handler_type;

  // The return type of the initiating function.
  typedef int return_type;

  // Construct an async_result from a given handler.
  explicit async_result(completion_handler_type&)
  {
  }

  // Obtain the value to be returned from the initiating function.
  return_type get()
  {
    return 42;
  }

private:
  // Disallow copying and assignment.
  async_result(const async_result&) BOOST_ASIO_DELETED;
  async_result& operator=(const async_result&) BOOST_ASIO_DELETED;
};

} // namespace asio
} // namespace zr_boost_1_81

#endif // ARCHETYPES_ASYNC_RESULT_HPP
