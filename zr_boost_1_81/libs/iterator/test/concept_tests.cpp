// (C) Copyright Jeremy Siek 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/iterator/iterator_concepts.hpp>
#include <boost/iterator/iterator_categories.hpp>
#include <boost/operators.hpp>

#include <iterator>
#include <cstddef>

struct new_random_access
  : std::random_access_iterator_tag
  , zr_boost_1_81::random_access_traversal_tag
{};

struct new_iterator
{
  typedef new_random_access iterator_category;
  typedef int value_type;
  typedef std::ptrdiff_t difference_type;
  typedef int* pointer;
  typedef int& reference;

  int& operator*() const { return *m_x; }
  new_iterator& operator++() { return *this; }
  new_iterator operator++(int) { return *this; }
  new_iterator& operator--() { return *this; }
  new_iterator operator--(int) { return *this; }
  new_iterator& operator+=(std::ptrdiff_t) { return *this; }
  new_iterator operator+(std::ptrdiff_t) { return *this; }
  new_iterator& operator-=(std::ptrdiff_t) { return *this; }
  std::ptrdiff_t operator-(const new_iterator&) const { return 0; }
  new_iterator operator-(std::ptrdiff_t) const { return *this; }
  bool operator==(const new_iterator&) const { return false; }
  bool operator!=(const new_iterator&) const { return false; }
  bool operator<(const new_iterator&) const { return false; }
  int* m_x;
};
new_iterator operator+(std::ptrdiff_t, new_iterator x) { return x; }

struct old_iterator
{
  typedef std::random_access_iterator_tag iterator_category;
  typedef int value_type;
  typedef std::ptrdiff_t difference_type;
  typedef int* pointer;
  typedef int& reference;

  int& operator*() const { return *m_x; }
  old_iterator& operator++() { return *this; }
  old_iterator operator++(int) { return *this; }
  old_iterator& operator--() { return *this; }
  old_iterator operator--(int) { return *this; }
  old_iterator& operator+=(std::ptrdiff_t) { return *this; }
  old_iterator operator+(std::ptrdiff_t) { return *this; }
  old_iterator& operator-=(std::ptrdiff_t) { return *this; }
  old_iterator operator-(std::ptrdiff_t) const { return *this; }
  std::ptrdiff_t operator-(const old_iterator&) const { return 0; }
  bool operator==(const old_iterator&) const { return false; }
  bool operator!=(const old_iterator&) const { return false; }
  bool operator<(const old_iterator&) const { return false; }
  int* m_x;
};
old_iterator operator+(std::ptrdiff_t, old_iterator x) { return x; }

int
main()
{
  zr_boost_1_81::iterator_traversal<new_iterator>::type tc;
  zr_boost_1_81::random_access_traversal_tag derived = tc;
  (void)derived;

  zr_boost_1_81::function_requires<
    zr_boost_1_81_concepts::WritableIteratorConcept<int*> >();
  zr_boost_1_81::function_requires<
    zr_boost_1_81_concepts::LvalueIteratorConcept<int*> >();
  zr_boost_1_81::function_requires<
    zr_boost_1_81_concepts::RandomAccessTraversalConcept<int*> >();

  zr_boost_1_81::function_requires<
    zr_boost_1_81_concepts::ReadableIteratorConcept<const int*> >();
  zr_boost_1_81::function_requires<
    zr_boost_1_81_concepts::LvalueIteratorConcept<const int*> >();
  zr_boost_1_81::function_requires<
    zr_boost_1_81_concepts::RandomAccessTraversalConcept<const int*> >();

  zr_boost_1_81::function_requires<
    zr_boost_1_81_concepts::WritableIteratorConcept<new_iterator> >();
  zr_boost_1_81::function_requires<
    zr_boost_1_81_concepts::LvalueIteratorConcept<new_iterator> >();
  zr_boost_1_81::function_requires<
    zr_boost_1_81_concepts::RandomAccessTraversalConcept<new_iterator> >();

  zr_boost_1_81::function_requires<
    zr_boost_1_81_concepts::WritableIteratorConcept<old_iterator> >();
  zr_boost_1_81::function_requires<
    zr_boost_1_81_concepts::LvalueIteratorConcept<old_iterator> >();
  zr_boost_1_81::function_requires<
    zr_boost_1_81_concepts::RandomAccessTraversalConcept<old_iterator> >();

  zr_boost_1_81::function_requires<
    zr_boost_1_81_concepts::InteroperableIteratorConcept<int*, int const*> >();

  return 0;
}
