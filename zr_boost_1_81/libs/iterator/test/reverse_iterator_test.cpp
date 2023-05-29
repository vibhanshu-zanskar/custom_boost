// Copyright Thomas Witt 2003, Jeremy Siek 2004.

// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/iterator/reverse_iterator.hpp>
#include <boost/iterator/new_iterator_tests.hpp>
#include <boost/concept_check.hpp>
#include <boost/concept_archetype.hpp>
#include <boost/iterator/iterator_concepts.hpp>
#include <boost/iterator/iterator_archetypes.hpp>
#include <boost/cstdlib.hpp>
#include <algorithm>
#include <deque>
#include <iostream>

using zr_boost_1_81::dummyT;

// Test reverse iterator
int main()
{
  dummyT array[] = { dummyT(0), dummyT(1), dummyT(2),
                     dummyT(3), dummyT(4), dummyT(5) };
  const int N = sizeof(array)/sizeof(dummyT);

  // Concept checks
  // Adapting old-style iterators
  {
    typedef zr_boost_1_81::reverse_iterator<zr_boost_1_81::bidirectional_iterator_archetype<dummyT> > Iter;
    zr_boost_1_81::function_requires< zr_boost_1_81::BidirectionalIteratorConcept<Iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ReadableIteratorConcept<Iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::LvalueIteratorConcept<Iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::BidirectionalTraversalConcept<Iter> >();
  }
  {
    typedef zr_boost_1_81::reverse_iterator<zr_boost_1_81::mutable_bidirectional_iterator_archetype<dummyT> > Iter;
    zr_boost_1_81::function_requires< zr_boost_1_81::Mutable_BidirectionalIteratorConcept<Iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::WritableIteratorConcept<Iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::LvalueIteratorConcept<Iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::BidirectionalTraversalConcept<Iter> >();
  }
  // Adapting new-style iterators
  {
    typedef zr_boost_1_81::iterator_archetype<
        const dummyT
      , zr_boost_1_81::iterator_archetypes::readable_iterator_t
      , zr_boost_1_81::bidirectional_traversal_tag
    > iter;
    typedef zr_boost_1_81::reverse_iterator<iter> Iter;
    zr_boost_1_81::function_requires< zr_boost_1_81::InputIteratorConcept<Iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ReadableIteratorConcept<Iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::BidirectionalTraversalConcept<Iter> >();
  }
#if 0
  // It does not seem feasible to make this work. Need to change docs to
  // require at lease Readable for the base iterator. -Jeremy
  {
    typedef zr_boost_1_81::iterator_archetype<
        dummyT
      , zr_boost_1_81::iterator_archetypes::writable_iterator_t
      , zr_boost_1_81::bidirectional_traversal_tag
    > iter;
    typedef zr_boost_1_81::reverse_iterator<iter> Iter;
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::WritableIteratorConcept<Iter, dummyT> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::BidirectionalTraversalConcept<Iter> >();
  }
#endif
#if !BOOST_WORKAROUND(BOOST_MSVC, == 1200)  // Causes Internal Error in linker.
  {
    typedef zr_boost_1_81::iterator_archetype<
        dummyT
      , zr_boost_1_81::iterator_archetypes::readable_writable_iterator_t
      , zr_boost_1_81::bidirectional_traversal_tag
    > iter;
    typedef zr_boost_1_81::reverse_iterator<iter> Iter;
    zr_boost_1_81::function_requires< zr_boost_1_81::InputIteratorConcept<Iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ReadableIteratorConcept<Iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::WritableIteratorConcept<Iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::BidirectionalTraversalConcept<Iter> >();
  }
  {
    typedef zr_boost_1_81::iterator_archetype<
        const dummyT
      , zr_boost_1_81::iterator_archetypes::readable_lvalue_iterator_t
      , zr_boost_1_81::bidirectional_traversal_tag
    > iter;
    typedef zr_boost_1_81::reverse_iterator<iter> Iter;
    zr_boost_1_81::function_requires< zr_boost_1_81::BidirectionalIteratorConcept<Iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ReadableIteratorConcept<Iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::LvalueIteratorConcept<Iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::BidirectionalTraversalConcept<Iter> >();
  }
  {
    typedef zr_boost_1_81::iterator_archetype<
        dummyT
      , zr_boost_1_81::iterator_archetypes::writable_lvalue_iterator_t
      , zr_boost_1_81::bidirectional_traversal_tag
    > iter;
    typedef zr_boost_1_81::reverse_iterator<iter> Iter;
    zr_boost_1_81::function_requires< zr_boost_1_81::BidirectionalIteratorConcept<Iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::WritableIteratorConcept<Iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::LvalueIteratorConcept<Iter> >();
    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::BidirectionalTraversalConcept<Iter> >();
  }
#endif

  // Test reverse_iterator
  {
    dummyT reversed[N];
    std::copy(array, array + N, reversed);
    std::reverse(reversed, reversed + N);

    typedef zr_boost_1_81::reverse_iterator<dummyT*> reverse_iterator;

    reverse_iterator i(reversed + N);
    zr_boost_1_81::random_access_iterator_test(i, N, array);

    zr_boost_1_81::random_access_iterator_test(zr_boost_1_81::make_reverse_iterator(reversed + N), N, array);

    typedef zr_boost_1_81::reverse_iterator<const dummyT*> const_reverse_iterator;

    const_reverse_iterator j(reversed + N);
    zr_boost_1_81::random_access_iterator_test(j, N, array);

    const dummyT* const_reversed = reversed;

    zr_boost_1_81::random_access_iterator_test(zr_boost_1_81::make_reverse_iterator(const_reversed + N), N, array);

    zr_boost_1_81::const_nonconst_iterator_test(i, ++j);
  }

  // Test reverse_iterator again, with traits fully deducible on all platforms
  {
    std::deque<dummyT> reversed_container;
    std::reverse_copy(array, array + N, std::back_inserter(reversed_container));
    const std::deque<dummyT>::iterator reversed = reversed_container.begin();


    typedef zr_boost_1_81::reverse_iterator<
        std::deque<dummyT>::iterator> reverse_iterator;
    typedef zr_boost_1_81::reverse_iterator<
        std::deque<dummyT>::const_iterator> const_reverse_iterator;

    // MSVC/STLport gives an INTERNAL COMPILER ERROR when any computation
    // (e.g. "reversed + N") is used in the constructor below.
    const std::deque<dummyT>::iterator finish = reversed_container.end();
    reverse_iterator i(finish);

    zr_boost_1_81::random_access_iterator_test(i, N, array);
    zr_boost_1_81::random_access_iterator_test(zr_boost_1_81::make_reverse_iterator(reversed + N), N, array);

    const_reverse_iterator j = reverse_iterator(finish);
    zr_boost_1_81::random_access_iterator_test(j, N, array);

    const std::deque<dummyT>::const_iterator const_reversed = reversed;
    zr_boost_1_81::random_access_iterator_test(zr_boost_1_81::make_reverse_iterator(const_reversed + N), N, array);

    // Many compilers' builtin deque iterators don't interoperate well, though
    // STLport fixes that problem.
#if defined(__SGI_STL_PORT)                                                             \
    || !BOOST_WORKAROUND(__GNUC__, <= 2)                                                \
    && !(BOOST_WORKAROUND(__GNUC__, == 3) && BOOST_WORKAROUND(__GNUC_MINOR__, <= 1))    \
    && !BOOST_WORKAROUND(BOOST_BORLANDC, BOOST_TESTED_AT(0x551))                          \
    && !BOOST_WORKAROUND(__LIBCOMO_VERSION__, BOOST_TESTED_AT(29))                      \
    && !BOOST_WORKAROUND(BOOST_DINKUMWARE_STDLIB, <= 1)

    zr_boost_1_81::const_nonconst_iterator_test(i, ++j);

#endif
  }

  return zr_boost_1_81::report_errors();
}
