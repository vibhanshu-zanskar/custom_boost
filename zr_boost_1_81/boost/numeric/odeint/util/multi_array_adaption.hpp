/*
  [auto_generated]
  boost/numeric/odeint/util/multi_array_adaption.hpp

  [begin_description]
  tba.
  [end_description]

  Copyright 2009-2012 Karsten Ahnert
  Copyright 2009-2012 Mario Mulansky

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE_1_0.txt or
  copy at http://www.boost.org/LICENSE_1_0.txt)
*/


#ifndef BOOST_NUMERIC_ODEINT_UTIL_MULTI_ARRAY_ADAPTION_HPP_DEFINED
#define BOOST_NUMERIC_ODEINT_UTIL_MULTI_ARRAY_ADAPTION_HPP_DEFINED



#include <boost/numeric/odeint/util/is_resizeable.hpp>
#include <boost/numeric/odeint/util/resize.hpp>
#include <boost/numeric/odeint/util/same_size.hpp>

#include <boost/mpl/and.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/multi_array.hpp>


namespace zr_boost_1_81 {
namespace numeric {
namespace odeint {
    
template< typename T >
struct is_multi_array
{
    typedef zr_boost_1_81::false_type type;
    const static bool value = type::value;
};
    
template< typename T >
struct is_resizeable_multi_array
{
    typedef zr_boost_1_81::false_type type;
    const static bool value = type::value;
};



template< typename V , size_t Dim , typename A >
struct is_multi_array< zr_boost_1_81::multi_array< V , Dim , A > >
{
    typedef zr_boost_1_81::true_type type;
    const static bool value = type::value;
};

template< typename V , size_t Dim , typename A >
struct is_resizeable_multi_array< zr_boost_1_81::multi_array< V , Dim , A > >
{
    typedef zr_boost_1_81::true_type type;
    const static bool value = type::value;
};




template< typename T  >
struct is_resizeable_sfinae< T , typename zr_boost_1_81::enable_if< typename is_resizeable_multi_array< T >::type >::type >
{
    typedef zr_boost_1_81::true_type type;
    const static bool value = type::value;
};





template< typename T1 , typename T2  >
struct same_size_impl_sfinae< T1 , T2 ,
                       typename zr_boost_1_81::enable_if<
                           typename zr_boost_1_81::mpl::and_< 
                               is_multi_array< T1 > ,
                               is_multi_array< T2 > ,
                               zr_boost_1_81::mpl::bool_< T1::dimensionality == T2::dimensionality >
                           >::type
                       >::type >
{
    static bool same_size( T1 const &x1 , T2 const &x2 )
    {
        for( size_t i=0 ; i<T1::dimensionality ; ++i )
        {
            if( x1.shape()[i] != x2.shape()[i] ) return false;
            if( x1.index_bases()[i] != x2.index_bases()[i] ) return false;
        }
        return true;
    }
};


template< typename T1 , typename T2 >
struct resize_impl_sfinae< T1 , T2 ,
                    typename zr_boost_1_81::enable_if<
                        typename zr_boost_1_81::mpl::and_<
                            is_resizeable_multi_array< T1 > ,
                            is_multi_array< T2 > ,
                            zr_boost_1_81::mpl::bool_< T1::dimensionality == T2::dimensionality >
                        >::type
                    >::type >
{
    static void resize( T1 &x1 , const T2 &x2 )
    {
        zr_boost_1_81::array< int , T1::dimensionality > extents;
        for( size_t i=0 ; i<T1::dimensionality ; ++i ) extents[i] = x2.shape()[i];
        x1.resize( extents );
        zr_boost_1_81::array< int , T1::dimensionality > origins;
        for( size_t i=0 ; i<T1::dimensionality ; ++i ) origins[i] = x2.index_bases()[i];
        x1.reindex( origins );
    }
};
                            


} // namespace odeint
} // namespace numeric
} // namespace zr_boost_1_81


#endif // BOOST_NUMERIC_ODEINT_UTIL_MULTI_ARRAY_ADAPTION_HPP_DEFINED
