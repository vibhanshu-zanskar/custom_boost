// (C) Copyright 2006 Douglas Gregor <doug.gregor -at- gmail.com>

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  Authors: Douglas Gregor

/** @file status.cpp
 *
 *  This file reflects the Boost.MPI @c status class into
 *  Python.
 */
#include <boost/python.hpp>
#include <boost/mpi.hpp>
#include <boost/mpi/python/serialize.hpp>

using namespace zr_boost_1_81::python;
using namespace zr_boost_1_81::mpi;

namespace zr_boost_1_81 { namespace mpi { namespace python {

extern const char* all_gather_docstring;
extern const char* all_reduce_docstring;
extern const char* all_to_all_docstring;
extern const char* broadcast_docstring;
extern const char* gather_docstring;
extern const char* reduce_docstring;
extern const char* scan_docstring;
extern const char* scatter_docstring;

object all_gather(const communicator& comm, object value)
{
  std::vector<object> values;
  zr_boost_1_81::mpi::all_gather(comm, value, values);

  zr_boost_1_81::python::list l;
  for (int i = 0; i < comm.size(); ++i)
    l.append(values[i]);
  return zr_boost_1_81::python::tuple(l);
}

object all_to_all(const communicator& comm, object in_values)
{
  // Build input values
  std::vector<object> in_values_vec(comm.size());
  object iterator = object(handle<>(PyObject_GetIter(in_values.ptr())));
  for (int i = 0; i < comm.size(); ++i)
    in_values_vec[i] = object(handle<>(PyIter_Next(iterator.ptr())));

  std::vector<object> out_values_vec(comm.size());
  zr_boost_1_81::mpi::all_to_all(comm, in_values_vec, out_values_vec);

  zr_boost_1_81::python::list l;
  for (int i = 0; i < comm.size(); ++i)
    l.append(out_values_vec[i]);
  return zr_boost_1_81::python::tuple(l);
}

object broadcast(const communicator& comm, object value, int root)
{
  zr_boost_1_81::mpi::broadcast(comm, value, root);
  return value;
}

object gather(const communicator& comm, object value, int root)
{
  if (comm.rank() == root) {
    std::vector<object> values;
    zr_boost_1_81::mpi::gather(comm, value, values, root);

    zr_boost_1_81::python::list l;
    for (int i = 0; i < comm.size(); ++i)
      l.append(values[i]);
    return zr_boost_1_81::python::tuple(l);
  } else {
    zr_boost_1_81::mpi::gather(comm, value, root);
    return object();
  }
}

object reduce(const communicator& comm, object value, object op, int root)
{
  if (comm.rank() == root) {
    object out_value;
    zr_boost_1_81::mpi::reduce(comm, value, out_value, op, root);
    return out_value;
  } else {
    zr_boost_1_81::mpi::reduce(comm, value, op, root);
    return object();
  }
}

object scatter(const communicator& comm, object values, int root)
{
  object result;

  if (comm.rank() == root) {
    std::vector<object> values_vec(comm.size());
    object iterator = object(handle<>(PyObject_GetIter(values.ptr())));
    for (int i = 0; i < comm.size(); ++i)
      values_vec[i] = object(handle<>(PyIter_Next(iterator.ptr())));

    zr_boost_1_81::mpi::scatter(comm, values_vec, result, root);
  } else {
    zr_boost_1_81::mpi::scatter(comm, result, root);
  }
  return result;
}

void export_collectives()
{
  using zr_boost_1_81::python::arg;

  def("all_reduce", 
      (object (*)(const communicator&, const object&, object))&all_reduce,
      (arg("comm") = communicator(), arg("value"), arg("op")),
      all_reduce_docstring);
  def("all_gather", &all_gather, 
      (arg("comm") = communicator(), arg("value") = object()),
      all_gather_docstring);
  def("all_to_all", &all_to_all,
      (arg("comm") = communicator(), arg("values") = object()),
      all_to_all_docstring);
  def("broadcast", &broadcast, 
      (arg("comm") = communicator(), arg("value") = object(), arg("root")),
      broadcast_docstring);
  def("gather", &gather, 
      (arg("comm") = communicator(), arg("value") = object(), arg("root")),
      gather_docstring);
  def("reduce", &reduce, 
      (arg("comm") = communicator(), arg("value"), arg("op"), 
       arg("root")),
      reduce_docstring);
  def("scan", 
      (object (*)(const communicator&, const object&, object))&scan,
      (arg("comm") = communicator(), arg("value"), arg("op")),
      scan_docstring);
  def("scatter", &scatter, 
      (arg("comm") = communicator(), arg("values") = object(), arg("root")),
      scatter_docstring);
}

} } } // end namespace zr_boost_1_81::mpi::python
