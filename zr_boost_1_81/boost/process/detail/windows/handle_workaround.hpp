// Copyright (c) 2018 Klemens D. Morgenstern
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_DETAIL_WINDOWS_HANDLE_WORKAROUND_HPP_
#define BOOST_PROCESS_DETAIL_WINDOWS_HANDLE_WORKAROUND_HPP_

#include <boost/winapi/basic_types.hpp>
#include <boost/winapi/dll.hpp>
#include <boost/winapi/access_rights.hpp>
//#define BOOST_USE_WINDOWS_H 1

#if defined( BOOST_USE_WINDOWS_H )
#include <winternl.h>
#endif


namespace zr_boost_1_81 { namespace process { namespace detail { namespace windows { namespace workaround
{


typedef struct _SYSTEM_HANDLE_ENTRY_
{
    ::zr_boost_1_81::winapi::ULONG_ OwnerPid;
    ::zr_boost_1_81::winapi::BYTE_ ObjectType;
    ::zr_boost_1_81::winapi::BYTE_ HandleFlags;
    ::zr_boost_1_81::winapi::USHORT_ HandleValue;
    ::zr_boost_1_81::winapi::PVOID_ ObjectPointer;
    ::zr_boost_1_81::winapi::ULONG_ AccessMask;
} SYSTEM_HANDLE_ENTRY_, *PSYSTEM_HANDLE_ENTRY_;

typedef struct _SYSTEM_HANDLE_INFORMATION_
{
    ::zr_boost_1_81::winapi::ULONG_ Count;
    SYSTEM_HANDLE_ENTRY_ Handle[1];
} SYSTEM_HANDLE_INFORMATION_, *PSYSTEM_HANDLE_INFORMATION_;

#if defined( BOOST_USE_WINDOWS_H )

using UNICODE_STRING_  = ::UNICODE_STRING;
using GENERIC_MAPPING_ = ::GENERIC_MAPPING;
using OBJECT_INFORMATION_CLASS_ = ::OBJECT_INFORMATION_CLASS;

constexpr static OBJECT_INFORMATION_CLASS_  ObjectTypeInformation = ::OBJECT_INFORMATION_CLASS::ObjectTypeInformation;

typedef struct _OBJECT_TYPE_INFORMATION_ {
    UNICODE_STRING TypeName;
    ULONG TotalNumberOfObjects;
    ULONG TotalNumberOfHandles;
    ULONG TotalPagedPoolUsage;
    ULONG TotalNonPagedPoolUsage;
    ULONG TotalNamePoolUsage;
    ULONG TotalHandleTableUsage;
    ULONG HighWaterNumberOfObjects;
    ULONG HighWaterNumberOfHandles;
    ULONG HighWaterPagedPoolUsage;
    ULONG HighWaterNonPagedPoolUsage;
    ULONG HighWaterNamePoolUsage;
    ULONG HighWaterHandleTableUsage;
    ULONG InvalidAttributes;
    GENERIC_MAPPING GenericMapping;
    ULONG ValidAccessMask;
    BOOLEAN SecurityRequired;
    BOOLEAN MaintainHandleCount;
    UCHAR   TypeIndex;
    CHAR    ReservedByte;
    ULONG PoolType;
    ULONG DefaultPagedPoolCharge;
    ULONG DefaultNonPagedPoolCharge;
} OBJECT_TYPE_INFORMATION_, *POBJECT_TYPE_INFORMATION_;

#else

typedef enum _OBJECT_INFORMATION_CLASS_
{
    ObjectBasicInformation,
    ObjectNameInformation,
    ObjectTypeInformation,
    ObjectAllInformation,
    ObjectDataInformation
} OBJECT_INFORMATION_CLASS_, *POBJECT_INFORMATION_CLASS_;

typedef struct _UNICODE_STRING_ {
    ::zr_boost_1_81::winapi::USHORT_ Length;
    ::zr_boost_1_81::winapi::USHORT_ MaximumLength;
    ::zr_boost_1_81::winapi::LPWSTR_ Buffer;
} UNICODE_STRING_, *PUNICODE_STRING_;

typedef struct _GENERIC_MAPPING_ {
    ::zr_boost_1_81::winapi::ACCESS_MASK_ GenericRead;
    ::zr_boost_1_81::winapi::ACCESS_MASK_ GenericWrite;
    ::zr_boost_1_81::winapi::ACCESS_MASK_ GenericExecute;
    ::zr_boost_1_81::winapi::ACCESS_MASK_ GenericAll;
} GENERIC_MAPPING_;

#endif

typedef struct _OBJECT_BASIC_INFORMATION {
    ::zr_boost_1_81::winapi::ULONG_  Attributes;
    ::zr_boost_1_81::winapi::ACCESS_MASK_  GrantedAccess;
    ::zr_boost_1_81::winapi::ULONG_  HandleCount;
    ::zr_boost_1_81::winapi::ULONG_  PointerCount;
    ::zr_boost_1_81::winapi::ULONG_  PagedPoolUsage;
    ::zr_boost_1_81::winapi::ULONG_  NonPagedPoolUsage;
    ::zr_boost_1_81::winapi::ULONG_  Reserved[3];
    ::zr_boost_1_81::winapi::ULONG_  NameInformationLength;
    ::zr_boost_1_81::winapi::ULONG_  TypeInformationLength;
    ::zr_boost_1_81::winapi::ULONG_  SecurityDescriptorLength;
    ::zr_boost_1_81::winapi::LARGE_INTEGER_  CreateTime;
} OBJECT_BASIC_INFORMATION_, *POBJECT_BASIC_INFORMATION_;

typedef struct _OBJECT_NAME_INFORMATION {
    UNICODE_STRING_ Name;
} OBJECT_NAME_INFORMATION_, *POBJECT_NAME_INFORMATION_;


#if defined( BOOST_USE_WINDOWS_H )

extern "C"
{

using SYSTEM_INFORMATION_CLASS_  = ::SYSTEM_INFORMATION_CLASS;
constexpr static SYSTEM_INFORMATION_CLASS_  SystemHandleInformation_ = static_cast<SYSTEM_INFORMATION_CLASS_>(16);

inline ::zr_boost_1_81::winapi::NTSTATUS_ nt_system_query_information(
        SYSTEM_INFORMATION_CLASS SystemInformationClass,
        void * SystemInformation,
        ::zr_boost_1_81::winapi::ULONG_ SystemInformationLength,
        ::zr_boost_1_81::winapi::PULONG_ ReturnLength)
{
    return ::NtQuerySystemInformation(SystemInformationClass, SystemInformation, SystemInformationLength, ReturnLength);
}

inline ::zr_boost_1_81::winapi::NTSTATUS_ nt_query_object(
        ::zr_boost_1_81::winapi::HANDLE_ Handle,
        OBJECT_INFORMATION_CLASS_ ObjectInformationClass,
        ::zr_boost_1_81::winapi::PVOID_  ObjectInformation,
        ::zr_boost_1_81::winapi::ULONG_  ObjectInformationLength,
        ::zr_boost_1_81::winapi::PULONG_ ReturnLength
)
{
    return ::NtQueryObject(Handle, ObjectInformationClass, ObjectInformation, ObjectInformationLength, ReturnLength);
}

}

#else

//this import workaround is to keep it a header-only library. and enums cannot be imported from the winapi.

extern "C"
{

typedef enum _SYSTEM_INFORMATION_CLASS_
{
    SystemBasicInformation_ = 0,
    SystemProcessorInformation_ = 1,
    SystemPerformanceInformation_ = 2,
    SystemTimeOfDayInformation_ = 3,
    SystemProcessInformation_ = 5,
    SystemProcessorPerformanceInformation_ = 8,
    SystemHandleInformation_ = 16,
    SystemPagefileInformation_ = 18,
    SystemInterruptInformation_ = 23,
    SystemExceptionInformation_ = 33,
    SystemRegistryQuotaInformation_ = 37,
    SystemLookasideInformation_ = 45
} SYSTEM_INFORMATION_CLASS_;


typedef struct _OBJECT_TYPE_INFORMATION_ {
    UNICODE_STRING_ TypeName;
    ::zr_boost_1_81::winapi::ULONG_ TotalNumberOfObjects;
    ::zr_boost_1_81::winapi::ULONG_ TotalNumberOfHandles;
    ::zr_boost_1_81::winapi::ULONG_ TotalPagedPoolUsage;
    ::zr_boost_1_81::winapi::ULONG_ TotalNonPagedPoolUsage;
    ::zr_boost_1_81::winapi::ULONG_ TotalNamePoolUsage;
    ::zr_boost_1_81::winapi::ULONG_ TotalHandleTableUsage;
    ::zr_boost_1_81::winapi::ULONG_ HighWaterNumberOfObjects;
    ::zr_boost_1_81::winapi::ULONG_ HighWaterNumberOfHandles;
    ::zr_boost_1_81::winapi::ULONG_ HighWaterPagedPoolUsage;
    ::zr_boost_1_81::winapi::ULONG_ HighWaterNonPagedPoolUsage;
    ::zr_boost_1_81::winapi::ULONG_ HighWaterNamePoolUsage;
    ::zr_boost_1_81::winapi::ULONG_ HighWaterHandleTableUsage;
    ::zr_boost_1_81::winapi::ULONG_ InvalidAttributes;
    GENERIC_MAPPING_ GenericMapping;
    ::zr_boost_1_81::winapi::ULONG_ ValidAccessMask;
    ::zr_boost_1_81::winapi::BOOLEAN_ SecurityRequired;
    ::zr_boost_1_81::winapi::BOOLEAN_ MaintainHandleCount;
    ::zr_boost_1_81::winapi::UCHAR_   TypeIndex;
    ::zr_boost_1_81::winapi::CHAR_    ReservedByte;
    ::zr_boost_1_81::winapi::ULONG_ PoolType;
    ::zr_boost_1_81::winapi::ULONG_ DefaultPagedPoolCharge;
    ::zr_boost_1_81::winapi::ULONG_ DefaultNonPagedPoolCharge;
} OBJECT_TYPE_INFORMATION_, *POBJECT_TYPE_INFORMATION_;



/*
NTSTATUS NtQuerySystemInformation(
  IN SYSTEM_INFORMATION_CLASS SystemInformationClass,
  OUT PVOID                   SystemInformation,
  IN ULONG                    SystemInformationLength,
  OUT PULONG                  ReturnLength
);
 */
typedef ::zr_boost_1_81::winapi::NTSTATUS_ (*nt_system_query_information_p )(
        SYSTEM_INFORMATION_CLASS_,
        void *,
        ::zr_boost_1_81::winapi::ULONG_,
        ::zr_boost_1_81::winapi::PULONG_);
/*
NTSYSCALLAPI NTSTATUS NtQueryObject(
  HANDLE                   Handle,
  OBJECT_INFORMATION_CLASS ObjectInformationClass,
  PVOID                    ObjectInformation,
  ULONG                    ObjectInformationLength,
  PULONG                   ReturnLength
);
 */

typedef ::zr_boost_1_81::winapi::NTSTATUS_ (*nt_query_object_p )(
        ::zr_boost_1_81::winapi::HANDLE_,
        OBJECT_INFORMATION_CLASS_,
        void *,
        ::zr_boost_1_81::winapi::ULONG_,
        ::zr_boost_1_81::winapi::PULONG_);

}

inline ::zr_boost_1_81::winapi::NTSTATUS_ nt_system_query_information(
        SYSTEM_INFORMATION_CLASS_ SystemInformationClass,
        void *SystemInformation,
        ::zr_boost_1_81::winapi::ULONG_ SystemInformationLength,
        ::zr_boost_1_81::winapi::PULONG_ ReturnLength)
{
    static ::zr_boost_1_81::winapi::HMODULE_ h = ::zr_boost_1_81::winapi::get_module_handle(L"Ntdll.dll");
    static nt_system_query_information_p f = reinterpret_cast<nt_system_query_information_p>(::zr_boost_1_81::winapi::get_proc_address(h, "NtQuerySystemInformation"));

    return (*f)(SystemInformationClass, SystemInformation, SystemInformationLength, ReturnLength);
}


inline ::zr_boost_1_81::winapi::BOOL_ nt_query_object(
        ::zr_boost_1_81::winapi::HANDLE_ Handle,
        OBJECT_INFORMATION_CLASS_ ObjectInformationClass,
        void *ObjectInformation,
        ::zr_boost_1_81::winapi::ULONG_ ObjectInformationLength,
        ::zr_boost_1_81::winapi::PULONG_ ReturnLength)
{
    static ::zr_boost_1_81::winapi::HMODULE_ h = ::zr_boost_1_81::winapi::get_module_handle(L"Ntdll.dll");
    static nt_query_object_p f = reinterpret_cast<nt_query_object_p>(::zr_boost_1_81::winapi::get_proc_address(h, "NtQueryObject"));

    return (*f)(Handle, ObjectInformationClass, ObjectInformation, ObjectInformationLength, ReturnLength);
}

#endif

}}}}}

#endif /* BOOST_PROCESS_DETAIL_WINDOWS_JOB_WORKAROUND_HPP_ */
