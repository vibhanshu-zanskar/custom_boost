//
// cpp03/can_query_not_applicable_static.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
namespace traits {

template<>
struct static_query<object, prop>
{
  static const bool is_valid = true;
  static const bool is_noexcept = true;
  typedef int result_type;
  static int value() { return 123; }
};

} // namespace traits
} // namespace asio
} // namespace zr_boost_1_81

int main()
{
  assert((!zr_boost_1_81::asio::can_query<object, prop>::value));
  assert((!zr_boost_1_81::asio::can_query<const object, prop>::value));
}