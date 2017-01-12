/*********************************************************************************
*     File Name           :     src/engine/engine_constraints.hpp
*     Created By          :     jonesax
*     Creation Date       :     [2017-01-11 09:04]
*     Last Modified       :     [2017-01-11 09:25]
*     Description         :     
**********************************************************************************/
#ifndef __ENGINE_CONSTRAINTS_HPP__
#define __ENGINE_CONSTRAINTS_HPP__

#include <type_traits>

namespace detail{
  template<class> struct sfinae_true : std::true_type{};
    
  template<class T, class A0>
  static auto has_tick_event( int)
    -> sfinae_true<decltype(std::declval<T>().stream(std::declval<A0>()))>;
  template<class, class A0>
  static auto has_tick_event(long) -> std::false_type;
} // detail::

template<class T, class Arg>
struct has_tick_event : decltype(detail::has_tick_event<T, Arg>(0)){};


#endif
