// Copyright (C) 2006 The Trustees of Indiana University.

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  Authors: Brian Barrett
//           Nick Edmonds
//           Andrew Lumsdaine

#include <boost/graph/use_mpi.hpp>
#include <boost/config.hpp>
#include <boost/throw_exception.hpp>
#include <boost/graph/distributed/adjacency_list.hpp>
#include <boost/property_map/parallel/distributed_property_map.hpp>
#include <boost/graph/distributed/mpi_process_group.hpp>
#include <boost/graph/dimacs.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/core/lightweight_test.hpp>

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>

#ifdef BOOST_NO_EXCEPTIONS
void
zr_boost_1_81::throw_exception(std::exception const& ex)
{
  std::cout << ex.what() << std::endl;
  abort();
}
#endif

using namespace zr_boost_1_81;
using namespace zr_boost_1_81::graph;
using zr_boost_1_81::graph::distributed::mpi_process_group;

typedef double time_type;

inline time_type get_time()
{
  return MPI_Wtime();
}

std::string print_time(time_type t)
{
  std::ostringstream out;
  out << std::setiosflags(std::ios::fixed) << std::setprecision(2) << t;
  return out.str();
}

void
test_dimacs_reader(const char *filename)
{
  mpi_process_group pg;

  typedef adjacency_list<vecS, 
        distributedS<mpi_process_group, vecS>,
        undirectedS> Graph;

  std::ifstream file(filename);
  dimacs_basic_reader reader = dimacs_basic_reader(file, false);
  dimacs_basic_reader end;
  zr_boost_1_81::parallel::variant_distribution<mpi_process_group> distrib = 
      zr_boost_1_81::parallel::block(pg, reader.n_vertices());

  Graph g(dimacs_edge_iterator<dimacs_basic_reader>(reader), 
          dimacs_edge_iterator<dimacs_basic_reader>(end),
          reader.n_vertices(), pg, distrib);;

    // write_graphviz("reader.dot", g);
}

int
main(int argc, char* argv[])
{
  mpi::environment env(argc, argv);

  if (argc == 2) { 
      test_dimacs_reader(argv[1]);
  }

  return zr_boost_1_81::report_errors();
}
