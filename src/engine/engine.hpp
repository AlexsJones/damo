/*********************************************************************************
 *     File Name           :     src/engine/engine.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-16 17:27]
 *     Last Modified       :     [2016-02-16 19:29]
 *     Description         :      
 **********************************************************************************/

#ifndef __ENGINE_HPP__
#define __ENGINE_HPP__
#include <SDL2/SDL.h>
#include "utilities.hpp"
#include "actor.hpp"
#include "types.hpp"
#include <memory>

using namespace std;

class Engine {

  public:

    Engine(int width, int height);

    ~Engine();

    void Tick(void);

    SDL_Texture *loadTextureFromFile(string filePath);

    void renderTexture(SDL_Texture *texture, SDL_Rect location); 

    void renderActor(shared_ptr<Actor> a);

    SDL_Renderer *m_renderer;
 
  private:

    SDL_Window *m_window;

};


#endif
