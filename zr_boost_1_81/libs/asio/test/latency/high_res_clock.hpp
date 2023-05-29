//
// high_res_clock.hpp
// ~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIGH_RES_CLOCK_HPP
#define HIGH_RES_CLOCK_HPP

#include <boost/config.hpp>
#include <boost/cstdint.hpp>

#if defined(BOOST_ASIO_WINDOWS)

inline zr_boost_1_81::uint64_t high_res_clock()
{
  LARGE_INTEGER i;
  QueryPerformanceCounter(&i);
  return i.QuadPart;
}

#elif defined(__GNUC__) && defined(__x86_64__)

inline zr_boost_1_81::uint64_t high_res_clock()
{
  unsigned long low, high;
  __asm__ __volatile__("rdtsc" : "=a" (low), "=d" (high));
  return (((zr_boost_1_81::uint64_t)high) << 32) | low;
}

#else

#include <boost/date_time/posix_time/posix_time_types.hpp>

inline zr_boost_1_81::uint64_t high_res_clock()
{
  zr_boost_1_81::posix_time::ptime now =
    zr_boost_1_81::posix_time::microsec_clock::universal_time();

  zr_boost_1_81::posix_time::ptime epoch(
      zr_boost_1_81::gregorian::date(1970, 1, 1),
      zr_boost_1_81::posix_time::seconds(0));

  return (now - epoch).total_microseconds();
}

#endif

#endif // HIGH_RES_CLOCK_HPP
