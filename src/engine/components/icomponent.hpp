#ifndef __ICOMPONENT_HPP__
#define __ICOMPONENT_HPP__
#include "iobject.hpp"
#include "ievent.hpp"
#include <SDL2/SDL.h>

class IComponent : public IEvent {
	public:

	virtual void tickEvent(IObject &actor, SDL_Event *event) = 0;

	virtual bool isEventEnabled(void)  {

		return true;
	}
};

#endif