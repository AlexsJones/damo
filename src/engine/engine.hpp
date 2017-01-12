/*********************************************************************************
 *     File Name           :     src/engine/engine.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-16 17:27]
 *     Last Modified       :     [2017-01-12 09:54]
 *     Description         :      
 **********************************************************************************/

#ifndef __ENGINE_HPP__
#define __ENGINE_HPP__
#include <SDL2/SDL.h>
#include "utilities.hpp"
#include "iactor.hpp"
#include "iscene.hpp"
#include <list>
#include <memory>
#include "engineconstraints.hpp"
using namespace std;

class Engine {

  public:

    Engine(int width, int height,bool is_fullscreen=false);

    ~Engine();

    void tick(void);

    SDL_Texture *loadTextureFromFile(string filePath);

    void renderTexture(SDL_Texture *texture, shared_ptr<SDL_Rect> location,
        SDL_Rect *clip); 

    void renderActor(shared_ptr<IActor> a, SDL_Event *e);

    void renderScene(shared_ptr<IScene> s, SDL_Event *e);

    void addScene(shared_ptr<IScene> s);

    bool IsExiting(void);

    SDL_Renderer *getRenderer(void);

  private:

    SDL_Renderer *m_renderer;
    
    SDL_Window *m_window;

    list<shared_ptr<IScene>> m_scenes;

    int m_width;

    int m_height;
  
    bool b_shouldExit;
};


#endif
