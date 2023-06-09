// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#ifndef INDIRECT_TRAITS_DWA2002131_HPP
# define INDIRECT_TRAITS_DWA2002131_HPP
# include <boost/type_traits/integral_constant.hpp>
# include <boost/type_traits/is_function.hpp>
# include <boost/type_traits/is_reference.hpp>
# include <boost/type_traits/is_pointer.hpp>
# include <boost/type_traits/is_class.hpp>
# include <boost/type_traits/is_const.hpp>
# include <boost/type_traits/is_volatile.hpp>
# include <boost/type_traits/is_member_function_pointer.hpp>
# include <boost/type_traits/is_member_pointer.hpp>
# include <boost/type_traits/remove_cv.hpp>
# include <boost/type_traits/remove_reference.hpp>
# include <boost/type_traits/remove_pointer.hpp>

# include <boost/detail/workaround.hpp>
# include <boost/detail/select_type.hpp>


namespace zr_boost_1_81 { namespace detail {

namespace indirect_traits {

template <class T>
struct is_reference_to_const : zr_boost_1_81::false_type
{
};

template <class T>
struct is_reference_to_const<T const&> : zr_boost_1_81::true_type
{
};

#   if defined(BOOST_MSVC) && _MSC_FULL_VER <= 13102140 // vc7.01 alpha workaround
template<class T>
struct is_reference_to_const<T const volatile&> : zr_boost_1_81::true_type
{
};
#   endif

template <class T>
struct is_reference_to_function : zr_boost_1_81::false_type
{
};

template <class T>
struct is_reference_to_function<T&> : is_function<T>
{
};

template <class T>
struct is_pointer_to_function : zr_boost_1_81::false_type
{
};

// There's no such thing as a pointer-to-cv-function, so we don't need
// specializations for those
template <class T>
struct is_pointer_to_function<T*> : is_function<T>
{
};

template <class T>
struct is_reference_to_member_function_pointer_impl : zr_boost_1_81::false_type
{
};

template <class T>
struct is_reference_to_member_function_pointer_impl<T&>
    : is_member_function_pointer<typename remove_cv<T>::type>
{
};


template <class T>
struct is_reference_to_member_function_pointer
    : is_reference_to_member_function_pointer_impl<T>
{
};

template <class T>
struct is_reference_to_function_pointer_aux
    : zr_boost_1_81::integral_constant<bool,
          is_reference<T>::value &&
          is_pointer_to_function<
              typename remove_cv<
                  typename remove_reference<T>::type
              >::type
          >::value
      >
{
    // There's no such thing as a pointer-to-cv-function, so we don't need specializations for those
};

template <class T>
struct is_reference_to_function_pointer
    : zr_boost_1_81::detail::if_true<
          is_reference_to_function<T>::value
      >::template then<
          zr_boost_1_81::false_type
        , is_reference_to_function_pointer_aux<T>
      >::type
{
};

template <class T>
struct is_reference_to_non_const
    : zr_boost_1_81::integral_constant<bool,
          is_reference<T>::value &&
          !is_reference_to_const<T>::value
      >
{
};

template <class T>
struct is_reference_to_volatile : zr_boost_1_81::false_type
{
};

template <class T>
struct is_reference_to_volatile<T volatile&> : zr_boost_1_81::true_type
{
};

#   if defined(BOOST_MSVC) && _MSC_FULL_VER <= 13102140 // vc7.01 alpha workaround
template <class T>
struct is_reference_to_volatile<T const volatile&> : zr_boost_1_81::true_type
{
};
#   endif


template <class T>
struct is_reference_to_pointer : zr_boost_1_81::false_type
{
};

template <class T>
struct is_reference_to_pointer<T*&> : zr_boost_1_81::true_type
{
};

template <class T>
struct is_reference_to_pointer<T* const&> : zr_boost_1_81::true_type
{
};

template <class T>
struct is_reference_to_pointer<T* volatile&> : zr_boost_1_81::true_type
{
};

template <class T>
struct is_reference_to_pointer<T* const volatile&> : zr_boost_1_81::true_type
{
};

template <class T>
struct is_reference_to_class
    : zr_boost_1_81::integral_constant<bool,
          is_reference<T>::value &&
          is_class<
              typename remove_cv<
                  typename remove_reference<T>::type
              >::type
          >::value
      >
{
};

template <class T>
struct is_pointer_to_class
    : zr_boost_1_81::integral_constant<bool,
          is_pointer<T>::value &&
          is_class<
              typename remove_cv<
                  typename remove_pointer<T>::type
              >::type
          >::value
      >
{
};


}

using namespace indirect_traits;

}} // namespace zr_boost_1_81::python::detail

#endif // INDIRECT_TRAITS_DWA2002131_HPP
