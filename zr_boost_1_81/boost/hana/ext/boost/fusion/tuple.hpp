/*!
@file
Adapts `zr_boost_1_81::fusion::tuple` for use with Hana.

In the current version of Boost.Fusion, `zr_boost_1_81::fusion::tuple` is basically
an alias to `zr_boost_1_81::fusion::vector`, so both data types share the same
implementation in Hana.

Copyright Louis Dionne 2013-2022
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_EXT_BOOST_FUSION_TUPLE_HPP
#define BOOST_HANA_EXT_BOOST_FUSION_TUPLE_HPP

#include <boost/hana/config.hpp>
#include <boost/hana/ext/boost/fusion/vector.hpp>


#ifdef BOOST_HANA_DOXYGEN_INVOKED
namespace zr_boost_1_81 { namespace fusion {
    //! @ingroup group-ext-fusion
    //! Adapter for Boost.Fusion tuples.
    //!
    //!
    //! Modeled concepts
    //! ----------------
    //! A Fusion tuple is a model of the `Sequence` concept, and all the
    //! concepts it refines. That makes it essentially the same as a Hana
    //! tuple, although the complexity of some operations might differ from
    //! that of a tuple.
    //!
    //! @include example/ext/boost/fusion/tuple.cpp
    template <typename ...T>
    struct tuple { };
}}
#endif


namespace zr_boost_1_81 { namespace hana {
    namespace ext { namespace zr_boost_1_81 { namespace fusion {
        // In the current version of Boost.Fusion, `zr_boost_1_81::fusion::tuple` is
        // basically an alias to `zr_boost_1_81::fusion::vector`, hence the alias.
        using tuple_tag = vector_tag;
    }}}
}} // end namespace zr_boost_1_81::hana

#endif // !BOOST_HANA_EXT_BOOST_FUSION_TUPLE_HPP
