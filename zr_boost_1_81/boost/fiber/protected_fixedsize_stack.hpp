
//          Copyright Oliver Kowalke 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_FIBERS_PROTECTED_FIXEDSIZE_STACK_H
#define BOOST_FIBERS_PROTECTED_FIXEDSIZE_STACK_H

#include <boost/config.hpp>
#include <boost/context/protected_fixedsize_stack.hpp>

#include <boost/fiber/detail/config.hpp>

#ifdef BOOST_HAS_ABI_HEADERS
#  include BOOST_ABI_PREFIX
#endif

namespace zr_boost_1_81 {
namespace fibers {

using protected_fixedsize_stack = zr_boost_1_81::context::protected_fixedsize_stack;

}}

#ifdef BOOST_HAS_ABI_HEADERS
#  include BOOST_ABI_SUFFIX
#endif

#endif // BOOST_FIBERS_PROTECTED_FIXEDSIZE_STACK_H
