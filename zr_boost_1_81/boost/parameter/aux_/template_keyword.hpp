// Copyright Daniel Wallin 2006.
// Copyright Cromwell D. Enage 2017.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PARAMETER_TEMPLATE_KEYWORD_060203_HPP
#define BOOST_PARAMETER_TEMPLATE_KEYWORD_060203_HPP

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    struct template_keyword_base
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/config.hpp>

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <type_traits>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename T>
    using is_template_keyword = ::std::is_base_of<
        ::zr_boost_1_81::parameter::aux::template_keyword_base
      , typename ::std::remove_const<
            typename ::std::remove_reference<T>::type
        >::type
    >;
}}} // namespace zr_boost_1_81::parameter::aux

#else   // !defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/remove_const.hpp>

#if defined(BOOST_PARAMETER_HAS_PERFECT_FORWARDING)
#include <boost/type_traits/is_base_of.hpp>
#include <boost/type_traits/remove_reference.hpp>
#else
#include <boost/type_traits/is_convertible.hpp>
#include <boost/type_traits/is_lvalue_reference.hpp>
#endif

namespace zr_boost_1_81 { namespace parameter { namespace aux {

#if !defined(BOOST_PARAMETER_HAS_PERFECT_FORWARDING)
    template <typename T>
    struct is_template_keyword_aux
      : ::zr_boost_1_81::mpl::if_<
            ::zr_boost_1_81::is_convertible<
                T*
              , ::zr_boost_1_81::parameter::aux::template_keyword_base const*
            >
          , ::zr_boost_1_81::mpl::true_
          , ::zr_boost_1_81::mpl::false_
        >::type
    {
    };
#endif  // BOOST_PARAMETER_HAS_PERFECT_FORWARDING

    template <typename T>
    struct is_template_keyword
      : ::zr_boost_1_81::mpl::if_<
#if defined(BOOST_PARAMETER_HAS_PERFECT_FORWARDING)
            // Cannot use is_convertible<> to check if T is derived from
            // template_keyword_base. -- Cromwell D. Enage
            ::zr_boost_1_81::is_base_of<
                ::zr_boost_1_81::parameter::aux::template_keyword_base
              , typename ::zr_boost_1_81::remove_const<
                    typename ::zr_boost_1_81::remove_reference<T>::type
                >::type
            >
          , ::zr_boost_1_81::mpl::true_
          , ::zr_boost_1_81::mpl::false_
#else
            ::zr_boost_1_81::is_lvalue_reference<T>
          , ::zr_boost_1_81::mpl::false_
          , ::zr_boost_1_81::parameter::aux::is_template_keyword_aux<T>
#endif  // BOOST_PARAMETER_HAS_PERFECT_FORWARDING
        >::type
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#endif  // BOOST_PARAMETER_CAN_USE_MP11
#endif  // include guard

