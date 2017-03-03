/*********************************************************************************
 *     File Name           :     /home/anon/Code/sdl/src/engine/actor.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-16 18:00]
 *     Last Modified       :     [2017-03-03 16:04]
 *     Description         :      
 **********************************************************************************/

#include "actor.hpp"
#include "utilities.hpp"

Actor::Actor(int x, int y, SDL_Renderer *renderer, SDL_Texture *texture):
  ref_renderer(renderer), m_currentPosition(make_shared<SDL_Rect>()) {

    jnx_guid_create(&m_guid);

    setPosition(x,y);

    setTexture(texture);

    setupPhysics();

    cout << "Created Actor with guid:" << getUniqueIdentifier()  << endl;
  }
Actor::Actor(int x,int y, SDL_Renderer *renderer, string path):
  ref_renderer(renderer)
  , m_currentPosition(make_shared<SDL_Rect>()) {

    jnx_guid_create(&m_guid);

    setPosition(x,y);

    setupPhysics();

    setTexture(load(path,ref_renderer));

    cout << "Created Actor with guid:" << getUniqueIdentifier()  << endl;
  }
Actor::Actor(int x, int y, SDL_Renderer *renderer):
  ref_renderer(renderer)
  , m_currentPosition(make_shared<SDL_Rect>()) {

    jnx_guid_create(&m_guid);

    setPosition(x,y);

    setupPhysics();

    cout << "Created Actor with guid:" << getUniqueIdentifier()  << endl;
  }
Actor::~Actor(void) {

  if(m_texture) {
    cleanup(m_texture);
  }
}
void Actor::setTexture(SDL_Texture *tex) {

  m_texture = tex;

  SDL_Rect r = { 0,0,0,0};

  if(m_texture) {
    int w,h;
    SDL_QueryTexture(m_texture,NULL,NULL,&w,&h);
    r.w = w;
    r.h = h;
  }
  m_texture_size = r;
}
SDL_Rect Actor::getTextureSize(void) {

  return m_texture_size;
}
SDL_Texture *Actor::getTexture(void) {

  return m_texture;
}
shared_ptr<SDL_Rect> Actor::getPosition(void) {

  return m_currentPosition;
}
void Actor::setPosition(int x, int y) {
  m_currentPosition->x = x;
  m_currentPosition->y = y;
}
void Actor::setPosition(shared_ptr<SDL_Rect> pos) {
  m_currentPosition = pos;
}
void Actor::render(const SDL_Rect *clip) {

  auto box = getBox();

  box.x -= clip->x;
  box.y -= clip->y;

  auto texture = getTexture();

  SDL_RenderCopy(ref_renderer,texture,NULL,&box);
}
void Actor::tickEvent(SDL_Event *e) {

  int xval = 0;
  int yval = 0;

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
      default: break;
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

    m_currentPosition->x += vel.x * DT;
    m_currentPosition->y += vel.y * DT;
  }

  if (!ACTION) { timestep.resetTime(); }
}

SDL_Rect Actor::getBox(void) {

  auto size = getTextureSize();
  SDL_Rect box = { m_currentPosition->x, m_currentPosition->y, 
    size.w, size.h};

  return box;
}
