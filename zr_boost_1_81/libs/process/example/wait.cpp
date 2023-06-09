// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/process.hpp>
#include <boost/asio.hpp>

namespace bp = zr_boost_1_81::process;

int main()
{
    {
        bp::child c("test.exe");
        c.wait();
        auto exit_code = c.exit_code();
    }

    {
        zr_boost_1_81::asio::io_context io_context;

        bp::child c(
            "test.exe",
            io_context,
            bp::on_exit([&](int exit, const std::error_code& ec_in){})
        );

        io_context.run();
    }
}
