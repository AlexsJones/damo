/*********************************************************************************
*     File Name           :     src/engine/landscape/ilandscape.hpp
*     Created By          :     anon
*     Creation Date       :     [2016-02-19 14:09]
*     Last Modified       :     [2017-02-23 15:26]
*     Description         :      
**********************************************************************************/

#ifndef __ILANDSCAPE_HPP__
#define __ILANDSCAPE_HPP__
#include "iactor.hpp"
#include <memory>
#include <SDL2/SDL.h>

using namespace std;

class ILandscape {

public:

    virtual SDL_Texture *getTexture(void) = 0;
    
    virtual shared_ptr<SDL_Rect> getPosition(void) = 0;

    virtual void tickEvent(SDL_Event *e) = 0;

    virtual bool isEventEnabled(void) = 0;
};

#endif
