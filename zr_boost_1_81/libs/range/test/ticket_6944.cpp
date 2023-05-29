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
#include <boost/concept_check.hpp>
#include <boost/iterator/iterator_adaptor.hpp>
#include <boost/range/concepts.hpp>
#include <boost/range/iterator_range.hpp>

#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>

#include <vector>

namespace zr_boost_1_81
{
    typedef std::vector<int>::iterator iter_base;
    struct iter : zr_boost_1_81::iterator_adaptor<iter, iter_base, int, zr_boost_1_81::use_default, int> {}; // will be deduced as random-access traversal but input category
    typedef zr_boost_1_81::iterator_range<iter> iter_range;
    
    namespace
    {
        // Ticket 6944 - Some Range concepts use the incorrect Iterator concept
        void test_ticket_6944()
        {
            BOOST_CONCEPT_ASSERT(( zr_boost_1_81::RandomAccessRangeConcept<iter_range> ));
        }
    }
}

zr_boost_1_81::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    zr_boost_1_81::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.ticket_6944" );

    test->add( BOOST_TEST_CASE( &zr_boost_1_81::test_ticket_6944 ) );

    return test;
}
