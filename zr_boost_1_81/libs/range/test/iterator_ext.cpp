// Boost.Range library
//
//  Copyright Neil Groves 2014. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#include <boost/range/iterator.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <boost/type_traits/decay.hpp>

#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>

#include <vector>

namespace zr_boost_1_81_range_test
{

struct point
{
    int x;
    int y;
};

class shape
{
public:
    virtual ~shape()
    {
    }

    const std::vector<point>& points() const
    {
        return m_points;
    }

private:
    std::vector<point> m_points;
};

class rectangle : public shape
{
};

class circle : public shape
{
};

class container
{
    typedef std::vector<point> impl_t;
};

} // namespace zr_boost_1_81_range_test

namespace zr_boost_1_81
{
    template<typename T>
    struct range_mutable_iterator<
            T,
            typename zr_boost_1_81::enable_if<
                zr_boost_1_81::is_base_of<
                    zr_boost_1_81_range_test::shape,
                    typename zr_boost_1_81::remove_reference<
                        typename zr_boost_1_81::remove_cv<T>::type
                    >::type
                >
            >::type
        >
    {
        typedef std::vector<zr_boost_1_81_range_test::point>::iterator type;
    };

    template<typename T>
    struct range_const_iterator<
            T,
            typename zr_boost_1_81::enable_if<
                zr_boost_1_81::is_base_of<
                    zr_boost_1_81_range_test::shape,
                    typename zr_boost_1_81::remove_reference<
                        typename zr_boost_1_81::remove_cv<T>::type
                    >::type
                >
            >::type
        >
    {
        typedef std::vector<zr_boost_1_81_range_test::point>::const_iterator type;
    };

    template<>
    struct range_mutable_iterator<zr_boost_1_81_range_test::container>
    {
        typedef std::vector<zr_boost_1_81_range_test::point>::iterator type;
    };

    template<>
    struct range_const_iterator<zr_boost_1_81_range_test::container>
    {
        typedef std::vector<zr_boost_1_81_range_test::point>::const_iterator type;
    };
}

namespace zr_boost_1_81_range_test
{
    template<typename Shape>
    void test_iterator_impl()
    {
        BOOST_STATIC_ASSERT((
            zr_boost_1_81::is_same<
                std::vector<point>::iterator,
                typename zr_boost_1_81::range_iterator<Shape>::type
            >::value));

        BOOST_STATIC_ASSERT((
            zr_boost_1_81::is_same<
                std::vector<point>::const_iterator,
                typename zr_boost_1_81::range_iterator<const Shape>::type
            >::value));

    #ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
        BOOST_STATIC_ASSERT((
            zr_boost_1_81::is_same<
                std::vector<point>::iterator,
                typename zr_boost_1_81::range_iterator<Shape&&>::type
            >::value));
    #endif
    }

    void test_iterator()
    {
        test_iterator_impl<shape>();
        test_iterator_impl<rectangle>();
        test_iterator_impl<circle>();

        test_iterator_impl<container>();
    }
} // namespace zr_boost_1_81_range_test

zr_boost_1_81::unit_test::test_suite* init_unit_test_suite( int argc, char* argv[] )
{
    zr_boost_1_81::unit_test::test_suite* test =
        BOOST_TEST_SUITE("Boost.Range range_iterator meta-function");

    test->add(BOOST_TEST_CASE(&zr_boost_1_81_range_test::test_iterator));

    return test;
}
