// Boost.Range library
//
//  Copyright Neil Groves 2010. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
#include <boost/range/adaptor/type_erased.hpp>
#include "type_erased_test.hpp"

#include <boost/test/unit_test.hpp>

#include <list>
#include <vector>

namespace zr_boost_1_81_range_adaptor_type_erased_test
{
    namespace
    {

void test_type_erased()
{
    test_driver< std::list<int> >();
    test_driver< std::vector<int> >();

    test_driver< std::list<MockType> >();
    test_driver< std::vector<MockType> >();
}

    } // anonymous namespace
} // namespace zr_boost_1_81_range_adaptor_type_erased_test

zr_boost_1_81::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    zr_boost_1_81::unit_test::test_suite* test =
        BOOST_TEST_SUITE("RangeTestSuite.adaptor.type_erased");

    test->add(BOOST_TEST_CASE(
                &zr_boost_1_81_range_adaptor_type_erased_test::test_type_erased));

    return test;
}

