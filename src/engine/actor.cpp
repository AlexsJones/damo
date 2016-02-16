/*********************************************************************************
 *     File Name           :     /home/anon/Code/sdl/src/engine/actor.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-16 18:00]
 *     Last Modified       :     [2016-02-16 19:19]
 *     Description         :      
 **********************************************************************************/

#include "actor.hpp"


Actor::Actor(SDL_Texture *texture, int x, int y):
  m_texture(texture){
    m_currentPosition.w = x;
    m_currentPosition.h = y;
  }
SDL_Texture *Actor::getTexture(void) {

  return m_texture;
}

SDL_Rect Actor::getPosition(void) {

  return m_currentPosition;
}
