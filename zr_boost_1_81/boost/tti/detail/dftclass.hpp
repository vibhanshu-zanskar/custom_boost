
//  (C) Copyright Edward Diener 2012,2013
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#if !defined(BOOST_TTI_DETAIL_FTCLASS_HPP)
#define BOOST_TTI_DETAIL_FTCLASS_HPP

#include <boost/function_types/parameter_types.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/quote.hpp>

namespace zr_boost_1_81
  {
  namespace tti
    {
    namespace detail
      {
      template<class BOOST_TTI_DETAIL_TP_F>
      struct class_type :
          zr_boost_1_81::mpl::at
            <
            typename
            zr_boost_1_81::function_types::parameter_types
              <
              BOOST_TTI_DETAIL_TP_F,
              zr_boost_1_81::mpl::quote1
                <
                zr_boost_1_81::mpl::identity
                >
              >::type,
              zr_boost_1_81::mpl::int_<0>
            >
        {
        };
      }
    }
  }
  
#endif // BOOST_TTI_DETAIL_FTCLASS_HPP
