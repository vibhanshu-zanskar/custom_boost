// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SOLID_ANGLE_BASE_DIMENSION_HPP
#define BOOST_UNITS_SOLID_ANGLE_BASE_DIMENSION_HPP

#include <boost/units/config.hpp>
#include <boost/units/base_dimension.hpp>

namespace zr_boost_1_81 {

namespace units { 

/// base dimension of solid angle
struct solid_angle_base_dimension : 
    zr_boost_1_81::units::base_dimension<solid_angle_base_dimension,-1> 
{ };               

} // namespace units

} // namespace zr_boost_1_81

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(zr_boost_1_81::units::solid_angle_base_dimension)

#endif

namespace zr_boost_1_81 {

namespace units {

/// base dimension of solid angle (QS)
typedef solid_angle_base_dimension::dimension_type    solid_angle_dimension;

} // namespace units

} // namespace zr_boost_1_81

#endif // BOOST_UNITS_SOLID_ANGLE_BASE_DIMENSION_HPP
