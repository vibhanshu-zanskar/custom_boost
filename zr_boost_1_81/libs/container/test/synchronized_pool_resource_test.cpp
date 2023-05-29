//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2015-2015. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#include <boost/container/pmr/synchronized_pool_resource.hpp>
#include <boost/core/lightweight_test.hpp>
#include "pool_resource_test.hpp"

int main()
{
   test_pool_resource<zr_boost_1_81::container::pmr::synchronized_pool_resource>();
   return ::zr_boost_1_81::report_errors();
}
