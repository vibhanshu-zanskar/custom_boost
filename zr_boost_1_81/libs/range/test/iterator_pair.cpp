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

#include <boost/range/concepts.hpp>
#include <boost/range/functions.hpp>
#include <boost/range/metafunctions.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits.hpp>
#include <boost/test/test_tools.hpp>
#include <vector>
#include <iterator>
#include <utility>

void check_iterator_pair()
{
    typedef std::vector<int> vec_t;
    vec_t                    vec;
    vec.push_back( 4 );
    typedef std::pair<vec_t::iterator,vec_t::iterator>
                             pair_t;
    typedef std::pair<vec_t::const_iterator,vec_t::const_iterator>
                             const_pair_t;
    typedef const pair_t     const_pair_tt;
    pair_t                   pair       = std::make_pair( zr_boost_1_81::begin( vec ), zr_boost_1_81::end( vec ) );
    const_pair_t             const_pair = std::make_pair( zr_boost_1_81::begin( vec ), zr_boost_1_81::end( vec ) );
    const_pair_tt            constness_pair( pair );


    BOOST_STATIC_ASSERT(( zr_boost_1_81::is_same< zr_boost_1_81::range_value<pair_t>::type,
                          std::iterator_traits<pair_t::first_type>::value_type>::value ));
    BOOST_STATIC_ASSERT(( zr_boost_1_81::is_same< zr_boost_1_81::range_iterator<pair_t>::type, pair_t::first_type >::value ));
    BOOST_STATIC_ASSERT(( zr_boost_1_81::is_same< zr_boost_1_81::range_const_iterator<pair_t>::type, pair_t::first_type >::value ));
    BOOST_STATIC_ASSERT(( zr_boost_1_81::is_same< zr_boost_1_81::range_difference<pair_t>::type,
                          std::iterator_traits<pair_t::first_type>::difference_type >::value ));
    BOOST_STATIC_ASSERT(( zr_boost_1_81::is_same< zr_boost_1_81::range_size<pair_t>::type, std::size_t >::value ));
    BOOST_STATIC_ASSERT(( zr_boost_1_81::is_same< zr_boost_1_81::range_iterator<pair_t>::type, pair_t::first_type >::value ));
    BOOST_STATIC_ASSERT(( zr_boost_1_81::is_same< zr_boost_1_81::range_iterator<const_pair_t>::type, const_pair_t::first_type >::value ));

    BOOST_STATIC_ASSERT(( zr_boost_1_81::is_same< zr_boost_1_81::range_value<const_pair_tt>::type,
                          std::iterator_traits<const_pair_t::first_type>::value_type>::value ));
    BOOST_STATIC_ASSERT(( zr_boost_1_81::is_same< zr_boost_1_81::range_iterator<const_pair_tt>::type, const_pair_tt::first_type >::value ));
    //
    // This behavior is not supported with v2.
    //BOOST_STATIC_ASSERT(( is_same< range_const_iterator<const_pair_tt>::type, const_pair_tt::first_type >::value ));
    BOOST_STATIC_ASSERT(( zr_boost_1_81::is_same< zr_boost_1_81::range_difference<const_pair_tt>::type,
                          std::iterator_traits<const_pair_tt::first_type>::difference_type >::value ));
    BOOST_STATIC_ASSERT(( zr_boost_1_81::is_same< zr_boost_1_81::range_size<const_pair_tt>::type, std::size_t >::value ));
    BOOST_STATIC_ASSERT(( zr_boost_1_81::is_same< zr_boost_1_81::range_iterator<const_pair_tt>::type, const_pair_tt::first_type >::value ));
    BOOST_STATIC_ASSERT(( zr_boost_1_81::is_same< zr_boost_1_81::range_iterator<const_pair_tt>::type, const_pair_tt::first_type >::value ));

    BOOST_CHECK( zr_boost_1_81::begin( pair ) == pair.first );
    BOOST_CHECK( zr_boost_1_81::end( pair )   == pair.second );
    BOOST_CHECK( zr_boost_1_81::empty( pair ) == (pair.first == pair.second) );
    BOOST_CHECK( zr_boost_1_81::size( pair )  ==
                    static_cast<std::size_t>(
                        std::distance(pair.first, pair.second)) );

    BOOST_CHECK( zr_boost_1_81::begin( const_pair ) == const_pair.first );
    BOOST_CHECK( zr_boost_1_81::end( const_pair )   == const_pair.second );
    BOOST_CHECK( zr_boost_1_81::empty( const_pair ) == (const_pair.first == const_pair.second) );
    BOOST_CHECK( zr_boost_1_81::size( const_pair )  ==
                    static_cast<std::size_t>(
                        std::distance(const_pair.first, const_pair.second)) );

    BOOST_CHECK( zr_boost_1_81::begin( constness_pair ) == constness_pair.first );
    BOOST_CHECK( zr_boost_1_81::end( constness_pair )   == constness_pair.second );
    BOOST_CHECK( zr_boost_1_81::empty( constness_pair ) == (constness_pair.first == const_pair.second) );
    BOOST_CHECK( zr_boost_1_81::size( constness_pair )  ==
                    static_cast<std::size_t>(
                        std::distance(constness_pair.first,
                                      constness_pair.second)) );
}


#include <boost/test/unit_test.hpp>

zr_boost_1_81::unit_test::test_suite* init_unit_test_suite( int argc, char* argv[] )
{
    zr_boost_1_81::unit_test::test_suite* test = BOOST_TEST_SUITE( "Range Test Suite" );

    test->add( BOOST_TEST_CASE( &check_iterator_pair ) );

    return test;
}






