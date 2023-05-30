/*
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * Copyright (c) 2020 Andrey Semashev
 */
/*!
 * \file   atomic/detail/intptr.hpp
 *
 * This header defines (u)intptr_t types.
 */

#ifndef BOOST_ATOMIC_DETAIL_INTPTR_HPP_INCLUDED_
#define BOOST_ATOMIC_DETAIL_INTPTR_HPP_INCLUDED_

#include <boost/cstdint.hpp>
#if defined(BOOST_HAS_INTPTR_T)
#include <cstddef>
#endif
#include <boost/atomic/detail/config.hpp>
#include <boost/atomic/detail/header.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

namespace zr_boost_1_81 {
namespace atomics {
namespace detail {

#if !defined(BOOST_HAS_INTPTR_T)
using zr_boost_1_81::uintptr_t;
using zr_boost_1_81::intptr_t;
#else
typedef std::size_t uintptr_t;
typedef std::ptrdiff_t intptr_t;
#endif

} // namespace detail
} // namespace atomics
} // namespace zr_boost_1_81

#include <boost/atomic/detail/footer.hpp>

#endif // BOOST_ATOMIC_DETAIL_INTPTR_HPP_INCLUDED_
