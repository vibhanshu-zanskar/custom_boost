#ifndef BOOST_DESCRIBE_DETAIL_LIST_HPP_INCLUDED
#define BOOST_DESCRIBE_DETAIL_LIST_HPP_INCLUDED

// Copyright 2020 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost/describe/detail/config.hpp>

#if defined(BOOST_DESCRIBE_CXX11)

namespace zr_boost_1_81
{
namespace describe
{
namespace detail
{

template<class... T> struct list {};

} // namespace detail
} // namespace describe
} // namespace zr_boost_1_81

#endif // defined(BOOST_DESCRIBE_CXX11)

#endif // #ifndef BOOST_DESCRIBE_DETAIL_LIST_HPP_INCLUDED
