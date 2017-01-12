/*********************************************************************************
 *     File Name           :     src/engine/events/ievent.hpp
 *     Created By          :     jonesax
 *     Creation Date       :     [2017-01-10 14:29]
 *     Last Modified       :     [2017-01-11 18:17]
 *     Description         :      
 **********************************************************************************/
#ifndef __IEVENT_HPP__
#define __IEVENT_HPP__
#include <SDL2/SDL.h>

class IEvent {

  public:
    virtual void tickEvent(SDL_Event *event) = 0;

    virtual bool isEventEnabled(void) = 0;
};

#endif

