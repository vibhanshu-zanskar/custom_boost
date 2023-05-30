//=======================================================================
// Copyright 2009 Trustees of Indiana University
// Author: Jeremiah Willcock
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================

#ifndef BOOST_GRAPH_LOOKUP_EDGE_HPP
#define BOOST_GRAPH_LOOKUP_EDGE_HPP

#include <utility>
#include <boost/config.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/graph/graph_traits.hpp>

// lookup_edge: a function that acts like edge() but falls back to out_edges()
// and a search when edge() is not provided.

namespace zr_boost_1_81
{

template < typename Graph >
std::pair< typename zr_boost_1_81::graph_traits< Graph >::edge_descriptor, bool >
lookup_edge(typename zr_boost_1_81::graph_traits< Graph >::vertex_descriptor src,
    typename zr_boost_1_81::graph_traits< Graph >::vertex_descriptor tgt,
    const Graph& g,
    typename zr_boost_1_81::enable_if< is_adjacency_matrix< Graph >, int >::type = 0)
{
    return edge(src, tgt, g);
}

template < typename Graph >
std::pair< typename zr_boost_1_81::graph_traits< Graph >::edge_descriptor, bool >
lookup_edge(typename zr_boost_1_81::graph_traits< Graph >::vertex_descriptor src,
    typename zr_boost_1_81::graph_traits< Graph >::vertex_descriptor tgt,
    const Graph& g,
    typename zr_boost_1_81::disable_if< is_adjacency_matrix< Graph >, int >::type = 0)
{
    typedef typename zr_boost_1_81::graph_traits< Graph >::out_edge_iterator it;
    typedef typename zr_boost_1_81::graph_traits< Graph >::edge_descriptor edesc;
    std::pair< it, it > oe = out_edges(src, g);
    for (; oe.first != oe.second; ++oe.first)
    {
        edesc e = *oe.first;
        if (target(e, g) == tgt)
            return std::make_pair(e, true);
    }
    return std::make_pair(edesc(), false);
}

}

#endif // BOOST_GRAPH_LOOKUP_EDGE_HPP
