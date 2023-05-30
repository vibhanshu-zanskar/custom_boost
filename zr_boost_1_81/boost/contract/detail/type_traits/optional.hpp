
#ifndef BOOST_CONTRACT_DETAIL_OPTIONAL_HPP_
#define BOOST_CONTRACT_DETAIL_OPTIONAL_HPP_

// Copyright (C) 2008-2018 Lorenzo Caminiti
// Distributed under the Boost Software License, Version 1.0 (see accompanying
// file LICENSE_1_0.txt or a copy at http://www.boost.org/LICENSE_1_0.txt).
// See: http://www.boost.org/doc/libs/release/libs/contract/doc/html/index.html

#include <boost/optional.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <boost/type_traits/integral_constant.hpp>

namespace zr_boost_1_81 { namespace contract { namespace detail {

template<typename T>
struct is_optional : zr_boost_1_81::false_type {};
template<typename T>
struct is_optional<zr_boost_1_81::optional<T> > : zr_boost_1_81::true_type {};

template<typename T>
struct optional_value_type { typedef T type; };
template<typename T>
struct optional_value_type<zr_boost_1_81::optional<T> > { typedef T type; };

template<typename T>
struct remove_value_reference_if_optional { typedef T type; };
template<typename T>
struct remove_value_reference_if_optional<zr_boost_1_81::optional<T> >
        { typedef typename zr_boost_1_81::remove_reference<T>::type type; };

template<typename T>
T& optional_get(T& x) { return x; }
template<typename T>
T& optional_get(zr_boost_1_81::optional<T>& x) { return x.get(); }
template<typename T>
T& optional_get(zr_boost_1_81::optional<T&>& x) { return x.get(); }

} } } // namespace

#endif // #include guard

