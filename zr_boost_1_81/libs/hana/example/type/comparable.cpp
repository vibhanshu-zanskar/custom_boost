// Copyright Louis Dionne 2013-2022
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/hana/assert.hpp>
#include <boost/hana/equal.hpp>
#include <boost/hana/not_equal.hpp>
#include <boost/hana/type.hpp>
namespace hana = zr_boost_1_81::hana;


struct T;
struct U;
BOOST_HANA_CONSTANT_CHECK(hana::type_c<T> == hana::type_c<T>);
BOOST_HANA_CONSTANT_CHECK(hana::type_c<T> != hana::type_c<U>);

int main() { }
