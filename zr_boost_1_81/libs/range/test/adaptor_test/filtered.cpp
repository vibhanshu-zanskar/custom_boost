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
#include <boost/range/adaptor/filtered.hpp>

#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/assign.hpp>
#include <boost/range/algorithm_ext.hpp>

#include <algorithm>
#include <list>
#include <set>
#include <string>
#include <vector>
#include <sstream>

namespace zr_boost_1_81
{
    namespace
    {
        struct always_false_pred
        {
            template< class T1 >
            bool operator()(T1) const { return false; }
        };

        struct always_true_pred
        {
            template< class T1 >
            bool operator()(T1) const { return true; }
        };

        struct is_even
        {
            template< class IntegerT >
            bool operator()( IntegerT x ) const { return x % 2 == 0; }
        };

        struct is_odd
        {
            template< class IntegerT >
            bool operator()( IntegerT x ) const { return x % 2 != 0; }
        };

        struct lambda_init
        {
        };

        struct lambda
        {
            lambda(const lambda_init& init) {}
            lambda(const lambda& rhs) {}

            template< class T1 >
            bool operator()(T1) const { return false; }

        private:
            lambda() {}
            lambda& operator=(const lambda& rhs) { return *this; }
        };

        template< class Container, class Pred >
        void filtered_test_impl( Container& c, Pred pred )
        {
            using namespace zr_boost_1_81::adaptors;

            typedef BOOST_DEDUCED_TYPENAME Container::value_type value_t;

            // This is my preferred syntax using the | operator.
            std::vector< value_t > test_result1;
            zr_boost_1_81::push_back(test_result1, c | filtered(pred));

            // This is an alternative syntax preferred by some.
            std::vector< value_t > test_result2;
            zr_boost_1_81::push_back(test_result2, adaptors::filter(c, pred));

            // Calculate the reference result.
            std::vector< value_t > reference_result;
            typedef BOOST_DEDUCED_TYPENAME Container::const_iterator iter_t;
            for (iter_t it = c.begin(); it != c.end(); ++it)
            {
                if (pred(*it))
                    reference_result.push_back(*it);
            }

            BOOST_CHECK_EQUAL_COLLECTIONS( reference_result.begin(),
                                           reference_result.end(),
                                           test_result1.begin(),
                                           test_result1.end() );

            BOOST_CHECK_EQUAL_COLLECTIONS( reference_result.begin(),
                                           reference_result.end(),
                                           test_result2.begin(),
                                           test_result2.end() );
        }

        template< class Rng >
        void check_copy_assign(Rng r)
        {
            Rng r2 = r;
            r2 = r;
        }

        template< class Container, class Pred >
        void filtered_range_copy_assign(Container& c, Pred pred)
        {
            using namespace zr_boost_1_81::adaptors;
            check_copy_assign(c | filtered(pred));
            check_copy_assign(adaptors::filter(c, pred));
        }

        template< class Container, class Pred, class PredInit >
        void filtered_test_impl()
        {
            using namespace zr_boost_1_81::assign;

            Container c;
            PredInit init;
            Pred pred(init);

            // test empty container
            filtered_test_impl(c, pred);

            // test one element
            c += 1;
            filtered_test_impl(c, pred);

            // test many elements
            c += 1,2,2,2,3,4,4,4,4,5,6,7,8,9,9;
            filtered_test_impl(c, pred);

            // test the range and iterator are copy assignable
            filtered_range_copy_assign(c, pred);
        }

        template< class Container >
        void filtered_test_all_predicates()
        {
            filtered_test_impl< Container, always_false_pred, always_false_pred >();
            filtered_test_impl< Container, always_true_pred, always_true_pred >();
            filtered_test_impl< Container, is_odd, is_odd >();
            filtered_test_impl< Container, is_even, is_even >();
            filtered_test_impl< Container, lambda, lambda_init >();
        }

        void ticket_10988_single_pass()
        {
            std::vector<int> v;
            std::string str("0 1 2 3 4 5");
            std::istringstream in(str);

            zr_boost_1_81::push_back(v,
                zr_boost_1_81::make_iterator_range(
                    std::istream_iterator<int>(in),
                    std::istream_iterator<int>())
                | zr_boost_1_81::adaptors::filtered(is_even()));

            std::vector<int> reference;
            for (int i = 0; i < 6; i += 2)
            {
                reference.push_back(i);
            }
            BOOST_CHECK_EQUAL_COLLECTIONS(
                reference.begin(), reference.end(),
                v.begin(), v.end());
        }

        void filtered_test()
        {
            filtered_test_all_predicates< std::vector< int > >();
            filtered_test_all_predicates< std::list< int > >();
            filtered_test_all_predicates< std::set< int > >();
            filtered_test_all_predicates< std::multiset< int > >();
            ticket_10988_single_pass();
        }
    }
}

zr_boost_1_81::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    zr_boost_1_81::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.adaptor.filtered" );

    test->add( BOOST_TEST_CASE( &zr_boost_1_81::filtered_test ) );

    return test;
}
