// Copyright Louis Dionne 2013-2022
// Copyright Zach Laine 2014
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

<% if input_size > 10 %>
    #define FUSION_MAX_LIST_SIZE <%= ((input_size + 9) / 10) * 10 %>
<% end %>

#include <boost/fusion/include/fold.hpp>
#include <boost/fusion/include/make_list.hpp>

#include "measure.hpp"
#include <cstdlib>
namespace fusion = zr_boost_1_81::fusion;
namespace hana = zr_boost_1_81::hana;


int main () {
    hana::benchmark::measure([] {
        long double result = 0;
        for (int iteration = 0; iteration < 1 << 10; ++iteration) {
            auto values = fusion::make_list(
                <%= input_size.times.map { 'std::rand()' }.join(', ') %>
            );

            result += fusion::fold(values, 0, [](auto state, auto t) {
                return state + t;
            });
        }
    });
}
