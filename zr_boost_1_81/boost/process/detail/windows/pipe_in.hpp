// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_WINDOWS_INITIALIZERS_PIPE_IN_HPP
#define BOOST_PROCESS_WINDOWS_INITIALIZERS_PIPE_IN_HPP

#include <boost/winapi/process.hpp>
#include <boost/winapi/handles.hpp>
#include <boost/process/detail/used_handles.hpp>
#include <boost/process/detail/handler_base.hpp>

namespace zr_boost_1_81 { namespace process { namespace detail { namespace windows {

struct pipe_in : public ::zr_boost_1_81::process::detail::handler_base, ::zr_boost_1_81::process::detail::uses_handles
{
    ::zr_boost_1_81::winapi::HANDLE_ handle;

    ::zr_boost_1_81::winapi::HANDLE_ get_used_handles() const { return handle; }

    pipe_in(::zr_boost_1_81::winapi::HANDLE_ handle) : handle(handle) {}

    template<typename T> //async_pipe
    pipe_in(T & p) : handle(p.native_source())
    {
        p.assign_source(::zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_);
    }

    template <class WindowsExecutor>
    void on_setup(WindowsExecutor &e) const
    {
        zr_boost_1_81::winapi::SetHandleInformation(handle,
                zr_boost_1_81::winapi::HANDLE_FLAG_INHERIT_,
                zr_boost_1_81::winapi::HANDLE_FLAG_INHERIT_);

        e.startup_info.hStdInput = handle;
        e.startup_info.dwFlags  |= zr_boost_1_81::winapi::STARTF_USESTDHANDLES_;
        e.inherit_handles = true;
    }
    template<typename WindowsExecutor>
    void on_error(WindowsExecutor &, const std::error_code &) const
    {
        ::zr_boost_1_81::winapi::CloseHandle(handle);
    }

    template<typename WindowsExecutor>
    void on_success(WindowsExecutor &) const
    {
        ::zr_boost_1_81::winapi::CloseHandle(handle);
    }
};

class async_pipe;

struct async_pipe_in : public pipe_in
{
    async_pipe &pipe;

    template<typename AsyncPipe>
    async_pipe_in(AsyncPipe & p) : pipe_in(p.native_source()), pipe(p)
    {
    }

    template<typename Pipe, typename Executor>
    static void close(Pipe & pipe, Executor &)
    {
        zr_boost_1_81::system::error_code ec;
        std::move(pipe).source().close(ec);
    }

    template<typename Executor>
    void on_error(Executor & exec, const std::error_code &)
    {
        close(pipe, exec);
    }

    template<typename Executor>
    void on_success(Executor &exec)
    {
        close(pipe, exec);
    }
};


}}}}

#endif
