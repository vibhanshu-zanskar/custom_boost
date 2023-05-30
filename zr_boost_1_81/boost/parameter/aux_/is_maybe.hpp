// Copyright Daniel Wallin, David Abrahams 2010.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PARAMETER_IS_MAYBE_050329_HPP
#define BOOST_PARAMETER_IS_MAYBE_050329_HPP

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    struct maybe_base
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <type_traits>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename T>
    using is_maybe = ::std::is_base_of<
        ::zr_boost_1_81::parameter::aux::maybe_base
      , typename ::std::remove_const<T>::type
    >;
}}} // namespace zr_boost_1_81::parameter::aux

#else   // !defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <boost/type_traits/remove_const.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename T>
    struct is_maybe
      : ::zr_boost_1_81::mpl::if_<
            ::zr_boost_1_81::is_base_of<
                ::zr_boost_1_81::parameter::aux::maybe_base
              , typename ::zr_boost_1_81::remove_const<T>::type
            >
          , ::zr_boost_1_81::mpl::true_
          , ::zr_boost_1_81::mpl::false_
        >::type
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#endif  // BOOST_PARAMETER_CAN_USE_MP11
#endif  // include guard

