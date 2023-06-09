/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1, typename Context>
        struct result<This(A0 , A1, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2, typename Context>
        struct result<This(A0 , A1 , A2, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3, typename Context>
        struct result<This(A0 , A1 , A2 , A3, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a29, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a29, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a30, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a29, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a30, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a31, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a29, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a30, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a31, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a32, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a29, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a30, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a31, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a32, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a33, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a29, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a30, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a31, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a32, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a33, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a34, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a29, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a30, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a31, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a32, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a33, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a34, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a35, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a29, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a30, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a31, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a32, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a33, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a34, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a35, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a36, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a29, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a30, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a31, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a32, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a33, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a34, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a35, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a36, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a37, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a29, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a30, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a31, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a32, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a33, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a34, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a35, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a36, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a37, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a38, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38 , A39 const& a39
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a29, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a30, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a31, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a32, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a33, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a34, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a35, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a36, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a37, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a38, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a39, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38 , A39 const& a39 , A40 const& a40
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a29, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a30, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a31, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a32, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a33, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a34, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a35, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a36, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a37, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a38, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a39, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a40, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38 , A39 const& a39 , A40 const& a40 , A41 const& a41
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a29, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a30, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a31, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a32, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a33, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a34, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a35, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a36, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a37, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a38, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a39, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a40, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a41, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38 , A39 const& a39 , A40 const& a40 , A41 const& a41 , A42 const& a42
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a29, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a30, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a31, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a32, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a33, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a34, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a35, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a36, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a37, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a38, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a39, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a40, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a41, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a42, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38 , A39 const& a39 , A40 const& a40 , A41 const& a41 , A42 const& a42 , A43 const& a43
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a29, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a30, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a31, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a32, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a33, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a34, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a35, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a36, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a37, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a38, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a39, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a40, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a41, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a42, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a43, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38 , A39 const& a39 , A40 const& a40 , A41 const& a41 , A42 const& a42 , A43 const& a43 , A44 const& a44
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a29, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a30, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a31, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a32, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a33, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a34, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a35, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a36, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a37, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a38, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a39, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a40, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a41, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a42, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a43, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a44, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44 , typename A45, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44 , typename A45, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38 , A39 const& a39 , A40 const& a40 , A41 const& a41 , A42 const& a42 , A43 const& a43 , A44 const& a44 , A45 const& a45
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a29, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a30, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a31, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a32, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a33, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a34, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a35, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a36, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a37, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a38, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a39, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a40, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a41, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a42, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a43, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a44, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a45, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44 , typename A45 , typename A46, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44 , typename A45 , typename A46, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38 , A39 const& a39 , A40 const& a40 , A41 const& a41 , A42 const& a42 , A43 const& a43 , A44 const& a44 , A45 const& a45 , A46 const& a46
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a29, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a30, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a31, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a32, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a33, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a34, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a35, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a36, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a37, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a38, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a39, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a40, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a41, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a42, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a43, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a44, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a45, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a46, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44 , typename A45 , typename A46 , typename A47, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44 , typename A45 , typename A46 , typename A47, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38 , A39 const& a39 , A40 const& a40 , A41 const& a41 , A42 const& a42 , A43 const& a43 , A44 const& a44 , A45 const& a45 , A46 const& a46 , A47 const& a47
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a29, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a30, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a31, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a32, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a33, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a34, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a35, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a36, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a37, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a38, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a39, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a40, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a41, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a42, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a43, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a44, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a45, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a46, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a47, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44 , typename A45 , typename A46 , typename A47 , typename A48, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44 , typename A45 , typename A46 , typename A47 , typename A48, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38 , A39 const& a39 , A40 const& a40 , A41 const& a41 , A42 const& a42 , A43 const& a43 , A44 const& a44 , A45 const& a45 , A46 const& a46 , A47 const& a47 , A48 const& a48
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a29, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a30, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a31, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a32, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a33, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a34, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a35, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a36, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a37, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a38, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a39, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a40, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a41, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a42, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a43, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a44, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a45, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a46, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a47, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a48, ctx)
                );
        }
    
    
    
    
    
    
    
        template <typename This, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44 , typename A45 , typename A46 , typename A47 , typename A48 , typename A49, typename Context>
        struct result<This(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 , A49, Context)>
            : detail::result_of::target<A0>
        {
        };
        
        template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22 , typename A23 , typename A24 , typename A25 , typename A26 , typename A27 , typename A28 , typename A29 , typename A30 , typename A31 , typename A32 , typename A33 , typename A34 , typename A35 , typename A36 , typename A37 , typename A38 , typename A39 , typename A40 , typename A41 , typename A42 , typename A43 , typename A44 , typename A45 , typename A46 , typename A47 , typename A48 , typename A49, typename Context>
        typename detail::result_of::target<A0>::type
        operator()(
            A0 const&
          , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8 , A9 const& a9 , A10 const& a10 , A11 const& a11 , A12 const& a12 , A13 const& a13 , A14 const& a14 , A15 const& a15 , A16 const& a16 , A17 const& a17 , A18 const& a18 , A19 const& a19 , A20 const& a20 , A21 const& a21 , A22 const& a22 , A23 const& a23 , A24 const& a24 , A25 const& a25 , A26 const& a26 , A27 const& a27 , A28 const& a28 , A29 const& a29 , A30 const& a30 , A31 const& a31 , A32 const& a32 , A33 const& a33 , A34 const& a34 , A35 const& a35 , A36 const& a36 , A37 const& a37 , A38 const& a38 , A39 const& a39 , A40 const& a40 , A41 const& a41 , A42 const& a42 , A43 const& a43 , A44 const& a44 , A45 const& a45 , A46 const& a46 , A47 const& a47 , A48 const& a48 , A49 const& a49
          , Context const & ctx
        ) const
        {
            return
                typename detail::result_of::target<A0>::type(
                    zr_boost_1_81::zr_boost_1_81phoenix::eval(a1, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a2, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a3, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a4, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a5, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a6, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a7, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a8, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a9, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a10, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a11, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a12, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a13, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a14, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a15, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a16, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a17, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a18, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a19, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a20, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a21, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a22, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a23, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a24, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a25, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a26, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a27, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a28, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a29, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a30, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a31, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a32, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a33, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a34, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a35, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a36, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a37, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a38, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a39, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a40, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a41, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a42, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a43, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a44, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a45, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a46, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a47, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a48, ctx) , zr_boost_1_81::zr_boost_1_81phoenix::eval(a49, ctx)
                );
        }
