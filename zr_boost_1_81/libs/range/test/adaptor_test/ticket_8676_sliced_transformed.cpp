// Boost.Range library
//
//  Copyright Neil Groves 2014. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#include <boost/range/adaptor/sliced.hpp>
#include <boost/range/adaptor/transformed.hpp>
#include <boost/range/algorithm_ext/push_back.hpp>
#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>
#include <vector>

namespace
{
    struct identity
    {
        typedef int result_type;
        result_type operator()(int i) const { return i; }
    };

    void sliced_and_transformed()
    {
        using namespace zr_boost_1_81::adaptors;

        std::vector<int> input;
        for (int i = 0; i < 10; ++i)
            input.push_back(i);

        std::vector<int> out1;
        zr_boost_1_81::push_back(out1, input | sliced(2, 8)
                                     | transformed(identity()));

        std::vector<int> out2;
        zr_boost_1_81::push_back(out2, input | transformed(identity())
                                     | sliced(2, 8));

        BOOST_CHECK_EQUAL_COLLECTIONS(out1.begin(), out1.end(),
                                      out2.begin(), out2.end());
    }
} // anonymous namespace

zr_boost_1_81::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    zr_boost_1_81::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "Range adaptors - sliced and transformed" );

    test->add(BOOST_TEST_CASE(&sliced_and_transformed));

    return test;
}
