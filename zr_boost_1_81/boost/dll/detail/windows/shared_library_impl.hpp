// Copyright 2014 Renato Tegon Forti, Antony Polukhin.
// Copyright Antony Polukhin, 2015-2022.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_DLL_SHARED_LIBRARY_IMPL_HPP
#define BOOST_DLL_SHARED_LIBRARY_IMPL_HPP

#include <boost/dll/config.hpp>
#include <boost/dll/shared_library_load_mode.hpp>
#include <boost/dll/detail/aggressive_ptr_cast.hpp>
#include <boost/dll/detail/system_error.hpp>
#include <boost/dll/detail/windows/path_from_handle.hpp>

#include <boost/move/utility.hpp>
#include <boost/swap.hpp>

#include <boost/winapi/dll.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
# pragma once
#endif

namespace zr_boost_1_81 { namespace dll { namespace detail {

class shared_library_impl {
    BOOST_MOVABLE_BUT_NOT_COPYABLE(shared_library_impl)

public:
    typedef zr_boost_1_81::winapi::HMODULE_ native_handle_t;

    shared_library_impl() BOOST_NOEXCEPT
        : handle_(NULL)
    {}

    ~shared_library_impl() BOOST_NOEXCEPT {
        unload();
    }

    shared_library_impl(BOOST_RV_REF(shared_library_impl) sl) BOOST_NOEXCEPT
        : handle_(sl.handle_)
    {
        sl.handle_ = NULL;
    }

    shared_library_impl & operator=(BOOST_RV_REF(shared_library_impl) sl) BOOST_NOEXCEPT {
        swap(sl);
        return *this;
    }

    static zr_boost_1_81::dll::fs::path decorate(const zr_boost_1_81::dll::fs::path& sl) {
        zr_boost_1_81::dll::fs::path actual_path = sl;
        actual_path += suffix();
        return actual_path;
    }

    void load(zr_boost_1_81::dll::fs::path sl, load_mode::type portable_mode, zr_boost_1_81::dll::fs::error_code &ec) {
        typedef zr_boost_1_81::winapi::DWORD_ native_mode_t;
        native_mode_t native_mode = static_cast<native_mode_t>(portable_mode);
        unload();

        if (!sl.is_absolute() && !(native_mode & load_mode::search_system_folders)) {
            zr_boost_1_81::dll::fs::error_code current_path_ec;
            zr_boost_1_81::dll::fs::path prog_loc = zr_boost_1_81::dll::fs::current_path(current_path_ec);

            if (!current_path_ec) {
                prog_loc /= sl;
                sl.swap(prog_loc);
            }
        }
        native_mode = static_cast<unsigned>(native_mode) & ~static_cast<unsigned>(load_mode::search_system_folders);

        // Trying to open with appended decorations
        if (!!(native_mode & load_mode::append_decorations)) {
            native_mode = static_cast<unsigned>(native_mode) & ~static_cast<unsigned>(load_mode::append_decorations);

            if (load_impl(decorate(sl), native_mode, ec)) {
                return;
            }

            // MinGW loves 'lib' prefix and puts it even on Windows platform.
            const zr_boost_1_81::dll::fs::path mingw_load_path = (
                sl.has_parent_path()
                ? sl.parent_path() / L"lib"
                : L"lib"
            ).native() + sl.filename().native() + suffix().native();
            if (load_impl(mingw_load_path, native_mode, ec)) {
                return;
            }
        }

        // From MSDN: If the string specifies a module name without a path and the
        // file name extension is omitted, the function appends the default library
        // extension .dll to the module name.
        //
        // From experiments: Default library extension appended to the module name even if
        // we have some path. So we do not check for path, only for extension. We can not be sure that
        // such behavior remain across all platforms, so we add L"." by hand.
        if (sl.has_extension()) {
            handle_ = zr_boost_1_81::winapi::LoadLibraryExW(sl.c_str(), 0, native_mode);
        } else {
            handle_ = zr_boost_1_81::winapi::LoadLibraryExW((sl.native() + L".").c_str(), 0, native_mode);
        }

        // LoadLibraryExW method is capable of self loading from program_location() path. No special actions
        // must be taken to allow self loading.
        if (!handle_) {
            ec = zr_boost_1_81::dll::detail::last_error_code();
        }
    }

    bool is_loaded() const BOOST_NOEXCEPT {
        return (handle_ != 0);
    }

    void unload() BOOST_NOEXCEPT {
        if (handle_) {
            zr_boost_1_81::winapi::FreeLibrary(handle_);
            handle_ = 0;
        }
    }

    void swap(shared_library_impl& rhs) BOOST_NOEXCEPT {
        zr_boost_1_81::swap(handle_, rhs.handle_);
    }

    zr_boost_1_81::dll::fs::path full_module_path(zr_boost_1_81::dll::fs::error_code &ec) const {
        return zr_boost_1_81::dll::detail::path_from_handle(handle_, ec);
    }

    static zr_boost_1_81::dll::fs::path suffix() {
        return L".dll";
    }

    void* symbol_addr(const char* sb, zr_boost_1_81::dll::fs::error_code &ec) const BOOST_NOEXCEPT {
        if (is_resource()) {
            // `GetProcAddress` could not be called for libraries loaded with
            // `LOAD_LIBRARY_AS_DATAFILE`, `LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE`
            // or `LOAD_LIBRARY_AS_IMAGE_RESOURCE`.
            ec = zr_boost_1_81::dll::fs::make_error_code(
                zr_boost_1_81::dll::fs::errc::operation_not_supported
            );

            return NULL;
        }

        // Judging by the documentation of GetProcAddress
        // there is no version for UNICODE on desktop/server Windows, because
        // names of functions are stored in narrow characters.
        void* const symbol = zr_boost_1_81::dll::detail::aggressive_ptr_cast<void*>(
            zr_boost_1_81::winapi::get_proc_address(handle_, sb)
        );
        if (symbol == NULL) {
            ec = zr_boost_1_81::dll::detail::last_error_code();
        }

        return symbol;
    }

    native_handle_t native() const BOOST_NOEXCEPT {
        return handle_;
    }

private:
    // Returns true if this load attempt should be the last one.
    bool load_impl(const zr_boost_1_81::dll::fs::path &load_path, zr_boost_1_81::winapi::DWORD_ mode, zr_boost_1_81::dll::fs::error_code &ec) {
        handle_ = zr_boost_1_81::winapi::LoadLibraryExW(load_path.c_str(), 0, mode);
        if (handle_) {
            return true;
        }

        ec = zr_boost_1_81::dll::detail::last_error_code();
        if (zr_boost_1_81::dll::fs::exists(load_path)) {
            // decorated path exists : current error is not a bad file descriptor
            return true;
        }

        ec.clear();
        return false;
    }

    bool is_resource() const BOOST_NOEXCEPT {
        return false; /*!!(
            reinterpret_cast<zr_boost_1_81::winapi::ULONG_PTR_>(handle_) & static_cast<zr_boost_1_81::winapi::ULONG_PTR_>(3)
        );*/
    }

    native_handle_t handle_;
};

}}} // zr_boost_1_81::dll::detail

#endif // BOOST_DLL_SHARED_LIBRARY_IMPL_HPP
