// Copyright 2014 Renato Tegon Forti, Antony Polukhin.
// Copyright Antony Polukhin, 2015-2022.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_DLL_DETAIL_POSIX_PROGRAM_LOCATION_IMPL_HPP
#define BOOST_DLL_DETAIL_POSIX_PROGRAM_LOCATION_IMPL_HPP

#include <boost/dll/config.hpp>
#include <boost/dll/detail/system_error.hpp>
#include <boost/predef/os.h>

#ifdef BOOST_HAS_PRAGMA_ONCE
# pragma once
#endif

#if BOOST_OS_MACOS || BOOST_OS_IOS

#include <mach-o/dyld.h>

namespace zr_boost_1_81 { namespace dll { namespace detail {
    inline zr_boost_1_81::dll::fs::path program_location_impl(zr_boost_1_81::dll::fs::error_code &ec) {
        ec.clear();

        char path[1024];
        uint32_t size = sizeof(path);
        if (_NSGetExecutablePath(path, &size) == 0)
            return zr_boost_1_81::dll::fs::path(path);

        char *p = new char[size];
        if (_NSGetExecutablePath(p, &size) != 0) {
            ec = zr_boost_1_81::dll::fs::make_error_code(
                zr_boost_1_81::dll::fs::errc::bad_file_descriptor
            );
        }

        zr_boost_1_81::dll::fs::path ret(p);
        delete[] p;
        return ret;
    }
}}} // namespace zr_boost_1_81::dll::detail

#elif BOOST_OS_SOLARIS

#include <stdlib.h>
namespace zr_boost_1_81 { namespace dll { namespace detail {
    inline zr_boost_1_81::dll::fs::path program_location_impl(zr_boost_1_81::dll::fs::error_code& ec) {
        ec.clear();

        return zr_boost_1_81::dll::fs::path(getexecname());
    }
}}} // namespace zr_boost_1_81::dll::detail

#elif BOOST_OS_BSD_FREE

#include <sys/types.h>
#include <sys/sysctl.h>
#include <stdlib.h>

namespace zr_boost_1_81 { namespace dll { namespace detail {
    inline zr_boost_1_81::dll::fs::path program_location_impl(zr_boost_1_81::dll::fs::error_code& ec) {
        ec.clear();

        int mib[4];
        mib[0] = CTL_KERN;
        mib[1] = KERN_PROC;
        mib[2] = KERN_PROC_PATHNAME;
        mib[3] = -1;
        char buf[10240];
        size_t cb = sizeof(buf);
        sysctl(mib, 4, buf, &cb, NULL, 0);

        return zr_boost_1_81::dll::fs::path(buf);
    }
}}} // namespace zr_boost_1_81::dll::detail



#elif BOOST_OS_BSD_NET

namespace zr_boost_1_81 { namespace dll { namespace detail {
    inline zr_boost_1_81::dll::fs::path program_location_impl(zr_boost_1_81::dll::fs::error_code &ec) {
        return zr_boost_1_81::dll::fs::read_symlink("/proc/curproc/exe", ec);
    }
}}} // namespace zr_boost_1_81::dll::detail

#elif BOOST_OS_BSD_DRAGONFLY


namespace zr_boost_1_81 { namespace dll { namespace detail {
    inline zr_boost_1_81::dll::fs::path program_location_impl(zr_boost_1_81::dll::fs::error_code &ec) {
        return zr_boost_1_81::dll::fs::read_symlink("/proc/curproc/file", ec);
    }
}}} // namespace zr_boost_1_81::dll::detail

#elif BOOST_OS_QNX

#include <fstream>
#include <string> // for std::getline
namespace zr_boost_1_81 { namespace dll { namespace detail {
    inline zr_boost_1_81::dll::fs::path program_location_impl(zr_boost_1_81::dll::fs::error_code &ec) {
        ec.clear();

        std::string s;
        std::ifstream ifs("/proc/self/exefile");
        std::getline(ifs, s);

        if (ifs.fail() || s.empty()) {
            ec = zr_boost_1_81::dll::fs::make_error_code(
                zr_boost_1_81::dll::fs::errc::bad_file_descriptor
            );
        }

        return zr_boost_1_81::dll::fs::path(s);
    }
}}} // namespace zr_boost_1_81::dll::detail

#else  // BOOST_OS_LINUX || BOOST_OS_UNIX || BOOST_OS_HPUX || BOOST_OS_ANDROID

namespace zr_boost_1_81 { namespace dll { namespace detail {
    inline zr_boost_1_81::dll::fs::path program_location_impl(zr_boost_1_81::dll::fs::error_code &ec) {
        // We can not use
        // zr_boost_1_81::dll::detail::path_from_handle(dlopen(NULL, RTLD_LAZY | RTLD_LOCAL), ignore);
        // because such code returns empty path.

        return zr_boost_1_81::dll::fs::read_symlink("/proc/self/exe", ec);   // Linux specific
    }
}}} // namespace zr_boost_1_81::dll::detail

#endif

#endif // BOOST_DLL_DETAIL_POSIX_PROGRAM_LOCATION_IMPL_HPP

