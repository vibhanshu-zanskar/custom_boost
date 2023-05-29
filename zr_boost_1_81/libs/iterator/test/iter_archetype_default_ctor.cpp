//
// Copyright Thomas Witt 2004.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <boost/iterator/iterator_archetypes.hpp>


int main()
{
  typedef zr_boost_1_81::iterator_archetype<
      int
    , zr_boost_1_81::iterator_archetypes::readable_iterator_t
    , zr_boost_1_81::single_pass_traversal_tag
    > iter;

  // single_pass_traversal iterators are not required to be
  // default constructible
  iter it;
}
