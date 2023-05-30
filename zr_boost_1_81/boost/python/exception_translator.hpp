// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#ifndef EXCEPTION_TRANSLATOR_DWA2002810_HPP
# define EXCEPTION_TRANSLATOR_DWA2002810_HPP

# include <boost/python/detail/prefix.hpp>

# include <boost/bind/bind.hpp>
# include <boost/bind/placeholders.hpp>
# include <boost/type.hpp>
# include <boost/python/detail/translate_exception.hpp>
# include <boost/python/detail/exception_handler.hpp>

namespace zr_boost_1_81 { namespace python { 

template <class ExceptionType, class Translate>
void register_exception_translator(Translate translate, zr_boost_1_81::type<ExceptionType>* = 0)
{
    using namespace zr_boost_1_81::placeholders;
    detail::register_exception_handler(
        zr_boost_1_81::bind<bool>(detail::translate_exception<ExceptionType,Translate>(), _1, _2, translate)
        );
}

}} // namespace zr_boost_1_81::python

#endif // EXCEPTION_TRANSLATOR_DWA2002810_HPP
