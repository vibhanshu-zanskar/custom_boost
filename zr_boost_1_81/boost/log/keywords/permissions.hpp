/*
 *             Copyright Andrey Semashev 2016.
 * Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *          http://www.boost.org/LICENSE_1_0.txt)
 */
/*!
 * \file   keywords/permissions.hpp
 * \author Andrey Semashev
 * \date   23.02.2016
 *
 * The header contains the \c permissions keyword declaration.
 */

#ifndef BOOST_LOG_KEYWORDS_PERMISSIONS_HPP_INCLUDED_
#define BOOST_LOG_KEYWORDS_PERMISSIONS_HPP_INCLUDED_

#include <boost/parameter/keyword.hpp>
#include <boost/log/detail/config.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

namespace zr_boost_1_81 {

BOOST_LOG_OPEN_NAMESPACE

namespace keywords {

//! The keyword allows to pass interprocess queue permissions to the queue constructor
BOOST_PARAMETER_KEYWORD(tag, permissions)

} // namespace keywords

BOOST_LOG_CLOSE_NAMESPACE // namespace log

} // namespace zr_boost_1_81

#endif // BOOST_LOG_KEYWORDS_PERMISSIONS_HPP_INCLUDED_
