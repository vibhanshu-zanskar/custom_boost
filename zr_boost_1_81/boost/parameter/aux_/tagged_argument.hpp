// Copyright Daniel Wallin, David Abrahams 2005.
// Copyright Cromwell D. Enage 2017.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PARAMETER_TAGGED_ARGUMENT_050328_HPP
#define BOOST_PARAMETER_TAGGED_ARGUMENT_050328_HPP

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    struct error_const_lvalue_bound_to_out_parameter;
    struct error_lvalue_bound_to_consume_parameter;
    struct error_rvalue_bound_to_out_parameter;
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/keyword_fwd.hpp>
#include <boost/parameter/config.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <boost/mp11/integral.hpp>
#include <boost/mp11/utility.hpp>
#include <type_traits>
#endif

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename Keyword, typename Arg>
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
    using tagged_argument_type = ::zr_boost_1_81::mp11::mp_if<
        ::zr_boost_1_81::mp11::mp_if<
            ::std::is_scalar<Arg>
          , ::zr_boost_1_81::mp11::mp_false
          , ::std::is_same<
                typename Keyword::qualifier
              , ::zr_boost_1_81::parameter::consume_reference
            >
        >
      , ::zr_boost_1_81::parameter::aux::error_lvalue_bound_to_consume_parameter
      , ::zr_boost_1_81::mp11::mp_if<
            ::std::is_const<Arg>
          , ::zr_boost_1_81::mp11::mp_if<
                ::std::is_same<
                    typename Keyword::qualifier
                  , ::zr_boost_1_81::parameter::out_reference
                >
              , ::zr_boost_1_81::parameter::aux
                ::error_const_lvalue_bound_to_out_parameter
              , ::std::remove_const<Arg>
            >
          , ::zr_boost_1_81::mp11::mp_identity<Arg>
        >
    >;
#else   // !defined(BOOST_PARAMETER_CAN_USE_MP11)
    struct tagged_argument_type
      : ::zr_boost_1_81::mpl::eval_if<
            ::zr_boost_1_81::is_same<
                typename Keyword::qualifier
              , ::zr_boost_1_81::parameter::out_reference
            >
          , ::zr_boost_1_81::parameter::aux::error_const_lvalue_bound_to_out_parameter
          , ::zr_boost_1_81::remove_const<Arg>
        >
    {
    };
#endif  // BOOST_PARAMETER_CAN_USE_MP11
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/aux_/tagged_argument_fwd.hpp>
#include <boost/parameter/aux_/is_tagged_argument.hpp>
#include <boost/parameter/aux_/default.hpp>
#include <boost/parameter/aux_/void.hpp>
#include <boost/parameter/aux_/arg_list.hpp>
#include <boost/parameter/aux_/result_of0.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/is_function.hpp>
#include <boost/type_traits/is_scalar.hpp>
#include <boost/type_traits/remove_reference.hpp>

#if defined(BOOST_NO_CXX11_HDR_FUNCTIONAL)
#include <boost/function.hpp>
#else
#include <functional>
#endif

