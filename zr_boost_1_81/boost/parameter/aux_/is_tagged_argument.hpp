// Copyright Daniel Wallin, David Abrahams 2005.
// Copyright Cromwell D. Enage 2017.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PARAMETER_IS_TAGGED_ARGUMENT_HPP
#define BOOST_PARAMETER_IS_TAGGED_ARGUMENT_HPP

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    struct tagged_argument_base
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/config.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

#if defined(BOOST_PARAMETER_HAS_PERFECT_FORWARDING) || \
    (0 < BOOST_PARAMETER_EXPONENTIAL_OVERLOAD_THRESHOLD_ARITY)
#include <boost/type_traits/is_base_of.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    // This metafunction identifies tagged_argument specializations
    // and their derived classes.
    template <typename T>
    struct is_tagged_argument
      : ::zr_boost_1_81::mpl::if_<
            // Cannot use is_convertible<> to check if T is derived from
            // tagged_argument_base. -- Cromwell D. Enage
            ::zr_boost_1_81::is_base_of<
                ::zr_boost_1_81::parameter::aux::tagged_argument_base
              , typename ::zr_boost_1_81::remove_const<
                    typename ::zr_boost_1_81::remove_reference<T>::type
                >::type
            >
          , ::zr_boost_1_81::mpl::true_
          , ::zr_boost_1_81::mpl::false_
        >::type
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#else   // no perfect forwarding support and no exponential overloads
#include <boost/type_traits/is_convertible.hpp>
#include <boost/type_traits/is_lvalue_reference.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename T>
    struct is_tagged_argument_aux
      : ::zr_boost_1_81::is_convertible<
            T*
          , ::zr_boost_1_81::parameter::aux::tagged_argument_base const*
        >
    {
    };

    // This metafunction identifies tagged_argument specializations
    // and their derived classes.
    template <typename T>
    struct is_tagged_argument
      : ::zr_boost_1_81::mpl::if_<
            ::zr_boost_1_81::is_lvalue_reference<T>
          , ::zr_boost_1_81::mpl::false_
          , ::zr_boost_1_81::parameter::aux::is_tagged_argument_aux<T>
        >::type
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#endif  // perfect forwarding support, or exponential overloads

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <type_traits>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename T>
    using is_tagged_argument_mp11 = ::std::is_base_of<
        ::zr_boost_1_81::parameter::aux::tagged_argument_base
      , typename ::std::remove_const<
            typename ::std::remove_reference<T>::type
        >::type
    >;
}}} // namespace zr_boost_1_81::parameter::aux

#endif  // BOOST_PARAMETER_CAN_USE_MP11
#endif  // include guard

