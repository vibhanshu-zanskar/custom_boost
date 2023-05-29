//
// Copyright Thomas Witt 2003.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <boost/iterator/iterator_archetypes.hpp>
#include <boost/iterator/iterator_categories.hpp>
#include <boost/iterator/iterator_concepts.hpp>
#include <boost/concept_check.hpp>
#include <boost/cstdlib.hpp>

int main()
{
  {
    typedef zr_boost_1_81::iterator_archetype<
        int
      , zr_boost_1_81::iterator_archetypes::readable_iterator_t
      , zr_boost_1_81::random_access_traversal_tag
    > iter;

    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ReadableIteratorConcept<iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::RandomAccessTraversalConcept<iter> >();
  }
  {
    typedef zr_boost_1_81::iterator_archetype<
        int
      , zr_boost_1_81::iterator_archetypes::readable_writable_iterator_t
      , zr_boost_1_81::random_access_traversal_tag
    > iter;

    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ReadableIteratorConcept<iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::WritableIteratorConcept<iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::RandomAccessTraversalConcept<iter> >();
  }
  {
    typedef zr_boost_1_81::iterator_archetype<
        const int // I don't like adding const to Value. It is redundant. -JGS
      , zr_boost_1_81::iterator_archetypes::readable_lvalue_iterator_t
      , zr_boost_1_81::random_access_traversal_tag
    > iter;

    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ReadableIteratorConcept<iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::LvalueIteratorConcept<iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::RandomAccessTraversalConcept<iter> >();
  }
  {
    typedef zr_boost_1_81::iterator_archetype<
        int
      , zr_boost_1_81::iterator_archetypes::writable_lvalue_iterator_t
      , zr_boost_1_81::random_access_traversal_tag
    > iter;

    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::WritableIteratorConcept<iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::LvalueIteratorConcept<iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::RandomAccessTraversalConcept<iter> >();
  }

  return zr_boost_1_81::exit_success;
}

