//
// placeholders.hpp
// ~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_ASIO_PLACEHOLDERS_HPP
#define BOOST_ASIO_PLACEHOLDERS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <boost/asio/detail/config.hpp>

#if defined(BOOST_ASIO_HAS_BOOST_BIND)
# include <boost/bind/arg.hpp>
#endif // defined(BOOST_ASIO_HAS_BOOST_BIND)

#include <boost/asio/detail/push_options.hpp>

namespace zr_boost_1_81 {
namespace asio {
namespace placeholders {

#if defined(GENERATING_DOCUMENTATION)

/// An argument placeholder, for use with zr_boost_1_81::bind(), that corresponds to
/// the error argument of a handler for any of the asynchronous functions.
unspecified error;

/// An argument placeholder, for use with zr_boost_1_81::bind(), that corresponds to
/// the bytes_transferred argument of a handler for asynchronous functions such
/// as zr_boost_1_81::asio::basic_stream_socket::async_write_some or
/// zr_boost_1_81::asio::async_write.
unspecified bytes_transferred;

/// An argument placeholder, for use with zr_boost_1_81::bind(), that corresponds to
/// the iterator argument of a handler for asynchronous functions such as
/// zr_boost_1_81::asio::async_connect.
unspecified iterator;

/// An argument placeholder, for use with zr_boost_1_81::bind(), that corresponds to
/// the results argument of a handler for asynchronous functions such as
/// zr_boost_1_81::asio::basic_resolver::async_resolve.
unspecified results;

/// An argument placeholder, for use with zr_boost_1_81::bind(), that corresponds to
/// the results argument of a handler for asynchronous functions such as
/// zr_boost_1_81::asio::async_connect.
unspecified endpoint;

/// An argument placeholder, for use with zr_boost_1_81::bind(), that corresponds to
/// the signal_number argument of a handler for asynchronous functions such as
/// zr_boost_1_81::asio::signal_set::async_wait.
unspecified signal_number;

#elif defined(BOOST_ASIO_HAS_BOOST_BIND)
# if defined(__BORLANDC__) || defined(__GNUC__)

inline zr_boost_1_81::arg<1> error()
{
  return zr_boost_1_81::arg<1>();
}

inline zr_boost_1_81::arg<2> bytes_transferred()
{
  return zr_boost_1_81::arg<2>();
}

inline zr_boost_1_81::arg<2> iterator()
{
  return zr_boost_1_81::arg<2>();
}

inline zr_boost_1_81::arg<2> results()
{
  return zr_boost_1_81::arg<2>();
}

inline zr_boost_1_81::arg<2> endpoint()
{
  return zr_boost_1_81::arg<2>();
}

inline zr_boost_1_81::arg<2> signal_number()
{
  return zr_boost_1_81::arg<2>();
}

# else

namespace detail
{
  template <int Number>
  struct placeholder
  {
    static zr_boost_1_81::arg<Number>& get()
    {
      static zr_boost_1_81::arg<Number> result;
      return result;
    }
  };
}

#  if defined(BOOST_ASIO_MSVC) && (BOOST_ASIO_MSVC < 1400)

static zr_boost_1_81::arg<1>& error
  = zr_boost_1_81::asio::placeholders::detail::placeholder<1>::get();
static zr_boost_1_81::arg<2>& bytes_transferred
  = zr_boost_1_81::asio::placeholders::detail::placeholder<2>::get();
static zr_boost_1_81::arg<2>& iterator
  = zr_boost_1_81::asio::placeholders::detail::placeholder<2>::get();
static zr_boost_1_81::arg<2>& results
  = zr_boost_1_81::asio::placeholders::detail::placeholder<2>::get();
static zr_boost_1_81::arg<2>& endpoint
  = zr_boost_1_81::asio::placeholders::detail::placeholder<2>::get();
static zr_boost_1_81::arg<2>& signal_number
  = zr_boost_1_81::asio::placeholders::detail::placeholder<2>::get();

#  else

namespace
{
  zr_boost_1_81::arg<1>& error
    = zr_boost_1_81::asio::placeholders::detail::placeholder<1>::get();
  zr_boost_1_81::arg<2>& bytes_transferred
    = zr_boost_1_81::asio::placeholders::detail::placeholder<2>::get();
  zr_boost_1_81::arg<2>& iterator
    = zr_boost_1_81::asio::placeholders::detail::placeholder<2>::get();
  zr_boost_1_81::arg<2>& results
    = zr_boost_1_81::asio::placeholders::detail::placeholder<2>::get();
  zr_boost_1_81::arg<2>& endpoint
    = zr_boost_1_81::asio::placeholders::detail::placeholder<2>::get();
  zr_boost_1_81::arg<2>& signal_number
    = zr_boost_1_81::asio::placeholders::detail::placeholder<2>::get();
} // namespace

#  endif
# endif
#endif

} // namespace placeholders
} // namespace asio
} // namespace zr_boost_1_81

#include <boost/asio/detail/pop_options.hpp>

#endif // BOOST_ASIO_PLACEHOLDERS_HPP
