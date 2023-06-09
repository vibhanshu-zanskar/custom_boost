
//  (C) Copyright Edward Diener 2019
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#if !defined(BOOST_TTI_DETAIL_COMP_MEM_FUN_TEMPLATE_HPP)
#define BOOST_TTI_DETAIL_COMP_MEM_FUN_TEMPLATE_HPP

#include <boost/mpl/bool.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/array/enum.hpp>
#include <boost/tti/detail/dftclass.hpp>
#include <boost/tti/detail/dnullptr.hpp>
#include <boost/tti/detail/dmacro_sunfix.hpp>
#include <boost/tti/gen/namespace_gen.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#define BOOST_TTI_DETAIL_TRAIT_HAS_COMP_MEMBER_FUNCTION_TEMPLATE(trait,name,tparray) \
  template<class BOOST_TTI_DETAIL_TP_T> \
  struct BOOST_PP_CAT(trait,_detail_hcmft) \
    { \
    template<class BOOST_TTI_DETAIL_TP_F> \
    struct cl_type : \
      zr_boost_1_81::remove_const \
        < \
        typename BOOST_TTI_NAMESPACE::detail::class_type<BOOST_TTI_DETAIL_TP_F>::type \
        > \
      { \
      }; \
    \
    template<BOOST_TTI_DETAIL_TP_T> \
    struct helper BOOST_TTI_DETAIL_MACRO_SUNFIX ; \
    \
    template<class BOOST_TTI_DETAIL_TP_U> \
    static ::zr_boost_1_81::type_traits::yes_type check(helper<&BOOST_TTI_DETAIL_TP_U::template name<BOOST_PP_ARRAY_ENUM(tparray)> > *); \
    \
    template<class BOOST_TTI_DETAIL_TP_U> \
    static ::zr_boost_1_81::type_traits::no_type check(...); \
    \
    typedef zr_boost_1_81::mpl::bool_<sizeof(check<typename cl_type<BOOST_TTI_DETAIL_TP_T>::type>(BOOST_TTI_DETAIL_NULLPTR))==sizeof(::zr_boost_1_81::type_traits::yes_type)> type; \
    }; \
/**/

#endif // BOOST_TTI_DETAIL_COMP_MEM_FUN_TEMPLATE_HPP
