#ifndef BOOST_ENDIAN_DETAIL_IS_SCOPED_ENUM_HPP_INCLUDED
#define BOOST_ENDIAN_DETAIL_IS_SCOPED_ENUM_HPP_INCLUDED

// Copyright 2020 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost/type_traits/conditional.hpp>
#include <boost/type_traits/is_enum.hpp>
#include <boost/type_traits/is_convertible.hpp>

namespace zr_boost_1_81
{
namespace endian
{
namespace detail
{

template<class T> struct negation: zr_boost_1_81::integral_constant<bool, !T::value> {};

template<class T> struct is_scoped_enum:
    zr_boost_1_81::conditional<
        zr_boost_1_81::is_enum<T>::value,
        negation< zr_boost_1_81::is_convertible<T, int> >,
        zr_boost_1_81::false_type
    >::type
{
};

} // namespace detail
} // namespace endian
} // namespace zr_boost_1_81

#endif  // BOOST_ENDIAN_DETAIL_IS_SCOPED_ENUM_HPP_INCLUDED
