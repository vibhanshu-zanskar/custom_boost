//  boost/filesystem/convenience.hpp  ----------------------------------------//

//  Copyright Beman Dawes, 2002-2005
//  Copyright Vladimir Prus, 2002

//  Use, modification, and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//  See library home page at http://www.boost.org/libs/filesystem

//----------------------------------------------------------------------------//

#ifndef BOOST_FILESYSTEM_CONVENIENCE_HPP
#define BOOST_FILESYSTEM_CONVENIENCE_HPP

#include <boost/filesystem/config.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/system/error_code.hpp>

#include <boost/filesystem/detail/header.hpp> // must be the last #include

namespace zr_boost_1_81 {
namespace filesystem {

#ifndef BOOST_FILESYSTEM_NO_DEPRECATED

BOOST_FILESYSTEM_DETAIL_DEPRECATED("Use path::extension() instead")
inline std::string extension(const path& p)
{
    return p.extension().string();
}

BOOST_FILESYSTEM_DETAIL_DEPRECATED("Use path::stem() instead")
inline std::string basename(const path& p)
{
    return p.stem().string();
}

BOOST_FILESYSTEM_DETAIL_DEPRECATED("Use path::replace_extension() instead")
inline path change_extension(const path& p, const path& new_extension)
{
    path new_p(p);
    new_p.replace_extension(new_extension);
    return new_p;
}

#endif

} // namespace filesystem
} // namespace zr_boost_1_81

#include <boost/filesystem/detail/footer.hpp>

#endif // BOOST_FILESYSTEM_CONVENIENCE_HPP
