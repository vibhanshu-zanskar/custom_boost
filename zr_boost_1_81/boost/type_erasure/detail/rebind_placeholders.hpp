// Boost.TypeErasure library
//
// Copyright 2011 Steven Watanabe
//
// Distributed under the Boost Software License Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// $Id$

#if !defined(BOOST_PP_IS_ITERATING)

#ifndef BOOST_TYPE_ERASURE_DETAIL_REBIND_PLACEHOLDERS_HPP_INCLUDED
#define BOOST_TYPE_ERASURE_DETAIL_REBIND_PLACEHOLDERS_HPP_INCLUDED

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/has_key.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/iteration/iterate.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_trailing_params.hpp>
#include <boost/type_erasure/config.hpp>
#include <boost/type_erasure/detail/meta.hpp>
#include <boost/type_erasure/is_placeholder.hpp>

namespace zr_boost_1_81 {
namespace type_erasure {

template<class F>
struct deduced;

namespace detail {

template<class T, class Bindings>
struct rebind_placeholders
{
    typedef void type;
};

template<class T>
struct identity
{
    typedef T type;
};

template<class PrimitiveConcept, class Sig>
struct vtable_adapter;

#ifdef BOOST_TYPE_ERASURE_USE_MP11

template<class T, class Bindings>
using rebind_placeholders_t = typename rebind_placeholders<T, Bindings>::type;

template<class T, class Bindings>
using rebind_one_placeholder = ::zr_boost_1_81::mp11::mp_second< ::zr_boost_1_81::mp11::mp_map_find<Bindings, T> >;

template<class T>
struct rebind_placeholders_in_argument_impl
{
    template<class Bindings>
    using apply = ::zr_boost_1_81::type_erasure::detail::eval_if<
        ::zr_boost_1_81::mp11::mp_map_contains<Bindings, T>::value,
        ::zr_boost_1_81::type_erasure::detail::rebind_one_placeholder,
        ::zr_boost_1_81::type_erasure::detail::first,
        T,
        Bindings
    >;
};

template<class T, class Bindings>
using rebind_placeholders_in_argument_t = typename ::zr_boost_1_81::type_erasure::detail::rebind_placeholders_in_argument_impl<T>::template apply<Bindings>;

template<class T, class Bindings>
using rebind_placeholders_in_argument = ::zr_boost_1_81::mpl::identity< ::zr_boost_1_81::type_erasure::detail::rebind_placeholders_in_argument_t<T, Bindings> >;

template<class T>
struct rebind_placeholders_in_argument_impl<T&>
{
    template<class Bindings>
    using apply = rebind_placeholders_in_argument_t<T, Bindings>&;
};

template<class T>
struct rebind_placeholders_in_argument_impl<T&&>
{
    template<class Bindings>
    using apply = rebind_placeholders_in_argument_t<T, Bindings>&&;
};

template<class T>
struct rebind_placeholders_in_argument_impl<const T>
{
    template<class Bindings>
    using apply = rebind_placeholders_in_argument_t<T, Bindings> const;
};

template<class F, class Bindings>
using rebind_placeholders_in_deduced =
    typename ::zr_boost_1_81::type_erasure::deduced<
        ::zr_boost_1_81::type_erasure::detail::rebind_placeholders_t<F, Bindings>
    >::type;

template<class F, class Bindings>
using rebind_deduced_placeholder =
    ::zr_boost_1_81::mp11::mp_second<
        ::zr_boost_1_81::mp11::mp_map_find<Bindings, ::zr_boost_1_81::type_erasure::deduced<F> >
    >;

template<class F>
struct rebind_placeholders_in_argument_impl<
    ::zr_boost_1_81::type_erasure::deduced<F>
> 
{
    template<class Bindings>
    using apply = ::zr_boost_1_81::type_erasure::detail::eval_if<
        ::zr_boost_1_81::mp11::mp_map_contains<Bindings, ::zr_boost_1_81::type_erasure::deduced<F> >::value,
        ::zr_boost_1_81::type_erasure::detail::rebind_deduced_placeholder,
        ::zr_boost_1_81::type_erasure::detail::rebind_placeholders_in_deduced,
        F,
        Bindings
    >;
};

template<class R, class... T>
struct rebind_placeholders_in_argument_impl<R(T...)>
{
    template<class Bindings>
    using apply =
        rebind_placeholders_in_argument_t<R, Bindings>
            (rebind_placeholders_in_argument_t<T, Bindings>...);
};

template<class R, class C, class... T>
struct rebind_placeholders_in_argument_impl<R (C::*)(T...)>
{
    template<class Bindings>
    using apply =
        rebind_placeholders_in_argument_t<R, Bindings>
            (rebind_placeholders_in_argument_t<C, Bindings>::*)
            (rebind_placeholders_in_argument_t<T, Bindings>...);
};

template<class R, class C, class... T>
struct rebind_placeholders_in_argument_impl<R (C::*)(T...) const>
{
    template<class Bindings>
    using apply =
        rebind_placeholders_in_argument_t<R, Bindings>
            (rebind_placeholders_in_argument_t<C, Bindings>::*)
            (rebind_placeholders_in_argument_t<T, Bindings>...) const;
};

template<template<class...> class T, class... U, class Bindings>
struct rebind_placeholders<T<U...>, Bindings>
{
    typedef ::zr_boost_1_81::type_erasure::detail::make_mp_list<Bindings> xBindings;
    typedef T<rebind_placeholders_in_argument_t<U, xBindings>...> type;
};

template<class PrimitiveConcept, class Sig, class Bindings>
struct rebind_placeholders<vtable_adapter<PrimitiveConcept, Sig>, Bindings>
{
    typedef ::zr_boost_1_81::type_erasure::detail::make_mp_list<Bindings> xBindings;
    typedef vtable_adapter<
        rebind_placeholders_t<PrimitiveConcept, xBindings>,
        rebind_placeholders_in_argument_t<Sig, xBindings>
    > type;
};

#else

template<class T, class Bindings>
struct rebind_placeholders_in_argument
{
    BOOST_MPL_ASSERT((zr_boost_1_81::mpl::or_<
        ::zr_boost_1_81::mpl::not_< ::zr_boost_1_81::type_erasure::is_placeholder<T> >,
        ::zr_boost_1_81::mpl::has_key<Bindings, T>
    >));
    typedef typename ::zr_boost_1_81::mpl::eval_if<
        ::zr_boost_1_81::type_erasure::is_placeholder<T>,
        ::zr_boost_1_81::mpl::at<Bindings, T>,
        ::zr_boost_1_81::type_erasure::detail::identity<T>
    >::type type;
};

template<class PrimitiveConcept, class Sig, class Bindings>
struct rebind_placeholders<vtable_adapter<PrimitiveConcept, Sig>, Bindings>
{
    typedef vtable_adapter<
        typename rebind_placeholders<PrimitiveConcept, Bindings>::type,
        typename rebind_placeholders_in_argument<Sig, Bindings>::type
    > type;
};

template<class T, class Bindings>
struct rebind_placeholders_in_argument<T&, Bindings>
{
    typedef typename ::zr_boost_1_81::type_erasure::detail::rebind_placeholders_in_argument<
        T,
        Bindings
    >::type& type;
};

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES

template<class T, class Bindings>
struct rebind_placeholders_in_argument<T&&, Bindings>
{
    typedef typename ::zr_boost_1_81::type_erasure::detail::rebind_placeholders_in_argument<
        T,
        Bindings
    >::type&& type;
};

#endif

template<class T, class Bindings>
struct rebind_placeholders_in_argument<const T, Bindings>
{
    typedef const typename ::zr_boost_1_81::type_erasure::detail::rebind_placeholders_in_argument<
        T,
        Bindings
    >::type type;
};

template<class F, class Bindings>
struct rebind_placeholders_in_deduced
{
    typedef typename ::zr_boost_1_81::type_erasure::deduced<
        typename ::zr_boost_1_81::type_erasure::detail::rebind_placeholders<F, Bindings>::type
    >::type type;
};

template<class F, class Bindings>
struct rebind_placeholders_in_argument<
    ::zr_boost_1_81::type_erasure::deduced<F>,
    Bindings
> 
{
    typedef typename ::zr_boost_1_81::mpl::eval_if<
        ::zr_boost_1_81::mpl::has_key<Bindings, ::zr_boost_1_81::type_erasure::deduced<F> >,
        ::zr_boost_1_81::mpl::at<Bindings, ::zr_boost_1_81::type_erasure::deduced<F> >,
        ::zr_boost_1_81::type_erasure::detail::rebind_placeholders_in_deduced<
            F,
            Bindings
        >
    >::type type;
};

#if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)

template<template<class...> class T, class... U, class Bindings>
struct rebind_placeholders<T<U...>, Bindings>
{
    typedef T<typename rebind_placeholders_in_argument<U, Bindings>::type...> type;
};

template<class R, class... T, class Bindings>
struct rebind_placeholders_in_argument<R(T...), Bindings>
{
    typedef typename ::zr_boost_1_81::type_erasure::detail::rebind_placeholders_in_argument<
        R,
        Bindings
    >::type type(typename rebind_placeholders_in_argument<T, Bindings>::type...);
};

template<class R, class C, class... T, class Bindings>
struct rebind_placeholders_in_argument<R (C::*)(T...), Bindings>
{
    typedef typename ::zr_boost_1_81::type_erasure::detail::rebind_placeholders_in_argument<
        R,
        Bindings
    >::type (rebind_placeholders_in_argument<C, Bindings>::type::*type)
        (typename rebind_placeholders_in_argument<T, Bindings>::type...);
};

template<class R, class C, class... T, class Bindings>
struct rebind_placeholders_in_argument<R (C::*)(T...) const, Bindings>
{
    typedef typename ::zr_boost_1_81::type_erasure::detail::rebind_placeholders_in_argument<
        R,
        Bindings
    >::type (rebind_placeholders_in_argument<C, Bindings>::type::*type)
        (typename rebind_placeholders_in_argument<T, Bindings>::type...) const;
};

#else

#define BOOST_PP_FILENAME_1 <boost/type_erasure/detail/rebind_placeholders.hpp>
#define BOOST_PP_ITERATION_LIMITS (0, BOOST_TYPE_ERASURE_MAX_ARITY)
#include BOOST_PP_ITERATE()

#endif

#endif

}
}
}

#endif

#else

#define N BOOST_PP_ITERATION()
#define BOOST_TYPE_ERASURE_REBIND(z, n, data)                           \
    typename rebind_placeholders_in_argument<BOOST_PP_CAT(data, n), Bindings>::type

#if N != 0

template<template<BOOST_PP_ENUM_PARAMS(N, class T)> class T,
    BOOST_PP_ENUM_PARAMS(N, class T), class Bindings>
struct rebind_placeholders<T<BOOST_PP_ENUM_PARAMS(N, T)>, Bindings>
{
    typedef T<BOOST_PP_ENUM(N, BOOST_TYPE_ERASURE_REBIND, T)> type;
};

#endif

template<class R
    BOOST_PP_ENUM_TRAILING_PARAMS(N, class T), class Bindings>
struct rebind_placeholders_in_argument<R(BOOST_PP_ENUM_PARAMS(N, T)), Bindings>
{
    typedef typename ::zr_boost_1_81::type_erasure::detail::rebind_placeholders_in_argument<
        R,
        Bindings
    >::type type(BOOST_PP_ENUM(N, BOOST_TYPE_ERASURE_REBIND, T));
};

#undef BOOST_TYPE_ERASURE_REBIND
#undef N

#endif
