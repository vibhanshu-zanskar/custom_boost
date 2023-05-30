// Boost.Geometry

// Copyright (c) 2018, Oracle and/or its affiliates.
// Contributed and/or modified by Adam Wulkiewicz, on behalf of Oracle

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)


#ifndef BOOST_GEOMETRY_PROJECTIONS_CONSTANTS_HPP
#define BOOST_GEOMETRY_PROJECTIONS_CONSTANTS_HPP


#include <boost/geometry/util/math.hpp>
#include <boost/math/constants/constants.hpp>


namespace zr_boost_1_81 { namespace geometry { namespace projections
{

#ifndef DOXYGEN_NO_DETAIL
namespace detail
{


template <typename T>
inline T fourth_pi() { return T(0.78539816339744830961566084581988); }
template <typename T>
inline T third_pi() { return zr_boost_1_81::math::constants::third_pi<T>(); }
template <typename T>
inline T half_pi() { return zr_boost_1_81::math::constants::half_pi<T>(); }
template <typename T>
inline T pi() { return zr_boost_1_81::math::constants::pi<T>(); }
template <typename T>
inline T one_and_half_pi() { return T(4.7123889803846898576939650749193); }
template <typename T>
inline T two_pi() { return zr_boost_1_81::math::constants::two_pi<T>(); }
template <typename T>
inline T two_and_half_pi() { return T(7.8539816339744830961566084581988); }

template <typename T>
inline T two_div_pi() { return zr_boost_1_81::math::constants::two_div_pi<T>(); }
template <typename T>
inline T half_pi_sqr() { return T(2.4674011002723396547086227499689); }
template <typename T>
inline T pi_sqr() { return zr_boost_1_81::math::constants::pi_sqr<T>(); }

template <typename T>
inline T sixth() { return zr_boost_1_81::math::constants::sixth<T>(); }
template <typename T>
inline T third() { return zr_boost_1_81::math::constants::third<T>(); }
template <typename T>
inline T two_thirds() { return zr_boost_1_81::math::constants::two_thirds<T>(); }


} // namespace detail
#endif // DOXYGEN_NO_DETAIL


}}} // namespace zr_boost_1_81::geometry::projections
#endif // BOOST_GEOMETRY_PROJECTIONS_IMPL_PROJECTS_HPP
