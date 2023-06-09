#ifndef BOOST_THREAD_QUEUE_BASE_HPP
#define BOOST_THREAD_QUEUE_BASE_HPP

//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Vicente J. Botet Escriba 2014. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/thread for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#include <boost/thread/detail/config.hpp>
#include <boost/thread/detail/move.hpp>
#include <boost/thread/concurrent_queues/queue_op_status.hpp>
#include <boost/type_traits/conditional.hpp>
#include <boost/type_traits/is_copy_constructible.hpp>


#include <boost/config/abi_prefix.hpp>

namespace zr_boost_1_81
{
namespace concurrent
{
namespace detail
{

  template <typename ValueType, class SizeType>
  class queue_base_copyable_only
  {
  public:
    typedef ValueType value_type;
    typedef SizeType size_type;

    // Constructors/Assignment/Destructors
    virtual ~queue_base_copyable_only() {};

    // Observers
    virtual bool empty() const = 0;
    virtual bool full() const = 0;
    virtual size_type size() const = 0;
    virtual bool closed() const = 0;

    // Modifiers
    virtual void close() = 0;

    virtual void push(const value_type& x) = 0;

    virtual void pull(value_type&) = 0;
    virtual value_type pull() = 0;

    virtual queue_op_status try_push(const value_type& x) = 0;
    virtual queue_op_status try_pull(value_type&) = 0;

    virtual queue_op_status nonblocking_push(const value_type& x) = 0;
    virtual queue_op_status nonblocking_pull(value_type&) = 0;

    virtual queue_op_status wait_push(const value_type& x) = 0;
    virtual queue_op_status wait_pull(ValueType& elem) = 0;

  };

  template <typename ValueType, class SizeType>
  class queue_base_movable_only
  {
  public:
    typedef ValueType value_type;
    typedef SizeType size_type;
    // Constructors/Assignment/Destructors
    virtual ~queue_base_movable_only() {};

    // Observers
    virtual bool empty() const = 0;
    virtual bool full() const = 0;
    virtual size_type size() const = 0;
    virtual bool closed() const = 0;

    // Modifiers
    virtual void close() = 0;

    virtual void pull(value_type&) = 0;
    // enable_if is_nothrow_movable<value_type>
    virtual value_type pull() = 0;

    virtual queue_op_status try_pull(value_type&) = 0;

    virtual queue_op_status nonblocking_pull(value_type&) = 0;

    virtual queue_op_status wait_pull(value_type& elem) = 0;

    virtual void push(BOOST_THREAD_RV_REF(value_type) x) = 0;
    virtual queue_op_status try_push(BOOST_THREAD_RV_REF(value_type) x) = 0;
    virtual queue_op_status nonblocking_push(BOOST_THREAD_RV_REF(value_type) x) = 0;
    virtual queue_op_status wait_push(BOOST_THREAD_RV_REF(value_type) x) = 0;
  };


  template <typename ValueType, class SizeType>
  class queue_base_copyable_and_movable
  {
  public:
    typedef ValueType value_type;
    typedef SizeType size_type;
    // Constructors/Assignment/Destructors
    virtual ~queue_base_copyable_and_movable() {};


    // Observers
    virtual bool empty() const = 0;
    virtual bool full() const = 0;
    virtual size_type size() const = 0;
    virtual bool closed() const = 0;

    // Modifiers
    virtual void close() = 0;

    virtual void push(const value_type& x) = 0;

    virtual void pull(value_type&) = 0;
    // enable_if is_nothrow_copy_movable<value_type>
    virtual value_type pull() = 0;

    virtual queue_op_status try_push(const value_type& x) = 0;
    virtual queue_op_status try_pull(value_type&) = 0;

    virtual queue_op_status nonblocking_push(const value_type& x) = 0;
    virtual queue_op_status nonblocking_pull(value_type&) = 0;

    virtual queue_op_status wait_push(const value_type& x) = 0;
    virtual queue_op_status wait_pull(value_type& elem) = 0;

    virtual void push(BOOST_THREAD_RV_REF(value_type) x) = 0;
    virtual queue_op_status try_push(BOOST_THREAD_RV_REF(value_type) x) = 0;
    virtual queue_op_status nonblocking_push(BOOST_THREAD_RV_REF(value_type) x) = 0;
    virtual queue_op_status wait_push(BOOST_THREAD_RV_REF(value_type) x) = 0;
  };

  template <class T, class ST,
#if ! defined  BOOST_NO_CXX11_RVALUE_REFERENCES
#if defined __GNUC__ && ! defined __clang__
#if __GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 7) || !defined(__GXX_EXPERIMENTAL_CXX0X__)
          bool Copyable = is_copy_constructible<T>::value,
          bool Movable = true
#else
          bool Copyable = std::is_copy_constructible<T>::value && std::is_copy_assignable<T>::value,
          bool Movable = std::is_move_constructible<T>::value && std::is_move_assignable<T>::value
#endif // __GNUC__
#elif defined _MSC_VER
#if _MSC_VER < 1700
          bool Copyable = is_copy_constructible<T>::value,
          bool Movable = true
#else
          bool Copyable = std::is_copy_constructible<T>::value && std::is_copy_assignable<T>::value,
          bool Movable = std::is_move_constructible<T>::value && std::is_move_assignable<T>::value
#endif // _MSC_VER
#else
          bool Copyable = std::is_copy_constructible<T>::value && std::is_copy_assignable<T>::value,
          bool Movable = std::is_move_constructible<T>::value && std::is_move_assignable<T>::value
#endif
#else
          bool Copyable = is_copy_constructible<T>::value,
          bool Movable = has_move_emulation_enabled<T>::value
#endif
      >
  struct queue_base;

  template <class T, class ST>
  struct queue_base<T, ST, true, true> {
    typedef queue_base_copyable_and_movable<T, ST> type;
  };
  template <class T, class ST>
  struct queue_base<T, ST, true, false> {
    typedef queue_base_copyable_only<T, ST> type;
  };
  template <class T, class ST>
  struct queue_base<T, ST, false, true> {
    typedef queue_base_movable_only<T, ST> type;
  };

}

  template <typename ValueType, class SizeType=std::size_t>
  class queue_base :
    public detail::queue_base<ValueType, SizeType>::type
  {
  public:
      typedef ValueType value_type;
      typedef SizeType size_type;
    // Constructors/Assignment/Destructors
    virtual ~queue_base() {};
  };

}
using concurrent::queue_base;

}

#include <boost/config/abi_suffix.hpp>

#endif
