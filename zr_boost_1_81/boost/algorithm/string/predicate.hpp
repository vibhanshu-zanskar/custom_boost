//  Boost string_algo library predicate.hpp header file  ---------------------------//

//  Copyright Pavol Droba 2002-2003.
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/ for updates, documentation, and revision history.

#ifndef BOOST_STRING_PREDICATE_HPP
#define BOOST_STRING_PREDICATE_HPP

#include <iterator>
#include <boost/algorithm/string/config.hpp>
#include <boost/range/begin.hpp>
#include <boost/range/end.hpp>
#include <boost/range/iterator.hpp>
#include <boost/range/const_iterator.hpp>
#include <boost/range/as_literal.hpp>
#include <boost/range/iterator_range_core.hpp>

#include <boost/algorithm/string/compare.hpp>
#include <boost/algorithm/string/find.hpp>
#include <boost/algorithm/string/detail/predicate.hpp>

/*! \file boost/algorithm/string/predicate.hpp
    Defines string-related predicates. 
    The predicates determine whether a substring is contained in the input string 
    under various conditions: a string starts with the substring, ends with the 
    substring, simply contains the substring or if both strings are equal.
    Additionaly the algorithm \c all() checks all elements of a container to satisfy a 
    condition.

    All predicates provide the strong exception guarantee.
*/

namespace zr_boost_1_81 {
    namespace algorithm {

//  starts_with predicate  -----------------------------------------------//

        //! 'Starts with' predicate
        /*!
            This predicate holds when the test string is a prefix of the Input.
            In other words, if the input starts with the test.
            When the optional predicate is specified, it is used for character-wise
            comparison.

            \param Input An input sequence
            \param Test A test sequence
            \param Comp An element comparison predicate
            \return The result of the test

              \note This function provides the strong exception-safety guarantee
        */
        template<typename Range1T, typename Range2T, typename PredicateT>
            inline bool starts_with( 
            const Range1T& Input, 
            const Range2T& Test,
            PredicateT Comp)
        {
            iterator_range<BOOST_STRING_TYPENAME range_const_iterator<Range1T>::type> lit_input(::zr_boost_1_81::as_literal(Input));
            iterator_range<BOOST_STRING_TYPENAME range_const_iterator<Range2T>::type> lit_test(::zr_boost_1_81::as_literal(Test));

            typedef BOOST_STRING_TYPENAME 
                range_const_iterator<Range1T>::type Iterator1T;
            typedef BOOST_STRING_TYPENAME 
                range_const_iterator<Range2T>::type Iterator2T;

            Iterator1T InputEnd=::zr_boost_1_81::end(lit_input);
            Iterator2T TestEnd=::zr_boost_1_81::end(lit_test);

            Iterator1T it=::zr_boost_1_81::begin(lit_input);
            Iterator2T pit=::zr_boost_1_81::begin(lit_test);
            for(;
                it!=InputEnd && pit!=TestEnd;
                ++it,++pit)
            {
                if( !(Comp(*it,*pit)) )
                    return false;
            }

            return pit==TestEnd;
        }

        //! 'Starts with' predicate
        /*!
            \overload
        */
        template<typename Range1T, typename Range2T>
        inline bool starts_with( 
            const Range1T& Input, 
            const Range2T& Test)
        {
            return ::zr_boost_1_81::algorithm::starts_with(Input, Test, is_equal());
        }

        //! 'Starts with' predicate ( case insensitive )
        /*!
            This predicate holds when the test string is a prefix of the Input.
            In other words, if the input starts with the test.
            Elements are compared case insensitively.

            \param Input An input sequence
            \param Test A test sequence
            \param Loc A locale used for case insensitive comparison
            \return The result of the test

            \note This function provides the strong exception-safety guarantee
        */
        template<typename Range1T, typename Range2T>
        inline bool istarts_with( 
            const Range1T& Input, 
            const Range2T& Test,
            const std::locale& Loc=std::locale())
        {
            return ::zr_boost_1_81::algorithm::starts_with(Input, Test, is_iequal(Loc));
        }


//  ends_with predicate  -----------------------------------------------//

        //! 'Ends with' predicate
        /*!
            This predicate holds when the test string is a suffix of the Input.
            In other words, if the input ends with the test.
            When the optional predicate is specified, it is used for character-wise
            comparison.


            \param Input An input sequence
            \param Test A test sequence
            \param Comp An element comparison predicate
            \return The result of the test

              \note This function provides the strong exception-safety guarantee
        */
        template<typename Range1T, typename Range2T, typename PredicateT>
        inline bool ends_with( 
            const Range1T& Input, 
            const Range2T& Test,
            PredicateT Comp)
        {
            iterator_range<BOOST_STRING_TYPENAME range_const_iterator<Range1T>::type> lit_input(::zr_boost_1_81::as_literal(Input));
            iterator_range<BOOST_STRING_TYPENAME range_const_iterator<Range2T>::type> lit_test(::zr_boost_1_81::as_literal(Test));

            typedef BOOST_STRING_TYPENAME
                range_const_iterator<Range1T>::type Iterator1T;
            typedef BOOST_STRING_TYPENAME
                std::iterator_traits<Iterator1T>::iterator_category category;

            return detail::
                ends_with_iter_select( 
                    ::zr_boost_1_81::begin(lit_input), 
                    ::zr_boost_1_81::end(lit_input), 
                    ::zr_boost_1_81::begin(lit_test), 
                    ::zr_boost_1_81::end(lit_test), 
                    Comp,
                    category());
        }


