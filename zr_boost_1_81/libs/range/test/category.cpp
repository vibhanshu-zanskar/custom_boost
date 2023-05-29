// Boost.Range library
//
//  Copyright Neil Groves 2014. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#include <boost/range/category.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>

#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>

#include <vector>

namespace zr_boost_1_81_range_test
{
    namespace
    {

void test_category()
{
    typedef std::vector<int> cont;

    BOOST_STATIC_ASSERT((
        zr_boost_1_81::is_same<
            zr_boost_1_81::iterator_category<cont::const_iterator>::type,
            zr_boost_1_81::range_category<cont>::type
        >::value));

    BOOST_STATIC_ASSERT((
        zr_boost_1_81::is_same<
            zr_boost_1_81::iterator_category<cont::const_iterator>::type,
            zr_boost_1_81::range_category<const cont>::type
        >::value));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
    BOOST_STATIC_ASSERT((
        zr_boost_1_81::is_same<
            zr_boost_1_81::iterator_category<cont::const_iterator>::type,
            zr_boost_1_81::range_category<cont&&>::type
        >::value));
#endif
}

    } // anonymous namespace
} // namespace zr_boost_1_81_range_test

zr_boost_1_81::unit_test::test_suite* init_unit_test_suite( int argc, char* argv[] )
{
    zr_boost_1_81::unit_test::test_suite* test =
        BOOST_TEST_SUITE("Boost.Range range_category meta-function");

    test->add(BOOST_TEST_CASE(&zr_boost_1_81_range_test::test_category));

    return test;
}
