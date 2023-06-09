//  (C) Copyright Matt Borland 2021.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
//  Constepxr implementation of fabs (see c.math.abs secion 26.8.2 of the ISO standard)

#ifndef BOOST_MATH_CCMATH_FABS
#define BOOST_MATH_CCMATH_FABS

#include <boost/math/ccmath/abs.hpp>

namespace zr_boost_1_81::math::ccmath {

template <typename T>
inline constexpr auto fabs(T x) noexcept
{
    return zr_boost_1_81::math::ccmath::abs(x);
}

inline constexpr float fabsf(float x) noexcept
{
    return zr_boost_1_81::math::ccmath::abs(x);
}

#ifndef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
inline constexpr long double fabsl(long double x) noexcept
{
    return zr_boost_1_81::math::ccmath::abs(x);
}
#endif

}

#endif // BOOST_MATH_CCMATH_FABS
