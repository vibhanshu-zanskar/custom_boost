// Boost.TypeErasure library
//
// Copyright 2011 Steven Watanabe
//
// Distributed under the Boost Software License Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// $Id$

#ifndef BOOST_TYPE_ERASURE_DETAIL_NORMALIZE_HPP_INCLUDED
#define BOOST_TYPE_ERASURE_DETAIL_NORMALIZE_HPP_INCLUDED

#include <boost/mpl/assert.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/set.hpp>
#include <boost/mpl/map.hpp>
#include <boost/mpl/has_key.hpp>
#include <boost/mpl/insert.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/back_inserter.hpp>
#include <boost/mpl/inserter.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/copy.hpp>
#include <boost/mpl/at.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_erasure/detail/get_placeholders.hpp>
#include <boost/type_erasure/detail/rebind_placeholders.hpp>
#include <boost/type_erasure/detail/normalize_deduced.hpp>
#include <boost/type_erasure/detail/meta.hpp>
#include <boost/type_erasure/relaxed.hpp>
#include <boost/type_erasure/builtin.hpp>

namespace zr_boost_1_81 {
namespace type_erasure {

template<class F>
struct deduced;

template<class T, class U>
struct same_type;

namespace detail {
struct substitution_map_tag {};

// a wrapper around an mpl::map that
// defaults to the identity map.
template<class M>
struct substitution_map
{
    typedef substitution_map_tag tag;
    typedef M map_type;
};

}
}

namespace mpl {

template<>
struct at_impl< ::zr_boost_1_81::type_erasure::detail::substitution_map_tag>
{
    template<class Seq, class Key>
    struct apply
    {
        typedef typename ::zr_boost_1_81::mpl::eval_if<
            ::zr_boost_1_81::mpl::has_key<typename Seq::map_type, Key>,
            ::zr_boost_1_81::mpl::at<typename Seq::map_type, Key>,
            ::zr_boost_1_81::mpl::identity<Key>
        >::type type;
    };
};

template<>
struct has_key_impl< ::zr_boost_1_81::type_erasure::detail::substitution_map_tag>
{
    template<class Seq, class Key>
    struct apply : zr_boost_1_81::mpl::true_
    {};
};

}

namespace type_erasure {
namespace detail {

// Given the arguments to same_type, determines
// which should be the key and which should be
// the value in the substitution map.
template<class T, class U>
struct select_pair
{
    BOOST_MPL_ASSERT((::zr_boost_1_81::is_same<T, U>));
    typedef void type;
};

template<class T, class U>
struct select_pair<T, ::zr_boost_1_81::type_erasure::deduced<U> >
{
    typedef ::zr_boost_1_81::mpl::pair< ::zr_boost_1_81::type_erasure::deduced<U>, T> type;
};

template<class T, class U>
struct select_pair< ::zr_boost_1_81::type_erasure::deduced<T>, U>
{
    typedef ::zr_boost_1_81::mpl::pair< ::zr_boost_1_81::type_erasure::deduced<T>, U> type;
};

template<class T, class U>
struct select_pair<
    ::zr_boost_1_81::type_erasure::deduced<T>,
    ::zr_boost_1_81::type_erasure::deduced<U>
>
{
    typedef ::zr_boost_1_81::mpl::pair<
        ::zr_boost_1_81::type_erasure::deduced<T>,
        ::zr_boost_1_81::type_erasure::deduced<U>
    > type;
};

#ifndef BOOST_TYPE_ERASURE_USE_MP11

// given a partial substitution map from same_type,
// resolves a placeholder as far as possible.
template<class M, class T>
struct resolve_same_type
{
    typedef typename ::zr_boost_1_81::mpl::eval_if< ::zr_boost_1_81::mpl::has_key<M, T>,
        ::zr_boost_1_81::type_erasure::detail::resolve_same_type<
            M,
            typename ::zr_boost_1_81::mpl::at<M, T>::type
        >,
        ::zr_boost_1_81::mpl::identity<T>
    >::type type;
};

// M is a map of placeholder substitutions
template<class M, class T>
struct normalize_placeholder
{
    typedef typename ::zr_boost_1_81::mpl::eval_if< ::zr_boost_1_81::mpl::has_key<M, T>,
        ::zr_boost_1_81::type_erasure::detail::normalize_placeholder<
            M,
            typename ::zr_boost_1_81::mpl::at<M, T>::type
        >,
        ::zr_boost_1_81::mpl::identity<T>
    >::type type;
};

template<class M, class T>
struct normalize_placeholder<M, ::zr_boost_1_81::type_erasure::deduced<T> >
{
    typedef typename ::zr_boost_1_81::mpl::eval_if< ::zr_boost_1_81::mpl::has_key<M, T>,
        ::zr_boost_1_81::type_erasure::detail::normalize_placeholder<
            M,
            typename ::zr_boost_1_81::mpl::at<M, T>::type
        >,
        ::zr_boost_1_81::type_erasure::detail::normalize_deduced<
            M,
            T
        >
    >::type type;
};

// Takes a mpl::map of placeholder substitutions and
// fully resolves it.  i.e.  a -> b, b -> c, becomes
// a -> c, b -> c.  Also resolves deduced placeholders
// whose arguments are all resolved.
template<class M>
struct create_placeholder_map
{
    typedef typename ::zr_boost_1_81::mpl::fold<
        M,
        ::zr_boost_1_81::mpl::map0<>,
        ::zr_boost_1_81::mpl::insert<
            ::zr_boost_1_81::mpl::_1,
            ::zr_boost_1_81::mpl::pair<
                ::zr_boost_1_81::mpl::first< ::zr_boost_1_81::mpl::_2>,
                ::zr_boost_1_81::type_erasure::detail::normalize_placeholder<M, ::zr_boost_1_81::mpl::second< ::zr_boost_1_81::mpl::_2> >
            >
        >
    >::type type;
};

template<class Bindings, class P, class Out, class Sub>
struct convert_deduced
{
    typedef typename ::zr_boost_1_81::type_erasure::detail::rebind_placeholders_in_argument<
        typename P::first,
        Bindings
    >::type result1;
    typedef typename ::zr_boost_1_81::mpl::at<Sub, result1>::type result;
    typedef typename ::zr_boost_1_81::mpl::eval_if<
        ::zr_boost_1_81::mpl::has_key<Out, typename P::second>,
        ::zr_boost_1_81::mpl::identity<Out>,
        ::zr_boost_1_81::mpl::insert<Out, ::zr_boost_1_81::mpl::pair<typename P::second, result> >
    >::type type;
    BOOST_MPL_ASSERT((zr_boost_1_81::is_same<typename ::zr_boost_1_81::mpl::at<type, typename P::second>::type, result>));
};

template<class Bindings, class M, class Sub>
struct convert_deductions
{
    typedef typename ::zr_boost_1_81::mpl::fold<
        M,
        Bindings,
        ::zr_boost_1_81::type_erasure::detail::convert_deduced<
            Bindings, ::zr_boost_1_81::mpl::_2, ::zr_boost_1_81::mpl::_1, Sub
        >
    >::type type;
};

template<class Bindings, class P, class Out>
struct add_deduced
{
    typedef typename ::zr_boost_1_81::type_erasure::detail::rebind_placeholders_in_argument<
        typename P::first,
        Bindings
    >::type result;
    typedef typename ::zr_boost_1_81::mpl::eval_if<
        ::zr_boost_1_81::mpl::has_key<Out, typename P::second>,
        ::zr_boost_1_81::mpl::identity<Out>,
        ::zr_boost_1_81::mpl::insert<Out, ::zr_boost_1_81::mpl::pair<typename P::second, result> >
    >::type type;
    BOOST_MPL_ASSERT((zr_boost_1_81::is_same<typename ::zr_boost_1_81::mpl::at<type, typename P::second>::type, result>));
};

template<class Bindings, class M>
struct add_deductions
{
    typedef typename ::zr_boost_1_81::mpl::fold<
        M,
        Bindings,
        ::zr_boost_1_81::type_erasure::detail::add_deduced<
            Bindings, ::zr_boost_1_81::mpl::_2, ::zr_boost_1_81::mpl::_1
        >
    >::type type;
};

// Fold Op for normalize_concept_impl
template<class Out, class T>
struct insert_concept
{
    typedef ::zr_boost_1_81::mpl::pair<
        typename ::zr_boost_1_81::mpl::insert<typename Out::first, T>::type,
        typename Out::second
    > type;
};

template<class Out, class T, class U>
struct insert_concept<Out, ::zr_boost_1_81::type_erasure::same_type<T, U> >
{
    typedef typename ::zr_boost_1_81::type_erasure::detail::resolve_same_type<
        typename Out::second,
        T
    >::type t1;
    typedef typename ::zr_boost_1_81::type_erasure::detail::resolve_same_type<
        typename Out::second,
        U
    >::type t2;
    typedef ::zr_boost_1_81::mpl::pair<
        typename Out::first,
        typename ::zr_boost_1_81::mpl::eval_if<
            ::zr_boost_1_81::is_same<t1, t2>,
            ::zr_boost_1_81::mpl::identity<typename Out::second>,
            ::zr_boost_1_81::mpl::insert<
                typename Out::second,
                typename ::zr_boost_1_81::type_erasure::detail::select_pair<
                    t1,
                    t2
                >::type
            >
        >::type
    > type;
};

// flattens a concept returning an mpl::pair
// - first is an MPL sequence containing the leaf concepts
// - second is an MPL map of the placeholder substitutions
//   used to resolve same_type.
template<class Concept, class Out = ::zr_boost_1_81::mpl::pair< ::zr_boost_1_81::mpl::set0<>, ::zr_boost_1_81::mpl::map0<> > >
struct normalize_concept_impl
{
    typedef typename ::zr_boost_1_81::mpl::eval_if< ::zr_boost_1_81::mpl::is_sequence<Concept>,
        ::zr_boost_1_81::mpl::fold<Concept, Out, normalize_concept_impl< ::zr_boost_1_81::mpl::_2, ::zr_boost_1_81::mpl::_1> >,
        ::zr_boost_1_81::type_erasure::detail::insert_concept<Out, Concept>
    >::type type;
};

struct append_typeinfo
{
    template<class Set, class T>
    struct apply
    {
        typedef typename ::zr_boost_1_81::mpl::insert<
            Set,
            ::zr_boost_1_81::type_erasure::typeid_<T>
        >::type type;
    };
};

// Seq should be a flattened MPL sequence of leaf concepts.
// adds typeid_<P> for every placeholder used.
template<class Seq>
struct add_typeinfo
{
    typedef typename ::zr_boost_1_81::mpl::fold<
        Seq,
        ::zr_boost_1_81::mpl::set0<>,
        ::zr_boost_1_81::type_erasure::detail::get_placeholders<
            ::zr_boost_1_81::mpl::_2,
            ::zr_boost_1_81::mpl::_1
        >
    >::type placeholders;
    typedef typename ::zr_boost_1_81::mpl::fold<
        placeholders,
        Seq,
        ::zr_boost_1_81::type_erasure::detail::append_typeinfo
    >::type type;
};

template<class Concept>
struct get_placeholder_normalization_map
{
    typedef typename ::zr_boost_1_81::type_erasure::detail::create_placeholder_map<
        typename normalize_concept_impl<Concept>::type::second
    >::type type;
};

// Flattens a Concept to an mpl::vector of primitive
// concepts.  Resolves same_type and deduced placeholders.
template<class Concept>
struct normalize_concept
{
    typedef typename normalize_concept_impl<Concept>::type impl;
    typedef typename ::zr_boost_1_81::type_erasure::detail::create_placeholder_map<
        typename impl::second
    >::type substitutions;
    typedef typename ::zr_boost_1_81::mpl::fold<
        typename impl::first,
        ::zr_boost_1_81::mpl::set0<>,
        ::zr_boost_1_81::mpl::insert<
            ::zr_boost_1_81::mpl::_1,
            ::zr_boost_1_81::type_erasure::detail::rebind_placeholders<
                ::zr_boost_1_81::mpl::_2,
                ::zr_boost_1_81::type_erasure::detail::substitution_map<substitutions>
            >
        >
    >::type basic;
    typedef typename ::zr_boost_1_81::mpl::eval_if<
        ::zr_boost_1_81::type_erasure::is_relaxed<Concept>,
        ::zr_boost_1_81::type_erasure::detail::add_typeinfo<basic>,
        ::zr_boost_1_81::mpl::identity<basic>
    >::type concept_set;
    typedef typename ::zr_boost_1_81::mpl::copy<
        concept_set,
        ::zr_boost_1_81::mpl::back_inserter< ::zr_boost_1_81::mpl::vector0<> >
    >::type type;
};

// Returns an MPL sequence containing all the concepts
// in Concept.  If Concept is considered as a DAG,
// the result will be sorted topologically.
template<
    class Concept,
    class Map = typename ::zr_boost_1_81::type_erasure::detail::create_placeholder_map<
            typename ::zr_boost_1_81::type_erasure::detail::normalize_concept_impl<
                Concept
            >::type::second
        >::type,
    class Out = ::zr_boost_1_81::mpl::set0<>
>
struct collect_concepts
{
    typedef typename ::zr_boost_1_81::type_erasure::detail::rebind_placeholders<
        Concept,
        ::zr_boost_1_81::type_erasure::detail::substitution_map<Map>
    >::type transformed;
    typedef typename ::zr_boost_1_81::mpl::eval_if< ::zr_boost_1_81::mpl::is_sequence<Concept>,
        ::zr_boost_1_81::mpl::fold<Concept, Out, collect_concepts< ::zr_boost_1_81::mpl::_2, Map, ::zr_boost_1_81::mpl::_1> >,
        ::zr_boost_1_81::mpl::identity<Out>
    >::type type1;
    typedef typename ::zr_boost_1_81::mpl::eval_if<
        ::zr_boost_1_81::is_same<transformed, void>,
        ::zr_boost_1_81::mpl::identity<type1>,
        ::zr_boost_1_81::mpl::insert<
            type1,
            transformed
        >
    >::type type;
};

#else

template<bool>
struct resolve_same_type_impl;

template<class M, class T>
using resolve_same_type_t =
    typename ::zr_boost_1_81::type_erasure::detail::resolve_same_type_impl<
        (::zr_boost_1_81::mp11::mp_map_contains<M, T>::value)
    >::template apply<M, T>;

template<>
struct resolve_same_type_impl<true>
{
    template<class M, class T>
    using apply = ::zr_boost_1_81::type_erasure::detail::resolve_same_type_t<
        M,
        ::zr_boost_1_81::mp11::mp_second< ::zr_boost_1_81::mp11::mp_map_find<M, T> >
    >;
};

template<>
struct resolve_same_type_impl<false>
{
    template<class M, class T>
    using apply = T;
};

// given a partial substitution map from same_type,
// resolves a placeholder as far as possible.
template<class M, class T>
using resolve_same_type = ::zr_boost_1_81::mpl::identity< ::zr_boost_1_81::type_erasure::detail::resolve_same_type_t<M, T> >;


// M is a map of placeholder substitutions

template<bool>
struct normalize_placeholder_impl;

template<class M, class T>
using normalize_placeholder_t =
    typename ::zr_boost_1_81::type_erasure::detail::normalize_placeholder_impl<
        ::zr_boost_1_81::mp11::mp_map_contains<M, T>::value
    >::template apply<M, T>;

template<>
struct normalize_placeholder_impl<true>
{
    template<class M, class T>
    using apply = ::zr_boost_1_81::type_erasure::detail::normalize_placeholder_t<
        M,
        typename ::zr_boost_1_81::mp11::mp_second< ::zr_boost_1_81::mp11::mp_map_find<M, T> >
    >;
};

template<class T>
struct normalize_deduced_impl
{
    template<class Map>
    using apply = T;
};

template<template<class...> class F, class... T>
struct normalize_deduced_impl< ::zr_boost_1_81::type_erasure::deduced<F<T...> > >
{
    template<class Map>
    using apply = typename ::zr_boost_1_81::type_erasure::deduced<F<normalize_placeholder_t<Map, T>...> >::type;
};

template<>
struct normalize_placeholder_impl<false>
{
    template<class M, class T>
    using apply = typename ::zr_boost_1_81::type_erasure::detail::normalize_deduced_impl<T>::template apply<M>;
};

template<class Map, class T>
using normalize_placeholder = ::zr_boost_1_81::mpl::identity< ::zr_boost_1_81::type_erasure::detail::normalize_placeholder_t<Map, T> >;

// Takes a mpl::map of placeholder substitutions and
// fully resolves it.  i.e.  a -> b, b -> c, becomes
// a -> c, b -> c.  Also resolves deduced placeholders
// whose arguments are all resolved.
template<class M>
struct create_placeholder_map
{
    template<class P>
    using transform_one = ::zr_boost_1_81::mpl::pair<
        typename ::zr_boost_1_81::mpl::first<P>::type,
        ::zr_boost_1_81::type_erasure::detail::normalize_placeholder_t<
            M,
            typename ::zr_boost_1_81::mpl::second<P>::type
        >
    >;
    typedef ::zr_boost_1_81::mp11::mp_transform<
        transform_one,
        M
    > type;
};

template<class M>
using create_placeholder_map_t = typename ::zr_boost_1_81::type_erasure::detail::create_placeholder_map<M>::type;

template<class Bindings, class P, class Out, class Sub>
struct convert_deduced
{
    typedef ::zr_boost_1_81::type_erasure::detail::rebind_placeholders_in_argument_t<
        typename P::first,
        Bindings
    > result1;
    typedef ::zr_boost_1_81::mp11::mp_second< ::zr_boost_1_81::mp11::mp_map_find<Sub, result1> > result;
    typedef ::zr_boost_1_81::mp11::mp_map_insert<Out, ::zr_boost_1_81::mpl::pair<typename P::second, result> > type;
    BOOST_MPL_ASSERT((zr_boost_1_81::is_same< ::zr_boost_1_81::mp11::mp_second< ::zr_boost_1_81::mp11::mp_map_find<type, typename P::second> >, result>));
};

template<class Bindings, class Sub>
struct convert_deduced_f
{
    template<class Out, class P>
    using apply = typename ::zr_boost_1_81::type_erasure::detail::convert_deduced<Bindings, P, Out, Sub>::type;
};

template<class Bindings, class M, class Sub>
using convert_deductions_t =
    ::zr_boost_1_81::mp11::mp_fold<
        M,
        ::zr_boost_1_81::type_erasure::detail::make_mp_list<Bindings>,
        ::zr_boost_1_81::type_erasure::detail::convert_deduced_f<Bindings, Sub>::template apply
    >;

template<class Bindings, class M, class Sub>
using convert_deductions = ::zr_boost_1_81::mpl::identity< ::zr_boost_1_81::type_erasure::detail::convert_deductions_t<Bindings, M, Sub> >;

template<class Bindings, class P, class Out>
struct add_deduced
{
    typedef typename ::zr_boost_1_81::type_erasure::detail::rebind_placeholders_in_argument<
        typename P::first,
        Bindings
    >::type result;
    typedef ::zr_boost_1_81::mp11::mp_map_insert<Out, ::zr_boost_1_81::mpl::pair<typename P::second, result> > type;
    BOOST_MPL_ASSERT((zr_boost_1_81::is_same< ::zr_boost_1_81::mp11::mp_second< ::zr_boost_1_81::mp11::mp_map_find<type, typename P::second> >, result>));
};

template<class Bindings>
struct add_deduced_f
{
    template<class Out, class P>
    using apply = typename ::zr_boost_1_81::type_erasure::detail::add_deduced<Bindings, P, Out>::type;
};

template<class Bindings, class M>
using add_deductions_t =
    ::zr_boost_1_81::mp11::mp_fold<
        M,
        ::zr_boost_1_81::type_erasure::detail::make_mp_list<Bindings>,
        ::zr_boost_1_81::type_erasure::detail::add_deduced_f<
            ::zr_boost_1_81::type_erasure::detail::make_mp_list<Bindings>
        >::template apply
    >;

template<class Bindings, class M>
using add_deductions = ::zr_boost_1_81::mpl::identity< ::zr_boost_1_81::type_erasure::detail::add_deductions_t<Bindings, M> >;

// Fold Op for normalize_concept_impl
template<class T>
struct insert_concept_impl
{
    template<class Out>
    using apply =
        ::zr_boost_1_81::mpl::pair<
            ::zr_boost_1_81::mp11::mp_set_push_back<typename Out::first, T>,
            typename Out::second
        >;
};

template<class Map, class T>
using mpl_insert = typename ::zr_boost_1_81::mpl::insert<Map, T>::type;

template<class T1, class T2, class Out>
using insert_concept_same_type =
    ::zr_boost_1_81::mpl::pair<
        typename Out::first,
        typename ::zr_boost_1_81::type_erasure::detail::eval_if<
            ::zr_boost_1_81::is_same<T1, T2>::value,
            ::zr_boost_1_81::type_erasure::detail::first,
            ::zr_boost_1_81::mp11::mp_map_insert, // FIXME: is this supposed to be a replace?
            typename Out::second,
            typename ::zr_boost_1_81::type_erasure::detail::select_pair<
                T1,
                T2
            >::type
        >
    >;

template<class T, class U>
struct insert_concept_impl< ::zr_boost_1_81::type_erasure::same_type<T, U> >
{
    template<class Out>
    using apply = ::zr_boost_1_81::type_erasure::detail::insert_concept_same_type<
        ::zr_boost_1_81::type_erasure::detail::resolve_same_type_t<
            typename Out::second,
            T
        >,
        ::zr_boost_1_81::type_erasure::detail::resolve_same_type_t<
            typename Out::second,
            U
        >,
        Out
    >;
};

template<bool>
struct normalize_concept_impl_test;

template<class Out, class Concept>
using normalize_concept_impl_f =
    typename ::zr_boost_1_81::type_erasure::detail::normalize_concept_impl_test<
        ::zr_boost_1_81::mpl::is_sequence<Concept>::value
    >::template apply<Out, Concept>;

template<>
struct normalize_concept_impl_test<true>
{
    template<class Out, class Concept>
    using apply =
        ::zr_boost_1_81::mp11::mp_fold<
            ::zr_boost_1_81::type_erasure::detail::make_mp_list<Concept>,
            Out,
            ::zr_boost_1_81::type_erasure::detail::normalize_concept_impl_f
        >;
};

template<>
struct normalize_concept_impl_test<false>
{
    template<class Out, class Concept>
    using apply = typename ::zr_boost_1_81::type_erasure::detail::insert_concept_impl<Concept>::template apply<Out>;
};

template<class Concept>
using normalize_concept_impl_t =
    ::zr_boost_1_81::type_erasure::detail::normalize_concept_impl_f<
        ::zr_boost_1_81::mpl::pair< ::zr_boost_1_81::mp11::mp_list<>, ::zr_boost_1_81::mp11::mp_list<> >,
        Concept
    >;

template<class Concept>
using normalize_concept_impl = ::zr_boost_1_81::mpl::identity< ::zr_boost_1_81::type_erasure::detail::normalize_concept_impl_t<Concept> >;

template<class S, class T>
using get_all_placeholders_impl = typename ::zr_boost_1_81::type_erasure::detail::get_placeholders<T, S>::type;

template<class Seq>
using get_all_placeholders =
    ::zr_boost_1_81::mp11::mp_fold<
        Seq,
        ::zr_boost_1_81::mp11::mp_list<>,
        ::zr_boost_1_81::type_erasure::detail::get_all_placeholders_impl
    >;

template<class T>
using make_identity_pair = ::zr_boost_1_81::mpl::pair<T, T>;

template<class Concept>
using make_identity_placeholder_map =
    ::zr_boost_1_81::mp11::mp_transform<
        ::zr_boost_1_81::type_erasure::detail::make_identity_pair,
        ::zr_boost_1_81::type_erasure::detail::get_all_placeholders<
            typename normalize_concept_impl_t<Concept>::first
        >
    >;

template<class S, class T>
using append_type_info = ::zr_boost_1_81::mp11::mp_set_push_back<
    S,
    ::zr_boost_1_81::type_erasure::typeid_<T>
>;

template<class Seq>
using add_typeinfo_t =
    ::zr_boost_1_81::mp11::mp_fold<
        get_all_placeholders<Seq>,
        Seq,
        ::zr_boost_1_81::type_erasure::detail::append_type_info
    >;

// Seq should be a flattened mp_list sequence of leaf concepts.
// adds typeid_<P> for every placeholder used.
template<class Seq>
using add_typeinfo = ::zr_boost_1_81::mpl::identity<add_typeinfo_t<Seq> >;

template<class Substitutions>
struct normalize_concept_substitute_f
{
    template<class Set, class Concept>
    using apply = ::zr_boost_1_81::mp11::mp_set_push_back<Set,
        typename ::zr_boost_1_81::type_erasure::detail::rebind_placeholders<
            Concept,
            Substitutions
        >::type
    >;
};

template<class Concept, class Pair>
using normalize_concept_adjustments =
    ::zr_boost_1_81::type_erasure::detail::eval_if<
        ::zr_boost_1_81::type_erasure::is_relaxed<Concept>::value,
        ::zr_boost_1_81::type_erasure::detail::add_typeinfo_t,
        ::zr_boost_1_81::type_erasure::detail::first,
        ::zr_boost_1_81::mp11::mp_fold<
            typename Pair::first,
            ::zr_boost_1_81::mp11::mp_list<>,
            ::zr_boost_1_81::type_erasure::detail::normalize_concept_substitute_f<
                ::zr_boost_1_81::type_erasure::detail::create_placeholder_map_t<
                    typename Pair::second
                >
            >::template apply
        >
    >;

template<class Concept>
using get_placeholder_normalization_map_t =
    ::zr_boost_1_81::type_erasure::detail::create_placeholder_map_t<
        typename normalize_concept_impl_t<Concept>::second
    >;

template<class Concept>
using get_placeholder_normalization_map =
    ::zr_boost_1_81::type_erasure::detail::create_placeholder_map<
        typename normalize_concept_impl_t<Concept>::second
    >;

// Flattens a Concept to an mpl::vector of primitive
// concepts.  Resolves same_type and deduced placeholders.
template<class Concept>
using normalize_concept_t =
    ::zr_boost_1_81::type_erasure::detail::normalize_concept_adjustments<
        Concept,
        zr_boost_1_81::type_erasure::detail::normalize_concept_impl_t<Concept>
    >;

template<class Concept>
using normalize_concept = ::zr_boost_1_81::mpl::identity< ::zr_boost_1_81::type_erasure::detail::normalize_concept_t<Concept> >;

template<class Map>
struct collect_concepts_f;

template<class Out, class Concept, class Map>
using collect_concepts_recursive = ::zr_boost_1_81::mp11::mp_fold<
    ::zr_boost_1_81::type_erasure::detail::make_mp_list<Concept>,
    Out,
    ::zr_boost_1_81::type_erasure::detail::collect_concepts_f<Map>::template apply
>;

template<class Concept, class Map, class Out, class Transformed>
using collect_concepts_impl =
    ::zr_boost_1_81::type_erasure::detail::eval_if< ::zr_boost_1_81::is_same<Transformed, void>::value,
        ::zr_boost_1_81::type_erasure::detail::first,
        ::zr_boost_1_81::mp11::mp_set_push_front,
        ::zr_boost_1_81::type_erasure::detail::eval_if< ::zr_boost_1_81::mpl::is_sequence<Concept>::value,
            ::zr_boost_1_81::type_erasure::detail::collect_concepts_recursive,
            ::zr_boost_1_81::type_erasure::detail::first,
            Out,
            Concept,
            Map
        >,
        Transformed
    >;

template<class Concept,
    class Map = ::zr_boost_1_81::type_erasure::detail::create_placeholder_map_t<
            typename ::zr_boost_1_81::type_erasure::detail::normalize_concept_impl_t<
                Concept
            >::second
        >,
    class Out = ::zr_boost_1_81::mp11::mp_list<>
>
using collect_concepts_t =
    collect_concepts_impl<Concept, Map, Out,
        typename ::zr_boost_1_81::type_erasure::detail::rebind_placeholders<
            Concept,
            Map
        >::type
    >;

template<class Map>
struct collect_concepts_f
{
    template<class Out, class Concept>
    using apply = ::zr_boost_1_81::type_erasure::detail::collect_concepts_t<Concept, Map, Out>;
};

// Returns an MPL sequence containing all the concepts
// in Concept.  If Concept is considered as a DAG,
// the result will be sorted topologically.
template<class Concept>
using collect_concepts = ::zr_boost_1_81::mpl::identity<
    ::zr_boost_1_81::type_erasure::detail::collect_concepts_t<Concept> >;

#endif

}
}
}

#endif
