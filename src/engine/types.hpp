/*********************************************************************************
 *     File Name           :     src/engine/types.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-16 17:34]
 *     Last Modified       :     [2016-02-16 17:56]
 *     Description         :      
 **********************************************************************************/

#ifndef __TYPES_HPP__
#define __TYPES_HPP__

template<typename T>

class Point {
  public:
    Point(T inputx, T inputy) {
      x = inputx;
      y = inputy;
    }
    T x;
    T y;
};


#endif
