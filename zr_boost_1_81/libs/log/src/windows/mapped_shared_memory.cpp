/*
 *              Copyright Andrey Semashev 2016.
 * Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *          http://www.boost.org/LICENSE_1_0.txt)
 */
/*!
 * \file   windows/mapped_shared_memory.cpp
 * \author Andrey Semashev
 * \date   13.02.2016
 *
 * \brief  This header is the Boost.Log library implementation, see the library documentation
 *         at http://www.boost.org/doc/libs/release/libs/log/doc/html/index.html.
 */

#include <boost/log/detail/config.hpp>
#include <boost/winapi/basic_types.hpp>
#include <boost/winapi/handles.hpp>
#include <boost/winapi/dll.hpp>
#include <boost/winapi/file_mapping.hpp>
#include <boost/winapi/page_protection_flags.hpp>
#include <boost/winapi/get_last_error.hpp>
#include <windows.h> // for error codes
#include <cstddef>
#include <limits>
#include <string>
#include <sstream>
#include <boost/assert.hpp>
#include <boost/cstdint.hpp>
#include <boost/memory_order.hpp>
#include <boost/atomic/atomic.hpp>
#include <boost/throw_exception.hpp>
#include <boost/log/exceptions.hpp>
#include <boost/log/utility/permissions.hpp>
#include "windows/mapped_shared_memory.hpp"
#include <boost/log/detail/header.hpp>

