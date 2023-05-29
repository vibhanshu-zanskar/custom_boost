// Boost.Range library
//
//  Copyright Thorsten Ottosen & Larry Evans 2003-2005. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

//#include <boost/range/as_array.hpp>

#include <boost/detail/workaround.hpp>

#if BOOST_WORKAROUND(BOOST_BORLANDC, BOOST_TESTED_AT(0x564))
#  pragma warn -8091 // suppress warning in Boost.Test
#  pragma warn -8057 // unused argument argc/argv in Boost.Test
#endif

#include <boost/range/iterator_range.hpp>
#include <boost/range/functions.hpp>
#include <boost/range/as_literal.hpp>
#include <boost/cstdint.hpp>
#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <string>
#include <vector>

void check_reference_type();

void check_iterator_range()
{

    typedef std::string::iterator                 iterator;
    typedef std::string::const_iterator           const_iterator;
    typedef zr_boost_1_81::iterator_range<iterator>       irange;
    typedef zr_boost_1_81::iterator_range<const_iterator> cirange;
    std::string       str  = "hello world";
    const std::string cstr = "const world";
    irange r    = zr_boost_1_81::make_iterator_range( str );
    r           = zr_boost_1_81::make_iterator_range( str.begin(), str.end() );
    cirange r2  = zr_boost_1_81::make_iterator_range( cstr );
    r2          = zr_boost_1_81::make_iterator_range( cstr.begin(), cstr.end() );
    r2          = zr_boost_1_81::make_iterator_range( str );

    BOOST_CHECK( !r.empty() );
    BOOST_CHECK( !r2.empty() );

//#if BOOST_WORKAROUND(BOOST_BORLANDC, BOOST_TESTED_AT(0x564))
//    if( !(bool)r )
//        BOOST_CHECK( false );
//    if( !(bool)r2 )
//        BOOST_CHECK( false );
//#else
    if( !r )
        BOOST_CHECK( false );
    if( !r2 )
        BOOST_CHECK( false );
//#endif

    BOOST_CHECK_EQUAL( r.size(), zr_boost_1_81::size( r ) );
    BOOST_CHECK_EQUAL( r2.size(), zr_boost_1_81::size( r2 ) );

    BOOST_CHECK_EQUAL( std::distance( r.begin(), r.end() ),
                       std::distance( zr_boost_1_81::begin( r2 ), zr_boost_1_81::end( r2 ) ) );
    std::cout << r << r2;


#ifndef BOOST_NO_STD_WSTRING
    std::wcout << zr_boost_1_81::make_iterator_range( std::wstring( L"a wide string" ) )
               << zr_boost_1_81::make_iterator_range( L"another wide string" );
#endif

    std::string res  = zr_boost_1_81::copy_range<std::string>( r );
    BOOST_CHECK_EQUAL_COLLECTIONS( res.begin(), res.end(), r.begin(), r.end() );

    irange rr = zr_boost_1_81::make_iterator_range( str );
    BOOST_CHECK( rr.equal( r ) );

    rr  = zr_boost_1_81::make_iterator_range( str.begin(), str.begin() + 5 );
    BOOST_CHECK( rr == zr_boost_1_81::as_literal("hello") );
    BOOST_CHECK( rr != zr_boost_1_81::as_literal("hell") );
    BOOST_CHECK( rr < zr_boost_1_81::as_literal("hello dude") );
    BOOST_CHECK( zr_boost_1_81::as_literal("hello") == rr );
    BOOST_CHECK( zr_boost_1_81::as_literal("hell")  != rr );
    BOOST_CHECK( ! (zr_boost_1_81::as_literal("hello dude") < rr ) );
    irange rrr = rr;
    BOOST_CHECK( rrr == rr );
    BOOST_CHECK( !( rrr != rr ) );
    BOOST_CHECK( !( rrr < rr ) );

    const irange cr = zr_boost_1_81::make_iterator_range( str );
    BOOST_CHECK_EQUAL( cr.front(), 'h' );
    BOOST_CHECK_EQUAL( cr.back(), 'd' );
    BOOST_CHECK_EQUAL( cr[1], 'e' );
    BOOST_CHECK_EQUAL( cr(1), 'e' );

    rrr = zr_boost_1_81::make_iterator_range( str, 1, -1 );
    BOOST_CHECK( rrr == zr_boost_1_81::as_literal("ello worl") );
    rrr = zr_boost_1_81::make_iterator_range( rrr, -1, 1 );
    BOOST_CHECK( rrr == str );

    check_reference_type();
    
    // Check that an iterator range can be instantiated with
    // a pointer to an array as an iterator.
    int arr[2][2];
    zr_boost_1_81::make_iterator_range(arr, arr + 2);
}

