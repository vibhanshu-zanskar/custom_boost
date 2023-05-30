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
#include <boost/dll/detail/posix/path_from_handle.hpp>
#include <boost/dll/detail/posix/program_location_impl.hpp>

#include <boost/move/utility.hpp>
#include <boost/swap.hpp>
#include <boost/predef/os.h>

#include <dlfcn.h>
#include <cstring> // strncmp
#if !BOOST_OS_MACOS && !BOOST_OS_IOS && !BOOST_OS_QNX
#   include <link.h>
#elif BOOST_OS_QNX
// QNX's copy of <elf.h> and <link.h> reside in sys folder
#   include <sys/link.h>
#endif

#ifdef BOOST_HAS_PRAGMA_ONCE
# pragma once
#endif

namespace zr_boost_1_81 { namespace dll { namespace detail {

class shared_library_impl {

    BOOST_MOVABLE_BUT_NOT_COPYABLE(shared_library_impl)

public:
    typedef void* native_handle_t;

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


    static zr_boost_1_81::dll::fs::path decorate(const zr_boost_1_81::dll::fs::path & sl) {
        zr_boost_1_81::dll::fs::path actual_path = (
            std::strncmp(sl.filename().string().c_str(), "lib", 3)
            ? zr_boost_1_81::dll::fs::path((sl.has_parent_path() ? sl.parent_path() / "lib" : "lib").native() + sl.filename().native())
            : sl
        );
        actual_path += suffix();
        return actual_path;
    }

    void load(zr_boost_1_81::dll::fs::path sl, load_mode::type portable_mode, zr_boost_1_81::dll::fs::error_code &ec) {
        typedef int native_mode_t;
        native_mode_t native_mode = static_cast<native_mode_t>(portable_mode);
        unload();

        // Do not allow opening NULL paths. User must use program_location() instead
        if (sl.empty()) {
            zr_boost_1_81::dll::detail::reset_dlerror();
            ec = zr_boost_1_81::dll::fs::make_error_code(
                zr_boost_1_81::dll::fs::errc::bad_file_descriptor
            );

            return;
        }

        // Fixing modes
        if (!(native_mode & load_mode::rtld_now)) {
            native_mode |= load_mode::rtld_lazy;
        }

        if (!(native_mode & load_mode::rtld_global)) {
            native_mode |= load_mode::rtld_local;
        }

#if BOOST_OS_LINUX || BOOST_OS_ANDROID
        if (!sl.has_parent_path() && !(native_mode & load_mode::search_system_folders)) {
            sl = "." / sl;
        }
#else
        if (!sl.is_absolute() && !(native_mode & load_mode::search_system_folders)) {
            zr_boost_1_81::dll::fs::error_code current_path_ec;
            zr_boost_1_81::dll::fs::path prog_loc = zr_boost_1_81::dll::fs::current_path(current_path_ec);
            if (!current_path_ec) {
                prog_loc /= sl;
                sl.swap(prog_loc);
            }
        }
#endif

        native_mode = static_cast<unsigned>(native_mode) & ~static_cast<unsigned>(load_mode::search_system_folders);

        // Trying to open with appended decorations
        if (!!(native_mode & load_mode::append_decorations)) {
            native_mode = static_cast<unsigned>(native_mode) & ~static_cast<unsigned>(load_mode::append_decorations);

            zr_boost_1_81::dll::fs::path actual_path = decorate(sl);
            handle_ = dlopen(actual_path.c_str(), native_mode);
            if (handle_) {
                zr_boost_1_81::dll::detail::reset_dlerror();
                return;
            }
            zr_boost_1_81::dll::fs::error_code prog_loc_err;
            zr_boost_1_81::dll::fs::path loc = zr_boost_1_81::dll::detail::program_location_impl(prog_loc_err);
            if (zr_boost_1_81::dll::fs::exists(actual_path) && !zr_boost_1_81::dll::fs::equivalent(sl, loc, prog_loc_err)) {
                // decorated path exists : current error is not a bad file descriptor and we are not trying to load the executable itself
                ec = zr_boost_1_81::dll::fs::make_error_code(
                    zr_boost_1_81::dll::fs::errc::executable_format_error
                );
                return;
            }
        }

        // Opening by exactly specified path
        handle_ = dlopen(sl.c_str(), native_mode);
        if (handle_) {
            zr_boost_1_81::dll::detail::reset_dlerror();
            return;
        }

        ec = zr_boost_1_81::dll::fs::make_error_code(
            zr_boost_1_81::dll::fs::errc::bad_file_descriptor
        );

        // Maybe user wanted to load the executable itself? Checking...
        // We assume that usually user wants to load a dynamic library not the executable itself, that's why
        // we try this only after traditional load fails.
        zr_boost_1_81::dll::fs::error_code prog_loc_err;
        zr_boost_1_81::dll::fs::path loc = zr_boost_1_81::dll::detail::program_location_impl(prog_loc_err);
        if (!prog_loc_err && zr_boost_1_81::dll::fs::equivalent(sl, loc, prog_loc_err) && !prog_loc_err) {
            // As is known the function dlopen() loads the dynamic library file
            // named by the null-terminated string filename and returns an opaque
            // "handle" for the dynamic library. If filename is NULL, then the
            // returned handle is for the main program.
            ec.clear();
            zr_boost_1_81::dll::detail::reset_dlerror();
            handle_ = dlopen(NULL, native_mode);
            if (!handle_) {
                ec = zr_boost_1_81::dll::fs::make_error_code(
                    zr_boost_1_81::dll::fs::errc::bad_file_descriptor
                );
            }
        }
    }

    bool is_loaded() const BOOST_NOEXCEPT {
        return (handle_ != 0);
    }

    void unload() BOOST_NOEXCEPT {
        if (!is_loaded()) {
            return;
        }

        dlclose(handle_);
        handle_ = 0;
    }

    void swap(shared_library_impl& rhs) BOOST_NOEXCEPT {
        zr_boost_1_81::swap(handle_, rhs.handle_);
    }

    zr_boost_1_81::dll::fs::path full_module_path(zr_boost_1_81::dll::fs::error_code &ec) const {
        return zr_boost_1_81::dll::detail::path_from_handle(handle_, ec);
    }

    static zr_boost_1_81::dll::fs::path suffix() {
        // https://sourceforge.net/p/predef/wiki/OperatingSystems/
#if BOOST_OS_MACOS || BOOST_OS_IOS
        return ".dylib";
#else
        return ".so";
#endif
    }

    void* symbol_addr(const char* sb, zr_boost_1_81::dll::fs::error_code &ec) const BOOST_NOEXCEPT {
        // dlsym - obtain the address of a symbol from a dlopen object
        void* const symbol = dlsym(handle_, sb);
        if (symbol == NULL) {
            ec = zr_boost_1_81::dll::fs::make_error_code(
                zr_boost_1_81::dll::fs::errc::invalid_seek
            );
        }

        // If handle does not refer to a valid object opened by dlopen(),
        // or if the named symbol cannot be found within any of the objects
        // associated with handle, dlsym() shall return NULL.
        // More detailed diagnostic information shall be available through dlerror().

        return symbol;
    }

    native_handle_t native() const BOOST_NOEXCEPT {
        return handle_;
    }

private:
    native_handle_t         handle_;
};

}}} // zr_boost_1_81::dll::detail

#endif // BOOST_DLL_SHARED_LIBRARY_IMPL_HPP
