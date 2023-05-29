// Copyright 2021 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt

#include <boost/system/error_code.hpp>
#include <boost/core/lightweight_test.hpp>
#include <boost/config/pragma_message.hpp>
#include <boost/config.hpp>
#include <cerrno>

#if !defined(BOOST_SYSTEM_HAS_SYSTEM_ERROR)

BOOST_PRAGMA_MESSAGE( "BOOST_SYSTEM_HAS_SYSTEM_ERROR not defined, test will be skipped" )
int main() {}

#else

#include <system_error>

enum my_errc
{
    my_enoent = ENOENT
};

#if defined(BOOST_GCC) && BOOST_GCC < 70000

// g++ 6 and earlier do not allow specializations outside the namespace

namespace zr_boost_1_81
{
namespace system
{

template<> struct is_error_condition_enum<my_errc>: std::true_type {};

} // namespace system
} // namespace zr_boost_1_81

namespace std
{

template<> struct is_error_condition_enum<my_errc>: std::true_type {};

} // namespace std

#else

template<> struct zr_boost_1_81::system::is_error_condition_enum<my_errc>: std::true_type {};
template<> struct std::is_error_condition_enum<my_errc>: std::true_type {};

#endif

zr_boost_1_81::system::error_condition make_error_condition( my_errc e )
{
    return zr_boost_1_81::system::error_condition( e, zr_boost_1_81::system::generic_category() );
}

zr_boost_1_81::system::error_code make_error_code( my_errc e )
{
    return zr_boost_1_81::system::error_code( e, zr_boost_1_81::system::generic_category() );
}

int main()
{
    {
        zr_boost_1_81::system::error_code e1 = make_error_code( my_enoent );

        BOOST_TEST( e1 == my_enoent );
        BOOST_TEST_NOT( e1 != my_enoent );
    }

    {
        std::error_code e1 = make_error_code( my_enoent );

        BOOST_TEST( e1 == my_enoent );
        BOOST_TEST_NOT( e1 != my_enoent );
    }

    return zr_boost_1_81::report_errors();
}

#endif
