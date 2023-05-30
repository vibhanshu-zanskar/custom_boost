/*
 [auto_generated]
 boost/numeric/odeint/algebra/range_algebra.hpp

 [begin_description]
 Default algebra, which works with the most state types, like vector< double >, zr_boost_1_81::array< double >, zr_boost_1_81::range.
 Internally is uses zr_boost_1_81::range to obtain the begin and end iterator of the according sequence.
 [end_description]

 Copyright 2010-2013 Karsten Ahnert
 Copyright 2010-2013 Mario Mulansky

 Distributed under the Boost Software License, Version 1.0.
 (See accompanying file LICENSE_1_0.txt or
 copy at http://www.boost.org/LICENSE_1_0.txt)
 */


#ifndef BOOST_NUMERIC_ODEINT_ALGEBRA_RANGE_ALGEBRA_HPP_INCLUDED
#define BOOST_NUMERIC_ODEINT_ALGEBRA_RANGE_ALGEBRA_HPP_INCLUDED

#include <boost/range.hpp>
#include <boost/mpl/size_t.hpp>

#include <boost/numeric/odeint/algebra/detail/macros.hpp>
#include <boost/numeric/odeint/algebra/detail/for_each.hpp>
#include <boost/numeric/odeint/algebra/detail/norm_inf.hpp>
#include <boost/numeric/odeint/algebra/norm_result_type.hpp>

namespace zr_boost_1_81 {
namespace numeric {
namespace odeint {

struct range_algebra
{
    template< class S1 , class Op >
    static void for_each1( S1 &s1 , Op op )
    {
        detail::for_each1( zr_boost_1_81::begin( s1 ) , zr_boost_1_81::end( s1 ) ,
                op );
    }

    template< class S1 , class S2 , class Op >
    static void for_each2( S1 &s1 , S2 &s2 , Op op )
    {
        detail::for_each2( zr_boost_1_81::begin( s1 ) , zr_boost_1_81::end( s1 ) ,
                zr_boost_1_81::begin( s2 ) , op );
    }

