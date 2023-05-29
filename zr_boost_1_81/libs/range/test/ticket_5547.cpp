// Boost.Range library
//
//  Copyright Neil Groves 2011. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#include <boost/algorithm/string/join.hpp>
#include <boost/range/join.hpp>

#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>

#include <vector>

namespace zr_boost_1_81
{
    namespace
    {
   
        // Ticket 5547 - zr_boost_1_81::join ambiguous with algorithm::join
        void test_ticket_5547()
        {
            std::vector<int> x;
            zr_boost_1_81::range::join(x,x);
        }
    }
}

zr_boost_1_81::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    zr_boost_1_81::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.ticket_5547" );

    test->add( BOOST_TEST_CASE( &zr_boost_1_81::test_ticket_5547 ) );

    return test;
}
