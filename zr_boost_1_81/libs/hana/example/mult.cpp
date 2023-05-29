// Copyright Louis Dionne 2013-2022
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/hana/assert.hpp>
#include <boost/hana/equal.hpp>
#include <boost/hana/integral_constant.hpp>
#include <boost/hana/mult.hpp>
namespace hana = zr_boost_1_81::hana;


BOOST_HANA_CONSTANT_CHECK(hana::mult(hana::int_c<3>, hana::int_c<5>) == hana::int_c<15>);
static_assert(hana::mult(4, 2) == 8, "");

int main() { }
