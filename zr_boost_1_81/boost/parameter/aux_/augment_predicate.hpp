// Copyright Cromwell D. Enage 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PARAMETER_AUGMENT_PREDICATE_HPP
#define BOOST_PARAMETER_AUGMENT_PREDICATE_HPP

#include <boost/parameter/keyword_fwd.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/type_traits/is_lvalue_reference.hpp>
#include <boost/type_traits/is_scalar.hpp>
#include <boost/type_traits/is_same.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename V, typename R, typename Tag>
    struct augment_predicate_check_consume_ref
      : ::zr_boost_1_81::mpl::eval_if<
            ::zr_boost_1_81::is_scalar<V>
          , ::zr_boost_1_81::mpl::true_
          , ::zr_boost_1_81::mpl::eval_if<
                ::zr_boost_1_81::is_same<
                    typename Tag::qualifier
                  , ::zr_boost_1_81::parameter::consume_reference
                >
              , ::zr_boost_1_81::mpl::if_<
                    ::zr_boost_1_81::is_lvalue_reference<R>
                  , ::zr_boost_1_81::mpl::false_
                  , ::zr_boost_1_81::mpl::true_
                >
              , zr_boost_1_81::mpl::true_
            >
        >::type
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/type_traits/is_const.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename V, typename R, typename Tag>
    struct augment_predicate_check_out_ref
      : ::zr_boost_1_81::mpl::eval_if<
            ::zr_boost_1_81::is_same<
                typename Tag::qualifier
              , ::zr_boost_1_81::parameter::out_reference
            >
          , ::zr_boost_1_81::mpl::eval_if<
                ::zr_boost_1_81::is_lvalue_reference<R>
              , ::zr_boost_1_81::mpl::if_<
                    ::zr_boost_1_81::is_const<V>
                  , ::zr_boost_1_81::mpl::false_
                  , ::zr_boost_1_81::mpl::true_
                >
              , ::zr_boost_1_81::mpl::false_
            >
          , ::zr_boost_1_81::mpl::true_
        >::type
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/aux_/lambda_tag.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/lambda.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <
        typename Predicate
      , typename R
      , typename Tag
      , typename T
      , typename Args
    >
    class augment_predicate
    {
        typedef typename ::zr_boost_1_81::mpl::lambda<
            Predicate
          , ::zr_boost_1_81::parameter::aux::lambda_tag
        >::type _actual_predicate;

     public:
        typedef typename ::zr_boost_1_81::mpl::eval_if<
            typename ::zr_boost_1_81::mpl::if_<
                ::zr_boost_1_81::parameter::aux
                ::augment_predicate_check_consume_ref<T,R,Tag>
              , ::zr_boost_1_81::parameter::aux
                ::augment_predicate_check_out_ref<T,R,Tag>
              , ::zr_boost_1_81::mpl::false_
            >::type
          , ::zr_boost_1_81::mpl::apply_wrap2<_actual_predicate,T,Args>
          , ::zr_boost_1_81::mpl::false_
        >::type type;
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/config.hpp>

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <boost/mp11/integral.hpp>
#include <boost/mp11/utility.hpp>
#include <type_traits>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename V, typename R, typename Tag>
    using augment_predicate_check_consume_ref_mp11 = ::zr_boost_1_81::mp11::mp_if<
        ::std::is_scalar<V>
      , ::zr_boost_1_81::mp11::mp_true
      , ::zr_boost_1_81::mp11::mp_if<
            ::std::is_same<
                typename Tag::qualifier
              , ::zr_boost_1_81::parameter::consume_reference
            >
          , ::zr_boost_1_81::mp11::mp_if<
                ::std::is_lvalue_reference<R>
              , ::zr_boost_1_81::mp11::mp_false
              , ::zr_boost_1_81::mp11::mp_true
            >
          , zr_boost_1_81::mp11::mp_true
        >
    >;

    template <typename V, typename R, typename Tag>
    using augment_predicate_check_out_ref_mp11 = ::zr_boost_1_81::mp11::mp_if<
        ::std::is_same<
            typename Tag::qualifier
          , ::zr_boost_1_81::parameter::out_reference
        >
      , ::zr_boost_1_81::mp11::mp_if<
            ::std::is_lvalue_reference<R>
          , ::zr_boost_1_81::mp11::mp_if<
                ::std::is_const<V>
              , ::zr_boost_1_81::mp11::mp_false
              , ::zr_boost_1_81::mp11::mp_true
            >
          , ::zr_boost_1_81::mp11::mp_false
        >
      , ::zr_boost_1_81::mp11::mp_true
    >;
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/mp11/list.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <
        typename Predicate
      , typename R
      , typename Tag
      , typename T
      , typename Args
    >
    struct augment_predicate_mp11_impl
    {
        using type = ::zr_boost_1_81::mp11::mp_if<
            ::zr_boost_1_81::mp11::mp_if<
                ::zr_boost_1_81::parameter::aux
                ::augment_predicate_check_consume_ref_mp11<T,R,Tag>
              , ::zr_boost_1_81::parameter::aux
                ::augment_predicate_check_out_ref_mp11<T,R,Tag>
              , ::zr_boost_1_81::mp11::mp_false
            >
          , ::zr_boost_1_81::mp11
            ::mp_apply_q<Predicate,::zr_boost_1_81::mp11::mp_list<T,Args> >
          , ::zr_boost_1_81::mp11::mp_false
        >;
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/aux_/has_nested_template_fn.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <
        typename Predicate
      , typename R
      , typename Tag
      , typename T
      , typename Args
    >
    using augment_predicate_mp11 = ::zr_boost_1_81::mp11::mp_if<
        ::zr_boost_1_81::parameter::aux::has_nested_template_fn<Predicate>
      , ::zr_boost_1_81::parameter::aux
        ::augment_predicate_mp11_impl<Predicate,R,Tag,T,Args>
      , ::zr_boost_1_81::parameter::aux
        ::augment_predicate<Predicate,R,Tag,T,Args>
    >;
}}} // namespace zr_boost_1_81::parameter::aux

#endif  // BOOST_PARAMETER_CAN_USE_MP11
#endif  // include guard

