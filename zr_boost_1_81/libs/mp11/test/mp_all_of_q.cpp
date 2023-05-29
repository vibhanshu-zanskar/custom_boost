
// Copyright 2015, 2016, 2017 Peter Dimov.
//
// Distributed under the Boost Software License, Version 1.0.
//
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt


#include <boost/mp11/algorithm.hpp>
#include <boost/mp11/list.hpp>
#include <boost/mp11/integral.hpp>
#include <boost/mp11/utility.hpp>
#include <boost/core/lightweight_test_trait.hpp>
#include <type_traits>
#include <tuple>
#include <utility>

struct X1 {};

int main()
{
    using zr_boost_1_81::mp11::mp_list;
    using zr_boost_1_81::mp11::mp_all_of_q;
    using zr_boost_1_81::mp11::mp_true;
    using zr_boost_1_81::mp11::mp_false;
    using zr_boost_1_81::mp11::mp_quote;

    {
        using L1 = mp_list<>;

        BOOST_TEST_TRAIT_TRUE((std::is_same<mp_all_of_q<L1, mp_quote<std::is_const>>, mp_true>));

        using L2 = mp_list<X1 const, X1 const, X1 const volatile, X1 const, X1 const volatile>;

        BOOST_TEST_TRAIT_TRUE((std::is_same<mp_all_of_q<L2, mp_quote<std::is_volatile>>, mp_false>));
        BOOST_TEST_TRAIT_TRUE((std::is_same<mp_all_of_q<L2, mp_quote<std::is_const>>, mp_true>));
    }

    {
        using L1 = std::tuple<>;

        BOOST_TEST_TRAIT_TRUE((std::is_same<mp_all_of_q<L1, mp_quote<std::is_const>>, mp_true>));

        using L2 = std::tuple<X1 const, X1 const, X1 const volatile, X1 const, X1 const volatile>;

        BOOST_TEST_TRAIT_TRUE((std::is_same<mp_all_of_q<L2, mp_quote<std::is_volatile>>, mp_false>));
        BOOST_TEST_TRAIT_TRUE((std::is_same<mp_all_of_q<L2, mp_quote<std::is_const>>, mp_true>));
    }

    {
        using L2 = std::pair<X1 const, X1 const volatile>;

        BOOST_TEST_TRAIT_TRUE((std::is_same<mp_all_of_q<L2, mp_quote<std::is_volatile>>, mp_false>));
        BOOST_TEST_TRAIT_TRUE((std::is_same<mp_all_of_q<L2, mp_quote<std::is_const>>, mp_true>));
    }

    return zr_boost_1_81::report_errors();
}