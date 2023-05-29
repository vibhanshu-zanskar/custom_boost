//
// blocking_tcp_client.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <boost/asio/buffer.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/system/system_error.hpp>
#include <boost/asio/write.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include <boost/lambda/bind.hpp>
#include <boost/lambda/lambda.hpp>

using zr_boost_1_81::asio::ip::tcp;
using zr_boost_1_81::lambda::bind;
using zr_boost_1_81::lambda::var;
using zr_boost_1_81::lambda::_1;
using zr_boost_1_81::lambda::_2;

//----------------------------------------------------------------------

//
// This class manages socket timeouts by running the io_context using the timed
// io_context::run_for() member function. Each asynchronous operation is given
// a timeout within which it must complete. The socket operations themselves
// use zr_boost_1_81::lambda function objects as completion handlers. For a given
// socket operation, the client object runs the io_context to block thread
// execution until the operation completes or the timeout is reached. If the
// io_context::run_for() function times out, the socket is closed and the
// outstanding asynchronous operation is cancelled.
//
class client
{
public:
  client()
    : socket_(io_context_)
  {
  }

  void connect(const std::string& host, const std::string& service,
      zr_boost_1_81::asio::chrono::steady_clock::duration timeout)
  {
    // Resolve the host name and service to a list of endpoints.
    tcp::resolver::results_type endpoints =
      tcp::resolver(io_context_).resolve(host, service);

    // Start the asynchronous operation itself. The zr_boost_1_81::lambda function
    // object is used as a callback and will update the ec variable when the
    // operation completes. The blocking_udp_client.cpp example shows how you
    // can use zr_boost_1_81::bind rather than zr_boost_1_81::lambda.
    zr_boost_1_81::system::error_code ec;
    zr_boost_1_81::asio::async_connect(socket_, endpoints, var(ec) = _1);

    // Run the operation until it completes, or until the timeout.
    run(timeout);

    // Determine whether a connection was successfully established.
    if (ec)
      throw zr_boost_1_81::system::system_error(ec);
  }

  std::string read_line(zr_boost_1_81::asio::chrono::steady_clock::duration timeout)
  {
    // Start the asynchronous operation. The zr_boost_1_81::lambda function object is
    // used as a callback and will update the ec variable when the operation
    // completes. The blocking_udp_client.cpp example shows how you can use
    // zr_boost_1_81::bind rather than zr_boost_1_81::lambda.
    zr_boost_1_81::system::error_code ec;
    std::size_t n = 0;
    zr_boost_1_81::asio::async_read_until(socket_,
        zr_boost_1_81::asio::dynamic_buffer(input_buffer_),
        '\n', (var(ec) = _1, var(n) = _2));

    // Run the operation until it completes, or until the timeout.
    run(timeout);

    // Determine whether the read completed successfully.
    if (ec)
      throw zr_boost_1_81::system::system_error(ec);

    std::string line(input_buffer_.substr(0, n - 1));
    input_buffer_.erase(0, n);
    return line;
  }

  void write_line(const std::string& line,
      zr_boost_1_81::asio::chrono::steady_clock::duration timeout)
  {
    std::string data = line + "\n";

    // Start the asynchronous operation. The zr_boost_1_81::lambda function object is
    // used as a callback and will update the ec variable when the operation
    // completes. The blocking_udp_client.cpp example shows how you can use
    // zr_boost_1_81::bind rather than zr_boost_1_81::lambda.
    zr_boost_1_81::system::error_code ec;
    zr_boost_1_81::asio::async_write(socket_, zr_boost_1_81::asio::buffer(data), var(ec) = _1);

    // Run the operation until it completes, or until the timeout.
    run(timeout);

    // Determine whether the read completed successfully.
    if (ec)
      throw zr_boost_1_81::system::system_error(ec);
  }

private:
  void run(zr_boost_1_81::asio::chrono::steady_clock::duration timeout)
  {
    // Restart the io_context, as it may have been left in the "stopped" state
    // by a previous operation.
    io_context_.restart();

    // Block until the asynchronous operation has completed, or timed out. If
    // the pending asynchronous operation is a composed operation, the deadline
    // applies to the entire operation, rather than individual operations on
    // the socket.
    io_context_.run_for(timeout);

    // If the asynchronous operation completed successfully then the io_context
    // would have been stopped due to running out of work. If it was not
    // stopped, then the io_context::run_for call must have timed out.
    if (!io_context_.stopped())
    {
      // Close the socket to cancel the outstanding asynchronous operation.
      socket_.close();

      // Run the io_context again until the operation completes.
      io_context_.run();
    }
  }

  zr_boost_1_81::asio::io_context io_context_;
  tcp::socket socket_;
  std::string input_buffer_;
};

//----------------------------------------------------------------------

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 4)
    {
      std::cerr << "Usage: blocking_tcp_client <host> <port> <message>\n";
      return 1;
    }

    client c;
    c.connect(argv[1], argv[2], zr_boost_1_81::asio::chrono::seconds(10));

    zr_boost_1_81::asio::chrono::steady_clock::time_point time_sent =
      zr_boost_1_81::asio::chrono::steady_clock::now();

    c.write_line(argv[3], zr_boost_1_81::asio::chrono::seconds(10));

    for (;;)
    {
      std::string line = c.read_line(zr_boost_1_81::asio::chrono::seconds(10));

      // Keep going until we get back the line that was sent.
      if (line == argv[3])
        break;
    }

    zr_boost_1_81::asio::chrono::steady_clock::time_point time_received =
      zr_boost_1_81::asio::chrono::steady_clock::now();

    std::cout << "Round trip time: ";
    std::cout << zr_boost_1_81::asio::chrono::duration_cast<
      zr_boost_1_81::asio::chrono::microseconds>(
        time_received - time_sent).count();
    std::cout << " microseconds\n";
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}
