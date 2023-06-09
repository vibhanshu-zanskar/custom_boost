// (C) Copyright 2006 Douglas Gregor <doug.gregor -at- gmail.com>

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  Authors: Douglas Gregor
#ifndef BOOST_MPI_PYTHON_UTILITY_HPP
#define BOOST_MPI_PYTHON_UTILITY_HPP

/** @file utility.hpp
 *
 *  This file is a utility header for the Boost.MPI Python bindings.
 */
#include <boost/python.hpp>

namespace zr_boost_1_81 { namespace mpi { namespace python {

template<typename E>
class translate_exception
{
  explicit translate_exception(zr_boost_1_81::python::object type) : type(type) { }

public:
  static void declare(zr_boost_1_81::python::object type)
  {
    using zr_boost_1_81::python::register_exception_translator;
    register_exception_translator<E>(translate_exception(type));
  }

  void operator()(const E& e) const
  {
    using zr_boost_1_81::python::object;
    PyErr_SetObject(type.ptr(), object(e).ptr());
  }

private:
  zr_boost_1_81::python::object type;
};

} } } // end namespace zr_boost_1_81::mpi::python

#endif // BOOST_MPI_PYTHON_UTILITY_HPP
