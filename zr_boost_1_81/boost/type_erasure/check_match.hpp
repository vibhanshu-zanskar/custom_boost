// Boost.TypeErasure library
//
// Copyright 2011 Steven Watanabe
//
// Distributed under the Boost Software License Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// $Id$

#if !defined(BOOST_PP_IS_ITERATING)

#ifndef BOOST_TYPE_ERASURE_CHECK_MATCH_HPP_INCLUDED
#define BOOST_TYPE_ERASURE_CHECK_MATCH_HPP_INCLUDED

#include <boost/mpl/vector.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/find_if.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/end.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/iteration/iterate.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_trailing_params.hpp>
#include <boost/preprocessor/repetition/enum_trailing_binary_params.hpp>
#include <boost/type_erasure/detail/extract_concept.hpp>
#include <boost/type_erasure/relaxed.hpp>
#include <boost/type_erasure/detail/access.hpp>

namespace zr_boost_1_81 {
namespace type_erasure {

#ifndef BOOST_TYPE_ERASURE_DOXYGEN

template<class T>
struct typeid_;

template<class Concept>
class binding;

#endif

namespace detail {

template<class P, class T, class Table>
bool maybe_check_table(const T& arg, const Table*& table, zr_boost_1_81::mpl::true_)
{
    if(table == 0) {
        table = &::zr_boost_1_81::type_erasure::detail::access::table(arg);
        return true;
    } else {
        return table->template find< ::zr_boost_1_81::type_erasure::typeid_<P> >()() ==
            ::zr_boost_1_81::type_erasure::detail::access::table(arg).
                template find< ::zr_boost_1_81::type_erasure::typeid_<P> >()();
    }
}

template<class P, class T, class Table>
bool maybe_check_table(const T&, const Table*&, zr_boost_1_81::mpl::false_)
{
    return true;
}

template<class Concept, class T>
struct should_check :
    zr_boost_1_81::mpl::and_<
        ::zr_boost_1_81::type_erasure::is_placeholder<T>,
        ::zr_boost_1_81::type_erasure::is_relaxed<Concept>
    >
{};

}

#ifdef BOOST_TYPE_ERASURE_DOXYGEN

/**
 * If @ref relaxed is in @c Concept, checks whether the
 * arguments to @c f match the types specified by
 * @c binding.  If @ref relaxed is not in @c Concept,
 * returns true.  If @c binding is not specified, it will
 * be deduced from the arguments.
 */
template<class Concept, class Op, class... U>
bool check_match(const binding<Concept>& binding_arg, const Op& f, U&&... args);

/**
 * \overload
 */
template<class Op, class... U>
bool check_match(const Op& f, U&&... args);

#else

#if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES) && !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)

namespace detail {

template<class Concept, class R>
bool check_table(const ::zr_boost_1_81::type_erasure::binding<Concept>* /*t*/, R(*)())
{
    return true;
}

template<class Concept, class R, class T0, class... T, class U0, class... U>
bool check_table(
    const ::zr_boost_1_81::type_erasure::binding<Concept>* t,
    R(*)(T0, T...),
    const U0& arg0,
    const U&... arg)
{
    typedef typename ::zr_boost_1_81::remove_cv<
        typename ::zr_boost_1_81::remove_reference<T0>::type
    >::type t0;
    if(!::zr_boost_1_81::type_erasure::detail::maybe_check_table<t0>(
        arg0,
        t,
        ::zr_boost_1_81::type_erasure::detail::should_check<Concept, t0>()))
        return false;

    return check_table(t, static_cast<void(*)(T...)>(0), arg...);
}

}

template<class Concept, class Op, class... U>
bool check_match(
    const ::zr_boost_1_81::type_erasure::binding<Concept>& table,
    const Op&,
    U&&... arg)
{

    return ::zr_boost_1_81::type_erasure::detail::check_table(
        &table,
        static_cast<typename ::zr_boost_1_81::type_erasure::detail::get_signature<Op>::type*>(0),
        arg...);
}

#ifndef BOOST_TYPE_ERASURE_USE_MP11

template<
    class Op,
    class... U
>
bool check_match(
    const Op&,
    U&&... arg)
{
    const ::zr_boost_1_81::type_erasure::binding<
        typename ::zr_boost_1_81::type_erasure::detail::extract_concept<
            typename ::zr_boost_1_81::type_erasure::detail::get_signature<Op>::type, U...>::type>* p = 0;

    return ::zr_boost_1_81::type_erasure::detail::check_table(
        p, static_cast<typename ::zr_boost_1_81::type_erasure::detail::get_signature<Op>::type*>(0), arg...);
}

#else

namespace detail {

template<class T>
struct get_args;

template<class R, class ... T>
struct get_args<R(T...)> { typedef ::zr_boost_1_81::mp11::mp_list<T...> type; };

template<class Sig>
using get_args_t = typename get_args<Sig>::type;

}

template<
    class Op,
    class... U
>
bool check_match(
    const Op&,
    U&&... arg)
{
    const ::zr_boost_1_81::type_erasure::binding<
        ::zr_boost_1_81::type_erasure::detail::extract_concept_t<
            ::zr_boost_1_81::type_erasure::detail::get_args_t<
                typename ::zr_boost_1_81::type_erasure::detail::get_signature<Op>::type
            >,
            ::zr_boost_1_81::mp11::mp_list< ::zr_boost_1_81::remove_reference_t<U>...> > >* p = 0;

    return ::zr_boost_1_81::type_erasure::detail::check_table(
        p, static_cast<typename ::zr_boost_1_81::type_erasure::detail::get_signature<Op>::type*>(0), arg...);
}

#endif

#else

#define BOOST_PP_FILENAME_1 <boost/type_erasure/check_match.hpp>
#define BOOST_PP_ITERATION_LIMITS (0, BOOST_TYPE_ERASURE_MAX_ARITY)
#include BOOST_PP_ITERATE()

#endif

#endif

}
}

