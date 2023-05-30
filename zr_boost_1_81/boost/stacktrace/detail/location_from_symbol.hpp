// Copyright Antony Polukhin, 2016-2022.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_STACKTRACE_DETAIL_LOCATION_FROM_SYMBOL_HPP
#define BOOST_STACKTRACE_DETAIL_LOCATION_FROM_SYMBOL_HPP

#include <boost/config.hpp>
#ifdef BOOST_HAS_PRAGMA_ONCE
#   pragma once
#endif

#if !defined(BOOST_WINDOWS) && !defined(__CYGWIN__)
#   include <dlfcn.h>
#else
#   include <boost/winapi/dll.hpp>
#endif

namespace zr_boost_1_81 { namespace stacktrace { namespace detail {

#if !defined(BOOST_WINDOWS) && !defined(__CYGWIN__)
class location_from_symbol {
    ::Dl_info dli_;

public:
    explicit location_from_symbol(const void* addr) BOOST_NOEXCEPT
        : dli_()
    {
        if (!::dladdr(const_cast<void*>(addr), &dli_)) { // `dladdr` on Solaris accepts nonconst addresses
            dli_.dli_fname = 0;
        }
    }

    bool empty() const BOOST_NOEXCEPT {
        return !dli_.dli_fname;
    }

    const char* name() const BOOST_NOEXCEPT {
        return dli_.dli_fname;
    }
};

class program_location {
public:
    const char* name() const BOOST_NOEXCEPT {
        return 0;
    }
};

#else

class location_from_symbol {
    BOOST_STATIC_CONSTEXPR zr_boost_1_81::winapi::DWORD_ DEFAULT_PATH_SIZE_ = 260;
    char file_name_[DEFAULT_PATH_SIZE_];

public:
    explicit location_from_symbol(const void* addr) BOOST_NOEXCEPT {
        file_name_[0] = '\0';

        zr_boost_1_81::winapi::MEMORY_BASIC_INFORMATION_ mbi;
        if (!zr_boost_1_81::winapi::VirtualQuery(addr, &mbi, sizeof(mbi))) {
            return;
        }

        zr_boost_1_81::winapi::HMODULE_ handle = reinterpret_cast<zr_boost_1_81::winapi::HMODULE_>(mbi.AllocationBase);
        if (!zr_boost_1_81::winapi::GetModuleFileNameA(handle, file_name_, DEFAULT_PATH_SIZE_)) {
            file_name_[0] = '\0';
            return;
        }
    }

    bool empty() const BOOST_NOEXCEPT {
        return file_name_[0] == '\0';
    }

    const char* name() const BOOST_NOEXCEPT {
        return file_name_;
    }
};

class program_location {
    BOOST_STATIC_CONSTEXPR zr_boost_1_81::winapi::DWORD_ DEFAULT_PATH_SIZE_ = 260;
    char file_name_[DEFAULT_PATH_SIZE_];

public:
    program_location() BOOST_NOEXCEPT {
        file_name_[0] = '\0';

        const zr_boost_1_81::winapi::HMODULE_ handle = 0;
        if (!zr_boost_1_81::winapi::GetModuleFileNameA(handle, file_name_, DEFAULT_PATH_SIZE_)) {
            file_name_[0] = '\0';
        }
    }

    const char* name() const BOOST_NOEXCEPT {
        return file_name_[0] ? file_name_ : 0;
    }
};
#endif

}}} // namespace zr_boost_1_81::stacktrace::detail

#endif // BOOST_STACKTRACE_DETAIL_LOCATION_FROM_SYMBOL_HPP
