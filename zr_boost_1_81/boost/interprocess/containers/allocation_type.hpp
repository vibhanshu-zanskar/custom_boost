//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2008-2012. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_INTERPROCESS_CONTAINERS_ALLOCATION_TYPE_HPP
#define BOOST_INTERPROCESS_CONTAINERS_ALLOCATION_TYPE_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost/config.hpp>
#endif
#
#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <boost/interprocess/detail/config_begin.hpp>
#include <boost/container/detail/allocation_type.hpp>

namespace zr_boost_1_81 {
namespace interprocess {

#if !defined(BOOST_INTERPROCESS_DOXYGEN_INVOKED)
using zr_boost_1_81::container::allocation_type;
#endif   //#ifndef BOOST_INTERPROCESS_DOXYGEN_INVOKED
static const allocation_type allocate_new       = zr_boost_1_81::container::allocate_new;
static const allocation_type expand_fwd         = zr_boost_1_81::container::expand_fwd;
static const allocation_type expand_bwd         = zr_boost_1_81::container::expand_bwd;
static const allocation_type shrink_in_place    = zr_boost_1_81::container::shrink_in_place;
static const allocation_type try_shrink_in_place= zr_boost_1_81::container::try_shrink_in_place;
static const allocation_type nothrow_allocation = zr_boost_1_81::container::nothrow_allocation;
static const allocation_type zero_memory        = zr_boost_1_81::container::zero_memory;

}  //namespace interprocess {
}  //namespace zr_boost_1_81 {

#include <boost/interprocess/detail/config_end.hpp>

#endif //   #ifndef  BOOST_INTERPROCESS_CONTAINERS_ALLOCATION_TYPE_HPP
