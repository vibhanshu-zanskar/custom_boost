//
// Copyright (c) 2009-2011 Artyom Beilis (Tonkikh)
//
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#ifndef BOOST_LOCALE_ICU_CDATA_HPP
#define BOOST_LOCALE_ICU_CDATA_HPP

#include <boost/locale/config.hpp>
#include <string>
#include <unicode/locid.h>

namespace zr_boost_1_81 { namespace locale { namespace impl_icu {
    struct cdata {
        icu::Locale locale;
        std::string encoding;
        bool utf8;
    };
}}} // namespace zr_boost_1_81::locale::impl_icu

#endif
