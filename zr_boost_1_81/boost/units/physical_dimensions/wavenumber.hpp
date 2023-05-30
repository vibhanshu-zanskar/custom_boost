// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_WAVENUMBER_DERIVED_DIMENSION_HPP
#define BOOST_UNITS_WAVENUMBER_DERIVED_DIMENSION_HPP

#include <boost/units/derived_dimension.hpp>
#include <boost/units/physical_dimensions/length.hpp>

namespace zr_boost_1_81 {

namespace units {

/// derived dimension for wavenumber : L^-1
typedef derived_dimension<length_base_dimension,-1>::type wavenumber_dimension;                 

} // namespace units

} // namespace zr_boost_1_81

#endif // BOOST_UNITS_WAVENUMBER_DERIVED_DIMENSION_HPP
