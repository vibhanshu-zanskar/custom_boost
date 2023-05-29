#include <boost/config.hpp>

#include <boost/fusion/include/vector.hpp>
#include <boost/fusion/include/make_vector.hpp>
#include <boost/fusion/sequence/intrinsic/at_c.hpp>

#define ZI_TUPLE      zr_boost_1_81::fusion::vector
#define ZI_MAKE_TUPLE zr_boost_1_81::fusion::make_vector
#define ZI_TUPLE_GET(n) zr_boost_1_81::fusion::at_c<n>

#include "detail/zip_iterator_test_original.ipp"
