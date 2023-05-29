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
#include <boost/range/adaptor/tokenized.hpp>

#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/range/algorithm_ext/push_back.hpp>

#include <algorithm>
#include <string>
#include <vector>

namespace zr_boost_1_81
{
    namespace
    {
        template< class Iterator, class Container >
        void tokenized_test_impl( Container& c, std::size_t expected_result )
        {
            using namespace zr_boost_1_81::adaptors;

            std::vector< zr_boost_1_81::sub_match< Iterator > > test_result1;
            zr_boost_1_81::push_back(test_result1, c | tokenized(zr_boost_1_81::regex("\\b")));

            BOOST_CHECK_EQUAL( test_result1.size(), expected_result );

//            std::vector< zr_boost_1_81::sub_match< Iterator > > test_result2;
//            zr_boost_1_81::push_back(test_result2, adaptors::tokenize(c, zr_boost_1_81::regex("\\b")));

//            BOOST_CHECK_EQUAL( test_result2.size(), expected_result );
        }

        template< class Container1, class Container2 >
        void tokenized_test_impl()
        {
            Container1 c;
            Container2& r = c;

            typedef typename zr_boost_1_81::range_iterator<Container2>::type It;

            // Test empty
            tokenized_test_impl<It, Container2>(r, 0u);

            // Test one element
            c = "a";
            tokenized_test_impl<It, Container2>(r, 2u);

            // Test many elements
            c = "a b c d e f g hijlmnopqrstuvwxyz";
            tokenized_test_impl<It, Container2>(r, 16u);
        }

        void tokenized_test()
        {
//            tokenized_test_impl<std::string, const std::string>();
            tokenized_test_impl<std::string, std::string>();
        }
    }
}

zr_boost_1_81::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    zr_boost_1_81::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.adaptor.tokenized" );

    test->add( BOOST_TEST_CASE( &zr_boost_1_81::tokenized_test ) );

    return test;
}
