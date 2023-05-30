// Copyright Cromwell D. Enage 2017.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PARAMETER_AUX_PACK_MAKE_PARAMETER_SPEC_ITEMS_HPP
#define BOOST_PARAMETER_AUX_PACK_MAKE_PARAMETER_SPEC_ITEMS_HPP

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    // This recursive metafunction forwards successive elements of
    // parameters::parameter_spec to make_deduced_items<>.
    // -- Cromwell D. Enage
    template <typename SpecSeq>
    struct make_deduced_list;

    // Helper for match_parameters_base_cond<...>, below.
    template <typename ArgumentPackAndError, typename SpecSeq>
    struct match_parameters_base_cond_helper;

    // Helper metafunction for make_parameter_spec_items<...>, below.
    template <typename SpecSeq, typename ...Args>
    struct make_parameter_spec_items_helper;
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/aux_/void.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename SpecSeq>
    struct make_parameter_spec_items_helper<SpecSeq>
    {
        typedef ::zr_boost_1_81::parameter::void_ type;
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/aux_/pack/make_deduced_items.hpp>

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <boost/mp11/list.hpp>
#else
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
#endif

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename SpecSeq>
    struct make_deduced_list_not_empty
      : ::zr_boost_1_81::parameter::aux::make_deduced_items<
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
            ::zr_boost_1_81::mp11::mp_front<SpecSeq>
#else
            typename ::zr_boost_1_81::mpl::front<SpecSeq>::type
#endif
          , ::zr_boost_1_81::parameter::aux::make_deduced_list<
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
                ::zr_boost_1_81::mp11::mp_pop_front<SpecSeq>
#else
                typename ::zr_boost_1_81::mpl::pop_front<SpecSeq>::type
#endif
            >
        >
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <boost/mp11/utility.hpp>
#else
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/identity.hpp>
#endif

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename SpecSeq>
    struct make_deduced_list
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
      : ::zr_boost_1_81::mp11::mp_if<
            ::zr_boost_1_81::mp11::mp_empty<SpecSeq>
          , ::zr_boost_1_81::mp11::mp_identity< ::zr_boost_1_81::parameter::void_>
#else
      : ::zr_boost_1_81::mpl::eval_if<
            ::zr_boost_1_81::mpl::empty<SpecSeq>
          , ::zr_boost_1_81::mpl::identity< ::zr_boost_1_81::parameter::void_>
#endif
          , ::zr_boost_1_81::parameter::aux::make_deduced_list_not_empty<SpecSeq>
        >
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <type_traits>
#else
#include <boost/mpl/bool.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/is_same.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename ArgumentPackAndError>
    struct is_arg_pack_error_void
      : ::zr_boost_1_81::mpl::if_<
            ::zr_boost_1_81::is_same<
                typename ::zr_boost_1_81::mpl::second<ArgumentPackAndError>::type
              , ::zr_boost_1_81::parameter::void_
            >
          , ::zr_boost_1_81::mpl::true_
          , ::zr_boost_1_81::mpl::false_
        >::type
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#endif  // BOOST_PARAMETER_CAN_USE_MP11

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    // Checks if the arguments match the criteria of overload resolution.
    // If NamedList satisfies the PS0, PS1, ..., this is a metafunction
    // returning parameters.  Otherwise it has no nested ::type.
    template <typename ArgumentPackAndError, typename SpecSeq>
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
    using match_parameters_base_cond = ::zr_boost_1_81::mp11::mp_if<
        ::zr_boost_1_81::mp11::mp_empty<SpecSeq>
      , ::std::is_same<
            ::zr_boost_1_81::mp11::mp_at_c<ArgumentPackAndError,1>
          , ::zr_boost_1_81::parameter::void_
        >
      , ::zr_boost_1_81::parameter::aux::match_parameters_base_cond_helper<
            ArgumentPackAndError
          , SpecSeq
        >
    >;
#else
    struct match_parameters_base_cond
      : ::zr_boost_1_81::mpl::eval_if<
            ::zr_boost_1_81::mpl::empty<SpecSeq>
          , ::zr_boost_1_81::parameter::aux
            ::is_arg_pack_error_void<ArgumentPackAndError>
          , ::zr_boost_1_81::parameter::aux::match_parameters_base_cond_helper<
                ArgumentPackAndError
              , SpecSeq
            >
        >
    {
    };
#endif  // BOOST_PARAMETER_CAN_USE_MP11
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/aux_/pack/satisfies.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename ArgumentPackAndError, typename SpecSeq>
    struct match_parameters_base_cond_helper
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
      : ::zr_boost_1_81::mp11::mp_if<
#else
      : ::zr_boost_1_81::mpl::eval_if<
#endif
            ::zr_boost_1_81::parameter::aux::satisfies_requirements_of<
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
                ::zr_boost_1_81::mp11::mp_at_c<ArgumentPackAndError,0>
              , ::zr_boost_1_81::mp11::mp_front<SpecSeq>
#else
                typename ::zr_boost_1_81::mpl::first<ArgumentPackAndError>::type
              , typename ::zr_boost_1_81::mpl::front<SpecSeq>::type
#endif
            >
          , ::zr_boost_1_81::parameter::aux::match_parameters_base_cond<
                ArgumentPackAndError
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
              , ::zr_boost_1_81::mp11::mp_pop_front<SpecSeq>
#else
              , typename ::zr_boost_1_81::mpl::pop_front<SpecSeq>::type
#endif
            >
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
          , ::zr_boost_1_81::mp11::mp_false
#else
          , ::zr_boost_1_81::mpl::false_
#endif
        >
    {
    };

    // This parameters item chaining metafunction class does not require
    // the lengths of the SpecSeq and of Args parameter pack to match.
    // Used by argument_pack to build the items in the resulting arg_list.
    // -- Cromwell D. Enage
    template <typename SpecSeq, typename ...Args>
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
    using make_parameter_spec_items = ::zr_boost_1_81::mp11::mp_if<
        ::zr_boost_1_81::mp11::mp_empty<SpecSeq>
      , ::zr_boost_1_81::mp11::mp_identity< ::zr_boost_1_81::parameter::void_>
      , ::zr_boost_1_81::parameter::aux
        ::make_parameter_spec_items_helper<SpecSeq,Args...>
    >;
#else
    struct make_parameter_spec_items
      : ::zr_boost_1_81::mpl::eval_if<
            ::zr_boost_1_81::mpl::empty<SpecSeq>
          , ::zr_boost_1_81::mpl::identity< ::zr_boost_1_81::parameter::void_>
          , ::zr_boost_1_81::parameter::aux
            ::make_parameter_spec_items_helper<SpecSeq,Args...>
        >
    {
    };
#endif
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/aux_/pack/make_items.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename SpecSeq, typename A0, typename ...Args>
    struct make_parameter_spec_items_helper<SpecSeq,A0,Args...>
      : ::zr_boost_1_81::parameter::aux::make_items<
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
            ::zr_boost_1_81::mp11::mp_front<SpecSeq>
#else
            typename ::zr_boost_1_81::mpl::front<SpecSeq>::type
#endif
          , A0
          , ::zr_boost_1_81::parameter::aux::make_parameter_spec_items<
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
                ::zr_boost_1_81::mp11::mp_pop_front<SpecSeq>
#else
                typename ::zr_boost_1_81::mpl::pop_front<SpecSeq>::type
#endif
              , Args...
            >
        >
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#endif  // include guard

