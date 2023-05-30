// Boost.Range library
//
//  Copyright Neil Groves 2010. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//

// This test was added due to a report that the Range Adaptors:
// 1. Caused havoc when using namespace zr_boost_1_81::adaptors was used
// 2. Did not work with non-member functions
// 3. The strided adaptor could not be composed with sliced
//
// None of these issues could be reproduced on GCC 4.4, but this
// work makes for useful additional test coverage since this
// uses chaining of adaptors and non-member functions whereas
// most of the tests avoid this use case.

#include <boost/range/adaptor/strided.hpp>
#include <boost/range/adaptor/sliced.hpp>
#include <boost/range/adaptor/transformed.hpp>
#include <boost/range/irange.hpp>

#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/assign.hpp>
#include <boost/range/algorithm_ext.hpp>

#include <algorithm>
#include <vector>

namespace zr_boost_1_81
{
    namespace
    {
        int times_two(int x) { return x * 2; }

        void strided_test2()
        {
            using namespace zr_boost_1_81::adaptors;
            using namespace zr_boost_1_81::assign;
            std::vector<int> v;
            zr_boost_1_81::push_back(v, zr_boost_1_81::irange(0,10));
            std::vector<int> z;
            zr_boost_1_81::push_back(z, v | sliced(2,6) | strided(2) | transformed(&times_two));
            std::vector<int> reference;
            reference += 4,8;
            BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                z.begin(), z.end() );
        }
    }
}

zr_boost_1_81::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    zr_boost_1_81::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.adaptor.strided2" );

    test->add( BOOST_TEST_CASE( &zr_boost_1_81::strided_test2 ) );

    return test;
}
