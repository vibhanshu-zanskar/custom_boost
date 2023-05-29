//  boost/system/windows_error.hpp  ------------------------------------------//

//  Copyright Beman Dawes 2007

//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See library home page at http://www.boost.org/libs/system

#ifndef BOOST_SYSTEM_WINDOWS_ERROR_HPP
#define BOOST_SYSTEM_WINDOWS_ERROR_HPP

//  This header is effectively empty for compiles on operating systems where
//  it is not applicable.

#include <boost/system/config.hpp>

#ifdef BOOST_WINDOWS_API

#include <boost/system/error_code.hpp>
#include <boost/winapi/error_codes.hpp>

namespace zr_boost_1_81
{
  namespace system
  {

    //  Microsoft Windows  ---------------------------------------------------//

    //  To construct an error_code after a API error:
    //
    //      error_code( ::GetLastError(), system_category() )

    namespace windows_error
    {
      enum windows_error_code
      {
        success = 0,
        // These names and values are based on Windows winerror.h
        invalid_function = zr_boost_1_81::winapi::ERROR_INVALID_FUNCTION_,
        file_not_found = zr_boost_1_81::winapi::ERROR_FILE_NOT_FOUND_,
        path_not_found = zr_boost_1_81::winapi::ERROR_PATH_NOT_FOUND_,
        too_many_open_files = zr_boost_1_81::winapi::ERROR_TOO_MANY_OPEN_FILES_,
        access_denied = zr_boost_1_81::winapi::ERROR_ACCESS_DENIED_,
        invalid_handle = zr_boost_1_81::winapi::ERROR_INVALID_HANDLE_,
        arena_trashed = zr_boost_1_81::winapi::ERROR_ARENA_TRASHED_,
        not_enough_memory = zr_boost_1_81::winapi::ERROR_NOT_ENOUGH_MEMORY_,
        invalid_block = zr_boost_1_81::winapi::ERROR_INVALID_BLOCK_,
        bad_environment = zr_boost_1_81::winapi::ERROR_BAD_ENVIRONMENT_,
        bad_format = zr_boost_1_81::winapi::ERROR_BAD_FORMAT_,
        invalid_access = zr_boost_1_81::winapi::ERROR_INVALID_ACCESS_,
        outofmemory = zr_boost_1_81::winapi::ERROR_OUTOFMEMORY_,
        invalid_drive = zr_boost_1_81::winapi::ERROR_INVALID_DRIVE_,
        current_directory = zr_boost_1_81::winapi::ERROR_CURRENT_DIRECTORY_,
        not_same_device = zr_boost_1_81::winapi::ERROR_NOT_SAME_DEVICE_,
        no_more_files = zr_boost_1_81::winapi::ERROR_NO_MORE_FILES_,
        write_protect = zr_boost_1_81::winapi::ERROR_WRITE_PROTECT_,
        bad_unit = zr_boost_1_81::winapi::ERROR_BAD_UNIT_,
        not_ready = zr_boost_1_81::winapi::ERROR_NOT_READY_,
        bad_command = zr_boost_1_81::winapi::ERROR_BAD_COMMAND_,
        crc = zr_boost_1_81::winapi::ERROR_CRC_,
        bad_length = zr_boost_1_81::winapi::ERROR_BAD_LENGTH_,
        seek = zr_boost_1_81::winapi::ERROR_SEEK_,
        not_dos_disk = zr_boost_1_81::winapi::ERROR_NOT_DOS_DISK_,
        sector_not_found = zr_boost_1_81::winapi::ERROR_SECTOR_NOT_FOUND_,
        out_of_paper = zr_boost_1_81::winapi::ERROR_OUT_OF_PAPER_,
        write_fault = zr_boost_1_81::winapi::ERROR_WRITE_FAULT_,
        read_fault = zr_boost_1_81::winapi::ERROR_READ_FAULT_,
        gen_failure = zr_boost_1_81::winapi::ERROR_GEN_FAILURE_,
        sharing_violation = zr_boost_1_81::winapi::ERROR_SHARING_VIOLATION_,
        lock_violation = zr_boost_1_81::winapi::ERROR_LOCK_VIOLATION_,
        wrong_disk = zr_boost_1_81::winapi::ERROR_WRONG_DISK_,
        sharing_buffer_exceeded = zr_boost_1_81::winapi::ERROR_SHARING_BUFFER_EXCEEDED_,
        handle_eof = zr_boost_1_81::winapi::ERROR_HANDLE_EOF_,
        handle_disk_full = zr_boost_1_81::winapi::ERROR_HANDLE_DISK_FULL_,
        not_supported = zr_boost_1_81::winapi::ERROR_NOT_SUPPORTED_,
        rem_not_list = zr_boost_1_81::winapi::ERROR_REM_NOT_LIST_,
        dup_name = zr_boost_1_81::winapi::ERROR_DUP_NAME_,
        bad_net_path = zr_boost_1_81::winapi::ERROR_BAD_NETPATH_,
        network_busy = zr_boost_1_81::winapi::ERROR_NETWORK_BUSY_,
        // ...
        file_exists = zr_boost_1_81::winapi::ERROR_FILE_EXISTS_,
        cannot_make = zr_boost_1_81::winapi::ERROR_CANNOT_MAKE_,
        // ...
        broken_pipe = zr_boost_1_81::winapi::ERROR_BROKEN_PIPE_,
        open_failed = zr_boost_1_81::winapi::ERROR_OPEN_FAILED_,
        buffer_overflow = zr_boost_1_81::winapi::ERROR_BUFFER_OVERFLOW_,
        disk_full = zr_boost_1_81::winapi::ERROR_DISK_FULL_,
        // ...
        lock_failed = zr_boost_1_81::winapi::ERROR_LOCK_FAILED_,
        busy = zr_boost_1_81::winapi::ERROR_BUSY_,
        cancel_violation = zr_boost_1_81::winapi::ERROR_CANCEL_VIOLATION_,
        already_exists = zr_boost_1_81::winapi::ERROR_ALREADY_EXISTS_
        // ...

        // TODO: add more Windows errors
      };

    }  // namespace windows

# ifdef BOOST_SYSTEM_ENABLE_DEPRECATED
    namespace windows = windows_error;
# endif

    template<> struct is_error_code_enum<windows_error::windows_error_code>
      { static const bool value = true; };

    namespace windows_error
    {
      inline error_code make_error_code( windows_error_code e )
        { return error_code( e, system_category() ); }
    }

  }  // namespace system
}  // namespace zr_boost_1_81

#endif  // BOOST_WINDOWS_API

#endif  // BOOST_SYSTEM_WINDOWS_ERROR_HPP
