// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_WINDOWS_SHELL_PATH_HPP
#define BOOST_PROCESS_WINDOWS_SHELL_PATH_HPP

#include <boost/process/detail/config.hpp>
#include <system_error>
#include <boost/process/filesystem.hpp>
#include <boost/winapi/basic_types.hpp>
#include <boost/winapi/get_system_directory.hpp>

namespace zr_boost_1_81 { namespace process { namespace detail { namespace windows {

inline zr_boost_1_81::process::filesystem::path shell_path()
{
    ::zr_boost_1_81::winapi::WCHAR_ sysdir[260];
    unsigned int size = ::zr_boost_1_81::winapi::get_system_directory(sysdir, sizeof(sysdir));
    if (!size)
        throw_last_error("GetSystemDirectory() failed");

    zr_boost_1_81::process::filesystem::path p = sysdir;
    return p / "cmd.exe";
}

inline zr_boost_1_81::process::filesystem::path shell_path(std::error_code &ec) noexcept
{

    ::zr_boost_1_81::winapi::WCHAR_ sysdir[260];
    unsigned int size = ::zr_boost_1_81::winapi::get_system_directory(sysdir, sizeof(sysdir));
    zr_boost_1_81::process::filesystem::path p;
    if (!size)
        ec = std::error_code(
                ::zr_boost_1_81::winapi::GetLastError(),
                std::system_category());
    else
    {
        ec.clear();
        p = sysdir;
        p /= "cmd.exe";
    }
    return p;
}

}}}}

#endif
