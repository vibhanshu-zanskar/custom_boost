//  (C) Copyright Andrzej Krzemienski 2015.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.

//[example_code
#define BOOST_TEST_MODULE decorator_21
#include <boost/test/included/unit_test.hpp>

namespace utf = zr_boost_1_81::unit_test;
namespace tt = zr_boost_1_81::test_tools;

tt::assertion_result fail(utf::test_unit_id)
{
  tt::assertion_result ans(false);
  ans.message() << "precondition failed";
  return ans;
}

BOOST_AUTO_TEST_CASE(test_1)
{
  BOOST_TEST(false);
}
 
BOOST_AUTO_TEST_CASE(test_2,
  * utf::depends_on("test_1"))
{
  BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(test_3,
  * utf::precondition(fail))
{
  BOOST_TEST(true);
}
//]
