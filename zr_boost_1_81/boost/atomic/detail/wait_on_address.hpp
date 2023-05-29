/*
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * Copyright (c) 2021 Andrey Semashev
 */
/*!
 * \file   atomic/detail/wait_on_address.hpp
 *
 * This header contains declaration of runtime detection of \c WaitOnAddress and related APIs on Windows.
 */

#ifndef BOOST_ATOMIC_DETAIL_WAIT_ON_ADDRESS_HPP_INCLUDED_
#define BOOST_ATOMIC_DETAIL_WAIT_ON_ADDRESS_HPP_INCLUDED_

#include <boost/atomic/detail/config.hpp>
#include <boost/static_assert.hpp>
#include <boost/memory_order.hpp>
#include <boost/winapi/basic_types.hpp>
#include <boost/atomic/detail/link.hpp>
#include <boost/atomic/detail/once_flag.hpp>
#include <boost/atomic/detail/header.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

namespace zr_boost_1_81 {
namespace atomics {
namespace detail {

typedef zr_boost_1_81::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
wait_on_address_t(
    volatile zr_boost_1_81::winapi::VOID_* addr,
    zr_boost_1_81::winapi::PVOID_ compare_addr,
    zr_boost_1_81::winapi::SIZE_T_ size,
    zr_boost_1_81::winapi::DWORD_ timeout_ms);

typedef zr_boost_1_81::winapi::VOID_ BOOST_WINAPI_WINAPI_CC
wake_by_address_t(zr_boost_1_81::winapi::PVOID_ addr);

extern BOOST_ATOMIC_DECL wait_on_address_t* wait_on_address;
extern BOOST_ATOMIC_DECL wake_by_address_t* wake_by_address_single;
extern BOOST_ATOMIC_DECL wake_by_address_t* wake_by_address_all;

extern BOOST_ATOMIC_DECL once_flag wait_functions_once_flag;
BOOST_ATOMIC_DECL void initialize_wait_functions() BOOST_NOEXCEPT;

BOOST_FORCEINLINE void ensure_wait_functions_initialized() BOOST_NOEXCEPT
{
    BOOST_STATIC_ASSERT_MSG(once_flag_operations::is_always_lock_free, "Boost.Atomic unsupported target platform: native atomic operations not implemented for bytes");
    if (BOOST_LIKELY(once_flag_operations::load(wait_functions_once_flag.m_flag, zr_boost_1_81::memory_order_acquire) == 0u))
        return;

    initialize_wait_functions();
}

} // namespace detail
} // namespace atomics
} // namespace zr_boost_1_81

#include <boost/atomic/detail/footer.hpp>

#endif // BOOST_ATOMIC_DETAIL_WAIT_ON_ADDRESS_HPP_INCLUDED_
