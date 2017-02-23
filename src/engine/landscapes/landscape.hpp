/*********************************************************************************
*     File Name           :     src/engine/landscape.hpp
*     Created By          :     anon
*     Creation Date       :     [2016-02-17 18:00]
*     Last Modified       :     [2017-02-23 15:25]
*     Description         :      
**********************************************************************************/
#ifndef __LANDSCAPE_HPP__
#define __LANDSCAPE_HPP__
#include <memory>
#include <SDL2/SDL.h>
#include "ilandscape.hpp"

using namespace std;

class Landscape : public ILandscape {

  public:
    Landscape(int width, int height, int x, int y);

    shared_ptr<SDL_Rect> getPosition(void);

    shared_ptr<SDL_Rect> getSize(void);

    void setTexture(SDL_Texture *tex);

    shared_ptr<SDL_Rect> getTextureSize(void);

    void setPosition(int x, int y);

    void setPosition(shared_ptr<SDL_Rect> pos);

    SDL_Texture* getTexture(void);

    void tickEvent(SDL_Event *e);

    bool isEventEnabled(void);


  private:

    int m_width;
    
    int m_height;

    shared_ptr<SDL_Rect> m_currentPosition;
};

#endif
