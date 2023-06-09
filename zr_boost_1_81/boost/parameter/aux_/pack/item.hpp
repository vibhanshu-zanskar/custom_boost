// Copyright David Abrahams, Daniel Wallin 2003.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PARAMETER_AUX_PACK_ITEM_HPP
#define BOOST_PARAMETER_AUX_PACK_ITEM_HPP

#include <boost/parameter/aux_/void.hpp>
#include <boost/config.hpp>
#include <boost/config/workaround.hpp>

#if BOOST_WORKAROUND(BOOST_BORLANDC, BOOST_TESTED_AT(0x564))
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#endif

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    // A parameter spec item typelist.
    template <
        typename Spec
      , typename Arg
      , typename Tail = ::zr_boost_1_81::parameter::void_
    >
    struct item
    {
        typedef Spec spec;
#if BOOST_WORKAROUND(BOOST_BORLANDC, BOOST_TESTED_AT(0x564))
        typedef ::zr_boost_1_81::is_const<
            typename ::zr_boost_1_81::remove_reference<Arg>::type
        > is_arg_const;
#endif
        typedef Arg arg;
        typedef Tail tail;
    };

    template <typename Spec, typename Arg, typename Tail>
    struct make_item
    {
        typedef zr_boost_1_81::parameter::aux
        ::item<Spec,Arg,typename Tail::type> type;
    };
}}} // namespace zr_boost_1_81::parameter::aux

#endif  // include guard

