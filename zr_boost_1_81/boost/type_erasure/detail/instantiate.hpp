// Boost.TypeErasure library
//
// Copyright 2012 Steven Watanabe
//
// Distributed under the Boost Software License Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// $Id$

#if !defined(BOOST_PP_IS_ITERATING)

#ifndef BOOST_TYPE_ERASURE_DETAIL_INSTANTIATE_HPP_INCLUDED
#define BOOST_TYPE_ERASURE_DETAIL_INSTANTIATE_HPP_INCLUDED

#include <boost/mpl/transform.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/at.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/iteration/iterate.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/type_erasure/detail/normalize.hpp>
#include <boost/type_erasure/detail/rebind_placeholders.hpp>

namespace zr_boost_1_81 {
namespace type_erasure {
namespace detail {

#ifdef BOOST_TYPE_ERASURE_USE_MP11

template<class L>
struct make_instantiate_concept_impl;

template<class T, T t>
struct instantiate_concept;

template<class T>
using instantiate_concept_impl = instantiate_concept<decltype(&T::apply), &T::apply>;

template<class... T>
struct make_instantiate_concept_impl< ::zr_boost_1_81::mp11::mp_list<T...> >
{
    template<template<class> class F>
    using apply = void(F<T>...);
};

template<class Map>
struct instantiate_concept_rebind_f
{
    template<class T>
    using apply =
        typename ::zr_boost_1_81::type_erasure::detail::rebind_placeholders<
            T,
            Map
        >::type;
};

template<class Concept, class Map>
using make_instantiate_concept =
    ::zr_boost_1_81::type_erasure::detail::make_instantiate_concept_impl<
        ::zr_boost_1_81::mp11::mp_transform<
            ::zr_boost_1_81::type_erasure::detail::instantiate_concept_rebind_f<
                typename ::zr_boost_1_81::type_erasure::detail::add_deductions<
                    ::zr_boost_1_81::type_erasure::detail::make_mp_list<Map>,
                    typename ::zr_boost_1_81::type_erasure::detail::get_placeholder_normalization_map<
                        Concept
                    >::type
                >::type
            >::template apply,
            ::zr_boost_1_81::type_erasure::detail::normalize_concept_t<Concept>
        >
    >;

#define BOOST_TYPE_ERASURE_INSTANTIATE(Concept, Map)                                        \
    ((void)(typename ::zr_boost_1_81::type_erasure::detail::make_instantiate_concept<Concept, Map>  \
        ::template apply< ::zr_boost_1_81::type_erasure::detail::instantiate_concept_impl>*)0)

#define BOOST_TYPE_ERASURE_INSTANTIATE1(Concept, P0, T0)                        \
    ((void)(typename ::zr_boost_1_81::type_erasure::detail::make_instantiate_concept<   \
        Concept, ::zr_boost_1_81::mpl::map1< ::zr_boost_1_81::mpl::pair<P0, T0> > >             \
        ::template apply< ::zr_boost_1_81::type_erasure::detail::instantiate_concept_impl>*)0)

#else

template<int N>
struct make_instantiate_concept_impl;

template<class Concept>
struct make_instantiate_concept {
    typedef typename ::zr_boost_1_81::type_erasure::detail::normalize_concept<
        Concept>::type normalized;
    typedef typename ::zr_boost_1_81::type_erasure::detail::make_instantiate_concept_impl<
        (::zr_boost_1_81::mpl::size<normalized>::value)
    >::type type;
};

#define BOOST_TYPE_ERASURE_INSTANTIATE(Concept, Map)            \
    (::zr_boost_1_81::type_erasure::detail::make_instantiate_concept<   \
        Concept                                                 \
    >::type::apply((Concept*)0, (Map*)0))

#define BOOST_TYPE_ERASURE_INSTANTIATE1(Concept, P0, T0)        \
    (::zr_boost_1_81::type_erasure::detail::make_instantiate_concept<   \
        Concept                                                 \
    >::type::apply(                                             \
        (Concept*)0,                                            \
        (::zr_boost_1_81::mpl::map1< ::zr_boost_1_81::mpl::pair<P0, T0> >*)0))

#define BOOST_PP_FILENAME_1 <boost/type_erasure/detail/instantiate.hpp>
#define BOOST_PP_ITERATION_LIMITS (0, BOOST_TYPE_ERASURE_MAX_FUNCTIONS)
#include BOOST_PP_ITERATE()

#endif

}
}
}

#endif

#else

#define N BOOST_PP_ITERATION()

#define BOOST_TYPE_ERASURE_INSTANTIATE_IMPL(z, n, data)\
    (void)&::zr_boost_1_81::mpl::at_c<data, n>::type::apply;

struct BOOST_PP_CAT(instantiate_concept, N) {
    template<class Concept, class Map>
    static void apply(Concept *, Map *) {
#if N > 0
        typedef typename ::zr_boost_1_81::type_erasure::detail::normalize_concept<
            Concept>::type normalized;
        typedef typename ::zr_boost_1_81::type_erasure::detail::get_placeholder_normalization_map<
            Concept
        >::type placeholder_subs;

        typedef typename ::zr_boost_1_81::mpl::transform<
            normalized,
            ::zr_boost_1_81::type_erasure::detail::rebind_placeholders<
                ::zr_boost_1_81::mpl::_1,
                typename ::zr_boost_1_81::type_erasure::detail::add_deductions<
                    Map,
                    placeholder_subs
                >::type
            >
        >::type concept_sequence;
#endif
        BOOST_PP_REPEAT(N, BOOST_TYPE_ERASURE_INSTANTIATE_IMPL, concept_sequence)
    }
};

template<>
struct make_instantiate_concept_impl<N>
{
    typedef ::zr_boost_1_81::type_erasure::detail::BOOST_PP_CAT(instantiate_concept, N) type;
};

#undef BOOST_TYPE_ERASURE_INSTANTIATE_IMPL

#undef N

#endif
