//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef BOOST_RANGE_DETAIL_RANGE_RETURN_HPP_INCLUDED
#define BOOST_RANGE_DETAIL_RANGE_RETURN_HPP_INCLUDED

#include <boost/range/begin.hpp>
#include <boost/range/end.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/next_prior.hpp>

namespace zr_boost_1_81
{
    enum range_return_value
    {
        // (*) indicates the most common values
        return_found,       // only the found resulting iterator (*)
        return_next,        // next(found) iterator
        return_prior,       // prior(found) iterator
        return_begin_found, // [begin, found) range (*)
        return_begin_next,  // [begin, next(found)) range
        return_begin_prior, // [begin, prior(found)) range
        return_found_end,   // [found, end) range (*)
        return_next_end,    // [next(found), end) range
        return_prior_end,   // [prior(found), end) range
        return_begin_end    // [begin, end) range
    };

    template< class SinglePassRange, range_return_value >
    struct range_return
    {
        typedef zr_boost_1_81::iterator_range<
            BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type > type;

        static type pack(BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type found,
                         SinglePassRange& rng)
        {
            return type(found, zr_boost_1_81::end(rng));
        }
    };

    template< class SinglePassRange >
    struct range_return< SinglePassRange, return_found >
    {
        typedef BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type type;

        static type pack(type found, SinglePassRange&)
        {
            return found;
        }
    };

    template< class SinglePassRange >
    struct range_return< SinglePassRange, return_next >
    {
        typedef BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type type;

        static type pack(type found, SinglePassRange& rng)
        {
            return found == zr_boost_1_81::end(rng)
                ? found
                : zr_boost_1_81::next(found);
        }
    };

    template< class BidirectionalRange >
    struct range_return< BidirectionalRange, return_prior >
    {
        typedef BOOST_DEDUCED_TYPENAME range_iterator<BidirectionalRange>::type type;

        static type pack(type found, BidirectionalRange& rng)
        {
            return found == zr_boost_1_81::begin(rng)
                ? found
                : zr_boost_1_81::prior(found);
        }
    };

    template< class SinglePassRange >
    struct range_return< SinglePassRange, return_begin_found >
    {
        typedef zr_boost_1_81::iterator_range<
            BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type > type;

        static type pack(BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type found,
                         SinglePassRange& rng)
        {
            return type(zr_boost_1_81::begin(rng), found);
        }
    };

    template< class SinglePassRange >
    struct range_return< SinglePassRange, return_begin_next >
    {
        typedef zr_boost_1_81::iterator_range<
            BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type > type;

        static type pack(BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type found,
                         SinglePassRange& rng)
        {
            return type( zr_boost_1_81::begin(rng), 
                         found == zr_boost_1_81::end(rng) ? found : zr_boost_1_81::next(found) );
        }
    };

    template< class BidirectionalRange >
    struct range_return< BidirectionalRange, return_begin_prior >
    {
        typedef zr_boost_1_81::iterator_range<
            BOOST_DEDUCED_TYPENAME range_iterator<BidirectionalRange>::type > type;

        static type pack(BOOST_DEDUCED_TYPENAME range_iterator<BidirectionalRange>::type found,
                         BidirectionalRange& rng)
        {
            return type( zr_boost_1_81::begin(rng),
                         found == zr_boost_1_81::begin(rng) ? found : zr_boost_1_81::prior(found) );
        }
    };

    template< class SinglePassRange >
    struct range_return< SinglePassRange, return_found_end >
    {
        typedef zr_boost_1_81::iterator_range<
            BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type > type;

        static type pack(BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type found,
                         SinglePassRange& rng)
        {
            return type(found, zr_boost_1_81::end(rng));
        }
    };

    template< class SinglePassRange >
    struct range_return< SinglePassRange, return_next_end >
    {
        typedef zr_boost_1_81::iterator_range<
            BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type > type;

        static type pack(BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type found,
                         SinglePassRange& rng)
        {
            return type( found == zr_boost_1_81::end(rng) ? found : zr_boost_1_81::next(found),
                         zr_boost_1_81::end(rng) );
        }
    };

    template< class BidirectionalRange >
    struct range_return< BidirectionalRange, return_prior_end >
    {
        typedef zr_boost_1_81::iterator_range<
            BOOST_DEDUCED_TYPENAME range_iterator<BidirectionalRange>::type > type;

        static type pack(BOOST_DEDUCED_TYPENAME range_iterator<BidirectionalRange>::type found,
                         BidirectionalRange& rng)
        {
            return type( found == zr_boost_1_81::begin(rng) ? found : zr_boost_1_81::prior(found),
                         zr_boost_1_81::end(rng) );
        }
    };

    template< class SinglePassRange >
    struct range_return< SinglePassRange, return_begin_end >
    {
        typedef zr_boost_1_81::iterator_range<
            BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type > type;

        static type pack(BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type,
                         SinglePassRange& rng)
        {
            return type(zr_boost_1_81::begin(rng), zr_boost_1_81::end(rng));
        }
    };

}

#endif // include guard
