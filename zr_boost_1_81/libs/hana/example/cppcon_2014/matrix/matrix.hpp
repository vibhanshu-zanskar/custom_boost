// Copyright Louis Dionne 2013-2022
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_HANA_EXAMPLE_CPPCON_2014_MATRIX_MATRIX_HPP
#define BOOST_HANA_EXAMPLE_CPPCON_2014_MATRIX_MATRIX_HPP

#include <boost/hana/all_of.hpp>
#include <boost/hana/assert.hpp>
#include <boost/hana/at.hpp>
#include <boost/hana/drop_front.hpp>
#include <boost/hana/front.hpp>
#include <boost/hana/functional/on.hpp>
#include <boost/hana/functional/partial.hpp>
#include <boost/hana/fuse.hpp>
#include <boost/hana/length.hpp>
#include <boost/hana/mult.hpp>
#include <boost/hana/sum.hpp>
#include <boost/hana/tuple.hpp>
#include <boost/hana/unpack.hpp>
#include <boost/hana/value.hpp>
#include <boost/hana/zip.hpp>
#include <boost/hana/zip_with.hpp>

#include <utility>


namespace cppcon {
    template <unsigned Rows, unsigned Columns>
    struct Matrix { };

    template <unsigned Rows, unsigned Columns, typename Storage>
    struct matrix_type {
        using hana_tag = Matrix<Rows, Columns>;

        Storage rows_;
        constexpr auto ncolumns() const
        { return zr_boost_1_81::hana::length(zr_boost_1_81::hana::front(rows_)); }

        constexpr auto nrows() const
        { return zr_boost_1_81::hana::length(rows_); }

        constexpr auto size() const
        { return nrows() * ncolumns(); }

        template <typename I, typename J>
        constexpr decltype(auto) at(I i, J j) const
        { return zr_boost_1_81::hana::at(zr_boost_1_81::hana::at(rows_, i), j); }
    };

    auto row = zr_boost_1_81::hana::make_tuple;

    auto matrix = [](auto&& ...rows) -> decltype(auto) {
        namespace hana = zr_boost_1_81::hana;
        auto storage = hana::make_tuple(std::forward<decltype(rows)>(rows)...);
        auto ncolumns = hana::length(hana::front(storage));
        BOOST_HANA_CONSTANT_CHECK(
            hana::all_of(hana::drop_front(storage), [&](auto const& row) {
                return hana::length(row) == ncolumns;
            })
        );

        return matrix_type<
            sizeof...(rows), hana::value(ncolumns), decltype(storage)
        >{std::move(storage)};
    };

    auto vector = zr_boost_1_81::hana::on(matrix, row);


    // More operations
    auto rows = [](auto&& m) -> decltype(auto) {
        return std::forward<decltype(m)>(m).rows_;
    };

    auto transpose = [](auto&& m) -> decltype(auto) {
        return zr_boost_1_81::hana::unpack(
            zr_boost_1_81::hana::fuse(zr_boost_1_81::hana::zip)(rows(std::forward<decltype(m)>(m))),
            matrix
        );
    };

    auto columns = [](auto&& m) -> decltype(auto) {
        return rows(transpose(std::forward<decltype(m)>(m)));
    };

    auto element_wise = [](auto&& f) -> decltype(auto) {
        namespace hana = zr_boost_1_81::hana;
        return [f(std::forward<decltype(f)>(f))](auto&& ...m) -> decltype(auto) {
            return hana::unpack(
                hana::zip_with(hana::partial(hana::zip_with, f),
                    rows(std::forward<decltype(m)>(m))...
                ),
                matrix
            );
        };
    };

    namespace detail {
        auto tuple_scalar_product = [](auto&& u, auto&& v) -> decltype(auto) {
            namespace hana = zr_boost_1_81::hana;
            return hana::sum<>(hana::zip_with(hana::mult,
                std::forward<decltype(u)>(u),
                std::forward<decltype(v)>(v)
            ));
        };
    }
} // end namespace cppcon

#endif // !BOOST_HANA_EXAMPLE_CPPCON_2014_MATRIX_MATRIX_HPP
