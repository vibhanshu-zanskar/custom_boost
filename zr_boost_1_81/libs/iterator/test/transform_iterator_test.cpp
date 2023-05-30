//  (C) Copyright Jeremy Siek 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  Revision History
//  22 Nov 2002 Thomas Witt
//       Added interoperability check.
//  28 Oct 2002   Jeremy Siek
//       Updated for new iterator adaptors.
//  08 Mar 2001   Jeremy Siek
//       Moved test of transform iterator into its own file. It to
//       to be in iterator_adaptor_test.cpp.

#include <boost/assert.hpp>
#include <boost/config.hpp>
#include <algorithm>
#include <boost/iterator/transform_iterator.hpp>
#include <boost/iterator/iterator_concepts.hpp>
#include <boost/iterator/new_iterator_tests.hpp>
#include <boost/pending/iterator_tests.hpp>
#include <boost/concept_check.hpp>

#ifdef BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
namespace zr_boost_1_81 { namespace detail
{
  template<> struct function_object_result<int (*)(int)>
  {
      typedef int type;
  };
}}
#endif

struct mult_functor {
  // Functors used with transform_iterator must be
  // DefaultConstructible, as the transform_iterator must be
  // DefaultConstructible to satisfy the requirements for
  // TrivialIterator.
  mult_functor() { }
  mult_functor(int aa) : a(aa) { }
  int operator()(int b) const { return a * b; }
  int a;
};

struct adaptable_mult_functor
 : mult_functor
{
  typedef int result_type;
  typedef int argument_type;
  // Functors used with transform_iterator must be
  // DefaultConstructible, as the transform_iterator must be
  // DefaultConstructible to satisfy the requirements for
  // TrivialIterator.
  adaptable_mult_functor() { }
  adaptable_mult_functor(int aa) : mult_functor(aa) { }
};


struct const_select_first
{
  typedef int const& result_type;

  int const& operator()(std::pair<int, int>const& p) const
  {
    return p.first;
  }
};

struct select_first
  : const_select_first // derivation to allow conversions
{
  typedef int& result_type;

  int& operator()(std::pair<int, int>& p) const
  {
    return p.first;
  }
};

struct select_second
{
  typedef int& result_type;

  int& operator()(std::pair<int, int>& p) const
  {
    return p.second;
  }
};

struct value_select_first
{
  typedef int result_type;

  int operator()(std::pair<int, int>const& p) const
  {
    return p.first;
  }
};

int mult_2(int arg)
{
  return arg*2;
}

struct polymorphic_mult_functor
{
    //Implement result_of protocol
    template <class FArgs> struct result;
    template <class F, class T> struct result<const F(T       )> {typedef T type;};
    template <class F, class T> struct result<const F(T&      )> {typedef T type;};
    template <class F, class T> struct result<const F(const T&)> {typedef T type;};
    template <class F, class T> struct result<F(T       )> {typedef void type;};
    template <class F, class T> struct result<F(T&      )> {typedef void type;};
    template <class F, class T> struct result<F(const T&)> {typedef void type;};

    template <class T>
    T operator()(const T& _arg) const {return _arg*2;}
    template <class T>
    void operator()(const T& _arg) { BOOST_ASSERT(0); }
};

