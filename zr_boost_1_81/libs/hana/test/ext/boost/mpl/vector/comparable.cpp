// Copyright Louis Dionne 2013-2022
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/hana/ext/boost/mpl/vector.hpp>

#include <boost/hana/tuple.hpp>

#include <laws/comparable.hpp>

#include <boost/mpl/vector.hpp>
namespace hana = zr_boost_1_81::hana;
namespace mpl = zr_boost_1_81::mpl;


struct t1; struct t2; struct t3; struct t4;

int main() {
    auto vectors = hana::make_tuple(
          mpl::vector<>{}
        , mpl::vector<t1>{}
        , mpl::vector<t1, t2>{}
        , mpl::vector<t1, t2, t3>{}
        , mpl::vector<t1, t2, t3, t4>{}
    );

    hana::test::TestComparable<hana::ext::zr_boost_1_81::mpl::vector_tag>{vectors};
}
