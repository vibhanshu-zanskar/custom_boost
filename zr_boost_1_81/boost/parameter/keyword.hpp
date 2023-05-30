// Copyright Daniel Wallin, David Abrahams 2005.
// Copyright Cromwell D. Enage 2017.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PARAMETER_KEYWORD_HPP
#define BOOST_PARAMETER_KEYWORD_HPP

#include <boost/parameter/aux_/tag.hpp>
#include <boost/parameter/aux_/default.hpp>
#include <boost/parameter/keyword_fwd.hpp>
#include <boost/parameter/config.hpp>

#if defined(BOOST_PARAMETER_HAS_PERFECT_FORWARDING)
#include <boost/core/enable_if.hpp>
#include <utility>

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <boost/mp11/integral.hpp>
#include <boost/mp11/utility.hpp>
#include <type_traits>
#else
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/is_scalar.hpp>
#include <boost/type_traits/is_const.hpp>
#endif

namespace zr_boost_1_81 { namespace parameter {

    // Instances of unique specializations of keyword<...> serve to
    // associate arguments with parameter names.  For example:
    //
    //     struct rate_;             // parameter names
    //     struct skew_;
    //
    //     namespace
    //     {
    //         keyword<rate_> rate;  // keywords
    //         keyword<skew_> skew;
    //     }
    //
    //     ...
    //
    //     f(rate = 1, skew = 2.4);
    template <typename Tag>
    struct keyword
    {
        typedef Tag tag;

        inline BOOST_CONSTEXPR keyword()
        {
        }

        template <typename T>
        inline BOOST_CONSTEXPR typename ::zr_boost_1_81::lazy_enable_if<
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
            ::zr_boost_1_81::mp11::mp_if<
                ::std::is_scalar<T>
              , ::zr_boost_1_81::mp11::mp_true
              , ::zr_boost_1_81::mp11::mp_if<
                    ::std::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::in_reference
                    >
                  , ::zr_boost_1_81::mp11::mp_true
                  , ::std::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::forward_reference
                    >
                >
            >
#else   // !defined(BOOST_PARAMETER_CAN_USE_MP11)
            typename ::zr_boost_1_81::mpl::eval_if<
                ::zr_boost_1_81::is_scalar<T>
              , ::zr_boost_1_81::mpl::true_
              , ::zr_boost_1_81::mpl::eval_if<
                    ::zr_boost_1_81::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::in_reference
                    >
                  , ::zr_boost_1_81::mpl::true_
                  , ::zr_boost_1_81::mpl::if_<
                        ::zr_boost_1_81::is_same<
                            typename Tag::qualifier
                          , ::zr_boost_1_81::parameter::forward_reference
                        >
                      , ::zr_boost_1_81::mpl::true_
                      , ::zr_boost_1_81::mpl::false_
                    >
                >
            >::type
#endif  // BOOST_PARAMETER_CAN_USE_MP11
          , ::zr_boost_1_81::parameter::aux::tag<Tag,T const&>
        >::type
            operator=(T const& x) const
        {
            typedef typename ::zr_boost_1_81::parameter::aux
            ::tag<Tag,T const&>::type result;
            return result(x);
        }

        template <typename Default>
        inline BOOST_CONSTEXPR typename ::zr_boost_1_81::enable_if<
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
            ::zr_boost_1_81::mp11::mp_if<
                ::std::is_scalar<Default>
              , ::zr_boost_1_81::mp11::mp_true
              , ::zr_boost_1_81::mp11::mp_if<
                    ::std::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::in_reference
                    >
                  , ::zr_boost_1_81::mp11::mp_true
                  , ::std::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::forward_reference
                    >
                >
            >
#else   // !defined(BOOST_PARAMETER_CAN_USE_MP11)
            typename ::zr_boost_1_81::mpl::eval_if<
                ::zr_boost_1_81::is_scalar<Default>
              , ::zr_boost_1_81::mpl::true_
              , ::zr_boost_1_81::mpl::eval_if<
                    ::zr_boost_1_81::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::in_reference
                    >
                  , ::zr_boost_1_81::mpl::true_
                  , ::zr_boost_1_81::mpl::if_<
                        ::zr_boost_1_81::is_same<
                            typename Tag::qualifier
                          , ::zr_boost_1_81::parameter::forward_reference
                        >
                      , ::zr_boost_1_81::mpl::true_
                      , ::zr_boost_1_81::mpl::false_
                    >
                >
            >::type
#endif  // BOOST_PARAMETER_CAN_USE_MP11
          , ::zr_boost_1_81::parameter::aux::default_<Tag,Default const>
        >::type
            operator|(Default const& d) const
        {
            return ::zr_boost_1_81::parameter::aux::default_<Tag,Default const>(d);
        }

