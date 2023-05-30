//  (C) Copyright John Maddock 2005.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MATH_COMPLEX_FABS_INCLUDED
#define BOOST_MATH_COMPLEX_FABS_INCLUDED

#ifndef BOOST_MATH_HYPOT_INCLUDED
#  include <boost/math/special_functions/hypot.hpp>
#endif

namespace zr_boost_1_81{ namespace math{

template<class T> 
inline T fabs(const std::complex<T>& z)
{
   return ::zr_boost_1_81::math::hypot(z.real(), z.imag());
}

} } // namespaces

#endif // BOOST_MATH_COMPLEX_FABS_INCLUDED
