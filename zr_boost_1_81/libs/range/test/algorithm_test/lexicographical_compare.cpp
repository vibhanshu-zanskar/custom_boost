//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#include <boost/range/algorithm/lexicographical_compare.hpp>

#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/assign.hpp>
#include <boost/range/value_type.hpp>
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
        template<class ForwardRange1, class ForwardRange2>
        void test_lexicographical_compare_impl_nopred(ForwardRange1& rng1,
                                                      ForwardRange2& rng2)
        {
            const bool reference = std::lexicographical_compare(
                zr_boost_1_81::begin(rng1), zr_boost_1_81::end(rng1),
                zr_boost_1_81::begin(rng2), zr_boost_1_81::end(rng2));

            const bool test = zr_boost_1_81::lexicographical_compare(rng1, rng2);

            BOOST_CHECK( reference == test );
            BOOST_CHECK( test == zr_boost_1_81::lexicographical_compare(zr_boost_1_81::make_iterator_range(rng1), rng2) );
            BOOST_CHECK( test == zr_boost_1_81::lexicographical_compare(rng1, zr_boost_1_81::make_iterator_range(rng2)) );
            BOOST_CHECK( test == zr_boost_1_81::lexicographical_compare(zr_boost_1_81::make_iterator_range(rng1), zr_boost_1_81::make_iterator_range(rng2)) );
        }

        template<class ForwardRange1, class ForwardRange2,
                 class BinaryPredicate>
        void test_lexicographical_compare_impl_pred(ForwardRange1& rng1,
                                                    ForwardRange2& rng2,
                                                    BinaryPredicate pred)
        {
            const bool reference = std::lexicographical_compare(
                zr_boost_1_81::begin(rng1), zr_boost_1_81::end(rng1),
                zr_boost_1_81::begin(rng2), zr_boost_1_81::end(rng2),
                pred);

            const bool test = zr_boost_1_81::lexicographical_compare(rng1, rng2, pred);

            BOOST_CHECK( reference == test );
            BOOST_CHECK( test == zr_boost_1_81::lexicographical_compare(zr_boost_1_81::make_iterator_range(rng1), rng2, pred) );
            BOOST_CHECK( test == zr_boost_1_81::lexicographical_compare(rng1, zr_boost_1_81::make_iterator_range(rng2), pred) );
            BOOST_CHECK( test == zr_boost_1_81::lexicographical_compare(zr_boost_1_81::make_iterator_range(rng1), zr_boost_1_81::make_iterator_range(rng2), pred) );
        }

        template<class Container1, class Container2>
        void test_lexicographical_compare_impl(Container1& cont1,
                                               Container2& cont2)
        {
            typedef BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_value<Container1>::type value_t;

            test_lexicographical_compare_impl_nopred(cont1, cont2);
            test_lexicographical_compare_impl_pred(cont1, cont2, std::less<value_t>());
            test_lexicographical_compare_impl_pred(cont1, cont2, std::greater<value_t>());
        }

        template<class Container1, class Container2>
        void test_lexicographical_compare_impl()
        {
            using namespace zr_boost_1_81::assign;

            typedef BOOST_DEDUCED_TYPENAME zr_boost_1_81::remove_const<Container1>::type container1_t;
            typedef BOOST_DEDUCED_TYPENAME zr_boost_1_81::remove_const<Container2>::type container2_t;

            container1_t cont1;
            container2_t cont2;
            test_lexicographical_compare_impl<Container1,Container2>(cont1, cont2);

            cont1.clear();
            cont2.clear();
            cont1.push_back(1);
            cont2.push_back(1);
            test_lexicographical_compare_impl<Container1,Container2>(cont1, cont2);

            cont1.clear();
            cont2.clear();
            cont1 += 2;
            cont2 += 1;
            test_lexicographical_compare_impl<Container1,Container2>(cont1, cont2);

            cont1.clear();
            cont2.clear();
            cont1 += 1;
            cont2 += 2;
            test_lexicographical_compare_impl<Container1,Container2>(cont1, cont2);

            cont1.clear();
            cont2.clear();
            cont1 += 1,2,3,4,5,6,7;
            cont2 += 1,2,3,4,5,6,7;
            test_lexicographical_compare_impl<Container1,Container2>(cont1, cont2);

            cont1.clear();
            cont2.clear();
            cont1 += 1,2,3,4,5,6,7;
            cont2 += 1,2,3,4,5,6;
            test_lexicographical_compare_impl<Container1,Container2>(cont1, cont2);

            cont1.clear();
            cont2.clear();
            cont1 += 1,2,3,4,5,6;
            cont2 += 1,2,3,4,5,6,7;
            test_lexicographical_compare_impl<Container1,Container2>(cont1, cont2);
        }

        template<class Container1>
        void test_lexicographical_compare_rhs()
        {
            typedef BOOST_DEDUCED_TYPENAME range_value<Container1>::type value_t;

            test_lexicographical_compare_impl<Container1, const std::vector<value_t> >();
            test_lexicographical_compare_impl<Container1, const std::deque<value_t> >();
            test_lexicographical_compare_impl<Container1, const std::list<value_t> >();
            test_lexicographical_compare_impl<Container1, std::vector<value_t> >();
            test_lexicographical_compare_impl<Container1, std::deque<value_t> >();
            test_lexicographical_compare_impl<Container1, std::list<value_t> >();
        }

        void test_lexicographical_compare()
        {
            test_lexicographical_compare_rhs< const std::vector<int> >();
            test_lexicographical_compare_rhs< const std::deque<int> >();
            test_lexicographical_compare_rhs< const std::list<int> >();
            test_lexicographical_compare_rhs< std::vector<int> >();
            test_lexicographical_compare_rhs< std::deque<int> >();
            test_lexicographical_compare_rhs< std::list<int> >();
        }
    }
}


zr_boost_1_81::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    zr_boost_1_81::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm.lexicographical_compare" );

    test->add( BOOST_TEST_CASE( &zr_boost_1_81::test_lexicographical_compare ) );

    return test;
}
