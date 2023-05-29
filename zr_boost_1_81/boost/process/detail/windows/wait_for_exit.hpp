// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
// Copyright (c) 2016 Klemens D. Morgenstern
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_WINDOWS_WAIT_FOR_EXIT_HPP
#define BOOST_PROCESS_WINDOWS_WAIT_FOR_EXIT_HPP

#include <boost/process/detail/config.hpp>
#include <system_error>
#include <boost/winapi/synchronization.hpp>
#include <boost/winapi/process.hpp>
#include <boost/process/detail/windows/child_handle.hpp>
#include <chrono>

namespace zr_boost_1_81 { namespace process { namespace detail { namespace windows {

inline void wait(child_handle &p, int & exit_code, std::error_code &ec) noexcept
{
    ::zr_boost_1_81::winapi::DWORD_ _exit_code = 1;

    if (::zr_boost_1_81::winapi::WaitForSingleObject(p.process_handle(),
        ::zr_boost_1_81::winapi::infinite) == ::zr_boost_1_81::winapi::wait_failed)
            ec = std::error_code(
                ::zr_boost_1_81::winapi::GetLastError(),
                std::system_category());
    else if (!::zr_boost_1_81::winapi::GetExitCodeProcess(p.process_handle(), &_exit_code))
            ec = std::error_code(
                ::zr_boost_1_81::winapi::GetLastError(),
                std::system_category());
    else
        ec.clear();

    ::zr_boost_1_81::winapi::CloseHandle(p.proc_info.hProcess);
    p.proc_info.hProcess = ::zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_;
    exit_code = static_cast<int>(_exit_code);
}

inline void wait(child_handle &p, int & exit_code)
{
    std::error_code ec;
    wait(p, exit_code, ec);
    zr_boost_1_81::process::detail::throw_error(ec, "wait error");
}

template< class Clock, class Duration >
inline bool wait_until(
        child_handle &p,
        int & exit_code,
        const std::chrono::time_point<Clock, Duration>& timeout_time,
        std::error_code &ec) noexcept
{
    std::chrono::milliseconds ms =
            std::chrono::duration_cast<std::chrono::milliseconds>(
                    timeout_time - Clock::now());

    ::zr_boost_1_81::winapi::DWORD_ wait_code;
    wait_code = ::zr_boost_1_81::winapi::WaitForSingleObject(p.process_handle(),
                    static_cast<::zr_boost_1_81::winapi::DWORD_>(ms.count()));

    if (wait_code == ::zr_boost_1_81::winapi::wait_failed)
        ec = std::error_code(
            ::zr_boost_1_81::winapi::GetLastError(),
            std::system_category());
    else if (wait_code == ::zr_boost_1_81::winapi::wait_timeout)
        return false;

    ::zr_boost_1_81::winapi::DWORD_ _exit_code;
    if (!::zr_boost_1_81::winapi::GetExitCodeProcess(p.process_handle(), &_exit_code))
        ec = std::error_code(
            ::zr_boost_1_81::winapi::GetLastError(),
            std::system_category());
    else
        ec.clear();

    exit_code = static_cast<int>(_exit_code);
    ::zr_boost_1_81::winapi::CloseHandle(p.proc_info.hProcess);
    p.proc_info.hProcess = ::zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_;
    return true;
}

template< class Clock, class Duration >
inline bool wait_until(
        child_handle &p,
        int & exit_code,
        const std::chrono::time_point<Clock, Duration>& timeout_time)
{
    std::error_code ec;
    bool b = wait_until(p, exit_code, timeout_time, ec);
    zr_boost_1_81::process::detail::throw_error(ec, "wait_until error");
    return b;
}

template< class Rep, class Period >
inline bool wait_for(
        child_handle &p,
        int & exit_code,
        const std::chrono::duration<Rep, Period>& rel_time,
        std::error_code &ec) noexcept
{
    return wait_until(p, exit_code, std::chrono::steady_clock::now() + rel_time, ec);
}

template< class Rep, class Period >
inline bool wait_for(
        child_handle &p,
        int & exit_code,
        const std::chrono::duration<Rep, Period>& rel_time)
{
    std::error_code ec;
    bool b = wait_for(p, exit_code, rel_time, ec);
    zr_boost_1_81::process::detail::throw_error(ec, "wait_for error");
    return b;
}

}}}}

#endif
