//
// connection.hpp
// ~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef SERIALIZATION_CONNECTION_HPP
#define SERIALIZATION_CONNECTION_HPP

#include <boost/asio.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/tuple/tuple.hpp>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

namespace s11n_example {

/// The connection class provides serialization primitives on top of a socket.
/**
 * Each message sent using this class consists of:
 * @li An 8-byte header containing the length of the serialized data in
 * hexadecimal.
 * @li The serialized data.
 */
class connection
{
public:
  /// Constructor.
  connection(const zr_boost_1_81::asio::executor& ex)
    : socket_(ex)
  {
  }

  /// Get the underlying socket. Used for making a connection or for accepting
  /// an incoming connection.
  zr_boost_1_81::asio::ip::tcp::socket& socket()
  {
    return socket_;
  }

  /// Asynchronously write a data structure to the socket.
  template <typename T, typename Handler>
  void async_write(const T& t, Handler handler)
  {
    // Serialize the data first so we know how large it is.
    std::ostringstream archive_stream;
    zr_boost_1_81::archive::text_oarchive archive(archive_stream);
    archive << t;
    outbound_data_ = archive_stream.str();

    // Format the header.
    std::ostringstream header_stream;
    header_stream << std::setw(header_length)
      << std::hex << outbound_data_.size();
    if (!header_stream || header_stream.str().size() != header_length)
    {
      // Something went wrong, inform the caller.
      zr_boost_1_81::system::error_code error(zr_boost_1_81::asio::error::invalid_argument);
      zr_boost_1_81::asio::post(socket_.get_executor(), zr_boost_1_81::bind(handler, error));
      return;
    }
    outbound_header_ = header_stream.str();

    // Write the serialized data to the socket. We use "gather-write" to send
    // both the header and the data in a single write operation.
    std::vector<zr_boost_1_81::asio::const_buffer> buffers;
    buffers.push_back(zr_boost_1_81::asio::buffer(outbound_header_));
    buffers.push_back(zr_boost_1_81::asio::buffer(outbound_data_));
    zr_boost_1_81::asio::async_write(socket_, buffers, handler);
  }

  /// Asynchronously read a data structure from the socket.
  template <typename T, typename Handler>
  void async_read(T& t, Handler handler)
  {
    // Issue a read operation to read exactly the number of bytes in a header.
    void (connection::*f)(
        const zr_boost_1_81::system::error_code&,
        T&, zr_boost_1_81::tuple<Handler>)
      = &connection::handle_read_header<T, Handler>;
    zr_boost_1_81::asio::async_read(socket_, zr_boost_1_81::asio::buffer(inbound_header_),
        zr_boost_1_81::bind(f,
          this, zr_boost_1_81::asio::placeholders::error, zr_boost_1_81::ref(t),
          zr_boost_1_81::make_tuple(handler)));
  }

  /// Handle a completed read of a message header. The handler is passed using
  /// a tuple since zr_boost_1_81::bind seems to have trouble binding a function object
  /// created using zr_boost_1_81::bind as a parameter.
  template <typename T, typename Handler>
  void handle_read_header(const zr_boost_1_81::system::error_code& e,
      T& t, zr_boost_1_81::tuple<Handler> handler)
  {
    if (e)
    {
      zr_boost_1_81::get<0>(handler)(e);
    }
    else
    {
      // Determine the length of the serialized data.
      std::istringstream is(std::string(inbound_header_, header_length));
      std::size_t inbound_data_size = 0;
      if (!(is >> std::hex >> inbound_data_size))
      {
        // Header doesn't seem to be valid. Inform the caller.
        zr_boost_1_81::system::error_code error(zr_boost_1_81::asio::error::invalid_argument);
        zr_boost_1_81::get<0>(handler)(error);
        return;
      }

      // Start an asynchronous call to receive the data.
      inbound_data_.resize(inbound_data_size);
      void (connection::*f)(
          const zr_boost_1_81::system::error_code&,
          T&, zr_boost_1_81::tuple<Handler>)
        = &connection::handle_read_data<T, Handler>;
      zr_boost_1_81::asio::async_read(socket_, zr_boost_1_81::asio::buffer(inbound_data_),
        zr_boost_1_81::bind(f, this,
          zr_boost_1_81::asio::placeholders::error, zr_boost_1_81::ref(t), handler));
    }
  }

  /// Handle a completed read of message data.
  template <typename T, typename Handler>
  void handle_read_data(const zr_boost_1_81::system::error_code& e,
      T& t, zr_boost_1_81::tuple<Handler> handler)
  {
    if (e)
    {
      zr_boost_1_81::get<0>(handler)(e);
    }
    else
    {
      // Extract the data structure from the data just received.
      try
      {
        std::string archive_data(&inbound_data_[0], inbound_data_.size());
        std::istringstream archive_stream(archive_data);
        zr_boost_1_81::archive::text_iarchive archive(archive_stream);
        archive >> t;
      }
      catch (std::exception& e)
      {
        // Unable to decode data.
        zr_boost_1_81::system::error_code error(zr_boost_1_81::asio::error::invalid_argument);
        zr_boost_1_81::get<0>(handler)(error);
        return;
      }

      // Inform caller that data has been received ok.
      zr_boost_1_81::get<0>(handler)(e);
    }
  }

private:
  /// The underlying socket.
  zr_boost_1_81::asio::ip::tcp::socket socket_;

  /// The size of a fixed length header.
  enum { header_length = 8 };

  /// Holds an outbound header.
  std::string outbound_header_;

  /// Holds the outbound data.
  std::string outbound_data_;

  /// Holds an inbound header.
  char inbound_header_[header_length];

  /// Holds the inbound data.
  std::vector<char> inbound_data_;
};

typedef zr_boost_1_81::shared_ptr<connection> connection_ptr;

} // namespace s11n_example

#endif // SERIALIZATION_CONNECTION_HPP
