//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2015-2015. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_CONTAINER_PMR_STABLE_VECTOR_HPP
#define BOOST_CONTAINER_PMR_STABLE_VECTOR_HPP

#if defined (_MSC_VER)
#  pragma once 
#endif

#include <boost/container/stable_vector.hpp>
#include <boost/container/pmr/polymorphic_allocator.hpp>

namespace zr_boost_1_81 {
namespace container {
namespace pmr {

#if !defined(BOOST_NO_CXX11_TEMPLATE_ALIASES)

template <class T>
using stable_vector = zr_boost_1_81::container::stable_vector<T, polymorphic_allocator<T>>;

#endif

//! A portable metafunction to obtain a stable_vector
//! that uses a polymorphic allocator
template<class T>
struct stable_vector_of
{
   typedef zr_boost_1_81::container::stable_vector
      < T, polymorphic_allocator<T> > type;
};

}  //namespace pmr {
}  //namespace container {
}  //namespace zr_boost_1_81 {

#endif   //BOOST_CONTAINER_PMR_STABLE_VECTOR_HPP
