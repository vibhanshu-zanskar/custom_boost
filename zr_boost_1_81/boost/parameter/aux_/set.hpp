// Copyright Daniel Wallin 2006.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PARAMETER_SET_060912_HPP
#define BOOST_PARAMETER_SET_060912_HPP

#include <boost/parameter/config.hpp>

#if defined(BOOST_PARAMETER_CAN_USE_MP11)
#include <boost/mp11/list.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    typedef ::zr_boost_1_81::mp11::mp_list<> set0;
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/mp11/algorithm.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename S, typename K>
    struct insert_
    {
        using type = ::zr_boost_1_81::mp11::mp_insert_c<S,0,K>;
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/mp11/integral.hpp>
#include <boost/mp11/utility.hpp>
#include <type_traits>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename Set, typename K>
    struct has_key_
    {
        using type = ::zr_boost_1_81::mp11::mp_if<
            ::zr_boost_1_81::mp11::mp_empty<Set>
          , ::zr_boost_1_81::mp11::mp_false
          , ::std::is_same<
                ::zr_boost_1_81::mp11::mp_find<Set,K>
              , ::zr_boost_1_81::mp11::mp_size<Set>
            >
        >;
    };
}}} // namespace zr_boost_1_81::parameter::aux

#elif BOOST_WORKAROUND(BOOST_BORLANDC, BOOST_TESTED_AT(0x564))
#include <boost/mpl/list.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    typedef ::zr_boost_1_81::mpl::list0<> set0;
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/mpl/push_front.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename Set, typename K>
    struct insert_ : ::zr_boost_1_81::mpl::push_front<Set,K>
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/find.hpp>
#include <boost/type_traits/is_same.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename Set, typename K>
    struct has_key_
    {
        typedef typename ::zr_boost_1_81::mpl::find<Set,K>::type iter;
        typedef typename ::zr_boost_1_81::mpl::if_<
            ::zr_boost_1_81::is_same<iter,typename ::zr_boost_1_81::mpl::end<Set>::type>
          , ::zr_boost_1_81::mpl::false_
          , ::zr_boost_1_81::mpl::true_
        >::type type;
    };
}}} // namespace zr_boost_1_81::parameter::aux

#else   // !BOOST_PARAMETER_CAN_USE_MP11 && Borland workarounds not needed
#include <boost/mpl/set/set0.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    typedef ::zr_boost_1_81::mpl::set0<> set0;
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/mpl/insert.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename Set, typename K>
    struct insert_ : ::zr_boost_1_81::mpl::insert<Set,K>
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#include <boost/mpl/has_key.hpp>

namespace zr_boost_1_81 { namespace parameter { namespace aux {

    template <typename Set, typename K>
    struct has_key_ : ::zr_boost_1_81::mpl::has_key<Set,K>
    {
    };
}}} // namespace zr_boost_1_81::parameter::aux

#endif  // BOOST_PARAMETER_CAN_USE_MP11 || Borland workarounds needed
#endif  // include guard

