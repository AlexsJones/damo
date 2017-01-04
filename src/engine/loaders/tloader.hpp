/*********************************************************************************
*     File Name           :     src/engine/loaders/iloader.hpp
*     Created By          :     jonesax
*     Creation Date       :     [2017-01-04 08:13]
*     Last Modified       :     [2017-01-04 08:39]
*     Description         :      
**********************************************************************************/

#ifndef __ILOADER_HPP__
#define __ILOADER_HPP__
#include <iostream>
#include <SDL2/SDL.h>
template<class T>
class TLoader {

  virtual T load(std::string path, SDL_Renderer *renderer) =0;
};

#endif
