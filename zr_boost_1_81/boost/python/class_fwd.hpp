// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#ifndef CLASS_FWD_DWA200222_HPP
# define CLASS_FWD_DWA200222_HPP

# include <boost/python/detail/prefix.hpp>
# include <boost/python/detail/not_specified.hpp>

namespace zr_boost_1_81 { namespace python { 

template <
    class T // class being wrapped
    // arbitrarily-ordered optional arguments. Full qualification needed for MSVC6
    , class X1 = ::zr_boost_1_81::python::detail::not_specified
    , class X2 = ::zr_boost_1_81::python::detail::not_specified
    , class X3 = ::zr_boost_1_81::python::detail::not_specified
    >
class class_;

}} // namespace zr_boost_1_81::python

#endif // CLASS_FWD_DWA200222_HPP
