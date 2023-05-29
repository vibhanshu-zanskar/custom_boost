//
// receiver.cpp
// ~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <array>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

constexpr short multicast_port = 30001;

class receiver
{
public:
  receiver(zr_boost_1_81::asio::io_context& io_context,
      const zr_boost_1_81::asio::ip::address& listen_address,
      const zr_boost_1_81::asio::ip::address& multicast_address)
    : socket_(io_context)
  {
    // Create the socket so that multiple may be bound to the same address.
    zr_boost_1_81::asio::ip::udp::endpoint listen_endpoint(
        listen_address, multicast_port);
    socket_.open(listen_endpoint.protocol());
    socket_.set_option(zr_boost_1_81::asio::ip::udp::socket::reuse_address(true));
    socket_.bind(listen_endpoint);

    // Join the multicast group.
    socket_.set_option(
        zr_boost_1_81::asio::ip::multicast::join_group(multicast_address));

    do_receive();
  }

private:
  void do_receive()
  {
    socket_.async_receive_from(
        zr_boost_1_81::asio::buffer(data_), sender_endpoint_,
        [this](zr_boost_1_81::system::error_code ec, std::size_t length)
        {
          if (!ec)
          {
            std::cout.write(data_.data(), length);
            std::cout << std::endl;

            do_receive();
          }
        });
  }

  zr_boost_1_81::asio::ip::udp::socket socket_;
  zr_boost_1_81::asio::ip::udp::endpoint sender_endpoint_;
  std::array<char, 1024> data_;
};

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 3)
    {
      std::cerr << "Usage: receiver <listen_address> <multicast_address>\n";
      std::cerr << "  For IPv4, try:\n";
      std::cerr << "    receiver 0.0.0.0 239.255.0.1\n";
      std::cerr << "  For IPv6, try:\n";
      std::cerr << "    receiver 0::0 ff31::8000:1234\n";
      return 1;
    }

    zr_boost_1_81::asio::io_context io_context;
    receiver r(io_context,
        zr_boost_1_81::asio::ip::make_address(argv[1]),
        zr_boost_1_81::asio::ip::make_address(argv[2]));
    io_context.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}
