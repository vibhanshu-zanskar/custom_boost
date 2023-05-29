//-----------------------------------------------------------------------------
// boost variant/detail/element_index.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014-2022 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_VARIANT_DETAIL_ELEMENT_INDEX_HPP
#define BOOST_VARIANT_DETAIL_ELEMENT_INDEX_HPP

#include <boost/config.hpp>
#include <boost/variant/recursive_wrapper_fwd.hpp>
#include <boost/variant/variant_fwd.hpp>

#include <boost/type_traits/remove_cv.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <boost/mpl/find_if.hpp>

namespace zr_boost_1_81 { namespace detail { namespace variant {

template <class VariantElement, class T>
struct variant_element_functor :
    zr_boost_1_81::mpl::or_<
        zr_boost_1_81::is_same<VariantElement, T>,
        zr_boost_1_81::is_same<VariantElement, zr_boost_1_81::recursive_wrapper<T> >,
        zr_boost_1_81::is_same<VariantElement, T& >
    >
{};

template <class Types, class T>
struct element_iterator_impl :
    zr_boost_1_81::mpl::find_if<
        Types,
        zr_boost_1_81::mpl::or_<
            variant_element_functor<zr_boost_1_81::mpl::_1, T>,
            variant_element_functor<zr_boost_1_81::mpl::_1, typename zr_boost_1_81::remove_cv<T>::type >
        >
    >
{};

template <class Variant, class T>
struct element_iterator :
    element_iterator_impl< typename Variant::types, typename zr_boost_1_81::remove_reference<T>::type >
{};

template <class Variant, class T>
struct holds_element :
    zr_boost_1_81::mpl::not_<
        zr_boost_1_81::is_same<
            typename zr_boost_1_81::mpl::end<typename Variant::types>::type,
            typename element_iterator<Variant, T>::type
        >
    >
{};


}}} // namespace zr_boost_1_81::detail::variant

#endif // BOOST_VARIANT_DETAIL_ELEMENT_INDEX_HPP
