//
// echo_server.cpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <boost/asio/detached.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/spawn.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/asio/write.hpp>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <iostream>

using zr_boost_1_81::asio::ip::tcp;

class session : public zr_boost_1_81::enable_shared_from_this<session>
{
public:
  explicit session(zr_boost_1_81::asio::io_context& io_context)
    : strand_(zr_boost_1_81::asio::make_strand(io_context)),
      socket_(io_context),
      timer_(io_context)
  {
  }

  tcp::socket& socket()
  {
    return socket_;
  }

  void go()
  {
    zr_boost_1_81::asio::spawn(strand_,
        zr_boost_1_81::bind(&session::echo,
          shared_from_this(), zr_boost_1_81::placeholders::_1),
        zr_boost_1_81::asio::detached_t());
    zr_boost_1_81::asio::spawn(strand_,
        zr_boost_1_81::bind(&session::timeout,
          shared_from_this(), zr_boost_1_81::placeholders::_1),
        zr_boost_1_81::asio::detached_t());
  }

private:
  void echo(zr_boost_1_81::asio::yield_context yield)
  {
    try
    {
      char data[128];
      for (;;)
      {
        timer_.expires_after(zr_boost_1_81::asio::chrono::seconds(10));
        std::size_t n = socket_.async_read_some(zr_boost_1_81::asio::buffer(data), yield);
        zr_boost_1_81::asio::async_write(socket_, zr_boost_1_81::asio::buffer(data, n), yield);
      }
    }
    catch (std::exception& e)
    {
      socket_.close();
      timer_.cancel();
    }
  }

  void timeout(zr_boost_1_81::asio::yield_context yield)
  {
    while (socket_.is_open())
    {
      zr_boost_1_81::system::error_code ignored_ec;
      timer_.async_wait(yield[ignored_ec]);
      if (timer_.expiry() <= zr_boost_1_81::asio::steady_timer::clock_type::now())
        socket_.close();
    }
  }

  zr_boost_1_81::asio::strand<zr_boost_1_81::asio::io_context::executor_type> strand_;
  tcp::socket socket_;
  zr_boost_1_81::asio::steady_timer timer_;
};

void do_accept(zr_boost_1_81::asio::io_context& io_context,
    unsigned short port, zr_boost_1_81::asio::yield_context yield)
{
  tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port));

  for (;;)
  {
    zr_boost_1_81::system::error_code ec;
    zr_boost_1_81::shared_ptr<session> new_session(new session(io_context));
    acceptor.async_accept(new_session->socket(), yield[ec]);
    if (!ec) new_session->go();
  }
}

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      std::cerr << "Usage: echo_server <port>\n";
      return 1;
    }

    zr_boost_1_81::asio::io_context io_context;

    zr_boost_1_81::asio::spawn(io_context,
        zr_boost_1_81::bind(do_accept, zr_boost_1_81::ref(io_context),
          atoi(argv[1]), zr_boost_1_81::placeholders::_1),
        zr_boost_1_81::asio::detached_t());

    io_context.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}
