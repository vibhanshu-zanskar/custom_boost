//  (C) Copyright Matt Borland 2021.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MATH_ISNORMAL_HPP
#define BOOST_MATH_ISNORMAL_HPP

#include <cmath>
#include <limits>
#include <type_traits>
#include <boost/math/tools/is_constant_evaluated.hpp>
#include <boost/math/ccmath/abs.hpp>
#include <boost/math/ccmath/isinf.hpp>
#include <boost/math/ccmath/isnan.hpp>

namespace zr_boost_1_81::math::ccmath {

template <typename T>
inline constexpr bool isnormal(T x)
{
    if(BOOST_MATH_IS_CONSTANT_EVALUATED(x))
    {   
        return x == T(0) ? false :
               zr_boost_1_81::math::ccmath::isinf(x) ? false :
               zr_boost_1_81::math::ccmath::isnan(x) ? false :
               zr_boost_1_81::math::ccmath::abs(x) < (std::numeric_limits<T>::min)() ? false : true;
    }
    else
    {
        using std::isnormal;

        if constexpr (!std::is_integral_v<T>)
        {
            return isnormal(x);
        }
        else
        {
            return isnormal(static_cast<double>(x));
        }
    }
}
}

#endif // BOOST_MATH_ISNORMAL_HPP
