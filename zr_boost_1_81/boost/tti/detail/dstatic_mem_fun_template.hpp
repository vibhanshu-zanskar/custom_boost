
//  (C) Copyright Edward Diener 2019
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#if !defined(BOOST_TTI_DETAIL_STATIC_MEM_FUN_TEMPLATE_HPP)
#define BOOST_TTI_DETAIL_STATIC_MEM_FUN_TEMPLATE_HPP

#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/array/enum.hpp>
#include <boost/tti/detail/dmacro_sunfix.hpp>
#include <boost/tti/detail/dnullptr.hpp>
#include <boost/tti/detail/dtfunction.hpp>
#include <boost/tti/detail/denclosing_type.hpp>
#include <boost/tti/detail/dstatic_function_tags.hpp>
#include <boost/tti/detail/dstatic_function_type.hpp>
#include <boost/tti/gen/namespace_gen.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#define BOOST_TTI_DETAIL_TRAIT_IMPL_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE(trait,name,pparray) \
  template<class BOOST_TTI_DETAIL_TP_T,class BOOST_TTI_DETAIL_TP_TYPE> \
  struct BOOST_PP_CAT(trait,_detail_ihsmft) \
    { \
    template<BOOST_TTI_DETAIL_TP_TYPE *> \
    struct helper BOOST_TTI_DETAIL_MACRO_SUNFIX ; \
    \
    template<class U> \
    static ::zr_boost_1_81::type_traits::yes_type check(helper<&U::template name<BOOST_PP_ARRAY_ENUM(pparray)> > *); \
    \
    template<class U> \
    static ::zr_boost_1_81::type_traits::no_type check(...); \
    \
    typedef zr_boost_1_81::mpl::bool_<sizeof(check<BOOST_TTI_DETAIL_TP_T>(BOOST_TTI_DETAIL_NULLPTR))==sizeof(::zr_boost_1_81::type_traits::yes_type)> type; \
    }; \
/**/

#define BOOST_TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE_TEST_FUNC_CALL(trait,name,pparray) \
  template<class BOOST_TTI_DETAIL_TP_T,class BOOST_TTI_DETAIL_TP_R,class BOOST_TTI_DETAIL_TP_FS,class BOOST_TTI_DETAIL_TP_TAG> \
  struct BOOST_PP_CAT(trait,_detail_hsmft_ttc) : \
    BOOST_PP_CAT(trait,_detail_ihsmft) \
      < \
      BOOST_TTI_DETAIL_TP_T, \
      typename BOOST_TTI_NAMESPACE::detail::tfunction_seq<BOOST_TTI_DETAIL_TP_R,BOOST_TTI_DETAIL_TP_FS,BOOST_TTI_DETAIL_TP_TAG>::type \
      > \
    { \
    }; \
/**/

#define BOOST_TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE_TEST_FUNC(trait,name,pparray) \
  BOOST_TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE_TEST_FUNC_CALL(trait,name,pparray) \
  template<class BOOST_TTI_DETAIL_TP_T,class BOOST_TTI_DETAIL_TP_R,class BOOST_TTI_DETAIL_TP_FS,class BOOST_TTI_DETAIL_TP_TAG> \
  struct BOOST_PP_CAT(trait,_detail_hsmft_tt) : \
    zr_boost_1_81::mpl::eval_if \
      < \
      BOOST_TTI_NAMESPACE::detail::static_function_tag<BOOST_TTI_DETAIL_TP_TAG>, \
      BOOST_PP_CAT(trait,_detail_hsmft_ttc)<BOOST_TTI_DETAIL_TP_T,BOOST_TTI_DETAIL_TP_R,BOOST_TTI_DETAIL_TP_FS,BOOST_TTI_DETAIL_TP_TAG>, \
      zr_boost_1_81::mpl::false_ \
      > \
    { \
    }; \
/**/

#define BOOST_TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE_OP(trait,name,pparray) \
  BOOST_TTI_DETAIL_TRAIT_IMPL_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE(trait,name,pparray) \
  BOOST_TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE_TEST_FUNC(trait,name,pparray) \
  template<class BOOST_TTI_DETAIL_TP_T,class BOOST_TTI_DETAIL_TP_R,class BOOST_TTI_DETAIL_TP_FS,class BOOST_TTI_DETAIL_TP_TAG> \
  struct BOOST_PP_CAT(trait,_detail_hsmft_op) : \
    zr_boost_1_81::mpl::eval_if \
      < \
      BOOST_TTI_NAMESPACE::detail::static_function_type<BOOST_TTI_DETAIL_TP_R,BOOST_TTI_DETAIL_TP_FS,BOOST_TTI_DETAIL_TP_TAG>, \
      BOOST_PP_CAT(trait,_detail_ihsmft)<BOOST_TTI_DETAIL_TP_T,BOOST_TTI_DETAIL_TP_R>, \
      BOOST_PP_CAT(trait,_detail_hsmft_tt)<BOOST_TTI_DETAIL_TP_T,BOOST_TTI_DETAIL_TP_R,BOOST_TTI_DETAIL_TP_FS,BOOST_TTI_DETAIL_TP_TAG> \
      > \
    { \
    }; \
/**/

#define BOOST_TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE(trait,name,pparray) \
  BOOST_TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE_OP(trait,name,pparray) \
  template<class BOOST_TTI_DETAIL_TP_T,class BOOST_TTI_DETAIL_TP_R,class BOOST_TTI_DETAIL_TP_FS,class BOOST_TTI_DETAIL_TP_TAG> \
  struct BOOST_PP_CAT(trait,_detail_hsmft) : \
    zr_boost_1_81::mpl::eval_if \
        < \
        BOOST_TTI_NAMESPACE::detail::enclosing_type<BOOST_TTI_DETAIL_TP_T>, \
        BOOST_PP_CAT(trait,_detail_hsmft_op)<BOOST_TTI_DETAIL_TP_T,BOOST_TTI_DETAIL_TP_R,BOOST_TTI_DETAIL_TP_FS,BOOST_TTI_DETAIL_TP_TAG>, \
        zr_boost_1_81::mpl::false_ \
        > \
    { \
    }; \
/**/

#endif // BOOST_TTI_DETAIL_STATIC_MEM_FUN_TEMPLATE_HPP
