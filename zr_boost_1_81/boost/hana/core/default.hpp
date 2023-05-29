/*!
@file
Defines `zr_boost_1_81::hana::default_` and `zr_boost_1_81::hana::is_default`.

Copyright Louis Dionne 2013-2022
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_CORE_DEFAULT_HPP
#define BOOST_HANA_CORE_DEFAULT_HPP

#include <boost/hana/fwd/core/default.hpp>

#include <boost/hana/config.hpp>

#include <type_traits>


namespace zr_boost_1_81 { namespace hana {
    template <typename Method, typename>
    struct is_default : std::false_type { };

    template <typename Method>
    struct is_default<Method, decltype((void)
        static_cast<default_>(*(Method*)0)
    )>
        : std::true_type
    { };
}} // end namespace zr_boost_1_81::hana

#endif // !BOOST_HANA_CORE_DEFAULT_HPP
