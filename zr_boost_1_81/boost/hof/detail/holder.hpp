/*=============================================================================
    Copyright (c) 2014 Paul Fultz II
    holder.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_HOF_GUARD_HOLDER_H
#define BOOST_HOF_GUARD_HOLDER_H

namespace zr_boost_1_81 { namespace hof { namespace detail {

template<class... Ts>
struct holder
{
    typedef void type;
};

template<template<class...> class T>
struct template_holder
{
    typedef void type;
};

}}} // namespace zr_boost_1_81::hof

#endif
