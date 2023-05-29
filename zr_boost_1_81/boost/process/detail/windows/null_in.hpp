// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_WINDOWS_INITIALIZERS_NULL_IN_HPP
#define BOOST_PROCESS_WINDOWS_INITIALIZERS_NULL_IN_HPP

#include <boost/winapi/process.hpp>
#include <boost/winapi/handles.hpp>
#include <boost/winapi/handle_info.hpp>
#include <boost/process/detail/handler_base.hpp>
#include <boost/process/detail/used_handles.hpp>
#include <boost/process/detail/windows/file_descriptor.hpp>

namespace zr_boost_1_81 { namespace process { namespace detail { namespace windows {

struct null_in : public ::zr_boost_1_81::process::detail::handler_base, ::zr_boost_1_81::process::detail::uses_handles
{
    file_descriptor source{"NUL", file_descriptor::read};

    ::zr_boost_1_81::winapi::HANDLE_ get_used_handles() const { return source.handle(); }


public:
    template <class WindowsExecutor>
    void on_setup(WindowsExecutor &e) const
    {
        zr_boost_1_81::winapi::SetHandleInformation(source.handle(),
                zr_boost_1_81::winapi::HANDLE_FLAG_INHERIT_,
                zr_boost_1_81::winapi::HANDLE_FLAG_INHERIT_);

        e.startup_info.hStdInput = source.handle();
        e.startup_info.dwFlags  |= zr_boost_1_81::winapi::STARTF_USESTDHANDLES_;
        e.inherit_handles = true;
    }
};

}}}}

#endif
