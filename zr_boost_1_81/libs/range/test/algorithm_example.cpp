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
#include <boost/range/as_literal.hpp>
#include <boost/test/test_tools.hpp>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

namespace
{
    //
    // example: extracting bounds in a generic algorithm
    //
    template< typename Range, typename T >
    inline typename zr_boost_1_81::range_iterator<Range>::type
    find( Range& c, const T& value )
    {
       return std::find( zr_boost_1_81::begin( c ), zr_boost_1_81::end( c ), value );
    }
    
    template< typename Range, typename T >
    inline typename zr_boost_1_81::range_iterator<Range>::type 
    find( const Range& c, const T& value )
    {
       return std::find( zr_boost_1_81::begin( c ), zr_boost_1_81::end( c ), value );
    }
                   
    // 
    // replace first value and return its index
    //                                
    template< class Range, class T >
    inline typename zr_boost_1_81::range_difference<Range>::type
    my_generic_replace( Range& c, const T& value, const T& replacement )
    {
       typename zr_boost_1_81::range_iterator<Range>::type found = find( c, value );
       
       if( found != zr_boost_1_81::end( c ) )
           *found = replacement;
       return std::distance( zr_boost_1_81::begin( c ), found );
    }                  
}


void check_algorithm()
{
    //
    // usage
    //
    const int N = 5;                     
    std::vector<int> my_vector;
    int values[] = { 1,2,3,4,5,6,7,8,9 };
    my_vector.assign( values, values + 9 );
    typedef std::vector<int>::iterator iterator;
    std::pair<iterator,iterator>       my_view( zr_boost_1_81::begin( my_vector ), 
                                                zr_boost_1_81::begin( my_vector ) + N );
    BOOST_CHECK_EQUAL( my_generic_replace( my_vector, 4, 2 ), 3 );
    BOOST_CHECK_EQUAL( my_generic_replace( my_view, 4, 2 ), N );

}

#include <boost/test/unit_test.hpp>
using zr_boost_1_81::unit_test::test_suite;

test_suite* init_unit_test_suite( int argc, char* argv[] )
{
    test_suite* test = BOOST_TEST_SUITE( "Range Test Suite" );

    test->add( BOOST_TEST_CASE( &check_algorithm ) );

    return test;
}



