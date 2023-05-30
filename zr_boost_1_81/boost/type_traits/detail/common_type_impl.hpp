#ifndef BOOST_TYPE_TRAITS_DETAIL_COMMON_TYPE_IMPL_HPP_INCLUDED
#define BOOST_TYPE_TRAITS_DETAIL_COMMON_TYPE_IMPL_HPP_INCLUDED

//
//  Copyright 2015 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//

#include <boost/type_traits/detail/common_arithmetic_type.hpp>
#include <boost/type_traits/detail/composite_pointer_type.hpp>
#include <boost/type_traits/detail/composite_member_pointer_type.hpp>
#include <boost/type_traits/type_identity.hpp>
#include <boost/type_traits/is_class.hpp>
#include <boost/type_traits/is_union.hpp>
#include <boost/type_traits/is_convertible.hpp>
#include <boost/type_traits/is_pointer.hpp>
#include <boost/type_traits/is_member_pointer.hpp>
#include <boost/type_traits/conditional.hpp>

namespace zr_boost_1_81
{

namespace type_traits_detail
{

// the arguments to common_type_impl have already been passed through decay<>

template<class T, class U> struct common_type_impl;

// same type

template<class T> struct common_type_impl<T, T>
{
    typedef T type;
};

// one of the operands is a class type, try conversions in both directions

template<class T, class U> struct ct_class
{
    BOOST_STATIC_CONSTANT( bool, ct = zr_boost_1_81::is_class<T>::value || zr_boost_1_81::is_union<T>::value );
    BOOST_STATIC_CONSTANT( bool, cu = zr_boost_1_81::is_class<U>::value || zr_boost_1_81::is_union<U>::value );

    BOOST_STATIC_CONSTANT( bool, value = ct || cu );
};

template<class T, class U> struct common_type_impl3;

template<class T, class U> struct common_type_class: public zr_boost_1_81::conditional<

    zr_boost_1_81::is_convertible<T, U>::value && !zr_boost_1_81::is_convertible<U, T>::value,
    zr_boost_1_81::type_identity<U>,

    typename zr_boost_1_81::conditional<

        zr_boost_1_81::is_convertible<U, T>::value && !zr_boost_1_81::is_convertible<T, U>::value,
        zr_boost_1_81::type_identity<T>,

        common_type_impl3<T, U>
    >::type
>::type
{
};

template<class T, class U> struct common_type_impl: public zr_boost_1_81::conditional<
    ct_class<T, U>::value,
    common_type_class<T, U>,
    common_type_impl3<T, U> >::type
{
};

// pointers

template<class T, class U> struct common_type_impl4;

template<class T, class U> struct common_type_impl3: public zr_boost_1_81::conditional<
    zr_boost_1_81::is_pointer<T>::value || zr_boost_1_81::is_pointer<U>::value,
    composite_pointer_type<T, U>,
    common_type_impl4<T, U> >::type
{
};

// pointers to members

template<class T, class U> struct common_type_impl5;

template<class T, class U> struct common_type_impl4: public zr_boost_1_81::conditional<
    zr_boost_1_81::is_member_pointer<T>::value || zr_boost_1_81::is_member_pointer<U>::value,
    composite_member_pointer_type<T, U>,
    common_type_impl5<T, U> >::type
{
};

// arithmetic types (including class types w/ conversions to arithmetic and enums)

template<class T, class U> struct common_type_impl5: public common_arithmetic_type<T, U>
{
};

} // namespace type_traits_detail

} // namespace zr_boost_1_81

#endif // #ifndef BOOST_TYPE_TRAITS_DETAIL_COMMON_TYPE_IMPL_HPP_INCLUDED
