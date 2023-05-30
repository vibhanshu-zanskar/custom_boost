//
// server.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <set>
#include <string>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ip/udp.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/asio/write.hpp>

using zr_boost_1_81::asio::steady_timer;
using zr_boost_1_81::asio::ip::tcp;
using zr_boost_1_81::asio::ip::udp;

//----------------------------------------------------------------------

class subscriber
{
public:
  virtual ~subscriber() {}
  virtual void deliver(const std::string& msg) = 0;
};

typedef zr_boost_1_81::shared_ptr<subscriber> subscriber_ptr;

//----------------------------------------------------------------------

class channel
{
public:
  void join(subscriber_ptr subscriber)
  {
    subscribers_.insert(subscriber);
  }

  void leave(subscriber_ptr subscriber)
  {
    subscribers_.erase(subscriber);
  }

  void deliver(const std::string& msg)
  {
    std::for_each(subscribers_.begin(), subscribers_.end(),
        zr_boost_1_81::bind(&subscriber::deliver,
          zr_boost_1_81::placeholders::_1, zr_boost_1_81::ref(msg)));
  }

private:
  std::set<subscriber_ptr> subscribers_;
};

//----------------------------------------------------------------------

//
// This class manages socket timeouts by applying the concept of a deadline.
// Some asynchronous operations are given deadlines by which they must complete.
// Deadlines are enforced by two "actors" that persist for the lifetime of the
// session object, one for input and one for output:
//
//  +----------------+                     +----------------+
//  |                |                     |                |
//  | check_deadline |<---+                | check_deadline |<---+
//  |                |    | async_wait()   |                |    | async_wait()
//  +----------------+    |  on input      +----------------+    |  on output
//              |         |  deadline                  |         |  deadline
//              +---------+                            +---------+
//
// If either deadline actor determines that the corresponding deadline has
// expired, the socket is closed and any outstanding operations are cancelled.
//
// The input actor reads messages from the socket, where messages are delimited
// by the newline character:
//
//  +------------+
//  |            |
//  | start_read |<---+
//  |            |    |
//  +------------+    |
//          |         |
//  async_- |    +-------------+
//   read_- |    |             |
//  until() +--->| handle_read |
//               |             |
//               +-------------+
//
// The deadline for receiving a complete message is 30 seconds. If a non-empty
// message is received, it is delivered to all subscribers. If a heartbeat (a
// message that consists of a single newline character) is received, a heartbeat
// is enqueued for the client, provided there are no other messages waiting to
// be sent.
//
// The output actor is responsible for sending messages to the client:
//
//  +--------------+
//  |              |<---------------------+
//  | await_output |                      |
//  |              |<---+                 |
//  +--------------+    |                 |
//      |      |        | async_wait()    |
//      |      +--------+                 |
//      V                                 |
//  +-------------+               +--------------+
//  |             | async_write() |              |
//  | start_write |-------------->| handle_write |
//  |             |               |              |
//  +-------------+               +--------------+
//
// The output actor first waits for an output message to be enqueued. It does
// this by using a steady_timer as an asynchronous condition variable. The
// steady_timer will be signalled whenever the output queue is non-empty.
//
// Once a message is available, it is sent to the client. The deadline for
// sending a complete message is 30 seconds. After the message is successfully
// sent, the output actor again waits for the output queue to become non-empty.
//
class tcp_session
  : public subscriber,
    public zr_boost_1_81::enable_shared_from_this<tcp_session>
{
public:
  tcp_session(zr_boost_1_81::asio::io_context& io_context, channel& ch)
    : channel_(ch),
      socket_(io_context),
      input_deadline_(io_context),
      non_empty_output_queue_(io_context),
      output_deadline_(io_context)
  {
    input_deadline_.expires_at(steady_timer::time_point::max());
    output_deadline_.expires_at(steady_timer::time_point::max());

    // The non_empty_output_queue_ steady_timer is set to the maximum time
    // point whenever the output queue is empty. This ensures that the output
    // actor stays asleep until a message is put into the queue.
    non_empty_output_queue_.expires_at(steady_timer::time_point::max());
  }

  tcp::socket& socket()
  {
    return socket_;
  }

  // Called by the server object to initiate the four actors.
  void start()
  {
    channel_.join(shared_from_this());

    start_read();

    input_deadline_.async_wait(
        zr_boost_1_81::bind(&tcp_session::check_deadline,
        shared_from_this(), &input_deadline_));

    await_output();

    output_deadline_.async_wait(
        zr_boost_1_81::bind(&tcp_session::check_deadline,
        shared_from_this(), &output_deadline_));
  }

private:
  void stop()
  {
    channel_.leave(shared_from_this());

    zr_boost_1_81::system::error_code ignored_ec;
    socket_.close(ignored_ec);
    input_deadline_.cancel();
    non_empty_output_queue_.cancel();
    output_deadline_.cancel();
  }

  bool stopped() const
  {
    return !socket_.is_open();
  }

  void deliver(const std::string& msg)
  {
    output_queue_.push_back(msg + "\n");

    // Signal that the output queue contains messages. Modifying the expiry
    // will wake the output actor, if it is waiting on the timer.
    non_empty_output_queue_.expires_at(steady_timer::time_point::min());
  }

  void start_read()
  {
    // Set a deadline for the read operation.
    input_deadline_.expires_after(zr_boost_1_81::asio::chrono::seconds(30));

    // Start an asynchronous operation to read a newline-delimited message.
    zr_boost_1_81::asio::async_read_until(socket_,
        zr_boost_1_81::asio::dynamic_buffer(input_buffer_), '\n',
        zr_boost_1_81::bind(&tcp_session::handle_read, shared_from_this(),
          zr_boost_1_81::placeholders::_1, zr_boost_1_81::placeholders::_2));
  }

  void handle_read(const zr_boost_1_81::system::error_code& ec, std::size_t n)
  {
    if (stopped())
      return;

    if (!ec)
    {
      // Extract the newline-delimited message from the buffer.
      std::string msg(input_buffer_.substr(0, n - 1));
      input_buffer_.erase(0, n);

      if (!msg.empty())
      {
        channel_.deliver(msg);
      }
      else
      {
        // We received a heartbeat message from the client. If there's nothing
        // else being sent or ready to be sent, send a heartbeat right back.
        if (output_queue_.empty())
        {
          output_queue_.push_back("\n");

          // Signal that the output queue contains messages. Modifying the
          // expiry will wake the output actor, if it is waiting on the timer.
          non_empty_output_queue_.expires_at(steady_timer::time_point::min());
        }
      }

      start_read();
    }
    else
    {
      stop();
    }
  }

  void await_output()
  {
    if (stopped())
      return;

    if (output_queue_.empty())
    {
      // There are no messages that are ready to be sent. The actor goes to
      // sleep by waiting on the non_empty_output_queue_ timer. When a new
      // message is added, the timer will be modified and the actor will wake.
      non_empty_output_queue_.expires_at(steady_timer::time_point::max());
      non_empty_output_queue_.async_wait(
          zr_boost_1_81::bind(&tcp_session::await_output, shared_from_this()));
    }
    else
    {
      start_write();
    }
  }

  void start_write()
  {
    // Set a deadline for the write operation.
    output_deadline_.expires_after(zr_boost_1_81::asio::chrono::seconds(30));

    // Start an asynchronous operation to send a message.
    zr_boost_1_81::asio::async_write(socket_,
        zr_boost_1_81::asio::buffer(output_queue_.front()),
        zr_boost_1_81::bind(&tcp_session::handle_write,
          shared_from_this(), zr_boost_1_81::placeholders::_1));
  }

  void handle_write(const zr_boost_1_81::system::error_code& ec)
  {
    if (stopped())
      return;

    if (!ec)
    {
      output_queue_.pop_front();

      await_output();
    }
    else
    {
      stop();
    }
  }

  void check_deadline(steady_timer* deadline)
  {
    if (stopped())
      return;

    // Check whether the deadline has passed. We compare the deadline against
    // the current time since a new asynchronous operation may have moved the
    // deadline before this actor had a chance to run.
    if (deadline->expiry() <= steady_timer::clock_type::now())
    {
      // The deadline has passed. Stop the session. The other actors will
      // terminate as soon as possible.
      stop();
    }
    else
    {
      // Put the actor back to sleep.
      deadline->async_wait(
          zr_boost_1_81::bind(&tcp_session::check_deadline,
          shared_from_this(), deadline));
    }
  }

  channel& channel_;
  tcp::socket socket_;
  std::string input_buffer_;
  steady_timer input_deadline_;
  std::deque<std::string> output_queue_;
  steady_timer non_empty_output_queue_;
  steady_timer output_deadline_;
};

