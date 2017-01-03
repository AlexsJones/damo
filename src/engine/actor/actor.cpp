/*********************************************************************************
 *     File Name           :     /home/anon/Code/sdl/src/engine/actor.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-16 18:00]
 *     Last Modified       :     [2017-01-03 22:15]
 *     Description         :      
 **********************************************************************************/

#include "actor.hpp"
#include "utilities.hpp"

Actor::Actor(int x, int y) { 
  jnx_guid_create(&m_guid);

  m_currentPosition->x = x;

  m_currentPosition->y = y;

  cout << "Created Actor with guid:" << getUniqueIdentifier()  << endl;
}
Actor::~Actor(void) {

  if(m_texture) {
    cleanup(m_texture);
  }
}
void Actor::setTexture(SDL_Texture *tex) {

  m_texture = tex;

  m_currentPosition = make_shared<SDL_Rect>();

}
shared_ptr<SDL_Rect> Actor::getTextureSize(void) {

  shared_ptr<SDL_Rect> r = make_shared<SDL_Rect>();
  r->w = 0;
  r->h = 0;

  if(m_texture) {
    int w,h;
    SDL_QueryTexture(m_texture,NULL,NULL,&w,&h);
    r->w = w;
    r->h = h;
  }
  return r;
}
SDL_Texture *Actor::getTexture(void) {
  if(!m_texture) return NULL;
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
string Actor::getUniqueIdentifier(void) {
  jnx_char *str;
  jnx_guid_to_string(&m_guid,&str);
  string output(str);
  free(str);
  return output;
}