int
main()
{
  const int N = 10;

  // Concept checks
  {
    typedef zr_boost_1_81::transform_iterator<adaptable_mult_functor, int*>       iter_t;
    typedef zr_boost_1_81::transform_iterator<adaptable_mult_functor, int const*> c_iter_t;

    zr_boost_1_81::function_requires< zr_boost_1_81_concepts::InteroperableIteratorConcept<iter_t, c_iter_t> >();
  }

  // Test transform_iterator
  {
    int x[N], y[N];
    for (int k = 0; k < N; ++k)
      x[k] = k;
    std::copy(x, x + N, y);

    for (int k2 = 0; k2 < N; ++k2)
      x[k2] = x[k2] * 2;

    typedef zr_boost_1_81::transform_iterator<adaptable_mult_functor, int*> iter_t;
    iter_t i(y, adaptable_mult_functor(2));
    zr_boost_1_81::input_iterator_test(i, x[0], x[1]);
    zr_boost_1_81::input_iterator_test(iter_t(&y[0], adaptable_mult_functor(2)), x[0], x[1]);

    zr_boost_1_81::random_access_readable_iterator_test(i, N, x);
  }

  // Test transform_iterator non adaptable functor
  {
    int x[N], y[N];
    for (int k = 0; k < N; ++k)
      x[k] = k;
    std::copy(x, x + N, y);

    for (int k2 = 0; k2 < N; ++k2)
      x[k2] = x[k2] * 2;

    typedef zr_boost_1_81::transform_iterator<mult_functor, int*, int> iter_t;
    iter_t i(y, mult_functor(2));
    zr_boost_1_81::input_iterator_test(i, x[0], x[1]);
    zr_boost_1_81::input_iterator_test(iter_t(&y[0], mult_functor(2)), x[0], x[1]);

    zr_boost_1_81::random_access_readable_iterator_test(i, N, x);
  }

  // Test transform_iterator default argument handling
  {
    {
      typedef zr_boost_1_81::transform_iterator<adaptable_mult_functor, int*, float> iter_t;
      BOOST_STATIC_ASSERT((zr_boost_1_81::is_same<iter_t::reference,  float>::value));
      BOOST_STATIC_ASSERT((zr_boost_1_81::is_same<iter_t::value_type, float>::value));
    }

    {
      typedef zr_boost_1_81::transform_iterator<adaptable_mult_functor, int*, zr_boost_1_81::use_default, float> iter_t;
      BOOST_STATIC_ASSERT((zr_boost_1_81::is_same<iter_t::reference,  int>::value));
      BOOST_STATIC_ASSERT((zr_boost_1_81::is_same<iter_t::value_type, float>::value));
    }

    {
      typedef zr_boost_1_81::transform_iterator<adaptable_mult_functor, int*, float, double> iter_t;
      BOOST_STATIC_ASSERT((zr_boost_1_81::is_same<iter_t::reference,  float>::value));
      BOOST_STATIC_ASSERT((zr_boost_1_81::is_same<iter_t::value_type, double>::value));
    }
  }

  // Test transform_iterator with function pointers
  {
    int x[N], y[N];
    for (int k = 0; k < N; ++k)
      x[k] = k;
    std::copy(x, x + N, y);

    for (int k2 = 0; k2 < N; ++k2)
      x[k2] = x[k2] * 2;

    zr_boost_1_81::input_iterator_test(
        zr_boost_1_81::make_transform_iterator(y, mult_2), x[0], x[1]);

    zr_boost_1_81::input_iterator_test(
        zr_boost_1_81::make_transform_iterator(&y[0], mult_2), x[0], x[1]);

    zr_boost_1_81::random_access_readable_iterator_test(
        zr_boost_1_81::make_transform_iterator(y, mult_2), N, x);

  }

  // Test transform_iterator as projection iterator
  {
    typedef std::pair<int, int> pair_t;

    int    x[N];
    int    y[N];
    pair_t values[N];

    for(int i = 0; i < N; ++i) {

      x[i]             = i;
      y[i]             = N - (i + 1);

    }

    std::copy(
        x
      , x + N
      , zr_boost_1_81::make_transform_iterator((pair_t*)values, select_first())
    );

    std::copy(
        y
      , y + N
      , zr_boost_1_81::make_transform_iterator((pair_t*)values, select_second())
    );

    zr_boost_1_81::random_access_readable_iterator_test(
        zr_boost_1_81::make_transform_iterator((pair_t*)values, value_select_first())
      , N
      , x
    );

    zr_boost_1_81::random_access_readable_iterator_test(
        zr_boost_1_81::make_transform_iterator((pair_t*)values, const_select_first())
      , N, x
    );

    zr_boost_1_81::constant_lvalue_iterator_test(
        zr_boost_1_81::make_transform_iterator((pair_t*)values, const_select_first()), x[0]);

    zr_boost_1_81::non_const_lvalue_iterator_test(
        zr_boost_1_81::make_transform_iterator((pair_t*)values, select_first()), x[0], 17);

    zr_boost_1_81::const_nonconst_iterator_test(
        ++zr_boost_1_81::make_transform_iterator((pair_t*)values, select_first())
      , zr_boost_1_81::make_transform_iterator((pair_t*)values, const_select_first())
    );
  }

  // Test transform_iterator with polymorphic object function
  {
    int x[N], y[N];
    for (int k = 0; k < N; ++k)
      x[k] = k;
    std::copy(x, x + N, y);

    for (int k2 = 0; k2 < N; ++k2)
      x[k2] = x[k2] * 2;

    zr_boost_1_81::input_iterator_test(
        zr_boost_1_81::make_transform_iterator(y, polymorphic_mult_functor()), x[0], x[1]);

    zr_boost_1_81::input_iterator_test(
        zr_boost_1_81::make_transform_iterator(&y[0], polymorphic_mult_functor()), x[0], x[1]);

    zr_boost_1_81::random_access_readable_iterator_test(
        zr_boost_1_81::make_transform_iterator(y, polymorphic_mult_functor()), N, x);
  }

  return zr_boost_1_81::report_errors();
}
