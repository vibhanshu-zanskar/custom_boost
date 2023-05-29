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
#include <boost/range/algorithm/find.hpp>

#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/assign.hpp>
#include "../test_driver/range_return_test_driver.hpp"
#include <algorithm>
#include <functional>
#include <list>
#include <numeric>
#include <deque>
#include <vector>

namespace zr_boost_1_81_range_test_algorithm_find
{
    class find_test_policy
    {
    public:
        template<class Container>
        BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_iterator<Container>::type
        test_iter(Container& cont)
        {
            typedef BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_iterator<Container>::type iter_t;
            iter_t result = zr_boost_1_81::find(cont, 3);
            iter_t result2 = zr_boost_1_81::find(zr_boost_1_81::make_iterator_range(cont), 3);
            BOOST_CHECK( result == result2 );
            return result;
        }

        template<zr_boost_1_81::range_return_value return_type>
        struct test_range
        {
            template<class Container, class Policy>
            BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_return<Container,return_type>::type
            operator()(Policy&, Container& cont)
            {
                typedef BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_return<Container,return_type>::type result_t;
                result_t result = zr_boost_1_81::find<return_type>(cont, 3);
                result_t result2 = zr_boost_1_81::find<return_type>(zr_boost_1_81::make_iterator_range(cont), 3);
                BOOST_CHECK( result == result2 );
                return result;
            }
        };

        template<class Container>
        BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_iterator<Container>::type
        reference(Container& cont)
        {
            return std::find(cont.begin(), cont.end(), 3);
        }
    };

    template<class Container>
    void test_find_container()
    {
        using namespace zr_boost_1_81::assign;

        typedef BOOST_DEDUCED_TYPENAME zr_boost_1_81::remove_const<Container>::type container_t;

        zr_boost_1_81::range_test::range_return_test_driver test_driver;

        container_t mcont;
        Container& cont = mcont;
        test_driver(cont, find_test_policy());

        mcont.clear();
        mcont += 1;
        test_driver(cont, find_test_policy());

        mcont.clear();
        mcont += 1,2,3,4,5,6,7,8,9;
        test_driver(cont, find_test_policy());
    }

    void test_find()
    {
        test_find_container< std::vector<int> >();
        test_find_container< std::list<int> >();
        test_find_container< std::deque<int> >();

        test_find_container< const std::vector<int> >();
        test_find_container< const std::list<int> >();
        test_find_container< const std::deque<int> >();

        std::vector<int> vi;
        const std::vector<int>& cvi = vi;
        std::vector<int>::const_iterator it = zr_boost_1_81::find(vi, 0);
        std::vector<int>::const_iterator it2 = zr_boost_1_81::find(cvi, 0);
        BOOST_CHECK( it == it2 );
    }
    
    // The find algorithm can be used like a "contains" algorithm
    // since the returned iterator_range is convertible to bool.
    // Therefore if the return value is an empty range it will
    // convert to the equivalent to "false" whereas a range that
    // is not empty will convert to "true". Therefore one can
    // use the syntax zr_boost_1_81::find<zr_boost_1_81::return_found_end>(rng, x)
    // as a contains function.
    void test_find_as_contains()
    {
        std::list<int> l;
        for (int i = 0; i < 10; ++i)
            l.push_back(i);
        
        BOOST_CHECK(zr_boost_1_81::find<zr_boost_1_81::return_found_end>(l, 3));
        BOOST_CHECK(!zr_boost_1_81::find<zr_boost_1_81::return_found_end>(l, 10));
    }
}

zr_boost_1_81::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    zr_boost_1_81::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm.find" );

    test->add( BOOST_TEST_CASE( &zr_boost_1_81_range_test_algorithm_find::test_find ) );
    test->add( BOOST_TEST_CASE( &zr_boost_1_81_range_test_algorithm_find::test_find_as_contains ) );

    return test;
}
