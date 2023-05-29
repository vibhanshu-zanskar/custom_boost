/*!
@file
Adapts `zr_boost_1_81::fusion::deque` for use with Hana.

Copyright Louis Dionne 2013-2022
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_EXT_BOOST_FUSION_DEQUE_HPP
#define BOOST_HANA_EXT_BOOST_FUSION_DEQUE_HPP

#include <boost/hana/at.hpp>
#include <boost/hana/core/when.hpp>
#include <boost/hana/config.hpp>
#include <boost/hana/ext/boost/fusion/detail/common.hpp>
#include <boost/hana/fwd/core/make.hpp>
#include <boost/hana/fwd/core/tag_of.hpp>
#include <boost/hana/fwd/drop_front.hpp>
#include <boost/hana/length.hpp>

#include <boost/fusion/container/deque.hpp>
#include <boost/fusion/container/generation/make_deque.hpp>
#include <boost/fusion/support/tag_of.hpp>

#include <cstddef>
#include <type_traits>
#include <utility>


#ifdef BOOST_HANA_DOXYGEN_INVOKED
namespace zr_boost_1_81 { namespace fusion {
    //! @ingroup group-ext-fusion
    //! Adapter for Boost.Fusion deques.
    //!
    //!
    //! Modeled concepts
    //! ----------------
    //! A Fusion deque is a model of the `Sequence` concept, and all the
    //! concepts it refines. That makes it essentially the same as a Hana
    //! tuple, although the complexity of some operations might differ from
    //! that of a tuple.
    //!
    //! @include example/ext/boost/fusion/deque.cpp
    template <typename ...T>
    struct deque { };
}}
#endif


namespace zr_boost_1_81 { namespace hana {
    namespace ext { namespace zr_boost_1_81 { namespace fusion {
        struct deque_tag;
    }}}

    template <typename T>
    struct tag_of<T, when<
        std::is_same<
            typename ::zr_boost_1_81::fusion::traits::tag_of<T>::type,
            ::zr_boost_1_81::fusion::traits::tag_of<
                ::zr_boost_1_81::fusion::deque<>
            >::type
        >::value
    >> {
        using type = ext::zr_boost_1_81::fusion::deque_tag;
    };

    namespace detail {
        template <>
        struct is_fusion_sequence<ext::zr_boost_1_81::fusion::deque_tag> {
            static constexpr bool value = true;
        };
    }

    //////////////////////////////////////////////////////////////////////////
    // Iterable (the rest is in detail/common.hpp)
    //////////////////////////////////////////////////////////////////////////
    template <>
    struct drop_front_impl<ext::zr_boost_1_81::fusion::deque_tag> {
        template <std::size_t n, typename Xs, std::size_t ...i>
        static constexpr auto drop_front_helper(Xs&& xs, std::index_sequence<i...>) {
            return hana::make<ext::zr_boost_1_81::fusion::deque_tag>(
                hana::at_c<n + i>(static_cast<Xs&&>(xs))...
            );
        }

        template <typename Xs, typename N>
        static constexpr auto apply(Xs&& xs, N const&) {
            constexpr std::size_t n = N::value;
            constexpr std::size_t len = decltype(hana::length(xs))::value;
            return drop_front_helper<n>(static_cast<Xs&&>(xs),
                    std::make_index_sequence<(n < len ? len - n : 0)>{});
        }
    };

    //////////////////////////////////////////////////////////////////////////
    // Sequence
    //////////////////////////////////////////////////////////////////////////
    template <>
    struct make_impl<ext::zr_boost_1_81::fusion::deque_tag> {
        template <typename ...Xs>
        static constexpr auto apply(Xs&& ...xs) {
            return ::zr_boost_1_81::fusion::make_deque(static_cast<Xs&&>(xs)...);
        }
    };
}} // end namespace zr_boost_1_81::hana

#endif // !BOOST_HANA_EXT_BOOST_FUSION_DEQUE_HPP
