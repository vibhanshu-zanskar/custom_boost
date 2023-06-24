//
// Copyright (c) 2017 James E. King III
// Use, modification and distribution is subject to the
// Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or http://www.boost.org/LICENSE_1_0.txt)
//

#include <boost/core/ignore_unused.hpp>
#include <boost/date_time/posix_time/posix_time_duration.hpp>
#include <boost/date_time/special_defs.hpp>

int main()
{
    using zr_boost_1_81::date_time::pos_infin;
    using zr_boost_1_81::posix_time::minutes;
    zr_boost_1_81::ignore_unused(minutes(static_cast<zr_boost_1_81::int64_t>(pos_infin))); // compiles: it's an integral
    zr_boost_1_81::ignore_unused(minutes(pos_infin));                              // won't compile: not an integral
    return 1;                                                              // return an error if we actually run for some reason
}
