
//  (C) Copyright Edward Diener 2019
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#if !defined(BOOST_TTI_DETAIL_ENUM_HPP)
#define BOOST_TTI_DETAIL_ENUM_HPP

#include <boost/mpl/and.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/has_xxx.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/tti/detail/ddeftype.hpp>
#include <boost/tti/detail/dlambda.hpp>
#include <boost/tti/detail/denclosing_type.hpp>
#include <boost/tti/gen/namespace_gen.hpp>
#include <boost/type_traits/is_enum.hpp>

#define BOOST_TTI_DETAIL_TRAIT_INVOKE_HAS_ENUM(trait,name) \
template<class BOOST_TTI_DETAIL_TP_T,class BOOST_TTI_DETAIL_TP_MFC> \
struct BOOST_PP_CAT(trait,_detail_enum_invoke) \
  { \
  BOOST_MPL_ASSERT((BOOST_TTI_NAMESPACE::detail::is_lambda_expression<BOOST_TTI_DETAIL_TP_MFC>)); \
  typedef typename zr_boost_1_81::mpl::apply<BOOST_TTI_DETAIL_TP_MFC,typename BOOST_TTI_DETAIL_TP_T::name>::type type; \
  }; \
/**/

#define BOOST_TTI_DETAIL_TRAIT_HAS_ENUM_OP_CHOOSE(trait,name) \
BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(BOOST_PP_CAT(trait,_detail_enum_mpl), name, false) \
BOOST_TTI_DETAIL_TRAIT_INVOKE_HAS_ENUM(trait,name) \
template<class BOOST_TTI_DETAIL_TP_T,class BOOST_TTI_DETAIL_TP_U,class BOOST_TTI_DETAIL_TP_B> \
struct BOOST_PP_CAT(trait,_detail_enum_op_choose) : \
  zr_boost_1_81::mpl::and_ \
    < \
    zr_boost_1_81::is_enum<typename BOOST_TTI_DETAIL_TP_T::name>, \
    BOOST_PP_CAT(trait,_detail_enum_invoke)<BOOST_TTI_DETAIL_TP_T,BOOST_TTI_DETAIL_TP_U> \
    > \
  { \
  }; \
\
template<class BOOST_TTI_DETAIL_TP_T,class BOOST_TTI_DETAIL_TP_U> \
struct BOOST_PP_CAT(trait,_detail_enum_op_choose)<BOOST_TTI_DETAIL_TP_T,BOOST_TTI_DETAIL_TP_U,zr_boost_1_81::mpl::false_::type> : \
  zr_boost_1_81::mpl::false_ \
  { \
  }; \
\
template<class BOOST_TTI_DETAIL_TP_T> \
struct BOOST_PP_CAT(trait,_detail_enum_op_choose)<BOOST_TTI_DETAIL_TP_T,BOOST_TTI_NAMESPACE::detail::deftype,zr_boost_1_81::mpl::true_::type> : \
  zr_boost_1_81::is_enum<typename BOOST_TTI_DETAIL_TP_T::name> \
  { \
  }; \
/**/

#define BOOST_TTI_DETAIL_TRAIT_HAS_ENUM_OP(trait,name) \
BOOST_TTI_DETAIL_TRAIT_HAS_ENUM_OP_CHOOSE(trait,name) \
template<class BOOST_TTI_DETAIL_TP_T,class BOOST_TTI_DETAIL_TP_U> \
struct BOOST_PP_CAT(trait,_detail_enum_op) : \
  BOOST_PP_CAT(trait,_detail_enum_op_choose) \
    < \
    BOOST_TTI_DETAIL_TP_T, \
    BOOST_TTI_DETAIL_TP_U, \
    typename BOOST_PP_CAT(trait,_detail_enum_mpl)<BOOST_TTI_DETAIL_TP_T>::type \
    > \
  { \
  }; \
/**/

#define BOOST_TTI_DETAIL_TRAIT_HAS_ENUM(trait,name) \
BOOST_TTI_DETAIL_TRAIT_HAS_ENUM_OP(trait,name) \
template<class BOOST_TTI_DETAIL_TP_T,class BOOST_TTI_DETAIL_TP_U> \
struct BOOST_PP_CAT(trait,_detail_enum) : \
    zr_boost_1_81::mpl::eval_if \
        < \
        BOOST_TTI_NAMESPACE::detail::enclosing_type<BOOST_TTI_DETAIL_TP_T>, \
        BOOST_PP_CAT(trait,_detail_enum_op)<BOOST_TTI_DETAIL_TP_T,BOOST_TTI_DETAIL_TP_U>, \
        zr_boost_1_81::mpl::false_ \
        > \
  { \
  }; \
/**/

#endif // BOOST_TTI_DETAIL_ENUM_HPP
