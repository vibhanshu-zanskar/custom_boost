/*
 * Copyright 2013 Andrey Semashev
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_TLS_HPP_INCLUDED_
#define BOOST_WINAPI_TLS_HPP_INCLUDED_

#include <boost/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if BOOST_WINAPI_PARTITION_APP_SYSTEM

#include <boost/winapi/detail/header.hpp>

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {
#if !defined( UNDER_CE )
// Windows CE define TlsAlloc and TlsFree as inline functions in kfuncs.h
BOOST_WINAPI_IMPORT zr_boost_1_81::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
TlsAlloc(BOOST_WINAPI_DETAIL_VOID);

BOOST_WINAPI_IMPORT zr_boost_1_81::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
TlsFree(zr_boost_1_81::winapi::DWORD_ dwTlsIndex);
#endif

BOOST_WINAPI_IMPORT_EXCEPT_WM zr_boost_1_81::winapi::LPVOID_ BOOST_WINAPI_WINAPI_CC
TlsGetValue(zr_boost_1_81::winapi::DWORD_ dwTlsIndex);

BOOST_WINAPI_IMPORT_EXCEPT_WM zr_boost_1_81::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
TlsSetValue(
    zr_boost_1_81::winapi::DWORD_ dwTlsIndex,
    zr_boost_1_81::winapi::LPVOID_ lpTlsValue);
} // extern "C"
#endif

namespace zr_boost_1_81 {
namespace winapi {

using ::TlsAlloc;
using ::TlsFree;
using ::TlsGetValue;
using ::TlsSetValue;

#if defined( BOOST_USE_WINDOWS_H )
BOOST_CONSTEXPR_OR_CONST DWORD_ TLS_OUT_OF_INDEXES_ = TLS_OUT_OF_INDEXES;
#else
BOOST_CONSTEXPR_OR_CONST DWORD_ TLS_OUT_OF_INDEXES_ = 0xFFFFFFFF;
#endif

BOOST_CONSTEXPR_OR_CONST DWORD_ tls_out_of_indexes = TLS_OUT_OF_INDEXES_;

}
}

#include <boost/winapi/detail/footer.hpp>

#endif // BOOST_WINAPI_PARTITION_APP_SYSTEM
#endif // BOOST_WINAPI_TLS_HPP_INCLUDED_
