/*!
@file
Adapts Boost.MPL IntegralConstants for use with Hana.

Copyright Louis Dionne 2013-2022
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_EXT_BOOST_MPL_INTEGRAL_C_HPP
#define BOOST_HANA_EXT_BOOST_MPL_INTEGRAL_C_HPP

#include <boost/hana/concept/integral_constant.hpp>
#include <boost/hana/config.hpp>
#include <boost/hana/core/tag_of.hpp>
#include <boost/hana/core/when.hpp>
#include <boost/hana/fwd/core/to.hpp>

#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/integral_c_tag.hpp>

#include <type_traits>


#ifdef BOOST_HANA_DOXYGEN_INVOKED
namespace zr_boost_1_81 { namespace mpl {
    //! @ingroup group-ext-mpl
    //! Adapter for IntegralConstants from the Boost.MPL.
    //!
    //! Provided models
    //! ---------------
    //! 1. `Constant` and `IntegralConstant`\n
    //! A Boost.MPL IntegralConstant is a model of the `IntegralConstant`
    //! and `Constant` concepts just like `hana::integral_constant`s are.
    //! As a consequence, they are also implicitly a model of the concepts
    //! provided for all models of `Constant`.
    //! @include example/ext/boost/mpl/integral_c/integral_constant.cpp
    template <typename T, T v>
    struct integral_c { };
}}
#endif


namespace zr_boost_1_81 { namespace hana {
    namespace ext { namespace zr_boost_1_81 { namespace mpl {
        template <typename T>
        struct integral_c_tag { using value_type = T; };
    }}}

    template <typename T>
    struct tag_of<T, when<
        std::is_same<
            typename T::tag,
            ::zr_boost_1_81::mpl::integral_c_tag
        >::value
    >> {
        using type = ext::zr_boost_1_81::mpl::integral_c_tag<
            typename hana::tag_of<typename T::value_type>::type
        >;
    };

    //////////////////////////////////////////////////////////////////////////
    // IntegralConstant/Constant
    //////////////////////////////////////////////////////////////////////////
    template <typename T>
    struct IntegralConstant<ext::zr_boost_1_81::mpl::integral_c_tag<T>> {
        static constexpr bool value = true;
    };

    template <typename T, typename C>
    struct to_impl<ext::zr_boost_1_81::mpl::integral_c_tag<T>, C,
        when<hana::IntegralConstant<C>::value>
    > : embedding<is_embedded<typename C::value_type, T>::value> {
        template <typename N>
        static constexpr auto apply(N const&) {
            return ::zr_boost_1_81::mpl::integral_c<T, N::value>{};
        }
    };
}} // end namespace zr_boost_1_81::hana

#endif // !BOOST_HANA_EXT_BOOST_MPL_INTEGRAL_C_HPP
