/*********************************************************************************
 *     File Name           :     /home/anon/Code/sdl/src/engine/actor.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-16 18:00]
 *     Last Modified       :     [2017-03-08 22:20]
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

Actor::Actor(int x, int y, SDL_Renderer *renderer, string path, SDL_Rect custom_render_size):
  ref_renderer(renderer)
  , m_currentPosition(make_shared<SDL_Rect>()) {

    jnx_guid_create(&m_guid);

    setPosition(x,y);

    setTexture(load(path,ref_renderer));

    m_custom_render_size = custom_render_size;

    cout << "Created Actor with guid:" << getUniqueIdentifier()  << endl;
}
Actor::~Actor(void) {

  if(m_texture) {
    cleanup(m_texture);
  }
}
Uint8 Actor::getAction(void) {

  return m_ACTION;
}
void Actor::addAction(Uint8 a) {
  m_ACTION |= a;
}
void Actor::removeAction(Uint8 a) {
  m_ACTION &= a;
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
SDL_Rect Actor::getRenderedSize(void) {

  if(m_custom_render_size.x == 0 && m_custom_render_size.y == 0 &&
    m_custom_render_size.w == 0 && m_custom_render_size.h == 0) {
    return getTextureSize();
  }
  return m_custom_render_size;
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

  if(m_clip.x == 0 && m_clip.y == 0 && m_clip.w == 0 && m_clip.h == 0){
    SDL_RenderCopy(ref_renderer,texture,NULL,&box);
  }
    else {
  SDL_RenderCopy(ref_renderer,texture,&m_clip,&box);
  }
}
void Actor::tickEvent(IObject &o, SDL_Event *e) {

  for(auto &c : m_components) {
    c->tickEvent(*this, e);
  }
}
void Actor::setClip(SDL_Rect c) {

  m_clip = c;

}
SDL_Rect Actor::getBox(void) {

  auto size = getRenderedSize();

  SDL_Rect box = { m_currentPosition->x, m_currentPosition->y, 
    size.w, size.h};

  return box;
}
void Actor::addComponent(shared_ptr<IComponent> c) {

  m_components.push_back(c);
}
void Actor::removeComponent(shared_ptr<IComponent> c) {

}
