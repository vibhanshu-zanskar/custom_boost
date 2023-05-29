//
// cpp14/prefer_member_prefer.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
  template <typename> static constexpr bool is_applicable_property_v = true;
  static constexpr bool is_preferable = true;
};

template <int>
struct object
{
  template <int N>
  constexpr object<N> prefer(prop<N>) const
  {
    return object<N>();
  }
};

int main()
{
  object<1> o1 = {};
  object<2> o2 = zr_boost_1_81::asio::prefer(o1, prop<2>());
  object<3> o3 = zr_boost_1_81::asio::prefer(o1, prop<2>(), prop<3>());
  object<4> o4 = zr_boost_1_81::asio::prefer(o1, prop<2>(), prop<3>(), prop<4>());
  (void)o2;
  (void)o3;
  (void)o4;

  const object<1> o5 = {};
  object<2> o6 = zr_boost_1_81::asio::prefer(o5, prop<2>());
  object<3> o7 = zr_boost_1_81::asio::prefer(o5, prop<2>(), prop<3>());
  object<4> o8 = zr_boost_1_81::asio::prefer(o5, prop<2>(), prop<3>(), prop<4>());
  (void)o6;
  (void)o7;
  (void)o8;

  constexpr object<2> o9 = zr_boost_1_81::asio::prefer(object<1>(), prop<2>());
  constexpr object<3> o10 = zr_boost_1_81::asio::prefer(object<1>(), prop<2>(), prop<3>());
  constexpr object<4> o11 = zr_boost_1_81::asio::prefer(object<1>(), prop<2>(), prop<3>(), prop<4>());
  (void)o9;
  (void)o10;
  (void)o11;
}
