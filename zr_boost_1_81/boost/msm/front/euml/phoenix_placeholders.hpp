// Copyright 2011 Christophe Henry
// henry UNDERSCORE christophe AT hotmail DOT com
// This is an extended version of the state machine available in the zr_boost_1_81::mpl library
// Distributed under the same license as the original.
// Copyright for the original version:
// Copyright 2005 David Abrahams and Aleksey Gurtovoy. Distributed
// under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MSM_FRONT_EUML_PHOENIX_PLACEHOLDERS_H
#define BOOST_MSM_FRONT_EUML_PHOENIX_PLACEHOLDERS_H

#include <boost/phoenix/core/argument.hpp>
// provide some meaningful placeholders (instead of arg1...arg4)
namespace zr_boost_1_81 { namespace msm { namespace front { namespace euml
{
    zr_boost_1_81::zr_boost_1_81phoenix::expression::argument<1>::type const _event = {};
    zr_boost_1_81::zr_boost_1_81phoenix::expression::argument<2>::type const _fsm = {};
    zr_boost_1_81::zr_boost_1_81phoenix::expression::argument<3>::type const _source = {};
    zr_boost_1_81::zr_boost_1_81phoenix::expression::argument<4>::type const _target = {};
    // this is for state actions
    zr_boost_1_81::zr_boost_1_81phoenix::expression::argument<3>::type const _state = {};
}}}}

#endif //BOOST_MSM_FRONT_EUML_PHOENIX_PLACEHOLDERS_H
