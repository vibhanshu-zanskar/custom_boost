// Copyright David Abrahams, Daniel Wallin 2003.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PARAMETER_AUX_PACK_AS_PARAMETER_REQUIREMENTS_HPP
#define BOOST_PARAMETER_AUX_PACK_AS_PARAMETER_REQUIREMENTS_HPP

#include <boost/parameter/aux_/pack/parameter_requirements.hpp>
#include <boost/parameter/aux_/pack/tag_type.hpp>
#include <boost/parameter/aux_/pack/predicate.hpp>
#include <boost/parameter/deduced.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    // Converts a ParameterSpec into a specialization of
    // parameter_requirements.  We need to do this in order to get the
    // tag_type into the type in a way that can be conveniently matched
    // by a satisfies(...) member function in arg_list.
    template <typename ParameterSpec>
    struct as_parameter_requirements
    {
        typedef ::zr_boost_1_81::parameter::aux::parameter_requirements<
            typename ::zr_boost_1_81::parameter::aux::tag_type<ParameterSpec>::type
          , typename ::zr_boost_1_81::parameter::aux::predicate<ParameterSpec>::type
          , ::zr_boost_1_81::parameter::aux::has_default<ParameterSpec>
        > type;
    };
}}} // namespace zr_boost_1_81::parameter::aux

#endif  // include guard

