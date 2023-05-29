/*
Copyright 2010 Beman Dawes

Copyright 2019 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost/io/quoted.hpp>
#include <boost/core/lightweight_test.hpp>
#include <iostream>
#include <sstream>

int main()
{
    const std::string s0("foo");
    std::string r;
    {
        std::stringstream ss;
        ss << zr_boost_1_81::io::quoted(s0);
        ss >> r;
        BOOST_TEST(r == "\"foo\"");
    }
    {
        std::stringstream ss;
        ss << zr_boost_1_81::io::quoted(s0);
        ss >> zr_boost_1_81::io::quoted(r);
        BOOST_TEST(r == "foo");
    }
    const std::string s0s("foo bar");
    {
        std::stringstream ss;
        ss << zr_boost_1_81::io::quoted(s0s);
        ss >> r;
        BOOST_TEST(r == "\"foo");
    }
    {
        std::stringstream ss;
        ss << zr_boost_1_81::io::quoted(s0s);
        ss >> zr_boost_1_81::io::quoted(r);
        BOOST_TEST(r == "foo bar");
    }
    const std::string s1("foo\\bar, \" *");
    {
        std::stringstream ss;
        ss << zr_boost_1_81::io::quoted(s1);
        ss >> r;
        BOOST_TEST(r == "\"foo\\\\bar,");
    }
    {
        std::stringstream ss;
        ss << zr_boost_1_81::io::quoted("foo\\bar, \" *");
        ss >> r;
        BOOST_TEST(r == "\"foo\\\\bar,");
    }
    {
        std::stringstream ss;
        ss << zr_boost_1_81::io::quoted(s1);
        ss >> zr_boost_1_81::io::quoted(r);
        BOOST_TEST(r == s1);
    }
    {
        std::stringstream ss;
        ss << zr_boost_1_81::io::quoted(s1.c_str());
        ss >> zr_boost_1_81::io::quoted(r);
        BOOST_TEST(r == s1);
    }
    std::string s2("'Jack & Jill'");
    {
        std::stringstream ss;
        ss << zr_boost_1_81::io::quoted(s2, '&', '\'');
        ss >> zr_boost_1_81::io::quoted(r, '&', '\'');
        BOOST_TEST(r == s2);
    }
    const std::wstring ws1(L"foo$bar, \" *");
    std::wstring wr;
    {
        std::wstringstream wss;
        wss << zr_boost_1_81::io::quoted(ws1, L'$');
        wss >> zr_boost_1_81::io::quoted(wr,  L'$');
        BOOST_TEST(wr == ws1);
    }
    const std::string s3("const string");
    {
        std::stringstream ss;
        ss << zr_boost_1_81::io::quoted(s3);
        ss >> zr_boost_1_81::io::quoted(r);
        BOOST_TEST(r == s3);
    }
    {
        std::stringstream ss;
        ss << "\"abc";
        ss >> zr_boost_1_81::io::quoted(r);
        BOOST_TEST(r == "abc");
    }
    {
        std::stringstream ss;
        ss << "abc";
        ss >> zr_boost_1_81::io::quoted(r);
        BOOST_TEST(r == "abc");
    }
    {
        std::stringstream ss;
        ss << "abc def";
        ss >> zr_boost_1_81::io::quoted(r);
        BOOST_TEST(r == "abc");
    }
    return zr_boost_1_81::report_errors();
}
