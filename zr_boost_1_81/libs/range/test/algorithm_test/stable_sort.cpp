//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#include <boost/range/algorithm/stable_sort.hpp>

#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/assign.hpp>
#include <algorithm>
#include <functional>
#include <list>
#include <numeric>
#include <deque>
#include <vector>

namespace zr_boost_1_81
{
    namespace
    {
        template<class Container>
        void test_stable_sort_impl(Container& cont)
        {
            Container reference(cont);
            Container test(cont);

            zr_boost_1_81::stable_sort(test);
            std::stable_sort(reference.begin(), reference.end());

            BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                                           test.begin(), test.end() );
                
            test = cont;
            zr_boost_1_81::stable_sort(zr_boost_1_81::make_iterator_range(test));
            BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                                           test.begin(), test.end() );
        }

        template<class Container, class BinaryPredicate>
        void test_stable_sort_impl(Container& cont, BinaryPredicate pred)
        {
            Container reference(cont);
            Container test(cont);

            zr_boost_1_81::stable_sort(test, pred);
            std::stable_sort(reference.begin(), reference.end(), pred);

            BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                                           test.begin(), test.end() );
                                           
            test = cont;
            zr_boost_1_81::stable_sort(zr_boost_1_81::make_iterator_range(test), pred);
            BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                                           test.begin(), test.end() );
        }

        template<class Container>
        void test_stable_sort_impl()
        {
            using namespace zr_boost_1_81::assign;

            Container cont;
            test_stable_sort_impl(cont);
            test_stable_sort_impl(cont, std::less<int>());
            test_stable_sort_impl(cont, std::greater<int>());

            cont.clear();
            cont += 1;
            test_stable_sort_impl(cont);
            test_stable_sort_impl(cont, std::less<int>());
            test_stable_sort_impl(cont, std::greater<int>());

            cont.clear();
            cont += 1,2,3,4,5,6,7,8,9;
            test_stable_sort_impl(cont);
            test_stable_sort_impl(cont, std::less<int>());
            test_stable_sort_impl(cont, std::greater<int>());
        }

        void test_stable_sort()
        {
            test_stable_sort_impl< std::vector<int> >();
            test_stable_sort_impl< std::deque<int> >();
        }
    }
}

zr_boost_1_81::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    zr_boost_1_81::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm.stable_sort" );

    test->add( BOOST_TEST_CASE( &zr_boost_1_81::test_stable_sort ) );

    return test;
}
