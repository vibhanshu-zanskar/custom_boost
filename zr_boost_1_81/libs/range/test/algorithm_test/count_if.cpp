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
#include <boost/range/algorithm/count_if.hpp>

#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/assign.hpp>
#include "../test_function/false_predicate.hpp"
#include "../test_function/true_predicate.hpp"
#include "../test_function/equal_to_x.hpp"
#include <algorithm>
#include <list>
#include <set>
#include <vector>

namespace zr_boost_1_81
{
    namespace
    {
        template< class Container >
        void test_count_if_impl()
        {
            using namespace zr_boost_1_81::range_test_function;
            using namespace zr_boost_1_81::assign;

            typedef equal_to_x<int> pred_t;
            typedef BOOST_DEDUCED_TYPENAME std::iterator_traits<BOOST_DEDUCED_TYPENAME Container::iterator>::difference_type diff_t;

            Container cont;
            const Container& cref_cont = cont;

            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count_if(cont, pred_t(0)) );
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count_if(cref_cont, pred_t(0)) );
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count_if(zr_boost_1_81::make_iterator_range(cont), pred_t(0)) );

            cont += 1;
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count_if(cont, pred_t(0)) );
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count_if(cref_cont, pred_t(0)) );
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count_if(zr_boost_1_81::make_iterator_range(cont), pred_t(0)) );
            BOOST_CHECK_EQUAL( 1u, zr_boost_1_81::count_if(cont, pred_t(1)) );
            BOOST_CHECK_EQUAL( 1u, zr_boost_1_81::count_if(cref_cont, pred_t(1)) );
            BOOST_CHECK_EQUAL( 1u, zr_boost_1_81::count_if(zr_boost_1_81::make_iterator_range(cont), pred_t(1)) );

            cont += 2,3,4,5,6,7,8,9;
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count_if(cont, pred_t(0)) );
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count_if(cref_cont, pred_t(0)) );
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count_if(zr_boost_1_81::make_iterator_range(cont), pred_t(0)) );
            BOOST_CHECK_EQUAL( 1u, zr_boost_1_81::count_if(cont, pred_t(1)) );
            BOOST_CHECK_EQUAL( 1u, zr_boost_1_81::count_if(cref_cont, pred_t(1)) );
            BOOST_CHECK_EQUAL( 1u, zr_boost_1_81::count_if(zr_boost_1_81::make_iterator_range(cont), pred_t(1)) );

            cont += 2;
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count_if(cont, pred_t(0)) );
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count_if(cref_cont, pred_t(0)) );
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count_if(zr_boost_1_81::make_iterator_range(cont), pred_t(0)) );
            BOOST_CHECK_EQUAL( 1u, zr_boost_1_81::count_if(cont, pred_t(1)) );
            BOOST_CHECK_EQUAL( 1u, zr_boost_1_81::count_if(cref_cont, pred_t(1)) );
            BOOST_CHECK_EQUAL( 1u, zr_boost_1_81::count_if(zr_boost_1_81::make_iterator_range(cont), pred_t(1)) );
            BOOST_CHECK_EQUAL( 2u, zr_boost_1_81::count_if(cont, pred_t(2)) );
            BOOST_CHECK_EQUAL( 2u, zr_boost_1_81::count_if(cref_cont, pred_t(2)) );
            BOOST_CHECK_EQUAL( 2u, zr_boost_1_81::count_if(zr_boost_1_81::make_iterator_range(cont), pred_t(2)) );

            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count_if(cont, false_predicate()) );
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count_if(cref_cont, false_predicate()) );
            BOOST_CHECK_EQUAL( 0u, zr_boost_1_81::count_if(zr_boost_1_81::make_iterator_range(cont), false_predicate()) );

            BOOST_CHECK_EQUAL( static_cast<diff_t>(cont.size()), zr_boost_1_81::count_if(cont, true_predicate()) );
            BOOST_CHECK_EQUAL( static_cast<diff_t>(cont.size()), zr_boost_1_81::count_if(cref_cont, true_predicate()) );
            BOOST_CHECK_EQUAL( static_cast<diff_t>(cont.size()), zr_boost_1_81::count_if(zr_boost_1_81::make_iterator_range(cont), true_predicate()) );
        }

        void test_count_if()
        {
            test_count_if_impl< std::vector<int> >();
            test_count_if_impl< std::list<int> >();
            test_count_if_impl< std::multiset<int> >();
        }
    }
}


zr_boost_1_81::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    zr_boost_1_81::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm.count_if" );

    test->add( BOOST_TEST_CASE( &zr_boost_1_81::test_count_if ) );

    return test;
}
