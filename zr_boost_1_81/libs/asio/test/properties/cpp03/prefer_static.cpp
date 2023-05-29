//
// cpp03/prefer_static.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <boost/asio/prefer.hpp>
#include <cassert>

template <int>
struct prop
{
  static const bool is_preferable = true;
};

template <int>
struct object
{
};

namespace zr_boost_1_81 {
namespace asio {

template<int N, int M>
struct is_applicable_property<object<N>, prop<M> >
{
  static const bool value = true;
};

namespace traits {

template<int N>
struct static_require<object<N>, prop<N> >
{
  static const bool is_valid = true;
};

} // namespace traits
} // namespace asio
} // namespace zr_boost_1_81

int main()
{
  object<1> o1 = {};
  object<1> o2 = zr_boost_1_81::asio::prefer(o1, prop<1>());
  object<1> o3 = zr_boost_1_81::asio::prefer(o1, prop<1>(), prop<1>());
  object<1> o4 = zr_boost_1_81::asio::prefer(o1, prop<1>(), prop<1>(), prop<1>());
  (void)o2;
  (void)o3;
  (void)o4;

  const object<1> o5 = {};
  object<1> o6 = zr_boost_1_81::asio::prefer(o5, prop<1>());
  object<1> o7 = zr_boost_1_81::asio::prefer(o5, prop<1>(), prop<1>());
  object<1> o8 = zr_boost_1_81::asio::prefer(o5, prop<1>(), prop<1>(), prop<1>());
  (void)o6;
  (void)o7;
  (void)o8;
}
