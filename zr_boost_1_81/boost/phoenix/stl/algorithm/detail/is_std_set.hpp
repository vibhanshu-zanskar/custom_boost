// Copyright 2005 Daniel Wallin.
// Copyright 2005 Joel de Guzman.
//
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// Modeled after range_ex, Copyright 2004 Eric Niebler
///////////////////////////////////////////////////////////////////////////////
//
// is_std_set.hpp
//
/////////////////////////////////////////////////////////////////////////////

#if defined(_MSC_VER)
# pragma once
#endif

#ifndef BOOST_PHOENIX_IS_STD_SET_EN_16_12_2004
#define BOOST_PHOENIX_IS_STD_SET_EN_16_12_2004

#include <boost/mpl/bool.hpp>
#include <set>

namespace zr_boost_1_81
{
    template<class T>
    struct is_std_set
        : zr_boost_1_81::mpl::false_
    {};

    template<
        class Kty
      , class Pr
      , class Alloc
    >
    struct is_std_set< ::std::set<Kty,Pr,Alloc> >
        : zr_boost_1_81::mpl::true_
    {};

    template<class T>
    struct is_std_multiset
        : zr_boost_1_81::mpl::false_
    {};

    template<
        class Kty
      , class Pr
      , class Alloc
    >
    struct is_std_multiset< ::std::multiset<Kty,Pr,Alloc> >
        : zr_boost_1_81::mpl::true_
    {};
}

#endif