        template <typename T>
        inline BOOST_CONSTEXPR typename ::zr_boost_1_81::lazy_enable_if<
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
            ::zr_boost_1_81::mp11::mp_if<
                ::zr_boost_1_81::mp11::mp_if<
                    ::std::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::out_reference
                    >
                  , ::zr_boost_1_81::mp11::mp_true
                  , ::std::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::forward_reference
                    >
                >
              , ::zr_boost_1_81::mp11::mp_if<
                    ::std::is_const<T>
                  , ::zr_boost_1_81::mp11::mp_false
                  , ::zr_boost_1_81::mp11::mp_true
                >
              , ::zr_boost_1_81::mp11::mp_false
            >
#else   // !defined(BOOST_PARAMETER_CAN_USE_MP11)
            typename ::zr_boost_1_81::mpl::eval_if<
                typename ::zr_boost_1_81::mpl::if_<
                    ::zr_boost_1_81::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::out_reference
                    >
                  , ::zr_boost_1_81::mpl::true_
                  , ::zr_boost_1_81::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::forward_reference
                    >
                >::type
              , ::zr_boost_1_81::mpl::if_<
                    ::zr_boost_1_81::is_const<T>
                  , ::zr_boost_1_81::mpl::false_
                  , ::zr_boost_1_81::mpl::true_
                >
              , ::zr_boost_1_81::mpl::false_
            >::type
#endif  // BOOST_PARAMETER_CAN_USE_MP11
          , ::zr_boost_1_81::parameter::aux::tag<Tag,T&>
        >::type
            operator=(T& x) const
        {
            typedef typename ::zr_boost_1_81::parameter::aux
            ::tag<Tag,T&>::type result;
            return result(x);
        }

        template <typename Default>
        inline BOOST_CONSTEXPR typename ::zr_boost_1_81::enable_if<
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
            ::zr_boost_1_81::mp11::mp_if<
                ::zr_boost_1_81::mp11::mp_if<
                    ::std::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::out_reference
                    >
                  , ::zr_boost_1_81::mp11::mp_true
                  , ::std::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::forward_reference
                    >
                >
              , ::zr_boost_1_81::mp11::mp_if<
                    ::std::is_const<Default>
                  , ::zr_boost_1_81::mp11::mp_false
                  , ::zr_boost_1_81::mp11::mp_true
                >
              , ::zr_boost_1_81::mp11::mp_false
            >
#else   // !defined(BOOST_PARAMETER_CAN_USE_MP11)
            typename ::zr_boost_1_81::mpl::eval_if<
                typename ::zr_boost_1_81::mpl::if_<
                    ::zr_boost_1_81::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::out_reference
                    >
                  , ::zr_boost_1_81::mpl::true_
                  , ::zr_boost_1_81::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::forward_reference
                    >
                >::type
              , ::zr_boost_1_81::mpl::if_<
                    ::zr_boost_1_81::is_const<Default>
                  , ::zr_boost_1_81::mpl::false_
                  , ::zr_boost_1_81::mpl::true_
                >
              , ::zr_boost_1_81::mpl::false_
            >::type
#endif  // BOOST_PARAMETER_CAN_USE_MP11
          , ::zr_boost_1_81::parameter::aux::default_<Tag,Default>
        >::type
            operator|(Default& d) const
        {
            return ::zr_boost_1_81::parameter::aux::default_<Tag,Default>(d);
        }

        template <typename Default>
        inline BOOST_CONSTEXPR
        ::zr_boost_1_81::parameter::aux::lazy_default<Tag,Default const>
            operator||(Default const& d) const
        {
            return ::zr_boost_1_81::parameter::aux
            ::lazy_default<Tag,Default const>(d);
        }

        template <typename Default>
        inline BOOST_CONSTEXPR
        ::zr_boost_1_81::parameter::aux::lazy_default<Tag,Default>
            operator||(Default& d) const
        {
            return ::zr_boost_1_81::parameter::aux::lazy_default<Tag,Default>(d);
        }

