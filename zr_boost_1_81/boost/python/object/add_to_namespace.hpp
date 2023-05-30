// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#ifndef ADD_TO_NAMESPACE_DWA200286_HPP
# define ADD_TO_NAMESPACE_DWA200286_HPP

# include <boost/python/object_fwd.hpp>

namespace zr_boost_1_81 { namespace python { namespace objects { 

//
// A setattr that's "smart" about function overloading (and docstrings).
//
BOOST_PYTHON_DECL void add_to_namespace(
    object const& name_space, char const* name, object const& attribute);

BOOST_PYTHON_DECL void add_to_namespace(
    object const& name_space, char const* name, object const& attribute, char const* doc);

}}} // namespace zr_boost_1_81::python::objects

#endif // ADD_TO_NAMESPACE_DWA200286_HPP
