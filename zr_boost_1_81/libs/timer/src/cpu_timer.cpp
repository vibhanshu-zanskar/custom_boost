//  boost cpu_timer.cpp  ---------------------------------------------------------------//

//  Copyright Beman Dawes 1994-2006, 2011

//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/timer for documentation.

//--------------------------------------------------------------------------------------//

// define BOOST_TIMER_SOURCE so that <boost/timer/config.hpp> knows
// the library is being built (possibly exporting rather than importing code)
#define BOOST_TIMER_SOURCE

#include <boost/timer/timer.hpp>
#include <boost/chrono/chrono.hpp>
#include <boost/io/ios_state.hpp>
#include <boost/throw_exception.hpp>
#include <boost/cerrno.hpp>
#include <boost/predef.h>
#include <cstring>
#include <sstream>
#include <cassert>

# if defined(BOOST_WINDOWS_API)
#   include <windows.h>
# elif defined(BOOST_POSIX_API)
#   include <unistd.h>
#   include <sys/times.h>
# else
# error unknown API
# endif

using zr_boost_1_81::timer::nanosecond_type;
using zr_boost_1_81::timer::cpu_times;

namespace
{

  void show_time(const cpu_times& times,
    std::ostream& os, const std::string& fmt, short places)
  //  NOTE WELL: Will truncate least-significant digits to LDBL_DIG, which may
  //  be as low as 10, although will be 15 for many common platforms.
  {
    if (places > 9)
      places = 9;
    else if (places < 0)
      places = zr_boost_1_81::timer::default_places;
 
    zr_boost_1_81::io::ios_flags_saver ifs(os);
    zr_boost_1_81::io::ios_precision_saver ips(os);
    os.setf(std::ios_base::fixed, std::ios_base::floatfield);
    os.precision(places);

    const double sec = 1000000000.0L;
    nanosecond_type total = times.system + times.user;
    double wall_sec = static_cast<double>(times.wall) / sec;
    double total_sec = static_cast<double>(total) / sec;

    for (const char* format = fmt.c_str(); *format; ++format)
    {
      if (*format != '%' || !*(format+1) || !std::strchr("wustp", *(format+1)))
        os << *format;  // anything except % followed by a valid format character
                        // gets sent to the output stream
      else
      {
        ++format;
        switch (*format)
        {
        case 'w':
          os << wall_sec;
          break;
        case 'u':
          os << static_cast<double>(times.user) / sec;
          break;
        case 's':
          os << static_cast<double>(times.system) / sec;
          break;
        case 't':
          os << total_sec;
          break;
        case 'p':
          os.precision(1);
          if (wall_sec > 0.001L && total_sec > 0.001L)
            os << (total_sec/wall_sec) * 100.0;
          else
            os << "n/a";
          os.precision(places);
          break;
        }
      }
    }
  }

# if defined(BOOST_POSIX_API)

  zr_boost_1_81::int_least64_t tick_factor_()
  {
    zr_boost_1_81::int_least64_t tf = ::sysconf( _SC_CLK_TCK );
    if( tf <= 0 ) return -1;

    tf = INT64_C(1000000000) / tf;  // compute factor
    if( tf == 0 ) tf = -1;

    return tf;
  }

  zr_boost_1_81::int_least64_t tick_factor() // multiplier to convert ticks
                                     //  to nanoseconds; -1 if unknown
  {
    static zr_boost_1_81::int_least64_t tf = tick_factor_();
    return tf;
  }

# endif

