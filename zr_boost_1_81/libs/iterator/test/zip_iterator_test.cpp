#include <boost/tuple/tuple.hpp>

#define ZI_TUPLE      zr_boost_1_81::tuples::tuple
#define ZI_MAKE_TUPLE zr_boost_1_81::make_tuple
#define ZI_TUPLE_GET(n) zr_boost_1_81::tuples::get<n>
#define ZI_USE_BOOST_TUPLE

#include "detail/zip_iterator_test_original.ipp"
