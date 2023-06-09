/*
 *          Copyright Andrey Semashev 2007 - 2015.
 * Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *          http://www.boost.org/LICENSE_1_0.txt)
 */
/*!
 * \file   main.cpp
 * \author Andrey Semashev
 * \date   07.03.2009
 *
 * \brief  An example of logging to a syslog server (syslogd, for example).
 *
 * The example shows how to initialize logging to a local syslog server.
 * The code creates a sink that will use native syslog API to emit messages.
 */

// #define BOOST_LOG_DYN_LINK 1

#include <boost/config.hpp>
#if !defined(BOOST_WINDOWS)
#define BOOST_LOG_USE_NATIVE_SYSLOG
#endif

#include <stdexcept>
#include <string>
#include <iostream>
#include <boost/smart_ptr/shared_ptr.hpp>

#include <boost/log/common.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/syslog_backend.hpp>

#if defined(BOOST_LOG_USE_NATIVE_SYSLOG)

namespace logging = zr_boost_1_81::log;
namespace attrs = zr_boost_1_81::log::attributes;
namespace src = zr_boost_1_81::log::sources;
namespace sinks = zr_boost_1_81::log::sinks;
namespace expr = zr_boost_1_81::log::expressions;
namespace keywords = zr_boost_1_81::log::keywords;

using zr_boost_1_81::shared_ptr;

//! Define application-specific severity levels
enum severity_levels
{
    normal,
    warning,
    error
};

int main(int argc, char* argv[])
{
    try
    {
        // Create a syslog sink
        shared_ptr< sinks::synchronous_sink< sinks::syslog_backend > > sink(
            new sinks::synchronous_sink< sinks::syslog_backend >(
                keywords::use_impl = sinks::syslog::native,
                keywords::facility = sinks::syslog::local7));

        sink->set_formatter
        (
            expr::format("native_syslog: %1%: %2%")
                % expr::attr< unsigned int >("RecordID")
                % expr::smessage
        );

        // We'll have to map our custom levels to the syslog levels
        sinks::syslog::custom_severity_mapping< severity_levels > mapping("Severity");
        mapping[normal] = sinks::syslog::info;
        mapping[warning] = sinks::syslog::warning;
        mapping[error] = sinks::syslog::critical;

        sink->locked_backend()->set_severity_mapper(mapping);

        // Add the sink to the core
        logging::core::get()->add_sink(sink);

        // Add some attributes too
        logging::core::get()->add_global_attribute("RecordID", attrs::counter< unsigned int >());

        // Do some logging
        src::severity_logger< severity_levels > lg(keywords::severity = normal);
        BOOST_LOG_SEV(lg, normal) << "A syslog record with normal level";
        BOOST_LOG_SEV(lg, warning) << "A syslog record with warning level";
        BOOST_LOG_SEV(lg, error) << "A syslog record with error level";

        return 0;
    }
    catch (std::exception& e)
    {
        std::cout << "FAILURE: " << e.what() << std::endl;
        return 1;
    }
}

#else // defined(BOOST_LOG_USE_NATIVE_SYSLOG)

int main (int, char*[])
{
    std::cout << "Native syslog API is not supported on this platform" << std::endl;
    return 0;
}

#endif // defined(BOOST_LOG_USE_NATIVE_SYSLOG)
