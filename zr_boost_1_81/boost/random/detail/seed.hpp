/* boost random/detail/seed.hpp header file
 *
 * Copyright Steven Watanabe 2009
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org for most recent version including documentation.
 *
 * $Id$
 */

#ifndef BOOST_RANDOM_DETAIL_SEED_HPP
#define BOOST_RANDOM_DETAIL_SEED_HPP

#include <boost/config.hpp>

// Sun seems to have trouble with the use of SFINAE for the
// templated constructor.  So does Borland.
#if !defined(BOOST_NO_SFINAE) && !defined(__SUNPRO_CC) && !defined(BOOST_BORLANDC)

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_arithmetic.hpp>

namespace zr_boost_1_81 {
namespace random {
namespace detail {

template<class T>
struct disable_seed : zr_boost_1_81::disable_if<zr_boost_1_81::is_arithmetic<T> > {};

template<class Engine, class T>
struct disable_constructor : disable_seed<T> {};

template<class Engine>
struct disable_constructor<Engine, Engine> {};

#define BOOST_RANDOM_DETAIL_GENERATOR_CONSTRUCTOR(Self, Generator, gen) \
    template<class Generator>                                           \
    explicit Self(Generator& gen, typename ::zr_boost_1_81::random::detail::disable_constructor<Self, Generator>::type* = 0)

#define BOOST_RANDOM_DETAIL_GENERATOR_SEED(Self, Generator, gen)    \
    template<class Generator>                                       \
    void seed(Generator& gen, typename ::zr_boost_1_81::random::detail::disable_seed<Generator>::type* = 0)

#define BOOST_RANDOM_DETAIL_SEED_SEQ_CONSTRUCTOR(Self, SeedSeq, seq)    \
    template<class SeedSeq>                                             \
    explicit Self(SeedSeq& seq, typename ::zr_boost_1_81::random::detail::disable_constructor<Self, SeedSeq>::type* = 0)

#define BOOST_RANDOM_DETAIL_SEED_SEQ_SEED(Self, SeedSeq, seq)   \
    template<class SeedSeq>                                     \
    void seed(SeedSeq& seq, typename ::zr_boost_1_81::random::detail::disable_seed<SeedSeq>::type* = 0)

#define BOOST_RANDOM_DETAIL_ARITHMETIC_CONSTRUCTOR(Self, T, x)  \
    explicit Self(const T& x)

#define BOOST_RANDOM_DETAIL_ARITHMETIC_SEED(Self, T, x) \
    void seed(const T& x)
}
}
}

#else

#include <boost/type_traits/is_arithmetic.hpp>

#define BOOST_RANDOM_DETAIL_GENERATOR_CONSTRUCTOR(Self, Generator, gen) \
    Self(Self& other) { *this = other; }                                \
    Self(const Self& other) { *this = other; }                          \
    template<class Generator>                                           \
    explicit Self(Generator& gen) {                                     \
        boost_random_constructor_impl(gen, ::zr_boost_1_81::is_arithmetic<Generator>());\
    }                                                                   \
    template<class Generator>                                           \
    void boost_random_constructor_impl(Generator& gen, ::zr_boost_1_81::false_type)

#define BOOST_RANDOM_DETAIL_GENERATOR_SEED(Self, Generator, gen)    \
    template<class Generator>                                       \
    void seed(Generator& gen) {                                     \
        boost_random_seed_impl(gen, ::zr_boost_1_81::is_arithmetic<Generator>());\
    }\
    template<class Generator>\
    void boost_random_seed_impl(Generator& gen, ::zr_boost_1_81::false_type)

#define BOOST_RANDOM_DETAIL_SEED_SEQ_CONSTRUCTOR(Self, SeedSeq, seq)    \
    Self(Self& other) { *this = other; }                                \
    Self(const Self& other) { *this = other; }                          \
    template<class SeedSeq>                                             \
    explicit Self(SeedSeq& seq) {                                       \
        boost_random_constructor_impl(seq, ::zr_boost_1_81::is_arithmetic<SeedSeq>());\
    }                                                                   \
    template<class SeedSeq>                                             \
    void boost_random_constructor_impl(SeedSeq& seq, ::zr_boost_1_81::false_type)

#define BOOST_RANDOM_DETAIL_SEED_SEQ_SEED(Self, SeedSeq, seq)           \
    template<class SeedSeq>                                             \
    void seed(SeedSeq& seq) {                                           \
        boost_random_seed_impl(seq, ::zr_boost_1_81::is_arithmetic<SeedSeq>()); \
    }                                                                   \
    template<class SeedSeq>                                             \
    void boost_random_seed_impl(SeedSeq& seq, ::zr_boost_1_81::false_type)

#define BOOST_RANDOM_DETAIL_ARITHMETIC_CONSTRUCTOR(Self, T, x)  \
    explicit Self(const T& x) { boost_random_constructor_impl(x, ::zr_boost_1_81::true_type()); }\
    void boost_random_constructor_impl(const T& x, ::zr_boost_1_81::true_type)

#define BOOST_RANDOM_DETAIL_ARITHMETIC_SEED(Self, T, x) \
    void seed(const T& x) { boost_random_seed_impl(x, ::zr_boost_1_81::true_type()); }\
    void boost_random_seed_impl(const T& x, ::zr_boost_1_81::true_type)

#endif

#endif
