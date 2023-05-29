/*
 *
 * Copyright (c) 1998-2002
 * John Maddock
 *
 * Use, modification and distribution are subject to the 
 * Boost Software License, Version 1.0. (See accompanying file 
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 *
 */

 /*
  *   LOCATION:    see http://www.boost.org for most recent version.
  *   FILE         regbase.cpp
  *   VERSION      see <boost/version.hpp>
  *   DESCRIPTION: Declares class regbase.
  */

#ifndef BOOST_REGEX_V5_REGBASE_HPP
#define BOOST_REGEX_V5_REGBASE_HPP

namespace zr_boost_1_81{
//
// class regbase
// handles error codes and flags
//
class regbase
{
public:
   enum flag_type_
   {
      //
      // Divide the flags up into logical groups:
      // bits 0-7 indicate main synatx type.
      // bits 8-15 indicate syntax subtype.
      // bits 16-31 indicate options that are common to all
      // regex syntaxes.
      // In all cases the default is 0.
      //
      // Main synatx group:
      //
      perl_syntax_group = 0,                      // default
      basic_syntax_group = 1,                     // POSIX basic
      literal = 2,                                // all characters are literals
      main_option_type = literal | basic_syntax_group | perl_syntax_group, // everything!
      //
      // options specific to perl group:
      //
      no_bk_refs = 1 << 8,                        // \d not allowed
      no_perl_ex = 1 << 9,                        // disable perl extensions
      no_mod_m = 1 << 10,                         // disable Perl m modifier
      mod_x = 1 << 11,                            // Perl x modifier
      mod_s = 1 << 12,                            // force s modifier on (overrides match_not_dot_newline)
      no_mod_s = 1 << 13,                         // force s modifier off (overrides match_not_dot_newline)

      //
      // options specific to basic group:
      //
      no_char_classes = 1 << 8,                   // [[:CLASS:]] not allowed
      no_intervals = 1 << 9,                      // {x,y} not allowed
      bk_plus_qm = 1 << 10,                       // uses \+ and \?
      bk_vbar = 1 << 11,                          // use \| for alternatives
      emacs_ex = 1 << 12,                         // enables emacs extensions

      //
      // options common to all groups:
      //
      no_escape_in_lists = 1 << 16,                     // '\' not special inside [...]
      newline_alt = 1 << 17,                            // \n is the same as |
      no_except = 1 << 18,                              // no exception on error
      failbit = 1 << 19,                                // error flag
      icase = 1 << 20,                                  // characters are matched regardless of case
      nocollate = 0,                                    // don't use locale specific collation (deprecated)
      collate = 1 << 21,                                // use locale specific collation
      nosubs = 1 << 22,                                 // don't mark sub-expressions
      save_subexpression_location = 1 << 23,            // save subexpression locations
      no_empty_expressions = 1 << 24,                   // no empty expressions allowed
      optimize = 0,                                     // not really supported
      


      basic = basic_syntax_group | collate | no_escape_in_lists,
      extended = no_bk_refs | collate | no_perl_ex | no_escape_in_lists,
      normal = 0,
      emacs = basic_syntax_group | collate | emacs_ex | bk_vbar,
      awk = no_bk_refs | collate | no_perl_ex,
      grep = basic | newline_alt,
      egrep = extended | newline_alt,
      sed = basic,
      perl = normal,
      ECMAScript = normal,
      JavaScript = normal,
      JScript = normal
   };
   typedef unsigned int flag_type;

   enum restart_info
   {
      restart_any = 0,
      restart_word = 1,
      restart_line = 2,
      restart_buf = 3,
      restart_continue = 4,
      restart_lit = 5,
      restart_fixed_lit = 6, 
      restart_count = 7
   };
};

//
// provide std lib proposal compatible constants:
//
namespace regex_constants{

   enum flag_type_
   {

      no_except = ::zr_boost_1_81::regbase::no_except,
      failbit = ::zr_boost_1_81::regbase::failbit,
      literal = ::zr_boost_1_81::regbase::literal,
      icase = ::zr_boost_1_81::regbase::icase,
      nocollate = ::zr_boost_1_81::regbase::nocollate,
      collate = ::zr_boost_1_81::regbase::collate,
      nosubs = ::zr_boost_1_81::regbase::nosubs,
      optimize = ::zr_boost_1_81::regbase::optimize,
      bk_plus_qm = ::zr_boost_1_81::regbase::bk_plus_qm,
      bk_vbar = ::zr_boost_1_81::regbase::bk_vbar,
      no_intervals = ::zr_boost_1_81::regbase::no_intervals,
      no_char_classes = ::zr_boost_1_81::regbase::no_char_classes,
      no_escape_in_lists = ::zr_boost_1_81::regbase::no_escape_in_lists,
      no_mod_m = ::zr_boost_1_81::regbase::no_mod_m,
      mod_x = ::zr_boost_1_81::regbase::mod_x,
      mod_s = ::zr_boost_1_81::regbase::mod_s,
      no_mod_s = ::zr_boost_1_81::regbase::no_mod_s,
      save_subexpression_location = ::zr_boost_1_81::regbase::save_subexpression_location,
      no_empty_expressions = ::zr_boost_1_81::regbase::no_empty_expressions,

      basic = ::zr_boost_1_81::regbase::basic,
      extended = ::zr_boost_1_81::regbase::extended,
      normal = ::zr_boost_1_81::regbase::normal,
      emacs = ::zr_boost_1_81::regbase::emacs,
      awk = ::zr_boost_1_81::regbase::awk,
      grep = ::zr_boost_1_81::regbase::grep,
      egrep = ::zr_boost_1_81::regbase::egrep,
      sed = basic,
      perl = normal,
      ECMAScript = normal,
      JavaScript = normal,
      JScript = normal
   };
   typedef ::zr_boost_1_81::regbase::flag_type syntax_option_type;

} // namespace regex_constants

} // namespace zr_boost_1_81

#endif

