//  header_only_test.cpp  -----------------------------------------------------//

//  Copyright Beman Dawes 2007

//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See library home page at http://www.boost.org/libs/system

//----------------------------------------------------------------------------// 

#include <boost/config/warning_disable.hpp>

#define BOOST_ERROR_CODE_HEADER_ONLY

#include <boost/detail/lightweight_test.hpp>
#include <boost/system/error_code.hpp>

int main()
{
    zr_boost_1_81::system::error_code ec( 0, zr_boost_1_81::system::system_category() );
    (void)ec;

    return ::zr_boost_1_81::report_errors();
}
