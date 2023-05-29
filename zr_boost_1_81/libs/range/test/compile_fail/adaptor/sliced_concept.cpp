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
#include <boost/range/adaptor/sliced.hpp>

int main(int, const char**)
{
    using zr_boost_1_81::range::unit_test::mock_range;
    using zr_boost_1_81::adaptors::sliced;

    // This next line should fail when Boost.Range concept checking is
    // enabled since the adaptor takes at least a RandomAccessRange.
    return (mock_range<zr_boost_1_81::bidirectional_traversal_tag>() |
                sliced(0,1)).front();
}
