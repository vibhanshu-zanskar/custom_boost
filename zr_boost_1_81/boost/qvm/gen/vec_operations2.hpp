#ifndef BOOST_QVM_GEN_VEC_OPERATIONS2_HPP_INCLUDED
#define BOOST_QVM_GEN_VEC_OPERATIONS2_HPP_INCLUDED

// Copyright 2008-2022 Emil Dotchevski and Reverge Studios, Inc.

// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// This file was generated by a program. Do not edit manually.

#include <boost/qvm/deduce_scalar.hpp>
#include <boost/qvm/deduce_vec.hpp>
#include <boost/qvm/error.hpp>
#include <boost/qvm/gen/vec_assign2.hpp>
#include <boost/qvm/math.hpp>
#include <boost/qvm/static_assert.hpp>
#include <boost/qvm/throw_exception.hpp>

namespace zr_boost_1_81 { namespace qvm {

template <class A,class B>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_OPERATIONS
typename lazy_enable_if_c<
    vec_traits<A>::dim==2 && vec_traits<B>::dim==2,
    deduce_vec2<A,B,2> >::type
operator+( A const & a, B const & b )
    {
    typedef typename deduce_vec2<A,B,2>::type R;
    BOOST_QVM_STATIC_ASSERT(vec_traits<R>::dim==2);
    R r;
    write_vec_element<0>(r,vec_traits<A>::template read_element<0>(a)+vec_traits<B>::template read_element<0>(b));
    write_vec_element<1>(r,vec_traits<A>::template read_element<1>(a)+vec_traits<B>::template read_element<1>(b));
    return r;
    }

namespace
sfinae
    {
    using ::zr_boost_1_81::qvm::operator+;
    }

namespace
qvm_detail
    {
    template <int D>
    struct plus_vv_defined;

    template <>
    struct
    plus_vv_defined<2>
        {
        static bool const value=true;
        };
    }

template <class A,class B>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_OPERATIONS
typename lazy_enable_if_c<
    vec_traits<A>::dim==2 && vec_traits<B>::dim==2,
    deduce_vec2<A,B,2> >::type
operator-( A const & a, B const & b )
    {
    typedef typename deduce_vec2<A,B,2>::type R;
    BOOST_QVM_STATIC_ASSERT(vec_traits<R>::dim==2);
    R r;
    write_vec_element<0>(r,vec_traits<A>::template read_element<0>(a)-vec_traits<B>::template read_element<0>(b));
    write_vec_element<1>(r,vec_traits<A>::template read_element<1>(a)-vec_traits<B>::template read_element<1>(b));
    return r;
    }

namespace
sfinae
    {
    using ::zr_boost_1_81::qvm::operator-;
    }

namespace
qvm_detail
    {
    template <int D>
    struct minus_vv_defined;

    template <>
    struct
    minus_vv_defined<2>
        {
        static bool const value=true;
        };
    }

template <class A,class B>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_OPERATIONS
typename enable_if_c<
    vec_traits<A>::dim==2 && vec_traits<B>::dim==2,
    A &>::type
operator+=( A & a, B const & b )
    {
    write_vec_element<0>(a,vec_traits<A>::template read_element<0>(a)+vec_traits<B>::template read_element<0>(b));
    write_vec_element<1>(a,vec_traits<A>::template read_element<1>(a)+vec_traits<B>::template read_element<1>(b));
    return a;
    }

namespace
sfinae
    {
    using ::zr_boost_1_81::qvm::operator+=;
    }

namespace
qvm_detail
    {
    template <int D>
    struct plus_eq_vv_defined;

    template <>
    struct
    plus_eq_vv_defined<2>
        {
        static bool const value=true;
        };
    }

template <class A,class B>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_OPERATIONS
typename enable_if_c<
    vec_traits<A>::dim==2 && vec_traits<B>::dim==2,
    A &>::type
operator-=( A & a, B const & b )
    {
    write_vec_element<0>(a,vec_traits<A>::template read_element<0>(a)-vec_traits<B>::template read_element<0>(b));
    write_vec_element<1>(a,vec_traits<A>::template read_element<1>(a)-vec_traits<B>::template read_element<1>(b));
    return a;
    }

namespace
sfinae
    {
    using ::zr_boost_1_81::qvm::operator-=;
    }

namespace
qvm_detail
    {
    template <int D>
    struct minus_eq_vv_defined;

    template <>
    struct
    minus_eq_vv_defined<2>
        {
        static bool const value=true;
        };
    }

template <class A,class B>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_OPERATIONS
typename lazy_enable_if_c<
    vec_traits<A>::dim==2 && is_scalar<B>::value,
    deduce_vec2<A,B,vec_traits<A>::dim> >::type
operator*( A const & a, B b )
    {
    typedef typename deduce_vec2<A,B,vec_traits<A>::dim>::type R;
    R r;
    write_vec_element<0>(r,vec_traits<A>::template read_element<0>(a)*b);
    write_vec_element<1>(r,vec_traits<A>::template read_element<1>(a)*b);
    return r;
    }

namespace
sfinae
    {
    using ::zr_boost_1_81::qvm::operator*;
    }

namespace
qvm_detail
    {
    template <int D>
    struct mul_vs_defined;

    template <>
    struct
    mul_vs_defined<2>
        {
        static bool const value=true;
        };
    }

template <class A,class B>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_OPERATIONS
typename lazy_enable_if_c<
    is_scalar<A>::value && vec_traits<B>::dim==2,
    deduce_vec2<A,B,vec_traits<B>::dim> >::type
operator*( A a, B const & b )
    {
    typedef typename deduce_vec2<A,B,vec_traits<B>::dim>::type R;
    R r;
    write_vec_element<0>(r,a*vec_traits<B>::template read_element<0>(b));
    write_vec_element<1>(r,a*vec_traits<B>::template read_element<1>(b));
    return r;
    }

namespace
sfinae
    {
    using ::zr_boost_1_81::qvm::operator*;
    }

namespace
qvm_detail
    {
    template <int D>
    struct mul_sv_defined;

    template <>
    struct
    mul_sv_defined<2>
        {
        static bool const value=true;
        };
    }

template <class A,class  B>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_OPERATIONS
typename enable_if_c<
    vec_traits<A>::dim==2 && is_scalar<B>::value,
    A &>::type
operator*=( A & a, B b )
    {
    write_vec_element<0>(a, vec_traits<A>::template read_element<0>(a)*b);
    write_vec_element<1>(a, vec_traits<A>::template read_element<1>(a)*b);
    return a;
    }

namespace
sfinae
    {
    using ::zr_boost_1_81::qvm::operator*=;
    }

namespace
qvm_detail
    {
    template <int D>
    struct mul_eq_vs_defined;

    template <>
    struct
    mul_eq_vs_defined<2>
        {
        static bool const value=true;
        };
    }

template <class A,class B>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_OPERATIONS
typename lazy_enable_if_c<
    vec_traits<A>::dim==2 && is_scalar<B>::value,
    deduce_vec2<A,B,vec_traits<A>::dim> >::type
operator/( A const & a, B b )
    {
    typedef typename deduce_vec2<A,B,vec_traits<A>::dim>::type R;
    R r;
    write_vec_element<0>(r,vec_traits<A>::template read_element<0>(a)/b);
    write_vec_element<1>(r,vec_traits<A>::template read_element<1>(a)/b);
    return r;
    }

namespace
sfinae
    {
    using ::zr_boost_1_81::qvm::operator/;
    }

namespace
qvm_detail
    {
    template <int D>
    struct div_vs_defined;

    template <>
    struct
    div_vs_defined<2>
        {
        static bool const value=true;
        };
    }

template <class A,class  B>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_OPERATIONS
typename enable_if_c<
    vec_traits<A>::dim==2 && is_scalar<B>::value,
    A &>::type
operator/=( A & a, B b )
    {
    write_vec_element<0>(a, vec_traits<A>::template read_element<0>(a)/b);
    write_vec_element<1>(a, vec_traits<A>::template read_element<1>(a)/b);
    return a;
    }

namespace
sfinae
    {
    using ::zr_boost_1_81::qvm::operator/=;
    }

namespace
qvm_detail
    {
    template <int D>
    struct div_eq_vs_defined;

    template <>
    struct
    div_eq_vs_defined<2>
        {
        static bool const value=true;
        };
    }

template <class R,class A>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_OPERATIONS
typename enable_if_c<
    is_vec<A>::value &&
    vec_traits<R>::dim==2 && vec_traits<A>::dim==2,
    R>::type
convert_to( A const & a )
    {
    R r;
    write_vec_element<0>(r,vec_traits<A>::template read_element<0>(a));
    write_vec_element<1>(r,vec_traits<A>::template read_element<1>(a));
    return r;
    }

namespace
sfinae
    {
    using ::zr_boost_1_81::qvm::convert_to;
    }

namespace
qvm_detail
    {
    template <int D>
    struct convert_to_v_defined;

    template <>
    struct
    convert_to_v_defined<2>
        {
        static bool const value=true;
        };
    }

template <class A,class B>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_OPERATIONS
typename enable_if_c<
    vec_traits<A>::dim==2 && vec_traits<B>::dim==2,
bool>::type
operator==( A const & a, B const & b )
    {
    return
        vec_traits<A>::template read_element<0>(a)==vec_traits<B>::template read_element<0>(b) &&
        vec_traits<A>::template read_element<1>(a)==vec_traits<B>::template read_element<1>(b);
    }

namespace
sfinae
    {
    using ::zr_boost_1_81::qvm::operator==;
    }

namespace
qvm_detail
    {
    template <int D>
    struct eq_vv_defined;

    template <>
    struct
    eq_vv_defined<2>
        {
        static bool const value=true;
        };
    }

template <class A,class B>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_OPERATIONS
typename enable_if_c<
    vec_traits<A>::dim==2 && vec_traits<B>::dim==2,
bool>::type
operator!=( A const & a, B const & b )
    {
    return
        !(vec_traits<A>::template read_element<0>(a)==vec_traits<B>::template read_element<0>(b)) ||
        !(vec_traits<A>::template read_element<1>(a)==vec_traits<B>::template read_element<1>(b));
    }

namespace
sfinae
    {
    using ::zr_boost_1_81::qvm::operator!=;
    }

namespace
qvm_detail
    {
    template <int D>
    struct neq_vv_defined;

    template <>
    struct
    neq_vv_defined<2>
        {
        static bool const value=true;
        };
    }

template <class A>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_OPERATIONS
typename lazy_enable_if_c<
    vec_traits<A>::dim==2,
    deduce_vec<A> >::type
operator-( A const & a )
    {
    typedef typename deduce_vec<A>::type R;
    R r;
    write_vec_element<0>(r,-vec_traits<A>::template read_element<0>(a));
    write_vec_element<1>(r,-vec_traits<A>::template read_element<1>(a));
    return r;
    }

namespace
sfinae
    {
    using ::zr_boost_1_81::qvm::operator-;
    }

namespace
qvm_detail
    {
    template <int D>
    struct minus_v_defined;

    template <>
    struct
    minus_v_defined<2>
        {
        static bool const value=true;
        };
    }

template <class A>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_OPERATIONS
typename enable_if_c<
    is_vec<A>::value && vec_traits<A>::dim==2,
    typename vec_traits<A>::scalar_type>::type
mag( A const & a )
    {
    typedef typename vec_traits<A>::scalar_type T;
    T const a0=vec_traits<A>::template read_element<0>(a);
    T const a1=vec_traits<A>::template read_element<1>(a);
    T const m2=a0*a0+a1*a1;
    T const mag=sqrt(m2);
    return mag;
    }

namespace
sfinae
    {
    using ::zr_boost_1_81::qvm::mag;
    }

namespace
qvm_detail
    {
    template <int D>
    struct mag_v_defined;

    template <>
    struct
    mag_v_defined<2>
        {
        static bool const value=true;
        };
    }

template <class A>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_OPERATIONS
typename enable_if_c<
    is_vec<A>::value && vec_traits<A>::dim==2,
    typename vec_traits<A>::scalar_type>::type
mag_sqr( A const & a )
    {
    typedef typename vec_traits<A>::scalar_type T;
    T const a0=vec_traits<A>::template read_element<0>(a);
    T const a1=vec_traits<A>::template read_element<1>(a);
    T const m2=a0*a0+a1*a1;
    return m2;
    }

namespace
sfinae
    {
    using ::zr_boost_1_81::qvm::mag_sqr;
    }

namespace
qvm_detail
    {
    template <int D>
    struct mag_sqr_v_defined;

    template <>
    struct
    mag_sqr_v_defined<2>
        {
        static bool const value=true;
        };
    }

template <class A>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_OPERATIONS
typename lazy_enable_if_c<
    vec_traits<A>::dim==2,
    deduce_vec<A> >::type
normalized( A const & a )
    {
    typedef typename vec_traits<A>::scalar_type T;
    T const a0=vec_traits<A>::template read_element<0>(a);
    T const a1=vec_traits<A>::template read_element<1>(a);
    T const m2=a0*a0+a1*a1;
    if( m2==scalar_traits<typename vec_traits<A>::scalar_type>::value(0) )
        BOOST_QVM_THROW_EXCEPTION(zero_magnitude_error());
    T const rm=scalar_traits<T>::value(1)/sqrt(m2);
    typedef typename deduce_vec<A>::type R;
    R r;
    write_vec_element<0>(r,a0*rm);
    write_vec_element<1>(r,a1*rm);
    return r;
    }

namespace
sfinae
    {
    using ::zr_boost_1_81::qvm::normalized;
    }

template <class A>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_OPERATIONS
typename enable_if_c<
    vec_traits<A>::dim==2,
    void>::type
normalize( A & a )
    {
    typedef typename vec_traits<A>::scalar_type T;
    T const a0=vec_traits<A>::template read_element<0>(a);
    T const a1=vec_traits<A>::template read_element<1>(a);
    T const m2=a0*a0+a1*a1;
    if( m2==scalar_traits<typename vec_traits<A>::scalar_type>::value(0) )
        BOOST_QVM_THROW_EXCEPTION(zero_magnitude_error());
    T const rm=scalar_traits<T>::value(1)/sqrt(m2);
    write_vec_element<0>(a,vec_traits<A>::template read_element<0>(a)*rm);
    write_vec_element<1>(a,vec_traits<A>::template read_element<1>(a)*rm);
    }

namespace
sfinae
    {
    using ::zr_boost_1_81::qvm::normalize;
    }

namespace
qvm_detail
    {
    template <int D>
    struct normalize_v_defined;

    template <>
    struct
    normalize_v_defined<2>
        {
        static bool const value=true;
        };
    }

template <class A,class B>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_OPERATIONS
typename lazy_enable_if_c<
    vec_traits<A>::dim==2 && vec_traits<B>::dim==2,
    deduce_scalar<typename vec_traits<A>::scalar_type,typename vec_traits<B>::scalar_type> >::type
dot( A const & a, B const & b )
    {
    typedef typename vec_traits<A>::scalar_type Ta;
    typedef typename vec_traits<B>::scalar_type Tb;
    typedef typename deduce_scalar<Ta,Tb>::type Tr;
    Ta const a0=vec_traits<A>::template read_element<0>(a);
    Ta const a1=vec_traits<A>::template read_element<1>(a);
    Tb const b0=vec_traits<B>::template read_element<0>(b);
    Tb const b1=vec_traits<B>::template read_element<1>(b);
    Tr const dot=a0*b0+a1*b1;
    return dot;
    }

namespace
sfinae
    {
    using ::zr_boost_1_81::qvm::dot;
    }

namespace
qvm_detail
    {
    template <int D>
    struct dot_vv_defined;

    template <>
    struct
    dot_vv_defined<2>
        {
        static bool const value=true;
        };
    }

} }

#endif
