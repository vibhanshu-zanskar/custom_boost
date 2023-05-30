// Boost.Geometry (aka GGL, Generic Geometry Library)

// Copyright (c) 2010-2012 Barend Gehrels, Amsterdam, the Netherlands.

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_GEOMETRIES_ADAPTED_BOOST_POLYGON_RING_HPP
#define BOOST_GEOMETRY_GEOMETRIES_ADAPTED_BOOST_POLYGON_RING_HPP

// Adapts Geometries from Boost.Polygon for usage in Boost.Geometry
// zr_boost_1_81::polygon::polygon_data -> zr_boost_1_81::geometry::ring

#include <cstddef>
#include <boost/polygon/polygon.hpp>

#include <boost/geometry/core/access.hpp>
#include <boost/geometry/core/cs.hpp>
#include <boost/geometry/core/coordinate_dimension.hpp>
#include <boost/geometry/core/coordinate_type.hpp>
#include <boost/geometry/core/mutable_range.hpp>
#include <boost/geometry/core/tags.hpp>


#ifndef DOXYGEN_NO_TRAITS_SPECIALIZATIONS

namespace zr_boost_1_81 { namespace geometry
{

namespace traits
{

template <typename CoordinateType>
struct tag<zr_boost_1_81::polygon::polygon_data<CoordinateType> >
{
    typedef ring_tag type;
};

template <typename CoordinateType>
struct clear<zr_boost_1_81::polygon::polygon_data<CoordinateType> >
{
    static inline void apply(zr_boost_1_81::polygon::polygon_data<CoordinateType>& data)
    {
        // There is no "clear" function but we can assign
        // a newly (and therefore empty) constructed polygon
        zr_boost_1_81::polygon::assign(data, zr_boost_1_81::polygon::polygon_data<CoordinateType>());
    }
};

template <typename CoordinateType>
struct push_back<zr_boost_1_81::polygon::polygon_data<CoordinateType> >
{
    typedef zr_boost_1_81::polygon::point_data<CoordinateType> point_type;

    static inline void apply(zr_boost_1_81::polygon::polygon_data<CoordinateType>& data,
         point_type const& point)
    {
        // Boost.Polygon's polygons are not appendable. So create a temporary vector,
        // add a record and set it to the original. Of course: this is not efficient.
        // But there seems no other way (without using a wrapper)
        std::vector<point_type> temporary_vector
            (
                zr_boost_1_81::polygon::begin_points(data),
                zr_boost_1_81::polygon::end_points(data)
            );
        temporary_vector.push_back(point);
        data.set(temporary_vector.begin(), temporary_vector.end());
    }
};

template <typename CoordinateType>
struct resize<zr_boost_1_81::polygon::polygon_data<CoordinateType> >
{
    typedef zr_boost_1_81::polygon::point_data<CoordinateType> point_type;

    static inline void apply(zr_boost_1_81::polygon::polygon_data<CoordinateType>& data,
                             std::size_t new_size)
    {
        // Boost.Polygon's polygons are not resizable. So create a temporary vector,
        // resize it and set it to the original. Of course: this is not efficient.
        // But there seems no other way (without using a wrapper)
        std::vector<point_type> temporary_vector
            (
                zr_boost_1_81::polygon::begin_points(data),
                zr_boost_1_81::polygon::end_points(data)
            );
        temporary_vector.resize(new_size);
        data.set(temporary_vector.begin(), temporary_vector.end());
    }
};


} // namespace traits

}} // namespace zr_boost_1_81::geometry


// Adapt Boost.Polygon's polygon_data to Boost.Range
// This just translates to
// polygon_data.begin() and polygon_data.end()
namespace zr_boost_1_81
{
    template<typename CoordinateType>
    struct range_mutable_iterator<zr_boost_1_81::polygon::polygon_data<CoordinateType> >
    {
        typedef typename zr_boost_1_81::polygon::polygon_traits
            <
                zr_boost_1_81::polygon::polygon_data<CoordinateType>
            >::iterator_type type;
    };

    template<typename CoordinateType>
    struct range_const_iterator<zr_boost_1_81::polygon::polygon_data<CoordinateType> >
    {
        typedef typename zr_boost_1_81::polygon::polygon_traits
            <
                zr_boost_1_81::polygon::polygon_data<CoordinateType>
            >::iterator_type type;
    };

    template<typename CoordinateType>
    struct range_size<zr_boost_1_81::polygon::polygon_data<CoordinateType> >
    {
        typedef std::size_t type;
    };

} // namespace zr_boost_1_81


// Support Boost.Polygon's polygon_data for Boost.Range ADP
namespace zr_boost_1_81 { namespace polygon
{

template<typename CoordinateType>
inline typename polygon_traits
        <
            polygon_data<CoordinateType>
        >::iterator_type range_begin(polygon_data<CoordinateType>& polygon)
{
    return polygon.begin();
}

template<typename CoordinateType>
inline typename polygon_traits
        <
            polygon_data<CoordinateType>
        >::iterator_type range_begin(polygon_data<CoordinateType> const& polygon)
{
    return polygon.begin();
}

template<typename CoordinateType>
inline typename polygon_traits
        <
            polygon_data<CoordinateType>
        >::iterator_type range_end(polygon_data<CoordinateType>& polygon)
{
    return polygon.end();
}

template<typename CoordinateType>
inline typename polygon_traits
        <
            polygon_data<CoordinateType>
        >::iterator_type range_end(polygon_data<CoordinateType> const& polygon)
{
    return polygon.end();
}

template<typename CoordinateType>
inline std::size_t range_calculate_size(polygon_data<CoordinateType> const& polygon)
{
    return polygon.size();
}

}}

#endif // DOXYGEN_NO_TRAITS_SPECIALIZATIONS


#endif // BOOST_GEOMETRY_GEOMETRIES_ADAPTED_BOOST_POLYGON_RING_HPP