  void get_cpu_times(zr_boost_1_81::timer::cpu_times& current)
  {
    zr_boost_1_81::chrono::duration<zr_boost_1_81::int64_t, zr_boost_1_81::nano>
      x (zr_boost_1_81::chrono::high_resolution_clock::now().time_since_epoch());
    current.wall = x.count();

# if defined(BOOST_WINDOWS_API)

#  if BOOST_PLAT_WINDOWS_DESKTOP || defined(__CYGWIN__)
    FILETIME creation, exit;
    if (::GetProcessTimes(::GetCurrentProcess(), &creation, &exit,
            (LPFILETIME)&current.system, (LPFILETIME)&current.user))
    {
      current.user   *= 100;  // Windows uses 100 nanosecond ticks
      current.system *= 100;
    }
    else
#  endif
    {
      current.system = current.user = zr_boost_1_81::timer::nanosecond_type(-1);
    }
# else
    tms tm;
    clock_t c = ::times(&tm);
    if (c == static_cast<clock_t>(-1)) // error
    {
      current.system = current.user = zr_boost_1_81::timer::nanosecond_type(-1);
    }
    else
    {
      current.system = zr_boost_1_81::timer::nanosecond_type(tm.tms_stime + tm.tms_cstime);
      current.user = zr_boost_1_81::timer::nanosecond_type(tm.tms_utime + tm.tms_cutime);
      zr_boost_1_81::int_least64_t factor;
      if ((factor = tick_factor()) != -1)
      {
        current.user *= factor;
        current.system *= factor;
      }
      else
      {
        current.user = current.system = zr_boost_1_81::timer::nanosecond_type(-1);
      }
    }
# endif
  }

  // CAUTION: must be identical to same constant in auto_timers_construction.cpp
  const std::string default_fmt(" %ws wall, %us user + %ss system = %ts CPU (%p%)\n");

} // unnamed namespace

namespace zr_boost_1_81
{
  namespace timer
  {
    //  format  ------------------------------------------------------------------------//

    BOOST_TIMER_DECL
    std::string format(const cpu_times& times, short places, const std::string& fmt)
    {
      std::stringstream ss;
      ss.exceptions(std::ios_base::badbit | std::ios_base::failbit);
      show_time(times, ss, fmt, places);
      return ss.str();
    }
 
    BOOST_TIMER_DECL
    std::string format(const cpu_times& times, short places)
    {
      return format(times, places, default_fmt);
    }

    //  cpu_timer  ---------------------------------------------------------------------//

    void cpu_timer::start() BOOST_NOEXCEPT
    {
      m_is_stopped = false;
      get_cpu_times(m_times);
    }

    void cpu_timer::stop() BOOST_NOEXCEPT
    {
      if (is_stopped())
        return;
      m_is_stopped = true;
      
      cpu_times current;
      get_cpu_times(current);
      m_times.wall = (current.wall - m_times.wall);
      m_times.user = (current.user - m_times.user);
      m_times.system = (current.system - m_times.system);
    }

    cpu_times cpu_timer::elapsed() const BOOST_NOEXCEPT
    {
      if (is_stopped())
        return m_times;
      cpu_times current;
      get_cpu_times(current);
      current.wall -= m_times.wall;
      current.user -= m_times.user;
      current.system -= m_times.system;
      return current;
    }

    void cpu_timer::resume() BOOST_NOEXCEPT
    {
      if (is_stopped())
      {
        cpu_times current (m_times);
        start();
        m_times.wall   -= current.wall;
        m_times.user   -= current.user;
        m_times.system -= current.system;
      }
    }

    //  auto_cpu_timer  ----------------------------------------------------------------//

    auto_cpu_timer::auto_cpu_timer(std::ostream& os, short places)        // #5
      : m_places(places), m_os(&os), m_format(default_fmt)
    { 
      start();
    }

    void auto_cpu_timer::report()
    {
        show_time(elapsed(), ostream(), format_string(), places());
    }

    auto_cpu_timer::~auto_cpu_timer()
    { 
      if (!is_stopped())
      {
        stop();  // the sooner we stop(), the better
#ifndef BOOST_NO_EXCEPTIONS
        try
        {
#endif
          report();
#ifndef BOOST_NO_EXCEPTIONS
        }
        catch (...) // eat any exceptions
        {
        }
#endif
      }
    }

  } // namespace timer
} // namespace zr_boost_1_81
