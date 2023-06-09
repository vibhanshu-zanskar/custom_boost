//  (C) Copyright Dave Abrahams, Steve Cleary, Beman Dawes, Howard
//  Hinnant & John Maddock 2000-2003.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.


#ifndef BOOST_TT_IS_CLASS_HPP_INCLUDED
#define BOOST_TT_IS_CLASS_HPP_INCLUDED

#include <boost/type_traits/detail/config.hpp>
#include <boost/type_traits/intrinsics.hpp>
#include <boost/type_traits/integral_constant.hpp>
#ifndef BOOST_IS_CLASS
#   include <boost/type_traits/is_union.hpp>

#ifdef BOOST_TT_HAS_CONFORMING_IS_CLASS_IMPLEMENTATION
#   include <boost/type_traits/detail/yes_no_type.hpp>
#else
#   include <boost/type_traits/is_scalar.hpp>
#   include <boost/type_traits/is_array.hpp>
#   include <boost/type_traits/is_reference.hpp>
#   include <boost/type_traits/is_void.hpp>
#   include <boost/type_traits/is_function.hpp>
#endif

#endif // BOOST_IS_CLASS

namespace zr_boost_1_81 {

namespace detail {

#ifndef BOOST_IS_CLASS
#ifdef BOOST_TT_HAS_CONFORMING_IS_CLASS_IMPLEMENTATION

// This is actually the conforming implementation which works with
// abstract classes.  However, enough compilers have trouble with
// it that most will use the one in
// boost/type_traits/object_traits.hpp. This implementation
// actually works with VC7.0, but other interactions seem to fail
// when we use it.

// is_class<> metafunction due to Paul Mensonides
// (leavings@attbi.com). For more details:
// http://groups.google.com/groups?hl=en&selm=000001c1cc83%24e154d5e0%247772e50c%40c161550a&rnum=1
#if defined(__GNUC__)  && !defined(__EDG_VERSION__)

template <class U> ::zr_boost_1_81::type_traits::yes_type is_class_tester(void(U::*)(void));
template <class U> ::zr_boost_1_81::type_traits::no_type is_class_tester(...);

template <typename T>
struct is_class_impl
{

    BOOST_STATIC_CONSTANT(bool, value =
            sizeof(is_class_tester<T>(0)) == sizeof(::zr_boost_1_81::type_traits::yes_type)
            && ! ::zr_boost_1_81::is_union<T>::value
        );
};

#else

template <typename T>
struct is_class_impl
{
    template <class U> static ::zr_boost_1_81::type_traits::yes_type is_class_tester(void(U::*)(void));
    template <class U> static ::zr_boost_1_81::type_traits::no_type is_class_tester(...);

    BOOST_STATIC_CONSTANT(bool, value =
            sizeof(is_class_tester<T>(0)) == sizeof(::zr_boost_1_81::type_traits::yes_type)
            && ! ::zr_boost_1_81::is_union<T>::value
        );
};

#endif

#else

template <typename T>
struct is_class_impl
{
    BOOST_STATIC_CONSTANT(bool, value =
        ! ::zr_boost_1_81::is_union<T>::value >::value
        && ! ::zr_boost_1_81::is_scalar<T>::value
        && ! ::zr_boost_1_81::is_array<T>::value
        && ! ::zr_boost_1_81::is_reference<T>::value
        && ! ::zr_boost_1_81::is_void<T>::value
        && ! ::zr_boost_1_81::is_function<T>::value
        );
};

# endif // BOOST_TT_HAS_CONFORMING_IS_CLASS_IMPLEMENTATION
# else // BOOST_IS_CLASS
template <typename T>
struct is_class_impl
{
    BOOST_STATIC_CONSTANT(bool, value = BOOST_IS_CLASS(T));
};
# endif // BOOST_IS_CLASS

} // namespace detail

template <class T> struct is_class : public integral_constant<bool, ::zr_boost_1_81::detail::is_class_impl<T>::value> {};
# ifdef __EDG_VERSION__
template <class T> struct is_class<const T> : public is_class<T>{};
template <class T> struct is_class<const volatile T> : public is_class<T>{};
template <class T> struct is_class<volatile T> : public is_class<T>{};
# endif
    
} // namespace zr_boost_1_81

#endif // BOOST_TT_IS_CLASS_HPP_INCLUDED
