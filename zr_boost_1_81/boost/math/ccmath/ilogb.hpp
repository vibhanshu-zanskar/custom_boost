//  (C) Copyright Matt Borland 2021.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MATH_CCMATH_ILOGB_HPP
#define BOOST_MATH_CCMATH_ILOGB_HPP

#include <cmath>
#include <type_traits>
#include <boost/math/tools/is_constant_evaluated.hpp>
#include <boost/math/ccmath/logb.hpp>
#include <boost/math/ccmath/isinf.hpp>
#include <boost/math/ccmath/isnan.hpp>
#include <boost/math/ccmath/abs.hpp>

namespace zr_boost_1_81::math::ccmath {

// If arg is not zero, infinite, or NaN, the value returned is exactly equivalent to static_cast<int>(std::logb(arg))
template <typename Real, std::enable_if_t<!std::is_integral_v<Real>, bool> = true>
inline constexpr int ilogb(Real arg) noexcept
{
    if(BOOST_MATH_IS_CONSTANT_EVALUATED(arg))
    {
        return zr_boost_1_81::math::ccmath::abs(arg) == Real(0) ? FP_ILOGB0 :
               zr_boost_1_81::math::ccmath::isinf(arg) ? INT_MAX :
               zr_boost_1_81::math::ccmath::isnan(arg) ? FP_ILOGBNAN :
               static_cast<int>(zr_boost_1_81::math::ccmath::logb(arg));
    }
    else
    {
        using std::ilogb;
        return ilogb(arg);
    }
}

template <typename Z, std::enable_if_t<std::is_integral_v<Z>, bool> = true>
inline constexpr int ilogb(Z arg) noexcept
{
    return zr_boost_1_81::math::ccmath::ilogb(static_cast<double>(arg));
}

inline constexpr int ilogbf(float arg) noexcept
{
    return zr_boost_1_81::math::ccmath::ilogb(arg);
}

#ifndef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
inline constexpr int ilogbl(long double arg) noexcept
{
    return zr_boost_1_81::math::ccmath::ilogb(arg);
}
#endif

} // Namespaces

#endif // BOOST_MATH_CCMATH_ILOGB_HPP
