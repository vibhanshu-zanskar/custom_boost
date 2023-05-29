/*
 * Copyright 2010 Vicente J. Botet Escriba
 * Copyright 2015 Andrey Semashev
 * Copyright 2017 James E. King, III
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_WAIT_HPP_INCLUDED_
#define BOOST_WINAPI_WAIT_HPP_INCLUDED_

#include <boost/winapi/basic_types.hpp>
#include <boost/winapi/wait_constants.hpp>
#include <boost/winapi/detail/header.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {

#if BOOST_WINAPI_PARTITION_APP || BOOST_WINAPI_PARTITION_SYSTEM
BOOST_WINAPI_IMPORT zr_boost_1_81::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
WaitForSingleObjectEx(
    zr_boost_1_81::winapi::HANDLE_ hHandle,
    zr_boost_1_81::winapi::DWORD_ dwMilliseconds,
    zr_boost_1_81::winapi::BOOL_ bAlertable);
#endif

#if BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM
#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_NT4
BOOST_WINAPI_IMPORT zr_boost_1_81::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
SignalObjectAndWait(
    zr_boost_1_81::winapi::HANDLE_ hObjectToSignal,
    zr_boost_1_81::winapi::HANDLE_ hObjectToWaitOn,
    zr_boost_1_81::winapi::DWORD_ dwMilliseconds,
    zr_boost_1_81::winapi::BOOL_ bAlertable);
#endif
#endif

#if BOOST_WINAPI_PARTITION_APP_SYSTEM
BOOST_WINAPI_IMPORT_EXCEPT_WM zr_boost_1_81::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
WaitForSingleObject(
    zr_boost_1_81::winapi::HANDLE_ hHandle,
    zr_boost_1_81::winapi::DWORD_ dwMilliseconds);

BOOST_WINAPI_IMPORT_EXCEPT_WM zr_boost_1_81::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
WaitForMultipleObjects(
    zr_boost_1_81::winapi::DWORD_ nCount,
    zr_boost_1_81::winapi::HANDLE_ const* lpHandles,
    zr_boost_1_81::winapi::BOOL_ bWaitAll,
    zr_boost_1_81::winapi::DWORD_ dwMilliseconds);

BOOST_WINAPI_IMPORT zr_boost_1_81::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
WaitForMultipleObjectsEx(
    zr_boost_1_81::winapi::DWORD_ nCount,
    zr_boost_1_81::winapi::HANDLE_ const* lpHandles,
    zr_boost_1_81::winapi::BOOL_ bWaitAll,
    zr_boost_1_81::winapi::DWORD_ dwMilliseconds,
    zr_boost_1_81::winapi::BOOL_ bAlertable);
#endif // BOOST_WINAPI_PARTITION_APP_SYSTEM

} // extern "C"
#endif

namespace zr_boost_1_81 {
namespace winapi {

#if BOOST_WINAPI_PARTITION_APP || BOOST_WINAPI_PARTITION_SYSTEM
using ::WaitForSingleObjectEx;
#endif
#if BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM
#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_NT4
using ::SignalObjectAndWait;
#endif
#endif

#if BOOST_WINAPI_PARTITION_APP_SYSTEM
using ::WaitForMultipleObjects;
using ::WaitForMultipleObjectsEx;
using ::WaitForSingleObject;
#endif

}
}

#include <boost/winapi/detail/footer.hpp>

#endif // BOOST_WINAPI_WAIT_HPP_INCLUDED_
