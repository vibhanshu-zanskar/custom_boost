//  (C) Copyright Matt Borland 2021.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MATH_CCMATH_TRUNC_HPP
#define BOOST_MATH_CCMATH_TRUNC_HPP

#include <cmath>
#include <type_traits>
#include <boost/math/tools/is_constant_evaluated.hpp>
#include <boost/math/ccmath/abs.hpp>
#include <boost/math/ccmath/isinf.hpp>
#include <boost/math/ccmath/isnan.hpp>
#include <boost/math/ccmath/floor.hpp>
#include <boost/math/ccmath/ceil.hpp>

namespace zr_boost_1_81::math::ccmath {

namespace detail {

template <typename T>
inline constexpr T trunc_impl(T arg) noexcept
{
    return (arg > 0) ? zr_boost_1_81::math::ccmath::floor(arg) : zr_boost_1_81::math::ccmath::ceil(arg);
}

} // Namespace detail

template <typename Real, std::enable_if_t<!std::is_integral_v<Real>, bool> = true>
inline constexpr Real trunc(Real arg) noexcept
{
    if(BOOST_MATH_IS_CONSTANT_EVALUATED(arg))
    {
        return zr_boost_1_81::math::ccmath::abs(arg) == Real(0) ? arg :
               zr_boost_1_81::math::ccmath::isinf(arg) ? arg :
               zr_boost_1_81::math::ccmath::isnan(arg) ? arg :
               zr_boost_1_81::math::ccmath::detail::trunc_impl(arg);
    }
    else
    {
        using std::trunc;
        return trunc(arg);
    }
}

template <typename Z, std::enable_if_t<std::is_integral_v<Z>, bool> = true>
inline constexpr double trunc(Z arg) noexcept
{
    return zr_boost_1_81::math::ccmath::trunc(static_cast<double>(arg));
}

inline constexpr float truncf(float arg) noexcept
{
    return zr_boost_1_81::math::ccmath::trunc(arg);
}

#ifndef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
inline constexpr long double truncl(long double arg) noexcept
{
    return zr_boost_1_81::math::ccmath::trunc(arg);
}
#endif

} // Namespaces

#endif // BOOST_MATH_CCMATH_TRUNC_HPP
