// Copyright 2022 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt

#include <boost/assert/source_location.hpp>
#include <boost/core/lightweight_test.hpp>
#include <boost/config.hpp>

zr_boost_1_81::source_location s_loc = BOOST_CURRENT_LOCATION;

BOOST_STATIC_CONSTEXPR zr_boost_1_81::source_location c_loc = BOOST_CURRENT_LOCATION;

zr_boost_1_81::source_location f( zr_boost_1_81::source_location const& loc = BOOST_CURRENT_LOCATION )
{
    return loc;
}

int main()
{
    {
        BOOST_TEST_CSTR_EQ( s_loc.file_name(), __FILE__ );
        BOOST_TEST_EQ( s_loc.line(), 9 );

#if defined(BOOST_GCC) && BOOST_GCC < 90000
        // '__static_initialization_and_destruction_0'
#else
        BOOST_TEST_CSTR_EQ( s_loc.function_name(), "" );
#endif
    }

    {
        BOOST_TEST_CSTR_EQ( c_loc.file_name(), __FILE__ );
        BOOST_TEST_EQ( c_loc.line(), 11 );
    }

    {
        zr_boost_1_81::source_location loc = f();

        BOOST_TEST_CSTR_EQ( loc.file_name(), __FILE__ );
        BOOST_TEST( loc.line() == 13 || loc.line() == 37 );
    }

    return zr_boost_1_81::report_errors();
}