namespace iterator_range_test_detail
{
    struct less
    {
        template< class Left, class Right >
        bool operator()(const Left& l, const Right& r) const
        {
            return l < r;
        }
    };
    
    struct greater
    {
        template< class Left, class Right >
        bool operator()(const Left& l, const Right& r) const
        {
            return l > r;
        }
    };
    
    struct less_or_equal
    {
        template< class Left, class Right >
        bool operator()(const Left& l, const Right& r) const
        {
            return l <= r;
        }
    };
    
    struct greater_or_equal
    {
        template< class Left, class Right >
        bool operator()(const Left& l, const Right& r) const
        {
            return l >= r;
        }
    };
    
    struct equal_to
    {
        template< class Left, class Right >
        bool operator()(const Left& l, const Right& r) const
        {
            return l == r;
        }
    };
    
    struct not_equal_to
    {
        template< class Left, class Right >
        bool operator()(const Left& l, const Right& r) const
        {
            return l != r;
        }
    };
    
    template< class Pred >
    void check_iterator_range_operators_impl(Pred pred)
    {
        std::vector<std::string> vals;
        vals.push_back(std::string());
        vals.push_back("a");
        vals.push_back("b");
        vals.push_back("z");
        vals.push_back("ab");
        vals.push_back("ba");
        vals.push_back("abc");
        vals.push_back("cba");
        vals.push_back("aa");
        vals.push_back("aaa");
        vals.push_back("aab");
        vals.push_back("bba");

        typedef std::string::const_iterator citer;
        typedef zr_boost_1_81::iterator_range<citer> iter_range;

        typedef std::vector<std::string>::const_iterator value_const_iterator;
        value_const_iterator first_val = vals.begin();
        value_const_iterator last_val = vals.end();
        
        for (value_const_iterator left_it = first_val; left_it != last_val; ++left_it)
        {
            const std::string& leftValue = *left_it;
            for (value_const_iterator right_it = first_val; right_it != last_val; ++right_it)
            {
                const std::string& rightValue = *right_it;
                iter_range left = zr_boost_1_81::make_iterator_range(leftValue);
                iter_range right = zr_boost_1_81::make_iterator_range(rightValue);
                
                const bool reference = pred(leftValue, rightValue);
                
                BOOST_CHECK_EQUAL( pred(left, right), reference );
                BOOST_CHECK_EQUAL( pred(left, rightValue), reference );
                BOOST_CHECK_EQUAL( pred(leftValue, right), reference );
            }
        }
    }
    
    void check_iterator_range_from_array()
    {
        double source[] = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0 };
        zr_boost_1_81::iterator_range<double*> rng = zr_boost_1_81::make_iterator_range(source);
        BOOST_CHECK_EQUAL_COLLECTIONS( rng.begin(), rng.end(),
                                       source, source + 6 );
    }

    void check_make_iterator_range_n()
    {
        using zr_boost_1_81::uint32_t;

        std::vector<uint32_t> input;
        for (uint32_t i = 0; i < 10u; ++i)
            input.push_back(i);

        zr_boost_1_81::iterator_range<std::vector<uint32_t>::iterator> rng =
                zr_boost_1_81::make_iterator_range_n(zr_boost_1_81::begin(input), 8u);

        BOOST_CHECK(rng.begin() == input.begin());
        BOOST_CHECK(rng.end() == input.begin() + 8);
        BOOST_CHECK_EQUAL(rng.size(), 8u);

        const std::vector<uint32_t>& cinput = input;

        zr_boost_1_81::iterator_range<std::vector<uint32_t>::const_iterator> crng =
                zr_boost_1_81::make_iterator_range_n(zr_boost_1_81::begin(cinput), 8u);

        BOOST_CHECK(crng.begin() == cinput.begin());
        BOOST_CHECK(crng.end() == cinput.begin() + 8);
        BOOST_CHECK_EQUAL(crng.size(), 8u);
    }

} // namespace iterator_range_test_detail

