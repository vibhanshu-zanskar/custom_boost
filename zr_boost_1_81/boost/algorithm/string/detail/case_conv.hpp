//  Boost string_algo library string_funct.hpp header file  ---------------------------//

//  Copyright Pavol Droba 2002-2003.
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/ for updates, documentation, and revision history.

#ifndef BOOST_STRING_CASE_CONV_DETAIL_HPP
#define BOOST_STRING_CASE_CONV_DETAIL_HPP

#include <boost/algorithm/string/config.hpp>
#include <locale>
#include <functional>

#include <boost/iterator/transform_iterator.hpp>
#include <boost/range/begin.hpp>
#include <boost/range/end.hpp>
#include <boost/type_traits/make_unsigned.hpp>

namespace zr_boost_1_81 {
    namespace algorithm {
        namespace detail {

//  case conversion functors -----------------------------------------------//

#if BOOST_WORKAROUND(BOOST_MSVC, >= 1400)
#pragma warning(push)
#pragma warning(disable:4512) //assignment operator could not be generated
#endif

            // a tolower functor
            template<typename CharT>
            struct to_lowerF
            {
                typedef CharT argument_type;
                typedef CharT result_type;
                // Constructor
                to_lowerF( const std::locale& Loc ) : m_Loc( &Loc ) {}

                // Operation
                CharT operator ()( CharT Ch ) const
                {
                    #if defined(BOOST_BORLANDC) && (BOOST_BORLANDC >= 0x560) && (BOOST_BORLANDC <= 0x564) && !defined(_USE_OLD_RW_STL)
                        return std::tolower( static_cast<typename zr_boost_1_81::make_unsigned <CharT>::type> ( Ch ));
                    #else
                        return std::tolower<CharT>( Ch, *m_Loc );
                    #endif
                }
            private:
                const std::locale* m_Loc;
            };

            // a toupper functor
            template<typename CharT>
            struct to_upperF
            {
                typedef CharT argument_type;
                typedef CharT result_type;
                // Constructor
                to_upperF( const std::locale& Loc ) : m_Loc( &Loc ) {}

                // Operation
                CharT operator ()( CharT Ch ) const
                {
                    #if defined(BOOST_BORLANDC) && (BOOST_BORLANDC >= 0x560) && (BOOST_BORLANDC <= 0x564) && !defined(_USE_OLD_RW_STL)
                        return std::toupper( static_cast<typename zr_boost_1_81::make_unsigned <CharT>::type> ( Ch ));
                    #else
                        return std::toupper<CharT>( Ch, *m_Loc );
                    #endif
                }
            private:
                const std::locale* m_Loc;
            };

#if BOOST_WORKAROUND(BOOST_MSVC, >= 1400)
#pragma warning(pop)
#endif

// algorithm implementation -------------------------------------------------------------------------

            // Transform a range
            template<typename OutputIteratorT, typename RangeT, typename FunctorT>
            OutputIteratorT transform_range_copy(
                OutputIteratorT Output,
                const RangeT& Input,
                FunctorT Functor)
            {
                return std::transform( 
                    ::zr_boost_1_81::begin(Input), 
                    ::zr_boost_1_81::end(Input), 
                    Output,
                    Functor);
            }

            // Transform a range (in-place)
            template<typename RangeT, typename FunctorT>
            void transform_range(
                const RangeT& Input,
                FunctorT Functor)
            {
                std::transform( 
                    ::zr_boost_1_81::begin(Input), 
                    ::zr_boost_1_81::end(Input), 
                    ::zr_boost_1_81::begin(Input),
                    Functor);
            }

            template<typename SequenceT, typename RangeT, typename FunctorT>
            inline SequenceT transform_range_copy( 
                const RangeT& Input, 
                FunctorT Functor)
            {
                return SequenceT(
                    ::zr_boost_1_81::make_transform_iterator(
                        ::zr_boost_1_81::begin(Input),
                        Functor),
                    ::zr_boost_1_81::make_transform_iterator(
                        ::zr_boost_1_81::end(Input), 
                        Functor));
            }

        } // namespace detail
    } // namespace algorithm
} // namespace zr_boost_1_81


#endif  // BOOST_STRING_CASE_CONV_DETAIL_HPP
