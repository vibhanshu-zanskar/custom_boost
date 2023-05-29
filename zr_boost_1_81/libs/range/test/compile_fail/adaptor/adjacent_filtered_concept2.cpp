// Boost.Range library
//
// Copyright Neil Groves 2014. Use, modification and distribution is subject
// to the Boost Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range
//

#include "mock_range.hpp"
#include <boost/range/adaptor/adjacent_filtered.hpp>

namespace
{

struct always_true
{
    typedef bool result_type;

    bool operator()(int, int) const
    {
        return true;
    }
};

} // anonymous namespace

int main(int, const char**)
{
    using zr_boost_1_81::range::unit_test::mock_const_range;
    using zr_boost_1_81::adaptors::adjacent_filtered;

    // This next line should fail when Boost.Range concept checking is
    // enabled since the adjacent_filtered adaptor takes at least a
    // ForwardRange.
    return (mock_const_range<zr_boost_1_81::single_pass_traversal_tag>() |
                adjacent_filtered(always_true())).front();
}
