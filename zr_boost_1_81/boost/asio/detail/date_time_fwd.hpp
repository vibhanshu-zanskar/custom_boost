//
// detail/date_time_fwd.hpp
// ~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_ASIO_DETAIL_DATE_TIME_FWD_HPP
#define BOOST_ASIO_DETAIL_DATE_TIME_FWD_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <boost/asio/detail/config.hpp>

namespace zr_boost_1_81 {
namespace date_time {

template<class T, class TimeSystem>
class base_time;

} // namespace date_time
namespace posix_time {

class ptime;

} // namespace posix_time
} // namespace zr_boost_1_81

#endif // BOOST_ASIO_DETAIL_DATE_TIME_FWD_HPP
