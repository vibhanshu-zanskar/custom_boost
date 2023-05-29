//  initialization_test.cpp  -------------------------------------------------//

//  Copyright Christoper Kohlhoff 2007

//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See library home page at http://www.boost.org/libs/system

//  This test verifiies that the error_category vtable does not suffer from
//  order-of-initialization problems.

#include <boost/system/error_code.hpp>
#include <boost/core/lightweight_test.hpp>

struct foo
{
  foo()
  {
    zr_boost_1_81::system::error_code ec;
    BOOST_TEST_NE( ec, zr_boost_1_81::system::errc::permission_denied );
  }
} f;

int main()
{
  return zr_boost_1_81::report_errors();
}
