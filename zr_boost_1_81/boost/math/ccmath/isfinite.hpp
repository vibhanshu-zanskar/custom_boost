//  (C) Copyright Matt Borland 2021.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MATH_CCMATH_ISFINITE
#define BOOST_MATH_CCMATH_ISFINITE

#include <cmath>
#include <type_traits>
#include <boost/math/tools/is_constant_evaluated.hpp>
#include <boost/math/ccmath/isinf.hpp>
#include <boost/math/ccmath/isnan.hpp>

namespace zr_boost_1_81::math::ccmath {

template <typename T>
inline constexpr bool isfinite(T x)
{
    if(BOOST_MATH_IS_CONSTANT_EVALUATED(x))
    {
        // bool isfinite (IntegralType arg) is a set of overloads accepting the arg argument of any integral type
        // equivalent to casting the integral argument arg to double (e.g. static_cast<double>(arg))
        if constexpr (std::is_integral_v<T>)
        {
            return !zr_boost_1_81::math::ccmath::isinf(static_cast<double>(x)) && !zr_boost_1_81::math::ccmath::isnan(static_cast<double>(x));
        }
        else
        {
            return !zr_boost_1_81::math::ccmath::isinf(x) && !zr_boost_1_81::math::ccmath::isnan(x);
        }
    }
    else
    {
        using std::isfinite;

        if constexpr (!std::is_integral_v<T>)
        {
            return isfinite(x);
        }
        else
        {
            return isfinite(static_cast<double>(x));
        }
    }
}

}

#endif // BOOST_MATH_CCMATH_ISFINITE