        template <typename T>
        inline BOOST_CONSTEXPR typename ::zr_boost_1_81::lazy_enable_if<
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
            ::zr_boost_1_81::mp11::mp_if<
                ::std::is_scalar<T>
              , ::zr_boost_1_81::mp11::mp_false
              , ::zr_boost_1_81::mp11::mp_if<
                    ::std::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::in_reference
                    >
                  , ::zr_boost_1_81::mp11::mp_true
                  , ::std::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::forward_reference
                    >
                >
            >
#else   // !defined(BOOST_PARAMETER_CAN_USE_MP11)
            typename ::zr_boost_1_81::mpl::eval_if<
                ::zr_boost_1_81::is_scalar<T>
              , ::zr_boost_1_81::mpl::false_
              , ::zr_boost_1_81::mpl::eval_if<
                    ::zr_boost_1_81::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::in_reference
                    >
                  , ::zr_boost_1_81::mpl::true_
                  , ::zr_boost_1_81::mpl::if_<
                        ::zr_boost_1_81::is_same<
                            typename Tag::qualifier
                          , ::zr_boost_1_81::parameter::forward_reference
                        >
                      , ::zr_boost_1_81::mpl::true_
                      , ::zr_boost_1_81::mpl::false_
                    >
                >
            >::type
#endif  // BOOST_PARAMETER_CAN_USE_MP11
          , ::zr_boost_1_81::parameter::aux::tag<Tag,T const>
        >::type
            operator=(T const&& x) const
        {
            typedef typename ::zr_boost_1_81::parameter::aux
            ::tag<Tag,T const>::type result;
            return result(::std::forward<T const>(x));
        }

        template <typename T>
        inline BOOST_CONSTEXPR typename ::zr_boost_1_81::lazy_enable_if<
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
            ::zr_boost_1_81::mp11::mp_if<
                ::std::is_scalar<T>
              , ::zr_boost_1_81::mp11::mp_false
              , ::zr_boost_1_81::mp11::mp_if<
                    ::std::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::consume_reference
                    >
                  , ::zr_boost_1_81::mp11::mp_true
                  , ::std::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::forward_reference
                    >
                >
            >
#else   // !defined(BOOST_PARAMETER_CAN_USE_MP11)
            typename ::zr_boost_1_81::mpl::eval_if<
                ::zr_boost_1_81::is_scalar<T>
              , ::zr_boost_1_81::mpl::false_
              , ::zr_boost_1_81::mpl::eval_if<
                    ::zr_boost_1_81::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::consume_reference
                    >
                  , ::zr_boost_1_81::mpl::true_
                  , ::zr_boost_1_81::mpl::if_<
                        ::zr_boost_1_81::is_same<
                            typename Tag::qualifier
                          , ::zr_boost_1_81::parameter::forward_reference
                        >
                      , ::zr_boost_1_81::mpl::true_
                      , ::zr_boost_1_81::mpl::false_
                    >
                >
            >::type
#endif  // BOOST_PARAMETER_CAN_USE_MP11
          , ::zr_boost_1_81::parameter::aux::tag<Tag,T>
        >::type
            operator=(T&& x) const
        {
            typedef typename ::zr_boost_1_81::parameter::aux::tag<Tag,T>::type result;
            return result(::std::forward<T>(x));
        }

        template <typename Default>
        inline BOOST_CONSTEXPR typename ::zr_boost_1_81::enable_if<
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
            ::zr_boost_1_81::mp11::mp_if<
                ::std::is_scalar<Default>
              , ::zr_boost_1_81::mp11::mp_false
              , ::zr_boost_1_81::mp11::mp_if<
                    ::std::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::in_reference
                    >
                  , ::zr_boost_1_81::mp11::mp_true
                  , ::std::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::forward_reference
                    >
                >
            >
#else   // !defined(BOOST_PARAMETER_CAN_USE_MP11)
            typename ::zr_boost_1_81::mpl::eval_if<
                ::zr_boost_1_81::is_scalar<Default>
              , ::zr_boost_1_81::mpl::false_
              , ::zr_boost_1_81::mpl::eval_if<
                    ::zr_boost_1_81::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::in_reference
                    >
                  , ::zr_boost_1_81::mpl::true_
                  , ::zr_boost_1_81::mpl::if_<
                        ::zr_boost_1_81::is_same<
                            typename Tag::qualifier
                          , ::zr_boost_1_81::parameter::forward_reference
                        >
                      , ::zr_boost_1_81::mpl::true_
                      , ::zr_boost_1_81::mpl::false_
                    >
                >
            >::type
#endif  // BOOST_PARAMETER_CAN_USE_MP11
          , ::zr_boost_1_81::parameter::aux::default_r_<Tag,Default const>
        >::type
            operator|(Default const&& d) const
        {
            return ::zr_boost_1_81::parameter::aux::default_r_<Tag,Default const>(
                ::std::forward<Default const>(d)
            );
        }

