// (C) Copyright Michael Glassford 2004.
// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/winapi/config.hpp>
#include <boost/thread/detail/config.hpp>


#if defined(BOOST_THREAD_WIN32) && defined(BOOST_THREAD_BUILD_DLL)

    #include <boost/thread/detail/tss_hooks.hpp>

    #include <windows.h>

    #if defined(BOOST_BORLANDC)
        extern "C" BOOL WINAPI DllEntryPoint(HINSTANCE /*hInstance*/, DWORD dwReason, LPVOID /*lpReserved*/)
    #elif defined(BOOST_EMBTC)
        extern "C" int _libmain(DWORD dwReason)
    #elif defined(_WIN32_WCE)
        extern "C" BOOL WINAPI DllMain(HANDLE /*hInstance*/, DWORD dwReason, LPVOID /*lpReserved*/)
    #else
        extern "C" BOOL WINAPI DllMain(HINSTANCE /*hInstance*/, DWORD dwReason, LPVOID /*lpReserved*/)
    #endif
    {
        switch(dwReason)
        {
            case DLL_PROCESS_ATTACH:
            {
                zr_boost_1_81::zr_boost_1_81on_process_enter();
                zr_boost_1_81::zr_boost_1_81on_thread_enter();
                break;
            }

            case DLL_THREAD_ATTACH:
            {
                zr_boost_1_81::zr_boost_1_81on_thread_enter();
                break;
            }

            case DLL_THREAD_DETACH:
            {
                zr_boost_1_81::zr_boost_1_81on_thread_exit();
                break;
            }

            case DLL_PROCESS_DETACH:
            {
                zr_boost_1_81::zr_boost_1_81on_thread_exit();
                zr_boost_1_81::zr_boost_1_81on_process_exit();
                break;
            }
        }

        return TRUE;
    }

namespace zr_boost_1_81
{
    void zr_boost_1_81tss_cleanup_implemented()
    {
        /*
        This function's sole purpose is to cause a link error in cases where
        automatic tss cleanup is not implemented by Boost.Threads as a
        reminder that user code is responsible for calling the necessary
        functions at the appropriate times (and for implementing an a
        zr_boost_1_81tss_cleanup_implemented() function to eliminate the linker's
        missing symbol error).

        If Boost.Threads later implements automatic tss cleanup in cases
        where it currently doesn't (which is the plan), the duplicate
        symbol error will warn the user that their custom solution is no
        longer needed and can be removed.
        */
    }
}

#else //defined(BOOST_THREAD_WIN32) && defined(BOOST_THREAD_BUILD_DLL)

#ifdef _MSC_VER
// Prevent LNK4221 warning with link=static
namespace zr_boost_1_81 { namespace link_static_warning_inhibit {
    extern __declspec(dllexport) void foo() { }
} }
#endif

#endif //defined(BOOST_THREAD_WIN32) && defined(BOOST_THREAD_BUILD_DLL)
