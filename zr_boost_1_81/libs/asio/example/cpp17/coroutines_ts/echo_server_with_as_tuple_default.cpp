//
// echo_server_with_as_tuple_default.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <boost/asio/as_tuple.hpp>
#include <boost/asio/co_spawn.hpp>
#include <boost/asio/detached.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/asio/write.hpp>
#include <cstdio>

using zr_boost_1_81::asio::as_tuple_t;
using zr_boost_1_81::asio::ip::tcp;
using zr_boost_1_81::asio::awaitable;
using zr_boost_1_81::asio::co_spawn;
using zr_boost_1_81::asio::detached;
using zr_boost_1_81::asio::use_awaitable_t;
using default_token = as_tuple_t<use_awaitable_t<>>;
using tcp_acceptor = default_token::as_default_on_t<tcp::acceptor>;
using tcp_socket = default_token::as_default_on_t<tcp::socket>;
namespace this_coro = zr_boost_1_81::asio::this_coro;

awaitable<void> echo(tcp_socket socket)
{
  char data[1024];
  for (;;)
  {
    auto [e1, nread] = co_await socket.async_read_some(zr_boost_1_81::asio::buffer(data));
    if (nread == 0) break;
    auto [e2, nwritten] = co_await async_write(socket, zr_boost_1_81::asio::buffer(data, nread));
    if (nwritten != nread) break;
  }
}

awaitable<void> listener()
{
  auto executor = co_await this_coro::executor;
  tcp_acceptor acceptor(executor, {tcp::v4(), 55555});
  for (;;)
  {
    if (auto [e, socket] = co_await acceptor.async_accept(); socket.is_open())
      co_spawn(executor, echo(std::move(socket)), detached);
  }
}

int main()
{
  try
  {
    zr_boost_1_81::asio::io_context io_context(1);

    zr_boost_1_81::asio::signal_set signals(io_context, SIGINT, SIGTERM);
    signals.async_wait([&](auto, auto){ io_context.stop(); });

    co_spawn(io_context, listener(), detached);

    io_context.run();
  }
  catch (std::exception& e)
  {
    std::printf("Exception: %s\n", e.what());
  }
}
