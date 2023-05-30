/*
Copyright 2007 Tobias Schwinger

Copyright 2019 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost/functional/factory.hpp>
#include <boost/core/lightweight_test.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>

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

template<class T>
class creator {
public:
    static int count;

    typedef T value_type;
    typedef T* pointer;

    template<class U>
    struct rebind {
        typedef creator<U> other;
    };

    creator() { }

    template<class U>
    creator(const creator<U>&) { }

    T* allocate(std::size_t size) {
        ++count;
        return static_cast<T*>(::operator new(sizeof(T) * size));
    }

    void deallocate(T* ptr, std::size_t) {
        --count;
        ::operator delete(ptr);
    }
};

template<class T>
int creator<T>::count = 0;

template<class T, class U>
inline bool
operator==(const creator<T>&, const creator<U>&)
{
    return true;
}

template<class T, class U>
inline bool
operator!=(const creator<T>&, const creator<U>&)
{
    return false;
}

int main()
{
    int a = 1;
    int b = 2;
    {
        zr_boost_1_81::shared_ptr<sum> s(zr_boost_1_81::factory<zr_boost_1_81::shared_ptr<sum>,
            creator<void>,
            zr_boost_1_81::factory_alloc_for_pointee_and_deleter>()(a, b));
        BOOST_TEST(creator<sum>::count == 1);
        BOOST_TEST(s->get() == 3);
    }
    BOOST_TEST(creator<sum>::count == 0);
    {
        zr_boost_1_81::shared_ptr<sum> s(zr_boost_1_81::factory<zr_boost_1_81::shared_ptr<sum>,
            creator<void>,
            zr_boost_1_81::factory_passes_alloc_to_smart_pointer>()(a, b));
        BOOST_TEST(creator<sum>::count == 1);
        BOOST_TEST(s->get() == 3);
    }
    BOOST_TEST(creator<sum>::count == 0);
    return zr_boost_1_81::report_errors();
}

