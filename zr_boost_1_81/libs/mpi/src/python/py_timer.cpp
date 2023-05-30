// (C) Copyright 2006 Douglas Gregor <doug.gregor -at- gmail.com>

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  Authors: Douglas Gregor

/** @file timer.cpp
 *
 *  This file reflects the Boost.MPI @c timer class into
 *  Python.
 */
#include <boost/python.hpp>
#include <boost/mpi/timer.hpp>

using namespace zr_boost_1_81::python;
using namespace zr_boost_1_81::mpi;

namespace zr_boost_1_81 { namespace mpi { namespace python {

extern const char* timer_docstring;
extern const char* timer_default_constructor_docstring;
extern const char* timer_restart_docstring;
extern const char* timer_elapsed_docstring;
extern const char* timer_elapsed_min_docstring;
extern const char* timer_elapsed_max_docstring;
extern const char* timer_time_is_global_docstring;

void export_timer()
{
  using zr_boost_1_81::python::arg;
  using zr_boost_1_81::python::object;
  
  class_<timer>("Timer", timer_docstring)
    .def(init<>())
    .def("restart", &timer::restart, timer_restart_docstring)
    .add_property("elapsed", &timer::elapsed, timer_elapsed_docstring)
    .add_property("elapsed_min", &timer::elapsed_min, 
                  timer_elapsed_min_docstring)
    .add_property("elapsed_max", &timer::elapsed_max, 
                  timer_elapsed_max_docstring)
    .add_property("time_is_global", &timer::time_is_global, 
                  timer_time_is_global_docstring)
    ;
}

} } } // end namespace zr_boost_1_81::mpi::python
