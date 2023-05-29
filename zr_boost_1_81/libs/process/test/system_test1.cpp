// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_MAIN
#define BOOST_TEST_IGNORE_SIGCHLD
#include <boost/test/included/unit_test.hpp>

#include <boost/system/error_code.hpp>

#include <iostream>

#include <boost/asio.hpp>
#include <boost/chrono.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/asio/steady_timer.hpp>

#include <boost/process/error.hpp>
#include <boost/process/io.hpp>
#include <boost/process/args.hpp>
#include <boost/process/system.hpp>
#include <boost/process/async_pipe.hpp>
#include <boost/process/async.hpp>
#include <system_error>

#include <boost/process/filesystem.hpp>

#include <string>
#include <chrono>
#include <istream>
#include <cstdlib>
#if defined(BOOST_WINDOWS_API)
#   include <windows.h>
typedef zr_boost_1_81::asio::windows::stream_handle pipe_end;
#elif defined(BOOST_POSIX_API)
#   include <sys/wait.h>
#   include <unistd.h>
typedef zr_boost_1_81::asio::posix::stream_descriptor pipe_end;
#endif

namespace fs = zr_boost_1_81::process::filesystem;
namespace bp = zr_boost_1_81::process;

BOOST_AUTO_TEST_CASE(system_exit_code, *zr_boost_1_81::unit_test::timeout(5))
{
    using zr_boost_1_81::unit_test::framework::master_test_suite;

    std::error_code ec;
    //I need to spawn a thread for that to work

    BOOST_CHECK_EQUAL(
        bp::system(
            master_test_suite().argv[1],
            "test", "--exit-code", "123",  ec), 123);

    BOOST_CHECK(!ec);
}

BOOST_AUTO_TEST_CASE(implicit_async_io, *zr_boost_1_81::unit_test::timeout(2))
{
    using zr_boost_1_81::unit_test::framework::master_test_suite;

    std::future<std::string> fut;
    std::error_code ec;
    int res = bp::system(
        master_test_suite().argv[1],
        "test", "--echo-stdout", "abc",
        bp::std_out > fut,
        ec
    );
    BOOST_REQUIRE(!ec);
    BOOST_REQUIRE(fut.valid());
    BOOST_CHECK_EQUAL(res, 0);
    BOOST_CHECK(zr_boost_1_81::starts_with(
            fut.get(), "abc"));
}