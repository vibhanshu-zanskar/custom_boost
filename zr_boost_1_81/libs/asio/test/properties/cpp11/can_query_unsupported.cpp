//
// cpp11/can_query_unsupported.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <boost/asio/query.hpp>
#include <cassert>

struct prop
{
};

struct object
{
};

namespace zr_boost_1_81 {
namespace asio {

template<>
struct is_applicable_property<object, prop>
{
  static constexpr bool value = true;
};

} // namespace asio
} // namespace zr_boost_1_81

int main()
{
  static_assert(!zr_boost_1_81::asio::can_query<object, prop>::value, "");
  static_assert(!zr_boost_1_81::asio::can_query<const object, prop>::value, "");
}