//
// Copyright (c) 2015-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/boostorg/beast
//

#ifndef BOOST_BEAST_CORE_IMPL_FILE_WIN32_IPP
#define BOOST_BEAST_CORE_IMPL_FILE_WIN32_IPP

#include <boost/beast/core/file_win32.hpp>

#if BOOST_BEAST_USE_WIN32_FILE

#include <boost/beast/core/detail/win32_unicode_path.hpp>
#include <boost/core/exchange.hpp>
#include <boost/winapi/access_rights.hpp>
#include <boost/winapi/error_codes.hpp>
#include <boost/winapi/get_last_error.hpp>
#include <limits>
#include <utility>

namespace zr_boost_1_81 {
namespace beast {

namespace detail {

// VFALCO Can't seem to get boost/detail/winapi to work with
//        this so use the non-Ex version for now.
BOOST_BEAST_DECL
zr_boost_1_81::winapi::BOOL_
set_file_pointer_ex(
    zr_boost_1_81::winapi::HANDLE_ hFile,
    zr_boost_1_81::winapi::LARGE_INTEGER_ lpDistanceToMove,
    zr_boost_1_81::winapi::PLARGE_INTEGER_ lpNewFilePointer,
    zr_boost_1_81::winapi::DWORD_ dwMoveMethod)
{
    auto dwHighPart = lpDistanceToMove.u.HighPart;
    auto dwLowPart = zr_boost_1_81::winapi::SetFilePointer(
        hFile,
        lpDistanceToMove.u.LowPart,
        &dwHighPart,
        dwMoveMethod);
    if(dwLowPart == zr_boost_1_81::winapi::INVALID_SET_FILE_POINTER_)
        return 0;
    if(lpNewFilePointer)
    {
        lpNewFilePointer->u.LowPart = dwLowPart;
        lpNewFilePointer->u.HighPart = dwHighPart;
    }
    return 1;
}

} // detail

file_win32::
~file_win32()
{
    if(h_ != zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_)
        zr_boost_1_81::winapi::CloseHandle(h_);
}

file_win32::
file_win32(file_win32&& other)
    : h_(zr_boost_1_81::exchange(other.h_,
        zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_))
{
}

file_win32&
file_win32::
operator=(file_win32&& other)
{
    if(&other == this)
        return *this;
    if(h_)
        zr_boost_1_81::winapi::CloseHandle(h_);
    h_ = other.h_;
    other.h_ = zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_;
    return *this;
}

void
file_win32::
native_handle(native_handle_type h)
{
     if(h_ != zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_)
        zr_boost_1_81::winapi::CloseHandle(h_);
    h_ = h;
}

void
file_win32::
close(error_code& ec)
{
    if(h_ != zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_)
    {
        if(! zr_boost_1_81::winapi::CloseHandle(h_))
            ec.assign(zr_boost_1_81::winapi::GetLastError(),
                system_category());
        else
            ec = {};
        h_ = zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_;
    }
    else
    {
        ec = {};
    }
}

void
file_win32::
open(char const* path, file_mode mode, error_code& ec)
{
    if(h_ != zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_)
    {
        zr_boost_1_81::winapi::CloseHandle(h_);
        h_ = zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_;
    }
    zr_boost_1_81::winapi::DWORD_ share_mode = 0;
    zr_boost_1_81::winapi::DWORD_ desired_access = 0;
    zr_boost_1_81::winapi::DWORD_ creation_disposition = 0;
    zr_boost_1_81::winapi::DWORD_ flags_and_attributes = 0;
/*
                             |                    When the file...
    This argument:           |             Exists            Does not exist
    -------------------------+------------------------------------------------------
    CREATE_ALWAYS            |            Truncates             Creates
    CREATE_NEW         +-----------+        Fails               Creates
    OPEN_ALWAYS     ===| does this |===>    Opens               Creates
    OPEN_EXISTING      +-----------+        Opens                Fails
    TRUNCATE_EXISTING        |            Truncates              Fails
*/
    switch(mode)
    {
    default:
    case file_mode::read:
        desired_access = zr_boost_1_81::winapi::GENERIC_READ_;
        share_mode = zr_boost_1_81::winapi::FILE_SHARE_READ_;
        creation_disposition = zr_boost_1_81::winapi::OPEN_EXISTING_;
        flags_and_attributes = 0x10000000; // FILE_FLAG_RANDOM_ACCESS
        break;

    case file_mode::scan:           
        desired_access = zr_boost_1_81::winapi::GENERIC_READ_;
        share_mode = zr_boost_1_81::winapi::FILE_SHARE_READ_;
        creation_disposition = zr_boost_1_81::winapi::OPEN_EXISTING_;
        flags_and_attributes = 0x08000000; // FILE_FLAG_SEQUENTIAL_SCAN
        break;

    case file_mode::write:          
        desired_access = zr_boost_1_81::winapi::GENERIC_READ_ |
                         zr_boost_1_81::winapi::GENERIC_WRITE_;
        creation_disposition = zr_boost_1_81::winapi::CREATE_ALWAYS_;
        flags_and_attributes = 0x10000000; // FILE_FLAG_RANDOM_ACCESS
        break;

    case file_mode::write_new:      
        desired_access = zr_boost_1_81::winapi::GENERIC_READ_ |
                         zr_boost_1_81::winapi::GENERIC_WRITE_;
        creation_disposition = zr_boost_1_81::winapi::CREATE_NEW_;
        flags_and_attributes = 0x10000000; // FILE_FLAG_RANDOM_ACCESS
        break;

    case file_mode::write_existing: 
        desired_access = zr_boost_1_81::winapi::GENERIC_READ_ |
                         zr_boost_1_81::winapi::GENERIC_WRITE_;
        creation_disposition = zr_boost_1_81::winapi::OPEN_EXISTING_;
        flags_and_attributes = 0x10000000; // FILE_FLAG_RANDOM_ACCESS
        break;

    case file_mode::append:         
        desired_access = zr_boost_1_81::winapi::GENERIC_READ_ |
                         zr_boost_1_81::winapi::GENERIC_WRITE_;

        creation_disposition = zr_boost_1_81::winapi::OPEN_ALWAYS_;
        flags_and_attributes = 0x08000000; // FILE_FLAG_SEQUENTIAL_SCAN
        break;

    case file_mode::append_existing:
        desired_access = zr_boost_1_81::winapi::GENERIC_READ_ |
                         zr_boost_1_81::winapi::GENERIC_WRITE_;
        creation_disposition = zr_boost_1_81::winapi::OPEN_EXISTING_;
        flags_and_attributes = 0x08000000; // FILE_FLAG_SEQUENTIAL_SCAN
        break;
    }
    
    detail::win32_unicode_path unicode_path(path, ec);
    if (ec)
        return;
    h_ = ::CreateFileW(
        unicode_path.c_str(),
        desired_access,
        share_mode,
        NULL,
        creation_disposition,
        flags_and_attributes,
        NULL);
    if (h_ == zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_)
    {
        ec.assign(zr_boost_1_81::winapi::GetLastError(),
            system_category());
        return;
    }
    if (mode == file_mode::append ||
        mode == file_mode::append_existing)
    {
        zr_boost_1_81::winapi::LARGE_INTEGER_ in;
        in.QuadPart = 0;
        if (!detail::set_file_pointer_ex(h_, in, 0,
            zr_boost_1_81::winapi::FILE_END_))
        {
            ec.assign(zr_boost_1_81::winapi::GetLastError(),
                system_category());
            zr_boost_1_81::winapi::CloseHandle(h_);
            h_ = zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_;
            return;
        }
    }
    ec = {};
}

std::uint64_t
file_win32::
size(error_code& ec) const
{
    if(h_ == zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_)
    {
        ec = make_error_code(errc::bad_file_descriptor);
        return 0;
    }
    zr_boost_1_81::winapi::LARGE_INTEGER_ fileSize;
    if(! zr_boost_1_81::winapi::GetFileSizeEx(h_, &fileSize))
    {
        ec.assign(zr_boost_1_81::winapi::GetLastError(),
            system_category());
        return 0;
    }
    ec = {};
    return fileSize.QuadPart;
}

std::uint64_t
file_win32::
pos(error_code& ec)
{
    if(h_ == zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_)
    {
        ec = make_error_code(errc::bad_file_descriptor);
        return 0;
    }
    zr_boost_1_81::winapi::LARGE_INTEGER_ in;
    zr_boost_1_81::winapi::LARGE_INTEGER_ out;
    in.QuadPart = 0;
    if(! detail::set_file_pointer_ex(h_, in, &out,
        zr_boost_1_81::winapi::FILE_CURRENT_))
    {
        ec.assign(zr_boost_1_81::winapi::GetLastError(),
            system_category());
        return 0;
    }
    ec = {};
    return out.QuadPart;
}

void
file_win32::
seek(std::uint64_t offset, error_code& ec)
{
    if(h_ == zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_)
    {
        ec = make_error_code(errc::bad_file_descriptor);
        return;
    }
    zr_boost_1_81::winapi::LARGE_INTEGER_ in;
    in.QuadPart = offset;
    if(! detail::set_file_pointer_ex(h_, in, 0,
        zr_boost_1_81::winapi::FILE_BEGIN_))
    {
        ec.assign(zr_boost_1_81::winapi::GetLastError(),
            system_category());
        return;
    }
    ec = {};
}

std::size_t
file_win32::
read(void* buffer, std::size_t n, error_code& ec)
{
    if(h_ == zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_)
    {
        ec = make_error_code(errc::bad_file_descriptor);
        return 0;
    }
    std::size_t nread = 0;
    while(n > 0)
    {
        zr_boost_1_81::winapi::DWORD_ amount;
        if(n > (std::numeric_limits<
                zr_boost_1_81::winapi::DWORD_>::max)())
            amount = (std::numeric_limits<
                zr_boost_1_81::winapi::DWORD_>::max)();
        else
            amount = static_cast<
                zr_boost_1_81::winapi::DWORD_>(n);
        zr_boost_1_81::winapi::DWORD_ bytesRead;
        if(! ::ReadFile(h_, buffer, amount, &bytesRead, 0))
        {
            auto const dwError = zr_boost_1_81::winapi::GetLastError();
            if(dwError != zr_boost_1_81::winapi::ERROR_HANDLE_EOF_)
                ec.assign(dwError, system_category());
            else
                ec = {};
            return nread;
        }
        if(bytesRead == 0)
            return nread;
        n -= bytesRead;
        nread += bytesRead;
        buffer = static_cast<char*>(buffer) + bytesRead;
    }
    ec = {};
    return nread;
}

std::size_t
file_win32::
write(void const* buffer, std::size_t n, error_code& ec)
{
    if(h_ == zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_)
    {
        ec = make_error_code(errc::bad_file_descriptor);
        return 0;
    }
    std::size_t nwritten = 0;
    while(n > 0)
    {
        zr_boost_1_81::winapi::DWORD_ amount;
        if(n > (std::numeric_limits<
                zr_boost_1_81::winapi::DWORD_>::max)())
            amount = (std::numeric_limits<
                zr_boost_1_81::winapi::DWORD_>::max)();
        else
            amount = static_cast<
                zr_boost_1_81::winapi::DWORD_>(n);
        zr_boost_1_81::winapi::DWORD_ bytesWritten;
        if(! ::WriteFile(h_, buffer, amount, &bytesWritten, 0))
        {
            auto const dwError = zr_boost_1_81::winapi::GetLastError();
            if(dwError != zr_boost_1_81::winapi::ERROR_HANDLE_EOF_)
                ec.assign(dwError, system_category());
            else
                ec = {};
            return nwritten;
        }
        if(bytesWritten == 0)
            return nwritten;
        n -= bytesWritten;
        nwritten += bytesWritten;
        buffer = static_cast<char const*>(buffer) + bytesWritten;
    }
    ec = {};
    return nwritten;
}

} // beast
} // boost

#endif

#endif
