// Copyright Louis Dionne 2013-2022
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/hana/ext/boost/tuple.hpp>

#include <boost/hana/tuple.hpp>

#include <laws/applicative.hpp>
#include <laws/base.hpp>
#include <laws/functor.hpp>
#include <laws/monad.hpp>

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
    );

    auto eq_values = hana::make_tuple(eq<0>{}, eq<2>{});

    auto eq_tuples_tuples = hana::make_tuple(
          ::zr_boost_1_81::make_tuple()
        , ::zr_boost_1_81::make_tuple(
            ::zr_boost_1_81::make_tuple(eq<0>{}))
        , ::zr_boost_1_81::make_tuple(
            ::zr_boost_1_81::make_tuple(eq<0>{}),
            ::zr_boost_1_81::make_tuple(eq<1>{}, eq<2>{}))
        , ::zr_boost_1_81::make_tuple(
            ::zr_boost_1_81::make_tuple(eq<0>{}),
            ::zr_boost_1_81::make_tuple(eq<1>{}, eq<2>{}),
            ::zr_boost_1_81::make_tuple(eq<3>{}, eq<4>{}))
    );

    //////////////////////////////////////////////////////////////////////////
    // Functor up to Monad
    //////////////////////////////////////////////////////////////////////////
    hana::test::TestFunctor<hana::ext::zr_boost_1_81::tuple_tag>{eq_tuples, eq_values};
    hana::test::TestApplicative<hana::ext::zr_boost_1_81::tuple_tag>{eq_tuples};
    hana::test::TestMonad<hana::ext::zr_boost_1_81::tuple_tag>{eq_tuples, eq_tuples_tuples};
}
