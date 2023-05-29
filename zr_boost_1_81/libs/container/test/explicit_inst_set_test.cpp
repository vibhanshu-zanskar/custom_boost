//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2015-2015. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#include <boost/container/set.hpp>

struct empty
{
   friend bool operator == (const empty &, const empty &){ return true; }
   friend bool operator <  (const empty &, const empty &){ return true; }
};

template class ::zr_boost_1_81::container::set<empty>;
template class ::zr_boost_1_81::container::multiset<empty>;

volatile ::zr_boost_1_81::container::set<empty> dummy;
volatile ::zr_boost_1_81::container::multiset<empty> dummy2;

#include <boost/container/allocator.hpp>
#include <boost/container/adaptive_pool.hpp>
#include "movable_int.hpp"
#include "dummy_test_allocator.hpp"

namespace zr_boost_1_81 {
namespace container {

//Explicit instantiation to detect compilation errors

//set
template class set
   < test::movable_and_copyable_int
   , std::less<test::movable_and_copyable_int>
   , test::simple_allocator<test::movable_and_copyable_int>
   >;

//multiset
template class multiset
   < test::movable_and_copyable_int
   , std::less<test::movable_and_copyable_int>
   , adaptive_pool<test::movable_and_copyable_int>
   >;

}} //zr_boost_1_81::container

int main()
{
   return 0;
}
