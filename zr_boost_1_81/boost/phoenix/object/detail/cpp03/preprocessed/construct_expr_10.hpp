/*==============================================================================
    Copyright (c) 2016 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
namespace zr_boost_1_81 { namespace zr_boost_1_81phoenix { namespace tag { struct construct {}; template <typename Ostream> inline Ostream &operator<<( Ostream & os , construct) { os << "construct"; return os; } } namespace expression { template < typename A0 = void , typename A1 = void , typename A2 = void , typename A3 = void , typename A4 = void , typename A5 = void , typename A6 = void , typename A7 = void , typename A8 = void , typename A9 = void , typename A10 = void , typename Dummy = void > struct construct; template < typename A0 , typename A1 > struct construct< A0 , A1 > : zr_boost_1_81::zr_boost_1_81phoenix::expr< tag:: construct , A0 , A1 > {}; template < typename A0 , typename A1 , typename A2 > struct construct< A0 , A1 , A2 > : zr_boost_1_81::zr_boost_1_81phoenix::expr< tag:: construct , A0 , A1 , A2 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 > struct construct< A0 , A1 , A2 , A3 > : zr_boost_1_81::zr_boost_1_81phoenix::expr< tag:: construct , A0 , A1 , A2 , A3 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 > struct construct< A0 , A1 , A2 , A3 , A4 > : zr_boost_1_81::zr_boost_1_81phoenix::expr< tag:: construct , A0 , A1 , A2 , A3 , A4 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 > struct construct< A0 , A1 , A2 , A3 , A4 , A5 > : zr_boost_1_81::zr_boost_1_81phoenix::expr< tag:: construct , A0 , A1 , A2 , A3 , A4 , A5 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 > struct construct< A0 , A1 , A2 , A3 , A4 , A5 , A6 > : zr_boost_1_81::zr_boost_1_81phoenix::expr< tag:: construct , A0 , A1 , A2 , A3 , A4 , A5 , A6 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 > struct construct< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 > : zr_boost_1_81::zr_boost_1_81phoenix::expr< tag:: construct , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 > struct construct< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 > : zr_boost_1_81::zr_boost_1_81phoenix::expr< tag:: construct , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 > struct construct< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 > : zr_boost_1_81::zr_boost_1_81phoenix::expr< tag:: construct , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 > {}; template < typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 > struct construct< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 > : zr_boost_1_81::zr_boost_1_81phoenix::expr< tag:: construct , A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 > {}; } namespace rule { struct construct : expression:: construct < proto::terminal<detail::target<proto::_> > , zr_boost_1_81::proto::vararg< meta_grammar > > {}; } namespace functional { typedef zr_boost_1_81::proto::functional::make_expr< tag:: construct > make_construct; } namespace result_of { template <typename A0 = void , typename A1 = void , typename A2 = void , typename A3 = void , typename A4 = void , typename A5 = void , typename A6 = void , typename A7 = void , typename A8 = void , typename A9 = void, typename Dummy = void> struct make_construct; template <typename A0> struct make_construct <A0> : zr_boost_1_81::result_of< functional:: make_construct( A0 ) > {}; template <typename A0 , typename A1> struct make_construct <A0 , A1> : zr_boost_1_81::result_of< functional:: make_construct( A0 , A1 ) > {}; template <typename A0 , typename A1 , typename A2> struct make_construct <A0 , A1 , A2> : zr_boost_1_81::result_of< functional:: make_construct( A0 , A1 , A2 ) > {}; template <typename A0 , typename A1 , typename A2 , typename A3> struct make_construct <A0 , A1 , A2 , A3> : zr_boost_1_81::result_of< functional:: make_construct( A0 , A1 , A2 , A3 ) > {}; template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4> struct make_construct <A0 , A1 , A2 , A3 , A4> : zr_boost_1_81::result_of< functional:: make_construct( A0 , A1 , A2 , A3 , A4 ) > {}; template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5> struct make_construct <A0 , A1 , A2 , A3 , A4 , A5> : zr_boost_1_81::result_of< functional:: make_construct( A0 , A1 , A2 , A3 , A4 , A5 ) > {}; template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6> struct make_construct <A0 , A1 , A2 , A3 , A4 , A5 , A6> : zr_boost_1_81::result_of< functional:: make_construct( A0 , A1 , A2 , A3 , A4 , A5 , A6 ) > {}; template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7> struct make_construct <A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7> : zr_boost_1_81::result_of< functional:: make_construct( A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 ) > {}; template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8> struct make_construct <A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8> : zr_boost_1_81::result_of< functional:: make_construct( A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 ) > {}; } template <typename A0> inline typename result_of:: make_construct< A0 >::type make_construct(A0 const& a0) { return functional::make_construct()(a0); } template <typename A0 , typename A1> inline typename result_of:: make_construct< A0 , A1 >::type make_construct(A0 const& a0 , A1 const& a1) { return functional::make_construct()(a0 , a1); } template <typename A0 , typename A1 , typename A2> inline typename result_of:: make_construct< A0 , A1 , A2 >::type make_construct(A0 const& a0 , A1 const& a1 , A2 const& a2) { return functional::make_construct()(a0 , a1 , a2); } template <typename A0 , typename A1 , typename A2 , typename A3> inline typename result_of:: make_construct< A0 , A1 , A2 , A3 >::type make_construct(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3) { return functional::make_construct()(a0 , a1 , a2 , a3); } template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4> inline typename result_of:: make_construct< A0 , A1 , A2 , A3 , A4 >::type make_construct(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4) { return functional::make_construct()(a0 , a1 , a2 , a3 , a4); } template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5> inline typename result_of:: make_construct< A0 , A1 , A2 , A3 , A4 , A5 >::type make_construct(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5) { return functional::make_construct()(a0 , a1 , a2 , a3 , a4 , a5); } template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6> inline typename result_of:: make_construct< A0 , A1 , A2 , A3 , A4 , A5 , A6 >::type make_construct(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6) { return functional::make_construct()(a0 , a1 , a2 , a3 , a4 , a5 , a6); } template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7> inline typename result_of:: make_construct< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 >::type make_construct(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7) { return functional::make_construct()(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7); } template <typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8> inline typename result_of:: make_construct< A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 >::type make_construct(A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4 , A5 const& a5 , A6 const& a6 , A7 const& a7 , A8 const& a8) { return functional::make_construct()(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8); } } } namespace zr_boost_1_81 { namespace zr_boost_1_81phoenix { template <typename Dummy> struct meta_grammar::case_< :: zr_boost_1_81 :: zr_boost_1_81phoenix :: tag:: construct , Dummy > : enable_rule< :: zr_boost_1_81 :: zr_boost_1_81phoenix :: rule:: construct , Dummy > {}; } }
