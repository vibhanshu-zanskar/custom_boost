// Copyright David Abrahams, Daniel Wallin 2003.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PARAMETER_AUX_PACK_MAKE_ITEMS_HPP
#define BOOST_PARAMETER_AUX_PACK_MAKE_ITEMS_HPP

#include <boost/parameter/aux_/void.hpp>
#include <boost/parameter/aux_/pack/item.hpp>
#include <boost/parameter/config.hpp>

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <boost/mp11/utility.hpp>
#include <type_traits>
#else
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/type_traits/is_same.hpp>
#endif

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    // Creates a item typelist.
    template <typename Spec, typename Arg, typename Tail>
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
    using make_items = ::zr_boost_1_81::mp11::mp_if<
        ::std::is_same<Arg,::zr_boost_1_81::parameter::void_>
      , ::zr_boost_1_81::mp11::mp_identity< ::zr_boost_1_81::parameter::void_>
      , ::zr_boost_1_81::parameter::aux::make_item<Spec,Arg,Tail>
    >;
#else
    struct make_items
      : ::zr_boost_1_81::mpl::eval_if<
            ::zr_boost_1_81::is_same<Arg,::zr_boost_1_81::parameter::void_>
          , ::zr_boost_1_81::mpl::identity< ::zr_boost_1_81::parameter::void_>
          , ::zr_boost_1_81::parameter::aux::make_item<Spec,Arg,Tail>
        >
    {
    };
#endif
}}} // namespace zr_boost_1_81::parameter::aux

#endif  // include guard

