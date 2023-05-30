// Copyright Daniel Wallin, David Abrahams 2005.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PARAMETER_VOID_050329_HPP
#define BOOST_PARAMETER_VOID_050329_HPP

namespace zr_boost_1_81 { namespace parameter { 

    // A placemarker for "no argument passed."
    // MAINTAINER NOTE: Do not make this into a metafunction
    struct void_
    {
    };
}} // namespace zr_boost_1_81::parameter

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    inline ::zr_boost_1_81::parameter::void_& void_reference()
    {
        static ::zr_boost_1_81::parameter::void_ instance;
        return instance;
    }
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/config/workaround.hpp>

#if BOOST_WORKAROUND(__SUNPRO_CC, BOOST_TESTED_AT(0x580))

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    typedef void* voidstar;
}}} // namespace zr_boost_1_81::parameter::aux

#endif
#endif  // include guard

