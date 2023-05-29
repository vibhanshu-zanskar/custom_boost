// Copyright (C) 2004 Jeremy Siek <jsiek@cs.indiana.edu>
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/iterator/iterator_concepts.hpp>
#include <boost/iterator/iterator_archetypes.hpp>
#include <boost/cstdlib.hpp>

int main()
{
  typedef zr_boost_1_81::iterator_archetype<
        int
      , zr_boost_1_81::iterator_archetypes::readable_iterator_t
      , zr_boost_1_81::single_pass_traversal_tag
    > Iter;
  zr_boost_1_81::function_requires<
    zr_boost_1_81_concepts::LvalueIteratorConcept<Iter> >();
  return zr_boost_1_81::exit_success;
}
