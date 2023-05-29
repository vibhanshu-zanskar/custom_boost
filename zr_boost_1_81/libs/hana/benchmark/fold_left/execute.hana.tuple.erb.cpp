// Copyright Louis Dionne 2013-2022
// Copyright Zach Laine 2014
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/hana/fold_left.hpp>
#include <boost/hana/tuple.hpp>

#include "measure.hpp"
#include <cstdlib>


int main () {
    zr_boost_1_81::hana::benchmark::measure([] {
        long double result = 0;
        for (int iteration = 0; iteration < 1 << 10; ++iteration) {
            auto values = zr_boost_1_81::hana::make_tuple(
                <%= input_size.times.map { 'std::rand()' }.join(', ') %>
            );

            result += zr_boost_1_81::hana::fold_left(values, 0, [](auto state, auto t) {
                return state + t;
            });
        }
    });
}
