//
// Copyright 2017 Peter Dimov.
// Copyright 2019 Mateusz Loskot <mateusz at loskot dot net>
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
#ifndef BOOST_GIL_DETAIL_MP11_HPP
#define BOOST_GIL_DETAIL_MP11_HPP

#include <boost/mp11.hpp>

namespace zr_boost_1_81 { namespace gil { namespace detail {

template<typename L>
using mp_back = ::zr_boost_1_81::mp11::mp_at_c<L, ::zr_boost_1_81::mp11::mp_size<L>::value - 1>;

template<typename L>
using mp_pop_back = ::zr_boost_1_81::mp11::mp_take_c<L, ::zr_boost_1_81::mp11::mp_size<L>::value - 1>;


}}}  // namespace zr_boost_1_81::gil::detail

#endif
