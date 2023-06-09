// Copyright (c) 2017 Klemens D. Morgenstern
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


#ifndef BOOST_PROCESS_DETAIL_POSIX_SIGCHLD_SERVICE_HPP_
#define BOOST_PROCESS_DETAIL_POSIX_SIGCHLD_SERVICE_HPP_

#include <boost/asio/dispatch.hpp>
#include <boost/asio/post.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/asio/strand.hpp>
#include <boost/optional.hpp>
#include <signal.h>
#include <functional>
#include <sys/wait.h>

namespace zr_boost_1_81 { namespace process { namespace detail { namespace posix {

class sigchld_service : public zr_boost_1_81::asio::detail::service_base<sigchld_service>
{
    zr_boost_1_81::asio::strand<zr_boost_1_81::asio::io_context::executor_type> _strand{get_io_context().get_executor()};
    zr_boost_1_81::asio::signal_set _signal_set{get_io_context(), SIGCHLD};

    std::vector<std::pair<::pid_t, std::function<void(int, std::error_code)>>> _receivers;
    inline void _handle_signal(const zr_boost_1_81::system::error_code & ec);
public:
    sigchld_service(zr_boost_1_81::asio::io_context & io_context)
        : zr_boost_1_81::asio::detail::service_base<sigchld_service>(io_context)
    {
    }

    template <typename SignalHandler>
    BOOST_ASIO_INITFN_RESULT_TYPE(SignalHandler,
        void (int, std::error_code))
    async_wait(::pid_t pid, SignalHandler && handler)
    {
        zr_boost_1_81::asio::async_completion<
        SignalHandler, void(zr_boost_1_81::system::error_code)> init{handler};

        auto & h = init.completion_handler;
        zr_boost_1_81::asio::dispatch(
                _strand,
                [this, pid, h]
                {
                    //check if the child actually is running first
                    int status;
                    auto pid_res = ::waitpid(pid, &status, WNOHANG);
                    if (pid_res < 0)
                    {
                        auto ec = get_last_error();
                        zr_boost_1_81::asio::post(
                                _strand,
                                [pid_res, ec, h]
                                {
                                    h(pid_res, ec);
                                });
                    }
                    else if ((pid_res == pid) && (WIFEXITED(status) || WIFSIGNALED(status)))
                        zr_boost_1_81::asio::post(
                                _strand,
                                [status, h]
                                {
                                    h(status, {}); //successfully exited already
                                });
                    else //still running
                    {
                        if (_receivers.empty())
                            _signal_set.async_wait(
                                    [this](const zr_boost_1_81::system::error_code &ec, int)
                                    {
                                        zr_boost_1_81::asio::dispatch(_strand, [this, ec]{this->_handle_signal(ec);});
                                    });
                        _receivers.emplace_back(pid, h);
                    }
                });

        return init.result.get();
    }
    void shutdown() override
    {
        _receivers.clear();
    }

    void cancel()
    {
        _signal_set.cancel();
    }
    void cancel(zr_boost_1_81::system::error_code & ec)
    {
        _signal_set.cancel(ec);
    }
};


void sigchld_service::_handle_signal(const zr_boost_1_81::system::error_code & ec)
{
    std::error_code ec_{ec.value(), std::system_category()};

    if (ec_)
    {
        for (auto & r : _receivers)
            r.second(-1, ec_);
        return;
    }

    for (auto & r : _receivers) {
        int status;
        int pid = ::waitpid(r.first, &status, WNOHANG);
        if (pid < 0) {
            // error (eg: the process no longer exists)
            r.second(-1, get_last_error());
            r.first = 0; // mark for deletion
        } else if (pid == r.first) {
            r.second(status, ec_);
            r.first = 0; // mark for deletion
        }
        // otherwise the process is still around
    }

    _receivers.erase(std::remove_if(_receivers.begin(), _receivers.end(),
            [](const std::pair<::pid_t, std::function<void(int, std::error_code)>> & p)
            {
                return p.first == 0;
            }),
            _receivers.end());

    if (!_receivers.empty())
    {
        _signal_set.async_wait(
            [this](const zr_boost_1_81::system::error_code & ec, int)
            {
                zr_boost_1_81::asio::post(_strand, [this, ec]{this->_handle_signal(ec);});
            });
    }
}


}
}
}
}




#endif
