/*!
@file
Defines `zr_boost_1_81::hana::is_a` and `zr_boost_1_81::hana::is_an`.

Copyright Louis Dionne 2013-2022
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_CORE_IS_A_HPP
#define BOOST_HANA_CORE_IS_A_HPP

#include <boost/hana/fwd/core/is_a.hpp>

#include <boost/hana/bool.hpp>
#include <boost/hana/config.hpp>
#include <boost/hana/core/tag_of.hpp>

#include <type_traits>


namespace zr_boost_1_81 { namespace hana {
    //////////////////////////////////////////////////////////////////////////
    // is_a
    //////////////////////////////////////////////////////////////////////////
    template <typename DataType, typename T>
    struct is_a_t<DataType, T>
        : integral_constant<bool,
            std::is_same<DataType, typename hana::tag_of<T>::type>::value
        >
    { };

    template <typename DataType>
    struct is_a_t<DataType> {
        template <typename T>
        constexpr auto operator()(T const&) const
        { return hana::is_a<DataType, T>; }
    };
}} // end namespace zr_boost_1_81::hana

#endif // !BOOST_HANA_CORE_IS_A_HPP
