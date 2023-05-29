/*
 * Copyright 2020 Andrey Semashev
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_WAIT_ON_ADDRESS_HPP_INCLUDED_
#define BOOST_WINAPI_WAIT_ON_ADDRESS_HPP_INCLUDED_

#include <boost/winapi/config.hpp>

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN8 && (BOOST_WINAPI_PARTITION_APP || BOOST_WINAPI_PARTITION_SYSTEM)

#include <boost/winapi/basic_types.hpp>
#include <boost/winapi/detail/header.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if !defined(BOOST_USE_WINDOWS_H)
extern "C" {

// Note: These functions are not dllimport
zr_boost_1_81::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
WaitOnAddress(
    volatile zr_boost_1_81::winapi::VOID_* addr,
    zr_boost_1_81::winapi::PVOID_ compare_addr,
    zr_boost_1_81::winapi::SIZE_T_ size,
    zr_boost_1_81::winapi::DWORD_ timeout_ms);

zr_boost_1_81::winapi::VOID_ BOOST_WINAPI_WINAPI_CC
WakeByAddressSingle(zr_boost_1_81::winapi::PVOID_ addr);

zr_boost_1_81::winapi::VOID_ BOOST_WINAPI_WINAPI_CC
WakeByAddressAll(zr_boost_1_81::winapi::PVOID_ addr);

} // extern "C"
#endif // !defined(BOOST_USE_WINDOWS_H)

namespace zr_boost_1_81 {
namespace winapi {

using ::WaitOnAddress;
using ::WakeByAddressSingle;
using ::WakeByAddressAll;

}
}

#include <boost/winapi/detail/footer.hpp>

#endif // BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN8 && (BOOST_WINAPI_PARTITION_APP || BOOST_WINAPI_PARTITION_SYSTEM)

#endif // BOOST_WINAPI_WAIT_ON_ADDRESS_HPP_INCLUDED_
