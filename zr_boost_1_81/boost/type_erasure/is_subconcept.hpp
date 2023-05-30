// Boost.TypeErasure library
//
// Copyright 2012 Steven Watanabe
//
// Distributed under the Boost Software License Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// $Id$

#ifndef BOOST_TYPE_ERASURE_IS_SUBCONCEPT_HPP_INCLUDED
#define BOOST_TYPE_ERASURE_IS_SUBCONCEPT_HPP_INCLUDED

#include <boost/mpl/and.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/find_if.hpp>
#include <boost/mpl/has_key.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_erasure/detail/normalize.hpp>
#include <boost/type_erasure/detail/check_map.hpp>
#include <boost/type_erasure/detail/rebind_placeholders.hpp>
#include <boost/type_erasure/static_binding.hpp>

namespace zr_boost_1_81 {
namespace type_erasure {
namespace detail {

#ifdef BOOST_TYPE_ERASURE_USE_MP11

template<class S, class K>
struct mp_set_has_key : ::zr_boost_1_81::mp11::mp_set_contains<S, K> {};

template<class Super, class Bindings>
struct is_subconcept_f
{
    template<class T>
    using apply = ::zr_boost_1_81::mp11::mp_set_contains<Super, ::zr_boost_1_81::type_erasure::detail::rebind_placeholders_t<T, Bindings> >;
};

template<class Super>
struct is_subconcept_f<Super, void>
{
    template<class T>
    using apply = ::zr_boost_1_81::mp11::mp_set_contains<Super, T>;
};

#endif

template<class Sub, class Super, class PlaceholderMap>
struct is_subconcept_impl {
#ifndef BOOST_TYPE_ERASURE_USE_MP11
    typedef typename ::zr_boost_1_81::type_erasure::detail::normalize_concept<
        Super>::concept_set super_set;

    typedef typename ::zr_boost_1_81::type_erasure::detail::get_placeholder_normalization_map<
        Super
    >::type placeholder_subs_super;
    
    typedef typename ::zr_boost_1_81::type_erasure::detail::normalize_concept<
        Sub>::type normalized_sub;
    typedef typename ::zr_boost_1_81::type_erasure::detail::get_placeholder_normalization_map<
        Sub
    >::type placeholder_subs_sub;

    typedef typename ::zr_boost_1_81::mpl::eval_if< ::zr_boost_1_81::is_same<PlaceholderMap, void>,
        zr_boost_1_81::mpl::identity<void>,
        ::zr_boost_1_81::type_erasure::detail::convert_deductions<
            PlaceholderMap,
            placeholder_subs_sub,
            placeholder_subs_super
        >
    >::type bindings;

    typedef typename ::zr_boost_1_81::mpl::if_< ::zr_boost_1_81::is_same<PlaceholderMap, void>,
        ::zr_boost_1_81::mpl::_1,
        ::zr_boost_1_81::type_erasure::detail::rebind_placeholders<
            ::zr_boost_1_81::mpl::_1,
            bindings
        >
    >::type transform;

    typedef typename ::zr_boost_1_81::is_same<
        typename ::zr_boost_1_81::mpl::find_if<normalized_sub,
            ::zr_boost_1_81::mpl::not_<
                ::zr_boost_1_81::mpl::has_key<
                    super_set,
                    transform
                >
            >
        >::type,
        typename ::zr_boost_1_81::mpl::end<normalized_sub>::type
    >::type type;
#else
    typedef ::zr_boost_1_81::type_erasure::detail::normalize_concept_t<Super> super_set;

    typedef ::zr_boost_1_81::type_erasure::detail::get_placeholder_normalization_map_t<
        Super
    > placeholder_subs_super;
    
    typedef ::zr_boost_1_81::type_erasure::detail::normalize_concept_t<Sub> normalized_sub;
    typedef ::zr_boost_1_81::type_erasure::detail::get_placeholder_normalization_map_t<
        Sub
    > placeholder_subs_sub;
    typedef ::zr_boost_1_81::mp11::mp_eval_if_c< ::zr_boost_1_81::is_same<PlaceholderMap, void>::value,
        void,
        ::zr_boost_1_81::type_erasure::detail::convert_deductions_t,
        PlaceholderMap,
        placeholder_subs_sub,
        placeholder_subs_super
    > bindings;

    typedef typename ::zr_boost_1_81::mp11::mp_all_of<
        normalized_sub,
        ::zr_boost_1_81::type_erasure::detail::is_subconcept_f<super_set, bindings>::template apply
    > type;
#endif
};

}

/**
 * @ref is_subconcept is a boolean metafunction that determines whether
 * one concept is a sub-concept of another.
 *
 * \code
 * is_subconcept<incrementable<>, incrementable<> >             -> true
 * is_subconcept<incrementable<>, addable<> >                   -> false
 * is_subconcept<incrementable<_a>, forward_iterator<_iter>,
 *   mpl::map<mpl::pair<_a, _iter> > >                          -> true
 * \endcode
 *
 * \tparam Sub The sub concept
 * \tparam Super The super concept
 * \tparam PlaceholderMap (optional) An MPL map with keys for
 *   every non-deduced placeholder in Sub.  The
 *   associated value of each key is the corresponding placeholder
 *   in Super.  If @c PlaceholderMap is omitted, @c Super and @c Sub
 *   are presumed to use the same set of placeholders.
 */
template<class Sub, class Super, class PlaceholderMap = void>
struct is_subconcept :
    ::zr_boost_1_81::mpl::and_<
        ::zr_boost_1_81::type_erasure::detail::check_map<Sub, PlaceholderMap>,
        ::zr_boost_1_81::type_erasure::detail::is_subconcept_impl<Sub, Super, PlaceholderMap>
    >::type
{};

#ifndef BOOST_TYPE_ERASURE_DOXYGEN
template<class Sub, class Super>
struct is_subconcept<Sub, Super, void> :
    ::zr_boost_1_81::type_erasure::detail::is_subconcept_impl<Sub, Super, void>::type
{};
template<class Sub, class Super, class PlaceholderMap>
struct is_subconcept<Sub, Super, static_binding<PlaceholderMap> > :
    ::zr_boost_1_81::mpl::and_<
        ::zr_boost_1_81::type_erasure::detail::check_map<Sub, PlaceholderMap>,
        ::zr_boost_1_81::type_erasure::detail::is_subconcept_impl<Sub, Super, PlaceholderMap>
    >::type
{};
#endif

}
}

#endif
