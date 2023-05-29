// Copyright 2021, 2022 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt

#include <boost/system/error_code.hpp>
#include <boost/system/error_category.hpp>
#include <boost/core/lightweight_test.hpp>
#include <boost/config/pragma_message.hpp>
#include <boost/config.hpp>
#include <cerrno>

#if !defined(BOOST_SYSTEM_HAS_SYSTEM_ERROR)

BOOST_PRAGMA_MESSAGE( "BOOST_SYSTEM_HAS_SYSTEM_ERROR not defined, test will be skipped" )
int main() {}

#else

#include <system_error>

class my_category_impl: public zr_boost_1_81::system::error_category
{
public:

    char const* name() const BOOST_NOEXCEPT
    {
        return "mycat";
    }

    std::string message( int /*ev*/ ) const
    {
        return "Unknown error";
    }
};

zr_boost_1_81::system::error_category const& my_category()
{
    static my_category_impl mycat;
    return mycat;
}

int main()
{
    {
        zr_boost_1_81::system::error_code e1( 5, my_category() );
        std::error_code e2( e1 );
        zr_boost_1_81::system::error_code e3( e2 );

        BOOST_TEST_EQ( e1, e3 );
        BOOST_TEST_EQ( e1.value(), e3.value() );
        BOOST_TEST_EQ( &e1.category(), &e3.category() );
    }

    return zr_boost_1_81::report_errors();
}

#endif
