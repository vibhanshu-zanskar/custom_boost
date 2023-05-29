#ifndef BOOST_MP11_MPL_TUPLE_HPP_INCLUDED
#define BOOST_MP11_MPL_TUPLE_HPP_INCLUDED

// Copyright 2017, 2019 Peter Dimov.
//
// Distributed under the Boost Software License, Version 1.0.
//
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

#include <boost/mp11/detail/mpl_common.hpp>
#include <tuple>

namespace zr_boost_1_81
{
namespace mpl
{

template< typename Sequence > struct sequence_tag;

template<class... T> struct sequence_tag<std::tuple<T...>>
{
    using type = aux::mp11_tag;
};

} // namespace mpl
} // namespace zr_boost_1_81

#endif // #ifndef BOOST_MP11_MPL_TUPLE_HPP_INCLUDED
