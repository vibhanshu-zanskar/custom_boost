// Copyright 2022 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt

#include <boost/system/error_code.hpp>
#include <boost/core/lightweight_test.hpp>
#include <sstream>

namespace sys = zr_boost_1_81::system;

int main()
{
    {
        std::wostringstream os;
        os << sys::error_code();

        BOOST_TEST( os.str() == L"system:0" );
    }

    return zr_boost_1_81::report_errors();
}
