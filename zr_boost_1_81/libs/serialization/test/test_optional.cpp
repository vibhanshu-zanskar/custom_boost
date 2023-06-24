/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// test_optional.cpp

// (C) Copyright 2004 Pavel Vozenilek
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// should pass compilation and execution

#include <cstddef> // NULL
#include <cstdio> // remove
#include <fstream>

#include <boost/config.hpp>

#if defined(BOOST_NO_STDC_NAMESPACE)
namespace std{
    using ::remove;
}
#endif

#include <boost/archive/archive_exception.hpp>
#include "test_tools.hpp"

#include <boost/serialization/optional.hpp>
#include <boost/serialization/string.hpp>

struct A {
    int m_x;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int /* version */){
        ar & zr_boost_1_81::serialization::make_nvp("x", m_x);
    };
    bool operator==(const A & rhs) const {
        return m_x == rhs.m_x;
    }
    // note that default constructor is not trivial
    A() :
        m_x(0)
    {}
    A(int x) :
        m_x(x)
    {}
};

int test_main( int /* argc */, char* /* argv */[] )
{
    const char * testfile = zr_boost_1_81::archive::tmpnam(NULL);
    BOOST_REQUIRE(NULL != testfile);

    const zr_boost_1_81::optional<int> aoptional1;
    const zr_boost_1_81::optional<int> aoptional2(123);
    const zr_boost_1_81::optional<A> aoptional3;
    A a(1);
    const zr_boost_1_81::optional<A> aoptional4(a);
    const zr_boost_1_81::optional<A *> aoptional5;
    const zr_boost_1_81::optional<A *> aoptional6(& a);
    {
        test_ostream os(testfile, TEST_STREAM_FLAGS);
        test_oarchive oa(os, TEST_ARCHIVE_FLAGS);
        oa << zr_boost_1_81::serialization::make_nvp("aoptional1",aoptional1);
        oa << zr_boost_1_81::serialization::make_nvp("aoptional2",aoptional2);
        oa << zr_boost_1_81::serialization::make_nvp("aoptional3",aoptional3);
        oa << zr_boost_1_81::serialization::make_nvp("aoptional4",aoptional4);
        oa << zr_boost_1_81::serialization::make_nvp("aoptional5",aoptional5);
        oa << zr_boost_1_81::serialization::make_nvp("aoptional6",aoptional6);
    }
    zr_boost_1_81::optional<int> aoptional1a(999);
    zr_boost_1_81::optional<int> aoptional2a;
    zr_boost_1_81::optional<A> aoptional3a;
    zr_boost_1_81::optional<A> aoptional4a;
    zr_boost_1_81::optional<A *> aoptional5a;
    zr_boost_1_81::optional<A *> aoptional6a;
    {
        test_istream is(testfile, TEST_STREAM_FLAGS);
        test_iarchive ia(is, TEST_ARCHIVE_FLAGS);
        ia >> zr_boost_1_81::serialization::make_nvp("aoptional1",aoptional1a);
        ia >> zr_boost_1_81::serialization::make_nvp("aoptional2",aoptional2a);
        ia >> zr_boost_1_81::serialization::make_nvp("aoptional3",aoptional3a);
        ia >> zr_boost_1_81::serialization::make_nvp("aoptional4",aoptional4a);
        ia >> zr_boost_1_81::serialization::make_nvp("aoptional5",aoptional5a);
        ia >> zr_boost_1_81::serialization::make_nvp("aoptional6",aoptional6a);
    }
    BOOST_CHECK(aoptional1 == aoptional1a);
    BOOST_CHECK(aoptional2 == aoptional2a);
    BOOST_CHECK(aoptional3 == aoptional3a);
    BOOST_CHECK(aoptional4.get() == aoptional4a.get());
    BOOST_CHECK(aoptional5 == aoptional5a);
    BOOST_CHECK(*aoptional6.get() == *aoptional6a.get());

    std::remove(testfile);
    return EXIT_SUCCESS;
}

// EOF
