#ifndef BOOST_METAPARSE_V1_UTIL_IS_DIGIT_HPP
#define BOOST_METAPARSE_V1_UTIL_IS_DIGIT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/metaparse/v1/util/in_range_c.hpp>

#include <boost/mpl/vector.hpp>

namespace zr_boost_1_81
{
  namespace metaparse
  {
    namespace v1
    {
      namespace util
      {
        template <class C = zr_boost_1_81::mpl::na>
        struct is_digit : in_range_c<char, '0', '9'>::apply<C> {};

        template <>
        struct is_digit<zr_boost_1_81::mpl::na>
        {
          typedef is_digit type;

          template <class C = zr_boost_1_81::mpl::na>
          struct apply : is_digit<C> {};
        };
      }
    }
  }
}

#endif

