/*********************************************************************************
*     File Name           :     src/engine/landscape.hpp
*     Created By          :     anon
*     Creation Date       :     [2016-02-17 18:00]
*     Last Modified       :     [2016-02-17 18:11]
*     Description         :      
**********************************************************************************/
#ifndef __LANDSCAPE_HPP__
#define __LANDSCAPE_HPP__
#include <memory>
#include <SDL2/SDL.h>

using namespace std;

class Landscape {

  public:
    Landscape(int width, int height, int x, int y);

    shared_ptr<SDL_Rect> getPosition(void);

    shared_ptr<SDL_Rect> getSize(void);

  private:

    int m_width;
    
    int m_height;

    shared_ptr<SDL_Rect> m_currentPosition;
};

#endif
