
//  (C) Copyright Edward Diener 2019
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#if !defined(BOOST_TTI_DETAIL_STATIC_FUNCTION_TAGS_HPP)
#define BOOST_TTI_DETAIL_STATIC_FUNCTION_TAGS_HPP

#include <boost/function_types/property_tags.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/or.hpp>

namespace zr_boost_1_81
  {
  namespace tti
    {
    namespace detail
      {
      template
        <
        class BOOST_TTI_DETAIL_TP_TAG
        >
      struct static_function_tag :
        zr_boost_1_81::mpl::not_
          <
          zr_boost_1_81::mpl::or_
            <
            zr_boost_1_81::function_types::has_const_property_tag<BOOST_TTI_DETAIL_TP_TAG>,
            zr_boost_1_81::function_types::has_volatile_property_tag<BOOST_TTI_DETAIL_TP_TAG>
            >
          >
        {
        };
      }
    }
  }
  
#endif // BOOST_TTI_DETAIL_STATIC_FUNCTION_TAGS_HPP