        template <typename Default>
        inline BOOST_CONSTEXPR typename ::zr_boost_1_81::enable_if<
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
            ::zr_boost_1_81::mp11::mp_if<
                ::std::is_scalar<Default>
              , ::zr_boost_1_81::mp11::mp_false
              , ::zr_boost_1_81::mp11::mp_if<
                    ::std::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::consume_reference
                    >
                  , ::zr_boost_1_81::mp11::mp_true
                  , ::std::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::forward_reference
                    >
                >
            >
#else   // !defined(BOOST_PARAMETER_CAN_USE_MP11)
            typename ::zr_boost_1_81::mpl::eval_if<
                ::zr_boost_1_81::is_scalar<Default>
              , ::zr_boost_1_81::mpl::false_
              , ::zr_boost_1_81::mpl::eval_if<
                    ::zr_boost_1_81::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::consume_reference
                    >
                  , ::zr_boost_1_81::mpl::true_
                  , ::zr_boost_1_81::mpl::if_<
                        ::zr_boost_1_81::is_same<
                            typename Tag::qualifier
                          , ::zr_boost_1_81::parameter::forward_reference
                        >
                      , ::zr_boost_1_81::mpl::true_
                      , ::zr_boost_1_81::mpl::false_
                    >
                >
            >::type
#endif  // BOOST_PARAMETER_CAN_USE_MP11
          , ::zr_boost_1_81::parameter::aux::default_r_<Tag,Default>
        >::type
            operator|(Default&& d) const
        {
            return ::zr_boost_1_81::parameter::aux
            ::default_r_<Tag,Default>(::std::forward<Default>(d));
        }

     public: // Insurance against ODR violations
        // Users will need to define their keywords in header files.  To
        // prevent ODR violations, it's important that the keyword used in
        // every instantiation of a function template is the same object.
        // We provide a reference to a common instance of each keyword
        // object and prevent construction by users.
        static ::zr_boost_1_81::parameter::keyword<Tag> const instance;

        // This interface is deprecated.
        static ::zr_boost_1_81::parameter::keyword<Tag>& get()
        {
            return const_cast< ::zr_boost_1_81::parameter::keyword<Tag>&>(instance);
        }
    };

    template <typename Tag>
    ::zr_boost_1_81::parameter::keyword<Tag> const ::zr_boost_1_81::parameter
    ::keyword<Tag>::instance = ::zr_boost_1_81::parameter::keyword<Tag>();
}} // namespace zr_boost_1_81::parameter

#else   // !defined(BOOST_PARAMETER_HAS_PERFECT_FORWARDING)

#if !defined(BOOST_NO_SFINAE)
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/is_scalar.hpp>
#include <boost/type_traits/is_const.hpp>
#endif  // BOOST_NO_SFINAE

namespace zr_boost_1_81 { namespace parameter {

    // Instances of unique specializations of keyword<...> serve to
    // associate arguments with parameter names.  For example:
    //
    //     struct rate_;             // parameter names
    //     struct skew_;
    //
    //     namespace
    //     {
    //         keyword<rate_> rate;  // keywords
    //         keyword<skew_> skew;
    //     }
    //
    //     ...
    //
    //     f(rate = 1, skew = 2.4);
    template <typename Tag>
    struct keyword
    {
        typedef Tag tag;

        inline BOOST_CONSTEXPR keyword()
        {
        }

