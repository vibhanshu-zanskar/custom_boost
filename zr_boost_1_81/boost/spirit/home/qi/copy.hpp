/*=============================================================================
    Copyright (c) 2001-2012 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(BOOST_SPIRIT_COPY_FEBRUARY_7_2012_0159PM)
#define BOOST_SPIRIT_COPY_FEBRUARY_7_2012_0159PM

#include <boost/config.hpp>

#if defined(_MSC_VER)
#pragma once
#endif

#if !defined(BOOST_NO_CXX11_AUTO_DECLARATIONS)
#include <boost/proto/deep_copy.hpp>

namespace zr_boost_1_81 { namespace spirit { namespace qi
{
    template <typename Expr>
    typename zr_boost_1_81::proto::result_of::deep_copy<Expr>::type
    copy(Expr const& expr)
    {
        BOOST_SPIRIT_ASSERT_MATCH(zr_boost_1_81::spirit::qi::domain, Expr);
        return zr_boost_1_81::proto::deep_copy(expr);
    }
}}}

#endif
#endif
