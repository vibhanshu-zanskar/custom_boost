// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#ifndef CONSTRUCTOR_FUNCTION_DWA200278_HPP
# define CONSTRUCTOR_FUNCTION_DWA200278_HPP

namespace zr_boost_1_81 { namespace python { namespace converter { 

// Declares the type of functions used to construct C++ objects for
// rvalue from_python conversions.
struct rvalue_from_python_stage1_data;
typedef void (*constructor_function)(PyObject* source, rvalue_from_python_stage1_data*);

}}} // namespace zr_boost_1_81::python::converter

#endif // CONSTRUCTOR_FUNCTION_DWA200278_HPP