#if defined(BOOST_PARAMETER_HAS_PERFECT_FORWARDING)
#include <boost/core/enable_if.hpp>
#include <utility>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    // Holds an lvalue reference to an argument of type Arg associated with
    // keyword Keyword
    template <typename Keyword, typename Arg>
    class tagged_argument
      : public ::zr_boost_1_81::parameter::aux::tagged_argument_base
    {
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
        using arg_type = typename ::zr_boost_1_81::parameter::aux
        ::tagged_argument_type<Keyword,Arg>::type;
#else
        typedef typename ::zr_boost_1_81::mpl::eval_if<
            typename ::zr_boost_1_81::mpl::eval_if<
                ::zr_boost_1_81::is_scalar<Arg>
              , ::zr_boost_1_81::mpl::false_
              , ::zr_boost_1_81::is_same<
                    typename Keyword::qualifier
                  , ::zr_boost_1_81::parameter::consume_reference
                >
            >::type
          , ::zr_boost_1_81::parameter::aux::error_lvalue_bound_to_consume_parameter
          , ::zr_boost_1_81::mpl::eval_if<
                ::zr_boost_1_81::is_const<Arg>
              , ::zr_boost_1_81::parameter::aux::tagged_argument_type<Keyword,Arg>
              , ::zr_boost_1_81::mpl::identity<Arg>
            >
        >::type arg_type;
#endif  // BOOST_PARAMETER_CAN_USE_MP11

     public:
        typedef Keyword key_type;

        // Wrap plain (non-UDT) function objects in either
        // a zr_boost_1_81::function or a std::function. -- Cromwell D. Enage
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
        using value_type = ::zr_boost_1_81::mp11::mp_if<
            ::std::is_function<arg_type>
          , ::std::function<arg_type>
          , Arg
        >;
#else   // !defined(BOOST_PARAMETER_CAN_USE_MP11)
        typedef typename ::zr_boost_1_81::mpl::if_<
            ::zr_boost_1_81::is_function<arg_type>
#if defined(BOOST_NO_CXX11_HDR_FUNCTIONAL)
          , ::zr_boost_1_81::function<arg_type>
#else
          , ::std::function<arg_type>
#endif
          , Arg
        >::type value_type;
#endif  // BOOST_PARAMETER_CAN_USE_MP11

        // If Arg is void_, then this type will evaluate to void_&.  If the
        // supplied argument is a plain function, then this type will evaluate
        // to a reference-to-const function wrapper type.  If the supplied
        // argument is an lvalue, then Arg will be deduced to the lvalue
        // reference. -- Cromwell D. Enage
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
        using reference = ::zr_boost_1_81::mp11::mp_if<
            ::std::is_function<arg_type>
          , value_type const&
          , Arg&
        >;
#else
        typedef typename ::zr_boost_1_81::mpl::if_<
            ::zr_boost_1_81::is_function<arg_type>
          , value_type const&
          , Arg&
        >::type reference;
#endif

     private:
        // Store plain functions by value, everything else by reference.
        // -- Cromwell D. Enage
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
        ::zr_boost_1_81::mp11::mp_if<
            ::std::is_function<arg_type>
          , value_type
          , reference
        > value;
#else
        typename ::zr_boost_1_81::mpl::if_<
            ::zr_boost_1_81::is_function<arg_type>
          , value_type
          , reference
        >::type value;
#endif

     public:
        inline explicit BOOST_CONSTEXPR tagged_argument(reference x)
          : value(x)
        {
        }

        inline BOOST_CONSTEXPR tagged_argument(tagged_argument const& copy)
          : value(copy.value)
        {
        }

        // A metafunction class that, given a keyword and a default type,
        // returns the appropriate result type for a keyword lookup given
        // that default.
        struct binding
        {
            template <typename KW, typename Default, typename Reference>
            struct apply
              : ::zr_boost_1_81::mpl::eval_if<
                    ::zr_boost_1_81::is_same<KW,key_type>
                  , ::zr_boost_1_81::mpl::if_<Reference,reference,value_type>
                  , ::zr_boost_1_81::mpl::identity<Default>
                >
            {
            };

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
            template <typename KW, typename Default, typename Reference>
            using fn = ::zr_boost_1_81::mp11::mp_if<
                ::std::is_same<KW,key_type>
              , ::zr_boost_1_81::mp11::mp_if<Reference,reference,value_type>
              , Default
            >;
#endif
        };

#if !defined(BOOST_PARAMETER_CAN_USE_MP11)
        // Comma operator to compose argument list without using parameters<>.
        // Useful for argument lists with undetermined length.
        template <typename Keyword2, typename Arg2>
        inline BOOST_CONSTEXPR ::zr_boost_1_81::parameter::aux::arg_list<
            ::zr_boost_1_81::parameter::aux::tagged_argument<Keyword,Arg>
          , ::zr_boost_1_81::parameter::aux::arg_list<
                ::zr_boost_1_81::parameter::aux::tagged_argument<Keyword2,Arg2>
            >
        >
            operator,(
                ::zr_boost_1_81::parameter::aux
                ::tagged_argument<Keyword2,Arg2> const& x
            ) const
        {
            return ::zr_boost_1_81::parameter::aux::arg_list<
                ::zr_boost_1_81::parameter::aux::tagged_argument<Keyword,Arg>
              , ::zr_boost_1_81::parameter::aux::arg_list<
                    ::zr_boost_1_81::parameter::aux::tagged_argument<Keyword2,Arg2>
                >
            >(
                *this
              , ::zr_boost_1_81::parameter::aux::arg_list<
                    ::zr_boost_1_81::parameter::aux::tagged_argument<Keyword2,Arg2>
                >(x, ::zr_boost_1_81::parameter::aux::empty_arg_list())
            );
        }

        template <typename Keyword2, typename Arg2>
        inline BOOST_CONSTEXPR ::zr_boost_1_81::parameter::aux::arg_list<
            ::zr_boost_1_81::parameter::aux::tagged_argument<Keyword,Arg>
          , ::zr_boost_1_81::parameter::aux::arg_list<
                ::zr_boost_1_81::parameter::aux::tagged_argument_rref<Keyword2,Arg2>
            >
        >
            operator,(
                ::zr_boost_1_81::parameter::aux
                ::tagged_argument_rref<Keyword2,Arg2> const& x
            ) const
        {
            return ::zr_boost_1_81::parameter::aux::arg_list<
                ::zr_boost_1_81::parameter::aux::tagged_argument<Keyword,Arg>
              , zr_boost_1_81::parameter::aux::arg_list<
                    zr_boost_1_81::parameter::aux::tagged_argument_rref<Keyword2,Arg2>
                >
            >(
                *this
              , ::zr_boost_1_81::parameter::aux::arg_list<
                    ::zr_boost_1_81::parameter::aux
                    ::tagged_argument_rref<Keyword2,Arg2>
                >(x, ::zr_boost_1_81::parameter::aux::empty_arg_list())
            );
        }
#endif  // BOOST_PARAMETER_CAN_USE_MP11

        // Accessor interface.
        inline BOOST_CONSTEXPR reference get_value() const
        {
            return this->value;
        }

        inline BOOST_CONSTEXPR reference
            operator[](::zr_boost_1_81::parameter::keyword<Keyword> const&) const
        {
            return this->get_value();
        }

        template <typename Default>
        inline BOOST_CONSTEXPR reference
            operator[](
                ::zr_boost_1_81::parameter::aux::default_<key_type,Default> const&
            ) const
        {
            return this->get_value();
        }

        template <typename Default>
        inline BOOST_CONSTEXPR reference
            operator[](
                ::zr_boost_1_81::parameter::aux::default_r_<key_type,Default> const&
            ) const
        {
            return this->get_value();
        }

        template <typename F>
        inline BOOST_CONSTEXPR reference
            operator[](
                ::zr_boost_1_81::parameter::aux::lazy_default<key_type,F> const&
            ) const
        {
            return this->get_value();
        }

        template <typename KW, typename Default>
        inline BOOST_CONSTEXPR Default&
            operator[](
                ::zr_boost_1_81::parameter::aux::default_<KW,Default> const& x
            ) const
        {
            return x.value;
        }

        template <typename KW, typename Default>
        inline BOOST_CONSTEXPR Default&&
            operator[](
                ::zr_boost_1_81::parameter::aux::default_r_<KW,Default> const& x
            ) const
        {
            return ::std::forward<Default>(x.value);
        }

        template <typename KW, typename F>
        inline BOOST_CONSTEXPR
        typename ::zr_boost_1_81::parameter::aux::result_of0<F>::type
            operator[](
                ::zr_boost_1_81::parameter::aux::lazy_default<KW,F> const& x
            ) const
        {
            return x.compute_default();
        }

        template <typename ParameterRequirements>
        static BOOST_CONSTEXPR typename ParameterRequirements::has_default
            satisfies(ParameterRequirements*);

        template <typename HasDefault, typename Predicate>
        static BOOST_CONSTEXPR
        typename ::zr_boost_1_81::mpl::apply_wrap1<Predicate,value_type>::type
            satisfies(
                ::zr_boost_1_81::parameter::aux::parameter_requirements<
                    key_type
                  , Predicate
                  , HasDefault
                >*
            );

        // MPL sequence support
        // Convenience for users
        typedef ::zr_boost_1_81::parameter::aux::tagged_argument<Keyword,Arg> type;
        // For the benefit of iterators
        typedef ::zr_boost_1_81::parameter::aux::empty_arg_list tail_type;
        // For dispatching to sequence intrinsics
        typedef ::zr_boost_1_81::parameter::aux::arg_list_tag tag;
    };

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
    template <typename Keyword>
    using tagged_argument_rref_key = ::zr_boost_1_81::mp11::mp_if<
        ::std::is_same<
            typename Keyword::qualifier
          , ::zr_boost_1_81::parameter::out_reference
        >
      , ::zr_boost_1_81::parameter::aux::error_rvalue_bound_to_out_parameter
      , ::zr_boost_1_81::mp11::mp_identity<Keyword>
    >;
