//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2006-2012. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////
   #include <boost/interprocess/sync/interprocess_mutex.hpp>
   #include <boost/interprocess/sync/interprocess_condition.hpp>

   struct trace_queue
   {
      enum { LineSize = 100 };

      trace_queue()
         :  message_in(false)
      {}

      //Mutex to protect access to the queue
      zr_boost_1_81::interprocess::interprocess_mutex      mutex;

      //Condition to wait when the queue is empty
      zr_boost_1_81::interprocess::interprocess_condition  cond_empty;

      //Condition to wait when the queue is full
      zr_boost_1_81::interprocess::interprocess_condition  cond_full;

      //Items to fill
      char   items[LineSize];

      //Is there any message
      bool message_in;
   };
