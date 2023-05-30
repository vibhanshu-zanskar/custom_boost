// Boost.Geometry (aka GGL, Generic Geometry Library)

// Copyright (c) 2010-2012 Barend Gehrels, Amsterdam, the Netherlands.

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_GEOMETRIES_ADAPTED_BOOST_POLYGON_BOX_HPP
#define BOOST_GEOMETRY_GEOMETRIES_ADAPTED_BOOST_POLYGON_BOX_HPP

// Adapts Geometries from Boost.Polygon for usage in Boost.Geometry
// zr_boost_1_81::polygon::rectangle_data -> zr_boost_1_81::geometry::box


#include <boost/polygon/polygon.hpp>

#include <boost/geometry/core/access.hpp>
#include <boost/geometry/core/cs.hpp>
#include <boost/geometry/core/coordinate_dimension.hpp>
#include <boost/geometry/core/coordinate_type.hpp>
#include <boost/geometry/core/tags.hpp>


namespace zr_boost_1_81 { namespace geometry
{


#ifndef DOXYGEN_NO_TRAITS_SPECIALIZATIONS
namespace traits
{


template <typename CoordinateType>
struct tag<zr_boost_1_81::polygon::rectangle_data<CoordinateType> >
{
    typedef box_tag type;
};


template <typename CoordinateType>
struct point_type<zr_boost_1_81::polygon::rectangle_data<CoordinateType> >
{
    // Not sure what to do here. Boost.Polygon's rectangle does NOT define its
    // point_type (but uses it...)
    typedef zr_boost_1_81::polygon::point_data<CoordinateType> type;
};


template <typename CoordinateType>
struct indexed_access
<
    zr_boost_1_81::polygon::rectangle_data<CoordinateType>,
    min_corner, 0
>
{
    typedef zr_boost_1_81::polygon::rectangle_data<CoordinateType> box_type;

    static inline CoordinateType get(box_type const& b)
    {
        return zr_boost_1_81::polygon::xl(b);
    }

    static inline void set(box_type& b, CoordinateType const& value)
    {
        zr_boost_1_81::polygon::xl(b, value);
    }
};


template <typename CoordinateType>
struct indexed_access
<
    zr_boost_1_81::polygon::rectangle_data<CoordinateType>,
    min_corner, 1
>
{
    typedef zr_boost_1_81::polygon::rectangle_data<CoordinateType> box_type;

    static inline CoordinateType get(box_type const& b)
    {
        return zr_boost_1_81::polygon::yl(b);
    }

    static inline void set(box_type& b, CoordinateType const& value)
    {
        zr_boost_1_81::polygon::yl(b, value);
    }
};


template <typename CoordinateType>
struct indexed_access
<
    zr_boost_1_81::polygon::rectangle_data<CoordinateType>,
    max_corner, 0
>
{
    typedef zr_boost_1_81::polygon::rectangle_data<CoordinateType> box_type;

    static inline CoordinateType get(box_type const& b)
    {
        return zr_boost_1_81::polygon::xh(b);
    }

    static inline void set(box_type& b, CoordinateType const& value)
    {
        zr_boost_1_81::polygon::xh(b, value);
    }
};


template <typename CoordinateType>
struct indexed_access
<
    zr_boost_1_81::polygon::rectangle_data<CoordinateType>,
    max_corner, 1
>
{
    typedef zr_boost_1_81::polygon::rectangle_data<CoordinateType> box_type;

    static inline CoordinateType get(box_type const& b)
    {
        return zr_boost_1_81::polygon::yh(b);
    }

    static inline void set(box_type& b, CoordinateType const& value)
    {
        zr_boost_1_81::polygon::yh(b, value);
    }
};


} // namespace traits
#endif // DOXYGEN_NO_TRAITS_SPECIALIZATIONS


}} // namespace zr_boost_1_81::geometry


#endif // BOOST_GEOMETRY_GEOMETRIES_ADAPTED_BOOST_POLYGON_BOX_HPP
