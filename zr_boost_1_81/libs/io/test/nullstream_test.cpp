/*
Copyright 2021 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost/io/nullstream.hpp>
#include <boost/core/lightweight_test.hpp>

int main()
{
    {
        zr_boost_1_81::io::onullstream s;
        s << "abc";
        s << 100;
        s << std::endl;
        BOOST_TEST(s);
    }
    {
        zr_boost_1_81::io::wonullstream s;
        s << L"abc";
        s << 100;
        s << std::endl;
        BOOST_TEST(s);
    }
    return zr_boost_1_81::report_errors();
}
