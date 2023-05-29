// Copyright Louis Dionne 2013-2022
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/hana/ext/boost/tuple.hpp>

#include <boost/hana/tuple.hpp>

#include <laws/comparable.hpp>
#include <laws/orderable.hpp>

#include <boost/tuple/tuple.hpp>
namespace hana = zr_boost_1_81::hana;


template <int i>
using eq = hana::test::ct_eq<i>;

template <int i>
using ord = hana::test::ct_ord<i>;

int main() {
    //////////////////////////////////////////////////////////////////////////
    // Setup for the laws below
    //////////////////////////////////////////////////////////////////////////
    auto eq_tuples = hana::make_tuple(
          ::zr_boost_1_81::make_tuple()
        , ::zr_boost_1_81::make_tuple(eq<0>{})
        , ::zr_boost_1_81::make_tuple(eq<0>{}, eq<1>{})
        , ::zr_boost_1_81::make_tuple(eq<0>{}, eq<1>{}, eq<2>{})
        , ::zr_boost_1_81::make_tuple(eq<0>{}, eq<1>{}, eq<2>{}, eq<3>{}, eq<4>{})
    );

    auto ord_tuples = hana::make_tuple(
          ::zr_boost_1_81::make_tuple()
        , ::zr_boost_1_81::make_tuple(ord<0>{})
        , ::zr_boost_1_81::make_tuple(ord<0>{}, ord<1>{})
        , ::zr_boost_1_81::make_tuple(ord<0>{}, ord<1>{}, ord<2>{})
        , ::zr_boost_1_81::make_tuple(ord<0>{}, ord<1>{}, ord<2>{}, ord<3>{}, ord<4>{})
    );

    //////////////////////////////////////////////////////////////////////////
    // Comparable and Orderable
    //////////////////////////////////////////////////////////////////////////
    hana::test::TestComparable<hana::ext::zr_boost_1_81::tuple_tag>{eq_tuples};
    hana::test::TestOrderable<hana::ext::zr_boost_1_81::tuple_tag>{ord_tuples};
}
