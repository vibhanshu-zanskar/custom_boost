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

#include <boost/range/functions.hpp>
#include <boost/range/metafunctions.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>
#include <vector>

void check_std_container()
{
    typedef std::vector<int> vec_t;
    vec_t                    vec;
    vec.push_back( 3 ); vec.push_back( 4 );
    const vec_t              cvec( vec );

    BOOST_STATIC_ASSERT(( zr_boost_1_81::is_same< zr_boost_1_81::range_value<vec_t>::type, vec_t::value_type >::value ));
    BOOST_STATIC_ASSERT(( zr_boost_1_81::is_same< zr_boost_1_81::range_iterator<vec_t>::type, vec_t::iterator >::value ));
    BOOST_STATIC_ASSERT(( zr_boost_1_81::is_same< zr_boost_1_81::range_iterator<const vec_t>::type, vec_t::const_iterator >::value ));
    BOOST_STATIC_ASSERT(( zr_boost_1_81::is_same< zr_boost_1_81::range_difference<vec_t>::type, vec_t::difference_type >::value ));
    BOOST_STATIC_ASSERT(( zr_boost_1_81::is_same< zr_boost_1_81::range_size<vec_t>::type, vec_t::size_type >::value ));
    BOOST_STATIC_ASSERT(( zr_boost_1_81::is_same< zr_boost_1_81::range_iterator<vec_t>::type, vec_t::iterator >::value ));
    BOOST_STATIC_ASSERT(( zr_boost_1_81::is_same< zr_boost_1_81::range_iterator<const vec_t>::type, vec_t::const_iterator >::value ));

    BOOST_STATIC_ASSERT(( zr_boost_1_81::is_same< zr_boost_1_81::range_value<const vec_t>::type, vec_t::value_type >::value ));
    BOOST_STATIC_ASSERT(( zr_boost_1_81::is_same< zr_boost_1_81::range_difference<const vec_t>::type, vec_t::difference_type >::value ));
    BOOST_STATIC_ASSERT(( zr_boost_1_81::is_same< zr_boost_1_81::range_size<const vec_t>::type, vec_t::size_type >::value ));

    BOOST_CHECK( zr_boost_1_81::begin( vec ) == vec.begin() );
    BOOST_CHECK( zr_boost_1_81::end( vec )   == vec.end() );
    BOOST_CHECK( zr_boost_1_81::empty( vec ) == vec.empty() );
    BOOST_CHECK( static_cast<std::size_t>(zr_boost_1_81::size( vec )) == vec.size() );

    BOOST_CHECK( zr_boost_1_81::begin( cvec ) == cvec.begin() );
    BOOST_CHECK( zr_boost_1_81::end( cvec )   == cvec.end() );
    BOOST_CHECK( zr_boost_1_81::empty( cvec ) == cvec.empty() );
    BOOST_CHECK( static_cast<std::size_t>(zr_boost_1_81::size( cvec )) == cvec.size() );

}


#include <boost/test/unit_test.hpp>

zr_boost_1_81::unit_test::test_suite* init_unit_test_suite( int argc, char* argv[] )
{
    zr_boost_1_81::unit_test::test_suite* test = BOOST_TEST_SUITE( "Range Test Suite" );

    test->add( BOOST_TEST_CASE( &check_std_container ) );

    return test;
}






