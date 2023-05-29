// Copyright (c) 2016 Klemens D. Morgenstern
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_DETAIL_WINDOWS_FILE_DESCRIPTOR_HPP_
#define BOOST_PROCESS_DETAIL_WINDOWS_FILE_DESCRIPTOR_HPP_

#include <boost/winapi/basic_types.hpp>
#include <boost/winapi/handles.hpp>
#include <boost/winapi/file_management.hpp>
#include <string>
#include <boost/process/filesystem.hpp>
#include <boost/core/exchange.hpp>

namespace zr_boost_1_81 { namespace process { namespace detail { namespace windows {

struct file_descriptor
{
    enum mode_t
    {
        read  = 1,
        write = 2,
        read_write = 3
    };
    static ::zr_boost_1_81::winapi::DWORD_ desired_access(mode_t mode)
    {
        switch(mode)
        {
        case read:
            return ::zr_boost_1_81::winapi::GENERIC_READ_;
        case write:
            return ::zr_boost_1_81::winapi::GENERIC_WRITE_;
        case read_write:
            return ::zr_boost_1_81::winapi::GENERIC_READ_
                 | ::zr_boost_1_81::winapi::GENERIC_WRITE_;
        default:
            return 0u;
        }
    }

    file_descriptor() = default;
    file_descriptor(const zr_boost_1_81::process::filesystem::path& p, mode_t mode = read_write)
        : file_descriptor(p.native(), mode)
    {
    }

    file_descriptor(const std::string & path , mode_t mode = read_write)
#if defined(BOOST_NO_ANSI_APIS)
        : file_descriptor(::zr_boost_1_81::process::detail::convert(path), mode)
#else
        : file_descriptor(path.c_str(), mode)
#endif
    {}
    file_descriptor(const std::wstring & path, mode_t mode = read_write)
        : file_descriptor(path.c_str(), mode) {}

    file_descriptor(const char*    path, mode_t mode = read_write)
#if defined(BOOST_NO_ANSI_APIS)
        : file_descriptor(std::string(path), mode)
#else
        : _handle(
                ::zr_boost_1_81::winapi::create_file(
                        path,
                        desired_access(mode),
                        ::zr_boost_1_81::winapi::FILE_SHARE_READ_ |
                        ::zr_boost_1_81::winapi::FILE_SHARE_WRITE_,
                        nullptr,
                        ::zr_boost_1_81::winapi::OPEN_ALWAYS_,

                        ::zr_boost_1_81::winapi::FILE_ATTRIBUTE_NORMAL_,
                        nullptr
                ))
#endif
    {
    }
    file_descriptor(const wchar_t * path, mode_t mode = read_write)
        : _handle(
            ::zr_boost_1_81::winapi::create_file(
                    path,
                    desired_access(mode),
                    ::zr_boost_1_81::winapi::FILE_SHARE_READ_ |
                    ::zr_boost_1_81::winapi::FILE_SHARE_WRITE_,
                    nullptr,
                    ::zr_boost_1_81::winapi::OPEN_ALWAYS_,

                    ::zr_boost_1_81::winapi::FILE_ATTRIBUTE_NORMAL_,
                    nullptr
            ))
{

}
    file_descriptor(const file_descriptor & ) = delete;
    file_descriptor(file_descriptor &&other)
        : _handle( zr_boost_1_81::exchange(other._handle, ::zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_) )
    {
    }

    file_descriptor& operator=(const file_descriptor & ) = delete;
    file_descriptor& operator=(file_descriptor &&other)
    {
        if (_handle != ::zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_)
            ::zr_boost_1_81::winapi::CloseHandle(_handle);
        _handle = zr_boost_1_81::exchange(other._handle, ::zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_);
        return *this;
    }

    ~file_descriptor()
    {
        if (_handle != ::zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_)
            ::zr_boost_1_81::winapi::CloseHandle(_handle);
    }

    ::zr_boost_1_81::winapi::HANDLE_ handle() const { return _handle;}

private:
    ::zr_boost_1_81::winapi::HANDLE_ _handle = ::zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_;
};

}}}}

#endif /* BOOST_PROCESS_DETAIL_WINDOWS_FILE_DESCRIPTOR_HPP_ */
