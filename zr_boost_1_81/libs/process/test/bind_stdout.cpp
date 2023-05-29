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
#include <boost/filesystem/fstream.hpp>

#include <boost/system/error_code.hpp>

#include <boost/asio.hpp>
#include <boost/algorithm/string/predicate.hpp>

#include <boost/process/error.hpp>
#include <boost/process/io.hpp>
#include <boost/process/args.hpp>
#include <boost/process/child.hpp>
#include <boost/process/async_pipe.hpp>
#include <system_error>

#include <boost/process/filesystem.hpp>

#include <string>
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

BOOST_AUTO_TEST_SUITE( bind_stdout );


namespace fs = zr_boost_1_81::process::filesystem;
namespace bp = zr_boost_1_81::process;

BOOST_AUTO_TEST_CASE(sync_io, *zr_boost_1_81::unit_test::timeout(5))
{
    using zr_boost_1_81::unit_test::framework::master_test_suite;

    bp::ipstream is;
    std::error_code ec;

    bp::child c(
        master_test_suite().argv[1],
        bp::args+={"test", "--echo-stdout", "hello"},
        bp::std_out > is,
        ec
    ); 

    BOOST_CHECK(!ec);


    std::string s;

    BOOST_TEST_CHECKPOINT("Starting read");
    is >> s;
    BOOST_TEST_CHECKPOINT("Finished read");

    BOOST_CHECK_EQUAL(s, "hello");
}


struct read_handler
{
    zr_boost_1_81::asio::streambuf &buffer_;

    read_handler(zr_boost_1_81::asio::streambuf &buffer) : buffer_(buffer) {}

    void operator()(const zr_boost_1_81::system::error_code &ec, std::size_t size)
    {
        BOOST_REQUIRE(!ec);
        std::istream is(&buffer_);
        std::string line;
        std::getline(is, line);
        BOOST_CHECK(zr_boost_1_81::algorithm::starts_with(line, "abc"));
    }
};

BOOST_AUTO_TEST_CASE(async_io, *zr_boost_1_81::unit_test::timeout(2))
{
    using zr_boost_1_81::unit_test::framework::master_test_suite;

    zr_boost_1_81::asio::io_context io_context;
    bp::async_pipe p(io_context);

    std::error_code ec;
    bp::child c(
        master_test_suite().argv[1],
        "test", "--echo-stdout", "abc",
        bp::std_out > p,
        ec
    );
    BOOST_REQUIRE(!ec);

    zr_boost_1_81::asio::streambuf buffer;
    zr_boost_1_81::asio::async_read_until(p, buffer, '\n',
        read_handler(buffer));

    io_context.run();
}

BOOST_AUTO_TEST_CASE(nul, *zr_boost_1_81::unit_test::timeout(2))
{
    using zr_boost_1_81::unit_test::framework::master_test_suite;


    std::error_code ec;
    bp::child c(
        master_test_suite().argv[1],
        bp::args+={"test", "--is-nul-stdout"},
        bp::std_out>bp::null,
        ec
    );
    BOOST_REQUIRE(!ec);

    c.wait();
    int exit_code = c.exit_code();
#if defined(BOOST_WINDOWS_API)
    BOOST_CHECK_EQUAL(EXIT_SUCCESS, exit_code);
#elif defined(BOOST_POSIX_API)
    BOOST_CHECK_EQUAL(EXIT_SUCCESS, exit_code);
#endif
}



BOOST_AUTO_TEST_CASE(file_io, *zr_boost_1_81::unit_test::timeout(2))
{
    using zr_boost_1_81::unit_test::framework::master_test_suite;

    fs::path pth =
            fs::path(master_test_suite().argv[1]).parent_path() / "std_out_log_file.txt";


    FILE* f = fopen(pth.string().c_str(), "w");
    BOOST_REQUIRE(f != nullptr);

    std::error_code ec;
    bp::child c(
        master_test_suite().argv[1],
        bp::args={"test", "--echo-stdout", "hello"},
        bp::std_out>f,
        ec
    );
    BOOST_REQUIRE(!ec);

    fclose(f);

    c.wait();
    {
        fs::ifstream is{pth};

        std::string s;
        is >> s;
        BOOST_CHECK_EQUAL(s, "hello");
    }
    zr_boost_1_81::process::filesystem::remove(pth);

}

BOOST_AUTO_TEST_SUITE_END();