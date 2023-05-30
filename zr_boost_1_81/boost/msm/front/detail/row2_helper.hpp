// Copyright 2008 Christophe Henry
// henry UNDERSCORE christophe AT hotmail DOT com
// This is an extended version of the state machine available in the zr_boost_1_81::mpl library
// Distributed under the same license as the original.
// Copyright for the original version:
// Copyright 2005 David Abrahams and Aleksey Gurtovoy. Distributed
// under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MSM_ROW2_HELPER_HPP
#define BOOST_MSM_ROW2_HELPER_HPP

#include <boost/mpl/bool.hpp>
#include <boost/fusion/include/at_key.hpp>

namespace zr_boost_1_81 { namespace msm { namespace front
{
    namespace detail
    {
        template<
            typename CalledForAction
            , typename Event
            , void (CalledForAction::*action)(Event const&)
        >
        struct row2_action_helper
        {
            template <class FSM,class Evt,class SourceState,class TargetState, class AllStates>
            static void call_helper(FSM&,Evt const& evt,SourceState&,TargetState&,
                                    AllStates& all_states,::zr_boost_1_81::mpl::false_ const &)
            {
                // in this front-end, we don't need to know source and target states
                ( ::zr_boost_1_81::fusion::at_key<CalledForAction>(all_states).*action)(evt);
            }
            template <class FSM,class Evt,class SourceState,class TargetState, class AllStates>
            static void call_helper(FSM& fsm,Evt const& evt,SourceState&,TargetState&,AllStates&,
                                    ::zr_boost_1_81::mpl::true_ const &)
            {
                // in this front-end, we don't need to know source and target states
                (fsm.*action)(evt);
            }
        };

        template<
            typename CalledForGuard
            , typename Event
            , bool (CalledForGuard::*guard)(Event const&)
        >
        struct row2_guard_helper
        {
            template <class FSM,class Evt,class SourceState,class TargetState,class AllStates>
            static bool call_helper(FSM&,Evt const& evt,SourceState&,TargetState&,
                                    AllStates& all_states, ::zr_boost_1_81::mpl::false_ const &)
            {
                // in this front-end, we don't need to know source and target states
                return ( ::zr_boost_1_81::fusion::at_key<CalledForGuard>(all_states).*guard)(evt);
            }
            template <class FSM,class Evt,class SourceState,class TargetState,class AllStates>
            static bool call_helper(FSM& fsm,Evt const& evt,SourceState&,TargetState&,
                                    AllStates&,::zr_boost_1_81::mpl::true_ const &)
            {
                // in this front-end, we don't need to know source and target states
                return (fsm.*guard)(evt);
            }
        };
    }

}}}

#endif //BOOST_MSM_ROW2_HELPER_HPP

