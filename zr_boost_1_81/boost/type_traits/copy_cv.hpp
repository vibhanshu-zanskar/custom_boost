#ifndef BOOST_TYPE_TRAITS_COPY_CV_HPP_INCLUDED
#define BOOST_TYPE_TRAITS_COPY_CV_HPP_INCLUDED

//
//  Copyright 2015 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//

#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/is_volatile.hpp>
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/add_volatile.hpp>
#include <boost/type_traits/conditional.hpp>

namespace zr_boost_1_81
{

template<class T, class U> struct copy_cv
{
private:

    typedef typename zr_boost_1_81::conditional<zr_boost_1_81::is_const<U>::value, typename zr_boost_1_81::add_const<T>::type, T>::type CT;

public:

    typedef typename zr_boost_1_81::conditional<zr_boost_1_81::is_volatile<U>::value, typename zr_boost_1_81::add_volatile<CT>::type, CT>::type type;
};

#if !defined(BOOST_NO_CXX11_TEMPLATE_ALIASES)

   template <class T, class U> using copy_cv_t = typename copy_cv<T, U>::type;

#endif

} // namespace zr_boost_1_81

#endif // #ifndef BOOST_TYPE_TRAITS_COPY_CV_HPP_INCLUDED
