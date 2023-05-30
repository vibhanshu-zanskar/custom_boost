// Boost.TypeErasure library
//
// Copyright 2011 Steven Watanabe
//
// Distributed under the Boost Software License Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// $Id$

#ifndef BOOST_TYPE_ERASURE_DETAIL_ACCESS_HPP_INCLUDED
#define BOOST_TYPE_ERASURE_DETAIL_ACCESS_HPP_INCLUDED

#include <boost/type_erasure/detail/storage.hpp>
#include <boost/type_erasure/detail/any_base.hpp>

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES) && \
    !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES) && \
    !defined(BOOST_NO_CXX11_FUNCTION_TEMPLATE_DEFAULT_ARGS) && \
    !defined(BOOST_NO_CXX11_TEMPLATE_ALIASES) && \
    !BOOST_WORKAROUND(BOOST_MSVC, == 1800) && \
    !BOOST_WORKAROUND(BOOST_GCC, < 40800) && /* Inherited constructors */ \
    !(defined(__clang_major__) && __clang_major__ == 3 && __clang__minor__ <= 2) /* Inherited constructors */
#define BOOST_TYPE_ERASURE_SFINAE_FRIENDLY_CONSTRUCTORS
#include <boost/type_traits/is_reference.hpp>
#include <boost/utility/enable_if.hpp>
#endif

namespace zr_boost_1_81 {
namespace type_erasure {

template<class Concept, class T>
class any;

template<class Concept, class T>
class param;

template<class Concept>
class binding;

namespace detail {

struct access
{
    template<class Derived>
    static const typename Derived::table_type&
    table(const ::zr_boost_1_81::type_erasure::any_base<Derived>& arg)
    {
        return static_cast<const Derived&>(arg).table;
    }
    template<class Concept, class T>
    static const ::zr_boost_1_81::type_erasure::binding<Concept>&
    table(const ::zr_boost_1_81::type_erasure::param<Concept, T>& arg)
    {
        return table(arg._impl);
    }
    template<class Concept, class T>
    static const ::zr_boost_1_81::type_erasure::binding<Concept>&
    table(const ::zr_boost_1_81::type_erasure::param<Concept, T&>& arg)
    {
        return arg._impl.table;
    }
#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
    template<class Concept, class T>
    static const ::zr_boost_1_81::type_erasure::binding<Concept>&
    table(const ::zr_boost_1_81::type_erasure::param<Concept, T&&>& arg)
    {
        return arg._impl.table;
    }
#endif
#ifdef BOOST_TYPE_ERASURE_SFINAE_FRIENDLY_CONSTRUCTORS
    template<class Concept, class T, class = typename ::zr_boost_1_81::enable_if_c<!::zr_boost_1_81::is_reference<T>::value>::type>
    static const typename any<Concept, T>::table_type&
    table(const ::zr_boost_1_81::type_erasure::any_base< ::zr_boost_1_81::type_erasure::any<Concept, T> >& arg)
    {
        return static_cast<const ::zr_boost_1_81::type_erasure::any<Concept, T>&>(arg)._boost_type_erasure_table;
    }
    template<class Concept, class T>
    static ::zr_boost_1_81::type_erasure::detail::storage&
    data(::zr_boost_1_81::type_erasure::any_base< ::zr_boost_1_81::type_erasure::any<Concept, T> >& arg)
    {
        return static_cast< ::zr_boost_1_81::type_erasure::any<Concept, T>&>(arg)._boost_type_erasure_data;
    }
    template<class Concept, class T>
    static const ::zr_boost_1_81::type_erasure::detail::storage&
    data(const ::zr_boost_1_81::type_erasure::any_base< ::zr_boost_1_81::type_erasure::any<Concept, T> >& arg)
    {
        return static_cast<const ::zr_boost_1_81::type_erasure::any<Concept, T>&>(arg)._boost_type_erasure_data;
    }
    template<class Concept, class T>
    static ::zr_boost_1_81::type_erasure::detail::storage&&
    data(::zr_boost_1_81::type_erasure::any_base< ::zr_boost_1_81::type_erasure::any<Concept, T> >&& arg)
    {
        return std::move(static_cast< ::zr_boost_1_81::type_erasure::any<Concept, T>&&>(arg)._boost_type_erasure_data);
    }
#endif
    template<class Derived>
    static ::zr_boost_1_81::type_erasure::detail::storage&
    data(::zr_boost_1_81::type_erasure::any_base<Derived>& arg)
    {
        return static_cast<Derived&>(arg).data;
    }
    template<class Concept, class T>
    static const ::zr_boost_1_81::type_erasure::detail::storage&
    data(::zr_boost_1_81::type_erasure::any_base< ::zr_boost_1_81::type_erasure::any<Concept, const T&> >& arg)
    {
        return static_cast< ::zr_boost_1_81::type_erasure::any<Concept, const T&>&>(arg).data;
    }
    template<class Derived>
    static const ::zr_boost_1_81::type_erasure::detail::storage&
    data(const ::zr_boost_1_81::type_erasure::any_base<Derived>& arg)
    {
        return static_cast<const Derived&>(arg).data;
    }
    template<class Concept, class T>
    static ::zr_boost_1_81::type_erasure::detail::storage&
    data(::zr_boost_1_81::type_erasure::any_base< ::zr_boost_1_81::type_erasure::any<Concept, T&> >& arg)
    {
        return const_cast< ::zr_boost_1_81::type_erasure::detail::storage&>(static_cast< ::zr_boost_1_81::type_erasure::any<Concept, T&>&>(arg).data);
    }
    template<class Concept, class T>
    static ::zr_boost_1_81::type_erasure::detail::storage&
    data(const ::zr_boost_1_81::type_erasure::any_base< ::zr_boost_1_81::type_erasure::any<Concept, T&> >& arg)
    {
        return const_cast< ::zr_boost_1_81::type_erasure::detail::storage&>(static_cast< const ::zr_boost_1_81::type_erasure::any<Concept, T&>&>(arg).data);
    }
    template<class Concept, class T>
    static const ::zr_boost_1_81::type_erasure::detail::storage&
    data(const ::zr_boost_1_81::type_erasure::any_base< ::zr_boost_1_81::type_erasure::any<Concept, const T&> >& arg)
    {
        return static_cast<const ::zr_boost_1_81::type_erasure::any<Concept, const T&>&>(arg).data;
    }
    template<class Concept, class T>
    static ::zr_boost_1_81::type_erasure::detail::storage&
    data(::zr_boost_1_81::type_erasure::param<Concept, T>& arg)
    {
        return data(arg._impl);
    }
    template<class Concept, class T>
    static ::zr_boost_1_81::type_erasure::detail::storage&
    data(::zr_boost_1_81::type_erasure::param<Concept, T&>& arg)
    {
        return arg._impl.data;
    }
    template<class Concept, class T>
    static const ::zr_boost_1_81::type_erasure::detail::storage&
    data(::zr_boost_1_81::type_erasure::param<Concept, const T&>& arg)
    {
        return arg._impl.data;
    }
    template<class Concept, class T>
    static const ::zr_boost_1_81::type_erasure::detail::storage&
    data(const ::zr_boost_1_81::type_erasure::param<Concept, T>& arg)
    {
        return data(arg._impl);
    }
    template<class Concept, class T>
    static const ::zr_boost_1_81::type_erasure::detail::storage&
    data(const ::zr_boost_1_81::type_erasure::param<Concept, T&>& arg)
    {
        return arg._impl.data;
    }

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES

