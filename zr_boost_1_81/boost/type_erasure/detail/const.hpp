// Boost.TypeErasure library
//
// Copyright 2012 Steven Watanabe
//
// Distributed under the Boost Software License Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// $Id$

#ifndef BOOST_TYPE_ERASURE_DETAIL_CONST_HPP_INCLUDED
#define BOOST_TYPE_ERASURE_DETAIL_CONST_HPP_INCLUDED

#include <boost/mpl/if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/is_reference.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <boost/type_traits/remove_cv.hpp>
#include <boost/type_erasure/placeholder_of.hpp>
#include <boost/type_erasure/derived.hpp>

namespace zr_boost_1_81 {
namespace type_erasure {
namespace detail {

template<class T>
struct is_non_const_ref : zr_boost_1_81::mpl::false_ {};
template<class T>
struct is_non_const_ref<T&> : zr_boost_1_81::mpl::true_ {};
template<class T>
struct is_non_const_ref<const T&> : zr_boost_1_81::mpl::false_ {};

template<class Placeholder, class Base>
struct should_be_const :
    ::zr_boost_1_81::mpl::or_<
        ::zr_boost_1_81::is_const<Placeholder>,
        ::zr_boost_1_81::type_erasure::detail::is_non_const_ref<
            typename ::zr_boost_1_81::type_erasure::placeholder_of<Base>::type
        >
    >
{};

template<class Placeholder, class Base>
struct should_be_non_const :
    ::zr_boost_1_81::mpl::and_<
        ::zr_boost_1_81::mpl::not_< ::zr_boost_1_81::is_const<Placeholder> >,
        ::zr_boost_1_81::mpl::not_<
            ::zr_boost_1_81::is_reference<
                typename ::zr_boost_1_81::type_erasure::placeholder_of<Base>::type
            >
        >
    >
{};

template<class Base>
struct non_const_this_param
{
    typedef typename ::zr_boost_1_81::type_erasure::placeholder_of<Base>::type placeholder;
    typedef typename ::zr_boost_1_81::type_erasure::derived<Base>::type plain_type;
    typedef typename ::zr_boost_1_81::mpl::if_<
        ::zr_boost_1_81::is_same<
            placeholder,
            typename ::zr_boost_1_81::remove_cv<
                typename ::zr_boost_1_81::remove_reference<placeholder>::type
            >::type&
        >,
        const plain_type,
        plain_type
    >::type type;
};

template<class T>
struct uncallable {};

template<class Placeholder, class Base>
struct maybe_const_this_param
{
    typedef typename ::zr_boost_1_81::type_erasure::derived<Base>::type plain_type;
    typedef typename ::zr_boost_1_81::remove_reference<Placeholder>::type plain_placeholder;
    typedef typename ::zr_boost_1_81::mpl::if_< ::zr_boost_1_81::is_reference<Placeholder>,
        typename ::zr_boost_1_81::mpl::if_<
            ::zr_boost_1_81::type_erasure::detail::should_be_non_const<plain_placeholder, Base>,
            plain_type&,
            typename ::zr_boost_1_81::mpl::if_<
                ::zr_boost_1_81::type_erasure::detail::should_be_const<plain_placeholder, Base>,
                const plain_type&,
                uncallable<plain_type>
            >::type
        >::type,
        plain_type
    >::type type;
};

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES

template<class Placeholder, class Base>
struct maybe_const_this_param<Placeholder&&, Base>
{
    typedef typename ::zr_boost_1_81::type_erasure::derived<Base>::type plain_type;
    typedef typename ::zr_boost_1_81::remove_reference<Placeholder>::type plain_placeholder;
    typedef typename ::zr_boost_1_81::type_erasure::placeholder_of<plain_type>::type self_placeholder;
    typedef typename ::zr_boost_1_81::mpl::if_< ::zr_boost_1_81::is_lvalue_reference<self_placeholder>,
        ::zr_boost_1_81::type_erasure::detail::uncallable<plain_type>,
        typename ::zr_boost_1_81::mpl::if_< ::zr_boost_1_81::is_rvalue_reference<self_placeholder>,
            const plain_type&,
            plain_type&&
        >::type
    >::type type;
};

#endif

}
}
}

#endif
