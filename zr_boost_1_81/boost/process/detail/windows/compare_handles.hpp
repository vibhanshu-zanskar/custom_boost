// Copyright (c) 2016 Klemens D. Morgenstern
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_DETAIL_WINDOWS_COMPARE_HANDLES_HPP_
#define BOOST_PROCESS_DETAIL_WINDOWS_COMPARE_HANDLES_HPP_

#include <boost/winapi/handles.hpp>
#include <boost/winapi/file_management.hpp>
#include <boost/process/detail/config.hpp>

namespace zr_boost_1_81 { namespace process { namespace detail { namespace windows {

inline bool compare_handles(zr_boost_1_81::winapi::HANDLE_ lhs, zr_boost_1_81::winapi::HANDLE_ rhs)
{
    if ( (lhs == ::zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_)
      || (rhs == ::zr_boost_1_81::winapi::INVALID_HANDLE_VALUE_))
        return false;

    if (lhs == rhs)
        return true;

    ::zr_boost_1_81::winapi::BY_HANDLE_FILE_INFORMATION_ lhs_info{0,{0,0},{0,0},{0,0},0,0,0,0,0,0};
    ::zr_boost_1_81::winapi::BY_HANDLE_FILE_INFORMATION_ rhs_info{0,{0,0},{0,0},{0,0},0,0,0,0,0,0};

    if (!::zr_boost_1_81::winapi::GetFileInformationByHandle(lhs, &lhs_info))
        ::zr_boost_1_81::process::detail::throw_last_error("GetFileInformationByHandle");

    if (!::zr_boost_1_81::winapi::GetFileInformationByHandle(rhs, &rhs_info))
        ::zr_boost_1_81::process::detail::throw_last_error("GetFileInformationByHandle");

    return     (lhs_info.nFileIndexHigh == rhs_info.nFileIndexHigh)
            && (lhs_info.nFileIndexLow  == rhs_info.nFileIndexLow);
}

}}}}



#endif /* BOOST_PROCESS_DETAIL_WINDOWS_COMPARE_HANDLES_HPP_ */
