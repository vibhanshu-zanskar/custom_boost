/*
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * Copyright (c) 2017 Andrey Semashev
 */
/*!
 * \file   atomic/detail/type_traits/integral_constant.hpp
 *
 * This header defines \c integral_constant wrapper
 */

#ifndef BOOST_ATOMIC_DETAIL_TYPE_TRAITS_INTEGRAL_CONSTANT_HPP_INCLUDED_
#define BOOST_ATOMIC_DETAIL_TYPE_TRAITS_INTEGRAL_CONSTANT_HPP_INCLUDED_

#include <boost/atomic/detail/config.hpp>
#if !defined(BOOST_ATOMIC_DETAIL_NO_CXX11_BASIC_HDR_TYPE_TRAITS)
#include <type_traits>
#else
#include <boost/type_traits/integral_constant.hpp>
#endif

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

namespace zr_boost_1_81 {
namespace atomics {
namespace detail {

#if !defined(BOOST_ATOMIC_DETAIL_NO_CXX11_BASIC_HDR_TYPE_TRAITS)
using std::integral_constant;
using std::true_type;
using std::false_type;
#else
using zr_boost_1_81::integral_constant;
using zr_boost_1_81::true_type;
using zr_boost_1_81::false_type;
#endif

} // namespace detail
} // namespace atomics
} // namespace zr_boost_1_81

#endif // BOOST_ATOMIC_DETAIL_TYPE_TRAITS_INTEGRAL_CONSTANT_HPP_INCLUDED_
