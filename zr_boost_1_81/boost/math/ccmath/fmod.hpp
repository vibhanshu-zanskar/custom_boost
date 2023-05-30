//  (C) Copyright Matt Borland 2021 - 2022.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MATH_CCMATH_FMOD_HPP
#define BOOST_MATH_CCMATH_FMOD_HPP

#include <cmath>
#include <cstdint>
#include <limits>
#include <type_traits>
#include <boost/math/tools/promotion.hpp>
#include <boost/math/tools/is_constant_evaluated.hpp>
#include <boost/math/ccmath/abs.hpp>
#include <boost/math/ccmath/isinf.hpp>
#include <boost/math/ccmath/isnan.hpp>
#include <boost/math/ccmath/isfinite.hpp>

namespace zr_boost_1_81::math::ccmath {

namespace detail {

template <typename T>
constexpr T fmod_impl(T x, T y)
{
    if (x == y)
    {
        return static_cast<T>(0);
    }
    else
    {
        while (x >= y)
        {
            x -= y;
        }

        return static_cast<T>(x);
    }
}

} // Namespace detail

template <typename Real, std::enable_if_t<!std::is_integral_v<Real>, bool> = true>
constexpr Real fmod(Real x, Real y)
{
    if(BOOST_MATH_IS_CONSTANT_EVALUATED(x))
    {
        if (zr_boost_1_81::math::ccmath::abs(x) == static_cast<Real>(0) && y != static_cast<Real>(0))
        {
            return x;
        }
        else if (zr_boost_1_81::math::ccmath::isinf(x) && !zr_boost_1_81::math::ccmath::isnan(y))
        {
            return std::numeric_limits<Real>::quiet_NaN();
        }
        else if (zr_boost_1_81::math::ccmath::abs(y) == static_cast<Real>(0) && !zr_boost_1_81::math::ccmath::isnan(x))
        {
            return std::numeric_limits<Real>::quiet_NaN();
        }
        else if (zr_boost_1_81::math::ccmath::isinf(y) && zr_boost_1_81::math::ccmath::isfinite(x))
        {
            return x;
        }
        else if (zr_boost_1_81::math::ccmath::isnan(x))
        {
            return x;
        }
        else if (zr_boost_1_81::math::ccmath::isnan(y))
        {
            return y;
        }

        return zr_boost_1_81::math::ccmath::detail::fmod_impl<Real>(x, y);
    }
    else
    {
        using std::fmod;
        return fmod(x, y);
    }
}

template <typename T1, typename T2>
constexpr auto fmod(T1 x, T2 y)
{
    if(BOOST_MATH_IS_CONSTANT_EVALUATED(x))
    {
        using promoted_type = zr_boost_1_81::math::tools::promote_args_t<T1, T2>;
        return zr_boost_1_81::math::ccmath::fmod(promoted_type(x), promoted_type(y));
    }
    else
    {
        using std::fmod;
        return fmod(x, y);
    }
}

constexpr float fmodf(float x, float y)
{
    return zr_boost_1_81::math::ccmath::fmod(x, y);
}

#ifndef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
constexpr long double fmodl(long double x, long double y)
{
    return zr_boost_1_81::math::ccmath::fmod(x, y);
}
#endif

} // Namespaces

#endif // BOOST_MATH_CCMATH_FMOD_HPP
