/*********************************************************************************
 *     File Name           :     /home/anon/Code/sdl/src/engine/actor.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-16 18:00]
 *     Last Modified       :     [2016-02-16 22:42]
 *     Description         :      
 **********************************************************************************/

#include "actor.hpp"
#include "utilities.hpp"

Actor::Actor(SDL_Texture *texture, int x, int y):
  m_texture(texture){
    m_currentPosition = make_shared<SDL_Rect>();
    m_currentPosition->x = x;
    m_currentPosition->y = y;
  }
Actor::~Actor() {

  if(m_texture) {
    cleanup(m_texture);
  }
}
SDL_Texture *Actor::getTexture(void) {

  return m_texture;
}
shared_ptr<SDL_Rect> Actor::getPosition(void) {

  return m_currentPosition;
}
shared_ptr<SDL_Rect> Actor::getSize(void) {

  int w,h;
  SDL_QueryTexture(m_texture,NULL,NULL,&w,&h);

  shared_ptr<SDL_Rect> r = make_shared<SDL_Rect>();
  r->w = w;
  r->h = h;

  return r;
}
void Actor::setPosition(int x, int y) {
  m_currentPosition->x = x;
  m_currentPosition->y = y;
}
