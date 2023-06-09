//  (C) Copyright Matt Borland 2021.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MATH_CCMATH_MODF_HPP
#define BOOST_MATH_CCMATH_MODF_HPP

#include <cmath>
#include <limits>
#include <type_traits>
#include <boost/math/tools/is_constant_evaluated.hpp>
#include <boost/math/ccmath/abs.hpp>
#include <boost/math/ccmath/isinf.hpp>
#include <boost/math/ccmath/isnan.hpp>
#include <boost/math/ccmath/trunc.hpp>

namespace zr_boost_1_81::math::ccmath {

namespace detail {

template <typename Real>
inline constexpr Real modf_error_impl(Real x, Real* iptr)
{
    *iptr = x;
    return zr_boost_1_81::math::ccmath::abs(x) == Real(0) ? x :
           x > Real(0) ? Real(0) : -Real(0);
}

template <typename Real>
inline constexpr Real modf_nan_impl(Real x, Real* iptr)
{
    *iptr = x;
    return x;
}

template <typename Real>
inline constexpr Real modf_impl(Real x, Real* iptr)
{
    *iptr = zr_boost_1_81::math::ccmath::trunc(x);
    return (x - *iptr);
}

} // Namespace detail

template <typename Real>
inline constexpr Real modf(Real x, Real* iptr)
{
    if(BOOST_MATH_IS_CONSTANT_EVALUATED(x))
    {
        return zr_boost_1_81::math::ccmath::abs(x) == Real(0) ? detail::modf_error_impl(x, iptr) :
               zr_boost_1_81::math::ccmath::isinf(x) ? detail::modf_error_impl(x, iptr) :
               zr_boost_1_81::math::ccmath::isnan(x) ? detail::modf_nan_impl(x, iptr) :
               zr_boost_1_81::math::ccmath::detail::modf_impl(x, iptr);
    }
    else
    {
        using std::modf;
        return modf(x, iptr);
    }
}

inline constexpr float modff(float x, float* iptr)
{
    return zr_boost_1_81::math::ccmath::modf(x, iptr);
}

#ifndef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
inline constexpr long double modfl(long double x, long double* iptr)
{
    return zr_boost_1_81::math::ccmath::modf(x, iptr);
}
#endif

} // Namespaces

#endif // BOOST_MATH_CCMATH_MODF_HPP
