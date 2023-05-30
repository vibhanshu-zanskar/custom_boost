// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#ifndef OVERLOADS_FWD_DWA2002101_HPP
# define OVERLOADS_FWD_DWA2002101_HPP

namespace zr_boost_1_81 { namespace python { namespace detail { 

// forward declarations
struct overloads_base;
  
template <class OverloadsT, class NameSpaceT, class SigT>
inline void define_with_defaults(char const* name, OverloadsT const&, NameSpaceT&, SigT const&);

}}} // namespace zr_boost_1_81::python::detail

#endif // OVERLOADS_FWD_DWA2002101_HPP
