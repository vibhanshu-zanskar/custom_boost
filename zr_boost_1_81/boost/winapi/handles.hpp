/*
 * Copyright 2010 Vicente J. Botet Escriba
 * Copyright 2015 Andrey Semashev
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_HANDLES_HPP_INCLUDED_
#define BOOST_WINAPI_HANDLES_HPP_INCLUDED_

#include <boost/winapi/basic_types.hpp>
#include <boost/winapi/detail/header.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {
BOOST_WINAPI_IMPORT_EXCEPT_WM zr_boost_1_81::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
CloseHandle(zr_boost_1_81::winapi::HANDLE_ handle);

BOOST_WINAPI_IMPORT_EXCEPT_WM zr_boost_1_81::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
DuplicateHandle(
    zr_boost_1_81::winapi::HANDLE_ hSourceProcessHandle,
    zr_boost_1_81::winapi::HANDLE_ hSourceHandle,
    zr_boost_1_81::winapi::HANDLE_ hTargetProcessHandle,
    zr_boost_1_81::winapi::HANDLE_* lpTargetHandle,
    zr_boost_1_81::winapi::DWORD_ dwDesiredAccess,
    zr_boost_1_81::winapi::BOOL_ bInheritHandle,
    zr_boost_1_81::winapi::DWORD_ dwOptions);

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN10
BOOST_WINAPI_IMPORT zr_boost_1_81::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC
CompareObjectHandles(
    zr_boost_1_81::winapi::HANDLE_ hFirstObjectHandle,
    zr_boost_1_81::winapi::HANDLE_ hSecondObjectHandle);
#endif
} // extern "C"
#endif

namespace zr_boost_1_81 {
namespace winapi {

using ::CloseHandle;
using ::DuplicateHandle;

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN10
using ::CompareObjectHandles;
#endif

// Note: MSVC-14.1 does not interpret INVALID_HANDLE_VALUE_ initializer as a constant expression
#if defined( BOOST_USE_WINDOWS_H )
BOOST_CONSTEXPR_OR_CONST DWORD_ DUPLICATE_CLOSE_SOURCE_ = DUPLICATE_CLOSE_SOURCE;
BOOST_CONSTEXPR_OR_CONST DWORD_ DUPLICATE_SAME_ACCESS_ = DUPLICATE_SAME_ACCESS;
const HANDLE_ INVALID_HANDLE_VALUE_ = INVALID_HANDLE_VALUE;
#else
BOOST_CONSTEXPR_OR_CONST DWORD_ DUPLICATE_CLOSE_SOURCE_ = 1;
BOOST_CONSTEXPR_OR_CONST DWORD_ DUPLICATE_SAME_ACCESS_ = 2;
const HANDLE_ INVALID_HANDLE_VALUE_ = (HANDLE_)(-1);
#endif

BOOST_CONSTEXPR_OR_CONST DWORD_ duplicate_close_source = DUPLICATE_CLOSE_SOURCE_;
BOOST_CONSTEXPR_OR_CONST DWORD_ duplicate_same_access = DUPLICATE_SAME_ACCESS_;
// Note: The "unused" attribute here should not be necessary because the variable is a constant.
//       However, MinGW gcc 5.3 spams warnings about this particular constant.
const HANDLE_ invalid_handle_value BOOST_ATTRIBUTE_UNUSED = INVALID_HANDLE_VALUE_;

}
}

#include <boost/winapi/detail/footer.hpp>

#endif // BOOST_WINAPI_HANDLES_HPP_INCLUDED_
