#ifndef BOOST_METAPARSE_V1_ALPHANUM_HPP
#define BOOST_METAPARSE_V1_ALPHANUM_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/metaparse/v1/one_of.hpp>
#include <boost/metaparse/v1/digit.hpp>
#include <boost/metaparse/v1/letter.hpp>

namespace zr_boost_1_81
{
  namespace metaparse
  {
    namespace v1
    {
      typedef one_of<letter, digit> alphanum;
    }
  }
}

#endif

