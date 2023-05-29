//
// connect_pair.cpp
// ~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <string>
#include <cctype>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/array.hpp>
#include <boost/bind/bind.hpp>

#if defined(BOOST_ASIO_HAS_LOCAL_SOCKETS)

using zr_boost_1_81::asio::local::stream_protocol;

class uppercase_filter
{
public:
  uppercase_filter(zr_boost_1_81::asio::io_context& io_context)
    : socket_(io_context)
  {
  }

  stream_protocol::socket& socket()
  {
    return socket_;
  }

  void start()
  {
    // Wait for request.
    socket_.async_read_some(zr_boost_1_81::asio::buffer(data_),
        zr_boost_1_81::bind(&uppercase_filter::handle_read,
          this, zr_boost_1_81::asio::placeholders::error,
          zr_boost_1_81::asio::placeholders::bytes_transferred));
  }

private:
  void handle_read(const zr_boost_1_81::system::error_code& ec, std::size_t size)
  {
    if (!ec)
    {
      // Compute result.
      for (std::size_t i = 0; i < size; ++i)
        data_[i] = std::toupper(data_[i]);

      // Send result.
      zr_boost_1_81::asio::async_write(socket_, zr_boost_1_81::asio::buffer(data_, size),
          zr_boost_1_81::bind(&uppercase_filter::handle_write,
            this, zr_boost_1_81::asio::placeholders::error));
    }
    else
    {
      throw zr_boost_1_81::system::system_error(ec);
    }
  }

  void handle_write(const zr_boost_1_81::system::error_code& ec)
  {
    if (!ec)
    {
      // Wait for request.
      socket_.async_read_some(zr_boost_1_81::asio::buffer(data_),
          zr_boost_1_81::bind(&uppercase_filter::handle_read,
            this, zr_boost_1_81::asio::placeholders::error,
            zr_boost_1_81::asio::placeholders::bytes_transferred));
    }
    else
    {
      throw zr_boost_1_81::system::system_error(ec);
    }
  }

  stream_protocol::socket socket_;
  zr_boost_1_81::array<char, 512> data_;
};

void run(zr_boost_1_81::asio::io_context* io_context)
{
  try
  {
    io_context->run();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception in thread: " << e.what() << "\n";
    std::exit(1);
  }
}

int main()
{
  try
  {
    zr_boost_1_81::asio::io_context io_context;

    // Create filter and establish a connection to it.
    uppercase_filter filter(io_context);
    stream_protocol::socket socket(io_context);
    zr_boost_1_81::asio::local::connect_pair(socket, filter.socket());
    filter.start();

    // The io_context runs in a background thread to perform filtering.
    zr_boost_1_81::thread thread(zr_boost_1_81::bind(run, &io_context));

    for (;;)
    {
      // Collect request from user.
      std::cout << "Enter a string: ";
      std::string request;
      std::getline(std::cin, request);

      // Send request to filter.
      zr_boost_1_81::asio::write(socket, zr_boost_1_81::asio::buffer(request));

      // Wait for reply from filter.
      std::vector<char> reply(request.size());
      zr_boost_1_81::asio::read(socket, zr_boost_1_81::asio::buffer(reply));

      // Show reply to user.
      std::cout << "Result: ";
      std::cout.write(&reply[0], request.size());
      std::cout << std::endl;
    }
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
    std::exit(1);
  }
}

#else // defined(BOOST_ASIO_HAS_LOCAL_SOCKETS)
# error Local sockets not available on this platform.
#endif // defined(BOOST_ASIO_HAS_LOCAL_SOCKETS)
