// Copyright David Abrahams, Daniel Wallin 2003.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PARAMETER_AUX_PACK_TAG_TYPE_HPP
#define BOOST_PARAMETER_AUX_PACK_TAG_TYPE_HPP

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    // helper for tag_type<...>, below.
    template <typename T>
    struct get_tag_type0
    {
        typedef typename T::key_type type;
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/deduced.hpp>
#include <boost/parameter/config.hpp>

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <boost/mp11/utility.hpp>
#else
#include <boost/mpl/eval_if.hpp>
#endif

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename T>
    struct get_tag_type
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
      : ::zr_boost_1_81::mp11::mp_if<
#else
      : ::zr_boost_1_81::mpl::eval_if<
#endif
            ::zr_boost_1_81::parameter::aux::is_deduced0<T>
          , ::zr_boost_1_81::parameter::aux::get_tag_type0<typename T::key_type>
          , ::zr_boost_1_81::parameter::aux::get_tag_type0<T>
        >
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/required.hpp>
#include <boost/parameter/optional.hpp>

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <boost/mp11/integral.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename T>
    using tag_type = ::zr_boost_1_81::mp11::mp_if<
        ::zr_boost_1_81::mp11::mp_if<
            ::zr_boost_1_81::parameter::aux::is_optional<T>
          , ::zr_boost_1_81::mp11::mp_true
          , ::zr_boost_1_81::parameter::aux::is_required<T>
        >
      , ::zr_boost_1_81::parameter::aux::get_tag_type<T>
      , ::zr_boost_1_81::mp11::mp_identity<T>
    >;
}}} // namespace zr_boost_1_81::parameter::aux

#else   // !defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/identity.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename T>
    struct tag_type
      : ::zr_boost_1_81::mpl::eval_if<
            typename ::zr_boost_1_81::mpl::if_<
                ::zr_boost_1_81::parameter::aux::is_optional<T>
              , ::zr_boost_1_81::mpl::true_
              , ::zr_boost_1_81::parameter::aux::is_required<T>
            >::type
          , ::zr_boost_1_81::parameter::aux::get_tag_type<T>
          , ::zr_boost_1_81::mpl::identity<T>
        >
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#endif  // BOOST_PARAMETER_CAN_USE_MP11
#endif  // include guard

