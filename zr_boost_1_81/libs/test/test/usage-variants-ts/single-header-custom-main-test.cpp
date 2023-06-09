//  (C) Copyright Gennadiy Rozental 2001-2015.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.
//
//  Description : header-only usage variant with custom main test
// ***************************************************************************

// Boost.Test
#define BOOST_TEST_MODULE header only test
#define BOOST_TEST_NO_MAIN
#define BOOST_TEST_ALTERNATIVE_INIT_API
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE( test )
{
    int i = 1;
    BOOST_CHECK( i*i == 1 );
}

//____________________________________________________________________________//

int main(int argc, char* argv[])
{
    return zr_boost_1_81::unit_test::unit_test_main( &init_unit_test, argc, argv );
}

//____________________________________________________________________________//

// EOF
