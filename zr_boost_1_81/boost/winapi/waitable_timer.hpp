/*
 * Copyright 2013 Andrey Semashev
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_WAITABLE_TIMER_HPP_INCLUDED_
#define BOOST_WINAPI_WAITABLE_TIMER_HPP_INCLUDED_

#include <boost/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if BOOST_WINAPI_PARTITION_APP_SYSTEM

#include <boost/winapi/detail/header.hpp>

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {
typedef zr_boost_1_81::winapi::VOID_
(BOOST_WINAPI_WINAPI_CC *PTIMERAPCROUTINE)(
    zr_boost_1_81::winapi::LPVOID_ lpArgToCompletionRoutine,
    zr_boost_1_81::winapi::DWORD_ dwTimerLowValue,
    zr_boost_1_81::winapi::DWORD_ dwTimerHighValue);

#if !defined( BOOST_NO_ANSI_APIS )
BOOST_WINAPI_IMPORT zr_boost_1_81::winapi::HANDLE_ BOOST_WINAPI_WINAPI_CC
CreateWaitableTimerA(
    ::_SECURITY_ATTRIBUTES* lpTimerAttributes,
    zr_boost_1_81::winapi::BOOL_ bManualReset,
    zr_boost_1_81::winapi::LPCSTR_ lpTimerName);

BOOST_WINAPI_IMPORT zr_boost_1_81::winapi::HANDLE_ BOOST_WINAPI_WINAPI_CC
OpenWaitableTimerA(
    zr_boost_1_81::winapi::DWORD_ dwDesiredAccess,
    zr_boost_1_81::winapi::BOOL_ bInheritHandle,
    zr_boost_1_81::winapi::LPCSTR_ lpTimerName);
#endif

BOOST_WINAPI_IMPORT zr_boost_1_81::winapi::HANDLE_ BOOST_WINAPI_WINAPI_CC
CreateWaitableTimerW(
    ::_SECURITY_ATTRIBUTES* lpTimerAttributes,
    zr_boost_1_81::winapi::BOOL_ bManualReset,
    zr_boost_1_81::winapi::LPCWSTR_ lpTimerName);

BOOST_WINAPI_IMPORT zr_boost_1_81::winapi::HANDLE_ BOOST_WINAPI_WINAPI_CC
OpenWaitableTimerW(
    zr_boost_1_81::winapi::DWORD_ dwDesiredAccess,
    zr_boost_1_81::winapi::BOOL_ bInheritHandle,
    zr_boost_1_81::winapi::LPCWSTR_ lpTimerName);

BOOST_WINAPI_IMPORT zr_boost_1_81::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
SetWaitableTimer(
    zr_boost_1_81::winapi::HANDLE_ hTimer,
    const ::_LARGE_INTEGER* lpDueTime,
    zr_boost_1_81::winapi::LONG_ lPeriod,
    PTIMERAPCROUTINE pfnCompletionRoutine,
    zr_boost_1_81::winapi::LPVOID_ lpArgToCompletionRoutine,
    zr_boost_1_81::winapi::BOOL_ fResume);

BOOST_WINAPI_IMPORT zr_boost_1_81::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
CancelWaitableTimer(zr_boost_1_81::winapi::HANDLE_ hTimer);
} // extern "C"
#endif

namespace zr_boost_1_81 {
namespace winapi {

typedef ::PTIMERAPCROUTINE PTIMERAPCROUTINE_;

#if !defined( BOOST_NO_ANSI_APIS )
using ::OpenWaitableTimerA;
#endif
using ::OpenWaitableTimerW;
using ::CancelWaitableTimer;

#if defined( BOOST_USE_WINDOWS_H )

BOOST_CONSTEXPR_OR_CONST DWORD_ TIMER_ALL_ACCESS_ = TIMER_ALL_ACCESS;
BOOST_CONSTEXPR_OR_CONST DWORD_ TIMER_MODIFY_STATE_ = TIMER_MODIFY_STATE;
BOOST_CONSTEXPR_OR_CONST DWORD_ TIMER_QUERY_STATE_ = TIMER_QUERY_STATE;

#else // defined( BOOST_USE_WINDOWS_H )

BOOST_CONSTEXPR_OR_CONST DWORD_ TIMER_ALL_ACCESS_ = 0x001F0003;
BOOST_CONSTEXPR_OR_CONST DWORD_ TIMER_MODIFY_STATE_ = 0x00000002;
BOOST_CONSTEXPR_OR_CONST DWORD_ TIMER_QUERY_STATE_ = 0x00000001;

#endif // defined( BOOST_USE_WINDOWS_H )

BOOST_CONSTEXPR_OR_CONST DWORD_ timer_all_access = TIMER_ALL_ACCESS_;
BOOST_CONSTEXPR_OR_CONST DWORD_ timer_modify_state = TIMER_MODIFY_STATE_;
BOOST_CONSTEXPR_OR_CONST DWORD_ timer_query_state = TIMER_QUERY_STATE_;


#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE HANDLE_ CreateWaitableTimerA(PSECURITY_ATTRIBUTES_ lpTimerAttributes, BOOL_ bManualReset, LPCSTR_ lpTimerName)
{
    return ::CreateWaitableTimerA(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpTimerAttributes), bManualReset, lpTimerName);
}
#endif

BOOST_FORCEINLINE HANDLE_ CreateWaitableTimerW(PSECURITY_ATTRIBUTES_ lpTimerAttributes, BOOL_ bManualReset, LPCWSTR_ lpTimerName)
{
    return ::CreateWaitableTimerW(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpTimerAttributes), bManualReset, lpTimerName);
}

BOOST_FORCEINLINE BOOL_ SetWaitableTimer(
    HANDLE_ hTimer,
    const LARGE_INTEGER_* lpDueTime,
    LONG_ lPeriod,
    PTIMERAPCROUTINE_ pfnCompletionRoutine,
    LPVOID_ lpArgToCompletionRoutine,
    BOOL_ fResume)
{
    return ::SetWaitableTimer(hTimer, reinterpret_cast< const ::_LARGE_INTEGER* >(lpDueTime), lPeriod, pfnCompletionRoutine, lpArgToCompletionRoutine, fResume);
}

#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE HANDLE_ create_waitable_timer(PSECURITY_ATTRIBUTES_ lpTimerAttributes, BOOL_ bManualReset, LPCSTR_ lpTimerName)
{
    return ::CreateWaitableTimerA(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpTimerAttributes), bManualReset, lpTimerName);
}
#endif

BOOST_FORCEINLINE HANDLE_ create_waitable_timer(PSECURITY_ATTRIBUTES_ lpTimerAttributes, BOOL_ bManualReset, LPCWSTR_ lpTimerName)
{
    return ::CreateWaitableTimerW(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpTimerAttributes), bManualReset, lpTimerName);
}

BOOST_FORCEINLINE HANDLE_ create_anonymous_waitable_timer(PSECURITY_ATTRIBUTES_ lpTimerAttributes, BOOL_ bManualReset)
{
#ifdef BOOST_NO_ANSI_APIS
    return ::CreateWaitableTimerW(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpTimerAttributes), bManualReset, 0);
#else
    return ::CreateWaitableTimerA(reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpTimerAttributes), bManualReset, 0);
#endif
}

}
}

#include <boost/winapi/detail/footer.hpp>

#endif // BOOST_WINAPI_PARTITION_APP_SYSTEM
#endif // BOOST_WINAPI_WAITABLE_TIMER_HPP_INCLUDED_
