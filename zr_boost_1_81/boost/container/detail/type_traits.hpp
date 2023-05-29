//////////////////////////////////////////////////////////////////////////////
// (C) Copyright John Maddock 2000.
// (C) Copyright Ion Gaztanaga 2005-2015.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/container for documentation.
//
// The alignment and Type traits implementation comes from
// John Maddock's TypeTraits library.
//
// Some other tricks come from Howard Hinnant's papers and StackOverflow replies
//////////////////////////////////////////////////////////////////////////////
#ifndef BOOST_CONTAINER_CONTAINER_DETAIL_TYPE_TRAITS_HPP
#define BOOST_CONTAINER_CONTAINER_DETAIL_TYPE_TRAITS_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost/config.hpp>
#endif

#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <boost/move/detail/type_traits.hpp>

namespace zr_boost_1_81 {
namespace container {
namespace dtl {

using ::zr_boost_1_81::move_detail::enable_if;
using ::zr_boost_1_81::move_detail::enable_if_and;
using ::zr_boost_1_81::move_detail::is_same;
using ::zr_boost_1_81::move_detail::is_different;
using ::zr_boost_1_81::move_detail::is_pointer;
using ::zr_boost_1_81::move_detail::add_reference;
using ::zr_boost_1_81::move_detail::add_const;
using ::zr_boost_1_81::move_detail::add_const_reference;
using ::zr_boost_1_81::move_detail::remove_const;
using ::zr_boost_1_81::move_detail::remove_reference;
using ::zr_boost_1_81::move_detail::remove_cvref;
using ::zr_boost_1_81::move_detail::make_unsigned;
using ::zr_boost_1_81::move_detail::is_floating_point;
using ::zr_boost_1_81::move_detail::is_integral;
using ::zr_boost_1_81::move_detail::is_enum;
using ::zr_boost_1_81::move_detail::is_pod;
using ::zr_boost_1_81::move_detail::is_empty;
using ::zr_boost_1_81::move_detail::is_trivially_destructible;
using ::zr_boost_1_81::move_detail::is_trivially_default_constructible;
using ::zr_boost_1_81::move_detail::is_trivially_copy_constructible;
using ::zr_boost_1_81::move_detail::is_trivially_move_constructible;
using ::zr_boost_1_81::move_detail::is_trivially_copy_assignable;
using ::zr_boost_1_81::move_detail::is_trivially_move_assignable;
using ::zr_boost_1_81::move_detail::is_nothrow_default_constructible;
using ::zr_boost_1_81::move_detail::is_nothrow_copy_constructible;
using ::zr_boost_1_81::move_detail::is_nothrow_move_constructible;
using ::zr_boost_1_81::move_detail::is_nothrow_copy_assignable;
using ::zr_boost_1_81::move_detail::is_nothrow_move_assignable;
using ::zr_boost_1_81::move_detail::is_nothrow_swappable;
using ::zr_boost_1_81::move_detail::alignment_of;
using ::zr_boost_1_81::move_detail::aligned_storage;
using ::zr_boost_1_81::move_detail::nat;
using ::zr_boost_1_81::move_detail::nat2;
using ::zr_boost_1_81::move_detail::nat3;
using ::zr_boost_1_81::move_detail::natN;
using ::zr_boost_1_81::move_detail::max_align_t;
using ::zr_boost_1_81::move_detail::is_convertible;

}  //namespace dtl {
}  //namespace container {
}  //namespace zr_boost_1_81 {

#endif   //#ifndef BOOST_CONTAINER_CONTAINER_DETAIL_TYPE_TRAITS_HPP
