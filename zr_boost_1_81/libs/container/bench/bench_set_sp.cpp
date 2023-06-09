//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2013-2013. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#include "boost/container/set.hpp"
#include "bench_set.hpp"

int main()
{
   using namespace zr_boost_1_81::container;

   fill_range_ints();
   fill_range_strings();

   //set(RB) vs set(SP)
   launch_tests< set<int, std::less<int>, std::allocator<int>, tree_assoc_options< tree_type<splay_tree> >::type >, set<int> >
      ("set<int>(SP)", "set<int>(RB)");
   launch_tests< set<string, std::less<string>, std::allocator<string>, tree_assoc_options< tree_type<splay_tree> >::type >, set<string> >
      ("set<string>(SP)", "set<string>(RB)");

   return 0;
}