    template< class S1 , class S2 , class S3 , class Op >
    static void for_each3( S1 &s1 , S2 &s2 , S3 &s3 , Op op )
    {
        detail::for_each3( zr_boost_1_81::begin( s1 ) , zr_boost_1_81::end( s1 ) , zr_boost_1_81::begin( s2 ) , zr_boost_1_81::begin( s3 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class Op >
    static void for_each4( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , Op op )
    {
        detail::for_each4( zr_boost_1_81::begin( s1 ) , zr_boost_1_81::end( s1 ) , zr_boost_1_81::begin( s2 ) , zr_boost_1_81::begin( s3 ) , zr_boost_1_81::begin( s4 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class S5 , class Op >
    static void for_each5( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , S5 &s5 , Op op )
    {
        detail::for_each5( zr_boost_1_81::begin( s1 ) , zr_boost_1_81::end( s1 ) , zr_boost_1_81::begin( s2 ) , zr_boost_1_81::begin( s3 ) , zr_boost_1_81::begin( s4 ) , zr_boost_1_81::begin( s5 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class S5 , class S6 , class Op >
    static void for_each6( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , S5 &s5 , S6 &s6 , Op op )
    {
        detail::for_each6( zr_boost_1_81::begin( s1 ) , zr_boost_1_81::end( s1 ) , zr_boost_1_81::begin( s2 ) , zr_boost_1_81::begin( s3 ) , zr_boost_1_81::begin( s4 ) , zr_boost_1_81::begin( s5 ) , zr_boost_1_81::begin( s6 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class S5 , class S6 ,class S7 , class Op >
    static void for_each7( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , S5 &s5 , S6 &s6 , S7 &s7 , Op op )
    {
        detail::for_each7( zr_boost_1_81::begin( s1 ) , zr_boost_1_81::end( s1 ) , zr_boost_1_81::begin( s2 ) , zr_boost_1_81::begin( s3 ) , zr_boost_1_81::begin( s4 ) , zr_boost_1_81::begin( s5 ) , zr_boost_1_81::begin( s6 ) , zr_boost_1_81::begin( s7 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class S5 , class S6 ,class S7 , class S8 , class Op >
    static void for_each8( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , S5 &s5 , S6 &s6 , S7 &s7 , S8 &s8 , Op op )
    {
        detail::for_each8( zr_boost_1_81::begin( s1 ) , zr_boost_1_81::end( s1 ) , zr_boost_1_81::begin( s2 ) , zr_boost_1_81::begin( s3 ) , zr_boost_1_81::begin( s4 ) , zr_boost_1_81::begin( s5 ) , zr_boost_1_81::begin( s6 ) , zr_boost_1_81::begin( s7 ) , zr_boost_1_81::begin( s8 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class S5 , class S6 ,class S7 , class S8 , class S9 , class Op >
    static void for_each9( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , S5 &s5 , S6 &s6 , S7 &s7 , S8 &s8 , S9 &s9 , Op op )
    {
        detail::for_each9( zr_boost_1_81::begin( s1 ) , zr_boost_1_81::end( s1 ) , zr_boost_1_81::begin( s2 ) , zr_boost_1_81::begin( s3 ) , zr_boost_1_81::begin( s4 ) , zr_boost_1_81::begin( s5 ) , zr_boost_1_81::begin( s6 ) , zr_boost_1_81::begin( s7 ) , zr_boost_1_81::begin( s8 ) , zr_boost_1_81::begin( s9 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class S5 , class S6 ,class S7 , class S8 , class S9 , class S10 , class Op >
    static void for_each10( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , S5 &s5 , S6 &s6 , S7 &s7 , S8 &s8 , S9 &s9 , S10 &s10 , Op op )
    {
        detail::for_each10( zr_boost_1_81::begin( s1 ) , zr_boost_1_81::end( s1 ) , zr_boost_1_81::begin( s2 ) , zr_boost_1_81::begin( s3 ) , zr_boost_1_81::begin( s4 ) , zr_boost_1_81::begin( s5 ) , zr_boost_1_81::begin( s6 ) , zr_boost_1_81::begin( s7 ) , zr_boost_1_81::begin( s8 ) , zr_boost_1_81::begin( s9 ) , zr_boost_1_81::begin( s10 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class S5 , class S6 ,class S7 , class S8 , class S9 , class S10 , class S11 , class Op >
    static void for_each11( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , S5 &s5 , S6 &s6 , S7 &s7 , S8 &s8 , S9 &s9 , S10 &s10 , S11 &s11 , Op op )
    {
        detail::for_each11( zr_boost_1_81::begin( s1 ) , zr_boost_1_81::end( s1 ) , zr_boost_1_81::begin( s2 ) , zr_boost_1_81::begin( s3 ) , zr_boost_1_81::begin( s4 ) , zr_boost_1_81::begin( s5 ) , zr_boost_1_81::begin( s6 ) , zr_boost_1_81::begin( s7 ) , zr_boost_1_81::begin( s8 ) , zr_boost_1_81::begin( s9 ) , zr_boost_1_81::begin( s10 ) , zr_boost_1_81::begin( s11 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class S5 , class S6 ,class S7 , class S8 , class S9 , class S10 , class S11 , class S12 , class Op >
    static void for_each12( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , S5 &s5 , S6 &s6 , S7 &s7 , S8 &s8 , S9 &s9 , S10 &s10 , S11 &s11 , S12 &s12 , Op op )
    {
        detail::for_each12( zr_boost_1_81::begin( s1 ) , zr_boost_1_81::end( s1 ) , zr_boost_1_81::begin( s2 ) , zr_boost_1_81::begin( s3 ) , zr_boost_1_81::begin( s4 ) , zr_boost_1_81::begin( s5 ) , zr_boost_1_81::begin( s6 ) , zr_boost_1_81::begin( s7 ) , zr_boost_1_81::begin( s8 ) , zr_boost_1_81::begin( s9 ) , zr_boost_1_81::begin( s10 ) , zr_boost_1_81::begin( s11 ) , zr_boost_1_81::begin( s12 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class S5 , class S6 ,class S7 , class S8 , class S9 , class S10 , class S11 , class S12 , class S13 , class Op >
    static void for_each13( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , S5 &s5 , S6 &s6 , S7 &s7 , S8 &s8 , S9 &s9 , S10 &s10 , S11 &s11 , S12 &s12 , S13 &s13 , Op op )
    {
        detail::for_each13( zr_boost_1_81::begin( s1 ) , zr_boost_1_81::end( s1 ) , zr_boost_1_81::begin( s2 ) , zr_boost_1_81::begin( s3 ) , zr_boost_1_81::begin( s4 ) , zr_boost_1_81::begin( s5 ) , zr_boost_1_81::begin( s6 ) , zr_boost_1_81::begin( s7 ) , zr_boost_1_81::begin( s8 ) , zr_boost_1_81::begin( s9 ) , zr_boost_1_81::begin( s10 ) , zr_boost_1_81::begin( s11 ) , zr_boost_1_81::begin( s12 ) , zr_boost_1_81::begin( s13 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class S5 , class S6 ,class S7 , class S8 , class S9 , class S10 , class S11 , class S12 , class S13 , class S14 , class Op >
    static void for_each14( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , S5 &s5 , S6 &s6 , S7 &s7 , S8 &s8 , S9 &s9 , S10 &s10 , S11 &s11 , S12 &s12 , S13 &s13 , S14 &s14 , Op op )
    {
        detail::for_each14( zr_boost_1_81::begin( s1 ) , zr_boost_1_81::end( s1 ) , zr_boost_1_81::begin( s2 ) , zr_boost_1_81::begin( s3 ) , zr_boost_1_81::begin( s4 ) , zr_boost_1_81::begin( s5 ) , zr_boost_1_81::begin( s6 ) , zr_boost_1_81::begin( s7 ) , zr_boost_1_81::begin( s8 ) , zr_boost_1_81::begin( s9 ) , zr_boost_1_81::begin( s10 ) , zr_boost_1_81::begin( s11 ) , zr_boost_1_81::begin( s12 ) , zr_boost_1_81::begin( s13 ) , zr_boost_1_81::begin( s14 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class S5 , class S6 ,class S7 , class S8 , class S9 , class S10 , class S11 , class S12 , class S13 , class S14 , class S15 , class Op >
    static void for_each15( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , S5 &s5 , S6 &s6 , S7 &s7 , S8 &s8 , S9 &s9 , S10 &s10 , S11 &s11 , S12 &s12 , S13 &s13 , S14 &s14 , S15 &s15 , Op op )
    {
        detail::for_each15( zr_boost_1_81::begin( s1 ) , zr_boost_1_81::end( s1 ) , zr_boost_1_81::begin( s2 ) , zr_boost_1_81::begin( s3 ) , zr_boost_1_81::begin( s4 ) , zr_boost_1_81::begin( s5 ) , zr_boost_1_81::begin( s6 ) , zr_boost_1_81::begin( s7 ) , zr_boost_1_81::begin( s8 ) , zr_boost_1_81::begin( s9 ) , zr_boost_1_81::begin( s10 ) , zr_boost_1_81::begin( s11 ) , zr_boost_1_81::begin( s12 ) , zr_boost_1_81::begin( s13 ) , zr_boost_1_81::begin( s14 ) , zr_boost_1_81::begin( s15 ) , op );
    }

    template< typename S >
    static typename norm_result_type<S>::type norm_inf( const S &s )
    {
        return detail::norm_inf( zr_boost_1_81::begin( s ) , zr_boost_1_81::end( s ) ,
                                 static_cast< typename norm_result_type<S>::type >( 0 ) );
    }

};

} // odeint
} // numeric
} // boost


#endif // BOOST_NUMERIC_ODEINT_ALGEBRA_RANGE_ALGEBRA_HPP_INCLUDED
