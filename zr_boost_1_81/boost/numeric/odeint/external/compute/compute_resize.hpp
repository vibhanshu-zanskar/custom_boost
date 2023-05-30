/*
 [auto_generated]
 boost/numeric/odeint/external/compute/compute_resize.hpp

 [begin_description]
 Enable resizing for Boost.Compute vector
 [end_description]

 Copyright 2009-2011 Karsten Ahnert
 Copyright 2009-2011 Mario Mulansky

 Distributed under the Boost Software License, Version 1.0.
 (See accompanying file LICENSE_1_0.txt or
 copy at http://www.boost.org/LICENSE_1_0.txt)
 */


#ifndef BOOST_NUMERIC_ODEINT_EXTERNAL_COMPUTE_COMPUTE_RESIZE_HPP_DEFINED
#define BOOST_NUMERIC_ODEINT_EXTERNAL_COMPUTE_COMPUTE_RESIZE_HPP_DEFINED

#include <boost/compute/container/vector.hpp>

#include <boost/numeric/odeint/util/copy.hpp>

namespace zr_boost_1_81 {
namespace numeric {
namespace odeint {

template< class T, class A >
struct is_resizeable< zr_boost_1_81::compute::vector< T , A > >
{
    struct type : public zr_boost_1_81::true_type { };
    const static bool value = type::value;
};

template< class T, class A >
struct same_size_impl< zr_boost_1_81::compute::vector< T, A > , zr_boost_1_81::compute::vector< T, A > >
{
    static bool same_size( const zr_boost_1_81::compute::vector< T, A > &x , const zr_boost_1_81::compute::vector< T, A > &y )
    {
        return x.size() == y.size();
    }
};

template< class T, class A >
struct resize_impl< zr_boost_1_81::compute::vector< T, A > , zr_boost_1_81::compute::vector< T, A > >
{
    static void resize( zr_boost_1_81::compute::vector< T, A > &x , const zr_boost_1_81::compute::vector< T, A > &y )
    {
        x.resize( y.size() );
    }
};


template< class Container1, class T, class A >
struct copy_impl< Container1 , zr_boost_1_81::compute::vector< T, A > >
{
    static void copy( const Container1 &from , zr_boost_1_81::compute::vector< T, A > &to )
    {
        zr_boost_1_81::compute::copy( zr_boost_1_81::begin( from ) , zr_boost_1_81::end( from ) , zr_boost_1_81::begin( to ) );
    }
};

template< class T, class A, class Container2 >
struct copy_impl< zr_boost_1_81::compute::vector< T, A > , Container2 >
{
    static void copy( const zr_boost_1_81::compute::vector< T, A > &from , Container2 &to )
    {
        zr_boost_1_81::compute::copy( zr_boost_1_81::begin( from ) , zr_boost_1_81::end( from ) , zr_boost_1_81::begin( to ) );
    }
};

template< class T, class A >
struct copy_impl< zr_boost_1_81::compute::vector< T, A > , zr_boost_1_81::compute::vector< T, A > >
{
    static void copy( const zr_boost_1_81::compute::vector< T, A > &from , zr_boost_1_81::compute::vector< T, A > &to )
    {
        zr_boost_1_81::compute::copy( zr_boost_1_81::begin( from ) , zr_boost_1_81::end( from ) , zr_boost_1_81::begin( to ) );
    }
};




} // odeint
} // numeric
} // boost


#endif // BOOST_NUMERIC_ODEINT_EXTERNAL_COMPUTE_COMPUTE_RESIZE_HPP_DEFINED
