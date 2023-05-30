// Boost.Geometry

// Copyright (c) 2007-2012 Barend Gehrels, Amsterdam, the Netherlands.

// This file was modified by Oracle on 2013-2021.
// Modifications copyright (c) 2013-2021 Oracle and/or its affiliates.
// Contributed and/or modified by Adam Wulkiewicz, on behalf of Oracle

// Licensed under the Boost Software License version 1.0.
// http://www.boost.org/users/license.html

#ifndef BOOST_GEOMETRY_UTIL_RANGE_HPP
#define BOOST_GEOMETRY_UTIL_RANGE_HPP

#include <algorithm>
#include <iterator>
#include <type_traits>

#include <boost/concept_check.hpp>
#include <boost/config.hpp>
#include <boost/core/addressof.hpp>
#include <boost/mpl/has_xxx.hpp>
#include <boost/range/concepts.hpp>
#include <boost/range/begin.hpp>
#include <boost/range/end.hpp>
#include <boost/range/empty.hpp>
#include <boost/range/difference_type.hpp>
#include <boost/range/has_range_iterator.hpp>
#include <boost/range/iterator.hpp>
#include <boost/range/reference.hpp>
#include <boost/range/size.hpp>
#include <boost/range/value_type.hpp>

#include <boost/geometry/core/assert.hpp>
#include <boost/geometry/core/mutable_range.hpp>