namespace zr_boost_1_81 {

BOOST_LOG_OPEN_NAMESPACE

namespace ipc {

namespace aux {

zr_boost_1_81::atomic< mapped_shared_memory::nt_query_section_t > mapped_shared_memory::nt_query_section(static_cast< mapped_shared_memory::nt_query_section_t >(NULL));

mapped_shared_memory::~mapped_shared_memory()
{
    if (m_mapped_address)
        unmap();

    if (m_handle)
    {
        BOOST_VERIFY(zr_boost_1_81::winapi::CloseHandle(m_handle) != 0);
        m_handle = NULL;
    }
}

//! Creates a new file mapping for the shared memory segment or opens the existing one
void mapped_shared_memory::create(const wchar_t* name, std::size_t size, permissions const& perms)
{
    BOOST_ASSERT(m_handle == NULL);

    const uint64_t size64 = static_cast< uint64_t >(size);

    // Unlike other create functions, this function opens the existing mapping, if one already exists
    zr_boost_1_81::winapi::HANDLE_ h = zr_boost_1_81::winapi::CreateFileMappingW
    (
        zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_,
        reinterpret_cast< zr_boost_1_81::winapi::SECURITY_ATTRIBUTES_* >(perms.get_native()),
        zr_boost_1_81::winapi::PAGE_READWRITE_ | zr_boost_1_81::winapi::SEC_COMMIT_,
        static_cast< zr_boost_1_81::winapi::DWORD_ >(size64 >> 32u),
        static_cast< zr_boost_1_81::winapi::DWORD_ >(size64),
        name
    );

    zr_boost_1_81::winapi::DWORD_ err = zr_boost_1_81::winapi::GetLastError();
    if (BOOST_UNLIKELY(h == NULL || err != ERROR_SUCCESS))
    {
        if (h != NULL)
            zr_boost_1_81::winapi::CloseHandle(h);
        std::ostringstream strm;
        strm << "Failed to create a shared memory segment of " << size << " bytes";
        BOOST_LOG_THROW_DESCR_PARAMS(zr_boost_1_81::log::system_error, strm.str(), (err));
    }

    m_handle = h;
    m_size = size;
}

//! Creates a new file mapping for the shared memory segment or opens the existing one. Returns \c true if the region was created and \c false if an existing one was opened.
bool mapped_shared_memory::create_or_open(const wchar_t* name, std::size_t size, permissions const& perms)
{
    BOOST_ASSERT(m_handle == NULL);

    const uint64_t size64 = static_cast< uint64_t >(size);

    // Unlike other create functions, this function opens the existing mapping, if one already exists
    zr_boost_1_81::winapi::HANDLE_ h = zr_boost_1_81::winapi::CreateFileMappingW
    (
        zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_,
        reinterpret_cast< zr_boost_1_81::winapi::SECURITY_ATTRIBUTES_* >(perms.get_native()),
        zr_boost_1_81::winapi::PAGE_READWRITE_ | zr_boost_1_81::winapi::SEC_COMMIT_,
        static_cast< zr_boost_1_81::winapi::DWORD_ >(size64 >> 32u),
        static_cast< zr_boost_1_81::winapi::DWORD_ >(size64),
        name
    );

    zr_boost_1_81::winapi::DWORD_ err = zr_boost_1_81::winapi::GetLastError();
    if (BOOST_UNLIKELY(h == NULL))
    {
        std::ostringstream strm;
        strm << "Failed to create or open a shared memory segment of " << size << " bytes";
        BOOST_LOG_THROW_DESCR_PARAMS(zr_boost_1_81::log::system_error, strm.str(), (err));
    }

    const bool created = (err != ERROR_ALREADY_EXISTS);
    try
    {
        if (created)
        {
            m_size = size;
        }
        else
        {
            // If an existing segment was opened, determine its size
            m_size = obtain_size(h);
        }
    }
    catch (...)
    {
        zr_boost_1_81::winapi::CloseHandle(h);
        throw;
    }

    m_handle = h;

    return created;
}

//! Opens the existing file mapping for the shared memory segment
void mapped_shared_memory::open(const wchar_t* name)
{
    BOOST_ASSERT(m_handle == NULL);

    // Note: FILE_MAP_WRITE implies reading permission as well
    zr_boost_1_81::winapi::HANDLE_ h = zr_boost_1_81::winapi::OpenFileMappingW(zr_boost_1_81::winapi::FILE_MAP_WRITE_ | zr_boost_1_81::winapi::SECTION_QUERY_, false, name);

    if (BOOST_UNLIKELY(h == NULL))
    {
        const zr_boost_1_81::winapi::DWORD_ err = zr_boost_1_81::winapi::GetLastError();
        BOOST_LOG_THROW_DESCR_PARAMS(zr_boost_1_81::log::system_error, "Failed to create a shared memory segment", (err));
    }

    try
    {
        m_size = obtain_size(h);
    }
    catch (...)
    {
        zr_boost_1_81::winapi::CloseHandle(h);
        throw;
    }

    m_handle = h;
}

//! Maps the file mapping into the current process memory
void mapped_shared_memory::map()
{
    BOOST_ASSERT(m_handle != NULL);
    BOOST_ASSERT(m_mapped_address == NULL);

    // Note: FILE_MAP_WRITE implies reading permission as well
    m_mapped_address = zr_boost_1_81::winapi::MapViewOfFile
    (
        m_handle,
        zr_boost_1_81::winapi::FILE_MAP_WRITE_ | zr_boost_1_81::winapi::SECTION_QUERY_,
        0u,
        0u,
        m_size
    );

    if (BOOST_UNLIKELY(m_mapped_address == NULL))
    {
        const zr_boost_1_81::winapi::DWORD_ err = zr_boost_1_81::winapi::GetLastError();
        BOOST_LOG_THROW_DESCR_PARAMS(zr_boost_1_81::log::system_error, "Failed to map the shared memory segment into the process address space", (err));
    }
}

//! Unmaps the file mapping
void mapped_shared_memory::unmap()
{
    BOOST_ASSERT(m_mapped_address != NULL);

    BOOST_VERIFY(zr_boost_1_81::winapi::UnmapViewOfFile(m_mapped_address) != 0);
    m_mapped_address = NULL;
}

//! Returns the size of the file mapping identified by the handle
std::size_t mapped_shared_memory::obtain_size(zr_boost_1_81::winapi::HANDLE_ h)
{
    nt_query_section_t query_section = nt_query_section.load(zr_boost_1_81::memory_order_acquire);

    if (BOOST_UNLIKELY(query_section == NULL))
    {
        // Check if ntdll.dll provides NtQuerySection, see: http://undocumented.ntinternals.net/index.html?page=UserMode%2FUndocumented%20Functions%2FNT%20Objects%2FSection%2FNtQuerySection.html
        zr_boost_1_81::winapi::HMODULE_ ntdll = zr_boost_1_81::winapi::GetModuleHandleW(L"ntdll.dll");
        if (BOOST_UNLIKELY(ntdll == NULL))
        {
            const zr_boost_1_81::winapi::DWORD_ err = zr_boost_1_81::winapi::GetLastError();
            BOOST_LOG_THROW_DESCR_PARAMS(zr_boost_1_81::log::system_error, "Failed to obtain a handle to ntdll.dll", (err));
        }

        query_section = (nt_query_section_t)zr_boost_1_81::winapi::get_proc_address(ntdll, "NtQuerySection");
        if (BOOST_UNLIKELY(query_section == NULL))
        {
            const zr_boost_1_81::winapi::DWORD_ err = zr_boost_1_81::winapi::GetLastError();
            BOOST_LOG_THROW_DESCR_PARAMS(zr_boost_1_81::log::system_error, "Failed to obtain the NtQuerySection function", (err));
        }

        nt_query_section.store(query_section, zr_boost_1_81::memory_order_release);
    }

    section_basic_information info = {};
    zr_boost_1_81::winapi::NTSTATUS_ err = query_section
    (
        h,
        0u, // SectionBasicInformation
        &info,
        sizeof(info),
        NULL
    );
    if (BOOST_UNLIKELY(err != 0u))
    {
        BOOST_LOG_THROW_DESCR_PARAMS(zr_boost_1_81::log::system_error, "Failed to test obtain size of the shared memory segment", (ERROR_INVALID_HANDLE));
    }

    return static_cast< std::size_t >(info.section_size.QuadPart);
}

} // namespace aux

} // namespace ipc

BOOST_LOG_CLOSE_NAMESPACE // namespace log

} // namespace zr_boost_1_81

#include <boost/log/detail/footer.hpp>
