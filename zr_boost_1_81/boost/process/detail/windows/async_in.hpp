// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_WINDOWS_INITIALIZERS_ASYNC_IN_HPP
#define BOOST_PROCESS_WINDOWS_INITIALIZERS_ASYNC_IN_HPP

#include <boost/winapi/process.hpp>
#include <boost/winapi/handles.hpp>
#include <boost/winapi/handle_info.hpp>
#include <boost/winapi/error_codes.hpp>

#include <boost/asio/write.hpp>
#include <boost/process/detail/handler_base.hpp>
#include <boost/process/detail/used_handles.hpp>
#include <boost/process/detail/windows/async_handler.hpp>
#include <boost/process/detail/windows/asio_fwd.hpp>
#include <boost/process/async_pipe.hpp>
#include <memory>
#include <future>

namespace zr_boost_1_81 { namespace process { namespace detail { namespace windows {


template<typename Buffer>
struct async_in_buffer : ::zr_boost_1_81::process::detail::windows::handler_base_ext,
                         ::zr_boost_1_81::process::detail::windows::require_io_context,
                         ::zr_boost_1_81::process::detail::uses_handles
{
    Buffer & buf;

    std::shared_ptr<std::promise<void>> promise;
    async_in_buffer operator>(std::future<void> & fut)
    {
        promise = std::make_shared<std::promise<void>>();
        fut = promise->get_future(); return std::move(*this);
    }

    std::shared_ptr<zr_boost_1_81::process::async_pipe> pipe;

    ::zr_boost_1_81::winapi::HANDLE_ get_used_handles() const
    {
        return std::move(*pipe).source().native_handle();
    }

    async_in_buffer(Buffer & buf) : buf(buf)
    {
    }
    template <typename Executor>
    inline void on_success(Executor&)
    {
        auto pipe_ = this->pipe;

        if (this->promise)
        {
            auto promise_ = this->promise;

            zr_boost_1_81::asio::async_write(*pipe_, buf,
                [promise_](const zr_boost_1_81::system::error_code & ec, std::size_t)
                {
                    if (ec && (ec.value() != ::zr_boost_1_81::winapi::ERROR_BROKEN_PIPE_))
                    {
                        std::error_code e(ec.value(), std::system_category());
                        promise_->set_exception(std::make_exception_ptr(process_error(e)));
                    }
                    promise_->set_value();
                });
        }
        else
            zr_boost_1_81::asio::async_write(*pipe_, buf,
                [pipe_](const zr_boost_1_81::system::error_code&, std::size_t){});

        std::move(*pipe_).source().close();


        this->pipe = nullptr;
    }

    template<typename Executor>
    void on_error(Executor &, const std::error_code &) const
    {
        ::zr_boost_1_81::winapi::CloseHandle(pipe->native_source());
    }

    template <typename WindowsExecutor>
    void on_setup(WindowsExecutor &exec)
    {
        if (!pipe)
            pipe = std::make_shared<zr_boost_1_81::process::async_pipe>(get_io_context(exec.seq));

        ::zr_boost_1_81::winapi::HANDLE_ source_handle = std::move(*pipe).source().native_handle();

        zr_boost_1_81::winapi::SetHandleInformation(source_handle,
                zr_boost_1_81::winapi::HANDLE_FLAG_INHERIT_,
                zr_boost_1_81::winapi::HANDLE_FLAG_INHERIT_);

        exec.startup_info.hStdInput = source_handle;
        exec.startup_info.dwFlags  |= zr_boost_1_81::winapi::STARTF_USESTDHANDLES_;
        exec.inherit_handles = true;
    }
};


}}}}

#endif
