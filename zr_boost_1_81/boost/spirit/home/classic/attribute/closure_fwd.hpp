/*=============================================================================
    Copyright (c) 2006 Tobias Schwinger
    http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(BOOST_SPIRIT_CLOSURE_FWD_HPP)
#define BOOST_SPIRIT_CLOSURE_FWD_HPP

#include <boost/spirit/home/classic/namespace.hpp>
#include <boost/spirit/home/classic/phoenix/tuples.hpp>

#if !defined(BOOST_SPIRIT_CLOSURE_LIMIT)
#   define BOOST_SPIRIT_CLOSURE_LIMIT PHOENIX_LIMIT
#endif

namespace zr_boost_1_81 { namespace spirit {

BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

    template<typename ClosureT>
    class closure_context;

    template <typename ClosureT>
    class init_closure_context;

    template <typename ParserT, typename ActorTupleT>
    struct init_closure_parser;

    template <
            typename DerivedT
        ,   typename T0 = ::zr_boost_1_81phoenix::nil_t
        ,   typename T1 = ::zr_boost_1_81phoenix::nil_t
        ,   typename T2 = ::zr_boost_1_81phoenix::nil_t

    #if BOOST_SPIRIT_CLOSURE_LIMIT > 3
        ,   typename T3 = ::zr_boost_1_81phoenix::nil_t
        ,   typename T4 = ::zr_boost_1_81phoenix::nil_t
        ,   typename T5 = ::zr_boost_1_81phoenix::nil_t

    #if BOOST_SPIRIT_CLOSURE_LIMIT > 6
        ,   typename T6 = ::zr_boost_1_81phoenix::nil_t
        ,   typename T7 = ::zr_boost_1_81phoenix::nil_t
        ,   typename T8 = ::zr_boost_1_81phoenix::nil_t

    #if BOOST_SPIRIT_CLOSURE_LIMIT > 9
        ,   typename T9 = ::zr_boost_1_81phoenix::nil_t
        ,   typename T10 = ::zr_boost_1_81phoenix::nil_t
        ,   typename T11 = ::zr_boost_1_81phoenix::nil_t

    #if BOOST_SPIRIT_CLOSURE_LIMIT > 12
        ,   typename T12 = ::zr_boost_1_81phoenix::nil_t
        ,   typename T13 = ::zr_boost_1_81phoenix::nil_t
        ,   typename T14 = ::zr_boost_1_81phoenix::nil_t

    #endif
    #endif
    #endif
    #endif
    >
    struct closure;

BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}} // namespace BOOST_SPIRIT_CLASSIC_NS

#endif

