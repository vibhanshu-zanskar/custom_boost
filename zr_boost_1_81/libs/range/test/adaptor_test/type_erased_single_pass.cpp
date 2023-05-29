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

#include <deque>
#include <list>
#include <vector>

namespace zr_boost_1_81_range_adaptor_type_erased_test
{
    namespace
    {

void test_single_pass()
{
    test_type_erased_exercise_buffer_types<
            std::list<int>, zr_boost_1_81::single_pass_traversal_tag>();

    test_type_erased_exercise_buffer_types<
            std::deque<int>, zr_boost_1_81::single_pass_traversal_tag>();

    test_type_erased_exercise_buffer_types<
            std::vector<int>, zr_boost_1_81::single_pass_traversal_tag>();

    test_type_erased_exercise_buffer_types<
            std::list<MockType>, zr_boost_1_81::single_pass_traversal_tag>();

    test_type_erased_exercise_buffer_types<
            std::deque<MockType>, zr_boost_1_81::single_pass_traversal_tag>();

    test_type_erased_exercise_buffer_types<
            std::vector<MockType>, zr_boost_1_81::single_pass_traversal_tag>();
}

    } // anonymous namespace
} // namespace zr_boost_1_81_range_adaptor_type_erased_test

zr_boost_1_81::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    zr_boost_1_81::unit_test::test_suite* test =
        BOOST_TEST_SUITE("RangeTestSuite.adaptor.type_erased_single_pass");

    test->add(BOOST_TEST_CASE(
        &zr_boost_1_81_range_adaptor_type_erased_test::test_single_pass));

    return test;
}

