/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
        
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0
              , typename Context
            >
            struct result<This(F, A0, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0)>::type
                    type;
                
            };
            template <typename F, typename A0, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)));
            }
            template <typename F, typename A0, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1
              , typename Context
            >
            struct result<This(F, A0 , A1, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)));
            }
            template <typename F, typename A0 , typename A1, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5 , A6, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A6 , Context ) >::type >::type >::type a6;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5 , a6)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A6 , Context ) >::type >::type >::type a6; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A7 , Context ) >::type >::type >::type a7;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A6 , Context ) >::type >::type >::type a6; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A7 , Context ) >::type >::type >::type a7; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A8 , Context ) >::type >::type >::type a8;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A6 , Context ) >::type >::type >::type a6; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A7 , Context ) >::type >::type >::type a7; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A8 , Context ) >::type >::type >::type a8; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A9 , Context ) >::type >::type >::type a9;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A6 , Context ) >::type >::type >::type a6; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A7 , Context ) >::type >::type >::type a7; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A8 , Context ) >::type >::type >::type a8; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A9 , Context ) >::type >::type >::type a9; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A10 , Context ) >::type >::type >::type a10;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A6 , Context ) >::type >::type >::type a6; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A7 , Context ) >::type >::type >::type a7; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A8 , Context ) >::type >::type >::type a8; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A9 , Context ) >::type >::type >::type a9; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A10 , Context ) >::type >::type >::type a10; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A11 , Context ) >::type >::type >::type a11;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A6 , Context ) >::type >::type >::type a6; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A7 , Context ) >::type >::type >::type a7; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A8 , Context ) >::type >::type >::type a8; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A9 , Context ) >::type >::type >::type a9; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A10 , Context ) >::type >::type >::type a10; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A11 , Context ) >::type >::type >::type a11; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A12 , Context ) >::type >::type >::type a12;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A6 , Context ) >::type >::type >::type a6; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A7 , Context ) >::type >::type >::type a7; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A8 , Context ) >::type >::type >::type a8; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A9 , Context ) >::type >::type >::type a9; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A10 , Context ) >::type >::type >::type a10; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A11 , Context ) >::type >::type >::type a11; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A12 , Context ) >::type >::type >::type a12; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A13 , Context ) >::type >::type >::type a13;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A6 , Context ) >::type >::type >::type a6; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A7 , Context ) >::type >::type >::type a7; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A8 , Context ) >::type >::type >::type a8; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A9 , Context ) >::type >::type >::type a9; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A10 , Context ) >::type >::type >::type a10; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A11 , Context ) >::type >::type >::type a11; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A12 , Context ) >::type >::type >::type a12; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A13 , Context ) >::type >::type >::type a13; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A14 , Context ) >::type >::type >::type a14;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A6 , Context ) >::type >::type >::type a6; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A7 , Context ) >::type >::type >::type a7; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A8 , Context ) >::type >::type >::type a8; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A9 , Context ) >::type >::type >::type a9; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A10 , Context ) >::type >::type >::type a10; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A11 , Context ) >::type >::type >::type a11; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A12 , Context ) >::type >::type >::type a12; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A13 , Context ) >::type >::type >::type a13; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A14 , Context ) >::type >::type >::type a14; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A15 , Context ) >::type >::type >::type a15;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A6 , Context ) >::type >::type >::type a6; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A7 , Context ) >::type >::type >::type a7; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A8 , Context ) >::type >::type >::type a8; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A9 , Context ) >::type >::type >::type a9; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A10 , Context ) >::type >::type >::type a10; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A11 , Context ) >::type >::type >::type a11; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A12 , Context ) >::type >::type >::type a12; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A13 , Context ) >::type >::type >::type a13; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A14 , Context ) >::type >::type >::type a14; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A15 , Context ) >::type >::type >::type a15; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A16 , Context ) >::type >::type >::type a16;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A6 , Context ) >::type >::type >::type a6; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A7 , Context ) >::type >::type >::type a7; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A8 , Context ) >::type >::type >::type a8; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A9 , Context ) >::type >::type >::type a9; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A10 , Context ) >::type >::type >::type a10; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A11 , Context ) >::type >::type >::type a11; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A12 , Context ) >::type >::type >::type a12; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A13 , Context ) >::type >::type >::type a13; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A14 , Context ) >::type >::type >::type a14; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A15 , Context ) >::type >::type >::type a15; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A16 , Context ) >::type >::type >::type a16; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A17 , Context ) >::type >::type >::type a17;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A6 , Context ) >::type >::type >::type a6; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A7 , Context ) >::type >::type >::type a7; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A8 , Context ) >::type >::type >::type a8; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A9 , Context ) >::type >::type >::type a9; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A10 , Context ) >::type >::type >::type a10; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A11 , Context ) >::type >::type >::type a11; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A12 , Context ) >::type >::type >::type a12; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A13 , Context ) >::type >::type >::type a13; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A14 , Context ) >::type >::type >::type a14; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A15 , Context ) >::type >::type >::type a15; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A16 , Context ) >::type >::type >::type a16; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A17 , Context ) >::type >::type >::type a17; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A18 , Context ) >::type >::type >::type a18;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A6 , Context ) >::type >::type >::type a6; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A7 , Context ) >::type >::type >::type a7; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A8 , Context ) >::type >::type >::type a8; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A9 , Context ) >::type >::type >::type a9; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A10 , Context ) >::type >::type >::type a10; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A11 , Context ) >::type >::type >::type a11; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A12 , Context ) >::type >::type >::type a12; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A13 , Context ) >::type >::type >::type a13; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A14 , Context ) >::type >::type >::type a14; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A15 , Context ) >::type >::type >::type a15; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A16 , Context ) >::type >::type >::type a16; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A17 , Context ) >::type >::type >::type a17; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A18 , Context ) >::type >::type >::type a18; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A19 , Context ) >::type >::type >::type a19;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18 , A19 & a19, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18 , A19 & a19, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A6 , Context ) >::type >::type >::type a6; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A7 , Context ) >::type >::type >::type a7; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A8 , Context ) >::type >::type >::type a8; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A9 , Context ) >::type >::type >::type a9; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A10 , Context ) >::type >::type >::type a10; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A11 , Context ) >::type >::type >::type a11; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A12 , Context ) >::type >::type >::type a12; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A13 , Context ) >::type >::type >::type a13; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A14 , Context ) >::type >::type >::type a14; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A15 , Context ) >::type >::type >::type a15; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A16 , Context ) >::type >::type >::type a16; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A17 , Context ) >::type >::type >::type a17; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A18 , Context ) >::type >::type >::type a18; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A19 , Context ) >::type >::type >::type a19; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A20 , Context ) >::type >::type >::type a20;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 & , A20 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18 , A19 & a19 , A20 & a20, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 & , A20 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18 , A19 & a19 , A20 & a20, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A6 , Context ) >::type >::type >::type a6; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A7 , Context ) >::type >::type >::type a7; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A8 , Context ) >::type >::type >::type a8; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A9 , Context ) >::type >::type >::type a9; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A10 , Context ) >::type >::type >::type a10; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A11 , Context ) >::type >::type >::type a11; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A12 , Context ) >::type >::type >::type a12; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A13 , Context ) >::type >::type >::type a13; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A14 , Context ) >::type >::type >::type a14; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A15 , Context ) >::type >::type >::type a15; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A16 , Context ) >::type >::type >::type a16; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A17 , Context ) >::type >::type >::type a17; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A18 , Context ) >::type >::type >::type a18; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A19 , Context ) >::type >::type >::type a19; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A20 , Context ) >::type >::type >::type a20; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A21 , Context ) >::type >::type >::type a21;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 & , A20 & , A21 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18 , A19 & a19 , A20 & a20 , A21 & a21, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 & , A20 & , A21 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18 , A19 & a19 , A20 & a20 , A21 & a21, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A6 , Context ) >::type >::type >::type a6; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A7 , Context ) >::type >::type >::type a7; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A8 , Context ) >::type >::type >::type a8; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A9 , Context ) >::type >::type >::type a9; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A10 , Context ) >::type >::type >::type a10; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A11 , Context ) >::type >::type >::type a11; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A12 , Context ) >::type >::type >::type a12; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A13 , Context ) >::type >::type >::type a13; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A14 , Context ) >::type >::type >::type a14; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A15 , Context ) >::type >::type >::type a15; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A16 , Context ) >::type >::type >::type a16; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A17 , Context ) >::type >::type >::type a17; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A18 , Context ) >::type >::type >::type a18; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A19 , Context ) >::type >::type >::type a19; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A20 , Context ) >::type >::type >::type a20; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A21 , Context ) >::type >::type >::type a21; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A22 , Context ) >::type >::type >::type a22;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 & , A20 & , A21 & , A22 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18 , A19 & a19 , A20 & a20 , A21 & a21 , A22 & a22, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 & , A20 & , A21 & , A22 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18 , A19 & a19 , A20 & a20 , A21 & a21 , A22 & a22, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A6 , Context ) >::type >::type >::type a6; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A7 , Context ) >::type >::type >::type a7; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A8 , Context ) >::type >::type >::type a8; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A9 , Context ) >::type >::type >::type a9; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A10 , Context ) >::type >::type >::type a10; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A11 , Context ) >::type >::type >::type a11; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A12 , Context ) >::type >::type >::type a12; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A13 , Context ) >::type >::type >::type a13; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A14 , Context ) >::type >::type >::type a14; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A15 , Context ) >::type >::type >::type a15; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A16 , Context ) >::type >::type >::type a16; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A17 , Context ) >::type >::type >::type a17; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A18 , Context ) >::type >::type >::type a18; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A19 , Context ) >::type >::type >::type a19; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A20 , Context ) >::type >::type >::type a20; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A21 , Context ) >::type >::type >::type a21; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A22 , Context ) >::type >::type >::type a22; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A23 , Context ) >::type >::type >::type a23;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 & , A20 & , A21 & , A22 & , A23 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18 , A19 & a19 , A20 & a20 , A21 & a21 , A22 & a22 , A23 & a23, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 & , A20 & , A21 & , A22 & , A23 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18 , A19 & a19 , A20 & a20 , A21 & a21 , A22 & a22 , A23 & a23, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A6 , Context ) >::type >::type >::type a6; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A7 , Context ) >::type >::type >::type a7; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A8 , Context ) >::type >::type >::type a8; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A9 , Context ) >::type >::type >::type a9; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A10 , Context ) >::type >::type >::type a10; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A11 , Context ) >::type >::type >::type a11; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A12 , Context ) >::type >::type >::type a12; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A13 , Context ) >::type >::type >::type a13; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A14 , Context ) >::type >::type >::type a14; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A15 , Context ) >::type >::type >::type a15; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A16 , Context ) >::type >::type >::type a16; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A17 , Context ) >::type >::type >::type a17; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A18 , Context ) >::type >::type >::type a18; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A19 , Context ) >::type >::type >::type a19; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A20 , Context ) >::type >::type >::type a20; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A21 , Context ) >::type >::type >::type a21; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A22 , Context ) >::type >::type >::type a22; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A23 , Context ) >::type >::type >::type a23; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A24 , Context ) >::type >::type >::type a24;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 & , A20 & , A21 & , A22 & , A23 & , A24 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18 , A19 & a19 , A20 & a20 , A21 & a21 , A22 & a22 , A23 & a23 , A24 & a24, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 & , A20 & , A21 & , A22 & , A23 & , A24 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18 , A19 & a19 , A20 & a20 , A21 & a21 , A22 & a22 , A23 & a23 , A24 & a24, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A6 , Context ) >::type >::type >::type a6; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A7 , Context ) >::type >::type >::type a7; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A8 , Context ) >::type >::type >::type a8; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A9 , Context ) >::type >::type >::type a9; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A10 , Context ) >::type >::type >::type a10; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A11 , Context ) >::type >::type >::type a11; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A12 , Context ) >::type >::type >::type a12; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A13 , Context ) >::type >::type >::type a13; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A14 , Context ) >::type >::type >::type a14; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A15 , Context ) >::type >::type >::type a15; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A16 , Context ) >::type >::type >::type a16; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A17 , Context ) >::type >::type >::type a17; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A18 , Context ) >::type >::type >::type a18; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A19 , Context ) >::type >::type >::type a19; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A20 , Context ) >::type >::type >::type a20; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A21 , Context ) >::type >::type >::type a21; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A22 , Context ) >::type >::type >::type a22; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A23 , Context ) >::type >::type >::type a23; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A24 , Context ) >::type >::type >::type a24; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A25 , Context ) >::type >::type >::type a25;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 & , A20 & , A21 & , A22 & , A23 & , A24 & , A25 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18 , A19 & a19 , A20 & a20 , A21 & a21 , A22 & a22 , A23 & a23 , A24 & a24 , A25 & a25, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 & , A20 & , A21 & , A22 & , A23 & , A24 & , A25 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18 , A19 & a19 , A20 & a20 , A21 & a21 , A22 & a22 , A23 & a23 , A24 & a24 , A25 & a25, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A6 , Context ) >::type >::type >::type a6; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A7 , Context ) >::type >::type >::type a7; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A8 , Context ) >::type >::type >::type a8; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A9 , Context ) >::type >::type >::type a9; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A10 , Context ) >::type >::type >::type a10; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A11 , Context ) >::type >::type >::type a11; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A12 , Context ) >::type >::type >::type a12; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A13 , Context ) >::type >::type >::type a13; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A14 , Context ) >::type >::type >::type a14; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A15 , Context ) >::type >::type >::type a15; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A16 , Context ) >::type >::type >::type a16; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A17 , Context ) >::type >::type >::type a17; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A18 , Context ) >::type >::type >::type a18; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A19 , Context ) >::type >::type >::type a19; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A20 , Context ) >::type >::type >::type a20; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A21 , Context ) >::type >::type >::type a21; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A22 , Context ) >::type >::type >::type a22; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A23 , Context ) >::type >::type >::type a23; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A24 , Context ) >::type >::type >::type a24; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A25 , Context ) >::type >::type >::type a25; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A26 , Context ) >::type >::type >::type a26;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 & , A20 & , A21 & , A22 & , A23 & , A24 & , A25 & , A26 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18 , A19 & a19 , A20 & a20 , A21 & a21 , A22 & a22 , A23 & a23 , A24 & a24 , A25 & a25 , A26 & a26, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 & , A20 & , A21 & , A22 & , A23 & , A24 & , A25 & , A26 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18 , A19 & a19 , A20 & a20 , A21 & a21 , A22 & a22 , A23 & a23 , A24 & a24 , A25 & a25 , A26 & a26, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A6 , Context ) >::type >::type >::type a6; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A7 , Context ) >::type >::type >::type a7; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A8 , Context ) >::type >::type >::type a8; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A9 , Context ) >::type >::type >::type a9; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A10 , Context ) >::type >::type >::type a10; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A11 , Context ) >::type >::type >::type a11; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A12 , Context ) >::type >::type >::type a12; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A13 , Context ) >::type >::type >::type a13; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A14 , Context ) >::type >::type >::type a14; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A15 , Context ) >::type >::type >::type a15; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A16 , Context ) >::type >::type >::type a16; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A17 , Context ) >::type >::type >::type a17; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A18 , Context ) >::type >::type >::type a18; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A19 , Context ) >::type >::type >::type a19; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A20 , Context ) >::type >::type >::type a20; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A21 , Context ) >::type >::type >::type a21; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A22 , Context ) >::type >::type >::type a22; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A23 , Context ) >::type >::type >::type a23; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A24 , Context ) >::type >::type >::type a24; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A25 , Context ) >::type >::type >::type a25; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A26 , Context ) >::type >::type >::type a26; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A27 , Context ) >::type >::type >::type a27;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 & , A20 & , A21 & , A22 & , A23 & , A24 & , A25 & , A26 & , A27 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18 , A19 & a19 , A20 & a20 , A21 & a21 , A22 & a22 , A23 & a23 , A24 & a24 , A25 & a25 , A26 & a26 , A27 & a27, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 & , A20 & , A21 & , A22 & , A23 & , A24 & , A25 & , A26 & , A27 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18 , A19 & a19 , A20 & a20 , A21 & a21 , A22 & a22 , A23 & a23 , A24 & a24 , A25 & a25 , A26 & a26 , A27 & a27, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx)));
            }
    
    
    
    
    
    
    
            template <
                typename This
              , typename F
              , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28
              , typename Context
            >
            struct result<This(F, A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28, Context)>
            {
                typedef typename
                    remove_reference<
                        typename zr_boost_1_81::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;
                typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A0 , Context ) >::type >::type >::type a0; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A1 , Context ) >::type >::type >::type a1; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A2 , Context ) >::type >::type >::type a2; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A3 , Context ) >::type >::type >::type a3; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A4 , Context ) >::type >::type >::type a4; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A5 , Context ) >::type >::type >::type a5; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A6 , Context ) >::type >::type >::type a6; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A7 , Context ) >::type >::type >::type a7; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A8 , Context ) >::type >::type >::type a8; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A9 , Context ) >::type >::type >::type a9; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A10 , Context ) >::type >::type >::type a10; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A11 , Context ) >::type >::type >::type a11; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A12 , Context ) >::type >::type >::type a12; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A13 , Context ) >::type >::type >::type a13; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A14 , Context ) >::type >::type >::type a14; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A15 , Context ) >::type >::type >::type a15; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A16 , Context ) >::type >::type >::type a16; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A17 , Context ) >::type >::type >::type a17; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A18 , Context ) >::type >::type >::type a18; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A19 , Context ) >::type >::type >::type a19; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A20 , Context ) >::type >::type >::type a20; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A21 , Context ) >::type >::type >::type a21; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A22 , Context ) >::type >::type >::type a22; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A23 , Context ) >::type >::type >::type a23; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A24 , Context ) >::type >::type >::type a24; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A25 , Context ) >::type >::type >::type a25; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A26 , Context ) >::type >::type >::type a26; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A27 , Context ) >::type >::type >::type a27; typedef typename zr_boost_1_81::add_reference< typename zr_boost_1_81::add_const< typename zr_boost_1_81::result_of< zr_boost_1_81::zr_boost_1_81phoenix::evaluator( A28 , Context ) >::type >::type >::type a28;
                typedef typename
                    zr_boost_1_81::result_of<fn(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12 , a13 , a14 , a15 , a16 , a17 , a18 , a19 , a20 , a21 , a22 , a23 , a24 , a25 , a26 , a27 , a28)>::type
                    type;
                
            };
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28, typename Context>
            typename result<
                function_eval(
                    F const &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 & , A20 & , A21 & , A22 & , A23 & , A24 & , A25 & , A26 & , A27 & , A28 &
                  , Context const &
                )
            >::type
            operator()(F const & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18 , A19 & a19 , A20 & a20 , A21 & a21 , A22 & a22 , A23 & a23 , A24 & a24 , A25 & a25 , A26 & a26 , A27 & a27 , A28 & a28, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx)));
            }
            template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28, typename Context>
            typename result<
                function_eval(
                    F &
                  , A0 & , A1 & , A2 & , A3 & , A4 & , A5 & , A6 & , A7 & , A8 & , A9 & , A10 & , A11 & , A12 & , A13 & , A14 & , A15 & , A16 & , A17 & , A18 & , A19 & , A20 & , A21 & , A22 & , A23 & , A24 & , A25 & , A26 & , A27 & , A28 &
                  , Context const &
                )
            >::type
            operator()(F & f, A0 & a0 , A1 & a1 , A2 & a2 , A3 & a3 , A4 & a4 , A5 & a5 , A6 & a6 , A7 & a7 , A8 & a8 , A9 & a9 , A10 & a10 , A11 & a11 , A12 & a12 , A13 & a13 , A14 & a14 , A15 & a15 , A16 & a16 , A17 & a17 , A18 & a18 , A19 & a19 , A20 & a20 , A21 & a21 , A22 & a22 , A23 & a23 , A24 & a24 , A25 & a25 , A26 & a26 , A27 & a27 , A28 & a28, Context const & ctx) const
            {
                return zr_boost_1_81::zr_boost_1_81phoenix::eval(f, ctx)(help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a0, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx)) , help_rvalue_deduction(zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx)));
            }
