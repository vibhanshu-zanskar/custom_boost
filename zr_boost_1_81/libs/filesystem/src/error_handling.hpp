//  error_handling.hpp  --------------------------------------------------------------------//

//  Copyright 2002-2009, 2014 Beman Dawes
//  Copyright 2019 Andrey Semashev

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

//  See library home page at http://www.boost.org/libs/filesystem

//--------------------------------------------------------------------------------------//

#ifndef BOOST_FILESYSTEM_SRC_ERROR_HANDLING_HPP_
#define BOOST_FILESYSTEM_SRC_ERROR_HANDLING_HPP_

#include <cerrno>
#include <boost/system/error_code.hpp>
#include <boost/filesystem/config.hpp>
#include <boost/filesystem/exception.hpp>

#if defined(BOOST_WINDOWS_API)
#include <boost/winapi/basic_types.hpp>
#include <boost/winapi/get_last_error.hpp>
#include <boost/winapi/error_codes.hpp>
#endif

#include <boost/filesystem/detail/header.hpp> // must be the last #include

namespace zr_boost_1_81 {
namespace filesystem {

#if defined(BOOST_POSIX_API)

typedef int err_t;

//  POSIX uses a 0 return to indicate success
#define BOOST_ERRNO errno

#define BOOST_ERROR_FILE_NOT_FOUND ENOENT
#define BOOST_ERROR_ALREADY_EXISTS EEXIST
#define BOOST_ERROR_NOT_SUPPORTED ENOSYS

#else

typedef zr_boost_1_81::winapi::DWORD_ err_t;

//  Windows uses a non-0 return to indicate success
#define BOOST_ERRNO zr_boost_1_81::winapi::GetLastError()

#define BOOST_ERROR_FILE_NOT_FOUND zr_boost_1_81::winapi::ERROR_FILE_NOT_FOUND_
#define BOOST_ERROR_ALREADY_EXISTS zr_boost_1_81::winapi::ERROR_ALREADY_EXISTS_
#define BOOST_ERROR_NOT_SUPPORTED zr_boost_1_81::winapi::ERROR_NOT_SUPPORTED_

// Note: Legacy MinGW doesn't have ntstatus.h and doesn't define NTSTATUS error codes other than STATUS_SUCCESS.
#if !defined(NT_SUCCESS)
#define NT_SUCCESS(Status) (((zr_boost_1_81::winapi::NTSTATUS_)(Status)) >= 0)
#endif
#if !defined(STATUS_SUCCESS)
#define STATUS_SUCCESS ((zr_boost_1_81::winapi::NTSTATUS_)0x00000000l)
#endif
#if !defined(STATUS_NOT_IMPLEMENTED)
#define STATUS_NOT_IMPLEMENTED ((zr_boost_1_81::winapi::NTSTATUS_)0xC0000002l)
#endif
#if !defined(STATUS_INVALID_INFO_CLASS)
#define STATUS_INVALID_INFO_CLASS ((zr_boost_1_81::winapi::NTSTATUS_)0xC0000003l)
#endif
#if !defined(STATUS_INVALID_HANDLE)
#define STATUS_INVALID_HANDLE ((zr_boost_1_81::winapi::NTSTATUS_)0xC0000008l)
#endif
#if !defined(STATUS_INVALID_PARAMETER)
#define STATUS_INVALID_PARAMETER ((zr_boost_1_81::winapi::NTSTATUS_)0xC000000Dl)
#endif
#if !defined(STATUS_NO_SUCH_DEVICE)
#define STATUS_NO_SUCH_DEVICE ((zr_boost_1_81::winapi::NTSTATUS_)0xC000000El)
#endif
#if !defined(STATUS_NO_SUCH_FILE)
#define STATUS_NO_SUCH_FILE ((zr_boost_1_81::winapi::NTSTATUS_)0xC000000Fl)
#endif
#if !defined(STATUS_NO_MORE_FILES)
#define STATUS_NO_MORE_FILES ((zr_boost_1_81::winapi::NTSTATUS_)0x80000006l)
#endif
#if !defined(STATUS_BUFFER_OVERFLOW)
#define STATUS_BUFFER_OVERFLOW ((zr_boost_1_81::winapi::NTSTATUS_)0x80000005l)
#endif
#if !defined(STATUS_NO_MEMORY)
#define STATUS_NO_MEMORY ((zr_boost_1_81::winapi::NTSTATUS_)0xC0000017l)
#endif
#if !defined(STATUS_ACCESS_DENIED)
#define STATUS_ACCESS_DENIED ((zr_boost_1_81::winapi::NTSTATUS_)0xC0000022l)
#endif
#if !defined(STATUS_OBJECT_NAME_NOT_FOUND)
#define STATUS_OBJECT_NAME_NOT_FOUND ((zr_boost_1_81::winapi::NTSTATUS_)0xC0000034l)
#endif
#if !defined(STATUS_OBJECT_PATH_NOT_FOUND)
#define STATUS_OBJECT_PATH_NOT_FOUND ((zr_boost_1_81::winapi::NTSTATUS_)0xC000003Al)
#endif
#if !defined(STATUS_NOT_SUPPORTED)
#define STATUS_NOT_SUPPORTED ((zr_boost_1_81::winapi::NTSTATUS_)0xC00000BBl)
#endif
#if !defined(STATUS_BAD_NETWORK_PATH)
#define STATUS_BAD_NETWORK_PATH ((zr_boost_1_81::winapi::NTSTATUS_)0xC00000BEl)
#endif
#if !defined(STATUS_DEVICE_DOES_NOT_EXIST)
#define STATUS_DEVICE_DOES_NOT_EXIST ((zr_boost_1_81::winapi::NTSTATUS_)0xC00000C0l)
#endif
#if !defined(STATUS_BAD_NETWORK_NAME)
#define STATUS_BAD_NETWORK_NAME ((zr_boost_1_81::winapi::NTSTATUS_)0xC00000CCl)
#endif
#if !defined(STATUS_DIRECTORY_NOT_EMPTY)
#define STATUS_DIRECTORY_NOT_EMPTY ((zr_boost_1_81::winapi::NTSTATUS_)0xC0000101l)
#endif
#if !defined(STATUS_NOT_A_DIRECTORY)
#define STATUS_NOT_A_DIRECTORY ((zr_boost_1_81::winapi::NTSTATUS_)0xC0000103l)
#endif
#if !defined(STATUS_NOT_FOUND)
#define STATUS_NOT_FOUND ((zr_boost_1_81::winapi::NTSTATUS_)0xC0000225l)
#endif

//! Converts NTSTATUS error codes to Win32 error codes for reporting
inline zr_boost_1_81::winapi::DWORD_ translate_ntstatus(zr_boost_1_81::winapi::NTSTATUS_ status)
{
    // We have to cast to unsigned integral type to avoid signed overflow and narrowing conversion in the constants.
    switch (static_cast< zr_boost_1_81::winapi::ULONG_ >(status))
    {
    case static_cast< zr_boost_1_81::winapi::ULONG_ >(STATUS_NO_MEMORY):
        return zr_boost_1_81::winapi::ERROR_OUTOFMEMORY_;
    case static_cast< zr_boost_1_81::winapi::ULONG_ >(STATUS_BUFFER_OVERFLOW):
        return zr_boost_1_81::winapi::ERROR_BUFFER_OVERFLOW_;
    case static_cast< zr_boost_1_81::winapi::ULONG_ >(STATUS_INVALID_HANDLE):
        return zr_boost_1_81::winapi::ERROR_INVALID_HANDLE_;
    case static_cast< zr_boost_1_81::winapi::ULONG_ >(STATUS_INVALID_PARAMETER):
        return zr_boost_1_81::winapi::ERROR_INVALID_PARAMETER_;
    case static_cast< zr_boost_1_81::winapi::ULONG_ >(STATUS_NO_MORE_FILES):
        return zr_boost_1_81::winapi::ERROR_NO_MORE_FILES_;
    case static_cast< zr_boost_1_81::winapi::ULONG_ >(STATUS_NO_SUCH_DEVICE):
    case static_cast< zr_boost_1_81::winapi::ULONG_ >(STATUS_DEVICE_DOES_NOT_EXIST):
        return zr_boost_1_81::winapi::ERROR_DEV_NOT_EXIST_;
    case static_cast< zr_boost_1_81::winapi::ULONG_ >(STATUS_NO_SUCH_FILE):
    case static_cast< zr_boost_1_81::winapi::ULONG_ >(STATUS_OBJECT_NAME_NOT_FOUND):
    case static_cast< zr_boost_1_81::winapi::ULONG_ >(STATUS_OBJECT_PATH_NOT_FOUND):
        return zr_boost_1_81::winapi::ERROR_FILE_NOT_FOUND_;
    case static_cast< zr_boost_1_81::winapi::ULONG_ >(STATUS_ACCESS_DENIED):
        return zr_boost_1_81::winapi::ERROR_ACCESS_DENIED_;
    case static_cast< zr_boost_1_81::winapi::ULONG_ >(STATUS_BAD_NETWORK_PATH):
        return zr_boost_1_81::winapi::ERROR_BAD_NETPATH_;
    case static_cast< zr_boost_1_81::winapi::ULONG_ >(STATUS_BAD_NETWORK_NAME):
        return zr_boost_1_81::winapi::ERROR_BAD_NET_NAME_;
    case static_cast< zr_boost_1_81::winapi::ULONG_ >(STATUS_DIRECTORY_NOT_EMPTY):
        return zr_boost_1_81::winapi::ERROR_DIR_NOT_EMPTY_;
    case static_cast< zr_boost_1_81::winapi::ULONG_ >(STATUS_NOT_A_DIRECTORY):
        return zr_boost_1_81::winapi::ERROR_DIRECTORY_; // The directory name is invalid
    case static_cast< zr_boost_1_81::winapi::ULONG_ >(STATUS_NOT_FOUND):
        return zr_boost_1_81::winapi::ERROR_NOT_FOUND_;
    // map "invalid info class" to "not supported" as this error likely indicates that the kernel does not support what we request
    case static_cast< zr_boost_1_81::winapi::ULONG_ >(STATUS_INVALID_INFO_CLASS):
    default:
        return zr_boost_1_81::winapi::ERROR_NOT_SUPPORTED_;
    }
}

#endif

//  error handling helpers  ----------------------------------------------------------//

// Implemented in exception.cpp
void emit_error(err_t error_num, system::error_code* ec, const char* message);
void emit_error(err_t error_num, path const& p, system::error_code* ec, const char* message);
void emit_error(err_t error_num, path const& p1, path const& p2, system::error_code* ec, const char* message);

inline bool error(err_t error_num, system::error_code* ec, const char* message)
{
    if (BOOST_LIKELY(!error_num))
    {
        if (ec)
            ec->clear();
        return false;
    }
    else
    { //  error
        filesystem::emit_error(error_num, ec, message);
        return true;
    }
}

inline bool error(err_t error_num, path const& p, system::error_code* ec, const char* message)
{
    if (BOOST_LIKELY(!error_num))
    {
        if (ec)
            ec->clear();
        return false;
    }
    else
    { //  error
        filesystem::emit_error(error_num, p, ec, message);
        return true;
    }
}

inline bool error(err_t error_num, path const& p1, path const& p2, system::error_code* ec, const char* message)
{
    if (BOOST_LIKELY(!error_num))
    {
        if (ec)
            ec->clear();
        return false;
    }
    else
    { //  error
        filesystem::emit_error(error_num, p1, p2, ec, message);
        return true;
    }
}

} // namespace filesystem
} // namespace zr_boost_1_81

#include <boost/filesystem/detail/footer.hpp>

#endif // BOOST_FILESYSTEM_SRC_ERROR_HANDLING_HPP_
