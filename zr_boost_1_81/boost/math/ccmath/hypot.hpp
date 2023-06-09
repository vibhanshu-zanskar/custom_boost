//  (C) Copyright John Maddock 2005-2021.
//  (C) Copyright Matt Borland 2021.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MATH_CCMATH_HYPOT_HPP
#define BOOST_MATH_CCMATH_HYPOT_HPP

#include <cmath>
#include <array>
#include <limits>
#include <type_traits>
#include <boost/math/tools/config.hpp>
#include <boost/math/tools/is_constant_evaluated.hpp>
#include <boost/math/ccmath/sqrt.hpp>
#include <boost/math/ccmath/abs.hpp>
#include <boost/math/ccmath/isinf.hpp>
#include <boost/math/ccmath/isnan.hpp>
#include <boost/math/ccmath/detail/swap.hpp>

namespace zr_boost_1_81::math::ccmath {

namespace detail {

template <typename T>
inline constexpr T hypot_impl(T x, T y) noexcept
{
    x = zr_boost_1_81::math::ccmath::abs(x);
    y = zr_boost_1_81::math::ccmath::abs(y);

    if (y > x)
    {
        zr_boost_1_81::math::ccmath::detail::swap(x, y);
    }

    if(x * std::numeric_limits<T>::epsilon() >= y)
    {
        return x;
    }

    T rat = y / x;
    return x * zr_boost_1_81::math::ccmath::sqrt(1 + rat * rat);
}

} // Namespace detail

template <typename Real, std::enable_if_t<!std::is_integral_v<Real>, bool> = true>
inline constexpr Real hypot(Real x, Real y) noexcept
{
    if(BOOST_MATH_IS_CONSTANT_EVALUATED(x))
    {
        return zr_boost_1_81::math::ccmath::abs(x) == Real(0) ? zr_boost_1_81::math::ccmath::abs(y) :
               zr_boost_1_81::math::ccmath::abs(y) == Real(0) ? zr_boost_1_81::math::ccmath::abs(x) :
               zr_boost_1_81::math::ccmath::isinf(x) ? std::numeric_limits<Real>::infinity() :
               zr_boost_1_81::math::ccmath::isinf(y) ? std::numeric_limits<Real>::infinity() :
               zr_boost_1_81::math::ccmath::isnan(x) ? std::numeric_limits<Real>::quiet_NaN() :
               zr_boost_1_81::math::ccmath::isnan(y) ? std::numeric_limits<Real>::quiet_NaN() :
               zr_boost_1_81::math::ccmath::detail::hypot_impl(x, y);
    }
    else
    {
        using std::hypot;
        return hypot(x, y);
    }
}

template <typename T1, typename T2>
inline constexpr auto hypot(T1 x, T2 y) noexcept
{
    if(BOOST_MATH_IS_CONSTANT_EVALUATED(x))
    {
        // If the type is an integer (e.g. epsilon == 0) then set the epsilon value to 1 so that type is at a minimum 
        // cast to double
        constexpr auto T1p = std::numeric_limits<T1>::epsilon() > 0 ? std::numeric_limits<T1>::epsilon() : 1;
        constexpr auto T2p = std::numeric_limits<T2>::epsilon() > 0 ? std::numeric_limits<T2>::epsilon() : 1;
        
        using promoted_type = 
                              #ifndef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
                              std::conditional_t<T1p <= LDBL_EPSILON && T1p <= T2p, T1,
                              std::conditional_t<T2p <= LDBL_EPSILON && T2p <= T1p, T2,
                              #endif
                              std::conditional_t<T1p <= DBL_EPSILON && T1p <= T2p, T1,
                              std::conditional_t<T2p <= DBL_EPSILON && T2p <= T1p, T2, double
                              #ifndef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
                              >>>>;
                              #else
                              >>;
                              #endif

        return zr_boost_1_81::math::ccmath::hypot(promoted_type(x), promoted_type(y));
    }
    else
    {
        using std::hypot;
        return hypot(x, y);
    }
}

inline constexpr float hypotf(float x, float y) noexcept
{
    return zr_boost_1_81::math::ccmath::hypot(x, y);
}

#ifndef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
inline constexpr long double hypotl(long double x, long double y) noexcept
{
    return zr_boost_1_81::math::ccmath::hypot(x, y);
}
#endif

} // Namespaces

#endif // BOOST_MATH_CCMATH_HYPOT_HPP
