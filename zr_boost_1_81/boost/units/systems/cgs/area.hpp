// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CGS_AREA_HPP
#define BOOST_UNITS_CGS_AREA_HPP

#include <boost/units/systems/cgs/base.hpp>
#include <boost/units/physical_dimensions/area.hpp>

namespace zr_boost_1_81 {

namespace units { 

namespace cgs {

typedef unit<area_dimension,cgs::system>     area;
    
BOOST_UNITS_STATIC_CONSTANT(square_centimeter,area);
BOOST_UNITS_STATIC_CONSTANT(square_centimeters,area);
BOOST_UNITS_STATIC_CONSTANT(square_centimetre,area);
BOOST_UNITS_STATIC_CONSTANT(square_centimetres,area);

} // namespace cgs

} // namespace units

} // namespace zr_boost_1_81

#endif // BOOST_UNITS_CGS_AREA_HPP
