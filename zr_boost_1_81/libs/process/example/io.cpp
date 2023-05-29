// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/process.hpp>
#include <string>

namespace bp = zr_boost_1_81::process;

int main()
{
    //
    bp::system(
        "test.exe",
        bp::std_out > stdout, //forward
        bp::std_err.close(), //close
        bp::std_in < bp::null //null in
    );

    zr_boost_1_81::process::filesystem::path p = "input.txt";

    bp::system(
        "test.exe",
        (bp::std_out & bp::std_err) > "output.txt", //redirect both to one file
        bp::std_in < p //read input from file
    );

    {
        bp::opstream p1;
        bp::ipstream p2;
        bp::system(
            "test.exe",
            bp::std_out > p2,
            bp::std_in < p1
        );
        p1 << "my_text";
        int i = 0;
        p2 >> i;

    }
    {
        zr_boost_1_81::asio::io_context io_context;
        bp::async_pipe p1(io_context);
        bp::async_pipe p2(io_context);
        bp::system(
            "test.exe",
            bp::std_out > p2,
            bp::std_in < p1,
            io_context,
            bp::on_exit([&](int exit, const std::error_code& ec_in)
                {
                    p1.async_close();
                    p2.async_close();
                })
        );
        std::vector<char> in_buf;
        std::string value = "my_string";
        zr_boost_1_81::asio::async_write(p1, zr_boost_1_81::asio::buffer(value),  []( const zr_boost_1_81::system::error_code&, std::size_t){});
        zr_boost_1_81::asio::async_read (p2, zr_boost_1_81::asio::buffer(in_buf), []( const zr_boost_1_81::system::error_code&, std::size_t){});
    }
    {
        zr_boost_1_81::asio::io_context io_context;
        std::vector<char> in_buf;
        std::string value = "my_string";
        bp::system(
        "test.exe",
        bp::std_out > bp::buffer(in_buf),
        bp::std_in  < bp::buffer(value)
        );
    }

    {
        zr_boost_1_81::asio::io_context io_context;
        std::future<std::vector<char>> in_buf;
        std::future<void> write_fut;
        std::string value = "my_string";
        bp::system(
            "test.exe",
            bp::std_out > in_buf,
            bp::std_in  < bp::buffer(value) > write_fut
            );

        write_fut.get();
        in_buf.get();
    }
}
