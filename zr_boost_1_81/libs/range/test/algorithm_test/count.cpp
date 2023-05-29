// Boost.Range library
//
//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#include <boost/range/algorithm/count.hpp>

#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/assign.hpp>
#include <algorithm>
#include <list>
#include <set>
#include <vector>

namespace zr_boost_1_81
{
    namespace
    {
        template< class Container >
        void test_count_impl()
        {
            using namespace zr_boost_1_81::assign;

            Container cont;
            const Container& cref_cont = cont;

            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count(cont, 0u) );
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count(cref_cont, 0u) );
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count(zr_boost_1_81::make_iterator_range(cont), 0u) );

            cont += 1;
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count(cont, 0u) );
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count(cref_cont, 0u) );
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count(zr_boost_1_81::make_iterator_range(cont), 0u) );
            BOOST_CHECK_EQUAL( 1u, zr_boost_1_81::count(cont, 1u) );
            BOOST_CHECK_EQUAL( 1u, zr_boost_1_81::count(cref_cont, 1u) );
            BOOST_CHECK_EQUAL( 1u, zr_boost_1_81::count(zr_boost_1_81::make_iterator_range(cont), 1u) );

            cont += 2,3,4,5,6,7,8,9;
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count(cont, 0u) );
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count(cref_cont, 0u) );
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count(zr_boost_1_81::make_iterator_range(cont), 0u) );
            BOOST_CHECK_EQUAL( 1u, zr_boost_1_81::count(cont, 1u) );
            BOOST_CHECK_EQUAL( 1u, zr_boost_1_81::count(cref_cont, 1u) );
            BOOST_CHECK_EQUAL( 1u, zr_boost_1_81::count(zr_boost_1_81::make_iterator_range(cont), 1u) );

            cont += 2;
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count(cont, 0u) );
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count(cref_cont, 0u) );
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count(zr_boost_1_81::make_iterator_range(cont), 0u) );
            BOOST_CHECK_EQUAL( 1u, zr_boost_1_81::count(cont, 1u) );
            BOOST_CHECK_EQUAL( 1u, zr_boost_1_81::count(cref_cont, 1u) );
            BOOST_CHECK_EQUAL( 1u, zr_boost_1_81::count(zr_boost_1_81::make_iterator_range(cont), 1u) );
            BOOST_CHECK_EQUAL( 2u, zr_boost_1_81::count(cont, 2u) );
            BOOST_CHECK_EQUAL( 2u, zr_boost_1_81::count(cref_cont, 2u) );
            BOOST_CHECK_EQUAL( 2u, zr_boost_1_81::count(zr_boost_1_81::make_iterator_range(cont), 2u) );
        }

        void test_count()
        {
            test_count_impl< std::vector<int> >();
            test_count_impl< std::list<int> >();
            test_count_impl< std::multiset<int> >();
        }
    }
}


zr_boost_1_81::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    zr_boost_1_81::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm.count" );

    test->add( BOOST_TEST_CASE( &zr_boost_1_81::test_count ) );

    return test;
}