        //! 'Ends with' predicate
        /*!
            \overload
        */
        template<typename Range1T, typename Range2T>
        inline bool ends_with( 
            const Range1T& Input, 
            const Range2T& Test)
        {
            return ::zr_boost_1_81::algorithm::ends_with(Input, Test, is_equal());
        }

        //! 'Ends with' predicate ( case insensitive )
        /*!
            This predicate holds when the test container is a suffix of the Input.
            In other words, if the input ends with the test.
            Elements are compared case insensitively.

            \param Input An input sequence
            \param Test A test sequence
            \param Loc A locale used for case insensitive comparison
            \return The result of the test

            \note This function provides the strong exception-safety guarantee
        */
        template<typename Range1T, typename Range2T>
        inline bool iends_with( 
            const Range1T& Input, 
            const Range2T& Test,
            const std::locale& Loc=std::locale())
        {
            return ::zr_boost_1_81::algorithm::ends_with(Input, Test, is_iequal(Loc));
        }

//  contains predicate  -----------------------------------------------//

        //! 'Contains' predicate
        /*!
            This predicate holds when the test container is contained in the Input.
            When the optional predicate is specified, it is used for character-wise
            comparison.

            \param Input An input sequence
            \param Test A test sequence
            \param Comp An element comparison predicate
            \return The result of the test

               \note This function provides the strong exception-safety guarantee
        */
        template<typename Range1T, typename Range2T, typename PredicateT>
        inline bool contains( 
            const Range1T& Input, 
            const Range2T& Test,
            PredicateT Comp)
        {
            iterator_range<BOOST_STRING_TYPENAME range_const_iterator<Range1T>::type> lit_input(::zr_boost_1_81::as_literal(Input));
            iterator_range<BOOST_STRING_TYPENAME range_const_iterator<Range2T>::type> lit_test(::zr_boost_1_81::as_literal(Test));

            if (::zr_boost_1_81::empty(lit_test))
            {
                // Empty range is contained always
                return true;
            }
            
            // Use the temporary variable to make VACPP happy
            bool bResult=(::zr_boost_1_81::algorithm::first_finder(lit_test,Comp)(::zr_boost_1_81::begin(lit_input), ::zr_boost_1_81::end(lit_input)));
            return bResult;
        }

        //! 'Contains' predicate
        /*!
            \overload
        */
        template<typename Range1T, typename Range2T>
        inline bool contains( 
            const Range1T& Input, 
            const Range2T& Test)
        {
            return ::zr_boost_1_81::algorithm::contains(Input, Test, is_equal());
        }

        //! 'Contains' predicate ( case insensitive )
        /*!
            This predicate holds when the test container is contained in the Input.
            Elements are compared case insensitively.

            \param Input An input sequence
            \param Test A test sequence
            \param Loc A locale used for case insensitive comparison
            \return The result of the test

            \note This function provides the strong exception-safety guarantee
        */
        template<typename Range1T, typename Range2T>
        inline bool icontains( 
            const Range1T& Input, 
            const Range2T& Test, 
            const std::locale& Loc=std::locale())
        {
            return ::zr_boost_1_81::algorithm::contains(Input, Test, is_iequal(Loc));
        }

//  equals predicate  -----------------------------------------------//

        //! 'Equals' predicate
        /*!
            This predicate holds when the test container is equal to the
            input container i.e. all elements in both containers are same.
            When the optional predicate is specified, it is used for character-wise
            comparison.

            \param Input An input sequence
            \param Test A test sequence
            \param Comp An element comparison predicate
            \return The result of the test

            \note This is a two-way version of \c std::equal algorithm

            \note This function provides the strong exception-safety guarantee
        */
        template<typename Range1T, typename Range2T, typename PredicateT>
        inline bool equals( 
            const Range1T& Input, 
            const Range2T& Test,
            PredicateT Comp)
        {
            iterator_range<BOOST_STRING_TYPENAME range_const_iterator<Range1T>::type> lit_input(::zr_boost_1_81::as_literal(Input));
            iterator_range<BOOST_STRING_TYPENAME range_const_iterator<Range2T>::type> lit_test(::zr_boost_1_81::as_literal(Test));

            typedef BOOST_STRING_TYPENAME 
                range_const_iterator<Range1T>::type Iterator1T;
            typedef BOOST_STRING_TYPENAME 
                range_const_iterator<Range2T>::type Iterator2T;
                
            Iterator1T InputEnd=::zr_boost_1_81::end(lit_input);
            Iterator2T TestEnd=::zr_boost_1_81::end(lit_test);

            Iterator1T it=::zr_boost_1_81::begin(lit_input);
            Iterator2T pit=::zr_boost_1_81::begin(lit_test);
            for(;
                it!=InputEnd && pit!=TestEnd;
                ++it,++pit)
            {
                if( !(Comp(*it,*pit)) )
                    return false;
            }

            return  (pit==TestEnd) && (it==InputEnd);
        }

