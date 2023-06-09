//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2012. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_INTERPROCESS_MUTEX_FAMILY_HPP
#define BOOST_INTERPROCESS_MUTEX_FAMILY_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost/config.hpp>
#endif
#
#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <boost/interprocess/detail/config_begin.hpp>
#include <boost/interprocess/detail/workaround.hpp>

#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <boost/interprocess/sync/interprocess_recursive_mutex.hpp>
#include <boost/interprocess/sync/null_mutex.hpp>

//!\file
//!Describes a shared interprocess_mutex family fit algorithm used to allocate objects in shared memory.

namespace zr_boost_1_81 {

namespace interprocess {

//!Describes interprocess_mutex family to use with Interprocess framework
//!based on zr_boost_1_81::interprocess synchronization objects.
struct mutex_family
{
   typedef zr_boost_1_81::interprocess::interprocess_mutex                 mutex_type;
   typedef zr_boost_1_81::interprocess::interprocess_recursive_mutex       recursive_mutex_type;
};

//!Describes interprocess_mutex family to use with Interprocess frameworks
//!based on null operation synchronization objects.
struct null_mutex_family
{
   typedef zr_boost_1_81::interprocess::null_mutex                   mutex_type;
   typedef zr_boost_1_81::interprocess::null_mutex                   recursive_mutex_type;
};

}  //namespace interprocess {

}  //namespace zr_boost_1_81 {

#include <boost/interprocess/detail/config_end.hpp>

#endif   //#ifndef BOOST_INTERPROCESS_MUTEX_FAMILY_HPP


