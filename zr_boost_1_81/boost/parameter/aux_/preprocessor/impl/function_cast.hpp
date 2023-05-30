// Copyright Daniel Wallin 2006.
// Copyright Cromwell D. Enage 2017.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PARAMETER_AUX_PREPROCESSOR_IMPL_FUNCTION_CAST_HPP
#define BOOST_PARAMETER_AUX_PREPROCESSOR_IMPL_FUNCTION_CAST_HPP

#include <boost/parameter/config.hpp>

#if defined(BOOST_PARAMETER_HAS_PERFECT_FORWARDING)

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    // Handles possible implicit casts.  Used by preprocessor.hpp
    // to normalize user input.
    //
    // cast<void*>::execute() is identity
    // cast<void*(X)>::execute() is identity
    // cast<void(X)>::execute() casts to X
    //
    // preprocessor.hpp uses this like this:
    //
    //     #define X(value, predicate)
    //         cast<void predicate>::execute(value)
    //
    //     X(something, *)
    //     X(something, *(predicate))
    //     X(something, (int))
    template <typename VoidExpr, typename Args>
    struct cast;
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/aux_/use_default_tag.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename T, typename B>
    inline ::zr_boost_1_81::parameter::aux::use_default_tag
        forward(::zr_boost_1_81::parameter::aux::use_default_tag)
    {
        return ::zr_boost_1_81::parameter::aux::use_default_tag();
    }
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <boost/mp11/integral.hpp>
#include <boost/mp11/utility.hpp>
#endif

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename Args>
    struct cast<void*,Args>
    {
        template <typename T, typename B>
        struct apply
        {
            typedef typename ::zr_boost_1_81::mpl
            ::if_<B,T,::zr_boost_1_81::mpl::true_>::type type;
        };

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
        template <typename T, typename B>
        using fn = ::zr_boost_1_81::mp11::mp_if<B,T,::zr_boost_1_81::mp11::mp_true>;
#endif
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/aux_/void.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename Predicate, typename Args>
    struct cast<void*(Predicate),Args>
      : ::zr_boost_1_81::parameter::aux::cast<void*,Args>
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/mpl/placeholders.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    // This is a hack used in cast<> to turn the user supplied type,
    // which may or may not be a placeholder expression, into one,
    // so that it will be properly evaluated by mpl::apply.
    template <typename T, typename Dummy = ::zr_boost_1_81::mpl::_1>
    struct as_placeholder_expr
    {
        typedef T type;
    };
}}} // namespace zr_boost_1_81::parameter::aux

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <boost/mp11/list.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename Target, typename Source, typename Args>
    struct apply_target_fn
    {
        using type = ::zr_boost_1_81::mp11
        ::mp_apply_q<Target,::zr_boost_1_81::mp11::mp_list<Source,Args> >;
    };
}}} // namespace zr_boost_1_81::parameter::aux

#endif

#include <boost/mpl/apply.hpp>

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <boost/parameter/aux_/has_nested_template_fn.hpp>
#include <type_traits>
#else
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#endif

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename Target, typename Source, typename Args>
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
    using is_target_same_as_source = ::std::is_same<
        typename ::std::remove_const<
            typename ::std::remove_reference<
                typename ::zr_boost_1_81::mp11::mp_if<
                    ::zr_boost_1_81::parameter::aux::has_nested_template_fn<Target>
                  , ::zr_boost_1_81::parameter::aux
                    ::apply_target_fn<Target,Source,Args>
                  , ::zr_boost_1_81::mpl::apply2<
                        ::zr_boost_1_81::parameter::aux::as_placeholder_expr<Target>
                      , Source
                      , Args
                    >
                >::type
            >::type
        >::type
      , typename ::std::remove_const<Source>::type
    >;
#else   // !defined(BOOST_PARAMETER_CAN_USE_MP11)
    struct is_target_same_as_source
      : ::zr_boost_1_81::mpl::if_<
            ::zr_boost_1_81::is_same<
                typename ::zr_boost_1_81::remove_const<
                    typename ::zr_boost_1_81::remove_reference<
                        typename ::zr_boost_1_81::mpl::apply2<
                            ::zr_boost_1_81::parameter::aux
                            ::as_placeholder_expr<Target>
                          , Source
                          , Args
                        >::type
                    >::type
                >::type
              , typename ::zr_boost_1_81::remove_const<Source>::type
            >
          , ::zr_boost_1_81::mpl::true_
          , ::zr_boost_1_81::mpl::false_
        >::type
    {
    };
