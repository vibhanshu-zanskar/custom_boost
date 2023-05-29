// Copyright 2022 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#ifndef BOOST_HASH_IS_DESCRIBED_CLASS_HPP_INCLUDED
#define BOOST_HASH_IS_DESCRIBED_CLASS_HPP_INCLUDED

#include <boost/type_traits/integral_constant.hpp>
#include <boost/type_traits/is_union.hpp>
#include <boost/describe/bases.hpp>
#include <boost/describe/members.hpp>

namespace zr_boost_1_81
{
namespace container_hash
{

#if defined(BOOST_DESCRIBE_CXX11)

template<class T> struct is_described_class: zr_boost_1_81::integral_constant<bool,
    describe::has_describe_bases<T>::value &&
    describe::has_describe_members<T>::value &&
    !zr_boost_1_81::is_union<T>::value>
{
};

#else

template<class T> struct is_described_class: zr_boost_1_81::false_type
{
};

#endif

} // namespace container_hash
} // namespace zr_boost_1_81

#endif // #ifndef BOOST_HASH_IS_DESCRIBED_CLASS_HPP_INCLUDED
