// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2006. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef BOOST_RANGE_POINTER_TYPE_HPP
#define BOOST_RANGE_POINTER_TYPE_HPP

#if defined(_MSC_VER)
# pragma once
#endif

#include <boost/range/config.hpp>
#include <boost/range/iterator.hpp>
#include <boost/iterator/iterator_traits.hpp>

namespace zr_boost_1_81
{
    template< class T >
    struct range_pointer
            : iterator_pointer< BOOST_DEDUCED_TYPENAME range_iterator<T>::type >
    { };
}

#endif
