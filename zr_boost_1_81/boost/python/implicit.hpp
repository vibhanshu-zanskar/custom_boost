// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#ifndef IMPLICIT_DWA2002325_HPP
# define IMPLICIT_DWA2002325_HPP

# include <boost/python/detail/prefix.hpp>
# include <boost/type.hpp>
# include <boost/python/converter/implicit.hpp>
# include <boost/python/converter/registry.hpp>
#ifndef BOOST_PYTHON_NO_PY_SIGNATURES
# include <boost/python/converter/pytype_function.hpp>
#endif
# include <boost/python/type_id.hpp>

namespace zr_boost_1_81 { namespace python { 

template <class Source, class Target>
void implicitly_convertible(zr_boost_1_81::type<Source>* = 0, zr_boost_1_81::type<Target>* = 0)
{
    typedef converter::implicit<Source,Target> functions;
    
    converter::registry::push_back(
          &functions::convertible
        , &functions::construct
        , type_id<Target>()
#ifndef BOOST_PYTHON_NO_PY_SIGNATURES
        , &converter::expected_from_python_type_direct<Source>::get_pytype
#endif
        );
}

}} // namespace zr_boost_1_81::python

#endif // IMPLICIT_DWA2002325_HPP
