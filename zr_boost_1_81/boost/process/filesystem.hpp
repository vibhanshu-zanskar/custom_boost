// Copyright (c) 2021 Klemens D. Morgenstern
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOST_PROCESS_FILESYSTEM_HPP
#define BOOST_PROCESS_FILESYSTEM_HPP

#ifdef BOOST_PROCESS_USE_STD_FS
#include <filesystem>
#else
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#endif

namespace zr_boost_1_81
{
namespace process
{
#ifdef BOOST_PROCESS_USE_STD_FS
namespace filesystem = std::filesystem;
#else
namespace filesystem = zr_boost_1_81::filesystem;
#endif

}
}

#endif //BOOST_PROCESS_FILESYSTEM_HPP