        template <typename T>
#if defined(BOOST_NO_SFINAE)
        inline typename ::zr_boost_1_81::parameter::aux::tag<Tag,T const&>::type
#else
        inline BOOST_CONSTEXPR typename ::zr_boost_1_81::lazy_enable_if<
            typename ::zr_boost_1_81::mpl::eval_if<
                ::zr_boost_1_81::is_scalar<T>
              , ::zr_boost_1_81::mpl::true_
              , ::zr_boost_1_81::mpl::eval_if<
                    ::zr_boost_1_81::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::in_reference
                    >
                  , ::zr_boost_1_81::mpl::true_
                  , ::zr_boost_1_81::mpl::if_<
                        ::zr_boost_1_81::is_same<
                            typename Tag::qualifier
                          , ::zr_boost_1_81::parameter::forward_reference
                        >
                      , ::zr_boost_1_81::mpl::true_
                      , ::zr_boost_1_81::mpl::false_
                    >
                >
            >::type
          , ::zr_boost_1_81::parameter::aux::tag<Tag,T const&>
        >::type
#endif  // BOOST_NO_SFINAE
            operator=(T const& x) const
        {
            typedef typename ::zr_boost_1_81::parameter::aux
            ::tag<Tag,T const&>::type result;
            return result(x);
        }

        template <typename Default>
#if defined(BOOST_NO_SFINAE)
        inline ::zr_boost_1_81::parameter::aux::default_<Tag,Default const>
#else
        inline BOOST_CONSTEXPR typename ::zr_boost_1_81::enable_if<
            typename ::zr_boost_1_81::mpl::eval_if<
                ::zr_boost_1_81::is_scalar<Default>
              , ::zr_boost_1_81::mpl::true_
              , ::zr_boost_1_81::mpl::eval_if<
                    ::zr_boost_1_81::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::in_reference
                    >
                  , ::zr_boost_1_81::mpl::true_
                  , ::zr_boost_1_81::mpl::if_<
                        ::zr_boost_1_81::is_same<
                            typename Tag::qualifier
                          , ::zr_boost_1_81::parameter::forward_reference
                        >
                      , ::zr_boost_1_81::mpl::true_
                      , ::zr_boost_1_81::mpl::false_
                    >
                >
            >::type
          , ::zr_boost_1_81::parameter::aux::default_<Tag,Default const>
        >::type
#endif  // BOOST_NO_SFINAE
            operator|(Default const& d) const
        {
            return ::zr_boost_1_81::parameter::aux::default_<Tag,Default const>(d);
        }

        template <typename T>
#if defined(BOOST_NO_SFINAE)
        inline typename ::zr_boost_1_81::parameter::aux::tag<Tag,T&>::type
#else
        inline BOOST_CONSTEXPR typename ::zr_boost_1_81::lazy_enable_if<
            typename ::zr_boost_1_81::mpl::eval_if<
                typename ::zr_boost_1_81::mpl::if_<
                    ::zr_boost_1_81::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::out_reference
                    >
                  , ::zr_boost_1_81::mpl::true_
                  , ::zr_boost_1_81::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::forward_reference
                    >
                >::type
              , ::zr_boost_1_81::mpl::if_<
                    ::zr_boost_1_81::is_const<T>
                  , ::zr_boost_1_81::mpl::false_
                  , ::zr_boost_1_81::mpl::true_
                >
              , ::zr_boost_1_81::mpl::false_
            >::type
          , ::zr_boost_1_81::parameter::aux::tag<Tag,T&>
        >::type
#endif  // BOOST_NO_SFINAE
            operator=(T& x) const
        {
            typedef typename ::zr_boost_1_81::parameter::aux
            ::tag<Tag,T&>::type result;
            return result(x);
        }

        template <typename Default>
#if defined(BOOST_NO_SFINAE)
        inline ::zr_boost_1_81::parameter::aux::default_<Tag,Default>
#else
        inline BOOST_CONSTEXPR typename ::zr_boost_1_81::enable_if<
            typename ::zr_boost_1_81::mpl::eval_if<
                typename ::zr_boost_1_81::mpl::if_<
                    ::zr_boost_1_81::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::out_reference
                    >
                  , ::zr_boost_1_81::mpl::true_
                  , ::zr_boost_1_81::is_same<
                        typename Tag::qualifier
                      , ::zr_boost_1_81::parameter::forward_reference
                    >
                >::type
              , ::zr_boost_1_81::mpl::if_<
                    ::zr_boost_1_81::is_const<Default>
                  , ::zr_boost_1_81::mpl::false_
                  , ::zr_boost_1_81::mpl::true_
                >
              , ::zr_boost_1_81::mpl::false_
            >::type
          , ::zr_boost_1_81::parameter::aux::default_<Tag,Default>
        >::type
#endif  // BOOST_NO_SFINAE
            operator|(Default& d) const
        {
            return ::zr_boost_1_81::parameter::aux::default_<Tag,Default>(d);
        }

