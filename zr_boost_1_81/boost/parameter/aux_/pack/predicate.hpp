// Copyright David Abrahams, Daniel Wallin 2003.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PARAMETER_AUX_PACK_PREDICATE_HPP
#define BOOST_PARAMETER_AUX_PACK_PREDICATE_HPP

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    // helper for get_predicate<...>, below
    template <typename T>
    struct get_predicate_or_default
    {
        typedef T type;
    };

    // helper for predicate<...>, below
    template <typename T>
    struct get_predicate
      : ::zr_boost_1_81::parameter::aux
        ::get_predicate_or_default<typename T::predicate>
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/aux_/use_default.hpp>
#include <boost/parameter/aux_/always_true_predicate.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <>
    struct get_predicate_or_default< ::zr_boost_1_81::parameter::aux::use_default>
    {
        typedef ::zr_boost_1_81::parameter::aux::always_true_predicate type;
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/required.hpp>
#include <boost/parameter/optional.hpp>
#include <boost/parameter/config.hpp>

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <boost/mp11/integral.hpp>
#include <boost/mp11/utility.hpp>
#else
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#endif

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename T>
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
    using predicate = ::zr_boost_1_81::mp11::mp_if<
        ::zr_boost_1_81::mp11::mp_if<
            ::zr_boost_1_81::parameter::aux::is_optional<T>
          , ::zr_boost_1_81::mp11::mp_true
          , ::zr_boost_1_81::parameter::aux::is_required<T>
        >
      , ::zr_boost_1_81::parameter::aux::get_predicate<T>
      , ::zr_boost_1_81::mp11::mp_identity<
            ::zr_boost_1_81::parameter::aux::always_true_predicate
        >
    >;
#else
    struct predicate
      : ::zr_boost_1_81::mpl::eval_if<
            typename ::zr_boost_1_81::mpl::if_<
                ::zr_boost_1_81::parameter::aux::is_optional<T>
              , ::zr_boost_1_81::mpl::true_
              , ::zr_boost_1_81::parameter::aux::is_required<T>
            >::type
          , ::zr_boost_1_81::parameter::aux::get_predicate<T>
          , ::zr_boost_1_81::mpl::identity<
                ::zr_boost_1_81::parameter::aux::always_true_predicate
            >
        >
    {
    };
#endif  // BOOST_PARAMETER_CAN_USE_MP11
}}} // namespace zr_boost_1_81::parameter::aux

#endif  // include guard

