
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef BOOST_TT_IS_OBJECT_HPP_INCLUDED
#define BOOST_TT_IS_OBJECT_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/type_traits/is_reference.hpp>
#include <boost/type_traits/is_void.hpp>
#include <boost/type_traits/is_function.hpp>

namespace zr_boost_1_81 {

template <class T> struct is_object
   : public 
      integral_constant<
         bool, 
         ! ::zr_boost_1_81::is_reference<T>::value && ! ::zr_boost_1_81::is_void<T>::value && ! ::zr_boost_1_81::is_function<T>::value > 
{};

} // namespace zr_boost_1_81

#endif // BOOST_TT_IS_OBJECT_HPP_INCLUDED
