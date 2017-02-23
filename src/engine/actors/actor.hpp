/*********************************************************************************
*     File Name           :     src/engine/actor.hpp
*     Created By          :     anon
*     Creation Date       :     [2016-02-16 17:57]
*     Last Modified       :     [2017-02-23 15:27]
*     Description         :      
**********************************************************************************/

#ifndef __ACTOR_HPP__
#define __ACTOR_HPP__
#include "iactor.hpp"
#include "utilities.hpp"
#include "textureloader.hpp"
#include <SDL2/SDL.h>
#include <memory>

using namespace std;

class Actor : public IActor, public TextureLoader  {

  public:
    void setTexture(SDL_Texture *tex);

    shared_ptr<SDL_Rect> getTextureSize(void);

    SDL_Texture *getTexture(void);

    void setPosition(int x, int y);

    void setPosition(shared_ptr<SDL_Rect> pos);
    
    shared_ptr<SDL_Rect> getPosition(void);
 
    void tickEvent(SDL_Event *event);

    bool isEventEnabled(void) {
      return true;
    }
    Actor(int x, int y, SDL_Renderer *renderer);
    
    Actor(int x, int y, SDL_Renderer *renderer, SDL_Texture *texture);

    Actor(int x, int y, SDL_Renderer *renderer, string path);

    ~Actor(void);

  private:

    SDL_Texture *m_texture;

    SDL_Renderer *ref_renderer;

    shared_ptr<SDL_Rect> m_currentPosition;
};

#endif