/*
 * Copyright 2017 James E. King, III
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_BCRYPT_HPP_INCLUDED_
#define BOOST_WINAPI_BCRYPT_HPP_INCLUDED_

#include <boost/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN6

#if BOOST_WINAPI_PARTITION_APP_SYSTEM

#if defined(BOOST_USE_WINDOWS_H)
#include <bcrypt.h>
#endif

#include <boost/winapi/detail/header.hpp>

#if defined(BOOST_USE_WINDOWS_H)

namespace zr_boost_1_81 { namespace winapi {
typedef ::BCRYPT_ALG_HANDLE BCRYPT_ALG_HANDLE_;
}}

#else // defined(BOOST_USE_WINDOWS_H)

namespace zr_boost_1_81 { namespace winapi {
typedef PVOID_ BCRYPT_ALG_HANDLE_;
}}

extern "C" {

zr_boost_1_81::winapi::NTSTATUS_ BOOST_WINAPI_WINAPI_CC
BCryptCloseAlgorithmProvider(
    zr_boost_1_81::winapi::BCRYPT_ALG_HANDLE_ hAlgorithm,
    zr_boost_1_81::winapi::ULONG_             dwFlags
);

zr_boost_1_81::winapi::NTSTATUS_ BOOST_WINAPI_WINAPI_CC
BCryptGenRandom(
    zr_boost_1_81::winapi::BCRYPT_ALG_HANDLE_ hAlgorithm,
    zr_boost_1_81::winapi::PUCHAR_            pbBuffer,
    zr_boost_1_81::winapi::ULONG_             cbBuffer,
    zr_boost_1_81::winapi::ULONG_             dwFlags
);

zr_boost_1_81::winapi::NTSTATUS_ BOOST_WINAPI_WINAPI_CC
BCryptOpenAlgorithmProvider(
    zr_boost_1_81::winapi::BCRYPT_ALG_HANDLE_ *phAlgorithm,
    zr_boost_1_81::winapi::LPCWSTR_           pszAlgId,
    zr_boost_1_81::winapi::LPCWSTR_           pszImplementation,
    zr_boost_1_81::winapi::DWORD_             dwFlags
);

} // extern "C"

#endif // defined(BOOST_USE_WINDOWS_H)

namespace zr_boost_1_81 {
namespace winapi {

#if defined(BOOST_USE_WINDOWS_H)
const WCHAR_ BCRYPT_RNG_ALGORITHM_[] = BCRYPT_RNG_ALGORITHM;
#else
const WCHAR_ BCRYPT_RNG_ALGORITHM_[] = L"RNG";
#endif

using ::BCryptCloseAlgorithmProvider;
using ::BCryptGenRandom;
using ::BCryptOpenAlgorithmProvider;

} // winapi
} // boost

#include <boost/winapi/detail/footer.hpp>

#endif // BOOST_WINAPI_PARTITION_APP_SYSTEM

#endif // BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN6

#endif // BOOST_WINAPI_BCRYPT_HPP_INCLUDED_
