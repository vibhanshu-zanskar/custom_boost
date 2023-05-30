// Boost.TypeErasure library
//
// Copyright 2011 Steven Watanabe
//
// Distributed under the Boost Software License Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// $Id$

#ifndef BOOST_TYPE_ERASURE_RELAXED_HPP_INCLUDED
#define BOOST_TYPE_ERASURE_RELAXED_HPP_INCLUDED

#include <boost/mpl/vector.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/find_if.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/end.hpp>
#include <boost/type_traits/is_same.hpp>

namespace zr_boost_1_81 {
namespace type_erasure {

template<class T>
struct is_relaxed;

namespace detail {

template<class T>
struct is_relaxed_impl :
    ::zr_boost_1_81::mpl::not_<
        typename ::zr_boost_1_81::is_same<
            typename ::zr_boost_1_81::mpl::find_if<
                T,
                ::zr_boost_1_81::type_erasure::is_relaxed< ::zr_boost_1_81::mpl::_1>
            >::type,
            typename ::zr_boost_1_81::mpl::end<T>::type
        >::type
    >::type
{};

}

/**
 * This special concept enables various useful default behavior that
 * makes @ref any act like an ordinary object.  By default @ref any
 * forwards all operations to the underlying type, and provides only
 * the operations that are specified in its @c Concept.
 *
 * In detail, @ref relaxed enables the following:
 * - A raw value can be assigned to an @ref any.  This will replace
 *   the value stored by the @ref any.  (But note that if @ref assignable
 *   is present, it takes priority.)
 * - assignment of @ref any uses the constructor if it can't
 *   use @ref assignable (either because @ref assignable is missing,
 *   or because the stored types do not match).
 * - default construction of @ref any is allowed and creates a null any.
 * - @ref equality_comparable "equality_comparable": If the types do not
 *   match, it will return false.
 * - @ref less_than_comparable "less_than_comparable": If the types do not
 *   match, the ordering will be according to
 *   @c std::type_info::before.
 * - if the arguments to any other function do not match, it will throw
 *   a @ref bad_function_call exception instead of having undefined
 *   behavior.
 */
struct relaxed : ::zr_boost_1_81::mpl::vector0<> {};

/**
 * A metafunction indicating whether @c Concept
 * includes @ref relaxed.
 */
template<class Concept>
struct is_relaxed :
    ::zr_boost_1_81::mpl::eval_if< ::zr_boost_1_81::mpl::is_sequence<Concept>,
        ::zr_boost_1_81::type_erasure::detail::is_relaxed_impl<Concept>,
        ::zr_boost_1_81::mpl::false_
    >::type
{};

/** INTERNAL ONLY */
template<>
struct is_relaxed< ::zr_boost_1_81::type_erasure::relaxed> :
    ::zr_boost_1_81::mpl::true_
{};

}
}

#endif