#endif

    // Holds an rvalue reference to an argument of type Arg associated with
    // keyword Keyword
    template <typename Keyword, typename Arg>
    struct tagged_argument_rref
      : ::zr_boost_1_81::parameter::aux::tagged_argument_base
    {
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
        using key_type = typename ::zr_boost_1_81::parameter::aux
        ::tagged_argument_rref_key<Keyword>::type;
#else
        typedef typename ::zr_boost_1_81::mpl::eval_if<
            ::zr_boost_1_81::is_same<
                typename Keyword::qualifier
              , ::zr_boost_1_81::parameter::out_reference
            >
          , ::zr_boost_1_81::parameter::aux::error_rvalue_bound_to_out_parameter
          , ::zr_boost_1_81::mpl::identity<Keyword>
        >::type key_type;
#endif
        typedef Arg value_type;
        typedef Arg&& reference;

     private:
        reference value;

     public:
        inline explicit BOOST_CONSTEXPR tagged_argument_rref(reference x)
          : value(::std::forward<Arg>(x))
        {
        }

        inline BOOST_CONSTEXPR tagged_argument_rref(
            tagged_argument_rref const& copy
        ) : value(::std::forward<Arg>(copy.value))
        {
        }

        // A metafunction class that, given a keyword and a default type,
        // returns the appropriate result type for a keyword lookup given
        // that default.
        struct binding
        {
            template <typename KW, typename Default, typename Reference>
            struct apply
            {
                typedef typename ::zr_boost_1_81::mpl::eval_if<
                    ::zr_boost_1_81::is_same<KW,key_type>
                  , ::zr_boost_1_81::mpl::if_<Reference,reference,value_type>
                  , ::zr_boost_1_81::mpl::identity<Default>
                >::type type;
            };

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
            template <typename KW, typename Default, typename Reference>
            using fn = ::zr_boost_1_81::mp11::mp_if<
                ::std::is_same<KW,key_type>
              , ::zr_boost_1_81::mp11::mp_if<Reference,reference,value_type>
              , Default
            >;
#endif
        };

#if !defined(BOOST_PARAMETER_CAN_USE_MP11)
        // Comma operator to compose argument list without using parameters<>.
        // Useful for argument lists with undetermined length.
        template <typename Keyword2, typename Arg2>
        inline BOOST_CONSTEXPR ::zr_boost_1_81::parameter::aux::arg_list<
            ::zr_boost_1_81::parameter::aux::tagged_argument_rref<Keyword,Arg>
          , ::zr_boost_1_81::parameter::aux::arg_list<
                ::zr_boost_1_81::parameter::aux::tagged_argument<Keyword2,Arg2>
            >
        >
            operator,(
                ::zr_boost_1_81::parameter::aux
                ::tagged_argument<Keyword2,Arg2> const& x
            ) const
        {
            return zr_boost_1_81::parameter::aux::arg_list<
                ::zr_boost_1_81::parameter::aux::tagged_argument_rref<Keyword,Arg>
              , ::zr_boost_1_81::parameter::aux::arg_list<
                    ::zr_boost_1_81::parameter::aux::tagged_argument<Keyword2,Arg2>
                >
            >(
                *this
              , ::zr_boost_1_81::parameter::aux::arg_list<
                    ::zr_boost_1_81::parameter::aux::tagged_argument<Keyword2,Arg2>
                >(x, ::zr_boost_1_81::parameter::aux::empty_arg_list())
            );
        }

        template <typename Keyword2, typename Arg2>
        inline BOOST_CONSTEXPR ::zr_boost_1_81::parameter::aux::arg_list<
            ::zr_boost_1_81::parameter::aux::tagged_argument_rref<Keyword,Arg>
          , ::zr_boost_1_81::parameter::aux::arg_list<
                ::zr_boost_1_81::parameter::aux::tagged_argument_rref<Keyword2,Arg2>
            >
        >
            operator,(
                ::zr_boost_1_81::parameter::aux
                ::tagged_argument_rref<Keyword2,Arg2> const& x
            ) const
        {
            return ::zr_boost_1_81::parameter::aux::arg_list<
                ::zr_boost_1_81::parameter::aux::tagged_argument_rref<Keyword,Arg>
              , ::zr_boost_1_81::parameter::aux::arg_list<
                    ::zr_boost_1_81::parameter::aux
                    ::tagged_argument_rref<Keyword2,Arg2>
                >
            >(
                *this
              , ::zr_boost_1_81::parameter::aux::arg_list<
                    ::zr_boost_1_81::parameter::aux::tagged_argument_rref<
                        Keyword2
                      , Arg2
                    >
                >(x, ::zr_boost_1_81::parameter::aux::empty_arg_list())
            );
        }
#endif  // BOOST_PARAMETER_CAN_USE_MP11

        // Accessor interface.
        inline BOOST_CONSTEXPR reference get_value() const
        {
            return ::std::forward<Arg>(this->value);
        }

        inline BOOST_CONSTEXPR reference
            operator[](::zr_boost_1_81::parameter::keyword<Keyword> const&) const
        {
            return this->get_value();
        }

        template <typename Default>
        inline BOOST_CONSTEXPR reference
            operator[](
                ::zr_boost_1_81::parameter::aux::default_<key_type,Default> const&
            ) const
        {
            return this->get_value();
        }

        template <typename Default>
        inline BOOST_CONSTEXPR reference
            operator[](
                ::zr_boost_1_81::parameter::aux::default_r_<key_type,Default> const&
            ) const
        {
            return this->get_value();
        }

        template <typename F>
        inline BOOST_CONSTEXPR reference
            operator[](
                ::zr_boost_1_81::parameter::aux::lazy_default<key_type,F> const&
            ) const
        {
            return this->get_value();
        }

        template <typename KW, typename Default>
        inline BOOST_CONSTEXPR Default&
            operator[](
                ::zr_boost_1_81::parameter::aux::default_<KW,Default> const& x
            ) const
        {
            return x.value;
        }

        template <typename KW, typename Default>
        inline BOOST_CONSTEXPR Default&&
            operator[](
                ::zr_boost_1_81::parameter::aux::default_r_<KW,Default> const& x
            ) const
        {
            return ::std::forward<Default>(x.value);
        }

        template <typename KW, typename F>
        inline BOOST_CONSTEXPR
        typename ::zr_boost_1_81::parameter::aux::result_of0<F>::type
            operator[](
                ::zr_boost_1_81::parameter::aux::lazy_default<KW,F> const& x
            ) const
        {
            return x.compute_default();
        }

        template <typename ParameterRequirements>
        static BOOST_CONSTEXPR typename ParameterRequirements::has_default
            satisfies(ParameterRequirements*);

        template <typename HasDefault, typename Predicate>
        static BOOST_CONSTEXPR
        typename ::zr_boost_1_81::mpl::apply_wrap1<Predicate,value_type>::type
            satisfies(
                ::zr_boost_1_81::parameter::aux::parameter_requirements<
                    key_type
                  , Predicate
                  , HasDefault
                >*
            );

        // MPL sequence support
        // Convenience for users
        typedef ::zr_boost_1_81::parameter::aux
        ::tagged_argument_rref<Keyword,Arg> type;
        // For the benefit of iterators
        typedef ::zr_boost_1_81::parameter::aux::empty_arg_list tail_type;
        // For dispatching to sequence intrinsics
        typedef ::zr_boost_1_81::parameter::aux::arg_list_tag tag;
    };
}}} // namespace zr_boost_1_81::parameter::aux

