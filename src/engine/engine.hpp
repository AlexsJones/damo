/*********************************************************************************
 *     File Name           :     src/engine/engine.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-16 17:27]
 *     Last Modified       :     [2017-02-23 15:10]
 *     Description         :      
 **********************************************************************************/

#ifndef __ENGINE_HPP__
#define __ENGINE_HPP__
#include <SDL2/SDL.h>
#include "utilities.hpp"
#include "ilandscape.hpp"
#include "iactor.hpp"
#include "iscene.hpp"
#include "camera.hpp"
#include <list>
#include <memory>
#include "engineconstraints.hpp"
using namespace std;

class Engine {

  public:

    Engine(int width, int height,bool is_fullscreen=false);

    ~Engine();

    void tick(void);

    void renderScene(shared_ptr<IScene> s, SDL_Event *e);

    void addScene(shared_ptr<IScene> s);

    bool IsExiting(void);

    SDL_Renderer *getRenderer(void);

    shared_ptr<Camera> getCamera(void);

  private:

    shared_ptr<Camera> m_camera;

    SDL_Renderer *m_renderer;
    
    SDL_Window *m_window;

    list<shared_ptr<IScene>> m_scenes;

    int m_width;

    int m_height;
  
    bool b_shouldExit;
};


#endif
