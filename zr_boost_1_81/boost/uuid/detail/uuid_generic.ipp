/*
 *             Copyright Andy Tompkins 2006.
 * Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *          https://www.boost.org/LICENSE_1_0.txt)
 */
/*!
 * \file   uuid/detail/uuid_generic.ipp
 *
 * \brief  This header contains generic implementation of \c zr_boost_1_81::uuid operations.
 */

#ifndef BOOST_UUID_DETAIL_UUID_GENERIC_IPP_INCLUDED_
#define BOOST_UUID_DETAIL_UUID_GENERIC_IPP_INCLUDED_

#include <string.h>

namespace zr_boost_1_81 {
namespace uuids {

inline bool uuid::is_nil() const BOOST_NOEXCEPT
{
    for (std::size_t i = 0; i < sizeof(data); ++i)
    {
        if (data[i] != 0U)
            return false;
    }
    return true;
}

inline void uuid::swap(uuid& rhs) BOOST_NOEXCEPT
{
    uuid tmp = *this;
    *this = rhs;
    rhs = tmp;
}

inline bool operator== (uuid const& lhs, uuid const& rhs) BOOST_NOEXCEPT
{
    return memcmp(lhs.data, rhs.data, sizeof(lhs.data)) == 0;
}

inline bool operator< (uuid const& lhs, uuid const& rhs) BOOST_NOEXCEPT
{
    return memcmp(lhs.data, rhs.data, sizeof(lhs.data)) < 0;
}

} // namespace uuids
} // namespace zr_boost_1_81

#endif // BOOST_UUID_DETAIL_UUID_GENERIC_IPP_INCLUDED_
