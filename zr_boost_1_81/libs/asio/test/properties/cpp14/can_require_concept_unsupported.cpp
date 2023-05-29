//
// cpp14/can_require_concept_unsupported.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <boost/asio/require_concept.hpp>
#include <cassert>

template <int>
struct prop
{
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
  static constexpr bool value = true;
};

} // namespace asio
} // namespace zr_boost_1_81

int main()
{
  static_assert(!zr_boost_1_81::asio::can_require_concept<object<1>, prop<2>>::value, "");
  static_assert(!zr_boost_1_81::asio::can_require_concept<const object<1>, prop<2>>::value, "");
}
