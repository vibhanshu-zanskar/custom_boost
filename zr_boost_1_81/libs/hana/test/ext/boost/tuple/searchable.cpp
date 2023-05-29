// Copyright Louis Dionne 2013-2022
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/hana/ext/boost/tuple.hpp>

#include <boost/hana/bool.hpp>
#include <boost/hana/tuple.hpp>

#include <laws/base.hpp>
#include <laws/searchable.hpp>

#include <boost/tuple/tuple.hpp>
namespace hana = zr_boost_1_81::hana;


template <int i>
using eq = hana::test::ct_eq<i>;

int main() {
    //////////////////////////////////////////////////////////////////////////
    // Setup for the laws below
    //////////////////////////////////////////////////////////////////////////
    auto eq_tuples = hana::make_tuple(
          ::zr_boost_1_81::make_tuple()
        , ::zr_boost_1_81::make_tuple(eq<0>{})
        , ::zr_boost_1_81::make_tuple(eq<0>{}, eq<1>{})
        , ::zr_boost_1_81::make_tuple(eq<0>{}, eq<1>{}, eq<2>{})
    );

    auto eq_tuple_keys = hana::make_tuple(
        eq<3>{}, eq<5>{}, eq<7>{}
    );

    //////////////////////////////////////////////////////////////////////////
    // Searchable
    //////////////////////////////////////////////////////////////////////////
    {
        hana::test::TestSearchable<hana::ext::zr_boost_1_81::tuple_tag>{eq_tuples, eq_tuple_keys};

        auto bools = hana::make_tuple(
              ::zr_boost_1_81::make_tuple(hana::true_c)
            , ::zr_boost_1_81::make_tuple(hana::false_c)
            , ::zr_boost_1_81::make_tuple(hana::true_c, hana::true_c)
            , ::zr_boost_1_81::make_tuple(hana::true_c, hana::false_c)
            , ::zr_boost_1_81::make_tuple(hana::false_c, hana::true_c)
            , ::zr_boost_1_81::make_tuple(hana::false_c, hana::false_c)
        );
        hana::test::TestSearchable<hana::ext::zr_boost_1_81::tuple_tag>{
            bools,
            hana::make_tuple(hana::true_c, hana::false_c)
        };
    }
}
