
// Copyright 2019 Peter Dimov.
//
// Distributed under the Boost Software License, Version 1.0.
//
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt


#include <boost/mp11/list.hpp>
#include <boost/mp11/utility.hpp>
#include <boost/core/lightweight_test_trait.hpp>

int main()
{
    using zr_boost_1_81::mp11::mp_append;
    using zr_boost_1_81::mp11::mp_valid;
    using zr_boost_1_81::mp11::mp_list;

    BOOST_TEST_TRAIT_FALSE((mp_valid<mp_append, void>));
    BOOST_TEST_TRAIT_FALSE((mp_valid<mp_append, void, void>));
    BOOST_TEST_TRAIT_FALSE((mp_valid<mp_append, void, void, void>));
    BOOST_TEST_TRAIT_FALSE((mp_valid<mp_append, void, void, void, void>));
    BOOST_TEST_TRAIT_FALSE((mp_valid<mp_append, void, void, void, void, void>));

    BOOST_TEST_TRAIT_FALSE((mp_valid<mp_append, mp_list<>, void>));
    BOOST_TEST_TRAIT_FALSE((mp_valid<mp_append, mp_list<>, mp_list<>, void>));
    BOOST_TEST_TRAIT_FALSE((mp_valid<mp_append, mp_list<>, mp_list<>, mp_list<>, void>));
    BOOST_TEST_TRAIT_FALSE((mp_valid<mp_append, mp_list<>, mp_list<>, mp_list<>, mp_list<>, void>));

    return zr_boost_1_81::report_errors();
}
