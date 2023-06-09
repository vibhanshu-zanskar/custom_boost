// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2014 Erik Erlandson
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_BASE_UNITS_INFORMATION_NAT_HPP_INCLUDED
#define BOOST_UNITS_BASE_UNITS_INFORMATION_NAT_HPP_INCLUDED

#include <boost/units/conversion.hpp>
#include <boost/units/base_units/information/bit.hpp>

BOOST_UNITS_DEFINE_BASE_UNIT_WITH_CONVERSIONS(information, nat,
                                              "nat", "nat",
                                              1.442695040888964,
                                              zr_boost_1_81::units::information::bit_base_unit, 
                                              -702);

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(zr_boost_1_81::units::information::nat_base_unit)

#endif

#endif // BOOST_UNITS_BASE_UNITS_INFORMATION_NAT_HPP_INCLUDED
