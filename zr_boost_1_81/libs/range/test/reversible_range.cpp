// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//


#include <boost/detail/workaround.hpp>

#if BOOST_WORKAROUND(BOOST_BORLANDC, BOOST_TESTED_AT(0x564))
#  pragma warn -8091 // suppress warning in Boost.Test
#  pragma warn -8057 // unused argument argc/argv in Boost.Test
#endif

#include <boost/range/rbegin.hpp>
#include <boost/range/rend.hpp>
#include <boost/range/begin.hpp>
#include <boost/range/end.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits.hpp>
#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>
#include <vector>
#include <algorithm>

void check_iterator()
{
    typedef std::vector<int>                            vec_t;
    typedef vec_t::iterator                             iterator;
    typedef std::pair<iterator,iterator>                pair_t;
    typedef zr_boost_1_81::range_reverse_iterator<pair_t>::type rev_iterator;
    typedef std::pair<rev_iterator,rev_iterator>        rev_pair_t;

    vec_t                            vec;
    pair_t                           p    = std::make_pair( vec.begin(), vec.end() );
    rev_pair_t                       rp   = std::make_pair( zr_boost_1_81::rbegin( p ), zr_boost_1_81::rend( p ) );
    int                             a[]  = {1,2,3,4,5,6,7,8,9,10};
    const int                       ca[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    BOOST_CHECK( zr_boost_1_81::rbegin( vec ) == zr_boost_1_81::range_reverse_iterator<vec_t>::type( vec.end() ) );
    BOOST_CHECK( zr_boost_1_81::rend( vec ) == zr_boost_1_81::range_reverse_iterator<vec_t>::type( vec.begin() ) );
    BOOST_CHECK( std::distance( zr_boost_1_81::rbegin( vec ), zr_boost_1_81::rend( vec ) ) == std::distance( zr_boost_1_81::begin( vec ), zr_boost_1_81::end( vec ) ) );

    BOOST_CHECK( zr_boost_1_81::rbegin( p ) == zr_boost_1_81::begin( rp ) );
    BOOST_CHECK( zr_boost_1_81::rend( p ) == zr_boost_1_81::end( rp ) );
    BOOST_CHECK( std::distance( zr_boost_1_81::rbegin( p ), zr_boost_1_81::rend( p ) ) == std::distance( zr_boost_1_81::begin( rp ), zr_boost_1_81::end( rp ) ) );
    BOOST_CHECK( std::distance( zr_boost_1_81::begin( p ), zr_boost_1_81::end( p ) ) == std::distance( zr_boost_1_81::rbegin( rp ), zr_boost_1_81::rend( rp ) ) );


    BOOST_CHECK_EQUAL( &*zr_boost_1_81::begin( a ), &*( zr_boost_1_81::rend( a ) - 1 ) );
    BOOST_CHECK_EQUAL( &*( zr_boost_1_81::end( a ) - 1 ), &*zr_boost_1_81::rbegin( a ) );
    BOOST_CHECK_EQUAL( &*zr_boost_1_81::begin( ca ), &*( zr_boost_1_81::rend( ca ) - 1 ) );
    BOOST_CHECK_EQUAL( &*( zr_boost_1_81::end( ca ) - 1 ), &*zr_boost_1_81::rbegin( ca ) );
}


zr_boost_1_81::unit_test::test_suite* init_unit_test_suite( int argc, char* argv[] )
{
    zr_boost_1_81::unit_test::test_suite* test = BOOST_TEST_SUITE( "Range Test Suite" );

    test->add( BOOST_TEST_CASE( &check_iterator ) );

    return test;
}