#endif  // BOOST_PARAMETER_CAN_USE_MP11
}}} // namespace zr_boost_1_81::parameter::aux

#if !defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/is_const.hpp>
#endif

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    // Covers the case where is_convertible<Source,Target> but not
    // is_same<Source,Target>.  Use cases are covered
    // by test/normalize_argument_types.cpp
    template <typename Source, typename Target>
    class cast_convert
    {
        typedef ::zr_boost_1_81::parameter::aux::cast_convert<Source,Target> _self;

     public:
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
        using type = typename ::zr_boost_1_81::mp11::mp_if<
            ::std::is_const<Source>
          , ::std::add_const<Target>
          , ::std::remove_const<Target>
        >::type;
#else
        typedef typename zr_boost_1_81::mpl::eval_if<
            ::zr_boost_1_81::is_const<Source>
          , ::zr_boost_1_81::add_const<Target>
          , ::zr_boost_1_81::remove_const<Target>
        >::type type;
#endif

     private:
        inline static typename _self::type
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
            _copy(typename ::std::remove_const<Target>::type value)
#else
            _copy(typename ::zr_boost_1_81::remove_const<Target>::type value)
#endif
        {
            return value;
        }

     public:
        inline static typename _self::type evaluate(Source&& source)
        {
            return _self::_copy(source);
        }
    };

    template <typename Target, typename Source, typename Args>
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
    using cast_impl = ::std::remove_reference<
        typename ::zr_boost_1_81::mp11::mp_if<
            ::zr_boost_1_81::parameter::aux::has_nested_template_fn<Target>
          , ::zr_boost_1_81::parameter::aux
            ::is_target_same_as_source<Target,Source,Args>
          , ::zr_boost_1_81::mpl::apply2<
                ::zr_boost_1_81::parameter::aux::as_placeholder_expr<Target>
              , Source
              , Args
            >
        >::type
    >;
#else
    struct cast_impl
      : ::zr_boost_1_81::remove_reference<
            typename ::zr_boost_1_81::mpl::apply2<
                ::zr_boost_1_81::parameter::aux::as_placeholder_expr<Target>
              , Source
              , Args
            >::type
        >
    {
    };
