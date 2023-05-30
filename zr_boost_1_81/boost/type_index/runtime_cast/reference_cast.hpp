//
// Copyright (c) Chris Glover, 2016.
//
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_TYPE_INDEX_RUNTIME_CAST_REFERENCE_CAST_HPP
#define BOOST_TYPE_INDEX_RUNTIME_CAST_REFERENCE_CAST_HPP

/// \file reference_cast.hpp
/// \brief Contains the overload of zr_boost_1_81::typeindex::runtime_cast for
/// reference types.

#include <boost/core/addressof.hpp>
#include <boost/type_index/runtime_cast/detail/runtime_cast_impl.hpp>
#include <boost/throw_exception.hpp>
#include <boost/type_traits/add_reference.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <boost/type_traits/is_base_and_derived.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
# pragma once
#endif

namespace zr_boost_1_81 { namespace typeindex {

/// \brief Indicates that runtime_cast was unable to perform the desired cast operation
/// because the source instance was not also an instance of the target type.
struct bad_runtime_cast : std::exception
{};

/// \brief Safely converts references to classes up, down, and sideways along the inheritance hierarchy.
/// \tparam T The desired target type. Like dynamic_cast, must be a pointer to complete class type.
/// \tparam U A complete class type of the source instance, u.
/// \return If there exists a valid conversion from U& to T, returns a T that references an address
/// suitably offset from u. If no such conversion exists, throws zr_boost_1_81::typeindex::bad_runtime_cast.
template<typename T, typename U>
typename zr_boost_1_81::add_reference<T>::type runtime_cast(U& u) {
    typedef typename zr_boost_1_81::remove_reference<T>::type impl_type;
    impl_type* value = detail::runtime_cast_impl<impl_type>(
        zr_boost_1_81::addressof(u), zr_boost_1_81::is_base_and_derived<T, U>());
    if(!value)
        BOOST_THROW_EXCEPTION(bad_runtime_cast());
    return *value;
}

/// \brief Safely converts references to classes up, down, and sideways along the inheritance hierarchy.
/// \tparam T The desired target type. Like dynamic_cast, must be a pointer to complete class type.
/// \tparam U A complete class type of the source instance, u.
/// \return If there exists a valid conversion from U const& to T const, returns a T const that references an address
/// suitably offset from u. If no such conversion exists, throws zr_boost_1_81::typeindex::bad_runtime_cast.
template<typename T, typename U>
typename zr_boost_1_81::add_reference<const T>::type runtime_cast(U const& u) {
    typedef typename zr_boost_1_81::remove_reference<T>::type impl_type;
    impl_type* value = detail::runtime_cast_impl<impl_type>(
        zr_boost_1_81::addressof(u), zr_boost_1_81::is_base_and_derived<T, U>());
    if(!value)
        BOOST_THROW_EXCEPTION(bad_runtime_cast());
    return *value;
}

}} // namespace zr_boost_1_81::typeindex

#endif // BOOST_TYPE_INDEX_RUNTIME_CAST_REFERENCE_CAST_HPP
