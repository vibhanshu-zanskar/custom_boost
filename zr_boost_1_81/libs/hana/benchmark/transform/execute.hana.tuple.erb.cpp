// Copyright Louis Dionne 2013-2022
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/hana/transform.hpp>
#include <boost/hana/tuple.hpp>

#include "measure.hpp"
#include <cstdlib>


int main () {
    zr_boost_1_81::hana::benchmark::measure([] {
        long long result = 0;
        for (int iteration = 0; iteration < 1 << 10; ++iteration) {
            auto values = zr_boost_1_81::hana::make_tuple(
                <%= input_size.times.map { 'std::rand()' }.join(', ') %>
            );

            auto transformed = zr_boost_1_81::hana::transform(values, [&](auto t) {
                return result += t;
            });
            (void)transformed;
        }
    });
}