#endif  // BOOST_PARAMETER_CAN_USE_MP11
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename Target, typename Args>
    struct cast<void(Target),Args>
    {
        template <typename T, typename B>
        struct apply
        {
            typedef typename ::zr_boost_1_81::mpl::eval_if<
                B
              , ::zr_boost_1_81::mpl::eval_if<
                    ::zr_boost_1_81::parameter::aux
                    ::is_target_same_as_source<Target,T,Args>
                  , ::zr_boost_1_81::mpl::identity<T>
                  , ::zr_boost_1_81::parameter::aux::cast_impl<Target,T,Args>
                >
              , ::zr_boost_1_81::parameter::aux
                ::is_target_same_as_source<Target,T,Args>
            >::type type;
        };

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
        template <typename T, typename B>
        using fn = typename ::zr_boost_1_81::mp11::mp_if<
            B
          , ::zr_boost_1_81::mp11::mp_if<
                ::zr_boost_1_81::parameter::aux
                ::is_target_same_as_source<Target,T,Args>
              , ::zr_boost_1_81::mp11::mp_identity<T>
              , ::zr_boost_1_81::parameter::aux::cast_impl<Target,T,Args>
            >
          , ::zr_boost_1_81::parameter::aux
            ::is_target_same_as_source<Target,T,Args>
        >::type;
#endif
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/value_type.hpp>

#if !defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <boost/mpl/apply_wrap.hpp>
#endif

// Expands to the target type of the argument as indicated by the predicate.
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
#define BOOST_PARAMETER_FUNCTION_CAST_T(tag, predicate, args)                \
    ::zr_boost_1_81::mp11::mp_apply_q<                                               \
        ::zr_boost_1_81::parameter::aux::cast<void predicate, args>                  \
      , ::zr_boost_1_81::mp11::mp_list<                                              \
            typename ::zr_boost_1_81::parameter::value_type<                         \
                args                                                         \
              , tag                                                          \
              , ::zr_boost_1_81::parameter::aux::use_default_tag                     \
            >::type                                                          \
          , ::zr_boost_1_81::mp11::mp_true                                           \
        >                                                                    \
    >
/**/
#else   // !defined(BOOST_PARAMETER_CAN_USE_MP11)
#define BOOST_PARAMETER_FUNCTION_CAST_T(tag, predicate, args)                \
    typename ::zr_boost_1_81::mpl::apply_wrap2<                                      \
        ::zr_boost_1_81::parameter::aux::cast<void predicate, args>                  \
      , typename ::zr_boost_1_81::parameter::value_type<                             \
            args                                                             \
          , tag                                                              \
          , ::zr_boost_1_81::parameter::aux::use_default_tag                         \
        >::type                                                              \
      , ::zr_boost_1_81::mpl::true_                                                  \
    >::type
/**/
#endif  // BOOST_PARAMETER_CAN_USE_MP11

// Expands to zr_boost_1_81::mpl::true_ if and only if the argument's source and
// target types are the same.
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
#define BOOST_PARAMETER_FUNCTION_CAST_B(tag, predicate, args)                \
    ::zr_boost_1_81::mp11::mp_apply_q<                                               \
        ::zr_boost_1_81::parameter::aux::cast<void predicate, args>                  \
      , ::zr_boost_1_81::mp11::mp_list<                                              \
            typename ::zr_boost_1_81::parameter::value_type<                         \
                args                                                         \
              , tag                                                          \
              , ::zr_boost_1_81::parameter::aux::use_default_tag                     \
            >::type                                                          \
          , ::zr_boost_1_81::mp11::mp_false                                          \
        >                                                                    \
    >
/**/
#else   // !defined(BOOST_PARAMETER_CAN_USE_MP11)
#define BOOST_PARAMETER_FUNCTION_CAST_B(tag, predicate, args)                \
    typename ::zr_boost_1_81::mpl::apply_wrap2<                                      \
        ::zr_boost_1_81::parameter::aux::cast<void predicate, args>                  \
      , typename ::zr_boost_1_81::parameter::value_type<                             \
            args                                                             \
          , tag                                                              \
          , ::zr_boost_1_81::parameter::aux::use_default_tag                         \
        >::type                                                              \
      , ::zr_boost_1_81::mpl::false_                                                 \
    >::type
/**/
#endif  // BOOST_PARAMETER_CAN_USE_MP11

#include <boost/core/enable_if.hpp>
#include <utility>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    // If the source and target types are not the same,
    // then perform an implicit conversion.
    template <typename Target, typename B, typename Source>
    inline typename ::zr_boost_1_81::lazy_disable_if<
        B
      , ::zr_boost_1_81::parameter::aux::cast_convert<Source,Target>
    >::type
        forward(Source&& source)
    {
        return ::zr_boost_1_81::parameter::aux::cast_convert<Source,Target>
        ::evaluate(::std::forward<Source>(source));
    }

    // If the source and target types are the same,
    // then simply forward the argument.
    // However, treat rvalue references to scalars as const lvalue references.
    template <typename T, typename B>
    inline typename ::zr_boost_1_81::enable_if<B,T const&>::type forward(T const& t)
    {
        return t;
    }

    template <typename T, typename B>
    inline typename ::zr_boost_1_81::enable_if<
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
        ::zr_boost_1_81::mp11::mp_if<
            B
          , ::zr_boost_1_81::mp11::mp_if<
                ::std::is_const<T>
              , ::zr_boost_1_81::mp11::mp_false
              , ::zr_boost_1_81::mp11::mp_true
            >
          , ::zr_boost_1_81::mp11::mp_false
        >
#else
        typename ::zr_boost_1_81::mpl::eval_if<
            B
          , ::zr_boost_1_81::mpl::if_<
                ::zr_boost_1_81::is_const<T>
              , ::zr_boost_1_81::mpl::false_
              , ::zr_boost_1_81::mpl::true_
            >
          , ::zr_boost_1_81::mpl::false_
        >::type
#endif  // BOOST_PARAMETER_CAN_USE_MP11
      , T&
    >::type
        forward(T& t)
    {
        return t;
    }
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/type_traits/is_scalar.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename T, typename B>
    inline typename ::zr_boost_1_81::enable_if<
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
        ::zr_boost_1_81::mp11::mp_if<
            B
          , ::zr_boost_1_81::mp11::mp_if<
                ::std::is_scalar<T>
              , ::zr_boost_1_81::mp11::mp_false
              , ::zr_boost_1_81::mp11::mp_true
            >
          , ::zr_boost_1_81::mp11::mp_false
        >
#else
        typename ::zr_boost_1_81::mpl::eval_if<
            B
          , ::zr_boost_1_81::mpl::if_<
                ::zr_boost_1_81::is_scalar<T>
              , ::zr_boost_1_81::mpl::false_
              , ::zr_boost_1_81::mpl::true_
            >
          , ::zr_boost_1_81::mpl::false_
        >::type
#endif  // BOOST_PARAMETER_CAN_USE_MP11
      , T const&&
    >::type
        forward(T const&& t)
    {
        return static_cast<T const&&>(t);
    }

    template <typename T, typename B>
    inline typename ::zr_boost_1_81::enable_if<
#if defined(BOOST_PARAMETER_CAN_USE_MP11)
        ::zr_boost_1_81::mp11::mp_if<
            B
          , ::zr_boost_1_81::mp11::mp_if<
                ::std::is_scalar<T>
              , ::zr_boost_1_81::mp11::mp_false
              , ::zr_boost_1_81::mp11::mp_true
            >
          , ::zr_boost_1_81::mp11::mp_false
        >
#else
        typename ::zr_boost_1_81::mpl::eval_if<
            B
          , ::zr_boost_1_81::mpl::if_<
                ::zr_boost_1_81::is_scalar<T>
              , ::zr_boost_1_81::mpl::false_
              , ::zr_boost_1_81::mpl::true_
            >
          , ::zr_boost_1_81::mpl::false_
        >::type
#endif  // BOOST_PARAMETER_CAN_USE_MP11
      , T&&
    >::type
        forward(T&& t)
    {
        return ::std::forward<T>(t);
    }
}}} // namespace zr_boost_1_81::parameter::aux

