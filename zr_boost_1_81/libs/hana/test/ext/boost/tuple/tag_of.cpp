// Copyright Louis Dionne 2013-2022
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/hana/core/tag_of.hpp>
#include <boost/hana/ext/boost/tuple.hpp>

#include <boost/tuple/tuple.hpp>

#include <type_traits>
namespace hana = zr_boost_1_81::hana;


int main() {
    //////////////////////////////////////////////////////////////////////////
    // make sure the tag is correct
    //////////////////////////////////////////////////////////////////////////
    {
        auto make_cons = [](auto x, auto xs) {
            return zr_boost_1_81::tuples::cons<decltype(x), decltype(xs)>{x, xs};
        };

        static_assert(std::is_same<
            hana::tag_of_t<decltype(zr_boost_1_81::make_tuple())>,
            hana::ext::zr_boost_1_81::tuple_tag
        >::value, "");

        static_assert(std::is_same<
            hana::tag_of_t<decltype(zr_boost_1_81::make_tuple(1))>,
            hana::ext::zr_boost_1_81::tuple_tag
        >::value, "");

        static_assert(std::is_same<
            hana::tag_of_t<decltype(zr_boost_1_81::make_tuple(1, '2'))>,
            hana::ext::zr_boost_1_81::tuple_tag
        >::value, "");

        static_assert(std::is_same<
            hana::tag_of_t<decltype(zr_boost_1_81::make_tuple(1, '2', 3.3))>,
            hana::ext::zr_boost_1_81::tuple_tag
        >::value, "");

        static_assert(std::is_same<
            hana::tag_of_t<decltype(make_cons(1, zr_boost_1_81::tuples::null_type{}))>,
            hana::ext::zr_boost_1_81::tuple_tag
        >::value, "");

        static_assert(std::is_same<
            hana::tag_of_t<decltype(make_cons(1, make_cons('2', zr_boost_1_81::tuples::null_type{})))>,
            hana::ext::zr_boost_1_81::tuple_tag
        >::value, "");

        static_assert(std::is_same<
            hana::tag_of_t<decltype(make_cons(1, zr_boost_1_81::make_tuple('2', 3.3)))>,
            hana::ext::zr_boost_1_81::tuple_tag
        >::value, "");

        static_assert(std::is_same<
            hana::tag_of_t<zr_boost_1_81::tuples::null_type>,
            hana::ext::zr_boost_1_81::tuple_tag
        >::value, "");
    }
}