        template <typename Default>
        inline BOOST_CONSTEXPR
        ::zr_boost_1_81::parameter::aux::lazy_default<Tag,Default const>
            operator||(Default const& d) const
        {
            return ::zr_boost_1_81::parameter::aux
            ::lazy_default<Tag,Default const>(d);
        }

        template <typename Default>
        inline BOOST_CONSTEXPR
        ::zr_boost_1_81::parameter::aux::lazy_default<Tag,Default>
            operator||(Default& d) const
        {
            return ::zr_boost_1_81::parameter::aux::lazy_default<Tag,Default>(d);
        }

     public: // Insurance against ODR violations
        // Users will need to define their keywords in header files.  To
        // prevent ODR violations, it's important that the keyword used in
        // every instantiation of a function template is the same object.
        // We provide a reference to a common instance of each keyword
        // object and prevent construction by users.
        static ::zr_boost_1_81::parameter::keyword<Tag> const instance;

        // This interface is deprecated.
        static ::zr_boost_1_81::parameter::keyword<Tag>& get()
        {
            return const_cast< ::zr_boost_1_81::parameter::keyword<Tag>&>(instance);
        }
    };

    template <typename Tag>
    ::zr_boost_1_81::parameter::keyword<Tag> const ::zr_boost_1_81::parameter
    ::keyword<Tag>::instance = ::zr_boost_1_81::parameter::keyword<Tag>();
}} // namespace zr_boost_1_81::parameter

#endif  // BOOST_PARAMETER_HAS_PERFECT_FORWARDING

#include <boost/parameter/aux_/name.hpp>
#include <boost/preprocessor/stringize.hpp>

// Reduces boilerplate required to declare and initialize keywords without
// violating ODR.  Declares a keyword tag type with the given name in
// namespace tag_namespace, and declares and initializes a reference in an
// anonymous namespace to a singleton instance of that type.
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
#define BOOST_PARAMETER_KEYWORD(tag_namespace, name)                         \
    namespace tag_namespace                                                  \
    {                                                                        \
        struct name                                                          \
        {                                                                    \
            static BOOST_CONSTEXPR char const* keyword_name()                \
            {                                                                \
                return BOOST_PP_STRINGIZE(name);                             \
            }                                                                \
            using _ = BOOST_PARAMETER_TAG_PLACEHOLDER_TYPE(name);            \
            using _1 = _;                                                    \
            BOOST_PARAMETER_TAG_MP11_PLACEHOLDER_BINDING(binding_fn, name);  \
            BOOST_PARAMETER_TAG_MP11_PLACEHOLDER_VALUE(fn, name);            \
            using qualifier = ::zr_boost_1_81::parameter::forward_reference;         \
        };                                                                   \
    }                                                                        \
    namespace                                                                \
    {                                                                        \
        ::zr_boost_1_81::parameter::keyword<tag_namespace::name> const& name         \
            = ::zr_boost_1_81::parameter::keyword<tag_namespace::name>::instance;    \
    }
/**/
#else   // !defined(BOOST_PARAMETER_CAN_USE_MP11)
#define BOOST_PARAMETER_KEYWORD(tag_namespace, name)                         \
    namespace tag_namespace                                                  \
    {                                                                        \
        struct name                                                          \
        {                                                                    \
            static BOOST_CONSTEXPR char const* keyword_name()                \
            {                                                                \
                return BOOST_PP_STRINGIZE(name);                             \
            }                                                                \
            typedef BOOST_PARAMETER_TAG_PLACEHOLDER_TYPE(name) _;            \
            typedef BOOST_PARAMETER_TAG_PLACEHOLDER_TYPE(name) _1;           \
            typedef ::zr_boost_1_81::parameter::forward_reference qualifier;         \
        };                                                                   \
    }                                                                        \
    namespace                                                                \
    {                                                                        \
        ::zr_boost_1_81::parameter::keyword<tag_namespace::name> const& name         \
            = ::zr_boost_1_81::parameter::keyword<tag_namespace::name>::instance;    \
    }
/**/
#endif  // BOOST_PARAMETER_CAN_USE_MP11

#endif  // include guard

