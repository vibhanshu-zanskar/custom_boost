// Copyright (c) 2016 Klemens D. Morgenstern
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


#ifndef BOOST_PROCESS_DETAIL_POSIX_ENV_INIT_HPP_
#define BOOST_PROCESS_DETAIL_POSIX_ENV_INIT_HPP_


#include <boost/process/detail/config.hpp>
#include <boost/process/detail/posix/handler.hpp>
#include <boost/process/environment.hpp>

namespace zr_boost_1_81 { namespace process { namespace detail { namespace posix {

template<typename Char>
struct env_init;

template<>
struct env_init<char> : handler_base_ext
{
    zr_boost_1_81::process::environment env;

    env_init(zr_boost_1_81::process::environment && env) : env(std::move(env)) {};
    env_init(const zr_boost_1_81::process::environment & env) : env(env) {};


    template <class Executor>
    void on_setup(Executor &exec) const
    {
        exec.env = env._env_impl;
    }

};

}}}}



#endif /* BOOST_PROCESS_DETAIL_WINDOWS_ENV_INIT_HPP_ */
