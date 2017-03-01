/*********************************************************************************
 *     File Name           :     src/engine/actor/iactor.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-19 11:51]
 *     Last Modified       :     [2017-03-01 22:38]
 *     Description         :      
 **********************************************************************************/

#ifndef __IACTOR_HPP__
#define __IACTOR_HPP__
#include <memory>
#include <SDL2/SDL.h>
#include <jnxc_headers/jnx_guid.h>
#include "ievent.hpp"
using namespace std;

class IActor : public IEvent {

  public: 

    virtual void setTexture(SDL_Texture *tex) = 0;

    virtual SDL_Rect getTextureSize(void) = 0;

    virtual void setPosition(int x, int y) = 0;

    virtual void setPosition(shared_ptr<SDL_Rect> pos) = 0;

    virtual shared_ptr<SDL_Rect> getPosition(void) = 0;

    virtual SDL_Texture* getTexture(void) = 0;

    virtual string getUniqueIdentifier(void) = 0;
    
    virtual void tickEvent(SDL_Event *e) = 0;

    virtual void render(const SDL_Rect *clip) = 0;

    virtual bool isEventEnabled(void) = 0;

    virtual void setEvent(bool t) = 0;

    jnx_guid m_guid;
};

#endif
