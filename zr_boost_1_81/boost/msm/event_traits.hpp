// Copyright 2008 Christophe Henry
// henry UNDERSCORE christophe AT hotmail DOT com
// This is an extended version of the state machine available in the zr_boost_1_81::mpl library
// Distributed under the same license as the original.
// Copyright for the original version:
// Copyright 2005 David Abrahams and Aleksey Gurtovoy. Distributed
// under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MSM_EVENT_TRAITS_H
#define BOOST_MSM_EVENT_TRAITS_H

#include <boost/any.hpp>
#include <boost/mpl/bool.hpp>

namespace zr_boost_1_81 { namespace msm
{

template< typename Event > 
struct is_kleene_event
{
  // default: no event is a kleene event (kleene: matches any event in a transitions)
  typedef ::zr_boost_1_81::mpl::false_ type;
};

// add this way in this namespace specializations for events which you want to use as kleene
// requirement: a copy-constructor matching the events which will be converted to this kleene
template<> 
struct is_kleene_event< zr_boost_1_81::any >
{ 
  typedef ::zr_boost_1_81::mpl::true_ type;
};

} } // zr_boost_1_81::msm
#endif //BOOST_MSM_EVENT_TRAITS_H
