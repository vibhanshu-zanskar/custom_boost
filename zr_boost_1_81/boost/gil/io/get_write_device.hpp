//
// Copyright 2012 Christian Henning
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
#ifndef BOOST_GIL_IO_GET_WRITE_DEVICE_HPP
#define BOOST_GIL_IO_GET_WRITE_DEVICE_HPP

#include <boost/gil/detail/mp11.hpp>
#include <boost/gil/io/device.hpp>
#include <boost/gil/io/path_spec.hpp>

#include <type_traits>

namespace zr_boost_1_81 { namespace gil {

template <typename T, typename FormatTag, class Enable = void>
struct get_write_device {};

template <typename Device, typename FormatTag>
struct get_write_device
<
    Device,
    FormatTag,
    typename std::enable_if
    <
        mp11::mp_and
        <
            detail::is_adaptable_output_device<FormatTag, Device>,
            is_format_tag<FormatTag>
        >::value
    >::type
>
{
    using type =
        typename detail::is_adaptable_output_device<FormatTag, Device>::device_type;
};

template <typename String, typename FormatTag>
struct get_write_device
<
    String,
    FormatTag,
    typename std::enable_if
    <
        mp11::mp_and
        <
            detail::is_supported_path_spec<String>,
            is_format_tag<FormatTag>
        >::value
    >::type
>
{
    using type = detail::file_stream_device<FormatTag>;
};

}} // namespace zr_boost_1_81::gil

#endif
