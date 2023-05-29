//
// connection.cpp
// ~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include "connection.hpp"
#include <vector>
#include <boost/bind/bind.hpp>
#include "connection_manager.hpp"
#include "request_handler.hpp"

namespace http {
namespace server {

connection::connection(zr_boost_1_81::asio::io_context& io_context,
    connection_manager& manager, request_handler& handler)
  : socket_(io_context),
    connection_manager_(manager),
    request_handler_(handler)
{
}

zr_boost_1_81::asio::ip::tcp::socket& connection::socket()
{
  return socket_;
}

void connection::start()
{
  socket_.async_read_some(zr_boost_1_81::asio::buffer(buffer_),
      zr_boost_1_81::bind(&connection::handle_read, shared_from_this(),
        zr_boost_1_81::asio::placeholders::error,
        zr_boost_1_81::asio::placeholders::bytes_transferred));
}

void connection::stop()
{
  socket_.close();
}

void connection::handle_read(const zr_boost_1_81::system::error_code& e,
    std::size_t bytes_transferred)
{
  if (!e)
  {
    zr_boost_1_81::tribool result;
    zr_boost_1_81::tie(result, zr_boost_1_81::tuples::ignore) = request_parser_.parse(
        request_, buffer_.data(), buffer_.data() + bytes_transferred);

    if (result)
    {
      request_handler_.handle_request(request_, reply_);
      zr_boost_1_81::asio::async_write(socket_, reply_.to_buffers(),
          zr_boost_1_81::bind(&connection::handle_write, shared_from_this(),
            zr_boost_1_81::asio::placeholders::error));
    }
    else if (!result)
    {
      reply_ = reply::stock_reply(reply::bad_request);
      zr_boost_1_81::asio::async_write(socket_, reply_.to_buffers(),
          zr_boost_1_81::bind(&connection::handle_write, shared_from_this(),
            zr_boost_1_81::asio::placeholders::error));
    }
    else
    {
      socket_.async_read_some(zr_boost_1_81::asio::buffer(buffer_),
          zr_boost_1_81::bind(&connection::handle_read, shared_from_this(),
            zr_boost_1_81::asio::placeholders::error,
            zr_boost_1_81::asio::placeholders::bytes_transferred));
    }
  }
  else if (e != zr_boost_1_81::asio::error::operation_aborted)
  {
    connection_manager_.stop(shared_from_this());
  }
}

void connection::handle_write(const zr_boost_1_81::system::error_code& e)
{
  if (!e)
  {
    // Initiate graceful connection closure.
    zr_boost_1_81::system::error_code ignored_ec;
    socket_.shutdown(zr_boost_1_81::asio::ip::tcp::socket::shutdown_both, ignored_ec);
  }

  if (e != zr_boost_1_81::asio::error::operation_aborted)
  {
    connection_manager_.stop(shared_from_this());
  }
}

} // namespace server
} // namespace http
