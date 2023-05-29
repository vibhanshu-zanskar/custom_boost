/*
Copyright 2019 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost/io/ostream_joiner.hpp>
#include <boost/core/lightweight_test.hpp>
#include <sstream>

int main()
{
    std::ostringstream o;
    zr_boost_1_81::io::ostream_joiner<char> j = zr_boost_1_81::io::make_ostream_joiner(o, ',');
    *j++ = 1;
    *j++ = '2';
    *j++ = "3";
    BOOST_TEST_EQ(o.str(), "1,2,3");
    return zr_boost_1_81::report_errors();
}
