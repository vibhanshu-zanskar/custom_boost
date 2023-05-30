#ifndef BOOST_METAPARSE_V1_UTIL_IN_RANGE_HPP
#define BOOST_METAPARSE_V1_UTIL_IN_RANGE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/less_equal.hpp>
#include <boost/mpl/comparison.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/mpl/bool.hpp>

#include <boost/mpl/vector.hpp>

namespace zr_boost_1_81
{
  namespace metaparse
  {
    namespace v1
    {
      namespace util
      {
        template <
          class LowerBound = zr_boost_1_81::mpl::na,
          class UpperBound = zr_boost_1_81::mpl::na,
          class Item = zr_boost_1_81::mpl::na
        >
        struct in_range :
          zr_boost_1_81::mpl::bool_<
            zr_boost_1_81::mpl::less_equal<LowerBound, Item>::type::value
            && zr_boost_1_81::mpl::less_equal<Item, UpperBound>::type::value
          >
        {};

        template <class LowerBound, class UpperBound>
        struct in_range<LowerBound, UpperBound, zr_boost_1_81::mpl::na>
        {
          typedef in_range type;

          template <class Item = zr_boost_1_81::mpl::na>
          struct apply : in_range<LowerBound, UpperBound, Item> {};
        };

        template <class LowerBound>
        struct in_range<LowerBound, zr_boost_1_81::mpl::na, zr_boost_1_81::mpl::na>
        {
          typedef in_range type;

          template <
            class UpperBound = zr_boost_1_81::mpl::na,
            class Item = zr_boost_1_81::mpl::na
          >
          struct apply : in_range<LowerBound, UpperBound, Item> {};
        };

        template <>
        struct in_range<zr_boost_1_81::mpl::na, zr_boost_1_81::mpl::na, zr_boost_1_81::mpl::na>
        {
          typedef in_range type;

          template <
            class LowerBound = zr_boost_1_81::mpl::na,
            class UpperBound = zr_boost_1_81::mpl::na,
            class Item = zr_boost_1_81::mpl::na
          >
          struct apply : in_range<LowerBound, UpperBound, Item> {};
        };
      }
    }
  }
}

#endif

