
//  Copyright 2015 Peter Dimov.
//
// Distributed under the Boost Software License, Version 1.0.
//
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt


#include <boost/core/lightweight_test_trait.hpp>
#include <boost/mp11/list.hpp>
#include <type_traits>
#include <tuple>
#include <utility>

int main()
{
    using zr_boost_1_81::mp11::mp_list;
    using zr_boost_1_81::mp11::mp_third;

    using L1 = mp_list<int[], void, float[]>;
    BOOST_TEST_TRAIT_TRUE((std::is_same<mp_third<L1>, float[]>));

    using L2 = std::tuple<int, float, char>;
    BOOST_TEST_TRAIT_TRUE((std::is_same<mp_third<L2>, char>));

    return zr_boost_1_81::report_errors();
}
