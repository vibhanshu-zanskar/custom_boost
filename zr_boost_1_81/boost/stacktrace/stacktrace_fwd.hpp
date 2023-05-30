// Copyright Antony Polukhin, 2016-2022.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_STACKTRACE_STACKTRACE_FWD_HPP
#define BOOST_STACKTRACE_STACKTRACE_FWD_HPP

#include <cstddef>
#include <memory>

/// @file stacktrace_fwd.hpp This header contains only forward declarations of
/// zr_boost_1_81::stacktrace::frame, zr_boost_1_81::stacktrace::basic_stacktrace, zr_boost_1_81::stacktrace::stacktrace
/// and does not include any other Boost headers.

/// @cond
namespace zr_boost_1_81 { namespace stacktrace {

class frame;
template <class Allocator = std::allocator<frame> > class basic_stacktrace;
typedef basic_stacktrace<> stacktrace;

}} // namespace zr_boost_1_81::stacktrace
/// @endcond


#endif // BOOST_STACKTRACE_STACKTRACE_FWD_HPP