        //! 'Equals' predicate
        /*!
            \overload
        */
        template<typename Range1T, typename Range2T>
        inline bool equals( 
            const Range1T& Input, 
            const Range2T& Test)
        {
            return ::zr_boost_1_81::algorithm::equals(Input, Test, is_equal());
        }

        //! 'Equals' predicate ( case insensitive )
        /*!
            This predicate holds when the test container is equal to the
            input container i.e. all elements in both containers are same.
            Elements are compared case insensitively.

            \param Input An input sequence
            \param Test A test sequence
            \param Loc A locale used for case insensitive comparison
            \return The result of the test

            \note This is a two-way version of \c std::equal algorithm

            \note This function provides the strong exception-safety guarantee
        */
        template<typename Range1T, typename Range2T>
        inline bool iequals( 
            const Range1T& Input, 
            const Range2T& Test,
            const std::locale& Loc=std::locale())
        {
            return ::zr_boost_1_81::algorithm::equals(Input, Test, is_iequal(Loc));
        }

// lexicographical_compare predicate -----------------------------//

        //! Lexicographical compare predicate
        /*!
             This predicate is an overload of std::lexicographical_compare
             for range arguments

             It check whether the first argument is lexicographically less
             then the second one.

             If the optional predicate is specified, it is used for character-wise
             comparison

             \param Arg1 First argument 
             \param Arg2 Second argument
             \param Pred Comparison predicate
             \return The result of the test

             \note This function provides the strong exception-safety guarantee
         */
        template<typename Range1T, typename Range2T, typename PredicateT>
        inline bool lexicographical_compare(
            const Range1T& Arg1,
            const Range2T& Arg2,
            PredicateT Pred)
        {
            iterator_range<BOOST_STRING_TYPENAME range_const_iterator<Range1T>::type> lit_arg1(::zr_boost_1_81::as_literal(Arg1));
            iterator_range<BOOST_STRING_TYPENAME range_const_iterator<Range2T>::type> lit_arg2(::zr_boost_1_81::as_literal(Arg2));

            return std::lexicographical_compare(
                ::zr_boost_1_81::begin(lit_arg1),
                ::zr_boost_1_81::end(lit_arg1),
                ::zr_boost_1_81::begin(lit_arg2),
                ::zr_boost_1_81::end(lit_arg2),
                Pred);
        }

        //! Lexicographical compare predicate
        /*!
            \overload
         */
        template<typename Range1T, typename Range2T>
            inline bool lexicographical_compare(
            const Range1T& Arg1,
            const Range2T& Arg2)
        {
            return ::zr_boost_1_81::algorithm::lexicographical_compare(Arg1, Arg2, is_less());
        }

        //! Lexicographical compare predicate (case-insensitive)
        /*!
            This predicate is an overload of std::lexicographical_compare
            for range arguments.
            It check whether the first argument is lexicographically less
            then the second one.
            Elements are compared case insensitively


             \param Arg1 First argument 
             \param Arg2 Second argument
             \param Loc A locale used for case insensitive comparison
             \return The result of the test

             \note This function provides the strong exception-safety guarantee
         */
        template<typename Range1T, typename Range2T>
        inline bool ilexicographical_compare(
            const Range1T& Arg1,
            const Range2T& Arg2,
            const std::locale& Loc=std::locale())
        {
            return ::zr_boost_1_81::algorithm::lexicographical_compare(Arg1, Arg2, is_iless(Loc));
        }
        

//  all predicate  -----------------------------------------------//

        //! 'All' predicate
        /*!
            This predicate holds it all its elements satisfy a given 
            condition, represented by the predicate.
            
            \param Input An input sequence
            \param Pred A predicate
            \return The result of the test

            \note This function provides the strong exception-safety guarantee
        */
        template<typename RangeT, typename PredicateT>
        inline bool all( 
            const RangeT& Input, 
            PredicateT Pred)
        {
            iterator_range<BOOST_STRING_TYPENAME range_const_iterator<RangeT>::type> lit_input(::zr_boost_1_81::as_literal(Input));

            typedef BOOST_STRING_TYPENAME 
                range_const_iterator<RangeT>::type Iterator1T;

            Iterator1T InputEnd=::zr_boost_1_81::end(lit_input);
            for( Iterator1T It=::zr_boost_1_81::begin(lit_input); It!=InputEnd; ++It)
            {
                if (!Pred(*It))
                    return false;
            }
            
            return true;
        }

    } // namespace algorithm

    // pull names to the boost namespace
    using algorithm::starts_with;
    using algorithm::istarts_with;
    using algorithm::ends_with;
    using algorithm::iends_with;
    using algorithm::contains;
    using algorithm::icontains;
    using algorithm::equals;
    using algorithm::iequals;
    using algorithm::all;
    using algorithm::lexicographical_compare;
    using algorithm::ilexicographical_compare;

} // namespace zr_boost_1_81


#endif  // BOOST_STRING_PREDICATE_HPP
