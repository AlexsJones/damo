/*********************************************************************************
*     File Name           :     src/engine/actor.hpp
*     Created By          :     anon
*     Creation Date       :     [2016-02-16 17:57]
*     Last Modified       :     [2016-02-16 22:37]
*     Description         :      
**********************************************************************************/

#ifndef __ACTOR_HPP__
#define __ACTOR_HPP__
#include "utilities.hpp"
#include "types.hpp"
#include <SDL2/SDL.h>
#include <memory>

using namespace std;

class Actor {

  public:

    SDL_Texture *getTexture(void);

    void setPosition(int x, int y);

    shared_ptr<SDL_Rect> getPosition(void);

    shared_ptr<SDL_Rect> getSize(void);

    Actor(SDL_Texture *texture,int x, int y);

    ~Actor();
  private:

    SDL_Texture *m_texture;

    shared_ptr<SDL_Rect> m_currentPosition;

};


#endif