template<typename Pred>
inline void check_iterator_range_operator()
{
    iterator_range_test_detail::check_iterator_range_operators_impl(
        Pred());
}

inline void test_advance()
{
    std::vector<int> l;
    l.push_back(1);
    l.push_back(2);
    typedef zr_boost_1_81::iterator_range<std::vector<int>::iterator> rng_t;

    rng_t r1(l.begin(), l.end());
    BOOST_CHECK(r1.advance_begin(1).advance_end(-1).empty());
    
    rng_t r2(l.begin(), l.end());
    BOOST_CHECK_EQUAL(r2.advance_begin(1).size(), 1u);

    rng_t r3(l.begin(), l.end());
    BOOST_CHECK_EQUAL(r3.advance_end(-1).size(), 1u);
}

struct ptr_iterator
  : zr_boost_1_81::iterator_adaptor<ptr_iterator, int *>
{
    ptr_iterator() {}
    ptr_iterator(int *p) : zr_boost_1_81::iterator_adaptor<ptr_iterator, int *>(p) {}
private:
    typedef void iterator; // To throw off the SFINAE mechanism in iterator_range
};

void test_sfinae()
{
    zr_boost_1_81::iterator_range<ptr_iterator> r(ptr_iterator(0), ptr_iterator(0));
}

//
//
// Check that constness is propagated correct from
// the iterator types.
//
// Test contributed by Larry Evans.
//

template< class Container >
int test_iter_range( Container& a_cont )
{
    typedef BOOST_DEDUCED_TYPENAME zr_boost_1_81::range_iterator<Container>::type citer_type;
    typedef zr_boost_1_81::iterator_range<citer_type> riter_type;
    riter_type a_riter( zr_boost_1_81::make_iterator_range( a_cont ) );
    a_riter.front();
    a_riter.back();
    int i = a_riter[0];
    return i;
}



void check_reference_type()
{
    typedef std::vector<int> veci_type;
    veci_type a_vec;
    a_vec.push_back( 999 );
    test_iter_range<veci_type>(a_vec);
    test_iter_range<veci_type const>(a_vec);
}

zr_boost_1_81::unit_test::test_suite* init_unit_test_suite( int argc, char* argv[] )
{
    zr_boost_1_81::unit_test::test_suite* test = BOOST_TEST_SUITE( "Range Test Suite" );
    
    test->add(BOOST_TEST_CASE(&check_iterator_range));
    test->add(BOOST_TEST_CASE(&check_iterator_range_operator<iterator_range_test_detail::less>));
    test->add(BOOST_TEST_CASE(&check_iterator_range_operator<iterator_range_test_detail::less_or_equal>));
    test->add(BOOST_TEST_CASE(&check_iterator_range_operator<iterator_range_test_detail::greater>));
    test->add(BOOST_TEST_CASE(&check_iterator_range_operator<iterator_range_test_detail::greater_or_equal>));
    test->add(BOOST_TEST_CASE(&check_iterator_range_operator<iterator_range_test_detail::equal_to>));
    test->add(BOOST_TEST_CASE(&check_iterator_range_operator<iterator_range_test_detail::not_equal_to>));
    test->add(BOOST_TEST_CASE(&iterator_range_test_detail::check_make_iterator_range_n));
    test->add(BOOST_TEST_CASE(&test_advance));
    
    return test;
}