#else   // !defined(BOOST_PARAMETER_HAS_PERFECT_FORWARDING)

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    // Holds an lvalue reference to an argument of type Arg associated with
    // keyword Keyword
    template <typename Keyword, typename Arg>
    class tagged_argument
      : public ::zr_boost_1_81::parameter::aux::tagged_argument_base
    {
        typedef typename ::zr_boost_1_81::remove_const<Arg>::type arg_type;

     public:
        typedef Keyword key_type;

        // Wrap plain (non-UDT) function objects in either
        // a zr_boost_1_81::function or a std::function. -- Cromwell D. Enage
        typedef typename ::zr_boost_1_81::mpl::if_<
            ::zr_boost_1_81::is_function<arg_type>
#if defined(BOOST_NO_CXX11_HDR_FUNCTIONAL)
          , ::zr_boost_1_81::function<arg_type>
#else
          , ::std::function<arg_type>
#endif
          , Arg
        >::type value_type;

        // If Arg is void_, then this type will evaluate to void_&.  If the
        // supplied argument is a plain function, then this type will evaluate
        // to a reference-to-const function wrapper type.  If the supplied
        // argument is an lvalue, then Arg will be deduced to the lvalue
        // reference. -- Cromwell D. Enage
        typedef typename ::zr_boost_1_81::mpl::if_<
            ::zr_boost_1_81::is_function<arg_type>
          , value_type const&
          , Arg&
        >::type reference;

     private:
        // Store plain functions by value, everything else by reference.
        // -- Cromwell D. Enage
        typename ::zr_boost_1_81::mpl::if_<
            ::zr_boost_1_81::is_function<arg_type>
          , value_type
          , reference
        >::type value;

     public:
        inline explicit BOOST_CONSTEXPR tagged_argument(reference x)
          : value(x)
        {
        }

        inline BOOST_CONSTEXPR tagged_argument(tagged_argument const& copy)
          : value(copy.value)
        {
        }

        // A metafunction class that, given a keyword and a default type,
        // returns the appropriate result type for a keyword lookup given
        // that default.
        struct binding
        {
            template <typename KW, typename Default, typename Reference>
            struct apply
            {
                typedef typename ::zr_boost_1_81::mpl::eval_if<
                    ::zr_boost_1_81::is_same<KW,key_type>
                  , ::zr_boost_1_81::mpl::if_<Reference,reference,value_type>
                  , ::zr_boost_1_81::mpl::identity<Default>
                >::type type;
            };
        };

        // Comma operator to compose argument list without using parameters<>.
        // Useful for argument lists with undetermined length.
        template <typename Keyword2, typename Arg2>
        inline ::zr_boost_1_81::parameter::aux::arg_list<
            ::zr_boost_1_81::parameter::aux::tagged_argument<Keyword,Arg>
          , ::zr_boost_1_81::parameter::aux::arg_list<
                ::zr_boost_1_81::parameter::aux::tagged_argument<Keyword2,Arg2>
            >
        >
            operator,(
                ::zr_boost_1_81::parameter::aux
                ::tagged_argument<Keyword2,Arg2> const& x
            ) const
        {
            return ::zr_boost_1_81::parameter::aux::arg_list<
                ::zr_boost_1_81::parameter::aux::tagged_argument<Keyword,Arg>
              , ::zr_boost_1_81::parameter::aux::arg_list<
                    ::zr_boost_1_81::parameter::aux::tagged_argument<Keyword2,Arg2>
                >
            >(
                *this
              , ::zr_boost_1_81::parameter::aux::arg_list<
                    ::zr_boost_1_81::parameter::aux::tagged_argument<Keyword2,Arg2>
                >(x, ::zr_boost_1_81::parameter::aux::empty_arg_list())
            );
        }

        // Accessor interface.
        inline BOOST_CONSTEXPR reference get_value() const
        {
            return this->value;
        }

        inline BOOST_CONSTEXPR reference
            operator[](::zr_boost_1_81::parameter::keyword<Keyword> const&) const
        {
            return this->get_value();
        }

#if defined(BOOST_NO_FUNCTION_TEMPLATE_ORDERING) || \
    BOOST_WORKAROUND(BOOST_BORLANDC, BOOST_TESTED_AT(0x564))
        template <typename KW, typename Default>
        inline BOOST_CONSTEXPR Default&
            get_with_default(
                ::zr_boost_1_81::parameter::aux::default_<KW,Default> const& x
              , int
            ) const
        {
            return x.value;
        }

        template <typename Default>
        inline BOOST_CONSTEXPR reference
            get_with_default(
                ::zr_boost_1_81::parameter::aux::default_<key_type,Default> const&
              , long
            ) const
        {
            return this->get_value();
        }

        template <typename KW, typename Default>
        inline BOOST_CONSTEXPR typename ::zr_boost_1_81::mpl::apply_wrap3<
            binding
          , KW
          , Default&
          , ::zr_boost_1_81::mpl::true_
        >::type
            operator[](
                ::zr_boost_1_81::parameter::aux::default_<KW,Default> const& x
            ) const
        {
            return this->get_with_default(x, 0L);
        }

        template <typename KW, typename F>
        inline BOOST_CONSTEXPR
        typename ::zr_boost_1_81::parameter::aux::result_of0<F>::type
            get_with_lazy_default(
                ::zr_boost_1_81::parameter::aux::lazy_default<KW,F> const& x
              , int
            ) const
        {
            return x.compute_default();
        }

        template <typename F>
        inline BOOST_CONSTEXPR reference
            get_with_lazy_default(
                ::zr_boost_1_81::parameter::aux::lazy_default<key_type,F> const&
              , long
            ) const
        {
            return this->get_value();
        }

        template <typename KW, typename F>
        inline BOOST_CONSTEXPR typename ::zr_boost_1_81::mpl::apply_wrap3<
            binding
          , KW
          , typename ::zr_boost_1_81::parameter::aux::result_of0<F>::type
          , ::zr_boost_1_81::mpl::true_
        >::type
            operator[](
                ::zr_boost_1_81::parameter::aux::lazy_default<KW,F> const& x
            ) const
        {
            return this->get_with_lazy_default(x, 0L);
        }
#else   // No function template ordering or Borland workarounds needed.
        template <typename Default>
        inline BOOST_CONSTEXPR reference
            operator[](
                ::zr_boost_1_81::parameter::aux::default_<key_type,Default> const&
            ) const
        {
            return this->get_value();
        }

        template <typename F>
        inline BOOST_CONSTEXPR reference
            operator[](
                ::zr_boost_1_81::parameter::aux::lazy_default<key_type,F> const&
            ) const
        {
            return this->get_value();
        }

        template <typename KW, typename Default>
        inline BOOST_CONSTEXPR Default&
            operator[](
                ::zr_boost_1_81::parameter::aux::default_<KW,Default> const& x
            ) const
        {
            return x.value;
        }

        template <typename KW, typename F>
        inline BOOST_CONSTEXPR
        typename ::zr_boost_1_81::parameter::aux::result_of0<F>::type
            operator[](
                ::zr_boost_1_81::parameter::aux::lazy_default<KW,F> const& x
            ) const
        {
            return x.compute_default();
        }

        template <typename ParameterRequirements>
        static BOOST_CONSTEXPR typename ParameterRequirements::has_default
            satisfies(ParameterRequirements*);

        template <typename HasDefault, typename Predicate>
        static BOOST_CONSTEXPR
        typename ::zr_boost_1_81::mpl::apply_wrap1<Predicate,value_type>::type
            satisfies(
                ::zr_boost_1_81::parameter::aux::parameter_requirements<
                    key_type
                  , Predicate
                  , HasDefault
                >*
            );
#endif  // Function template ordering, Borland workarounds needed.

        // MPL sequence support
        // Convenience for users
        typedef ::zr_boost_1_81::parameter::aux::tagged_argument<Keyword,Arg> type;
        // For the benefit of iterators
        typedef ::zr_boost_1_81::parameter::aux::empty_arg_list tail_type;
        // For dispatching to sequence intrinsics
        typedef ::zr_boost_1_81::parameter::aux::arg_list_tag tag;

#if BOOST_WORKAROUND(BOOST_MSVC, BOOST_TESTED_AT(1310))
        // warning suppression
     private:
        void operator=(type const&);
#endif
    };
}}} // namespace zr_boost_1_81::parameter::aux

