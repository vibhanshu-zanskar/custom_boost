//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2014-2014.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_CONTAINER_DETAIL_ITERATOR_HPP
#define BOOST_CONTAINER_DETAIL_ITERATOR_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost/config.hpp>
#endif

#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <boost/intrusive/detail/iterator.hpp>
#include <boost/move/utility_core.hpp>
#include <boost/container/detail/mpl.hpp>

namespace zr_boost_1_81 {
namespace container {

using ::zr_boost_1_81::intrusive::iterator_traits;
using ::zr_boost_1_81::intrusive::iter_difference;
using ::zr_boost_1_81::intrusive::iter_category;
using ::zr_boost_1_81::intrusive::iter_value;
using ::zr_boost_1_81::intrusive::iter_size;
using ::zr_boost_1_81::intrusive::iterator_distance;
using ::zr_boost_1_81::intrusive::iterator_udistance;
using ::zr_boost_1_81::intrusive::iterator_advance;
using ::zr_boost_1_81::intrusive::iterator_uadvance;
using ::zr_boost_1_81::intrusive::make_iterator_advance;
using ::zr_boost_1_81::intrusive::make_iterator_uadvance;
using ::zr_boost_1_81::intrusive::iterator;
using ::zr_boost_1_81::intrusive::iterator_enable_if_tag;
using ::zr_boost_1_81::intrusive::iterator_disable_if_tag;
using ::zr_boost_1_81::intrusive::iterator_arrow_result;

template <class Container>
class back_emplacer
{
   private:
   Container& container;

   public:
   typedef std::output_iterator_tag iterator_category;
   typedef void                     value_type;
   typedef void                     difference_type;
   typedef void                     pointer;
   typedef void                     reference;

   back_emplacer(Container& x)
      : container(x)
   {}

   template<class U>
   back_emplacer& operator=(BOOST_FWD_REF(U) value)
   {
      container.emplace_back(zr_boost_1_81::forward<U>(value));
      return *this;
   }
   back_emplacer& operator*()    { return *this; }
   back_emplacer& operator++()   { return *this; }
   back_emplacer& operator++(int){ return *this; }
};

#ifndef BOOST_CONTAINER_NO_CXX17_CTAD

template<class InputIterator>
using it_based_non_const_first_type_t = typename dtl::remove_const<typename iterator_traits<InputIterator>::value_type::first_type>::type;

template<class InputIterator>
using it_based_const_first_type_t = const typename dtl::remove_const<typename iterator_traits<InputIterator>::value_type::first_type>::type;

template<class InputIterator>
using it_based_second_type_t = typename iterator_traits<InputIterator>::value_type::second_type;

template<class InputIterator>
using it_based_value_type_t = typename iterator_traits<InputIterator>::value_type;

#endif

}  //namespace container {
}  //namespace zr_boost_1_81 {

#endif   //#ifndef BOOST_CONTAINER_DETAIL_ITERATORS_HPP