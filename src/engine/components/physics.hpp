#ifndef __PHYSICS_HPP__
#define __PHYSICS_HPP__
#include "iobject.hpp"
#include "icomponent.hpp"
#include "timer.hpp"
#include <SDL2/SDL.h>
#include "types.hpp"
#include "utilities.hpp"

enum Movement {
    NONE = 0
    ,LEFT = 1 << 1
    ,RIGHT = 1 << 2
    ,UP = 1 << 3
    ,DOWN = 1 << 4
};

class Physics : public IComponent {

public:
	Physics(void);

	void tickEvent(IObject &actor, SDL_Event *event);


private:
	float velocity = 1000.0f;
   
    fPoint vel;
   
    SDL_Point acc;
   
    float accstep;
   
    float deaccstep;
  
    Interval<Uint32> timestep;

    Uint8 ACTION = 0;

};

#endif 