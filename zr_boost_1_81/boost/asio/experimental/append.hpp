//
// experimental/append.hpp
// ~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_ASIO_EXPERIMENTAL_APPEND_HPP
#define BOOST_ASIO_EXPERIMENTAL_APPEND_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <boost/asio/detail/config.hpp>
#include <boost/asio/append.hpp>

#include <boost/asio/detail/push_options.hpp>

namespace zr_boost_1_81 {
namespace asio {
namespace experimental {

#if !defined(BOOST_ASIO_NO_DEPRECATED)
using zr_boost_1_81::asio::append_t;
using zr_boost_1_81::asio::append;
#endif // !defined(BOOST_ASIO_NO_DEPRECATED)

} // namespace experimental
} // namespace asio
} // namespace zr_boost_1_81

#include <boost/asio/detail/pop_options.hpp>

#endif // BOOST_ASIO_EXPERIMENTAL_APPEND_HPP
