#include "physics.hpp"

Physics::Physics(void) {

	vel.x = vel.y = 0;
    acc.x = acc.y = 0;
    timestep.set( 10 );
    accstep = 50;
    deaccstep = accstep / 2.0f;
}
void Physics::tickEvent(IObject &actor, SDL_Event *e) {

  SDL_Event event = *e;

  if (event.type == SDL_KEYDOWN) {
    switch (event.key.keysym.sym) {
      case SDLK_LEFT:   ACTION |= LEFT;     break;
      case SDLK_RIGHT:  ACTION |= RIGHT;    break;
      case SDLK_UP:     ACTION |= UP;     break;
      case SDLK_DOWN:   ACTION |= DOWN;     break;
      default: break;
    }
  }
  // KeyUp: Turn off Action 
  if (event.type == SDL_KEYUP) {
    switch (event.key.keysym.sym) {
      case SDLK_LEFT:   ACTION &= ~LEFT;    break;
      case SDLK_RIGHT:  ACTION &= ~RIGHT;   break;
      case SDLK_UP:     ACTION &= ~UP;      break;
      case SDLK_DOWN:   ACTION &= ~DOWN;    break;
      default: ACTION=0;
    }
  }

  while ( timestep() ) {
    float DT = timestep.get() / 1000.0f;
    if ( vel.x >= 0 ) {
      vel.x -= deaccstep;
      if ( vel.x < 0 ) { vel.x = 0; }
    } else {
      vel.x += deaccstep;
      if ( vel.x > 0 ) { vel.x = 0; }
    }
    if ( vel.y >= 0 ) {
      vel.y -= deaccstep;
      if ( vel.y < 0 ) { vel.y = 0; }
    } else {
      vel.y += deaccstep;
      if ( vel.y > 0 ) { vel.y = 0; }
    }
    if (hasFlag(ACTION, LEFT))  { 
      vel.x -= accstep; }
    if (hasFlag(ACTION, RIGHT)) { 
      vel.x += accstep; }
    if (hasFlag(ACTION, UP))  {
      vel.y -= accstep; }
    if (hasFlag(ACTION, DOWN))  { 
      vel.y += accstep; }

    if (vel.x > velocity)   vel.x = velocity;
    if (vel.x < -velocity)  vel.x = -velocity;
    if (vel.y > velocity)   vel.y = velocity;
    if (vel.y < -velocity)  vel.y = -velocity;

    auto position = actor.getPosition();
    position->x += vel.x * DT;
    position->y += vel.y * DT;

    actor.setPosition(position);
  }

  if (!ACTION) { timestep.resetTime(); }
}