/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef BOOST_SPIRIT_QI_DIRECTIVE_NO_CASE_HPP
#define BOOST_SPIRIT_QI_DIRECTIVE_NO_CASE_HPP

#if defined(_MSC_VER)
#pragma once
#endif

#include <boost/spirit/home/qi/meta_compiler.hpp>
#include <boost/spirit/home/support/common_terminals.hpp>

namespace zr_boost_1_81 { namespace spirit
{
    ///////////////////////////////////////////////////////////////////////////
    // Enablers
    ///////////////////////////////////////////////////////////////////////////
    template <typename CharEncoding>
    struct use_directive<
        qi::domain, tag::char_code<tag::no_case, CharEncoding> > // enables no_case
      : mpl::true_ {};

    template <typename CharEncoding>
    struct is_modifier_directive<qi::domain, tag::char_code<tag::no_case, CharEncoding> >
      : mpl::true_ {};
}}

#endif
