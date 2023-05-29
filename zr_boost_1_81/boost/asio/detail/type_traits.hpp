//
// detail/type_traits.hpp
// ~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_ASIO_DETAIL_TYPE_TRAITS_HPP
#define BOOST_ASIO_DETAIL_TYPE_TRAITS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <boost/asio/detail/config.hpp>

#if defined(BOOST_ASIO_HAS_STD_TYPE_TRAITS)
# include <type_traits>
#else // defined(BOOST_ASIO_HAS_STD_TYPE_TRAITS)
# include <boost/type_traits/add_const.hpp>
# include <boost/type_traits/add_lvalue_reference.hpp>
# include <boost/type_traits/aligned_storage.hpp>
# include <boost/type_traits/alignment_of.hpp>
# include <boost/type_traits/conditional.hpp>
# include <boost/type_traits/decay.hpp>
# include <boost/type_traits/has_nothrow_copy.hpp>
# include <boost/type_traits/has_nothrow_destructor.hpp>
# include <boost/type_traits/integral_constant.hpp>
# include <boost/type_traits/is_base_of.hpp>
# include <boost/type_traits/is_class.hpp>
# include <boost/type_traits/is_const.hpp>
# include <boost/type_traits/is_convertible.hpp>
# include <boost/type_traits/is_constructible.hpp>
# include <boost/type_traits/is_copy_constructible.hpp>
# include <boost/type_traits/is_destructible.hpp>
# include <boost/type_traits/is_function.hpp>
# include <boost/type_traits/is_object.hpp>
# include <boost/type_traits/is_pointer.hpp>
# include <boost/type_traits/is_same.hpp>
# include <boost/type_traits/remove_cv.hpp>
# include <boost/type_traits/remove_pointer.hpp>
# include <boost/type_traits/remove_reference.hpp>
# include <boost/utility/declval.hpp>
# include <boost/utility/enable_if.hpp>
# include <boost/utility/result_of.hpp>
#endif // defined(BOOST_ASIO_HAS_STD_TYPE_TRAITS)

namespace zr_boost_1_81 {
namespace asio {

#if defined(BOOST_ASIO_HAS_STD_TYPE_TRAITS)
using std::add_const;
using std::add_lvalue_reference;
#if defined(BOOST_ASIO_MSVC) && (_MSC_VER < 1900)
using std::aligned_storage;
#else // defined(BOOST_ASIO_MSVC) && (_MSC_VER < 1900)
template <std::size_t N, std::size_t A>
struct aligned_storage { struct type { alignas(A) unsigned char data[N]; }; };
#endif // defined(BOOST_ASIO_MSVC) && (_MSC_VER < 1900)
using std::alignment_of;
using std::conditional;
using std::decay;
using std::declval;
using std::enable_if;
using std::false_type;
using std::integral_constant;
using std::is_base_of;
using std::is_class;
using std::is_const;
using std::is_constructible;
using std::is_convertible;
using std::is_copy_constructible;
using std::is_destructible;
using std::is_function;
using std::is_move_constructible;
using std::is_nothrow_copy_constructible;
using std::is_nothrow_destructible;
using std::is_object;
using std::is_pointer;
using std::is_reference;
using std::is_same;
using std::is_scalar;
using std::remove_cv;
template <typename T>
struct remove_cvref : remove_cv<typename std::remove_reference<T>::type> {};
using std::remove_pointer;
using std::remove_reference;
#if defined(BOOST_ASIO_HAS_STD_INVOKE_RESULT)
template <typename> struct result_of;
template <typename F, typename... Args>
struct result_of<F(Args...)> : std::invoke_result<F, Args...> {};
#else // defined(BOOST_ASIO_HAS_STD_INVOKE_RESULT)
using std::result_of;
#endif // defined(BOOST_ASIO_HAS_STD_INVOKE_RESULT)
using std::true_type;
#else // defined(BOOST_ASIO_HAS_STD_TYPE_TRAITS)
using zr_boost_1_81::add_const;
using zr_boost_1_81::add_lvalue_reference;
using zr_boost_1_81::aligned_storage;
using zr_boost_1_81::alignment_of;
template <bool Condition, typename Type = void>
struct enable_if : zr_boost_1_81::enable_if_c<Condition, Type> {};
using zr_boost_1_81::conditional;
using zr_boost_1_81::decay;
using zr_boost_1_81::declval;
using zr_boost_1_81::false_type;
using zr_boost_1_81::integral_constant;
using zr_boost_1_81::is_base_of;
using zr_boost_1_81::is_class;
using zr_boost_1_81::is_const;
using zr_boost_1_81::is_constructible;
using zr_boost_1_81::is_convertible;
using zr_boost_1_81::is_copy_constructible;
using zr_boost_1_81::is_destructible;
using zr_boost_1_81::is_function;
#if defined(BOOST_ASIO_HAS_MOVE)
template <typename T>
struct is_move_constructible : false_type {};
#else // defined(BOOST_ASIO_HAS_MOVE)
template <typename T>
struct is_move_constructible : is_copy_constructible<T> {};
#endif // defined(BOOST_ASIO_HAS_MOVE)
template <typename T>
struct is_nothrow_copy_constructible : zr_boost_1_81::has_nothrow_copy<T> {};
template <typename T>
struct is_nothrow_destructible : zr_boost_1_81::has_nothrow_destructor<T> {};
using zr_boost_1_81::is_object;
using zr_boost_1_81::is_pointer;
using zr_boost_1_81::is_reference;
using zr_boost_1_81::is_same;
using zr_boost_1_81::is_scalar;
using zr_boost_1_81::remove_cv;
template <typename T>
struct remove_cvref : remove_cv<typename zr_boost_1_81::remove_reference<T>::type> {};
using zr_boost_1_81::remove_pointer;
using zr_boost_1_81::remove_reference;
using zr_boost_1_81::result_of;
using zr_boost_1_81::true_type;
#endif // defined(BOOST_ASIO_HAS_STD_TYPE_TRAITS)

template <typename> struct void_type { typedef void type; };

#if defined(BOOST_ASIO_HAS_VARIADIC_TEMPLATES)

template <typename...> struct conjunction : true_type {};
template <typename T> struct conjunction<T> : T {};
template <typename Head, typename... Tail> struct conjunction<Head, Tail...> :
  conditional<Head::value, conjunction<Tail...>, Head>::type {};

#endif // defined(BOOST_ASIO_HAS_VARIADIC_TEMPLATES)

struct defaulted_constraint
{
  BOOST_ASIO_CONSTEXPR defaulted_constraint() {}
};

template <bool Condition, typename Type = int>
struct constraint : enable_if<Condition, Type> {};

} // namespace asio
} // namespace zr_boost_1_81

#endif // BOOST_ASIO_DETAIL_TYPE_TRAITS_HPP