#elif BOOST_WORKAROUND(BOOST_BORLANDC, BOOST_TESTED_AT(0x564))
#define BOOST_PARAMETER_FUNCTION_CAST_T(value_t, predicate, args) value_t
#define BOOST_PARAMETER_FUNCTION_CAST_B(value, predicate, args) value
#else   // no perfect forwarding support and no Borland workarounds needed

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    // Handles possible implicit casts.  Used by preprocessor.hpp
    // to normalize user input.
    //
    // cast<void*>::execute() is identity
    // cast<void*(X)>::execute() is identity
    // cast<void(X)>::execute() casts to X
    //
    // preprocessor.hpp uses this like this:
    //
    //     #define X(value, predicate)
    //         cast<void predicate>::execute(value)
    //
    //     X(something, *)
    //     X(something, *(predicate))
    //     X(something, (int))
    template <typename VoidExpr, typename Args>
    struct cast;
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/aux_/use_default_tag.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename Args>
    struct cast<void*,Args>
    {
        template <typename T>
        struct apply
        {
            typedef T& type;
        };

        inline static ::zr_boost_1_81::parameter::aux::use_default_tag
            execute(::zr_boost_1_81::parameter::aux::use_default_tag)
        {
            return ::zr_boost_1_81::parameter::aux::use_default_tag();
        }

        template <typename U>
        inline static U& execute(U& value)
        {
            return value;
        }
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/parameter/aux_/void.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename Predicate, typename Args>
#if BOOST_WORKAROUND(__SUNPRO_CC, BOOST_TESTED_AT(0x580))
    struct cast< ::zr_boost_1_81::parameter::aux::voidstar(Predicate),Args>
#else
    struct cast<void*(Predicate),Args>
#endif
      : ::zr_boost_1_81::parameter::aux::cast<void*,Args>
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/mpl/placeholders.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    // This is a hack used in cast<> to turn the user supplied type,
    // which may or may not be a placeholder expression, into one,
    // so that it will be properly evaluated by mpl::apply.
    template <typename T, typename Dummy = ::zr_boost_1_81::mpl::_1>
    struct as_placeholder_expr
    {
        typedef T type;
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/mpl/apply.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename Target, typename Source, typename Args>
    struct is_target_same_as_source
      : ::zr_boost_1_81::mpl::if_<
            ::zr_boost_1_81::is_same<
                typename ::zr_boost_1_81::remove_const<
                    typename ::zr_boost_1_81::remove_reference<
                        typename ::zr_boost_1_81::mpl::apply2<
                            ::zr_boost_1_81::parameter::aux
                            ::as_placeholder_expr<Target>
                          , Source
                          , Args
                        >::type
                    >::type
                >::type
              , typename ::zr_boost_1_81::remove_const<Source>::type
            >
          , ::zr_boost_1_81::mpl::true_
          , ::zr_boost_1_81::mpl::false_
        >::type
    {
    };

    template <
        typename Target
      , typename Source
      , typename Args
      , typename Enable = ::zr_boost_1_81::parameter::aux
        ::is_target_same_as_source<Target,Source,Args>
    >
    struct cast_impl
    {
        typedef Source& type;

        inline static Source& evaluate(Source& value)
        {
            return value;
        }
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/add_lvalue_reference.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    // Covers the case where is_convertible<Source,Target> but not
    // is_same<Source,Target>.  Use cases are covered
    // by test/normalize_argument_types.cpp
    template <typename Source, typename Target>
    class cast_convert
    {
        typedef ::zr_boost_1_81::parameter::aux::cast_convert<Source,Target> _self;

     public:
        typedef typename ::zr_boost_1_81::add_lvalue_reference<
            typename ::zr_boost_1_81::add_const<Target>::type
        >::type type;

     private:
        template <typename U>
        inline static typename _self::type _mod_const(U const& u)
        {
            return u;
        }

        inline static Target _copy(Target value)
        {
            return value;
        }

     public:
        inline static typename _self::type evaluate(Source& source)
        {
            return _self::_mod_const(_self::_copy(source));
        }
    };

    template <typename Target, typename Source, typename Args>
    struct cast_impl<Target,Source,Args,::zr_boost_1_81::mpl::false_>
      : ::zr_boost_1_81::parameter::aux::cast_convert<
            Source,
            typename ::zr_boost_1_81::mpl::apply2<
                ::zr_boost_1_81::parameter::aux::as_placeholder_expr<Target>
              , Source
              , Args
            >::type
        >
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/mpl/eval_if.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename Target, typename Args>
    struct cast<void(Target),Args>
    {
        template <typename T>
        struct apply
        {
            typedef typename ::zr_boost_1_81::mpl::eval_if<
                    ::zr_boost_1_81::parameter::aux
                    ::is_target_same_as_source<Target,T,Args>
                  , ::zr_boost_1_81::add_lvalue_reference<T>
                  , ::zr_boost_1_81::parameter::aux::cast_impl<
                        Target
                      , T
                      , Args
                      , ::zr_boost_1_81::mpl::false_
                    >
            >::type type;
        };

        inline static ::zr_boost_1_81::parameter::aux::use_default_tag
            execute(::zr_boost_1_81::parameter::aux::use_default_tag)
        {
            return ::zr_boost_1_81::parameter::aux::use_default_tag();
        }

        template <typename U>
        inline static typename ::zr_boost_1_81::parameter::aux
        ::cast_impl<Target,U const,Args>::type
            execute(U const& value)
        {
            return ::zr_boost_1_81::parameter::aux
            ::cast_impl<Target,U const,Args>::evaluate(value);
        }

        template <typename U>
        inline static typename ::zr_boost_1_81::parameter::aux
        ::cast_impl<Target,U,Args>::type
            execute(U& value)
        {
            return ::zr_boost_1_81::parameter::aux
            ::cast_impl<Target,U,Args>::evaluate(value);
        }
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/mpl/apply_wrap.hpp>
#include <boost/parameter/value_type.hpp>

// Expands to the reference-qualified target type of the argument
// as indicated by the predicate.
#define BOOST_PARAMETER_FUNCTION_CAST_T(tag, predicate, args)                \
    typename ::zr_boost_1_81::mpl::apply_wrap1<                                      \
        ::zr_boost_1_81::parameter::aux::cast<void predicate, args>                  \
      , typename ::zr_boost_1_81::parameter::value_type<                             \
            args                                                             \
          , tag                                                              \
          , ::zr_boost_1_81::parameter::aux::use_default_tag                         \
        >::type                                                              \
    >::type
/**/

// Expands to the converted or passed-through value
// as indicated by the predicate.
#define BOOST_PARAMETER_FUNCTION_CAST_B(value, predicate, args)              \
    ::zr_boost_1_81::parameter::aux::cast<void predicate, args>::execute(value)
/**/

#endif  // perfect forwarding support, or Borland workarounds needed
#endif  // include guard