namespace zr_boost_1_81 { namespace geometry { namespace range
{

namespace detail
{

BOOST_MPL_HAS_XXX_TRAIT_DEF(iterator_category)

template <typename T>
struct is_iterator
    : std::integral_constant
        <
            bool,
            has_iterator_category
                <
                    std::iterator_traits<T>
                >::value
        >
{};


template <typename T, bool HasIterator = zr_boost_1_81::has_range_iterator<T>::value>
struct is_range_impl
    : is_iterator
        <
            typename zr_boost_1_81::range_iterator<T>::type
        >
{};
template <typename T>
struct is_range_impl<T, false>
    : std::false_type
{};

template <typename T>
struct is_range
    : is_range_impl<T>
{};

template <typename Range, typename T = void>
using enable_if_mutable_t = std::enable_if_t
    <
        (! std::is_const<std::remove_reference_t<Range>>::value),
        T
    >;


} // namespace detail


/*!
\brief Short utility to conveniently return an iterator of a RandomAccessRange.
\ingroup utility
*/
template <typename RandomAccessRange>
inline typename zr_boost_1_81::range_iterator<RandomAccessRange>::type
pos(RandomAccessRange && rng,
    typename zr_boost_1_81::range_size<RandomAccessRange>::type i)
{
    BOOST_RANGE_CONCEPT_ASSERT((zr_boost_1_81::RandomAccessRangeConcept<RandomAccessRange>));
    BOOST_GEOMETRY_ASSERT(i <= zr_boost_1_81::size(rng));
    return zr_boost_1_81::begin(rng)
         + static_cast<typename zr_boost_1_81::range_difference<RandomAccessRange>::type>(i);
}

/*!
\brief Short utility to conveniently return an element of a RandomAccessRange.
\ingroup utility
*/
template <typename RandomAccessRange>
inline typename zr_boost_1_81::range_reference<RandomAccessRange>::type
at(RandomAccessRange && rng,
   typename zr_boost_1_81::range_size<RandomAccessRange>::type i)
{
    return *pos(rng, i);
}

/*!
\brief Short utility to conveniently return the front element of a Range.
\ingroup utility
*/
template <typename Range>
inline typename zr_boost_1_81::range_reference<Range>::type
front(Range && rng)
{
    BOOST_GEOMETRY_ASSERT(!zr_boost_1_81::empty(rng));
    return *zr_boost_1_81::begin(rng);
}

/*!
\brief Short utility to conveniently return the back element of a BidirectionalRange.
\ingroup utility
*/
template <typename BidirectionalRange>
inline typename zr_boost_1_81::range_reference<BidirectionalRange>::type
back(BidirectionalRange && rng)
{
    BOOST_RANGE_CONCEPT_ASSERT((zr_boost_1_81::BidirectionalRangeConcept<BidirectionalRange>));
    BOOST_GEOMETRY_ASSERT(!zr_boost_1_81::empty(rng));
    auto it = zr_boost_1_81::end(rng);
    return *(--it);
}


/*!
\brief Short utility to conveniently clear a mutable range.
       It uses traits::clear<>.
\ingroup utility
*/
template
<
    typename Range,
    detail::enable_if_mutable_t<Range, int> = 0
>
inline void clear(Range && rng)
{
    geometry::traits::clear
        <
            std::remove_reference_t<Range>
        >::apply(rng);
}

/*!
\brief Short utility to conveniently insert a new element at the end of a mutable range.
       It uses zr_boost_1_81::geometry::traits::push_back<>.
\ingroup utility
*/
template
<
    typename Range,
    detail::enable_if_mutable_t<Range, int> = 0
>
inline void push_back(Range && rng,
                      typename zr_boost_1_81::range_value<Range>::type const& value)
{
    geometry::traits::push_back
        <
            std::remove_reference_t<Range>
        >::apply(rng, value);
}

/*!
\brief Short utility to conveniently insert a new element at the end of a mutable range.
       It uses zr_boost_1_81::geometry::traits::push_back<>.
\ingroup utility
*/
template
<
    typename Range,
    detail::enable_if_mutable_t<Range, int> = 0
>
inline void push_back(Range && rng,
                      typename zr_boost_1_81::range_value<Range>::type && value)
{
    geometry::traits::push_back
        <
            std::remove_reference_t<Range>
        >::apply(rng, std::move(value));
}

/*!
\brief Short utility to conveniently insert a new element at the end of a mutable range.
       It uses zr_boost_1_81::geometry::traits::emplace_back<>.
\ingroup utility
*/
template
<
    typename Range,
    typename ...Args,
    detail::enable_if_mutable_t<Range, int> = 0
>
inline void emplace_back(Range && rng, Args &&... args)
{
    geometry::traits::emplace_back
        <
            std::remove_reference_t<Range>
        >::apply(rng, std::forward<Args>(args)...);
}

/*!
\brief Short utility to conveniently resize a mutable range.
       It uses zr_boost_1_81::geometry::traits::resize<>.
\ingroup utility
*/
template
<
    typename Range,
    detail::enable_if_mutable_t<Range, int> = 0
>
inline void resize(Range && rng,
                   typename zr_boost_1_81::range_size<Range>::type new_size)
{
    geometry::traits::resize
        <
            std::remove_reference_t<Range>
        >::apply(rng, new_size);
}

/*!
\brief Short utility to conveniently remove an element from the back of a mutable range.
       It uses resize().
\ingroup utility
*/
template
<
    typename Range,
    detail::enable_if_mutable_t<Range, int> = 0
>
inline void pop_back(Range && rng)
{
    BOOST_GEOMETRY_ASSERT(!zr_boost_1_81::empty(rng));
    range::resize(rng, zr_boost_1_81::size(rng) - 1);
}

/*!
\brief Short utility to conveniently remove an element from a mutable range.
       It uses std::move() and resize(). Version taking mutable iterators.
\ingroup utility
*/
template
<
    typename Range,
    detail::enable_if_mutable_t<Range, int> = 0
>
inline typename zr_boost_1_81::range_iterator<Range>::type
erase(Range && rng,
      typename zr_boost_1_81::range_iterator<Range>::type it)
{
    BOOST_GEOMETRY_ASSERT(!zr_boost_1_81::empty(rng));
    BOOST_GEOMETRY_ASSERT(it != zr_boost_1_81::end(rng));

    typename zr_boost_1_81::range_difference<Range>::type const
        d = std::distance(zr_boost_1_81::begin(rng), it);

    typename zr_boost_1_81::range_iterator<Range>::type
        next = it;
    ++next;

    std::move(next, zr_boost_1_81::end(rng), it);
    range::resize(rng, zr_boost_1_81::size(rng) - 1);

    // NOTE: In general this should be sufficient:
    //    return it;
    // But in MSVC using the returned iterator causes
    // assertion failures when iterator debugging is enabled
    // Furthermore the code below should work in the case if resize()
    // invalidates iterators when the container is resized down.
    return zr_boost_1_81::begin(rng) + d;
}

/*!
\brief Short utility to conveniently remove an element from a mutable range.
       It uses std::move() and resize(). Version taking non-mutable iterators.
\ingroup utility
*/
template
<
    typename Range,
    detail::enable_if_mutable_t<Range, int> = 0
>
inline typename zr_boost_1_81::range_iterator<Range>::type
erase(Range && rng,
      typename zr_boost_1_81::range_iterator<std::remove_reference_t<Range> const>::type cit)
{
    BOOST_RANGE_CONCEPT_ASSERT(( zr_boost_1_81::RandomAccessRangeConcept<Range> ));

    typename zr_boost_1_81::range_iterator<Range>::type
        it = zr_boost_1_81::begin(rng)
                + std::distance(zr_boost_1_81::const_begin(rng), cit);

    return range::erase(rng, it);
}

/*!
\brief Short utility to conveniently remove a range of elements from a mutable range.
       It uses std::move() and resize(). Version taking mutable iterators.
\ingroup utility
*/
template
<
    typename Range,
    detail::enable_if_mutable_t<Range, int> = 0
>
inline typename zr_boost_1_81::range_iterator<Range>::type
erase(Range && rng,
      typename zr_boost_1_81::range_iterator<Range>::type first,
      typename zr_boost_1_81::range_iterator<Range>::type last)
{
    typename zr_boost_1_81::range_difference<Range>::type const
        diff = std::distance(first, last);
    BOOST_GEOMETRY_ASSERT(diff >= 0);

    std::size_t const count = static_cast<std::size_t>(diff);
    BOOST_GEOMETRY_ASSERT(count <= zr_boost_1_81::size(rng));
    
    if ( count > 0 )
    {
        typename zr_boost_1_81::range_difference<Range>::type const
            d = std::distance(zr_boost_1_81::begin(rng), first);

        std::move(last, zr_boost_1_81::end(rng), first);
        range::resize(rng, zr_boost_1_81::size(rng) - count);

        // NOTE: In general this should be sufficient:
        //    return first;
        // But in MSVC using the returned iterator causes
        // assertion failures when iterator debugging is enabled
        // Furthermore the code below should work in the case if resize()
        // invalidates iterators when the container is resized down.
        return zr_boost_1_81::begin(rng) + d;
    }

    return first;
}

/*!
\brief Short utility to conveniently remove a range of elements from a mutable range.
       It uses std::move() and resize(). Version taking non-mutable iterators.
\ingroup utility
*/
template
<
    typename Range,
    detail::enable_if_mutable_t<Range, int> = 0
>
inline typename zr_boost_1_81::range_iterator<Range>::type
erase(Range && rng,
      typename zr_boost_1_81::range_iterator<std::remove_reference_t<Range> const>::type cfirst,
      typename zr_boost_1_81::range_iterator<std::remove_reference_t<Range> const>::type clast)
{
    BOOST_RANGE_CONCEPT_ASSERT(( zr_boost_1_81::RandomAccessRangeConcept<Range> ));

    typename zr_boost_1_81::range_iterator<Range>::type
        first = zr_boost_1_81::begin(rng)
                    + std::distance(zr_boost_1_81::const_begin(rng), cfirst);
    typename zr_boost_1_81::range_iterator<Range>::type
        last = zr_boost_1_81::begin(rng)
                    + std::distance(zr_boost_1_81::const_begin(rng), clast);

    return range::erase(rng, first, last);
}

// back_inserter

template <class Container>
class back_insert_iterator
{
public:
    typedef std::output_iterator_tag iterator_category;
    typedef void value_type;
    typedef void difference_type;
    typedef void pointer;
    typedef void reference;

    typedef Container container_type;

    explicit back_insert_iterator(Container & c)
        : container(zr_boost_1_81::addressof(c))
    {}

    back_insert_iterator & operator=(typename Container::value_type const& value)
    {
        range::push_back(*container, value);
        return *this;
    }

    back_insert_iterator & operator=(typename Container::value_type && value)
    {
        range::push_back(*container, std::move(value));
        return *this;
    }

    back_insert_iterator & operator* ()
    {
        return *this;
    }

    back_insert_iterator & operator++ ()
    {
        return *this;
    }

    back_insert_iterator operator++(int)
    {
        return *this;
    }

private:
    Container * container;
};

template <typename Range>
inline back_insert_iterator<Range> back_inserter(Range & rng)
{
    return back_insert_iterator<Range>(rng);
}

}}} // namespace zr_boost_1_81::geometry::range

#endif // BOOST_GEOMETRY_UTIL_RANGE_HPP
