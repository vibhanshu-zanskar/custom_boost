// Copyright (c) 2016 Klemens D. Morgenstern
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


#ifndef BOOST_PROCESS_DETAIL_WINDOWS_ENV_INIT_HPP_
#define BOOST_PROCESS_DETAIL_WINDOWS_ENV_INIT_HPP_

#include <boost/winapi/error_codes.hpp>
#include <boost/winapi/process.hpp>


#include <boost/process/detail/config.hpp>
#include <boost/process/detail/handler_base.hpp>
#include <boost/process/environment.hpp>

namespace zr_boost_1_81 { namespace process { namespace detail { namespace windows {

template<typename Char>
struct env_init : public ::zr_boost_1_81::process::detail::handler_base
{
    zr_boost_1_81::process::basic_environment<Char> env;

    env_init(zr_boost_1_81::process::basic_environment<Char> && env) : env(std::move(env)) {};
    env_init(const zr_boost_1_81::process::basic_environment<Char> & env) : env(env) {};

    constexpr static ::zr_boost_1_81::winapi::DWORD_ creation_flag(char)    {return 0u;}
    constexpr static ::zr_boost_1_81::winapi::DWORD_ creation_flag(wchar_t)
    {
       return ::zr_boost_1_81::winapi::CREATE_UNICODE_ENVIRONMENT_;
    }

    template <class WindowsExecutor>
    void on_setup(WindowsExecutor &exec) const
    {
        auto e = env.native_handle();
        if (*e == null_char<char>())
        {
            exec.set_error(std::error_code(::zr_boost_1_81::winapi::ERROR_BAD_ENVIRONMENT_, std::system_category()),
                    "Empty Environment");
        }

        exec.env = e;
        exec.creation_flags |= creation_flag(Char());
    }

};

}}}}



#endif /* BOOST_PROCESS_DETAIL_WINDOWS_ENV_INIT_HPP_ */