typedef zr_boost_1_81::shared_ptr<tcp_session> tcp_session_ptr;

//----------------------------------------------------------------------

class udp_broadcaster
  : public subscriber
{
public:
  udp_broadcaster(zr_boost_1_81::asio::io_context& io_context,
      const udp::endpoint& broadcast_endpoint)
    : socket_(io_context)
  {
    socket_.connect(broadcast_endpoint);
    socket_.set_option(udp::socket::broadcast(true));
  }

private:
  void deliver(const std::string& msg)
  {
    zr_boost_1_81::system::error_code ignored_ec;
    socket_.send(zr_boost_1_81::asio::buffer(msg), 0, ignored_ec);
  }

  udp::socket socket_;
};

//----------------------------------------------------------------------

class server
{
public:
  server(zr_boost_1_81::asio::io_context& io_context,
      const tcp::endpoint& listen_endpoint,
      const udp::endpoint& broadcast_endpoint)
    : io_context_(io_context),
      acceptor_(io_context, listen_endpoint)
  {
    subscriber_ptr bc(new udp_broadcaster(io_context_, broadcast_endpoint));
    channel_.join(bc);

    start_accept();
  }

  void start_accept()
  {
    tcp_session_ptr new_session(new tcp_session(io_context_, channel_));

    acceptor_.async_accept(new_session->socket(),
        zr_boost_1_81::bind(&server::handle_accept,
          this, new_session, zr_boost_1_81::placeholders::_1));
  }

  void handle_accept(tcp_session_ptr session,
      const zr_boost_1_81::system::error_code& ec)
  {
    if (!ec)
    {
      session->start();
    }

    start_accept();
  }

private:
  zr_boost_1_81::asio::io_context& io_context_;
  tcp::acceptor acceptor_;
  channel channel_;
};

//----------------------------------------------------------------------

int main(int argc, char* argv[])
{
  try
  {
    using namespace std; // For atoi.

    if (argc != 4)
    {
      std::cerr << "Usage: server <listen_port> <bcast_address> <bcast_port>\n";
      return 1;
    }

    zr_boost_1_81::asio::io_context io_context;

    tcp::endpoint listen_endpoint(tcp::v4(), atoi(argv[1]));

    udp::endpoint broadcast_endpoint(
        zr_boost_1_81::asio::ip::make_address(argv[2]), atoi(argv[3]));

    server s(io_context, listen_endpoint, broadcast_endpoint);

    io_context.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}
