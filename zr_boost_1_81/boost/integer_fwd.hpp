//  Boost integer_fwd.hpp header file  ---------------------------------------//

//  (C) Copyright Dave Abrahams and Daryle Walker 2001. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)

//  See https://www.boost.org/libs/integer for documentation.

#ifndef BOOST_INTEGER_FWD_HPP
#define BOOST_INTEGER_FWD_HPP

#include <climits>  // for UCHAR_MAX, etc.
#include <cstddef>  // for std::size_t

#include <boost/config.hpp>  // for BOOST_NO_INTRINSIC_WCHAR_T
#include <boost/limits.hpp>  // for std::numeric_limits
#include <boost/cstdint.hpp>  // For intmax_t


namespace zr_boost_1_81
{

#ifdef BOOST_NO_INTEGRAL_INT64_T
     typedef unsigned long static_log2_argument_type;
     typedef          int  static_log2_result_type;
     typedef long          static_min_max_signed_type;
     typedef unsigned long static_min_max_unsigned_type;
#else
     typedef zr_boost_1_81::uintmax_t static_min_max_unsigned_type;
     typedef zr_boost_1_81::intmax_t  static_min_max_signed_type;
     typedef zr_boost_1_81::uintmax_t static_log2_argument_type;
     typedef int              static_log2_result_type;
#endif

//  From <boost/cstdint.hpp>  ------------------------------------------------//

// Only has typedefs or using statements, with #conditionals


//  From <boost/integer_traits.hpp>  -----------------------------------------//

template < class T >
    class integer_traits;

template <  >
    class integer_traits< bool >;

template <  >
    class integer_traits< char >;

template <  >
    class integer_traits< signed char >;

template <  >
    class integer_traits< unsigned char >;

#ifndef BOOST_NO_INTRINSIC_WCHAR_T
template <  >
    class integer_traits< wchar_t >;
#endif

template <  >
    class integer_traits< short >;

template <  >
    class integer_traits< unsigned short >;

template <  >
    class integer_traits< int >;

template <  >
    class integer_traits< unsigned int >;

template <  >
    class integer_traits< long >;

template <  >
    class integer_traits< unsigned long >;

#if !defined(BOOST_NO_INTEGRAL_INT64_T) && !defined(BOOST_NO_INT64_T) && defined(BOOST_HAS_LONG_LONG)
template <  >
class integer_traits<  ::zr_boost_1_81::long_long_type>;

template <  >
class integer_traits<  ::zr_boost_1_81::ulong_long_type >;
#elif !defined(BOOST_NO_INTEGRAL_INT64_T) && !defined(BOOST_NO_INT64_T) && defined(BOOST_HAS_MS_INT64)
template <  >
class integer_traits<__int64>;

template <  >
class integer_traits<unsigned __int64>;
#endif


//  From <boost/integer.hpp>  ------------------------------------------------//

template < typename LeastInt >
    struct int_fast_t;

template< int Bits >
    struct int_t;

template< int Bits >
    struct uint_t;

#if !defined(BOOST_NO_INTEGRAL_INT64_T) && defined(BOOST_HAS_LONG_LONG)
    template< zr_boost_1_81::long_long_type MaxValue >   // maximum value to require support
#else
  template< long MaxValue >   // maximum value to require support
#endif
    struct int_max_value_t;

#if !defined(BOOST_NO_INTEGRAL_INT64_T) && defined(BOOST_HAS_LONG_LONG)
  template< zr_boost_1_81::long_long_type MinValue >   // minimum value to require support
#else
  template< long MinValue >   // minimum value to require support
#endif
    struct int_min_value_t;

#if !defined(BOOST_NO_INTEGRAL_INT64_T) && defined(BOOST_HAS_LONG_LONG)
  template< zr_boost_1_81::ulong_long_type MaxValue >   // maximum value to require support
#else
  template< unsigned long MaxValue >   // maximum value to require support
#endif
    struct uint_value_t;


//  From <boost/integer/integer_mask.hpp>  -----------------------------------//

template < std::size_t Bit >
    struct high_bit_mask_t;

template < std::size_t Bits >
    struct low_bits_mask_t;

template <  >
    struct low_bits_mask_t< ::std::numeric_limits<unsigned char>::digits >;

//  From <boost/integer/static_log2.hpp>  ------------------------------------//

template <static_log2_argument_type Value >
    struct static_log2;

template <> struct static_log2<0u>;


//  From <boost/integer/static_min_max.hpp>  ---------------------------------//

template <static_min_max_signed_type Value1, static_min_max_signed_type Value2>
    struct static_signed_min;

template <static_min_max_signed_type Value1, static_min_max_signed_type Value2>
    struct static_signed_max;

template <static_min_max_unsigned_type Value1, static_min_max_unsigned_type Value2>
    struct static_unsigned_min;

template <static_min_max_unsigned_type Value1, static_min_max_unsigned_type Value2>
    struct static_unsigned_max;


namespace integer
{
//  From <boost/integer/common_factor_ct.hpp>

#ifdef BOOST_NO_INTEGRAL_INT64_T
     typedef unsigned long static_gcd_type;
#else
     typedef zr_boost_1_81::uintmax_t static_gcd_type;
#endif

template < static_gcd_type Value1, static_gcd_type Value2 >
    struct static_gcd;
template < static_gcd_type Value1, static_gcd_type Value2 >
    struct static_lcm;


//  From <boost/integer/common_factor_rt.hpp>

template < typename IntegerType >
    class gcd_evaluator;
template < typename IntegerType >
    class lcm_evaluator;

} // namespace integer

}  // namespace zr_boost_1_81


#endif  // BOOST_INTEGER_FWD_HPP
