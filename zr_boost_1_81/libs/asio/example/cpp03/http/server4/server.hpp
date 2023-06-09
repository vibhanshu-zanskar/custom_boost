//
// server.hpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HTTP_SERVER4_SERVER_HPP
#define HTTP_SERVER4_SERVER_HPP

#include <boost/asio.hpp>
#include <string>
#include <boost/array.hpp>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include "request_parser.hpp"

namespace http {
namespace server4 {

struct request;
struct reply;

/// The top-level coroutine of the HTTP server.
class server : zr_boost_1_81::asio::coroutine
{
public:
  /// Construct the server to listen on the specified TCP address and port, and
  /// serve up files from the given directory.
  explicit server(zr_boost_1_81::asio::io_context& io_context,
      const std::string& address, const std::string& port,
      zr_boost_1_81::function<void(const request&, reply&)> request_handler);

  /// Perform work associated with the server.
  void operator()(
      zr_boost_1_81::system::error_code ec = zr_boost_1_81::system::error_code(),
      std::size_t length = 0);

private:
  typedef zr_boost_1_81::asio::ip::tcp tcp;

  /// The user-supplied handler for all incoming requests.
  zr_boost_1_81::function<void(const request&, reply&)> request_handler_;

  /// Acceptor used to listen for incoming connections.
  zr_boost_1_81::shared_ptr<tcp::acceptor> acceptor_;

  /// The current connection from a client.
  zr_boost_1_81::shared_ptr<tcp::socket> socket_;

  /// Buffer for incoming data.
  zr_boost_1_81::shared_ptr<zr_boost_1_81::array<char, 8192> > buffer_;

  /// The incoming request.
  zr_boost_1_81::shared_ptr<request> request_;

  /// Whether the request is valid or not.
  zr_boost_1_81::tribool valid_request_;

  /// The parser for the incoming request.
  request_parser request_parser_;

  /// The reply to be sent back to the client.
  zr_boost_1_81::shared_ptr<reply> reply_;
};

} // namespace server4
} // namespace http

#endif // HTTP_SERVER4_SERVER_HPP
