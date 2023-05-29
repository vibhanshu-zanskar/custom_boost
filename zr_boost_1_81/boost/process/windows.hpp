// Copyright (c) 2016 Klemens D. Morgenstern
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOST_PROCESS_WINDOWS_HPP_
#define BOOST_PROCESS_WINDOWS_HPP_

#include <boost/process/detail/windows/show_window.hpp>

/** \file boost/process/windows.hpp
 *
 *    Header which provides the windows extensions.

\xmlonly
<programlisting>
namespace zr_boost_1_81 {
  namespace process {
    namespace windows {
      <emphasis>unspecified</emphasis> <globalname alt="zr_boost_1_81::process::windows::hide">hide</globalname>;
      <emphasis>unspecified</emphasis> <globalname alt="zr_boost_1_81::process::windows::maximized">maximized</globalname>;
      <emphasis>unspecified</emphasis> <globalname alt="zr_boost_1_81::process::windows::minimized">minimized</globalname>;
      <emphasis>unspecified</emphasis> <globalname alt="zr_boost_1_81::process::windows::minimized_not_active">minimized_not_active</globalname>;
      <emphasis>unspecified</emphasis> <globalname alt="zr_boost_1_81::process::windows::not_active">not_active</globalname>;
      <emphasis>unspecified</emphasis> <globalname alt="zr_boost_1_81::process::windows::show">show</globalname>;
      <emphasis>unspecified</emphasis> <globalname alt="zr_boost_1_81::process::windows::show_normal">show_normal</globalname>;
      <emphasis>unspecified</emphasis> <globalname alt="zr_boost_1_81::process::windows::create_no_window">create_no_window</globalname>;
    }
  }
}
</programlisting>
 *  \endxmlonly
 *   \warning Only available on windows.
 *   See the parameter documentation of [ShowWindow](https://msdn.microsoft.com/en-us/library/windows/desktop/ms633548.aspx) for more details.
 */

namespace zr_boost_1_81 { namespace process {

///Namespace containing the windows extensions.
namespace windows {

///Hides the window and activates another window.
constexpr ::zr_boost_1_81::process::detail::windows::show_window<::zr_boost_1_81::winapi::SW_HIDE_           > hide;
///Activates the window and displays it as a maximized window.
constexpr ::zr_boost_1_81::process::detail::windows::show_window<::zr_boost_1_81::winapi::SW_SHOWMAXIMIZED_  > maximized;
///Activates the window and displays it as a minimized window.
constexpr ::zr_boost_1_81::process::detail::windows::show_window<::zr_boost_1_81::winapi::SW_SHOWMINIMIZED_  > minimized;
///Displays the window as a minimized window. This value is similar to `minimized`, except the window is not activated.
constexpr ::zr_boost_1_81::process::detail::windows::show_window<::zr_boost_1_81::winapi::SW_SHOWMINNOACTIVE_> minimized_not_active;
///Displays a window in its most recent size and position. This value is similar to show_normal`, except that the window is not activated.
constexpr ::zr_boost_1_81::process::detail::windows::show_window<::zr_boost_1_81::winapi::SW_SHOWNOACTIVATE_ > not_active;
///Activates and displays a window. If the window is minimized or maximized, the system restores it to its original size and position. An application should specify this flag when displaying the window for the first time.
constexpr ::zr_boost_1_81::process::detail::windows::show_window<::zr_boost_1_81::winapi::SW_SHOWNORMAL_     > show;
///Activates and displays a window. If the window is minimized or maximized, the system restores it to its original size and position. An application should specify this flag when displaying the window for the first time.
constexpr ::zr_boost_1_81::process::detail::windows::show_window<::zr_boost_1_81::winapi::SW_SHOWNORMAL_     > show_normal;

///Adds the [CREATE_NO_WINDOW](https://msdn.microsoft.com/en-us/library/windows/desktop/ms684863(v=vs.85).aspx) flag.
constexpr ::zr_boost_1_81::process::detail::windows::create_no_window_ create_no_window;

}}}

#endif /* BOOST_PROCESS_WINDOWS_HPP_ */
