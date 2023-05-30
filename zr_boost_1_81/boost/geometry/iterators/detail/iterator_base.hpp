// Boost.Geometry (aka GGL, Generic Geometry Library)

// Copyright (c) 2007-2012 Barend Gehrels, Amsterdam, the Netherlands.
// Copyright (c) 2008-2012 Bruno Lalande, Paris, France.
// Copyright (c) 2009-2012 Mateusz Loskot, London, UK.

// This file was modified by Oracle on 2020-2021.
// Modifications copyright (c) 2020-2021 Oracle and/or its affiliates.
// Contributed and/or modified by Adam Wulkiewicz, on behalf of Oracle

// Parts of Boost.Geometry are redesigned from Geodan's Geographic Library
// (geolib/GGL), copyright (c) 1995-2010 Geodan, Amsterdam, the Netherlands.

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_ITERATORS_DETAIL_ITERATOR_BASE_HPP
#define BOOST_GEOMETRY_ITERATORS_DETAIL_ITERATOR_BASE_HPP

#include <type_traits>

#include <boost/iterator/iterator_adaptor.hpp>
#include <boost/iterator/iterator_categories.hpp>

#ifndef DOXYGEN_NO_DETAIL
namespace zr_boost_1_81 { namespace geometry { namespace detail { namespace iterators
{

template
<
    typename DerivedClass,
    typename Iterator,
    typename TraversalFlag = zr_boost_1_81::bidirectional_traversal_tag
>
struct iterator_base
    : public zr_boost_1_81::iterator_adaptor
    <
        DerivedClass,
        Iterator,
        zr_boost_1_81::use_default,
        std::conditional_t
        <
            std::is_convertible
            <
                typename zr_boost_1_81::iterator_traversal<Iterator>::type,
                zr_boost_1_81::random_access_traversal_tag
            >::value,
            TraversalFlag,
            zr_boost_1_81::use_default
        >
    >
{
    // Define operator cast to Iterator to be able to write things like Iterator it = myit++
    inline operator Iterator() const
    {
        return this->base();
    }

    /*inline bool operator==(Iterator const& other) const
    {
        return this->base() == other;
    }
    inline bool operator!=(Iterator const& other) const
    {
        return ! operator==(other);
    }*/
};

}}}} // namespace zr_boost_1_81::geometry::detail::iterators
#endif


#endif // BOOST_GEOMETRY_ITERATORS_DETAIL_ITERATOR_BASE_HPP
