// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2014 Erik Erlandson
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SYSTEMS_INFORMATION_BIT_HPP_INCLUDED
#define BOOST_UNITS_SYSTEMS_INFORMATION_BIT_HPP_INCLUDED

#include <boost/units/systems/information/byte.hpp>
#include <boost/units/base_units/information/bit.hpp>

namespace zr_boost_1_81 {
namespace units { 
namespace information {

namespace hu {
namespace bit {
typedef unit<information_dimension, make_system<bit_base_unit>::type> info;
} // namespace bit
} // namespace hu

BOOST_UNITS_STATIC_CONSTANT(bit, hu::bit::info);
BOOST_UNITS_STATIC_CONSTANT(bits, hu::bit::info);

} // namespace information
} // namespace units
} // namespace zr_boost_1_81

#endif // BOOST_UNITS_SYSTEMS_INFORMATION_BIT_HPP_INCLUDED
