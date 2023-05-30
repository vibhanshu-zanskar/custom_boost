// Boost.TypeErasure library
//
// Copyright 2011-2012 Steven Watanabe
//
// Distributed under the Boost Software License Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// $Id$

#if !defined(BOOST_PP_IS_ITERATING)

#ifndef BOOST_TYPE_ERASURE_REQUIRE_MATCH_HPP_INCLUDED
#define BOOST_TYPE_ERASURE_REQUIRE_MATCH_HPP_INCLUDED

#include <boost/throw_exception.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/and.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/facilities/intercept.hpp>
#include <boost/preprocessor/iteration/iterate.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_trailing_params.hpp>
#include <boost/preprocessor/repetition/enum_trailing_binary_params.hpp>
#include <boost/type_erasure/detail/extract_concept.hpp>
#include <boost/type_erasure/relaxed.hpp>
#include <boost/type_erasure/check_match.hpp>
#include <boost/type_erasure/exception.hpp>

namespace zr_boost_1_81 {
namespace type_erasure {

#ifndef BOOST_TYPE_ERASURE_DOXYGEN
template<class Concept>
class binding;
#endif

#ifdef BOOST_TYPE_ERASURE_DOXYGEN

/**
 * Checks that the actual types stored in all the @ref any
 * arguments match the types specified by @c binding.  If
 * they do not match then,
 * - If @ref relaxed is in @c Concept, throws @ref bad_function_call.
 * - Otherwise the behavior is undefined.
 *
 * If @c binding is not specified, it will be deduced from
 * the arguments.
 *
 * \post \call<code>(binding, f, args...)</code> is valid.
 */
template<class Concept, class Op, class... U>
void require_match(const binding<Concept>& binding_arg, const Op& f, U&&... args);

/**
 * \overload
 */
template<class Op, class... U>
void require_match(const Op& f, U&&... args);

#else

#if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES) && !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)

namespace detail {

template<class Concept, class Op, class... U>
void require_match_impl(
    ::zr_boost_1_81::mpl::true_,
    const ::zr_boost_1_81::type_erasure::binding<Concept>& table,
    const Op& op,
    U&&... arg)
{
    if(!::zr_boost_1_81::type_erasure::check_match(table, op, std::forward<U>(arg)...)) {
        BOOST_THROW_EXCEPTION(::zr_boost_1_81::type_erasure::bad_function_call());
    }
}

template<class Concept, class Op, class... U>
void require_match_impl(
    ::zr_boost_1_81::mpl::false_,
    const ::zr_boost_1_81::type_erasure::binding<Concept>&,
    const Op&,
    U&&...)
{}

template<class Op, class... U>
void require_match_impl(
    ::zr_boost_1_81::mpl::true_,
    const Op& op,
    U&&... arg)
{
    if(!::zr_boost_1_81::type_erasure::check_match(op, ::std::forward<U>(arg)...)) {
        BOOST_THROW_EXCEPTION(::zr_boost_1_81::type_erasure::bad_function_call());
    }
}

template<class Op, class... U>
void require_match_impl(
    ::zr_boost_1_81::mpl::false_,
    const Op&,
    U&&...)
{}

}

template<class Concept, class Op, class... U>
void require_match(
    const ::zr_boost_1_81::type_erasure::binding<Concept>& table,
    const Op& op,
    U&&... arg)
{
    ::zr_boost_1_81::type_erasure::is_relaxed<Concept> cond;
    ::zr_boost_1_81::type_erasure::detail::require_match_impl(cond, table, op, ::std::forward<U>(arg)...);
}

#ifndef BOOST_TYPE_ERASURE_USE_MP11

template<class Op, class... U>
void require_match(
    const Op& op,
    U&&... arg)
{
    ::zr_boost_1_81::type_erasure::is_relaxed<
        typename ::zr_boost_1_81::type_erasure::detail::extract_concept<
            typename ::zr_boost_1_81::type_erasure::detail::get_signature<Op>::type,
            U...>::type
    > cond;
    ::zr_boost_1_81::type_erasure::detail::require_match_impl(cond, op, ::std::forward<U>(arg)...);
}

#else

template<class Op, class... U>
void require_match(
    const Op& op,
    U&&... arg)
{
    ::zr_boost_1_81::type_erasure::is_relaxed<
        ::zr_boost_1_81::type_erasure::detail::extract_concept_t<
            ::zr_boost_1_81::type_erasure::detail::get_args_t<
                typename ::zr_boost_1_81::type_erasure::detail::get_signature<Op>::type
            >,
            ::zr_boost_1_81::mp11::mp_list< ::zr_boost_1_81::remove_reference_t<U>...> >
    > cond;
    ::zr_boost_1_81::type_erasure::detail::require_match_impl(cond, op, ::std::forward<U>(arg)...);
}

#endif

#else

#define BOOST_PP_FILENAME_1 <boost/type_erasure/require_match.hpp>
#define BOOST_PP_ITERATION_LIMITS (0, BOOST_TYPE_ERASURE_MAX_ARITY)
#include BOOST_PP_ITERATE()

#endif

#endif

}
}

