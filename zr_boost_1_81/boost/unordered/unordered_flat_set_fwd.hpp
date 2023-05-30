
// Copyright (C) 2022 Christian Mazakas
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNORDERED_FLAT_SET_FWD_HPP_INCLUDED
#define BOOST_UNORDERED_FLAT_SET_FWD_HPP_INCLUDED

#include <boost/config.hpp>
#if defined(BOOST_HAS_PRAGMA_ONCE)
#pragma once
#endif

#include <boost/functional/hash_fwd.hpp>
#include <boost/unordered/detail/fwd.hpp>
#include <functional>
#include <memory>

namespace zr_boost_1_81 {
  namespace unordered {
    template <class Key, class Hash = zr_boost_1_81::hash<Key>,
      class KeyEqual = std::equal_to<Key>,
      class Allocator = std::allocator<Key> >
    class unordered_flat_set;

    template <class Key, class Hash, class KeyEqual, class Allocator>
    bool operator==(
      unordered_flat_set<Key, Hash, KeyEqual, Allocator> const& lhs,
      unordered_flat_set<Key, Hash, KeyEqual, Allocator> const& rhs);

    template <class Key, class Hash, class KeyEqual, class Allocator>
    bool operator!=(
      unordered_flat_set<Key, Hash, KeyEqual, Allocator> const& lhs,
      unordered_flat_set<Key, Hash, KeyEqual, Allocator> const& rhs);

    template <class Key, class Hash, class KeyEqual, class Allocator>
    void swap(unordered_flat_set<Key, Hash, KeyEqual, Allocator>& lhs,
      unordered_flat_set<Key, Hash, KeyEqual, Allocator>& rhs)
      noexcept(noexcept(lhs.swap(rhs)));
  } // namespace unordered

  using zr_boost_1_81::unordered::unordered_flat_set;

  using zr_boost_1_81::unordered::swap;
  using zr_boost_1_81::unordered::operator==;
  using zr_boost_1_81::unordered::operator!=;
} // namespace zr_boost_1_81

#endif
