// Copyright David Abrahams 2005.
// Copyright Cromwell D. Enage 2017.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PARAMETER_AUX_TAG_DWA2005610_HPP
#define BOOST_PARAMETER_AUX_TAG_DWA2005610_HPP

#include <boost/parameter/aux_/unwrap_cv_reference.hpp>
#include <boost/parameter/aux_/tagged_argument.hpp>
#include <boost/parameter/config.hpp>

#if defined(BOOST_PARAMETER_CAN_USE_MP11) && \
    !BOOST_WORKAROUND(BOOST_MSVC, >= 1910)
// MSVC-14.1+ assigns rvalue references to tagged_argument instances
// instead of tagged_argument_rref instances with this code.
#include <boost/mp11/integral.hpp>
#include <boost/mp11/utility.hpp>
#include <type_traits>

namespace zr_boost_1_81 { namespace parameter { namespace aux { 

    template <typename Keyword, typename Arg>
    struct tag_if_lvalue_reference
    {
        using type = ::zr_boost_1_81::parameter::aux::tagged_argument_list_of_1<
            ::zr_boost_1_81::parameter::aux::tagged_argument<
                Keyword
              , typename ::zr_boost_1_81::parameter::aux
                ::unwrap_cv_reference<Arg>::type
            >
        >;
    };

    template <typename Keyword, typename Arg>
    struct tag_if_scalar
    {
        using type = ::zr_boost_1_81::parameter::aux::tagged_argument_list_of_1<
            ::zr_boost_1_81::parameter::aux
            ::tagged_argument<Keyword,typename ::std::add_const<Arg>::type>
        >;
    };

    template <typename Keyword, typename Arg>
    using tag_if_otherwise = ::zr_boost_1_81::mp11::mp_if<
        ::std::is_scalar<typename ::std::remove_const<Arg>::type>
      , ::zr_boost_1_81::parameter::aux::tag_if_scalar<Keyword,Arg>
      , ::zr_boost_1_81::mp11::mp_identity<
            ::zr_boost_1_81::parameter::aux::tagged_argument_list_of_1<
                ::zr_boost_1_81::parameter::aux::tagged_argument_rref<Keyword,Arg>
            >
        >
    >;

    template <typename Keyword, typename Arg>
    using tag = ::zr_boost_1_81::mp11::mp_if<
        ::zr_boost_1_81::mp11::mp_if<
            ::std::is_lvalue_reference<Arg>
          , ::zr_boost_1_81::mp11::mp_true
          , ::zr_boost_1_81::parameter::aux::is_cv_reference_wrapper<Arg>
        >
      , ::zr_boost_1_81::parameter::aux::tag_if_lvalue_reference<Keyword,Arg>
      , ::zr_boost_1_81::parameter::aux::tag_if_otherwise<Keyword,Arg>
    >;
}}} // namespace zr_boost_1_81::parameter::aux_

#elif defined(BOOST_PARAMETER_HAS_PERFECT_FORWARDING)
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/is_scalar.hpp>
#include <boost/type_traits/is_lvalue_reference.hpp>
#include <boost/type_traits/remove_const.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux { 

    template <typename Keyword, typename ActualArg>
    struct tag
    {
        typedef typename ::zr_boost_1_81::parameter::aux
        ::unwrap_cv_reference<ActualArg>::type Arg;
        typedef typename ::zr_boost_1_81::add_const<Arg>::type ConstArg;
        typedef typename ::zr_boost_1_81::remove_const<Arg>::type MutArg;
        typedef typename ::zr_boost_1_81::mpl::eval_if<
            typename ::zr_boost_1_81::mpl::if_<
                ::zr_boost_1_81::is_lvalue_reference<ActualArg>
              , ::zr_boost_1_81::mpl::true_
              , ::zr_boost_1_81::parameter::aux::is_cv_reference_wrapper<ActualArg>
            >::type
          , ::zr_boost_1_81::mpl::identity<
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
                ::zr_boost_1_81::parameter::aux::tagged_argument_list_of_1<
#endif
                    ::zr_boost_1_81::parameter::aux::tagged_argument<Keyword,Arg>
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
                >
#endif
            >
          , ::zr_boost_1_81::mpl::if_<
                ::zr_boost_1_81::is_scalar<MutArg>
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
              , ::zr_boost_1_81::parameter::aux::tagged_argument_list_of_1<
                    ::zr_boost_1_81::parameter::aux::tagged_argument<Keyword,ConstArg>
                >
              , ::zr_boost_1_81::parameter::aux::tagged_argument_list_of_1<
                    ::zr_boost_1_81::parameter::aux::tagged_argument_rref<Keyword,Arg>
                >
#else
              , ::zr_boost_1_81::parameter::aux::tagged_argument<Keyword,ConstArg>
              , ::zr_boost_1_81::parameter::aux::tagged_argument_rref<Keyword,Arg>
#endif
            >
        >::type type;
    };
}}} // namespace zr_boost_1_81::parameter::aux_

#else   // !defined(BOOST_PARAMETER_HAS_PERFECT_FORWARDING)

namespace zr_boost_1_81 { namespace parameter { namespace aux { 

    template <
        typename Keyword
      , typename Arg
#if BOOST_WORKAROUND(BOOST_BORLANDC, BOOST_TESTED_AT(0x564))
      , typename = typename ::zr_boost_1_81::parameter::aux
        ::is_cv_reference_wrapper<Arg>::type
#endif
    >
    struct tag
    {
        typedef ::zr_boost_1_81::parameter::aux::tagged_argument<
            Keyword
          , typename ::zr_boost_1_81::parameter::aux::unwrap_cv_reference<Arg>::type
        > type;
    };
}}} // namespace zr_boost_1_81::parameter::aux_

#if BOOST_WORKAROUND(BOOST_BORLANDC, BOOST_TESTED_AT(0x564))
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/remove_reference.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux { 

    template <typename Keyword, typename Arg>
    struct tag<Keyword,Arg,::zr_boost_1_81::mpl::false_>
    {
        typedef ::zr_boost_1_81::parameter::aux::tagged_argument<
            Keyword
          , typename ::zr_boost_1_81::remove_reference<Arg>::type
        > type;
    };
}}} // namespace zr_boost_1_81::parameter::aux_

#endif  // Borland workarounds needed.
#endif  // MP11 or perfect forwarding support
#endif  // include guard

