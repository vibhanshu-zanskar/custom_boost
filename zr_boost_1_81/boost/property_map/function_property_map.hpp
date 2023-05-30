//
//=======================================================================
// Author: Philipp Moeller
//
// Copyright 2012, Philipp Moeller
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================
//

#ifndef BOOST_PROPERTY_MAP_FUNCTION_PROPERTY_MAP_HPP
#define BOOST_PROPERTY_MAP_FUNCTION_PROPERTY_MAP_HPP

#include <boost/config.hpp>
#include <boost/property_map/property_map.hpp>
#include <boost/type_traits.hpp>
#include <boost/utility/result_of.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <utility>

namespace zr_boost_1_81 {

template<typename Func, typename Key, typename Ret = typename zr_boost_1_81::result_of<const Func(const Key&)>::type>
class function_property_map: public put_get_helper<Ret, function_property_map<Func, Key, Ret> > {
  public:
  typedef Key key_type;
  typedef Ret reference;
  typedef typename zr_boost_1_81::remove_cv<typename zr_boost_1_81::remove_reference<Ret>::type>::type value_type;

  typedef typename zr_boost_1_81::mpl::if_<
                     zr_boost_1_81::mpl::and_<
                       zr_boost_1_81::is_reference<Ret>,
                       zr_boost_1_81::mpl::not_<zr_boost_1_81::is_const<Ret> >
                     >,
                     zr_boost_1_81::lvalue_property_map_tag,
                     zr_boost_1_81::readable_property_map_tag>::type
    category;

  function_property_map(Func f = Func()) : f(f) {}

  reference operator[](const Key& k) const {
    return f(k);
  }

  private:
  Func f;
};

template<typename Key, typename Func>
function_property_map<Func, Key>
make_function_property_map(const Func& f) {
  return function_property_map<Func, Key>(f);
}

template<typename Key, typename Ret, typename Func>
function_property_map<Func, Key, Ret>
make_function_property_map(const Func& f) {
  return function_property_map<Func, Key, Ret>(f);
}

} // boost

#endif /* BOOST_PROPERTY_MAP_FUNCTION_PROPERTY_MAP_HPP */
