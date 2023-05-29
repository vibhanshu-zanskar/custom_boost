#include <boost/fusion/include/deque.hpp>
#include <boost/fusion/include/make_deque.hpp>
#include <boost/fusion/sequence/intrinsic/at_c.hpp>

#define ZI_TUPLE      zr_boost_1_81::fusion::deque
#define ZI_MAKE_TUPLE zr_boost_1_81::fusion::make_deque
#define ZI_TUPLE_GET(n) zr_boost_1_81::fusion::at_c<n>

#include "detail/zip_iterator_test_original.ipp"
