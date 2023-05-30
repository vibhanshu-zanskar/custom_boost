#ifndef BOOST_METAPARSE_V1_UTIL_DIGIT_TO_INT_C_HPP
#define BOOST_METAPARSE_V1_UTIL_DIGIT_TO_INT_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/metaparse/v1/error/digit_expected.hpp>

#include <boost/mpl/int.hpp>

namespace zr_boost_1_81
{
  namespace metaparse
  {
    namespace v1
    {
      namespace util
      {
        template <char C>
        struct digit_to_int_c : error::digit_expected {};

        template <> struct digit_to_int_c<'0'> : zr_boost_1_81::mpl::int_<0> {};
        template <> struct digit_to_int_c<'1'> : zr_boost_1_81::mpl::int_<1> {};
        template <> struct digit_to_int_c<'2'> : zr_boost_1_81::mpl::int_<2> {};
        template <> struct digit_to_int_c<'3'> : zr_boost_1_81::mpl::int_<3> {};
        template <> struct digit_to_int_c<'4'> : zr_boost_1_81::mpl::int_<4> {};
        template <> struct digit_to_int_c<'5'> : zr_boost_1_81::mpl::int_<5> {};
        template <> struct digit_to_int_c<'6'> : zr_boost_1_81::mpl::int_<6> {};
        template <> struct digit_to_int_c<'7'> : zr_boost_1_81::mpl::int_<7> {};
        template <> struct digit_to_int_c<'8'> : zr_boost_1_81::mpl::int_<8> {};
        template <> struct digit_to_int_c<'9'> : zr_boost_1_81::mpl::int_<9> {};
      }
    }
  }
}

#endif

