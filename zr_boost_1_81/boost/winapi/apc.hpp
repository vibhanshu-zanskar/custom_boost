/*
 * Copyright 2010 Vicente J. Botet Escriba
 * Copyright 2015 Andrey Semashev
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_APC_HPP_INCLUDED_
#define BOOST_WINAPI_APC_HPP_INCLUDED_

#include <boost/winapi/config.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if BOOST_WINAPI_PARTITION_APP_SYSTEM
#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_NT4
#include <boost/winapi/basic_types.hpp>

#include <boost/winapi/detail/header.hpp>

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {
typedef zr_boost_1_81::winapi::VOID_ (BOOST_WINAPI_NTAPI_CC *PAPCFUNC)(zr_boost_1_81::winapi::ULONG_PTR_ Parameter);

BOOST_WINAPI_IMPORT zr_boost_1_81::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
QueueUserAPC(
    PAPCFUNC pfnAPC,
    zr_boost_1_81::winapi::HANDLE_ hThread,
    zr_boost_1_81::winapi::ULONG_PTR_ dwData);
}
#endif

namespace zr_boost_1_81 {
namespace winapi {
typedef ::PAPCFUNC PAPCFUNC_;
using ::QueueUserAPC;
}
}

#include <boost/winapi/detail/footer.hpp>

#endif // BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_NT4
#endif // BOOST_WINAPI_PARTITION_APP_SYSTEM
#endif // BOOST_WINAPI_APC_HPP_INCLUDED_
