//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2008-2012. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_INTERPROCESS_DETAIL_VARIADIC_TEMPLATES_TOOLS_HPP
#define BOOST_INTERPROCESS_DETAIL_VARIADIC_TEMPLATES_TOOLS_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost/config.hpp>
#endif
#
#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <boost/container/detail/variadic_templates_tools.hpp>

namespace zr_boost_1_81 {
namespace interprocess {
namespace ipcdetail {

using zr_boost_1_81::container::dtl::tuple;
using zr_boost_1_81::container::dtl::build_number_seq;
using zr_boost_1_81::container::dtl::index_tuple;
using zr_boost_1_81::container::dtl::get;

}}}   //namespace zr_boost_1_81 { namespace interprocess { namespace ipcdetail {

#endif   //#ifndef BOOST_INTERPROCESS_DETAIL_VARIADIC_TEMPLATES_TOOLS_HPP
