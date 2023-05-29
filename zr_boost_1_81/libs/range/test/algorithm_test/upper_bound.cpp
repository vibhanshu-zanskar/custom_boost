//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#include <boost/range/algorithm/upper_bound.hpp>

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

namespace zr_boost_1_81_range_test_algorithm_upper_bound
{
    class upper_bound_policy
    {
    public:
        template< class Container >
        BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_iterator<Container>::type
        test_iter(Container& cont)
        {
            typedef BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_iterator<Container>::type iter_t;
            iter_t result = zr_boost_1_81::upper_bound(cont, 5);
            BOOST_CHECK( result == zr_boost_1_81::upper_bound(zr_boost_1_81::make_iterator_range(cont), 5) );
            return result;
        }

        template<zr_boost_1_81::range_return_value result_type>
        struct test_range
        {
            template<class Container, class Policy>
            BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_return<Container,result_type>::type
            operator()(Policy&, Container& cont)
            {
                typedef BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_return<Container,result_type>::type result_t;
                result_t result = zr_boost_1_81::upper_bound<result_type>(cont, 5);
                BOOST_CHECK( result == zr_boost_1_81::upper_bound<result_type>(zr_boost_1_81::make_iterator_range(cont), 5) );
                return result;
            }
        };

        template< class Container >
        BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_iterator<Container>::type
        reference(Container& cont)
        {
            return std::upper_bound(cont.begin(), cont.end(), 5);
        }
    };

    template< class BinaryPredicate >
    struct upper_bound_pred_policy
    {
        template< class Container >
        BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_iterator<Container>::type
        test_iter(Container& cont)
        {
            typedef BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_iterator<Container>::type iter_t;
            iter_t result = zr_boost_1_81::upper_bound(cont, 5, BinaryPredicate());
            BOOST_CHECK( result == zr_boost_1_81::upper_bound(zr_boost_1_81::make_iterator_range(cont), 5, BinaryPredicate()) );
            return result;
        }

        template< zr_boost_1_81::range_return_value result_type>
        struct test_range
        {
            template< class Container, class Policy >
            BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_return<Container,result_type>::type
            operator()(Policy& policy, Container& cont)
            {
                typedef BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_return<Container,result_type>::type result_t;

                result_t result = zr_boost_1_81::upper_bound<result_type>(cont, 5, policy.pred());

                BOOST_CHECK( result == zr_boost_1_81::upper_bound<result_type>(
                    zr_boost_1_81::make_iterator_range(cont), 5, policy.pred()) );

                return result;
            }
        };

        template<class Container>
        BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_iterator<Container>::type
        reference(Container& cont)
        {
            return std::upper_bound(
                    cont.begin(), cont.end(), 5, BinaryPredicate());
        }

        BinaryPredicate& pred() { return m_pred; }

    private:
        BinaryPredicate m_pred;
    };

    template<class Container,
             class TestPolicy,
             class BinaryPredicate>
    void test_upper_bound_impl(TestPolicy policy, BinaryPredicate pred)
    {
        using namespace zr_boost_1_81::assign;

        typedef BOOST_DEDUCED_TYPENAME zr_boost_1_81::remove_const<Container>::type container_t;
        typedef BOOST_DEDUCED_TYPENAME Container::value_type value_t;

        zr_boost_1_81::range_test::range_return_test_driver test_driver;

        container_t mcont;
        Container& cont = mcont;

        test_driver(cont, policy);

        mcont.clear();
        mcont += 1;

        std::vector<value_t> temp(mcont.begin(), mcont.end());
        std::sort(temp.begin(), temp.end(), pred);
        mcont.assign(temp.begin(), temp.end());

        test_driver(cont, policy);

        mcont.clear();
        mcont += 1,2,3,4,5,6,7,8,9;

        temp.assign(mcont.begin(), mcont.end());
        std::sort(temp.begin(), temp.end(), pred);
        mcont.assign(temp.begin(), temp.end());

        test_driver(cont, policy);
    }

    template<class Container>
    void test_upper_bound_impl()
    {
        test_upper_bound_impl<Container>(
            upper_bound_policy(),
            std::less<int>()
            );

        test_upper_bound_impl<Container>(
            upper_bound_pred_policy<std::less<int> >(),
            std::less<int>()
            );

        test_upper_bound_impl<Container>(
            upper_bound_pred_policy<std::greater<int> >(),
            std::greater<int>()
            );
    }

    void test_upper_bound()
    {
        test_upper_bound_impl< std::vector<int> >();
        test_upper_bound_impl< std::list<int> >();
        test_upper_bound_impl< std::deque<int> >();

        test_upper_bound_impl< const std::vector<int> >();
        test_upper_bound_impl< const std::list<int> >();
        test_upper_bound_impl< const std::deque<int> >();
    }
}

zr_boost_1_81::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    zr_boost_1_81::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm.upper_bound" );

    test->add( BOOST_TEST_CASE( &zr_boost_1_81_range_test_algorithm_upper_bound::test_upper_bound ) );

    return test;
}