// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_SECOND_BASE_UNIT_HPP
#define BOOST_UNITS_SI_SECOND_BASE_UNIT_HPP

#include <string>

#include <boost/units/config.hpp>
#include <boost/units/base_unit.hpp>
#include <boost/units/physical_dimensions/time.hpp>

namespace zr_boost_1_81 {

namespace units {

namespace si {

struct second_base_unit : public base_unit<second_base_unit, time_dimension, -7>
{
    static std::string name()   { return("second"); }
    static std::string symbol() { return("s"); }
};

} // namespace si

} // namespace units

} // namespace zr_boost_1_81

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(zr_boost_1_81::units::si::second_base_unit)

#endif

//#include <boost/units/base_units/detail/conversions.hpp>

#endif // BOOST_UNITS_SI_SECOND_BASE_UNIT_HPP