    template<class Derived>
    static ::zr_boost_1_81::type_erasure::detail::storage&&
    data(::zr_boost_1_81::type_erasure::any_base<Derived>&& arg)
    {
        return std::move(static_cast<Derived&>(arg).data);
    }
    template<class Concept, class T>
    static ::zr_boost_1_81::type_erasure::detail::storage&&
    data(::zr_boost_1_81::type_erasure::any_base< ::zr_boost_1_81::type_erasure::any<Concept, T&&> >& arg)
    {
        return std::move(static_cast< ::zr_boost_1_81::type_erasure::any<Concept, T&&>&>(arg).data);
    }
    template<class Concept, class T>
    static ::zr_boost_1_81::type_erasure::detail::storage&&
    data(::zr_boost_1_81::type_erasure::any_base< ::zr_boost_1_81::type_erasure::any<Concept, T&&> >&& arg)
    {
        return std::move(static_cast< ::zr_boost_1_81::type_erasure::any<Concept, T&&>&>(arg).data);
    }
    template<class Concept, class T>
    static ::zr_boost_1_81::type_erasure::detail::storage&&
    data(const ::zr_boost_1_81::type_erasure::any_base< ::zr_boost_1_81::type_erasure::any<Concept, T&&> >& arg)
    {
        return std::move(const_cast< ::zr_boost_1_81::type_erasure::detail::storage&>(static_cast< const ::zr_boost_1_81::type_erasure::any<Concept, T&&>&>(arg).data));
    }
    template<class Concept, class T>
    static ::zr_boost_1_81::type_erasure::detail::storage&
    data(::zr_boost_1_81::type_erasure::any_base< ::zr_boost_1_81::type_erasure::any<Concept, T&> >&& arg)
    {
        return std::move(static_cast< ::zr_boost_1_81::type_erasure::any<Concept, T&>&>(arg).data);
    }

    template<class Concept, class T>
    static ::zr_boost_1_81::type_erasure::detail::storage&&
    data(::zr_boost_1_81::type_erasure::param<Concept, T>&& arg)
    {
        return std::move(data(arg._impl));
    }
    template<class Concept, class T>
    static ::zr_boost_1_81::type_erasure::detail::storage&&
    data(::zr_boost_1_81::type_erasure::param<Concept, T&&>&& arg)
    {
        return std::move(arg._impl.data);
    }
    template<class Concept, class T>
    static ::zr_boost_1_81::type_erasure::detail::storage&
    data(::zr_boost_1_81::type_erasure::param<Concept, T&>&& arg)
    {
        return arg._impl.data;
    }
    template<class Concept, class T>
    static const ::zr_boost_1_81::type_erasure::detail::storage&
    data(::zr_boost_1_81::type_erasure::param<Concept, const T&>&& arg)
    {
        return arg._impl.data;
    }
    template<class Concept, class T>
    static ::zr_boost_1_81::type_erasure::detail::storage&&
    data(::zr_boost_1_81::type_erasure::param<Concept, T&&>& arg)
    {
        return std::move(arg._impl.data);
    }
    template<class Concept, class T>
    static ::zr_boost_1_81::type_erasure::detail::storage&&
    data(const ::zr_boost_1_81::type_erasure::param<Concept, T&&>& arg)
    {
        return std::move(const_cast< ::zr_boost_1_81::type_erasure::detail::storage&>(arg._impl.data));
    }

#endif

};

}
}
}

#endif
