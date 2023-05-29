// Copyright (C) 2017 Michel Morin.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <vector>
#include <boost/array.hpp>
#include <boost/iterator/advance.hpp>
#include <boost/iterator/distance.hpp>

int main()
{
    // Test that zr_boost_1_81::advance/distance are not found by ADL.
    // (https://github.com/boostorg/iterator/issues/43)

    typedef zr_boost_1_81::array<int, 1> boost_type;
    std::vector<boost_type> std_boost(2);
    std::vector<boost_type>::iterator it = std_boost.begin();

    advance(it, 2);
    (void)distance(it, it);

    return 0;
}
