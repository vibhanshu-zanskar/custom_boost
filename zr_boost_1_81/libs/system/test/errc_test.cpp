// Copyright 2020 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt

#include <boost/system/errc.hpp>
#include <boost/system/is_error_condition_enum.hpp>
#include <boost/core/lightweight_test.hpp>

int main()
{
    BOOST_TEST_EQ( static_cast<int>( zr_boost_1_81::system::errc::success ), 0 );
    BOOST_TEST_EQ( static_cast<int>( zr_boost_1_81::system::errc::no_such_file_or_directory ), ENOENT );
    BOOST_TEST_EQ( static_cast<int>( zr_boost_1_81::system::errc::address_family_not_supported ), EAFNOSUPPORT );

    BOOST_TEST( zr_boost_1_81::system::is_error_condition_enum< zr_boost_1_81::system::errc::errc_t >::value );

    return zr_boost_1_81::report_errors();
}
