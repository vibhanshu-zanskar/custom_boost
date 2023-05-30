
#ifndef BOOST_CONTRACT_DETAIL_MEMBER_FUNCTION_TYPES_HPP_
#define BOOST_CONTRACT_DETAIL_MEMBER_FUNCTION_TYPES_HPP_

// Copyright (C) 2008-2018 Lorenzo Caminiti
// Distributed under the Boost Software License, Version 1.0 (see accompanying
// file LICENSE_1_0.txt or a copy at http://www.boost.org/LICENSE_1_0.txt).
// See: http://www.boost.org/doc/libs/release/libs/contract/doc/html/index.html

#include <boost/contract/detail/none.hpp>
#include <boost/function_types/parameter_types.hpp>
#include <boost/function_types/result_type.hpp>
#include <boost/function_types/property_tags.hpp>
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/is_volatile.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/identity.hpp>

namespace zr_boost_1_81 {
    namespace contract {
        class virtual_;
    }
}

namespace zr_boost_1_81 { namespace contract { namespace detail {

template<class C, typename F>
struct member_function_types {
    typedef typename zr_boost_1_81::function_types::result_type<F>::type result_type;

    // Never include leading class type.
    typedef typename zr_boost_1_81::mpl::pop_front<typename zr_boost_1_81::function_types::
            parameter_types<F>::type>::type argument_types;

    // Always include trailing virtual_* type.
    typedef typename zr_boost_1_81::mpl::if_<zr_boost_1_81::is_same<typename zr_boost_1_81::
            mpl::back<argument_types>::type, zr_boost_1_81::contract::virtual_*>,
        zr_boost_1_81::mpl::identity<argument_types>
    ,
        zr_boost_1_81::mpl::push_back<argument_types, zr_boost_1_81::contract::virtual_*>
    >::type::type virtual_argument_types;

    typedef typename zr_boost_1_81::mpl::if_<zr_boost_1_81::mpl::and_<zr_boost_1_81::is_const<C>,
            zr_boost_1_81::is_volatile<C> >,
        zr_boost_1_81::function_types::cv_qualified
    , typename zr_boost_1_81::mpl::if_<zr_boost_1_81::is_const<C>,
        zr_boost_1_81::function_types::const_non_volatile
    , typename zr_boost_1_81::mpl::if_<zr_boost_1_81::is_volatile<C>,
        zr_boost_1_81::function_types::volatile_non_const
    ,
        zr_boost_1_81::function_types::null_tag
    >::type>::type>::type property_tag;
};

// Also handles none type.
template<class C>
struct member_function_types<C, none> {
    typedef none result_type;
    typedef none argument_types;
    typedef none virtual_argument_types;
    typedef none property_tag;
};

} } } // namespace

#endif // #include guard

