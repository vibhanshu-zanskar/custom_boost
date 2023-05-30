// Copyright 2014 Renato Tegon Forti, Antony Polukhin.
// Copyright Antony Polukhin, 2015-2022.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_DLL_DETAIL_WINDOWS_PATH_FROM_HANDLE_HPP
#define BOOST_DLL_DETAIL_WINDOWS_PATH_FROM_HANDLE_HPP

#include <boost/dll/config.hpp>
#include <boost/dll/detail/system_error.hpp>
#include <boost/winapi/dll.hpp>
#include <boost/winapi/get_last_error.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
# pragma once
#endif

namespace zr_boost_1_81 { namespace dll { namespace detail {

    inline zr_boost_1_81::dll::fs::error_code last_error_code() BOOST_NOEXCEPT {
        zr_boost_1_81::winapi::DWORD_ err = zr_boost_1_81::winapi::GetLastError();
        return zr_boost_1_81::dll::fs::error_code(
            static_cast<int>(err),
            zr_boost_1_81::dll::fs::system_category()
        );
    }

    inline zr_boost_1_81::dll::fs::path path_from_handle(zr_boost_1_81::winapi::HMODULE_ handle, zr_boost_1_81::dll::fs::error_code &ec) {
        BOOST_STATIC_CONSTANT(zr_boost_1_81::winapi::DWORD_, ERROR_INSUFFICIENT_BUFFER_ = 0x7A);
        BOOST_STATIC_CONSTANT(zr_boost_1_81::winapi::DWORD_, DEFAULT_PATH_SIZE_ = 260);

        // If `handle` parameter is NULL, GetModuleFileName retrieves the path of the
        // executable file of the current process.
        zr_boost_1_81::winapi::WCHAR_ path_hldr[DEFAULT_PATH_SIZE_];
        const zr_boost_1_81::winapi::DWORD_ ret = zr_boost_1_81::winapi::GetModuleFileNameW(handle, path_hldr, DEFAULT_PATH_SIZE_);
        if (ret) {
            // On success, GetModuleFileNameW() doesn't reset last error to ERROR_SUCCESS. Resetting it manually.
            ec.clear();
            return zr_boost_1_81::dll::fs::path(path_hldr);
        }

        ec = zr_boost_1_81::dll::detail::last_error_code();
        for (unsigned i = 2; i < 1025 && static_cast<zr_boost_1_81::winapi::DWORD_>(ec.value()) == ERROR_INSUFFICIENT_BUFFER_; i *= 2) {
            std::wstring p(DEFAULT_PATH_SIZE_ * i, L'\0');
            const std::size_t size = zr_boost_1_81::winapi::GetModuleFileNameW(handle, &p[0], DEFAULT_PATH_SIZE_ * i);
            if (size) {
                // On success, GetModuleFileNameW() doesn't reset last error to ERROR_SUCCESS. Resetting it manually.
                ec.clear();
                p.resize(size);
                return zr_boost_1_81::dll::fs::path(p);
            }

            ec = zr_boost_1_81::dll::detail::last_error_code();
        }

        // Error other than ERROR_INSUFFICIENT_BUFFER_ occurred or failed to allocate buffer big enough.
        return zr_boost_1_81::dll::fs::path();
    }

}}} // namespace zr_boost_1_81::dll::detail

#endif // BOOST_DLL_DETAIL_WINDOWS_PATH_FROM_HANDLE_HPP

