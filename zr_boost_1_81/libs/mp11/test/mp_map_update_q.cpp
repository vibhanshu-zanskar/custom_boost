
// Copyright 2016, 2017 Peter Dimov.
//
// Distributed under the Boost Software License, Version 1.0.
//
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt


#include <boost/mp11/map.hpp>
#include <boost/mp11/list.hpp>
#include <boost/mp11/integral.hpp>
#include <boost/core/lightweight_test_trait.hpp>
#include <type_traits>
#include <tuple>
#include <utility>

using zr_boost_1_81::mp11::mp_int;

struct Q_inc
{
    template<class T, class U> using fn = mp_int<U::value + 1>;
};

int main()
{
    using zr_boost_1_81::mp11::mp_map_update_q;
    using zr_boost_1_81::mp11::mp_list;

    using M1 = mp_list<>;

    using M2 = mp_map_update_q<M1, std::pair<char, mp_int<0>>, Q_inc>;
    BOOST_TEST_TRAIT_TRUE((std::is_same<M2, mp_list<std::pair<char, mp_int<0>>>>));

    using M3 = mp_map_update_q<M2, std::pair<char, mp_int<0>>, Q_inc>;
    BOOST_TEST_TRAIT_TRUE((std::is_same<M3, mp_list<std::pair<char, mp_int<1>>>>));

    using M4 = mp_map_update_q<M3, std::pair<int, mp_int<0>>, Q_inc>;
    BOOST_TEST_TRAIT_TRUE((std::is_same<M4, mp_list<std::pair<char, mp_int<1>>, std::pair<int, mp_int<0>>>>));

    using M5 = mp_map_update_q<M4, std::pair<long, mp_int<0>>, Q_inc>;
    BOOST_TEST_TRAIT_TRUE((std::is_same<M5, mp_list<std::pair<char, mp_int<1>>, std::pair<int, mp_int<0>>, std::pair<long, mp_int<0>>>>));

    using M6 = mp_map_update_q<M5, std::pair<long, mp_int<0>>, Q_inc>;
    BOOST_TEST_TRAIT_TRUE((std::is_same<M6, mp_list<std::pair<char, mp_int<1>>, std::pair<int, mp_int<0>>, std::pair<long, mp_int<1>>>>));

    using M7 = mp_map_update_q<M6, std::pair<char, mp_int<0>>, Q_inc>;
    BOOST_TEST_TRAIT_TRUE((std::is_same<M7, mp_list<std::pair<char, mp_int<2>>, std::pair<int, mp_int<0>>, std::pair<long, mp_int<1>>>>));

    return zr_boost_1_81::report_errors();
}
