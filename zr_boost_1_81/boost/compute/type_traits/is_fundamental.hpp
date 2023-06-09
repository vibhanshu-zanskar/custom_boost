//---------------------------------------------------------------------------//
// Copyright (c) 2013-2014 Kyle Lutz <kyle.r.lutz@gmail.com>
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
// See http://boostorg.github.com/compute for more information.
//---------------------------------------------------------------------------//

#ifndef BOOST_COMPUTE_TYPE_TRAITS_IS_FUNDAMENTAL_HPP
#define BOOST_COMPUTE_TYPE_TRAITS_IS_FUNDAMENTAL_HPP

#include <boost/compute/types/fundamental.hpp>

namespace zr_boost_1_81 {
namespace compute {

/// Meta-function returning \c true if \p T is a fundamental (i.e.
/// built-in) type.
///
/// For example,
/// \code
/// is_fundamental<float>::value == true
/// is_fundamental<std::pair<int, float>>::value == false
/// \endcode
template<class T>
struct is_fundamental : public zr_boost_1_81::false_type {};

/// \internal_
#define BOOST_COMPUTE_DETAIL_DECLARE_FUNDAMENTAL(type) \
    template<> struct is_fundamental<BOOST_PP_CAT(type, _)> : zr_boost_1_81::true_type {}; \
    template<> struct is_fundamental<BOOST_PP_CAT(BOOST_PP_CAT(type, 2), _)> : zr_boost_1_81::true_type {}; \
    template<> struct is_fundamental<BOOST_PP_CAT(BOOST_PP_CAT(type, 4), _)> : zr_boost_1_81::true_type {}; \
    template<> struct is_fundamental<BOOST_PP_CAT(BOOST_PP_CAT(type, 8), _)> : zr_boost_1_81::true_type {}; \
    template<> struct is_fundamental<BOOST_PP_CAT(BOOST_PP_CAT(type, 16), _)> : zr_boost_1_81::true_type {}; \
    template<> struct is_fundamental<BOOST_PP_CAT(cl_, BOOST_PP_CAT(type, 2))> : zr_boost_1_81::true_type {}; \
    template<> struct is_fundamental<BOOST_PP_CAT(cl_, BOOST_PP_CAT(type, 4))> : zr_boost_1_81::true_type {}; \
    template<> struct is_fundamental<BOOST_PP_CAT(cl_, BOOST_PP_CAT(type, 8))> : zr_boost_1_81::true_type {}; \
    template<> struct is_fundamental<BOOST_PP_CAT(cl_, BOOST_PP_CAT(type, 16))> : zr_boost_1_81::true_type {};

BOOST_COMPUTE_DETAIL_DECLARE_FUNDAMENTAL(char)
BOOST_COMPUTE_DETAIL_DECLARE_FUNDAMENTAL(uchar)
BOOST_COMPUTE_DETAIL_DECLARE_FUNDAMENTAL(short)
BOOST_COMPUTE_DETAIL_DECLARE_FUNDAMENTAL(ushort)
BOOST_COMPUTE_DETAIL_DECLARE_FUNDAMENTAL(int)
BOOST_COMPUTE_DETAIL_DECLARE_FUNDAMENTAL(uint)
BOOST_COMPUTE_DETAIL_DECLARE_FUNDAMENTAL(long)
BOOST_COMPUTE_DETAIL_DECLARE_FUNDAMENTAL(ulong)
BOOST_COMPUTE_DETAIL_DECLARE_FUNDAMENTAL(float)
BOOST_COMPUTE_DETAIL_DECLARE_FUNDAMENTAL(double)

#undef BOOST_COMPUTE_DETAIL_DECLARE_FUNDAMENTAL

} // end compute namespace
} // end boost namespace

#endif // BOOST_COMPUTE_TYPE_TRAITS_IS_FUNDAMENTAL_HPP
