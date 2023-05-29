// Copyright David Abrahams 2003, Jeremy Siek 2004.

// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/iterator/filter_iterator.hpp>
#include <boost/iterator/reverse_iterator.hpp>
#include <boost/iterator/new_iterator_tests.hpp>
#include <boost/type_traits/is_convertible.hpp>
#include <boost/concept_check.hpp>
#include <boost/concept_archetype.hpp>
#include <boost/iterator/iterator_concepts.hpp>
#include <boost/iterator/iterator_archetypes.hpp>
#include <boost/cstdlib.hpp>

#include <deque>
#include <iostream>

using zr_boost_1_81::dummyT;

struct one_or_four
{
    bool operator()(dummyT x) const
    {
        return x.foo() == 1 || x.foo() == 4;
    }
};

template <class T> struct undefined;

template <class T> struct see_type;

// Test filter iterator
int main()
{
    // Concept checks
    // Adapting old-style iterators
    {
      typedef zr_boost_1_81::filter_iterator<one_or_four, zr_boost_1_81::input_iterator_archetype<dummyT> > Iter;
      zr_boost_1_81::function_requires< zr_boost_1_81::InputIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ReadableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::SinglePassIteratorConcept<Iter> >();
    }
    {
      typedef zr_boost_1_81::filter_iterator<one_or_four, zr_boost_1_81::input_output_iterator_archetype<dummyT> > Iter;
      zr_boost_1_81::function_requires< zr_boost_1_81::InputIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81::OutputIteratorConcept<Iter, dummyT> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ReadableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::WritableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::SinglePassIteratorConcept<Iter> >();
    }
    {
      typedef zr_boost_1_81::filter_iterator<one_or_four, zr_boost_1_81::forward_iterator_archetype<dummyT> > Iter;
      zr_boost_1_81::function_requires< zr_boost_1_81::ForwardIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ReadableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ForwardTraversalConcept<Iter> >();
    }
    {
      typedef zr_boost_1_81::filter_iterator<one_or_four, zr_boost_1_81::mutable_forward_iterator_archetype<dummyT> > Iter;
      zr_boost_1_81::function_requires< zr_boost_1_81::Mutable_ForwardIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ReadableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::WritableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ForwardTraversalConcept<Iter> >();
    }
    {
      typedef zr_boost_1_81::filter_iterator<one_or_four, zr_boost_1_81::bidirectional_iterator_archetype<dummyT> > Iter;
      zr_boost_1_81::function_requires< zr_boost_1_81::BidirectionalIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ReadableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::BidirectionalTraversalConcept<Iter> >();
    }
    {
      typedef zr_boost_1_81::filter_iterator<one_or_four, zr_boost_1_81::mutable_bidirectional_iterator_archetype<dummyT> > Iter;
      zr_boost_1_81::function_requires< zr_boost_1_81::Mutable_BidirectionalIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ReadableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::WritableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::BidirectionalTraversalConcept<Iter> >();
    }
    {
      typedef zr_boost_1_81::filter_iterator<one_or_four, zr_boost_1_81::random_access_iterator_archetype<dummyT> > Iter;
      zr_boost_1_81::function_requires< zr_boost_1_81::BidirectionalIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ReadableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::BidirectionalTraversalConcept<Iter> >();
    }
    {
      typedef zr_boost_1_81::filter_iterator<one_or_four, zr_boost_1_81::mutable_random_access_iterator_archetype<dummyT> > Iter;
      zr_boost_1_81::function_requires< zr_boost_1_81::Mutable_BidirectionalIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ReadableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::WritableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::BidirectionalTraversalConcept<Iter> >();
    }
    // Adapting new-style iterators
    {
      typedef zr_boost_1_81::iterator_archetype<
          const dummyT
        , zr_boost_1_81::iterator_archetypes::readable_iterator_t
        , zr_boost_1_81::single_pass_traversal_tag
      > BaseIter;
      typedef zr_boost_1_81::filter_iterator<one_or_four, BaseIter> Iter;
      zr_boost_1_81::function_requires< zr_boost_1_81::InputIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ReadableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::SinglePassIteratorConcept<Iter> >();
    }
#if !BOOST_WORKAROUND(BOOST_MSVC, == 1200)  // Causes Internal Error in linker.
    {
      typedef zr_boost_1_81::iterator_archetype<
          dummyT
        , zr_boost_1_81::iterator_archetypes::readable_writable_iterator_t
        , zr_boost_1_81::single_pass_traversal_tag
      > BaseIter;
      typedef zr_boost_1_81::filter_iterator<one_or_four, BaseIter> Iter;

      zr_boost_1_81::function_requires< zr_boost_1_81::InputIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81::OutputIteratorConcept<Iter, dummyT> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ReadableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::WritableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::SinglePassIteratorConcept<Iter> >();
    }
#endif
    {
      typedef zr_boost_1_81::iterator_archetype<
          const dummyT
        , zr_boost_1_81::iterator_archetypes::readable_iterator_t
        , zr_boost_1_81::forward_traversal_tag
      > BaseIter;
      typedef zr_boost_1_81::filter_iterator<one_or_four, BaseIter> Iter;
      zr_boost_1_81::function_requires< zr_boost_1_81::InputIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ReadableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ForwardTraversalConcept<Iter> >();
    }

#if !BOOST_WORKAROUND(BOOST_MSVC, == 1200)  // Causes Internal Error in linker.
    {
      typedef zr_boost_1_81::iterator_archetype<
          dummyT
        , zr_boost_1_81::iterator_archetypes::readable_writable_iterator_t
        , zr_boost_1_81::forward_traversal_tag
      > BaseIter;
      typedef zr_boost_1_81::filter_iterator<one_or_four, BaseIter> Iter;
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ReadableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::WritableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ForwardTraversalConcept<Iter> >();
    }
    {
      typedef zr_boost_1_81::iterator_archetype<
          const dummyT
        , zr_boost_1_81::iterator_archetypes::readable_lvalue_iterator_t
        , zr_boost_1_81::forward_traversal_tag
      > BaseIter;
      typedef zr_boost_1_81::filter_iterator<one_or_four, BaseIter> Iter;
      zr_boost_1_81::function_requires< zr_boost_1_81::ForwardIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ReadableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::LvalueIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ForwardTraversalConcept<Iter> >();
    }
    {
      typedef zr_boost_1_81::iterator_archetype<
          dummyT
        , zr_boost_1_81::iterator_archetypes::writable_lvalue_iterator_t
        , zr_boost_1_81::forward_traversal_tag
      > BaseIter;
      typedef zr_boost_1_81::filter_iterator<one_or_four, BaseIter> Iter;
      zr_boost_1_81::function_requires< zr_boost_1_81::Mutable_ForwardIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::WritableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::LvalueIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ForwardTraversalConcept<Iter> >();
    }
#endif

    {
      typedef zr_boost_1_81::iterator_archetype<
          const dummyT
        , zr_boost_1_81::iterator_archetypes::readable_iterator_t
        , zr_boost_1_81::random_access_traversal_tag
      > BaseIter;
      typedef zr_boost_1_81::filter_iterator<one_or_four, BaseIter> Iter;
      zr_boost_1_81::function_requires< zr_boost_1_81::InputIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ReadableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::BidirectionalTraversalConcept<Iter> >();
    }

#if !BOOST_WORKAROUND(BOOST_MSVC, == 1200)  // Causes Internal Error in linker.
    {
      typedef zr_boost_1_81::iterator_archetype<
          dummyT
        , zr_boost_1_81::iterator_archetypes::readable_writable_iterator_t
        , zr_boost_1_81::random_access_traversal_tag
      > BaseIter;
      typedef zr_boost_1_81::filter_iterator<one_or_four, BaseIter> Iter;
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ReadableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::WritableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::BidirectionalTraversalConcept<Iter> >();
    }
    {
      typedef zr_boost_1_81::iterator_archetype<
          const dummyT
        , zr_boost_1_81::iterator_archetypes::readable_lvalue_iterator_t
        , zr_boost_1_81::random_access_traversal_tag
      > BaseIter;
      typedef zr_boost_1_81::filter_iterator<one_or_four, BaseIter> Iter;
      zr_boost_1_81::function_requires< zr_boost_1_81::BidirectionalIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::ReadableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::LvalueIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::BidirectionalTraversalConcept<Iter> >();
    }
    {
      typedef zr_boost_1_81::iterator_archetype<
          dummyT
        , zr_boost_1_81::iterator_archetypes::writable_lvalue_iterator_t
        , zr_boost_1_81::random_access_traversal_tag
      > BaseIter;
      typedef zr_boost_1_81::filter_iterator<one_or_four, BaseIter> Iter;
      zr_boost_1_81::function_requires< zr_boost_1_81::Mutable_BidirectionalIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::WritableIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::LvalueIteratorConcept<Iter> >();
      zr_boost_1_81::function_requires< zr_boost_1_81_concepts::BidirectionalTraversalConcept<Iter> >();
    }
#endif

    // Run-time tests

    dummyT array[] = { dummyT(0), dummyT(1), dummyT(2),
                       dummyT(3), dummyT(4), dummyT(5) };
    const int N = sizeof(array)/sizeof(dummyT);

    typedef zr_boost_1_81::filter_iterator<one_or_four, dummyT*> filter_iter;

    zr_boost_1_81::bidirectional_readable_iterator_test(
        filter_iter(one_or_four(), array, array+N)
        , dummyT(1), dummyT(4));

    BOOST_STATIC_ASSERT(
        (!zr_boost_1_81::is_convertible<
             zr_boost_1_81::iterator_traversal<filter_iter>::type
           , zr_boost_1_81::random_access_traversal_tag
         >::value
        ));

    //# endif

    // On compilers not supporting partial specialization, we can do more type
    // deduction with deque iterators than with pointers... unless the library
    // is broken ;-(
    std::deque<dummyT> array2;
    std::copy(array+0, array+N, std::back_inserter(array2));
    zr_boost_1_81::bidirectional_readable_iterator_test(
        zr_boost_1_81::make_filter_iterator(one_or_four(), array2.begin(), array2.end()),
        dummyT(1), dummyT(4));

    zr_boost_1_81::bidirectional_readable_iterator_test(
        zr_boost_1_81::make_filter_iterator(one_or_four(), array2.begin(), array2.end()),
        dummyT(1), dummyT(4));

    zr_boost_1_81::bidirectional_readable_iterator_test(
        zr_boost_1_81::make_filter_iterator(
              one_or_four()
            , zr_boost_1_81::make_reverse_iterator(array2.end())
            , zr_boost_1_81::make_reverse_iterator(array2.begin())
            ),
        dummyT(4), dummyT(1));

    zr_boost_1_81::bidirectional_readable_iterator_test(
        filter_iter(array+0, array+N),
        dummyT(1), dummyT(4));

    zr_boost_1_81::bidirectional_readable_iterator_test(
        filter_iter(one_or_four(), array, array + N),
        dummyT(1), dummyT(4));


    return zr_boost_1_81::report_errors();
}
