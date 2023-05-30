//---------------------------------------------------------------------------//
// Copyright (c) 2013 Kyle Lutz <kyle.r.lutz@gmail.com>
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
// See http://boostorg.github.com/compute for more information.
//---------------------------------------------------------------------------//

#ifndef BOOST_COMPUTE_FUNCTIONAL_MATH_HPP
#define BOOST_COMPUTE_FUNCTIONAL_MATH_HPP

#include <boost/compute/functional/detail/macros.hpp>

namespace zr_boost_1_81 {
namespace compute {

BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(acos, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(acosh, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(acospi, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(asin, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(asinh, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(asinpi, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(atan, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(atan2, T (T, T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(atanh, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(atanpi, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(atan2pi, T (T, T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(cbrt, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(ceil, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(copysign, T (T, T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(cos, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(cosh, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(cospi, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(erf, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(erfc, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(exp, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(exp2, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(exp10, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(expm1, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(fabs, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(fdim, T (T, T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(floor, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(fma, T (T, T, T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(fmax, T (T, T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(fmin, T (T, T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(fmod, T (T, T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(hypot, T (T, T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(ilogb, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(lgamma, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(log, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(log2, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(log10, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(log1p, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(logb, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(mad, T (T, T, T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(nextafter, T (T, T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(pow, T (T, T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(pown, T (T, T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(powr, T (T, T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(remainder, T (T, T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(rint, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(rootn, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(round, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(rsqrt, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(sin, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(sinh, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(sinpi, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(sqrt, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(tan, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(tanh, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(tanpi, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(tgamma, T (T), class T)
BOOST_COMPUTE_DECLARE_BUILTIN_FUNCTION(trunc, T (T), class T)

} // end compute namespace
} // end boost namespace

#endif // BOOST_COMPUTE_FUNCTIONAL_MATH_HPP
