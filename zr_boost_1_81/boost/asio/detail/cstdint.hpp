//
// detail/cstdint.hpp
// ~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_ASIO_DETAIL_CSTDINT_HPP
#define BOOST_ASIO_DETAIL_CSTDINT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <boost/asio/detail/config.hpp>

#if defined(BOOST_ASIO_HAS_CSTDINT)
# include <cstdint>
#else // defined(BOOST_ASIO_HAS_CSTDINT)
# include <boost/cstdint.hpp>
#endif // defined(BOOST_ASIO_HAS_CSTDINT)

namespace zr_boost_1_81 {
namespace asio {

#if defined(BOOST_ASIO_HAS_CSTDINT)
using std::int16_t;
using std::int_least16_t;
using std::uint16_t;
using std::uint_least16_t;
using std::int32_t;
using std::int_least32_t;
using std::uint32_t;
using std::uint_least32_t;
using std::int64_t;
using std::int_least64_t;
using std::uint64_t;
using std::uint_least64_t;
using std::uintptr_t;
using std::uintmax_t;
#else // defined(BOOST_ASIO_HAS_CSTDINT)
using zr_boost_1_81::int16_t;
using zr_boost_1_81::int_least16_t;
using zr_boost_1_81::uint16_t;
using zr_boost_1_81::uint_least16_t;
using zr_boost_1_81::int32_t;
using zr_boost_1_81::int_least32_t;
using zr_boost_1_81::uint32_t;
using zr_boost_1_81::uint_least32_t;
using zr_boost_1_81::int64_t;
using zr_boost_1_81::int_least64_t;
using zr_boost_1_81::uint64_t;
using zr_boost_1_81::uint_least64_t;
using zr_boost_1_81::uintptr_t;
using zr_boost_1_81::uintmax_t;
#endif // defined(BOOST_ASIO_HAS_CSTDINT)

} // namespace asio
} // namespace zr_boost_1_81

#endif // BOOST_ASIO_DETAIL_CSTDINT_HPP
