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
#include <boost/range/algorithm/unique.hpp>
#include <boost/range/detail/range_return.hpp>

#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/assign.hpp>
#include <boost/config.hpp>
#include "../test_driver/range_overload_test_driver.hpp"
#include <algorithm>
#include <functional>
#include <list>
#include <numeric>
#include <deque>
#include <vector>

namespace zr_boost_1_81_range_test_algorithm_unique
{
    // test the 'unique' algorithm without a predicate
    class unique_test_policy
    {
    public:
        template< class Container >
        BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_iterator<Container>::type
        test_iter(Container& cont)
        {
            // There isn't an iterator return version of zr_boost_1_81::unique, so just
            // perform the standard algorithm
            return std::unique(cont.begin(), cont.end());
        }

        template< zr_boost_1_81::range_return_value return_type >
        struct test_range
        {
            template< class Container, class Policy >
            BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_return<Container,return_type>::type
            operator()(Policy&, Container& cont)
            {
                typedef BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_return<Container,return_type>::type result_t;

                Container cont2(cont);

                result_t result = zr_boost_1_81::unique<return_type>(cont);

                zr_boost_1_81::unique<return_type>(zr_boost_1_81::make_iterator_range(cont2));

                BOOST_CHECK_EQUAL_COLLECTIONS( cont.begin(), cont.end(),
                                               cont2.begin(), cont2.end() );

                return result;
            }
        };

        template<typename Container>
        struct test_range_overload
        {
            BOOST_STATIC_CONSTANT(
                ::zr_boost_1_81::range_return_value,
                result_type = ::zr_boost_1_81::return_begin_found);
                
            template<typename Policy>
            BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_return<
                Container, result_type
            >::type
            operator()(Policy& policy, Container& cont)
            {
                typedef BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_return<
                                Container,result_type>::type result_t;
                
                Container cont2(cont);
                
                result_t result = zr_boost_1_81::unique(cont);
                
                zr_boost_1_81::unique(zr_boost_1_81::make_iterator_range(cont2));
                
                BOOST_CHECK_EQUAL_COLLECTIONS(
                    cont.begin(), cont.end(),
                    cont2.begin(), cont2.end());
                
                return result;
            }
        };

        template< class Container >
        BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_iterator<Container>::type
        reference(Container& cont)
        {
            return std::unique(cont.begin(), cont.end());
        }
    };
   
    // test the 'unique' algorithm with a predicate
    template<class Pred>
    class unique_pred_test_policy
    {
    public:
        template< class Container >
        BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_iterator<Container>::type
        test_iter(Container& cont)
        {
            // There isn't an iterator return version of zr_boost_1_81::unique, so just
            // perform the standard algorithm
            return std::unique(cont.begin(), cont.end(), Pred());
        }

        Pred pred() const { return Pred(); }

        template< zr_boost_1_81::range_return_value return_type >
        struct test_range
        {
            template< class Container, class Policy >
            BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_return<Container,return_type>::type
            operator()(Policy& policy, Container& cont)
            {
                typedef BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_return<Container,return_type>::type result_t;

                Container cont2(cont);

                result_t result = zr_boost_1_81::unique<return_type>(cont, policy.pred());

                zr_boost_1_81::unique<return_type>(zr_boost_1_81::make_iterator_range(cont2), policy.pred());

                BOOST_CHECK_EQUAL_COLLECTIONS( cont.begin(), cont.end(),
                                               cont2.begin(), cont2.end() );

                return result;
            }
        };
        
        template<typename Container>
        struct test_range_overload
        {
            BOOST_STATIC_CONSTANT(
                ::zr_boost_1_81::range_return_value,
                result_type = ::zr_boost_1_81::return_begin_found);
                
            template<typename Policy>
            BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_return<Container,result_type>::type
            operator()(Policy& policy, Container& cont)
            {
                typedef BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_return<
                            Container,result_type>::type result_t;
                
                Container cont2(cont);
                
                result_t result = zr_boost_1_81::unique(cont, policy.pred());
                
                zr_boost_1_81::unique(zr_boost_1_81::make_iterator_range(cont2), policy.pred());
                
                BOOST_CHECK_EQUAL_COLLECTIONS(
                    cont.begin(), cont.end(),
                    cont2.begin(), cont2.end());
                    
                return result;
            }
        };

        template< class Container >
        BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_iterator<Container>::type
        reference(Container& cont)
        {
            return std::unique(cont.begin(), cont.end(), Pred());
        }
    };

    template<class Container, class TestPolicy, class Pred>
    void test_unique_impl(TestPolicy policy, Pred pred)
    {
        using namespace zr_boost_1_81::assign;

        typedef BOOST_DEDUCED_TYPENAME Container::value_type value_t;

        zr_boost_1_81::range_test::range_overload_test_driver test_driver;

        Container cont;

        test_driver(cont, policy);

        cont.clear();
        cont += 1;

        std::vector<value_t> temp(cont.begin(), cont.end());
        std::sort(temp.begin(), temp.end(), pred);
        cont.assign(temp.begin(), temp.end());

        test_driver(cont, policy);

        cont.clear();
        cont += 1,2,2,2,2,3,4,5,6,7,8,9;

        temp.assign(cont.begin(), cont.end());
        std::sort(temp.begin(), temp.end(), pred);
        cont.assign(temp.begin(), temp.end());

        test_driver(cont, policy);
    }
    
    template<typename T>
    struct equal_div_2
    {
        typedef bool result_type;
        typedef const T& first_argument_type;
        typedef const T& second_argument_type;
        
        bool operator()(const T& left, const T& right) const
        {
            return left / 2 == right / 2;
        }
    };

    template<class Container>
    void test_unique_impl()
    {
        test_unique_impl<Container>(
            unique_test_policy(),
            std::less<int>()
        );

        test_unique_impl<Container>(
            unique_pred_test_policy<std::equal_to<int> >(),
            std::less<int>()
        );

        test_unique_impl<Container>(
            unique_pred_test_policy<std::equal_to<int> >(),
            std::greater<int>()
        );
        
        test_unique_impl<Container>(
            unique_pred_test_policy<equal_div_2<int> >(),
            std::less<int>()
        );
    }

    void test_unique()
    {
        test_unique_impl< std::vector<int> >();
        test_unique_impl< std::list<int> >();
        test_unique_impl< std::deque<int> >();
    }
}

zr_boost_1_81::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    zr_boost_1_81::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm.unique" );

    test->add( BOOST_TEST_CASE( &zr_boost_1_81_range_test_algorithm_unique::test_unique ) );

    return test;
}
