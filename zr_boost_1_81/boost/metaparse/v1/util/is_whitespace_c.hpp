#ifndef BOOST_METAPARSE_V1_UTIL_IS_WHITESPACE_C_HPP
#define BOOST_METAPARSE_V1_UTIL_IS_WHITESPACE_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/bool.hpp>

namespace zr_boost_1_81
{
  namespace metaparse
  {
    namespace v1
    {
      namespace util
      {
        template <char C>
        struct is_whitespace_c : zr_boost_1_81::mpl::false_ {};

        template <> struct is_whitespace_c<' '> : zr_boost_1_81::mpl::true_ {};
        template <> struct is_whitespace_c<'\r'> : zr_boost_1_81::mpl::true_ {};
        template <> struct is_whitespace_c<'\n'> : zr_boost_1_81::mpl::true_ {};
        template <> struct is_whitespace_c<'\t'> : zr_boost_1_81::mpl::true_ {};
      }
    }
  }
}

#endif

