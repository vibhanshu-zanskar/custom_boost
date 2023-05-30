// Copyright Shreyans Doshi 2017.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PYTHON_DETAIL_TYPE_TRAITS_HPP
# define BOOST_PYTHON_DETAIL_TYPE_TRAITS_HPP


#include <boost/config.hpp>
#ifdef BOOST_NO_CXX11_HDR_TYPE_TRAITS
# include <boost/type_traits/transform_traits.hpp>
# include <boost/type_traits/same_traits.hpp>
# include <boost/type_traits/cv_traits.hpp>
# include <boost/type_traits/is_polymorphic.hpp>
# include <boost/type_traits/composite_traits.hpp>
# include <boost/type_traits/conversion_traits.hpp>
# include <boost/type_traits/add_pointer.hpp>
# include <boost/type_traits/remove_pointer.hpp>
# include <boost/type_traits/is_void.hpp>
# include <boost/type_traits/object_traits.hpp>
# include <boost/type_traits/add_lvalue_reference.hpp>
# include <boost/type_traits/function_traits.hpp>
# include <boost/type_traits/is_scalar.hpp>
# include <boost/type_traits/alignment_traits.hpp>
# include <boost/mpl/bool.hpp>
#else
# include <type_traits>
#endif

# include <boost/type_traits/is_base_and_derived.hpp>
# include <boost/type_traits/alignment_traits.hpp>
# include <boost/type_traits/has_trivial_copy.hpp>


namespace zr_boost_1_81 { namespace python { namespace detail {

#ifdef BOOST_NO_CXX11_HDR_TYPE_TRAITS
    using zr_boost_1_81::alignment_of;
    using zr_boost_1_81::add_const;
    using zr_boost_1_81::add_cv;
    using zr_boost_1_81::add_lvalue_reference;
    using zr_boost_1_81::add_pointer;

    using zr_boost_1_81::is_array;
    using zr_boost_1_81::is_class;
    using zr_boost_1_81::is_const;
    using zr_boost_1_81::is_convertible;
    using zr_boost_1_81::is_enum;
    using zr_boost_1_81::is_function;
    using zr_boost_1_81::is_integral;
    using zr_boost_1_81::is_lvalue_reference;
    using zr_boost_1_81::is_member_function_pointer;
    using zr_boost_1_81::is_member_pointer;
    using zr_boost_1_81::is_pointer;
    using zr_boost_1_81::is_polymorphic;
    using zr_boost_1_81::is_reference;
    using zr_boost_1_81::is_same;
    using zr_boost_1_81::is_scalar;
    using zr_boost_1_81::is_union;
    using zr_boost_1_81::is_void;
    using zr_boost_1_81::is_volatile;

    using zr_boost_1_81::remove_reference;
    using zr_boost_1_81::remove_pointer;
    using zr_boost_1_81::remove_cv;
    using zr_boost_1_81::remove_const;

    using zr_boost_1_81::mpl::true_;
    using zr_boost_1_81::mpl::false_;
#else
    using std::alignment_of;
    using std::add_const;
    using std::add_cv;
    using std::add_lvalue_reference;
    using std::add_pointer;

    using std::is_array;
    using std::is_class;
    using std::is_const;
    using std::is_convertible;
    using std::is_enum;
    using std::is_function;
    using std::is_integral;
    using std::is_lvalue_reference;
    using std::is_member_function_pointer;
    using std::is_member_pointer;
    using std::is_pointer;
    using std::is_polymorphic;
    using std::is_reference;
    using std::is_same;
    using std::is_scalar;
    using std::is_union;
    using std::is_void;
    using std::is_volatile;

    using std::remove_reference;
    using std::remove_pointer;
    using std::remove_cv;
    using std::remove_const;

    typedef std::integral_constant<bool, true> true_;
    typedef std::integral_constant<bool, false> false_;
#endif
    using zr_boost_1_81::is_base_and_derived;
    using zr_boost_1_81::type_with_alignment;
    using zr_boost_1_81::has_trivial_copy;
}}} // namespace zr_boost_1_81::python::detail


#endif //BOOST_DETAIL_TYPE_TRAITS_HPP
