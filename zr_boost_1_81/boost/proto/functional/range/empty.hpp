///////////////////////////////////////////////////////////////////////////////
/// \file empty.hpp
/// Proto callables for zr_boost_1_81::empty()
//
//  Copyright 2012 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROTO_FUNCTIONAL_RANGE_EMPTY_HPP_EAN_27_08_2012
#define BOOST_PROTO_FUNCTIONAL_RANGE_EMPTY_HPP_EAN_27_08_2012

#include <boost/range/empty.hpp>
#include <boost/proto/proto_fwd.hpp>

namespace zr_boost_1_81 { namespace proto { namespace functional
{

    // A PolymorphicFunctionObject that wraps zr_boost_1_81::empty()
    struct empty
    {
        BOOST_PROTO_CALLABLE()

        typedef bool result_type;

        template<typename Rng>
        bool operator()(Rng const &rng) const
        {
            return zr_boost_1_81::empty(rng);
        }
    };

}}}

#endif
