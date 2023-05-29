//
// cpp11/query_free.cpp
// ~~~~~~~~~~~~~~~~~~~~
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
  friend constexpr int query(const object&, prop) { return 123; }
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
  object o1 = {};
  int result1 = zr_boost_1_81::asio::query(o1, prop());
  assert(result1 == 123);
  (void)result1;

  const object o2 = {};
  int result2 = zr_boost_1_81::asio::query(o2, prop());
  assert(result2 == 123);
  (void)result2;

  constexpr object o3 = {};
  constexpr int result3 = zr_boost_1_81::asio::query(o3, prop());
  assert(result3 == 123);
  (void)result3;
}
