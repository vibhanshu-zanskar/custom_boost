// Boost.Range library
//
//  Copyright Neil Groves 2014. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
#include <boost/range/adaptor/type_erased.hpp>
#include "type_erased_test.hpp"

#include <boost/test/unit_test.hpp>

#include <vector>

namespace zr_boost_1_81_range_adaptor_type_erased_test
{
    namespace
    {

void test_operator_brackets()
{
    typedef zr_boost_1_81::adaptors::type_erased<> type_erased_t;

    std::vector<int> c;
    for (int i = 0; i < 10; ++i)
        c.push_back(i);

    typedef zr_boost_1_81::any_range_type_generator<
                        std::vector<int> >::type any_range_type;

    BOOST_STATIC_ASSERT((
            zr_boost_1_81::is_same<
                int,
                zr_boost_1_81::range_value<any_range_type>::type
            >::value
    ));

    BOOST_STATIC_ASSERT((
            zr_boost_1_81::is_same<
                zr_boost_1_81::random_access_traversal_tag,
                zr_boost_1_81::iterator_traversal<
                    zr_boost_1_81::range_iterator<any_range_type>::type
                >::type
            >::value
    ));

    any_range_type rng = c | type_erased_t();

    for (int i = 0; i < 10; ++i)
    {
        BOOST_CHECK_EQUAL(rng[i], i);
    }
}

    } // anonymous namespace
} // namespace zr_boost_1_81_range_adaptor_type_erased_test

zr_boost_1_81::unit_test::test_suite*
init_unit_test_suite(int, char*[])
{
    zr_boost_1_81::unit_test::test_suite* test
        = BOOST_TEST_SUITE("RangeTestSuite.adaptor.type_erased_brackets");

    test->add(
        BOOST_TEST_CASE(
            &zr_boost_1_81_range_adaptor_type_erased_test::test_operator_brackets));

    return test;
}

