/*
 * Copyright 2010 Vicente J. Botet Escriba
 * Copyright 2015 Andrey Semashev
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_DIRECTORY_MANAGEMENT_HPP_INCLUDED_
#define BOOST_WINAPI_DIRECTORY_MANAGEMENT_HPP_INCLUDED_

#include <boost/winapi/basic_types.hpp>
#include <boost/winapi/get_system_directory.hpp>
#include <boost/winapi/detail/header.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {
#if !defined( BOOST_NO_ANSI_APIS )
BOOST_WINAPI_IMPORT zr_boost_1_81::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
    CreateDirectoryA(zr_boost_1_81::winapi::LPCSTR_, ::_SECURITY_ATTRIBUTES*);
#if BOOST_WINAPI_PARTITION_APP_SYSTEM
BOOST_WINAPI_IMPORT zr_boost_1_81::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
    GetTempPathA(zr_boost_1_81::winapi::DWORD_ length, zr_boost_1_81::winapi::LPSTR_ buffer);
#endif
BOOST_WINAPI_IMPORT zr_boost_1_81::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
    RemoveDirectoryA(zr_boost_1_81::winapi::LPCSTR_);
#endif
BOOST_WINAPI_IMPORT_EXCEPT_WM zr_boost_1_81::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
    CreateDirectoryW(zr_boost_1_81::winapi::LPCWSTR_, ::_SECURITY_ATTRIBUTES*);
#if BOOST_WINAPI_PARTITION_APP_SYSTEM
BOOST_WINAPI_IMPORT_EXCEPT_WM zr_boost_1_81::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
    GetTempPathW(zr_boost_1_81::winapi::DWORD_ length, zr_boost_1_81::winapi::LPWSTR_ buffer);
#endif
BOOST_WINAPI_IMPORT_EXCEPT_WM zr_boost_1_81::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
    RemoveDirectoryW(zr_boost_1_81::winapi::LPCWSTR_);
} // extern "C"
#endif

namespace zr_boost_1_81 {
namespace winapi {

#if !defined( BOOST_NO_ANSI_APIS )
#if BOOST_WINAPI_PARTITION_APP_SYSTEM
using ::GetTempPathA;
#endif
using ::RemoveDirectoryA;
#endif
#if BOOST_WINAPI_PARTITION_APP_SYSTEM
using ::GetTempPathW;
#endif
using ::RemoveDirectoryW;

#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE BOOL_ CreateDirectoryA(LPCSTR_ pPathName, PSECURITY_ATTRIBUTES_ pSecurityAttributes)
{
    return ::CreateDirectoryA(pPathName, reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(pSecurityAttributes));
}
#endif

BOOST_FORCEINLINE BOOL_ CreateDirectoryW(LPCWSTR_ pPathName, PSECURITY_ATTRIBUTES_ pSecurityAttributes)
{
    return ::CreateDirectoryW(pPathName, reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(pSecurityAttributes));
}

#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE BOOL_ create_directory(LPCSTR_ pPathName, PSECURITY_ATTRIBUTES_ pSecurityAttributes)
{
    return ::CreateDirectoryA(pPathName, reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(pSecurityAttributes));
}
#if BOOST_WINAPI_PARTITION_APP_SYSTEM
BOOST_FORCEINLINE DWORD_ get_temp_path(DWORD_ length, LPSTR_ buffer)
{
    return ::GetTempPathA(length, buffer);
}
#endif
BOOST_FORCEINLINE BOOL_ remove_directory(LPCSTR_ pPathName)
{
    return ::RemoveDirectoryA(pPathName);
}
#endif

BOOST_FORCEINLINE BOOL_ create_directory(LPCWSTR_ pPathName, PSECURITY_ATTRIBUTES_ pSecurityAttributes)
{
    return ::CreateDirectoryW(pPathName, reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(pSecurityAttributes));
}
#if BOOST_WINAPI_PARTITION_APP_SYSTEM
BOOST_FORCEINLINE DWORD_ get_temp_path(DWORD_ length, LPWSTR_ buffer)
{
    return ::GetTempPathW(length, buffer);
}
#endif
BOOST_FORCEINLINE BOOL_ remove_directory(LPCWSTR_ pPathName)
{
    return ::RemoveDirectoryW(pPathName);
}

} // namespace winapi
} // namespace zr_boost_1_81

#include <boost/winapi/detail/footer.hpp>

#endif // BOOST_WINAPI_DIRECTORY_MANAGEMENT_HPP_INCLUDED_
