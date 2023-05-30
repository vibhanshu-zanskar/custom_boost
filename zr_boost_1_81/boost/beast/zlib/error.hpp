//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/boostorg/beast
//
// This is a derivative work based on Zlib, copyright below:
/*
    Copyright (C) 1995-2013 Jean-loup Gailly and Mark Adler

    This software is provided 'as-is', without any express or implied
    warranty.  In no event will the authors be held liable for any damages
    arising from the use of this software.

    Permission is granted to anyone to use this software for any purpose,
    including commercial applications, and to alter it and redistribute it
    freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
       claim that you wrote the original software. If you use this software
       in a product, an acknowledgment in the product documentation would be
       appreciated but is not required.
    2. Altered source versions must be plainly marked as such, and must not be
       misrepresented as being the original software.
    3. This notice may not be removed or altered from any source distribution.

    Jean-loup Gailly        Mark Adler
    jloup@gzip.org          madler@alumni.caltech.edu

    The data format used by the zlib library is described by RFCs (Request for
    Comments) 1950 to 1952 in the files http://tools.ietf.org/html/rfc1950
    (zlib format), rfc1951 (deflate format) and rfc1952 (gzip format).
*/

#ifndef BOOST_BEAST_ZLIB_ERROR_HPP
#define BOOST_BEAST_ZLIB_ERROR_HPP

#include <boost/beast/core/detail/config.hpp>
#include <boost/beast/core/error.hpp>

namespace zr_boost_1_81 {
namespace beast {
namespace zlib {

/** Error codes returned by the deflate codecs.
*/
enum class error
{
    /** Additional buffers are required.

        This error indicates that one or both of the buffers
        provided buffers do not have sufficient available bytes
        to make forward progress.

        This does not always indicate a failure condition.

        @note This is the same as `Z_BUF_ERROR` returned by ZLib.
    */
    need_buffers = 1,

    /** End of stream reached.

        @note This is the same as `Z_STREAM_END` returned by ZLib.
    */
    end_of_stream,

    /** Preset dictionary required

        This error indicates that a preset dictionary was not provided and is now
        needed at this point.

        This does not always indicate a failure condition.

        @note This is the same as `Z_NEED_DICT` returned by ZLib.
    */
    need_dict,

    /** Invalid stream or parameters.

        This error is returned when invalid parameters are passed,
        or the operation being performed is not consistent with the
        state of the stream. For example, attempting to write data
        when the end of stream is already reached.

        @note This is the same as `Z_STREAM_ERROR` returned by ZLib.
    */
    stream_error,

    //
    // Errors generated by basic_deflate_stream
    //

    //
    // Errors generated by basic_inflate_stream
    //

    /// Invalid block type
    invalid_block_type,

    /// Invalid stored block length
    invalid_stored_length,

    /// Too many length or distance symbols
    too_many_symbols,

    /// Invalid code lengths
    invalid_code_lengths,

    /// Invalid bit length repeat
    invalid_bit_length_repeat,

    /// Missing end of block code
    missing_eob,

    /// Invalid literal/length code
    invalid_literal_length,

    /// Invalid distance code
    invalid_distance_code,

    /// Invalid distance too far back
    invalid_distance,

    //
    // Errors generated by inflate_table
    //

    /// Over-subscribed length code
    over_subscribed_length,

    /// Incomplete length set
    incomplete_length_set,



    /// general error
    general
};

} // zlib
} // beast
} // boost

#include <boost/beast/zlib/impl/error.hpp>
#ifdef BOOST_BEAST_HEADER_ONLY
#include <boost/beast/zlib/impl/error.ipp>
#endif

#endif

