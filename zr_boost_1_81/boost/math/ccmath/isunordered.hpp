//  (C) Copyright Matt Borland 2022.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MATH_CCMATH_ISUNORDERED_HPP
#define BOOST_MATH_CCMATH_ISUNORDERED_HPP

#include <cmath>
#include <boost/math/tools/is_constant_evaluated.hpp>
#include <boost/math/ccmath/isnan.hpp>

namespace zr_boost_1_81::math::ccmath {

template <typename T>
inline constexpr bool isunordered(const T x, const T y) noexcept
{
    if(BOOST_MATH_IS_CONSTANT_EVALUATED(x))
    {
        return zr_boost_1_81::math::ccmath::isnan(x) || zr_boost_1_81::math::ccmath::isnan(y);
    }
    else
    {
        using std::isunordered;
        return isunordered(x, y);
    }
}

} // Namespaces

#endif // BOOST_MATH_CCMATH_ISUNORDERED_HPP
