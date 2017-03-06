/*********************************************************************************
 *     File Name           :     /home/anon/Code/sdl/src/engine/actor.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-16 18:00]
 *     Last Modified       :     [2017-03-05 18:49]
 *     Description         :      
 **********************************************************************************/

#include "actor.hpp"
#include "utilities.hpp"

Actor::Actor(int x, int y, SDL_Renderer *renderer, SDL_Texture *texture):
  ref_renderer(renderer), m_currentPosition(make_shared<SDL_Rect>()) {

    jnx_guid_create(&m_guid);

    setPosition(x,y);

    setTexture(texture);

    cout << "Created Actor with guid:" << getUniqueIdentifier()  << endl;
  }
Actor::Actor(int x,int y, SDL_Renderer *renderer, string path):
  ref_renderer(renderer)
  , m_currentPosition(make_shared<SDL_Rect>()) {

    jnx_guid_create(&m_guid);

    setPosition(x,y);

    setTexture(load(path,ref_renderer));

    cout << "Created Actor with guid:" << getUniqueIdentifier()  << endl;
  }
Actor::Actor(int x, int y, SDL_Renderer *renderer):
  ref_renderer(renderer)
  , m_currentPosition(make_shared<SDL_Rect>()) {

    jnx_guid_create(&m_guid);

    setPosition(x,y);

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

  for(auto &c : m_components) {
    c->tickEvent(*this, e);
  }
}

SDL_Rect Actor::getBox(void) {

  auto size = getTextureSize();
  SDL_Rect box = { m_currentPosition->x, m_currentPosition->y, 
    size.w, size.h};

  return box;
}
void Actor::addComponent(shared_ptr<IComponent> c) {

  m_components.push_back(c);
}

void Actor::removeComponent(shared_ptr<IComponent> c) {

  m_components.erase(std::remove(m_components.begin(), m_components.end(), c), m_components.end());
}
