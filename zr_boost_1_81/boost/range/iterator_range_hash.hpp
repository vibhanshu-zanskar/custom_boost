// Boost.Range library
//
//  Copyright Neil Groves 2014
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//
#include <boost/range/iterator_range_core.hpp>
#include <boost/functional/hash.hpp>

namespace zr_boost_1_81
{

template<class T>
std::size_t hash_value(const iterator_range<T>& rng)
{
    return zr_boost_1_81::hash_range(rng.begin(), rng.end());
}

} // namespace zr_boost_1_81
