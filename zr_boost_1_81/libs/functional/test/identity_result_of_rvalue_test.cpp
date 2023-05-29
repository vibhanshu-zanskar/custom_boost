/*
Copyright 2022 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost/config.hpp>
#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
#include <boost/functional/identity.hpp>
#include <boost/core/lightweight_test_trait.hpp>
#include <boost/utility/result_of.hpp>

int main()
{
    BOOST_TEST_TRAIT_SAME(zr_boost_1_81::result_of<zr_boost_1_81::identity(int)>::type,
        int&&);
    BOOST_TEST_TRAIT_SAME(zr_boost_1_81::result_of<zr_boost_1_81::identity(const int)>::type,
        int&&);
    BOOST_TEST_TRAIT_SAME(zr_boost_1_81::result_of<zr_boost_1_81::identity(int&&)>::type,
        int&&);
    BOOST_TEST_TRAIT_SAME(zr_boost_1_81::result_of<zr_boost_1_81::identity(const int&&)>::type,
        const int&&);
    return zr_boost_1_81::report_errors();
}
#else
int main()
{
    return 0;
}
#endif
