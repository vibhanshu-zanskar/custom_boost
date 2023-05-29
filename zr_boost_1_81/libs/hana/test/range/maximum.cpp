// Copyright Louis Dionne 2013-2022
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/hana/assert.hpp>
#include <boost/hana/core/make.hpp>
#include <boost/hana/equal.hpp>
#include <boost/hana/integral_constant.hpp>
#include <boost/hana/maximum.hpp>
#include <boost/hana/range.hpp>
namespace hana = zr_boost_1_81::hana;


int main() {
    BOOST_HANA_CONSTANT_CHECK(hana::equal(
        hana::maximum(hana::make_range(hana::int_c<3>, hana::int_c<4>)),
        hana::int_c<3>
    ));
    BOOST_HANA_CONSTANT_CHECK(hana::equal(
        hana::maximum(hana::make_range(hana::int_c<3>, hana::int_c<5>)),
        hana::int_c<4>
    ));
    BOOST_HANA_CONSTANT_CHECK(hana::equal(
        hana::maximum(hana::make_range(hana::int_c<-1>, hana::int_c<6>)),
        hana::int_c<5>
    ));
}