#endif

#else

#define N BOOST_PP_ITERATION()

#ifdef BOOST_NO_CXX11_RVALUE_REFERENCES
#define RREF &
#define BOOST_TYPE_ERASURE_FORWARD_ARGS(N, X, x) BOOST_PP_ENUM_TRAILING_PARAMS(N, x)
#else
#define RREF &&
#define BOOST_TYPE_ERASURE_FORWARD_ARGS_I(z, n, data) std::forward<BOOST_PP_CAT(BOOST_PP_TUPLE_ELEM(2, 0, data), n)>(BOOST_PP_CAT(BOOST_PP_TUPLE_ELEM(2, 1, data), n))
#define BOOST_TYPE_ERASURE_FORWARD_ARGS(N, X, x) BOOST_PP_ENUM_TRAILING(N, BOOST_TYPE_ERASURE_FORWARD_ARGS_I, (X, x))
#endif

namespace detail {

template<
    class Concept,
    class Op
    BOOST_PP_ENUM_TRAILING_PARAMS(N, class U)
>
void require_match_impl(
    ::zr_boost_1_81::mpl::true_,
    const ::zr_boost_1_81::type_erasure::binding<Concept>& table,
    const Op& op
    BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(N, U, RREF arg))
{
    if(!::zr_boost_1_81::type_erasure::check_match
        (table, op BOOST_TYPE_ERASURE_FORWARD_ARGS(N, U, arg))) {
        BOOST_THROW_EXCEPTION(::zr_boost_1_81::type_erasure::bad_function_call());
    }
}

template<
    class Concept,
    class Op
    BOOST_PP_ENUM_TRAILING_PARAMS(N, class U)
>
void require_match_impl(
    ::zr_boost_1_81::mpl::false_,
    const ::zr_boost_1_81::type_erasure::binding<Concept>&,
    const Op&
    BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(N, U, RREF BOOST_PP_INTERCEPT))
{}

#if N != 0

template<
    class Op
    BOOST_PP_ENUM_TRAILING_PARAMS(N, class U)
>
void require_match_impl(
    ::zr_boost_1_81::mpl::true_,
    const Op& op
    BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(N, U, RREF arg))
{
    if(!::zr_boost_1_81::type_erasure::check_match
        (op BOOST_TYPE_ERASURE_FORWARD_ARGS(N, U, arg))) {
        BOOST_THROW_EXCEPTION(::zr_boost_1_81::type_erasure::bad_function_call());
    }
}

template<
    class Op
    BOOST_PP_ENUM_TRAILING_PARAMS(N, class U)
>
void require_match_impl(
    ::zr_boost_1_81::mpl::false_,
    const Op&
    BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(N, U, RREF BOOST_PP_INTERCEPT))
{}

#endif

}

template<
    class Concept,
    class Op
    BOOST_PP_ENUM_TRAILING_PARAMS(N, class U)
>
void require_match(
    const ::zr_boost_1_81::type_erasure::binding<Concept>& table,
    const Op& op
    BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(N, U, RREF arg))
{
    ::zr_boost_1_81::type_erasure::is_relaxed<Concept> cond;
    ::zr_boost_1_81::type_erasure::detail::require_match_impl
        (cond, table, op BOOST_TYPE_ERASURE_FORWARD_ARGS(N, U, arg));
}

#if N != 0

template<
    class Op
    BOOST_PP_ENUM_TRAILING_PARAMS(N, class U)
>
void require_match(
    const Op& op
    BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(N, U, RREF arg))
{
    ::zr_boost_1_81::type_erasure::is_relaxed<
        typename ::zr_boost_1_81::type_erasure::detail::BOOST_PP_CAT(do_extract_concept, N)<
        typename ::zr_boost_1_81::type_erasure::detail::get_signature<Op>::type,
        BOOST_PP_ENUM_PARAMS(N, U)>::type
    > cond;
    ::zr_boost_1_81::type_erasure::detail::require_match_impl
        (cond, op BOOST_TYPE_ERASURE_FORWARD_ARGS(N, U, arg));
}

#endif
    
#undef RREF
#undef BOOST_TYPE_ERASURE_FORWARD_ARGS
#undef BOOST_TYPE_ERASURE_FORWARD_ARGS_I
#undef N

#endif
