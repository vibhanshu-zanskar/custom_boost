// Boost.TypeErasure library
//
// Copyright 2012 Steven Watanabe
//
// Distributed under the Boost Software License Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// $Id$

#ifndef BOOST_TYPE_ERASURE_DETAIL_CHECK_MAP_HPP_INCLUDED
#define BOOST_TYPE_ERASURE_DETAIL_CHECK_MAP_HPP_INCLUDED

#include <boost/mpl/not.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/set.hpp>
#include <boost/mpl/has_key.hpp>
#include <boost/mpl/find_if.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/end.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_erasure/detail/get_placeholders.hpp>
#include <boost/type_erasure/detail/normalize.hpp>
#include <boost/type_erasure/deduced.hpp>
#include <boost/type_erasure/static_binding.hpp>

namespace zr_boost_1_81 {
namespace type_erasure {
namespace detail {

template<class T>
struct is_deduced : zr_boost_1_81::mpl::false_ {};
template<class T>
struct is_deduced< ::zr_boost_1_81::type_erasure::deduced<T> > : zr_boost_1_81::mpl::true_ {};

// returns true if Map has a key for every non-deduced placeholder in Concept
template<class Concept, class Map>
struct check_map {
#ifndef BOOST_TYPE_ERASURE_USE_MP11
    typedef typename normalize_concept<Concept>::basic basic_components;

    typedef typename ::zr_boost_1_81::mpl::fold<
        basic_components,
        ::zr_boost_1_81::mpl::set0<>,
        ::zr_boost_1_81::type_erasure::detail::get_placeholders<
            ::zr_boost_1_81::mpl::_2,
            ::zr_boost_1_81::mpl::_1
        >
    >::type placeholders;

    // Every non-deduced placeholder referenced in this
    // map is indirectly deduced.
    typedef typename ::zr_boost_1_81::type_erasure::detail::get_placeholder_normalization_map<
        Concept>::type placeholder_subs;
    typedef typename ::zr_boost_1_81::mpl::fold<
        placeholder_subs,
        ::zr_boost_1_81::mpl::set0<>,
        ::zr_boost_1_81::mpl::insert<
            ::zr_boost_1_81::mpl::_1,
            ::zr_boost_1_81::mpl::second< ::zr_boost_1_81::mpl::_2>
        >
    >::type indirect_deduced_placeholders;
    typedef typename ::zr_boost_1_81::is_same<
        typename ::zr_boost_1_81::mpl::find_if<
            placeholders,
            ::zr_boost_1_81::mpl::not_<
                ::zr_boost_1_81::mpl::or_<
                    ::zr_boost_1_81::type_erasure::detail::is_deduced< ::zr_boost_1_81::mpl::_1>,
                    ::zr_boost_1_81::mpl::has_key<Map, ::zr_boost_1_81::mpl::_1>,
                    ::zr_boost_1_81::mpl::has_key<indirect_deduced_placeholders, ::zr_boost_1_81::mpl::_1>
                >
            >
        >::type,
        typename ::zr_boost_1_81::mpl::end<placeholders>::type
    >::type type;

#else
    typedef ::zr_boost_1_81::type_erasure::detail::get_all_placeholders<
        ::zr_boost_1_81::type_erasure::detail::normalize_concept_t<Concept>
    > placeholders;

    // Every non-deduced placeholder referenced in this
    // map is indirectly deduced.
    typedef typename ::zr_boost_1_81::type_erasure::detail::get_placeholder_normalization_map<
        Concept>::type placeholder_subs;
    typedef ::zr_boost_1_81::mp11::mp_unique<
        ::zr_boost_1_81::mp11::mp_append<
            ::zr_boost_1_81::mp11::mp_transform<
                ::zr_boost_1_81::mp11::mp_first,
                ::zr_boost_1_81::type_erasure::detail::make_mp_list<Map>
            >,
            ::zr_boost_1_81::mp11::mp_transform<
                ::zr_boost_1_81::mp11::mp_second,
                ::zr_boost_1_81::type_erasure::detail::make_mp_list<placeholder_subs>
            >
        >
    > okay_placeholders;
    template<class P>
    using check_placeholder = ::zr_boost_1_81::mpl::or_<
        ::zr_boost_1_81::type_erasure::detail::is_deduced<P>,
        ::zr_boost_1_81::mp11::mp_set_contains<okay_placeholders, P>
    >;
    typedef ::zr_boost_1_81::mp11::mp_all_of<placeholders, check_placeholder> type;
#endif
};

template<class Concept, class Map>
struct check_map<Concept, ::zr_boost_1_81::type_erasure::static_binding<Map> > :
    check_map<Concept, Map>
{};

}
}
}

#endif
