/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
    
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 1>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 2>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 3>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 4>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 5>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 6>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 7>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 8>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 9>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 10>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 11>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 12>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 13>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 14>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 15>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 16>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 17>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 18>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16; typedef typename proto::result_of::child_c<Expr, 17>::type A17;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e) , proto::child_c< 17>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 19>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16; typedef typename proto::result_of::child_c<Expr, 17>::type A17; typedef typename proto::result_of::child_c<Expr, 18>::type A18;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e) , proto::child_c< 17>(e) , proto::child_c< 18>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 20>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16; typedef typename proto::result_of::child_c<Expr, 17>::type A17; typedef typename proto::result_of::child_c<Expr, 18>::type A18; typedef typename proto::result_of::child_c<Expr, 19>::type A19;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e) , proto::child_c< 17>(e) , proto::child_c< 18>(e) , proto::child_c< 19>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 21>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16; typedef typename proto::result_of::child_c<Expr, 17>::type A17; typedef typename proto::result_of::child_c<Expr, 18>::type A18; typedef typename proto::result_of::child_c<Expr, 19>::type A19; typedef typename proto::result_of::child_c<Expr, 20>::type A20;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e) , proto::child_c< 17>(e) , proto::child_c< 18>(e) , proto::child_c< 19>(e) , proto::child_c< 20>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 22>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16; typedef typename proto::result_of::child_c<Expr, 17>::type A17; typedef typename proto::result_of::child_c<Expr, 18>::type A18; typedef typename proto::result_of::child_c<Expr, 19>::type A19; typedef typename proto::result_of::child_c<Expr, 20>::type A20; typedef typename proto::result_of::child_c<Expr, 21>::type A21;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e) , proto::child_c< 17>(e) , proto::child_c< 18>(e) , proto::child_c< 19>(e) , proto::child_c< 20>(e) , proto::child_c< 21>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 23>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16; typedef typename proto::result_of::child_c<Expr, 17>::type A17; typedef typename proto::result_of::child_c<Expr, 18>::type A18; typedef typename proto::result_of::child_c<Expr, 19>::type A19; typedef typename proto::result_of::child_c<Expr, 20>::type A20; typedef typename proto::result_of::child_c<Expr, 21>::type A21; typedef typename proto::result_of::child_c<Expr, 22>::type A22;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e) , proto::child_c< 17>(e) , proto::child_c< 18>(e) , proto::child_c< 19>(e) , proto::child_c< 20>(e) , proto::child_c< 21>(e) , proto::child_c< 22>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 24>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16; typedef typename proto::result_of::child_c<Expr, 17>::type A17; typedef typename proto::result_of::child_c<Expr, 18>::type A18; typedef typename proto::result_of::child_c<Expr, 19>::type A19; typedef typename proto::result_of::child_c<Expr, 20>::type A20; typedef typename proto::result_of::child_c<Expr, 21>::type A21; typedef typename proto::result_of::child_c<Expr, 22>::type A22; typedef typename proto::result_of::child_c<Expr, 23>::type A23;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e) , proto::child_c< 17>(e) , proto::child_c< 18>(e) , proto::child_c< 19>(e) , proto::child_c< 20>(e) , proto::child_c< 21>(e) , proto::child_c< 22>(e) , proto::child_c< 23>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 25>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16; typedef typename proto::result_of::child_c<Expr, 17>::type A17; typedef typename proto::result_of::child_c<Expr, 18>::type A18; typedef typename proto::result_of::child_c<Expr, 19>::type A19; typedef typename proto::result_of::child_c<Expr, 20>::type A20; typedef typename proto::result_of::child_c<Expr, 21>::type A21; typedef typename proto::result_of::child_c<Expr, 22>::type A22; typedef typename proto::result_of::child_c<Expr, 23>::type A23; typedef typename proto::result_of::child_c<Expr, 24>::type A24;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e) , proto::child_c< 17>(e) , proto::child_c< 18>(e) , proto::child_c< 19>(e) , proto::child_c< 20>(e) , proto::child_c< 21>(e) , proto::child_c< 22>(e) , proto::child_c< 23>(e) , proto::child_c< 24>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 26>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16; typedef typename proto::result_of::child_c<Expr, 17>::type A17; typedef typename proto::result_of::child_c<Expr, 18>::type A18; typedef typename proto::result_of::child_c<Expr, 19>::type A19; typedef typename proto::result_of::child_c<Expr, 20>::type A20; typedef typename proto::result_of::child_c<Expr, 21>::type A21; typedef typename proto::result_of::child_c<Expr, 22>::type A22; typedef typename proto::result_of::child_c<Expr, 23>::type A23; typedef typename proto::result_of::child_c<Expr, 24>::type A24; typedef typename proto::result_of::child_c<Expr, 25>::type A25;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e) , proto::child_c< 17>(e) , proto::child_c< 18>(e) , proto::child_c< 19>(e) , proto::child_c< 20>(e) , proto::child_c< 21>(e) , proto::child_c< 22>(e) , proto::child_c< 23>(e) , proto::child_c< 24>(e) , proto::child_c< 25>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 27>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16; typedef typename proto::result_of::child_c<Expr, 17>::type A17; typedef typename proto::result_of::child_c<Expr, 18>::type A18; typedef typename proto::result_of::child_c<Expr, 19>::type A19; typedef typename proto::result_of::child_c<Expr, 20>::type A20; typedef typename proto::result_of::child_c<Expr, 21>::type A21; typedef typename proto::result_of::child_c<Expr, 22>::type A22; typedef typename proto::result_of::child_c<Expr, 23>::type A23; typedef typename proto::result_of::child_c<Expr, 24>::type A24; typedef typename proto::result_of::child_c<Expr, 25>::type A25; typedef typename proto::result_of::child_c<Expr, 26>::type A26;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e) , proto::child_c< 17>(e) , proto::child_c< 18>(e) , proto::child_c< 19>(e) , proto::child_c< 20>(e) , proto::child_c< 21>(e) , proto::child_c< 22>(e) , proto::child_c< 23>(e) , proto::child_c< 24>(e) , proto::child_c< 25>(e) , proto::child_c< 26>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 28>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16; typedef typename proto::result_of::child_c<Expr, 17>::type A17; typedef typename proto::result_of::child_c<Expr, 18>::type A18; typedef typename proto::result_of::child_c<Expr, 19>::type A19; typedef typename proto::result_of::child_c<Expr, 20>::type A20; typedef typename proto::result_of::child_c<Expr, 21>::type A21; typedef typename proto::result_of::child_c<Expr, 22>::type A22; typedef typename proto::result_of::child_c<Expr, 23>::type A23; typedef typename proto::result_of::child_c<Expr, 24>::type A24; typedef typename proto::result_of::child_c<Expr, 25>::type A25; typedef typename proto::result_of::child_c<Expr, 26>::type A26; typedef typename proto::result_of::child_c<Expr, 27>::type A27;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e) , proto::child_c< 17>(e) , proto::child_c< 18>(e) , proto::child_c< 19>(e) , proto::child_c< 20>(e) , proto::child_c< 21>(e) , proto::child_c< 22>(e) , proto::child_c< 23>(e) , proto::child_c< 24>(e) , proto::child_c< 25>(e) , proto::child_c< 26>(e) , proto::child_c< 27>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 29>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16; typedef typename proto::result_of::child_c<Expr, 17>::type A17; typedef typename proto::result_of::child_c<Expr, 18>::type A18; typedef typename proto::result_of::child_c<Expr, 19>::type A19; typedef typename proto::result_of::child_c<Expr, 20>::type A20; typedef typename proto::result_of::child_c<Expr, 21>::type A21; typedef typename proto::result_of::child_c<Expr, 22>::type A22; typedef typename proto::result_of::child_c<Expr, 23>::type A23; typedef typename proto::result_of::child_c<Expr, 24>::type A24; typedef typename proto::result_of::child_c<Expr, 25>::type A25; typedef typename proto::result_of::child_c<Expr, 26>::type A26; typedef typename proto::result_of::child_c<Expr, 27>::type A27; typedef typename proto::result_of::child_c<Expr, 28>::type A28;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e) , proto::child_c< 17>(e) , proto::child_c< 18>(e) , proto::child_c< 19>(e) , proto::child_c< 20>(e) , proto::child_c< 21>(e) , proto::child_c< 22>(e) , proto::child_c< 23>(e) , proto::child_c< 24>(e) , proto::child_c< 25>(e) , proto::child_c< 26>(e) , proto::child_c< 27>(e) , proto::child_c< 28>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 30>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16; typedef typename proto::result_of::child_c<Expr, 17>::type A17; typedef typename proto::result_of::child_c<Expr, 18>::type A18; typedef typename proto::result_of::child_c<Expr, 19>::type A19; typedef typename proto::result_of::child_c<Expr, 20>::type A20; typedef typename proto::result_of::child_c<Expr, 21>::type A21; typedef typename proto::result_of::child_c<Expr, 22>::type A22; typedef typename proto::result_of::child_c<Expr, 23>::type A23; typedef typename proto::result_of::child_c<Expr, 24>::type A24; typedef typename proto::result_of::child_c<Expr, 25>::type A25; typedef typename proto::result_of::child_c<Expr, 26>::type A26; typedef typename proto::result_of::child_c<Expr, 27>::type A27; typedef typename proto::result_of::child_c<Expr, 28>::type A28; typedef typename proto::result_of::child_c<Expr, 29>::type A29;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e) , proto::child_c< 17>(e) , proto::child_c< 18>(e) , proto::child_c< 19>(e) , proto::child_c< 20>(e) , proto::child_c< 21>(e) , proto::child_c< 22>(e) , proto::child_c< 23>(e) , proto::child_c< 24>(e) , proto::child_c< 25>(e) , proto::child_c< 26>(e) , proto::child_c< 27>(e) , proto::child_c< 28>(e) , proto::child_c< 29>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 31>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16; typedef typename proto::result_of::child_c<Expr, 17>::type A17; typedef typename proto::result_of::child_c<Expr, 18>::type A18; typedef typename proto::result_of::child_c<Expr, 19>::type A19; typedef typename proto::result_of::child_c<Expr, 20>::type A20; typedef typename proto::result_of::child_c<Expr, 21>::type A21; typedef typename proto::result_of::child_c<Expr, 22>::type A22; typedef typename proto::result_of::child_c<Expr, 23>::type A23; typedef typename proto::result_of::child_c<Expr, 24>::type A24; typedef typename proto::result_of::child_c<Expr, 25>::type A25; typedef typename proto::result_of::child_c<Expr, 26>::type A26; typedef typename proto::result_of::child_c<Expr, 27>::type A27; typedef typename proto::result_of::child_c<Expr, 28>::type A28; typedef typename proto::result_of::child_c<Expr, 29>::type A29; typedef typename proto::result_of::child_c<Expr, 30>::type A30;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e) , proto::child_c< 17>(e) , proto::child_c< 18>(e) , proto::child_c< 19>(e) , proto::child_c< 20>(e) , proto::child_c< 21>(e) , proto::child_c< 22>(e) , proto::child_c< 23>(e) , proto::child_c< 24>(e) , proto::child_c< 25>(e) , proto::child_c< 26>(e) , proto::child_c< 27>(e) , proto::child_c< 28>(e) , proto::child_c< 29>(e) , proto::child_c< 30>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 32>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16; typedef typename proto::result_of::child_c<Expr, 17>::type A17; typedef typename proto::result_of::child_c<Expr, 18>::type A18; typedef typename proto::result_of::child_c<Expr, 19>::type A19; typedef typename proto::result_of::child_c<Expr, 20>::type A20; typedef typename proto::result_of::child_c<Expr, 21>::type A21; typedef typename proto::result_of::child_c<Expr, 22>::type A22; typedef typename proto::result_of::child_c<Expr, 23>::type A23; typedef typename proto::result_of::child_c<Expr, 24>::type A24; typedef typename proto::result_of::child_c<Expr, 25>::type A25; typedef typename proto::result_of::child_c<Expr, 26>::type A26; typedef typename proto::result_of::child_c<Expr, 27>::type A27; typedef typename proto::result_of::child_c<Expr, 28>::type A28; typedef typename proto::result_of::child_c<Expr, 29>::type A29; typedef typename proto::result_of::child_c<Expr, 30>::type A30; typedef typename proto::result_of::child_c<Expr, 31>::type A31;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e) , proto::child_c< 17>(e) , proto::child_c< 18>(e) , proto::child_c< 19>(e) , proto::child_c< 20>(e) , proto::child_c< 21>(e) , proto::child_c< 22>(e) , proto::child_c< 23>(e) , proto::child_c< 24>(e) , proto::child_c< 25>(e) , proto::child_c< 26>(e) , proto::child_c< 27>(e) , proto::child_c< 28>(e) , proto::child_c< 29>(e) , proto::child_c< 30>(e) , proto::child_c< 31>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 33>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16; typedef typename proto::result_of::child_c<Expr, 17>::type A17; typedef typename proto::result_of::child_c<Expr, 18>::type A18; typedef typename proto::result_of::child_c<Expr, 19>::type A19; typedef typename proto::result_of::child_c<Expr, 20>::type A20; typedef typename proto::result_of::child_c<Expr, 21>::type A21; typedef typename proto::result_of::child_c<Expr, 22>::type A22; typedef typename proto::result_of::child_c<Expr, 23>::type A23; typedef typename proto::result_of::child_c<Expr, 24>::type A24; typedef typename proto::result_of::child_c<Expr, 25>::type A25; typedef typename proto::result_of::child_c<Expr, 26>::type A26; typedef typename proto::result_of::child_c<Expr, 27>::type A27; typedef typename proto::result_of::child_c<Expr, 28>::type A28; typedef typename proto::result_of::child_c<Expr, 29>::type A29; typedef typename proto::result_of::child_c<Expr, 30>::type A30; typedef typename proto::result_of::child_c<Expr, 31>::type A31; typedef typename proto::result_of::child_c<Expr, 32>::type A32;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e) , proto::child_c< 17>(e) , proto::child_c< 18>(e) , proto::child_c< 19>(e) , proto::child_c< 20>(e) , proto::child_c< 21>(e) , proto::child_c< 22>(e) , proto::child_c< 23>(e) , proto::child_c< 24>(e) , proto::child_c< 25>(e) , proto::child_c< 26>(e) , proto::child_c< 27>(e) , proto::child_c< 28>(e) , proto::child_c< 29>(e) , proto::child_c< 30>(e) , proto::child_c< 31>(e) , proto::child_c< 32>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 34>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16; typedef typename proto::result_of::child_c<Expr, 17>::type A17; typedef typename proto::result_of::child_c<Expr, 18>::type A18; typedef typename proto::result_of::child_c<Expr, 19>::type A19; typedef typename proto::result_of::child_c<Expr, 20>::type A20; typedef typename proto::result_of::child_c<Expr, 21>::type A21; typedef typename proto::result_of::child_c<Expr, 22>::type A22; typedef typename proto::result_of::child_c<Expr, 23>::type A23; typedef typename proto::result_of::child_c<Expr, 24>::type A24; typedef typename proto::result_of::child_c<Expr, 25>::type A25; typedef typename proto::result_of::child_c<Expr, 26>::type A26; typedef typename proto::result_of::child_c<Expr, 27>::type A27; typedef typename proto::result_of::child_c<Expr, 28>::type A28; typedef typename proto::result_of::child_c<Expr, 29>::type A29; typedef typename proto::result_of::child_c<Expr, 30>::type A30; typedef typename proto::result_of::child_c<Expr, 31>::type A31; typedef typename proto::result_of::child_c<Expr, 32>::type A32; typedef typename proto::result_of::child_c<Expr, 33>::type A33;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e) , proto::child_c< 17>(e) , proto::child_c< 18>(e) , proto::child_c< 19>(e) , proto::child_c< 20>(e) , proto::child_c< 21>(e) , proto::child_c< 22>(e) , proto::child_c< 23>(e) , proto::child_c< 24>(e) , proto::child_c< 25>(e) , proto::child_c< 26>(e) , proto::child_c< 27>(e) , proto::child_c< 28>(e) , proto::child_c< 29>(e) , proto::child_c< 30>(e) , proto::child_c< 31>(e) , proto::child_c< 32>(e) , proto::child_c< 33>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 35>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16; typedef typename proto::result_of::child_c<Expr, 17>::type A17; typedef typename proto::result_of::child_c<Expr, 18>::type A18; typedef typename proto::result_of::child_c<Expr, 19>::type A19; typedef typename proto::result_of::child_c<Expr, 20>::type A20; typedef typename proto::result_of::child_c<Expr, 21>::type A21; typedef typename proto::result_of::child_c<Expr, 22>::type A22; typedef typename proto::result_of::child_c<Expr, 23>::type A23; typedef typename proto::result_of::child_c<Expr, 24>::type A24; typedef typename proto::result_of::child_c<Expr, 25>::type A25; typedef typename proto::result_of::child_c<Expr, 26>::type A26; typedef typename proto::result_of::child_c<Expr, 27>::type A27; typedef typename proto::result_of::child_c<Expr, 28>::type A28; typedef typename proto::result_of::child_c<Expr, 29>::type A29; typedef typename proto::result_of::child_c<Expr, 30>::type A30; typedef typename proto::result_of::child_c<Expr, 31>::type A31; typedef typename proto::result_of::child_c<Expr, 32>::type A32; typedef typename proto::result_of::child_c<Expr, 33>::type A33; typedef typename proto::result_of::child_c<Expr, 34>::type A34;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e) , proto::child_c< 17>(e) , proto::child_c< 18>(e) , proto::child_c< 19>(e) , proto::child_c< 20>(e) , proto::child_c< 21>(e) , proto::child_c< 22>(e) , proto::child_c< 23>(e) , proto::child_c< 24>(e) , proto::child_c< 25>(e) , proto::child_c< 26>(e) , proto::child_c< 27>(e) , proto::child_c< 28>(e) , proto::child_c< 29>(e) , proto::child_c< 30>(e) , proto::child_c< 31>(e) , proto::child_c< 32>(e) , proto::child_c< 33>(e) , proto::child_c< 34>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 36>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16; typedef typename proto::result_of::child_c<Expr, 17>::type A17; typedef typename proto::result_of::child_c<Expr, 18>::type A18; typedef typename proto::result_of::child_c<Expr, 19>::type A19; typedef typename proto::result_of::child_c<Expr, 20>::type A20; typedef typename proto::result_of::child_c<Expr, 21>::type A21; typedef typename proto::result_of::child_c<Expr, 22>::type A22; typedef typename proto::result_of::child_c<Expr, 23>::type A23; typedef typename proto::result_of::child_c<Expr, 24>::type A24; typedef typename proto::result_of::child_c<Expr, 25>::type A25; typedef typename proto::result_of::child_c<Expr, 26>::type A26; typedef typename proto::result_of::child_c<Expr, 27>::type A27; typedef typename proto::result_of::child_c<Expr, 28>::type A28; typedef typename proto::result_of::child_c<Expr, 29>::type A29; typedef typename proto::result_of::child_c<Expr, 30>::type A30; typedef typename proto::result_of::child_c<Expr, 31>::type A31; typedef typename proto::result_of::child_c<Expr, 32>::type A32; typedef typename proto::result_of::child_c<Expr, 33>::type A33; typedef typename proto::result_of::child_c<Expr, 34>::type A34; typedef typename proto::result_of::child_c<Expr, 35>::type A35;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e) , proto::child_c< 17>(e) , proto::child_c< 18>(e) , proto::child_c< 19>(e) , proto::child_c< 20>(e) , proto::child_c< 21>(e) , proto::child_c< 22>(e) , proto::child_c< 23>(e) , proto::child_c< 24>(e) , proto::child_c< 25>(e) , proto::child_c< 26>(e) , proto::child_c< 27>(e) , proto::child_c< 28>(e) , proto::child_c< 29>(e) , proto::child_c< 30>(e) , proto::child_c< 31>(e) , proto::child_c< 32>(e) , proto::child_c< 33>(e) , proto::child_c< 34>(e) , proto::child_c< 35>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 37>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16; typedef typename proto::result_of::child_c<Expr, 17>::type A17; typedef typename proto::result_of::child_c<Expr, 18>::type A18; typedef typename proto::result_of::child_c<Expr, 19>::type A19; typedef typename proto::result_of::child_c<Expr, 20>::type A20; typedef typename proto::result_of::child_c<Expr, 21>::type A21; typedef typename proto::result_of::child_c<Expr, 22>::type A22; typedef typename proto::result_of::child_c<Expr, 23>::type A23; typedef typename proto::result_of::child_c<Expr, 24>::type A24; typedef typename proto::result_of::child_c<Expr, 25>::type A25; typedef typename proto::result_of::child_c<Expr, 26>::type A26; typedef typename proto::result_of::child_c<Expr, 27>::type A27; typedef typename proto::result_of::child_c<Expr, 28>::type A28; typedef typename proto::result_of::child_c<Expr, 29>::type A29; typedef typename proto::result_of::child_c<Expr, 30>::type A30; typedef typename proto::result_of::child_c<Expr, 31>::type A31; typedef typename proto::result_of::child_c<Expr, 32>::type A32; typedef typename proto::result_of::child_c<Expr, 33>::type A33; typedef typename proto::result_of::child_c<Expr, 34>::type A34; typedef typename proto::result_of::child_c<Expr, 35>::type A35; typedef typename proto::result_of::child_c<Expr, 36>::type A36;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e) , proto::child_c< 17>(e) , proto::child_c< 18>(e) , proto::child_c< 19>(e) , proto::child_c< 20>(e) , proto::child_c< 21>(e) , proto::child_c< 22>(e) , proto::child_c< 23>(e) , proto::child_c< 24>(e) , proto::child_c< 25>(e) , proto::child_c< 26>(e) , proto::child_c< 27>(e) , proto::child_c< 28>(e) , proto::child_c< 29>(e) , proto::child_c< 30>(e) , proto::child_c< 31>(e) , proto::child_c< 32>(e) , proto::child_c< 33>(e) , proto::child_c< 34>(e) , proto::child_c< 35>(e) , proto::child_c< 36>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 38>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16; typedef typename proto::result_of::child_c<Expr, 17>::type A17; typedef typename proto::result_of::child_c<Expr, 18>::type A18; typedef typename proto::result_of::child_c<Expr, 19>::type A19; typedef typename proto::result_of::child_c<Expr, 20>::type A20; typedef typename proto::result_of::child_c<Expr, 21>::type A21; typedef typename proto::result_of::child_c<Expr, 22>::type A22; typedef typename proto::result_of::child_c<Expr, 23>::type A23; typedef typename proto::result_of::child_c<Expr, 24>::type A24; typedef typename proto::result_of::child_c<Expr, 25>::type A25; typedef typename proto::result_of::child_c<Expr, 26>::type A26; typedef typename proto::result_of::child_c<Expr, 27>::type A27; typedef typename proto::result_of::child_c<Expr, 28>::type A28; typedef typename proto::result_of::child_c<Expr, 29>::type A29; typedef typename proto::result_of::child_c<Expr, 30>::type A30; typedef typename proto::result_of::child_c<Expr, 31>::type A31; typedef typename proto::result_of::child_c<Expr, 32>::type A32; typedef typename proto::result_of::child_c<Expr, 33>::type A33; typedef typename proto::result_of::child_c<Expr, 34>::type A34; typedef typename proto::result_of::child_c<Expr, 35>::type A35; typedef typename proto::result_of::child_c<Expr, 36>::type A36; typedef typename proto::result_of::child_c<Expr, 37>::type A37;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e) , proto::child_c< 17>(e) , proto::child_c< 18>(e) , proto::child_c< 19>(e) , proto::child_c< 20>(e) , proto::child_c< 21>(e) , proto::child_c< 22>(e) , proto::child_c< 23>(e) , proto::child_c< 24>(e) , proto::child_c< 25>(e) , proto::child_c< 26>(e) , proto::child_c< 27>(e) , proto::child_c< 28>(e) , proto::child_c< 29>(e) , proto::child_c< 30>(e) , proto::child_c< 31>(e) , proto::child_c< 32>(e) , proto::child_c< 33>(e) , proto::child_c< 34>(e) , proto::child_c< 35>(e) , proto::child_c< 36>(e) , proto::child_c< 37>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 39>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16; typedef typename proto::result_of::child_c<Expr, 17>::type A17; typedef typename proto::result_of::child_c<Expr, 18>::type A18; typedef typename proto::result_of::child_c<Expr, 19>::type A19; typedef typename proto::result_of::child_c<Expr, 20>::type A20; typedef typename proto::result_of::child_c<Expr, 21>::type A21; typedef typename proto::result_of::child_c<Expr, 22>::type A22; typedef typename proto::result_of::child_c<Expr, 23>::type A23; typedef typename proto::result_of::child_c<Expr, 24>::type A24; typedef typename proto::result_of::child_c<Expr, 25>::type A25; typedef typename proto::result_of::child_c<Expr, 26>::type A26; typedef typename proto::result_of::child_c<Expr, 27>::type A27; typedef typename proto::result_of::child_c<Expr, 28>::type A28; typedef typename proto::result_of::child_c<Expr, 29>::type A29; typedef typename proto::result_of::child_c<Expr, 30>::type A30; typedef typename proto::result_of::child_c<Expr, 31>::type A31; typedef typename proto::result_of::child_c<Expr, 32>::type A32; typedef typename proto::result_of::child_c<Expr, 33>::type A33; typedef typename proto::result_of::child_c<Expr, 34>::type A34; typedef typename proto::result_of::child_c<Expr, 35>::type A35; typedef typename proto::result_of::child_c<Expr, 36>::type A36; typedef typename proto::result_of::child_c<Expr, 37>::type A37; typedef typename proto::result_of::child_c<Expr, 38>::type A38;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e) , proto::child_c< 17>(e) , proto::child_c< 18>(e) , proto::child_c< 19>(e) , proto::child_c< 20>(e) , proto::child_c< 21>(e) , proto::child_c< 22>(e) , proto::child_c< 23>(e) , proto::child_c< 24>(e) , proto::child_c< 25>(e) , proto::child_c< 26>(e) , proto::child_c< 27>(e) , proto::child_c< 28>(e) , proto::child_c< 29>(e) , proto::child_c< 30>(e) , proto::child_c< 31>(e) , proto::child_c< 32>(e) , proto::child_c< 33>(e) , proto::child_c< 34>(e) , proto::child_c< 35>(e) , proto::child_c< 36>(e) , proto::child_c< 37>(e) , proto::child_c< 38>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
    
    
    
    
    
    
    
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, 40>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename zr_boost_1_81::zr_boost_1_81phoenix::result_of::context<State, Data>::type
                context_type;
            typedef typename proto::result_of::child_c<Expr, 0>::type A0; typedef typename proto::result_of::child_c<Expr, 1>::type A1; typedef typename proto::result_of::child_c<Expr, 2>::type A2; typedef typename proto::result_of::child_c<Expr, 3>::type A3; typedef typename proto::result_of::child_c<Expr, 4>::type A4; typedef typename proto::result_of::child_c<Expr, 5>::type A5; typedef typename proto::result_of::child_c<Expr, 6>::type A6; typedef typename proto::result_of::child_c<Expr, 7>::type A7; typedef typename proto::result_of::child_c<Expr, 8>::type A8; typedef typename proto::result_of::child_c<Expr, 9>::type A9; typedef typename proto::result_of::child_c<Expr, 10>::type A10; typedef typename proto::result_of::child_c<Expr, 11>::type A11; typedef typename proto::result_of::child_c<Expr, 12>::type A12; typedef typename proto::result_of::child_c<Expr, 13>::type A13; typedef typename proto::result_of::child_c<Expr, 14>::type A14; typedef typename proto::result_of::child_c<Expr, 15>::type A15; typedef typename proto::result_of::child_c<Expr, 16>::type A16; typedef typename proto::result_of::child_c<Expr, 17>::type A17; typedef typename proto::result_of::child_c<Expr, 18>::type A18; typedef typename proto::result_of::child_c<Expr, 19>::type A19; typedef typename proto::result_of::child_c<Expr, 20>::type A20; typedef typename proto::result_of::child_c<Expr, 21>::type A21; typedef typename proto::result_of::child_c<Expr, 22>::type A22; typedef typename proto::result_of::child_c<Expr, 23>::type A23; typedef typename proto::result_of::child_c<Expr, 24>::type A24; typedef typename proto::result_of::child_c<Expr, 25>::type A25; typedef typename proto::result_of::child_c<Expr, 26>::type A26; typedef typename proto::result_of::child_c<Expr, 27>::type A27; typedef typename proto::result_of::child_c<Expr, 28>::type A28; typedef typename proto::result_of::child_c<Expr, 29>::type A29; typedef typename proto::result_of::child_c<Expr, 30>::type A30; typedef typename proto::result_of::child_c<Expr, 31>::type A31; typedef typename proto::result_of::child_c<Expr, 32>::type A32; typedef typename proto::result_of::child_c<Expr, 33>::type A33; typedef typename proto::result_of::child_c<Expr, 34>::type A34; typedef typename proto::result_of::child_c<Expr, 35>::type A35; typedef typename proto::result_of::child_c<Expr, 36>::type A36; typedef typename proto::result_of::child_c<Expr, 37>::type A37; typedef typename proto::result_of::child_c<Expr, 38>::type A38; typedef typename proto::result_of::child_c<Expr, 39>::type A39;
            typedef
                typename zr_boost_1_81::result_of<
                    Fun(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39, context_type)
                >::type
                result_type;
            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        proto::child_c< 0>(e) , proto::child_c< 1>(e) , proto::child_c< 2>(e) , proto::child_c< 3>(e) , proto::child_c< 4>(e) , proto::child_c< 5>(e) , proto::child_c< 6>(e) , proto::child_c< 7>(e) , proto::child_c< 8>(e) , proto::child_c< 9>(e) , proto::child_c< 10>(e) , proto::child_c< 11>(e) , proto::child_c< 12>(e) , proto::child_c< 13>(e) , proto::child_c< 14>(e) , proto::child_c< 15>(e) , proto::child_c< 16>(e) , proto::child_c< 17>(e) , proto::child_c< 18>(e) , proto::child_c< 19>(e) , proto::child_c< 20>(e) , proto::child_c< 21>(e) , proto::child_c< 22>(e) , proto::child_c< 23>(e) , proto::child_c< 24>(e) , proto::child_c< 25>(e) , proto::child_c< 26>(e) , proto::child_c< 27>(e) , proto::child_c< 28>(e) , proto::child_c< 29>(e) , proto::child_c< 30>(e) , proto::child_c< 31>(e) , proto::child_c< 32>(e) , proto::child_c< 33>(e) , proto::child_c< 34>(e) , proto::child_c< 35>(e) , proto::child_c< 36>(e) , proto::child_c< 37>(e) , proto::child_c< 38>(e) , proto::child_c< 39>(e)
                      , zr_boost_1_81::zr_boost_1_81phoenix::context(s, d)
                    );
            }
        };
