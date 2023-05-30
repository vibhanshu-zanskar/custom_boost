//
// async_client.cpp
// ~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

using zr_boost_1_81::asio::ip::tcp;

class client
{
public:
  client(zr_boost_1_81::asio::io_context& io_context,
      const std::string& server, const std::string& path)
    : resolver_(io_context),
      socket_(io_context)
  {
    // Form the request. We specify the "Connection: close" header so that the
    // server will close the socket after transmitting the response. This will
    // allow us to treat all data up until the EOF as the content.
    std::ostream request_stream(&request_);
    request_stream << "GET " << path << " HTTP/1.0\r\n";
    request_stream << "Host: " << server << "\r\n";
    request_stream << "Accept: */*\r\n";
    request_stream << "Connection: close\r\n\r\n";

    // Start an asynchronous resolve to translate the server and service names
    // into a list of endpoints.
    resolver_.async_resolve(server, "http",
        zr_boost_1_81::bind(&client::handle_resolve, this,
          zr_boost_1_81::asio::placeholders::error,
          zr_boost_1_81::asio::placeholders::results));
  }

private:
  void handle_resolve(const zr_boost_1_81::system::error_code& err,
      const tcp::resolver::results_type& endpoints)
  {
    if (!err)
    {
      // Attempt a connection to each endpoint in the list until we
      // successfully establish a connection.
      zr_boost_1_81::asio::async_connect(socket_, endpoints,
          zr_boost_1_81::bind(&client::handle_connect, this,
            zr_boost_1_81::asio::placeholders::error));
    }
    else
    {
      std::cout << "Error: " << err.message() << "\n";
    }
  }

  void handle_connect(const zr_boost_1_81::system::error_code& err)
  {
    if (!err)
    {
      // The connection was successful. Send the request.
      zr_boost_1_81::asio::async_write(socket_, request_,
          zr_boost_1_81::bind(&client::handle_write_request, this,
            zr_boost_1_81::asio::placeholders::error));
    }
    else
    {
      std::cout << "Error: " << err.message() << "\n";
    }
  }

  void handle_write_request(const zr_boost_1_81::system::error_code& err)
  {
    if (!err)
    {
      // Read the response status line. The response_ streambuf will
      // automatically grow to accommodate the entire line. The growth may be
      // limited by passing a maximum size to the streambuf constructor.
      zr_boost_1_81::asio::async_read_until(socket_, response_, "\r\n",
          zr_boost_1_81::bind(&client::handle_read_status_line, this,
            zr_boost_1_81::asio::placeholders::error));
    }
    else
    {
      std::cout << "Error: " << err.message() << "\n";
    }
  }

  void handle_read_status_line(const zr_boost_1_81::system::error_code& err)
  {
    if (!err)
    {
      // Check that response is OK.
      std::istream response_stream(&response_);
      std::string http_version;
      response_stream >> http_version;
      unsigned int status_code;
      response_stream >> status_code;
      std::string status_message;
      std::getline(response_stream, status_message);
      if (!response_stream || http_version.substr(0, 5) != "HTTP/")
      {
        std::cout << "Invalid response\n";
        return;
      }
      if (status_code != 200)
      {
        std::cout << "Response returned with status code ";
        std::cout << status_code << "\n";
        return;
      }

      // Read the response headers, which are terminated by a blank line.
      zr_boost_1_81::asio::async_read_until(socket_, response_, "\r\n\r\n",
          zr_boost_1_81::bind(&client::handle_read_headers, this,
            zr_boost_1_81::asio::placeholders::error));
    }
    else
    {
      std::cout << "Error: " << err << "\n";
    }
  }

  void handle_read_headers(const zr_boost_1_81::system::error_code& err)
  {
    if (!err)
    {
      // Process the response headers.
      std::istream response_stream(&response_);
      std::string header;
      while (std::getline(response_stream, header) && header != "\r")
        std::cout << header << "\n";
      std::cout << "\n";

      // Write whatever content we already have to output.
      if (response_.size() > 0)
        std::cout << &response_;

      // Start reading remaining data until EOF.
      zr_boost_1_81::asio::async_read(socket_, response_,
          zr_boost_1_81::asio::transfer_at_least(1),
          zr_boost_1_81::bind(&client::handle_read_content, this,
            zr_boost_1_81::asio::placeholders::error));
    }
    else
    {
      std::cout << "Error: " << err << "\n";
    }
  }

  void handle_read_content(const zr_boost_1_81::system::error_code& err)
  {
    if (!err)
    {
      // Write all of the data that has been read so far.
      std::cout << &response_;

      // Continue reading remaining data until EOF.
      zr_boost_1_81::asio::async_read(socket_, response_,
          zr_boost_1_81::asio::transfer_at_least(1),
          zr_boost_1_81::bind(&client::handle_read_content, this,
            zr_boost_1_81::asio::placeholders::error));
    }
    else if (err != zr_boost_1_81::asio::error::eof)
    {
      std::cout << "Error: " << err << "\n";
    }
  }

  tcp::resolver resolver_;
  tcp::socket socket_;
  zr_boost_1_81::asio::streambuf request_;
  zr_boost_1_81::asio::streambuf response_;
};

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 3)
    {
      std::cout << "Usage: async_client <server> <path>\n";
      std::cout << "Example:\n";
      std::cout << "  async_client www.boost.org /LICENSE_1_0.txt\n";
      return 1;
    }

    zr_boost_1_81::asio::io_context io_context;
    client c(io_context, argv[1], argv[2]);
    io_context.run();
  }
  catch (std::exception& e)
  {
    std::cout << "Exception: " << e.what() << "\n";
  }

  return 0;
}
