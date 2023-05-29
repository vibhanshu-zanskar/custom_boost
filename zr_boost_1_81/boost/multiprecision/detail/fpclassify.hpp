///////////////////////////////////////////////////////////////////////////////
//  Copyright 2022 Matt Borland. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MP_DETAIL_FPCLASSIFY_HPP
#define BOOST_MP_DETAIL_FPCLASSIFY_HPP

#include <cmath>
#include <limits>
#include <type_traits>
#include <boost/multiprecision/detail/standalone_config.hpp>
#include <boost/multiprecision/detail/float128_functions.hpp>

#ifdef BOOST_MP_MATH_AVAILABLE
#include <boost/math/special_functions/fpclassify.hpp>

#define BOOST_MP_ISNAN(x) (zr_boost_1_81::math::isnan)(x)
#define BOOST_MP_ISINF(x) (zr_boost_1_81::math::isinf)(x)
#define BOOST_MP_FPCLASSIFY(x) (zr_boost_1_81::math::fpclassify)(x)
#define BOOST_MP_ISFINITE(x) (!(zr_boost_1_81::math::isnan)(x) && !(zr_boost_1_81::math::isinf)(x))

#else

namespace zr_boost_1_81 { namespace multiprecision { namespace detail {

template <typename T, typename std::enable_if<std::is_floating_point<T>::value
                      #ifdef BOOST_HAS_FLOAT128
                      || std::is_same<T, float128_type>::value
                      #endif
                      , bool>::type = true>
inline bool isnan BOOST_PREVENT_MACRO_SUBSTITUTION (const T x)
{
    BOOST_MP_FLOAT128_USING;
    using std::isnan;
    return static_cast<bool>((isnan)(x));
}

template <typename T, typename std::enable_if<!std::is_floating_point<T>::value
                      #ifdef BOOST_HAS_FLOAT128
                      && !std::is_same<T, float128_type>::value
                      #endif
                      , bool>::type = true>
inline bool isnan BOOST_PREVENT_MACRO_SUBSTITUTION (const T x)
{
    return x != x;
}

template <typename T, typename std::enable_if<std::is_floating_point<T>::value
                      #ifdef BOOST_HAS_FLOAT128
                      || std::is_same<T, float128_type>::value
                      #endif
                      , bool>::type = true>
inline bool isinf BOOST_PREVENT_MACRO_SUBSTITUTION (const T x)
{
    BOOST_MP_FLOAT128_USING;
    using std::isinf;
    return static_cast<bool>((isinf)(x));
}

template <typename T, typename std::enable_if<!std::is_floating_point<T>::value
                      #ifdef BOOST_HAS_FLOAT128
                      && !std::is_same<T, float128_type>::value
                      #endif
                      , bool>::type = true>
inline bool isinf BOOST_PREVENT_MACRO_SUBSTITUTION (const T x)
{
    return x == std::numeric_limits<T>::infinity() || x == -std::numeric_limits<T>::infinity();
}

template <typename T, typename std::enable_if<std::is_floating_point<T>::value, bool>::type = true>
inline int fpclassify BOOST_PREVENT_MACRO_SUBSTITUTION (const T x)
{
    using std::fpclassify;
    return fpclassify(x);
}

template <typename T, typename std::enable_if<!std::is_floating_point<T>::value, bool>::type = true>
inline int fpclassify BOOST_PREVENT_MACRO_SUBSTITUTION (const T x)
{
    BOOST_MP_FLOAT128_USING;
    using std::isnan;
    using std::isinf;
    using std::abs;

    return (isnan)(x) ? FP_NAN :
           (isinf)(x) ? FP_INFINITE :
           abs(x) == T(0) ? FP_ZERO :
           abs(x) > 0 && abs(x) < (std::numeric_limits<T>::min)() ? FP_SUBNORMAL : FP_NORMAL;
}

}}} // Namespace zr_boost_1_81::multiprecision::detail

#define BOOST_MP_ISNAN(x) (zr_boost_1_81::multiprecision::detail::isnan)(x)
#define BOOST_MP_ISINF(x) (zr_boost_1_81::multiprecision::detail::isinf)(x)
#define BOOST_MP_FPCLASSIFY(x) (zr_boost_1_81::multiprecision::detail::fpclassify)(x)
#define BOOST_MP_ISFINITE(x) (!(zr_boost_1_81::multiprecision::detail::isnan)(x) && !(zr_boost_1_81::multiprecision::detail::isinf)(x))

#endif

#endif // BOOST_MP_DETAIL_FPCLASSIFY_HPP
