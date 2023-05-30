// Copyright Daniel Wallin 2006.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PARAMETER_AUX_NAME_HPP
#define BOOST_PARAMETER_AUX_NAME_HPP

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    struct name_tag_base
    {
    };

    template <typename Tag>
    struct name_tag
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/mpl/bool.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename T>
    struct is_name_tag : ::zr_boost_1_81::mpl::false_
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/value_type.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/config.hpp>
#include <boost/config/workaround.hpp>

#if !defined(BOOST_NO_SFINAE) && \
    !BOOST_WORKAROUND(BOOST_BORLANDC, BOOST_TESTED_AT(0x592))
#include <boost/parameter/aux_/lambda_tag.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/bind.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/core/enable_if.hpp>

namespace zr_boost_1_81 { namespace mpl {

    template <typename T>
    struct lambda<
        T
      , typename ::zr_boost_1_81::enable_if<
            ::zr_boost_1_81::parameter::aux::is_name_tag<T>
          , ::zr_boost_1_81::parameter::aux::lambda_tag
        >::type
    >
    {
        typedef ::zr_boost_1_81::mpl::true_ is_le;
        typedef ::zr_boost_1_81::mpl::bind3<
            ::zr_boost_1_81::mpl::quote3< ::zr_boost_1_81::parameter::value_type>
          , ::zr_boost_1_81::mpl::arg<2>
          , T
          , void
        > result_;
        typedef result_ type;
    };
}} // namespace zr_boost_1_81::mpl

#endif  // SFINAE enabled, not Borland.

#include <boost/parameter/aux_/void.hpp>

#define BOOST_PARAMETER_TAG_PLACEHOLDER_TYPE(tag)                            \
    ::zr_boost_1_81::parameter::value_type<                                          \
        ::zr_boost_1_81::mpl::_2,tag,::zr_boost_1_81::parameter::void_                       \
    >
/**/

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
#define BOOST_PARAMETER_TAG_MP11_PLACEHOLDER_VALUE(name, tag)                \
    template <typename ArgumentPack>                                         \
    using name = typename ::zr_boost_1_81::parameter                                 \
    ::value_type<ArgumentPack,tag,::zr_boost_1_81::parameter::void_>::type
/**/

#include <boost/parameter/binding.hpp>

#define BOOST_PARAMETER_TAG_MP11_PLACEHOLDER_BINDING(name, tag)              \
    template <typename ArgumentPack>                                         \
    using name = typename ::zr_boost_1_81::parameter                                 \
    ::binding<ArgumentPack,tag,::zr_boost_1_81::parameter::void_>::type
/**/

#endif  // BOOST_PARAMETER_CAN_USE_MP11
#endif  // include guard

