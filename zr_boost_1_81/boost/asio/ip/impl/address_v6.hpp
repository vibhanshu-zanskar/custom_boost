//
// ip/impl/address_v6.hpp
// ~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_ASIO_IP_IMPL_ADDRESS_V6_HPP
#define BOOST_ASIO_IP_IMPL_ADDRESS_V6_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#if !defined(BOOST_ASIO_NO_IOSTREAM)

#include <boost/asio/detail/throw_error.hpp>

#include <boost/asio/detail/push_options.hpp>

namespace zr_boost_1_81 {
namespace asio {
namespace ip {

#if !defined(BOOST_ASIO_NO_DEPRECATED)

inline address_v6 address_v6::from_string(const char* str)
{
  return zr_boost_1_81::asio::ip::make_address_v6(str);
}

inline address_v6 address_v6::from_string(
    const char* str, zr_boost_1_81::system::error_code& ec)
{
  return zr_boost_1_81::asio::ip::make_address_v6(str, ec);
}

inline address_v6 address_v6::from_string(const std::string& str)
{
  return zr_boost_1_81::asio::ip::make_address_v6(str);
}

inline address_v6 address_v6::from_string(
    const std::string& str, zr_boost_1_81::system::error_code& ec)
{
  return zr_boost_1_81::asio::ip::make_address_v6(str, ec);
}

#endif // !defined(BOOST_ASIO_NO_DEPRECATED)

template <typename Elem, typename Traits>
std::basic_ostream<Elem, Traits>& operator<<(
    std::basic_ostream<Elem, Traits>& os, const address_v6& addr)
{
  return os << addr.to_string().c_str();
}

} // namespace ip
} // namespace asio
} // namespace zr_boost_1_81

#include <boost/asio/detail/pop_options.hpp>

#endif // !defined(BOOST_ASIO_NO_IOSTREAM)

#endif // BOOST_ASIO_IP_IMPL_ADDRESS_V6_HPP
