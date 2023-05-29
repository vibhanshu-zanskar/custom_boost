//
// async_file_copy.cpp
// ~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <boost/asio.hpp>

#if defined(BOOST_ASIO_HAS_FILE)

class file_copier
{
public:
  file_copier(zr_boost_1_81::asio::io_context& io_context,
      const char* from, const char* to)
    : from_file_(io_context, from,
        zr_boost_1_81::asio::stream_file::read_only),
      to_file_(io_context, to,
        zr_boost_1_81::asio::stream_file::write_only
          | zr_boost_1_81::asio::stream_file::create
          | zr_boost_1_81::asio::stream_file::truncate)
  {
  }

  void start()
  {
    do_read();
  }

private:
  void do_read()
  {
    from_file_.async_read_some(zr_boost_1_81::asio::buffer(data_),
        [this](zr_boost_1_81::system::error_code error, std::size_t n)
        {
          if (!error)
          {
            do_write(n);
          }
          else if (error != zr_boost_1_81::asio::error::eof)
          {
            std::cerr << "Error copying file: " << error.message() << "\n";
          }
        });
  }

  void do_write(std::size_t n)
  {
    zr_boost_1_81::asio::async_write(to_file_, zr_boost_1_81::asio::buffer(data_, n),
        [this](zr_boost_1_81::system::error_code error, std::size_t /*n*/)
        {
          if (!error)
          {
            do_read();
          }
          else
          {
            std::cerr << "Error copying file: " << error.message() << "\n";
          }
        });
  }

  zr_boost_1_81::asio::stream_file from_file_;
  zr_boost_1_81::asio::stream_file to_file_;
  char data_[4096];
};

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 3)
    {
      std::cerr << "Usage: async_file_copy <from> <to>\n";
      return 1;
    }

    zr_boost_1_81::asio::io_context io_context;

    file_copier copier(io_context, argv[1], argv[2]);
    copier.start();

    io_context.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
    return 1;
  }

  return 0;
}

#else // defined(BOOST_ASIO_HAS_FILE)
int main() {}
#endif // defined(BOOST_ASIO_HAS_FILE)
