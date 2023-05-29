// Boost.Range library
//
//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
//[tokenized_example
#include <boost/range/adaptor/tokenized.hpp>
#include <boost/range/algorithm/copy.hpp>
#include <boost/assign.hpp>
#include <iterator>
#include <iostream>
#include <vector>

//<-
#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/range/algorithm_ext/push_back.hpp>

namespace 
{
void tokenized_example_test()
//->
//=int main(int argc, const char* argv[])
{
    using namespace zr_boost_1_81::adaptors;
    
    typedef zr_boost_1_81::sub_match< std::string::iterator > match_type;
    
    std::string input = " a b c d e f g hijklmnopqrstuvwxyz";
    zr_boost_1_81::copy(
        input | tokenized(zr_boost_1_81::regex("\\w+")),
        std::ostream_iterator<match_type>(std::cout, "\n"));

//=    return 0;
//=}
//]
    using namespace zr_boost_1_81::assign;

    std::vector<std::string> reference;
    reference += "a","b","c","d","e","f","g","hijklmnopqrstuvwxyz";
    
    std::vector<match_type> test;
    zr_boost_1_81::push_back(test, input | tokenized(zr_boost_1_81::regex("\\w+")));
    
    BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
        test.begin(), test.end() );
}
}

zr_boost_1_81::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    zr_boost_1_81::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.adaptor.tokenized_example" );

    test->add( BOOST_TEST_CASE( &tokenized_example_test ) );

    return test;
}
