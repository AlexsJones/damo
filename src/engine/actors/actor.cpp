/*********************************************************************************
 *     File Name           :     /home/anon/Code/sdl/src/engine/actor.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-16 18:00]
 *     Last Modified       :     [2017-02-23 15:26]
 *     Description         :      
 **********************************************************************************/

#include "actor.hpp"
#include "utilities.hpp"

Actor::Actor(int x, int y, SDL_Renderer *renderer, SDL_Texture *texture):
  ref_renderer(renderer), m_currentPosition(make_shared<SDL_Rect>()) {

    setPosition(x,y);

    setTexture(texture);
  }
Actor::Actor(int x,int y, SDL_Renderer *renderer, string path):
  ref_renderer(renderer)
  , m_currentPosition(make_shared<SDL_Rect>()) {

    setPosition(x,y);

    setTexture(load(path,ref_renderer));
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
void Actor::render() {

  SDL_Rect *clip = NULL;
  auto location = getPosition();
  auto texture = getTexture();
  SDL_Rect dst;
  dst.x = location->x;
  dst.y = location->y;

  std::cout << "x:" << dst.x << " y:" << dst.y << std::endl;
  if(clip != NULL) {
    dst.w = clip->w;
    dst.h = clip->h;
  }else {
    SDL_QueryTexture(texture,NULL,NULL,&dst.w,&dst.h);
  }

  SDL_RenderCopy(ref_renderer,texture,clip,&dst);
}
void Actor::tickEvent(SDL_Event *e) {

  int xval = 0;
  int yval = 0;

  SDL_Event event = *e;
  if(event.type == SDL_KEYDOWN){ 
    switch(event.key.keysym.sym) {
      case SDLK_UP:
        m_currentPosition->y -= 1;
        break;
      case SDLK_DOWN:
        m_currentPosition->y += 1;
        break;
      case SDLK_LEFT:
        m_currentPosition->x -= 1;
        break;
      case SDLK_RIGHT:
        m_currentPosition->x += 1;
        break;
    }
  }
}
