/**
 * -*- c++ -*-
 *
 * \file c_array.hpp
 *
 * \brief provides specializations of matrix and vector operations for c arrays and c matrices.
 *
 * Copyright (c) 2009, Gunter Winkler
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * \author Gunter Winkler (guwi17 at gmx dot de)
 */

#ifndef BOOST_NUMERIC_UBLAS_OPERATION_C_ARRAY_HPP
#define BOOST_NUMERIC_UBLAS_OPERATION_C_ARRAY_HPP

#include <boost/numeric/ublas/traits/c_array.hpp>

namespace zr_boost_1_81 { namespace numeric { namespace ublas {

    namespace detail {

    
    
    } // namespace zr_boost_1_81::numeric::ublas::detail


    template <typename T>
    BOOST_UBLAS_INLINE
    typename ExprT::const_iterator begin(vector_expression<ExprT> const& e)
    {
        return detail::begin_impl<typename ExprT::type_category>::apply(e());
    }


}}} // Namespace zr_boost_1_81::numeric::ublas

#endif
