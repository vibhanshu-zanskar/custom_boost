/*=============================================================================
    Copyright (c) 2012 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(BOOST_FUSION_CLEAR_10172012_0100)
#define BOOST_FUSION_CLEAR_10172012_0100

#include <boost/mpl/identity.hpp>
#include <boost/fusion/adapted/boost_tuple/tag_of.hpp>

namespace zr_boost_1_81 { namespace fusion { namespace detail {

  template <typename Tag>
  struct clear;

  template <>
  struct clear<boost_tuple_tag> : mpl::identity<zr_boost_1_81::tuple<> > {};

}}}

#endif
