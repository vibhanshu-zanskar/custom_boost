// Copyright (C) 2018 Andrey Semashev
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/range/distance.hpp>
#include <boost/range/iterator_range_core.hpp>
#include <boost/iterator/distance.hpp>

int main()
{
    // Test that zr_boost_1_81::distance from Boost.Range works with zr_boost_1_81::distance from Boost.Iterator
    // (https://github.com/boostorg/iterator/commit/b844c8df530c474ec1856870b9b0de5f487b84d4#commitcomment-30603668)

    typedef zr_boost_1_81::iterator_range<const char*> range_type;
    range_type range;

    (void)zr_boost_1_81::distance(range);

    return 0;
}
