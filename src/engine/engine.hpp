/*********************************************************************************
 *     File Name           :     src/engine/engine.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-16 17:27]
 *     Last Modified       :     [2016-02-17 21:45]
 *     Description         :      
 **********************************************************************************/

#ifndef __ENGINE_HPP__
#define __ENGINE_HPP__
#include <SDL2/SDL.h>
#include "utilities.hpp"
#include "actor.hpp"
#include "scene.hpp"
#include <list>
#include <memory>

using namespace std;

class Engine {

  public:

    Engine(int width, int height);

    ~Engine();

    void tick(void);

    void event(void);

    SDL_Texture *loadTextureFromFile(string filePath);

    void renderTexture(SDL_Texture *texture, SDL_Rect location); 

    void renderTexture(SDL_Texture *texture, int x, int y, int w, int h); 

    void renderActor(shared_ptr<Actor> a);

    void renderScene(shared_ptr<Scene> s);

    void addScene(shared_ptr<Scene> s);

    bool IsExiting(void);

    SDL_Renderer *m_renderer;

  private:

    SDL_Window *m_window;

    list<shared_ptr<Scene>> m_scenes;

    int m_width;

    int m_height;
  
    bool b_shouldExit;
};


#endif
