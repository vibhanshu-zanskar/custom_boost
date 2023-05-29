// Copyright Louis Dionne 2013-2022
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/hana/functional/id.hpp>
namespace hana = zr_boost_1_81::hana;


static_assert(hana::id(1) == 1, "");
static_assert(hana::id('x') == 'x', "");

int main() { }
