// Copyright 2022 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt

// Reduced from a zr_boost_1_81::system::result test; codegen bug
// in GCC < 5 which is somehow triggered by __PRETTY_FUNCTION__
// and throwing an exception

#include <boost/assert/source_location.hpp>
#include <boost/core/lightweight_test.hpp>
#include <exception>

template<class T> class result
{
private:

    bool has_value_;
    T value_;

public:

    result(): has_value_( false ), value_()
    {
    }

    T value( zr_boost_1_81::source_location const& /*loc*/ = BOOST_CURRENT_LOCATION ) const
    {
        if( has_value_ )
        {
            return value_;
        }
        else
        {
            throw std::exception();
        }
    }
};

int main()
{
    result<int> r;
    BOOST_TEST_THROWS( r.value(), std::exception );
    return zr_boost_1_81::report_errors();
}
