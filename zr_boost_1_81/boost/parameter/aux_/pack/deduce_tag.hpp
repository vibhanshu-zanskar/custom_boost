// Copyright David Abrahams, Daniel Wallin 2003.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PARAMETER_AUX_PACK_DEDUCE_TAG_HPP
#define BOOST_PARAMETER_AUX_PACK_DEDUCE_TAG_HPP

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <
        typename Argument
      , typename ArgumentPack
      , typename DeducedArgs
      , typename UsedArgs
      , typename TagFn
      , typename EmitsErrors
    >
    struct deduce_tag;
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/aux_/lambda_tag.hpp>
#include <boost/parameter/config.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/lambda.hpp>

#if defined(BOOST_PARAMETER_CAN_USE_MP11)

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename Predicate, typename Argument, typename ArgumentPack>
    struct deduce_tag_condition_mpl
      : ::zr_boost_1_81::mpl::apply_wrap2<
            typename ::zr_boost_1_81::mpl::lambda<
                Predicate
              , ::zr_boost_1_81::parameter::aux::lambda_tag
            >::type
          , Argument
          , ArgumentPack
        >
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/aux_/has_nested_template_fn.hpp>
#include <boost/mp11/list.hpp>
#include <boost/mp11/utility.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename Predicate, typename Argument, typename ArgumentPack>
    struct deduce_tag_condition_mp11
    {
        using type = ::zr_boost_1_81::mp11::mp_apply_q<
            Predicate
          , ::zr_boost_1_81::mp11::mp_list<Argument,ArgumentPack>
        >;
    };

    template <typename Predicate, typename Argument, typename ArgumentPack>
    using deduce_tag_condition = ::zr_boost_1_81::mp11::mp_if<
        ::zr_boost_1_81::parameter::aux::has_nested_template_fn<Predicate>
      , ::zr_boost_1_81::parameter::aux
        ::deduce_tag_condition_mp11<Predicate,Argument,ArgumentPack>
      , ::zr_boost_1_81::parameter::aux
        ::deduce_tag_condition_mpl<Predicate,Argument,ArgumentPack>
    >;
}}} // namespace zr_boost_1_81::parameter::aux

#else
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/assert.hpp>
#endif  // BOOST_PARAMETER_CAN_USE_MP11

#include <boost/parameter/aux_/set.hpp>
#include <boost/parameter/aux_/pack/tag_type.hpp>
#include <boost/parameter/aux_/pack/tag_deduced.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    // Helper for deduce_tag<...>, below.
    template <
        typename Argument
      , typename ArgumentPack
      , typename DeducedArgs
      , typename UsedArgs
      , typename TagFn
      , typename EmitsErrors
    >
    class deduce_tag0
    {
        typedef typename DeducedArgs::spec _spec;

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
        typedef typename ::zr_boost_1_81::parameter::aux::deduce_tag_condition<
            typename _spec::predicate
#else
        typedef typename ::zr_boost_1_81::mpl::apply_wrap2<
            typename ::zr_boost_1_81::mpl::lambda<
                typename _spec::predicate
              , ::zr_boost_1_81::parameter::aux::lambda_tag
            >::type
#endif
          , Argument
          , ArgumentPack
        >::type _condition;

#if !defined(BOOST_PARAMETER_CAN_USE_MP11)
        // Deduced parameter matches several arguments.
        BOOST_MPL_ASSERT((
            typename ::zr_boost_1_81::mpl::eval_if<
                typename ::zr_boost_1_81::parameter::aux::has_key_<
                    UsedArgs
                  , typename ::zr_boost_1_81::parameter::aux::tag_type<_spec>::type
                >::type
              , ::zr_boost_1_81::mpl::eval_if<
                    _condition
                  , ::zr_boost_1_81::mpl::if_<
                        EmitsErrors
                      , ::zr_boost_1_81::mpl::false_
                      , ::zr_boost_1_81::mpl::true_
                    >
                  , ::zr_boost_1_81::mpl::true_
                >
              , ::zr_boost_1_81::mpl::true_
            >::type
        ));
#endif  // BOOST_PARAMETER_CAN_USE_MP11

     public:
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
        using type = typename ::zr_boost_1_81::mp11::mp_if<
#else
        typedef typename ::zr_boost_1_81::mpl::eval_if<
#endif
            _condition
          , ::zr_boost_1_81::parameter::aux
            ::tag_deduced<UsedArgs,_spec,Argument,TagFn>
          , ::zr_boost_1_81::parameter::aux::deduce_tag<
                Argument
              , ArgumentPack
              , typename DeducedArgs::tail
              , UsedArgs
              , TagFn
              , EmitsErrors
            >
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
        >::type;
#else
        >::type type;
#endif
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/aux_/void.hpp>

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <type_traits>
#else
#include <boost/mpl/pair.hpp>
#include <boost/type_traits/is_same.hpp>
#endif

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    // Tries to deduced a keyword tag for a given Argument.
    // Returns an mpl::pair<> consisting of the tagged_argument<>,
    // and an mpl::set<> where the new tag has been inserted.
    //
    //  Argument:     The argument type to be tagged.
    //
    //  ArgumentPack: The ArgumentPack built so far.
    //
    //  DeducedArgs:  A specialization of deduced_item<> (see below).
    //                A list containing only the deduced ParameterSpecs.
    //
    //  UsedArgs:     An mpl::set<> containing the keyword tags used so far.
    //
    //  TagFn:        A metafunction class used to tag positional or deduced
    //                arguments with a keyword tag.
    template <
        typename Argument
      , typename ArgumentPack
      , typename DeducedArgs
      , typename UsedArgs
      , typename TagFn
      , typename EmitsErrors
    >
    struct deduce_tag
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
      : ::zr_boost_1_81::mp11::mp_if<
            ::std::is_same<DeducedArgs,::zr_boost_1_81::parameter::void_>
          , ::zr_boost_1_81::mp11::mp_identity<
                ::zr_boost_1_81::mp11::mp_list< ::zr_boost_1_81::parameter::void_,UsedArgs>
            >
#else
      : ::zr_boost_1_81::mpl::eval_if<
            ::zr_boost_1_81::is_same<DeducedArgs,::zr_boost_1_81::parameter::void_>
          , ::zr_boost_1_81::mpl::pair< ::zr_boost_1_81::parameter::void_,UsedArgs>
#endif
          , ::zr_boost_1_81::parameter::aux::deduce_tag0<
                Argument
              , ArgumentPack
              , DeducedArgs
              , UsedArgs
              , TagFn
              , EmitsErrors
            >
        >
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#endif  // include guard

