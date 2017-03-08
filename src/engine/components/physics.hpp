#ifndef __PHYSICS_HPP__
#define __PHYSICS_HPP__
#include "icomponent.hpp"
#include "timer.hpp"
#include <SDL2/SDL.h>
#include "types.hpp"
#include "utilities.hpp"

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

};

#endif 