#endif

#else

namespace detail {

#define N BOOST_PP_ITERATION()

#define BOOST_TYPE_ERASURE_CHECK_TABLE(z, n, data)                          \
    typedef typename ::zr_boost_1_81::remove_cv<                                    \
        typename ::zr_boost_1_81::remove_reference<BOOST_PP_CAT(T, n)>::type        \
    >::type BOOST_PP_CAT(t, n);                                             \
    if(!::zr_boost_1_81::type_erasure::detail::maybe_check_table<BOOST_PP_CAT(t, n)>(   \
        BOOST_PP_CAT(arg, n),                                               \
        t,                                                                  \
        ::zr_boost_1_81::type_erasure::detail::should_check<Concept, BOOST_PP_CAT(t, n)>())) \
        return false;

template<
    class Concept,
    class R
    BOOST_PP_ENUM_TRAILING_PARAMS(N, class T)
    BOOST_PP_ENUM_TRAILING_PARAMS(N, class U)>
bool
BOOST_PP_CAT(check_table, N)(
    const ::zr_boost_1_81::type_erasure::binding<Concept>* t,
    R (*)(BOOST_PP_ENUM_PARAMS(N, T))
    BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(N, const U, &arg))
{
    BOOST_PP_REPEAT(N, BOOST_TYPE_ERASURE_CHECK_TABLE, ~)
    return true;
}

#if N != 0

template<class Sig BOOST_PP_ENUM_TRAILING_PARAMS(N, class U)>
struct BOOST_PP_CAT(do_extract_concept, N);

template<
    class R
    BOOST_PP_ENUM_TRAILING_PARAMS(N, class T)
    BOOST_PP_ENUM_TRAILING_PARAMS(N, class U)
>
struct BOOST_PP_CAT(do_extract_concept, N)<
    R(BOOST_PP_ENUM_PARAMS(N, T))
    BOOST_PP_ENUM_TRAILING_PARAMS(N, U)
>
  : ::zr_boost_1_81::type_erasure::detail::BOOST_PP_CAT(extract_concept, N)<
        BOOST_PP_ENUM_PARAMS(N, T)
        BOOST_PP_ENUM_TRAILING_PARAMS(N, U)>
{};

#endif

}

#ifdef BOOST_NO_CXX11_RVALUE_REFERENCES
#define RREF &
#else
#define RREF &&
#endif

template<
    class Concept,
    class Op
    BOOST_PP_ENUM_TRAILING_PARAMS(N, class U)
>
bool check_match(
    const ::zr_boost_1_81::type_erasure::binding<Concept>& table,
    const Op&
    BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(N, U, RREF arg))
{

    return ::zr_boost_1_81::type_erasure::detail::BOOST_PP_CAT(check_table, N)(
        &table,
        (typename ::zr_boost_1_81::type_erasure::detail::get_signature<Op>::type*)0
        BOOST_PP_ENUM_TRAILING_PARAMS(N, arg));
}

#if N != 0

template<
    class Op
    BOOST_PP_ENUM_TRAILING_PARAMS(N, class U)
>
bool check_match(
    const Op&
    BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(N, U, RREF arg))
{
    const ::zr_boost_1_81::type_erasure::binding<
        typename ::zr_boost_1_81::type_erasure::detail::BOOST_PP_CAT(do_extract_concept, N)<
            typename ::zr_boost_1_81::type_erasure::detail::get_signature<Op>::type,
            BOOST_PP_ENUM_PARAMS(N, U)>::type>* p = 0;

    return ::zr_boost_1_81::type_erasure::detail::BOOST_PP_CAT(check_table, N)(
        p,
        (typename ::zr_boost_1_81::type_erasure::detail::get_signature<Op>::type*)0
        BOOST_PP_ENUM_TRAILING_PARAMS(N, arg));
}

#undef RREF
#undef BOOST_TYPE_ERASURE_CHECK_TABLE
#undef N

#endif

#endif
