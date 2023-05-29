// Copyright Jason Rice 2020
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/hana/equal.hpp>
#include <boost/hana/not_equal.hpp>
#include <boost/hana/tuple.hpp>
#include <cassert>
namespace hana = zr_boost_1_81::hana;

namespace {
    template <typename T>
    struct optional {
        T t;
    };

    template <typename T>
    constexpr bool operator==(optional<T> const& o, T const& t) {
        return o.t == t;
    }
    template <typename T>
    constexpr bool operator==(T const& t, optional<T> const& o) {
        return o.t == t;
    }
    template <typename T>
    constexpr bool operator!=(optional<T> const& o, T const& t) {
        return o.t != t;
    }
    template <typename T>
    constexpr bool operator!=(T const& t, optional<T> const& o) {
        return o.t != t;
    }
}

int main() {
    zr_boost_1_81::hana::tuple<int> x{};
    optional<zr_boost_1_81::hana::tuple<int>> attr{x};
    assert(attr == x);  // <-- Kablooey!
}