#endif  // BOOST_PARAMETER_HAS_PERFECT_FORWARDING

#if defined(BOOST_PARAMETER_CAN_USE_MP11)

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename TaggedArg>
    struct tagged_argument_list_of_1 : public TaggedArg
    {
        using base_type = TaggedArg;

        inline explicit BOOST_CONSTEXPR tagged_argument_list_of_1(
            typename base_type::reference x
        ) : base_type(static_cast<typename base_type::reference>(x))
        {
        }

        inline BOOST_CONSTEXPR tagged_argument_list_of_1(
            tagged_argument_list_of_1 const& copy
        ) : base_type(static_cast<base_type const&>(copy))
        {
        }

        using base_type::operator[];
        using base_type::satisfies;

        template <typename TA2>
        inline BOOST_CONSTEXPR ::zr_boost_1_81::parameter::aux::flat_like_arg_list<
            ::zr_boost_1_81::parameter::aux
            ::flat_like_arg_tuple<typename TaggedArg::key_type,TaggedArg>
          , ::zr_boost_1_81::parameter::aux::flat_like_arg_tuple<
                typename TA2::base_type::key_type
              , typename TA2::base_type
            >
        >
            operator,(TA2 const& x) const
        {
            return zr_boost_1_81::parameter::aux::flat_like_arg_list<
                ::zr_boost_1_81::parameter::aux
                ::flat_like_arg_tuple<typename TaggedArg::key_type,TaggedArg>
              , ::zr_boost_1_81::parameter::aux::flat_like_arg_tuple<
                    typename TA2::base_type::key_type
                  , typename TA2::base_type
                >
            >(
                static_cast<base_type const&>(*this)
              , ::zr_boost_1_81::parameter::aux::arg_list<typename TA2::base_type>(
                    static_cast<typename TA2::base_type const&>(x)
                  , ::zr_boost_1_81::parameter::aux::empty_arg_list()
                )
            );
        }
    };
}}} // namespace zr_boost_1_81::parameter::aux

#endif  // BOOST_PARAMETER_CAN_USE_MP11
#endif  // include guard

