/*
Copyright 2007 Tobias Schwinger
Copyright 2017 Daniel James

Copyright 2019 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost/functional/factory.hpp>
#include <boost/core/lightweight_test.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <memory>

class sum  {
public:
    sum(int a, int b)
        : value_(a + b) { }

    int get() const {
        return value_;
    }

private:
    int value_;
};

int main()
{
    int a = 1;
    int b = 2;
    {
        zr_boost_1_81::shared_ptr<sum> s(zr_boost_1_81::factory<zr_boost_1_81::shared_ptr<sum>,
            std::allocator<char>,
            zr_boost_1_81::factory_alloc_for_pointee_and_deleter>()(a, b));
        BOOST_TEST(s->get() == 3);
    }
    {
        zr_boost_1_81::shared_ptr<sum> s(zr_boost_1_81::factory<zr_boost_1_81::shared_ptr<sum>,
            std::allocator<char>,
            zr_boost_1_81::factory_passes_alloc_to_smart_pointer>()(a, b));
        BOOST_TEST(s->get() == 3);
    }
    return zr_boost_1_81::report_errors();
}
