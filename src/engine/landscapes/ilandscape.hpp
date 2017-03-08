/*********************************************************************************
*     File Name           :     src/engine/landscape/ilandscape.hpp
*     Created By          :     anon
*     Creation Date       :     [2016-02-19 14:09]
*     Last Modified       :     [2017-02-23 15:26]
*     Description         :      
**********************************************************************************/

#ifndef __ILANDSCAPE_HPP__
#define __ILANDSCAPE_HPP__
#include "iobject.hpp"
#include "ievent.hpp"
#include <memory>
#include <SDL2/SDL.h>

using namespace std;

class ILandscape: public IObject, public IEvent {

public:

	virtual SDL_Rect getTextureSize(void) = 0;
	
    virtual SDL_Texture *getTexture(void) = 0;

    virtual Uint8 getAction(void) = 0;

    virtual void addAction(Uint8 a) = 0;

    virtual void removeAction(Uint8 a) = 0;
    
   	virtual void setPosition(int x, int y) = 0;

    virtual void setPosition(shared_ptr<SDL_Rect> pos) = 0;

    virtual shared_ptr<SDL_Rect> getPosition(void) = 0;

    virtual void tickEvent(IObject &obj, SDL_Event *e) = 0;

    virtual bool isEventEnabled(void) = 0;

    virtual void render(SDL_Rect *clip = NULL) = 0;

    virtual void setClip(SDL_Rect c) = 0;
};

#endif
