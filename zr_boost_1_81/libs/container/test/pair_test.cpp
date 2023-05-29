//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2011-2013. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////
#include <boost/container/detail/pair.hpp>
#include "movable_int.hpp"
#include "emplace_test.hpp"
#include<boost/move/utility_core.hpp>
#include<boost/move/detail/fwd_macros.hpp>
#include<boost/core/lightweight_test.hpp>

//non_copymovable_int
//copyable_int
//movable_int
//movable_and_copyable_int


#include <boost/tuple/tuple.hpp>

#if !defined(BOOST_NO_CXX11_HDR_TUPLE) || (defined(BOOST_MSVC) && (BOOST_MSVC == 1700 || BOOST_MSVC == 1600))
#define BOOST_CONTAINER_PAIR_TEST_HAS_HEADER_TUPLE
#endif

#if defined(BOOST_CONTAINER_PAIR_TEST_HAS_HEADER_TUPLE)
#include <tuple>
#endif

using namespace ::zr_boost_1_81::container;

int main ()
{
   {
      dtl::pair<test::non_copymovable_int, test::non_copymovable_int> p1;
      dtl::pair<test::copyable_int, test::copyable_int> p2;
      dtl::pair<test::movable_int, test::movable_int> p3;
      dtl::pair<test::movable_and_copyable_int, test::movable_and_copyable_int> p4;
   }
   {  //Constructible from two values
      dtl::pair<test::non_copymovable_int, test::non_copymovable_int> p1(1, 2);
      dtl::pair<test::copyable_int, test::copyable_int> p2(1, 2);
      dtl::pair<test::movable_int, test::movable_int> p3(1, 2);
      dtl::pair<test::movable_and_copyable_int, test::movable_and_copyable_int> p4(1, 2);
   }

   {  //Constructible from internal types
      dtl::pair<test::copyable_int, test::copyable_int> p2(test::copyable_int(1), test::copyable_int(2));
      {
         test::movable_int a(1), b(2);
         dtl::pair<test::movable_int, test::movable_int> p3(::zr_boost_1_81::move(a), ::zr_boost_1_81::move(b));
      }
      {
         test::movable_and_copyable_int a(1), b(2);
         dtl::pair<test::movable_and_copyable_int, test::movable_and_copyable_int> p4(::zr_boost_1_81::move(a), ::zr_boost_1_81::move(b));
      }
   }
   {  //piecewise construct from boost tuple
      using namespace zr_boost_1_81::tuples;
      {
         zr_boost_1_81::container::dtl::pair<int, float> p(piecewise_construct, tuple<>(), tuple<>());
         BOOST_TEST(p.first == 0);
         BOOST_TEST(p.second == 0.f);
      }
      {
         zr_boost_1_81::container::dtl::pair<int, float> p(piecewise_construct, tuple<>(), tuple<float>(2.f));
         BOOST_TEST(p.first == 0);
         BOOST_TEST(p.second == 2.f);
      }
      {
         zr_boost_1_81::container::dtl::pair<int, float> p(piecewise_construct, tuple<int>(2), tuple<float>(1.f));
         BOOST_TEST(p.first == 2);
         BOOST_TEST(p.second == 1.f);
      }
      {
         zr_boost_1_81::container::dtl::pair
            < zr_boost_1_81::container::dtl::pair<int, float>
            , zr_boost_1_81::container::dtl::pair<double, char>
            > p(piecewise_construct, tuple<int, float>(3, 4.f), tuple<double, char>(8.,'a'));
         BOOST_TEST(p.first.first   == 3);
         BOOST_TEST(p.first.second  == 4.f);
         BOOST_TEST(p.second.first  == 8.);
         BOOST_TEST(p.second.second == 'a');
      }
      {
         zr_boost_1_81::container::dtl::pair
            < tuple<int, float, double>
            , char
            > p(piecewise_construct, tuple<int, float, double>(3, 16.f, 32.), tuple<char>('b'));
         BOOST_TEST(p.first.get<0>() == 3);
         BOOST_TEST(p.first.get<1>() == 16.f);
         BOOST_TEST(p.first.get<2>() == 32.);
         BOOST_TEST(p.second == 'b');
      }
   }
   #if defined(BOOST_CONTAINER_PAIR_TEST_HAS_HEADER_TUPLE)
   {  //piecewise construct from std tuple
      using std::tuple;
      {
         zr_boost_1_81::container::dtl::pair<int, float> p(piecewise_construct, tuple<>(), tuple<>());
         BOOST_TEST(p.first == 0);
         BOOST_TEST(p.second == 0.f);
      }
      {
         zr_boost_1_81::container::dtl::pair<int, float> p(piecewise_construct, tuple<>(), tuple<float>(2.f));
         BOOST_TEST(p.first == 0);
         BOOST_TEST(p.second == 2.f);
      }
      {
         zr_boost_1_81::container::dtl::pair<int, float> p(piecewise_construct, tuple<int>(2), tuple<float>(1.f));
         BOOST_TEST(p.first == 2);
         BOOST_TEST(p.second == 1.f);
      }
      {
         zr_boost_1_81::container::dtl::pair
            < zr_boost_1_81::container::dtl::pair<int, float>
            , zr_boost_1_81::container::dtl::pair<double, char>
            > p(piecewise_construct, tuple<int, float>(3, 4.f), tuple<double, char>(8.,'a'));
         BOOST_TEST(p.first.first   == 3);
         BOOST_TEST(p.first.second  == 4.f);
         BOOST_TEST(p.second.first  == 8.);
         BOOST_TEST(p.second.second == 'a');
      }
      {
         zr_boost_1_81::container::dtl::pair
            < tuple<int, float, double>
            , char
            > p(piecewise_construct, tuple<int, float, double>(3, 16.f, 32.), tuple<char>('b'));
         BOOST_TEST(std::get<0>(p.first) == 3);
         BOOST_TEST(std::get<1>(p.first) == 16.f);
         BOOST_TEST(std::get<2>(p.first) == 32.);
         BOOST_TEST(p.second == 'b');
      }
      #if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES) && !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
      typedef dtl::pair<test::movable_int, test::movable_int> movable_pair_t;
      typedef dtl::pair<movable_pair_t, movable_pair_t> movable_pair_pair_t;
      test::movable_int a(1), b(2), c(3), d(4);
      movable_pair_pair_t p( piecewise_construct
                           , dtl::forward_as_tuple_impl(zr_boost_1_81::move(a), zr_boost_1_81::move(b))
                           , dtl::forward_as_tuple_impl(zr_boost_1_81::move(c), zr_boost_1_81::move(d))
                           );
      BOOST_TEST(p.first.first   == 1);
      BOOST_TEST(p.first.second  == 2);
      BOOST_TEST(p.second.first  == 3);
      BOOST_TEST(p.second.second == 4);
      #endif
   }
   #endif   //#!defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES) && !defined(BOOST_NO_CXX11_HDR_TUPLE)
   return ::zr_boost_1_81::report_errors();
}
