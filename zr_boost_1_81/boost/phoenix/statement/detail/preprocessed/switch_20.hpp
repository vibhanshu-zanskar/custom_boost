/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<2>
              , mpl::false_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<2>
              , mpl::true_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break;
                    default:
                        zr_boost_1_81::zr_boost_1_81phoenix::eval(
                            proto::child_c<0>(
                                fusion::deref(
                                    fusion::advance_c<
                                        1
                                    >(fusion::begin(flat_view))
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<3>
              , mpl::false_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<3>
              , mpl::true_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break;
                    default:
                        zr_boost_1_81::zr_boost_1_81phoenix::eval(
                            proto::child_c<0>(
                                fusion::deref(
                                    fusion::advance_c<
                                        2
                                    >(fusion::begin(flat_view))
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<4>
              , mpl::false_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<4>
              , mpl::true_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break;
                    default:
                        zr_boost_1_81::zr_boost_1_81phoenix::eval(
                            proto::child_c<0>(
                                fusion::deref(
                                    fusion::advance_c<
                                        3
                                    >(fusion::begin(flat_view))
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<5>
              , mpl::false_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<5>
              , mpl::true_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break;
                    default:
                        zr_boost_1_81::zr_boost_1_81phoenix::eval(
                            proto::child_c<0>(
                                fusion::deref(
                                    fusion::advance_c<
                                        4
                                    >(fusion::begin(flat_view))
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<6>
              , mpl::false_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<6>
              , mpl::true_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break;
                    default:
                        zr_boost_1_81::zr_boost_1_81phoenix::eval(
                            proto::child_c<0>(
                                fusion::deref(
                                    fusion::advance_c<
                                        5
                                    >(fusion::begin(flat_view))
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<7>
              , mpl::false_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<7>
              , mpl::true_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break;
                    default:
                        zr_boost_1_81::zr_boost_1_81phoenix::eval(
                            proto::child_c<0>(
                                fusion::deref(
                                    fusion::advance_c<
                                        6
                                    >(fusion::begin(flat_view))
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<8>
              , mpl::false_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<8>
              , mpl::true_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break;
                    default:
                        zr_boost_1_81::zr_boost_1_81phoenix::eval(
                            proto::child_c<0>(
                                fusion::deref(
                                    fusion::advance_c<
                                        7
                                    >(fusion::begin(flat_view))
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<9>
              , mpl::false_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 8 >::type >::type case8; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type >::type case_label8;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label8::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 8>(fusion::begin(flat_view)) ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<9>
              , mpl::true_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break;
                    default:
                        zr_boost_1_81::zr_boost_1_81phoenix::eval(
                            proto::child_c<0>(
                                fusion::deref(
                                    fusion::advance_c<
                                        8
                                    >(fusion::begin(flat_view))
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<10>
              , mpl::false_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 8 >::type >::type case8; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type >::type case_label8; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 9 >::type >::type case9; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type >::type case_label9;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label8::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 8>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label9::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 9>(fusion::begin(flat_view)) ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<10>
              , mpl::true_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 8 >::type >::type case8; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type >::type case_label8;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label8::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 8>(fusion::begin(flat_view)) ) ) , ctx ); break;
                    default:
                        zr_boost_1_81::zr_boost_1_81phoenix::eval(
                            proto::child_c<0>(
                                fusion::deref(
                                    fusion::advance_c<
                                        9
                                    >(fusion::begin(flat_view))
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<11>
              , mpl::false_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 8 >::type >::type case8; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type >::type case_label8; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 9 >::type >::type case9; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type >::type case_label9; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 10 >::type >::type case10; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type >::type case_label10;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label8::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 8>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label9::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 9>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label10::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 10>(fusion::begin(flat_view)) ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<11>
              , mpl::true_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 8 >::type >::type case8; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type >::type case_label8; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 9 >::type >::type case9; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type >::type case_label9;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label8::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 8>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label9::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 9>(fusion::begin(flat_view)) ) ) , ctx ); break;
                    default:
                        zr_boost_1_81::zr_boost_1_81phoenix::eval(
                            proto::child_c<0>(
                                fusion::deref(
                                    fusion::advance_c<
                                        10
                                    >(fusion::begin(flat_view))
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<12>
              , mpl::false_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 8 >::type >::type case8; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type >::type case_label8; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 9 >::type >::type case9; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type >::type case_label9; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 10 >::type >::type case10; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type >::type case_label10; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 11 >::type >::type case11; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type >::type case_label11;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label8::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 8>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label9::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 9>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label10::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 10>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label11::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 11>(fusion::begin(flat_view)) ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<12>
              , mpl::true_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 8 >::type >::type case8; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type >::type case_label8; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 9 >::type >::type case9; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type >::type case_label9; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 10 >::type >::type case10; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type >::type case_label10;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label8::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 8>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label9::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 9>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label10::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 10>(fusion::begin(flat_view)) ) ) , ctx ); break;
                    default:
                        zr_boost_1_81::zr_boost_1_81phoenix::eval(
                            proto::child_c<0>(
                                fusion::deref(
                                    fusion::advance_c<
                                        11
                                    >(fusion::begin(flat_view))
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<13>
              , mpl::false_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 8 >::type >::type case8; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type >::type case_label8; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 9 >::type >::type case9; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type >::type case_label9; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 10 >::type >::type case10; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type >::type case_label10; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 11 >::type >::type case11; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type >::type case_label11; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 12 >::type >::type case12; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type >::type case_label12;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label8::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 8>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label9::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 9>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label10::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 10>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label11::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 11>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label12::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 12>(fusion::begin(flat_view)) ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<13>
              , mpl::true_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 8 >::type >::type case8; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type >::type case_label8; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 9 >::type >::type case9; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type >::type case_label9; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 10 >::type >::type case10; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type >::type case_label10; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 11 >::type >::type case11; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type >::type case_label11;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label8::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 8>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label9::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 9>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label10::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 10>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label11::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 11>(fusion::begin(flat_view)) ) ) , ctx ); break;
                    default:
                        zr_boost_1_81::zr_boost_1_81phoenix::eval(
                            proto::child_c<0>(
                                fusion::deref(
                                    fusion::advance_c<
                                        12
                                    >(fusion::begin(flat_view))
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<14>
              , mpl::false_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 8 >::type >::type case8; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type >::type case_label8; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 9 >::type >::type case9; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type >::type case_label9; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 10 >::type >::type case10; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type >::type case_label10; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 11 >::type >::type case11; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type >::type case_label11; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 12 >::type >::type case12; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type >::type case_label12; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 13 >::type >::type case13; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type >::type case_label13;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label8::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 8>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label9::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 9>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label10::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 10>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label11::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 11>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label12::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 12>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label13::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 13>(fusion::begin(flat_view)) ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<14>
              , mpl::true_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 8 >::type >::type case8; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type >::type case_label8; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 9 >::type >::type case9; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type >::type case_label9; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 10 >::type >::type case10; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type >::type case_label10; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 11 >::type >::type case11; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type >::type case_label11; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 12 >::type >::type case12; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type >::type case_label12;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label8::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 8>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label9::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 9>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label10::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 10>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label11::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 11>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label12::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 12>(fusion::begin(flat_view)) ) ) , ctx ); break;
                    default:
                        zr_boost_1_81::zr_boost_1_81phoenix::eval(
                            proto::child_c<0>(
                                fusion::deref(
                                    fusion::advance_c<
                                        13
                                    >(fusion::begin(flat_view))
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<15>
              , mpl::false_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 8 >::type >::type case8; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type >::type case_label8; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 9 >::type >::type case9; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type >::type case_label9; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 10 >::type >::type case10; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type >::type case_label10; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 11 >::type >::type case11; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type >::type case_label11; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 12 >::type >::type case12; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type >::type case_label12; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 13 >::type >::type case13; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type >::type case_label13; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 14 >::type >::type case14; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case14 , 0 >::type >::type >::type case_label14;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label8::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 8>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label9::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 9>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label10::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 10>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label11::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 11>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label12::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 12>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label13::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 13>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label14::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 14>(fusion::begin(flat_view)) ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<15>
              , mpl::true_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 8 >::type >::type case8; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type >::type case_label8; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 9 >::type >::type case9; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type >::type case_label9; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 10 >::type >::type case10; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type >::type case_label10; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 11 >::type >::type case11; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type >::type case_label11; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 12 >::type >::type case12; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type >::type case_label12; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 13 >::type >::type case13; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type >::type case_label13;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label8::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 8>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label9::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 9>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label10::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 10>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label11::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 11>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label12::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 12>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label13::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 13>(fusion::begin(flat_view)) ) ) , ctx ); break;
                    default:
                        zr_boost_1_81::zr_boost_1_81phoenix::eval(
                            proto::child_c<0>(
                                fusion::deref(
                                    fusion::advance_c<
                                        14
                                    >(fusion::begin(flat_view))
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<16>
              , mpl::false_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 8 >::type >::type case8; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type >::type case_label8; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 9 >::type >::type case9; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type >::type case_label9; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 10 >::type >::type case10; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type >::type case_label10; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 11 >::type >::type case11; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type >::type case_label11; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 12 >::type >::type case12; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type >::type case_label12; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 13 >::type >::type case13; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type >::type case_label13; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 14 >::type >::type case14; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case14 , 0 >::type >::type >::type case_label14; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 15 >::type >::type case15; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case15 , 0 >::type >::type >::type case_label15;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label8::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 8>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label9::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 9>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label10::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 10>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label11::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 11>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label12::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 12>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label13::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 13>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label14::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 14>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label15::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 15>(fusion::begin(flat_view)) ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<16>
              , mpl::true_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 8 >::type >::type case8; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type >::type case_label8; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 9 >::type >::type case9; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type >::type case_label9; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 10 >::type >::type case10; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type >::type case_label10; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 11 >::type >::type case11; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type >::type case_label11; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 12 >::type >::type case12; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type >::type case_label12; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 13 >::type >::type case13; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type >::type case_label13; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 14 >::type >::type case14; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case14 , 0 >::type >::type >::type case_label14;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label8::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 8>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label9::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 9>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label10::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 10>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label11::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 11>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label12::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 12>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label13::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 13>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label14::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 14>(fusion::begin(flat_view)) ) ) , ctx ); break;
                    default:
                        zr_boost_1_81::zr_boost_1_81phoenix::eval(
                            proto::child_c<0>(
                                fusion::deref(
                                    fusion::advance_c<
                                        15
                                    >(fusion::begin(flat_view))
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<17>
              , mpl::false_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 8 >::type >::type case8; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type >::type case_label8; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 9 >::type >::type case9; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type >::type case_label9; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 10 >::type >::type case10; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type >::type case_label10; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 11 >::type >::type case11; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type >::type case_label11; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 12 >::type >::type case12; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type >::type case_label12; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 13 >::type >::type case13; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type >::type case_label13; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 14 >::type >::type case14; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case14 , 0 >::type >::type >::type case_label14; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 15 >::type >::type case15; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case15 , 0 >::type >::type >::type case_label15; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 16 >::type >::type case16; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case16 , 0 >::type >::type >::type case_label16;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label8::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 8>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label9::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 9>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label10::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 10>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label11::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 11>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label12::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 12>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label13::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 13>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label14::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 14>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label15::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 15>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label16::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 16>(fusion::begin(flat_view)) ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<17>
              , mpl::true_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 8 >::type >::type case8; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type >::type case_label8; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 9 >::type >::type case9; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type >::type case_label9; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 10 >::type >::type case10; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type >::type case_label10; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 11 >::type >::type case11; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type >::type case_label11; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 12 >::type >::type case12; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type >::type case_label12; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 13 >::type >::type case13; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type >::type case_label13; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 14 >::type >::type case14; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case14 , 0 >::type >::type >::type case_label14; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 15 >::type >::type case15; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case15 , 0 >::type >::type >::type case_label15;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label8::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 8>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label9::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 9>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label10::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 10>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label11::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 11>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label12::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 12>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label13::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 13>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label14::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 14>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label15::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 15>(fusion::begin(flat_view)) ) ) , ctx ); break;
                    default:
                        zr_boost_1_81::zr_boost_1_81phoenix::eval(
                            proto::child_c<0>(
                                fusion::deref(
                                    fusion::advance_c<
                                        16
                                    >(fusion::begin(flat_view))
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<18>
              , mpl::false_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 8 >::type >::type case8; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type >::type case_label8; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 9 >::type >::type case9; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type >::type case_label9; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 10 >::type >::type case10; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type >::type case_label10; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 11 >::type >::type case11; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type >::type case_label11; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 12 >::type >::type case12; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type >::type case_label12; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 13 >::type >::type case13; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type >::type case_label13; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 14 >::type >::type case14; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case14 , 0 >::type >::type >::type case_label14; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 15 >::type >::type case15; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case15 , 0 >::type >::type >::type case_label15; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 16 >::type >::type case16; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case16 , 0 >::type >::type >::type case_label16; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 17 >::type >::type case17; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case17 , 0 >::type >::type >::type case_label17;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label8::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 8>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label9::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 9>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label10::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 10>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label11::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 11>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label12::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 12>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label13::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 13>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label14::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 14>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label15::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 15>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label16::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 16>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label17::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 17>(fusion::begin(flat_view)) ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<18>
              , mpl::true_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 8 >::type >::type case8; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type >::type case_label8; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 9 >::type >::type case9; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type >::type case_label9; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 10 >::type >::type case10; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type >::type case_label10; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 11 >::type >::type case11; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type >::type case_label11; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 12 >::type >::type case12; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type >::type case_label12; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 13 >::type >::type case13; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type >::type case_label13; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 14 >::type >::type case14; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case14 , 0 >::type >::type >::type case_label14; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 15 >::type >::type case15; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case15 , 0 >::type >::type >::type case_label15; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 16 >::type >::type case16; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case16 , 0 >::type >::type >::type case_label16;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label8::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 8>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label9::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 9>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label10::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 10>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label11::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 11>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label12::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 12>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label13::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 13>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label14::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 14>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label15::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 15>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label16::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 16>(fusion::begin(flat_view)) ) ) , ctx ); break;
                    default:
                        zr_boost_1_81::zr_boost_1_81phoenix::eval(
                            proto::child_c<0>(
                                fusion::deref(
                                    fusion::advance_c<
                                        17
                                    >(fusion::begin(flat_view))
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<19>
              , mpl::false_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 8 >::type >::type case8; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type >::type case_label8; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 9 >::type >::type case9; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type >::type case_label9; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 10 >::type >::type case10; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type >::type case_label10; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 11 >::type >::type case11; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type >::type case_label11; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 12 >::type >::type case12; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type >::type case_label12; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 13 >::type >::type case13; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type >::type case_label13; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 14 >::type >::type case14; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case14 , 0 >::type >::type >::type case_label14; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 15 >::type >::type case15; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case15 , 0 >::type >::type >::type case_label15; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 16 >::type >::type case16; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case16 , 0 >::type >::type >::type case_label16; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 17 >::type >::type case17; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case17 , 0 >::type >::type >::type case_label17; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 18 >::type >::type case18; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case18 , 0 >::type >::type >::type case_label18;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label8::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 8>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label9::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 9>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label10::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 10>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label11::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 11>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label12::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 12>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label13::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 13>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label14::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 14>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label15::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 15>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label16::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 16>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label17::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 17>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label18::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 18>(fusion::begin(flat_view)) ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<19>
              , mpl::true_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 8 >::type >::type case8; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type >::type case_label8; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 9 >::type >::type case9; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type >::type case_label9; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 10 >::type >::type case10; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type >::type case_label10; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 11 >::type >::type case11; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type >::type case_label11; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 12 >::type >::type case12; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type >::type case_label12; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 13 >::type >::type case13; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type >::type case_label13; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 14 >::type >::type case14; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case14 , 0 >::type >::type >::type case_label14; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 15 >::type >::type case15; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case15 , 0 >::type >::type >::type case_label15; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 16 >::type >::type case16; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case16 , 0 >::type >::type >::type case_label16; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 17 >::type >::type case17; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case17 , 0 >::type >::type >::type case_label17;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label8::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 8>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label9::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 9>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label10::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 10>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label11::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 11>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label12::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 12>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label13::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 13>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label14::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 14>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label15::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 15>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label16::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 16>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label17::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 17>(fusion::begin(flat_view)) ) ) , ctx ); break;
                    default:
                        zr_boost_1_81::zr_boost_1_81phoenix::eval(
                            proto::child_c<0>(
                                fusion::deref(
                                    fusion::advance_c<
                                        18
                                    >(fusion::begin(flat_view))
                                )
                            )
                            , ctx
                        );
                }
            }
    
    
    
    
    
    
    
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<20>
              , mpl::false_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 8 >::type >::type case8; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type >::type case_label8; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 9 >::type >::type case9; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type >::type case_label9; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 10 >::type >::type case10; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type >::type case_label10; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 11 >::type >::type case11; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type >::type case_label11; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 12 >::type >::type case12; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type >::type case_label12; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 13 >::type >::type case13; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type >::type case_label13; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 14 >::type >::type case14; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case14 , 0 >::type >::type >::type case_label14; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 15 >::type >::type case15; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case15 , 0 >::type >::type >::type case_label15; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 16 >::type >::type case16; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case16 , 0 >::type >::type >::type case_label16; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 17 >::type >::type case17; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case17 , 0 >::type >::type >::type case_label17; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 18 >::type >::type case18; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case18 , 0 >::type >::type >::type case_label18; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 19 >::type >::type case19; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case19 , 0 >::type >::type >::type case_label19;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label8::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 8>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label9::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 9>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label10::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 10>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label11::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 11>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label12::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 12>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label13::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 13>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label14::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 14>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label15::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 15>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label16::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 16>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label17::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 17>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label18::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 18>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label19::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 19>(fusion::begin(flat_view)) ) ) , ctx ); break;
                }
            }
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context const & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<20>
              , mpl::true_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;
                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;
                flat_view_type flat_view(proto::flatten(cases));
                typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 0 >::type >::type case0; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case0 , 0 >::type >::type >::type case_label0; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 1 >::type >::type case1; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case1 , 0 >::type >::type >::type case_label1; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 2 >::type >::type case2; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case2 , 0 >::type >::type >::type case_label2; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 3 >::type >::type case3; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case3 , 0 >::type >::type >::type case_label3; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 4 >::type >::type case4; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case4 , 0 >::type >::type >::type case_label4; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 5 >::type >::type case5; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case5 , 0 >::type >::type >::type case_label5; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 6 >::type >::type case6; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case6 , 0 >::type >::type >::type case_label6; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 7 >::type >::type case7; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case7 , 0 >::type >::type >::type case_label7; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 8 >::type >::type case8; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case8 , 0 >::type >::type >::type case_label8; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 9 >::type >::type case9; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case9 , 0 >::type >::type >::type case_label9; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 10 >::type >::type case10; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case10 , 0 >::type >::type >::type case_label10; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 11 >::type >::type case11; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case11 , 0 >::type >::type >::type case_label11; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 12 >::type >::type case12; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case12 , 0 >::type >::type >::type case_label12; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 13 >::type >::type case13; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case13 , 0 >::type >::type >::type case_label13; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 14 >::type >::type case14; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case14 , 0 >::type >::type >::type case_label14; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 15 >::type >::type case15; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case15 , 0 >::type >::type >::type case_label15; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 16 >::type >::type case16; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case16 , 0 >::type >::type >::type case_label16; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 17 >::type >::type case17; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case17 , 0 >::type >::type >::type case_label17; typedef typename fusion::result_of::deref< typename fusion::result_of::advance_c< flat_view_begin , 18 >::type >::type case18; typedef typename proto::detail::uncvref< typename proto::result_of::value< typename proto::result_of::child_c< case18 , 0 >::type >::type >::type case_label18;
                switch(zr_boost_1_81::zr_boost_1_81phoenix::eval(cond, ctx))
                {
                    case case_label0::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 0>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label1::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 1>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label2::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 2>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label3::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 3>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label4::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 4>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label5::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 5>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label6::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 6>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label7::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 7>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label8::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 8>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label9::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 9>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label10::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 10>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label11::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 11>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label12::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 12>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label13::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 13>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label14::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 14>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label15::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 15>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label16::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 16>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label17::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 17>(fusion::begin(flat_view)) ) ) , ctx ); break; case case_label18::value : zr_boost_1_81::zr_boost_1_81phoenix::eval( proto::child_c<1>( fusion::deref( fusion::advance_c< 18>(fusion::begin(flat_view)) ) ) , ctx ); break;
                    default:
                        zr_boost_1_81::zr_boost_1_81phoenix::eval(
                            proto::child_c<0>(
                                fusion::deref(
                                    fusion::advance_c<
                                        19
                                    >(fusion::begin(flat_view))
                                )
                            )
                            , ctx
                        );
                }
            }
