#ifndef BOOST_ARCHIVE_POLYMORPHIC_TEXT_WOARCHIVE_HPP
#define BOOST_ARCHIVE_POLYMORPHIC_TEXT_WOARCHIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// polymorphic_text_oarchive.hpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com .
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for updates, documentation, and revision history.

#include <boost/config.hpp>
#ifdef BOOST_NO_STD_WSTREAMBUF
#error "wide char i/o not supported on this platform"
#else

#include <boost/archive/text_woarchive.hpp>
#include <boost/archive/detail/polymorphic_oarchive_route.hpp>

namespace zr_boost_1_81 {
namespace archive {

class BOOST_SYMBOL_VISIBLE polymorphic_text_woarchive :
    public detail::polymorphic_oarchive_route<text_woarchive>
{
public:
    polymorphic_text_woarchive(std::wostream & os, unsigned int flags = 0) :
        detail::polymorphic_oarchive_route<text_woarchive>(os, flags)
    {}
    ~polymorphic_text_woarchive() BOOST_OVERRIDE {}
};

} // namespace archive
} // namespace zr_boost_1_81

// required by export
BOOST_SERIALIZATION_REGISTER_ARCHIVE(
    zr_boost_1_81::archive::polymorphic_text_woarchive
)

#endif // BOOST_NO_STD_WSTREAMBUF
#endif // BOOST_ARCHIVE_POLYMORPHIC_TEXT_WOARCHIVE_HPP
