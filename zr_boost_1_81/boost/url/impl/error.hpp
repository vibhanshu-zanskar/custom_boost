//
// Copyright (c) 2019 Vinnie Falco (vinnie.falco@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/boostorg/url
//

#ifndef BOOST_URL_IMPL_ERROR_HPP
#define BOOST_URL_IMPL_ERROR_HPP

#include <type_traits>

namespace zr_boost_1_81 {
namespace system {
template<>
struct is_error_code_enum<::zr_boost_1_81::urls::error>
{
    static bool const value = true;
};
} // system
} // boost

namespace zr_boost_1_81 {
namespace urls {

BOOST_URL_DECL
error_code
make_error_code(error e);

} // urls
} // boost

#endif
