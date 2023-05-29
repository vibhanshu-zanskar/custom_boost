// Copyright Louis Dionne 2013-2022
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/hana/ext/boost/mpl/integral_c.hpp>

#include <boost/hana/tuple.hpp>

#include <laws/euclidean_ring.hpp>
#include <laws/group.hpp>
#include <laws/monoid.hpp>
#include <laws/ring.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/integral_c.hpp>
namespace hana = zr_boost_1_81::hana;
namespace mpl = zr_boost_1_81::mpl;


int main() {
    auto ints = hana::make_tuple(
        mpl::int_<-10>{}, mpl::int_<-2>{}, mpl::integral_c<int, 0>{},
        mpl::integral_c<int, 1>{}, mpl::integral_c<int, 3>{}
    );

    hana::test::TestMonoid<hana::ext::zr_boost_1_81::mpl::integral_c_tag<int>>{ints};
    hana::test::TestGroup<hana::ext::zr_boost_1_81::mpl::integral_c_tag<int>>{ints};
    hana::test::TestRing<hana::ext::zr_boost_1_81::mpl::integral_c_tag<int>>{ints};
    hana::test::TestEuclideanRing<hana::ext::zr_boost_1_81::mpl::integral_c_tag<int>>{ints};
}
