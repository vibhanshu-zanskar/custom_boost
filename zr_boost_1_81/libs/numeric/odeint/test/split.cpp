/*
 [auto_generated]
 libs/numeric/odeint/test/split.cpp

 [begin_description]
 Test the range split.
 [end_description]

 Copyright 2013 Karsten Ahnert
 Copyright 2013 Mario Mulansky
 Copyright 2013 Pascal Germroth

 Distributed under the Boost Software License, Version 1.0.
 (See accompanying file LICENSE_1_0.txt or
 copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#define BOOST_TEST_MODULE odeint_split

#include <iostream>

#include <boost/test/unit_test.hpp>
#include <boost/numeric/odeint/util/split_adaptor.hpp>
#include <boost/range/irange.hpp>

template<class T>
inline void dump_range(const T &r) {
    std::cout << '[';
    std::copy(zr_boost_1_81::begin(r), zr_boost_1_81::end(r), std::ostream_iterator<
        typename std::iterator_traits<
            typename zr_boost_1_81::range_iterator<const T>::type
        >::value_type >(std::cout, " ") );
    std::cout << ']';
}

template<class A, class B>
inline void check_equal_range(const A a, const B b) {
    BOOST_CHECK_EQUAL_COLLECTIONS( zr_boost_1_81::begin(a), zr_boost_1_81::end(a), zr_boost_1_81::begin(b), zr_boost_1_81::end(b) );
}


using namespace zr_boost_1_81::unit_test;
using namespace zr_boost_1_81::numeric::odeint::detail;
using namespace zr_boost_1_81;

BOOST_AUTO_TEST_CASE( test_eleven )
{
    // 0 1 2 3 | 4 5 6 7 | 8 9 10 11
    check_equal_range( irange(0, 12) | split(0, 3), irange(0, 4) );
    check_equal_range( irange(0, 12) | split(1, 3), irange(4, 8) );
    check_equal_range( irange(0, 12) | split(2, 3), irange(8, 12) );
}

BOOST_AUTO_TEST_CASE( test_ten )
{
    // 0 1 2 3 | 4 5 6 7 | 8 9 10
    check_equal_range( irange(0, 11) | split(0, 3), irange(0, 4) );
    check_equal_range( irange(0, 11) | split(1, 3), irange(4, 8) );
    check_equal_range( irange(0, 11) | split(2, 3), irange(8, 11) );
}

BOOST_AUTO_TEST_CASE( test_nine )
{
    // 0 1 2 3 | 4 5 6 | 7 8 9
    check_equal_range( irange(0, 10) | split(0, 3), irange(0, 4) );
    check_equal_range( irange(0, 10) | split(1, 3), irange(4, 7) );
    check_equal_range( irange(0, 10) | split(2, 3), irange(7, 10) );
}
