// Copyright (c) 2016 Klemens D. Morgenstern
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_MAIN
#define BOOST_TEST_IGNORE_SIGCHLD
#include <boost/test/included/unit_test.hpp>

#include <boost/process/error.hpp>
#include <boost/process/io.hpp>
#include <boost/process/async.hpp>
#include <boost/process/child.hpp>
#include <boost/process/async_system.hpp>

#include <string>
#include <boost/asio/io_context.hpp>
#include <boost/asio/post.hpp>
#include <boost/asio/spawn.hpp>
#include <boost/asio/coroutine.hpp>
#include <boost/asio/strand.hpp>
#include <boost/asio/use_future.hpp>
#include <boost/asio/yield.hpp>

#include <vector>
#include <array>
BOOST_AUTO_TEST_SUITE( async );

namespace bp = zr_boost_1_81::process;
BOOST_AUTO_TEST_CASE(stackful, *zr_boost_1_81::unit_test::timeout(15))
{
    using zr_boost_1_81::unit_test::framework::master_test_suite;

    bool did_something_else = false;

    zr_boost_1_81::asio::io_context ios;
    auto stackful =
            [&](zr_boost_1_81::asio::yield_context yield_)
            {
                int ret =
                    bp::async_system(
                        ios, yield_,
                        master_test_suite().argv[1],
                        "test", "--wait", "1");

                BOOST_CHECK_EQUAL(ret, 0);
                BOOST_CHECK(did_something_else);
            };

    zr_boost_1_81::asio::io_context::strand str{ios};
    zr_boost_1_81::asio::post(str, [&]{zr_boost_1_81::asio::spawn(ios, stackful);});
    zr_boost_1_81::asio::post(str, [&]{did_something_else = true;});

    ios.run();
    BOOST_CHECK(did_something_else);
}

BOOST_AUTO_TEST_SUITE_END();