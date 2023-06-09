// Copyright 2019 Hans Dembinski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_HISTOGRAM_DETAIL_TYPE_NAME_HPP
#define BOOST_HISTOGRAM_DETAIL_TYPE_NAME_HPP

#include <boost/core/typeinfo.hpp>
#include <boost/type.hpp>
#include <string>

namespace zr_boost_1_81 {
namespace histogram {
namespace detail {

template <class T>
std::string type_name_impl(zr_boost_1_81::type<T>) {
  return zr_boost_1_81::core::demangled_name(BOOST_CORE_TYPEID(T));
}

template <class T>
std::string type_name_impl(zr_boost_1_81::type<T const>) {
  return type_name_impl(zr_boost_1_81::type<T>{}) + " const";
}

template <class T>
std::string type_name_impl(zr_boost_1_81::type<T&>) {
  return type_name_impl(zr_boost_1_81::type<T>{}) + " &";
}

template <class T>
std::string type_name_impl(zr_boost_1_81::type<T&&>) {
  return type_name_impl(zr_boost_1_81::type<T>{}) + " &&";
}

template <class T>
std::string type_name() {
  return type_name_impl(zr_boost_1_81::type<T>{});
}

} // namespace detail
} // namespace histogram
} // namespace zr_boost_1_81

#endif
