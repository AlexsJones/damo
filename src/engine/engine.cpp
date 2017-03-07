/*********************************************************************************
 *     File Name           :     /home/anon/Code/sdl/src/engine/engine.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-16 17:30]
 *     Last Modified       :     [2017-03-06 10:42]
 *     Description         :      
 **********************************************************************************/

#include "engine.hpp"
#include "utilities.hpp"
#include <SDL2/SDL_image.h>

Engine::Engine(int width, int height,bool is_fullscreen):
  m_width(width),m_height(height) {

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
      cout << "SDL_Init Error: " << SDL_GetError() << endl;
      exit(1);
    }

    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
      cerr << "IMG_INIT:" << SDL_GetError() << endl;
      exit(1);
    }

    m_window = SDL_CreateWindow("Damo",SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED
        , width, height,
        SDL_WINDOW_SHOWN);

    if(m_window == NULL) {
      cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
      SDL_Quit();
      exit(1);
    }

    if(is_fullscreen){
      SDL_SetWindowFullscreen(m_window,SDL_WINDOW_FULLSCREEN_DESKTOP );
    }

    m_renderer = SDL_CreateRenderer(m_window, -1 ,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(m_renderer == NULL) {
      cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
      cleanup(m_window);
      exit(1);
    }
    m_camera = make_shared<Camera>(m_window);

  }
Engine::~Engine() {

  cleanup(m_window,m_renderer);

  SDL_Quit();
}
void Engine::renderScene(shared_ptr<IScene> s, SDL_Event *e) {

  SDL_Rect offset = m_camera->getBox();

  for(auto l : s->getLandscapes()) {
    if(l->isEventEnabled()) {
      l->tickEvent(*l,e);
    } 
    l->render(&offset);
  }

  for(auto a : s->getActors()) {
    if(a->isEventEnabled()) {
      a->tickEvent(*a,e);
    }

    //Just for debug...
    drawRect(a->getBox());

    a->render(&offset);
  }

}
void Engine::tick() {

  SDL_RenderClear(m_renderer);

  //Trap events
  SDL_Event e;
  while(SDL_PollEvent(&e)) {
    switch(e.type) {
      case SDL_QUIT:
        b_shouldExit=true;
        break;
      case SDL_KEYDOWN:
        if (e.key.keysym.sym == SDLK_F4) {
          if (hasFlag(SDL_GetWindowFlags(m_window), SDL_WINDOW_FULLSCREEN)) {
            SDL_SetWindowFullscreen(m_window, SDL_FALSE);
            SDL_SetWindowGrab(m_window, SDL_FALSE);
          }else {
            SDL_SetWindowFullscreen(m_window, SDL_TRUE);
            SDL_SetWindowGrab(m_window, SDL_TRUE);
          }
        }; 
        break;
      case SDL_WINDOWEVENT:
        //window.update(event.window);
        if ( e.window.event == SDL_WINDOWEVENT_RESIZED ){
          //  window.resize();
          //  camera.resize(window.getBox());
        }
        break;
    }
  }

  m_camera->update();

  for(auto s : m_scenes) {
    renderScene(s, &e);
  }

  SDL_RenderPresent(m_renderer);
}
void Engine::addScene(shared_ptr<IScene> s) {

  m_scenes.push_back(s);
}
bool Engine::IsExiting(void) {

  return b_shouldExit;
}
SDL_Renderer* Engine::getRenderer(void) {
  return m_renderer;
}
shared_ptr<Camera> Engine::getCamera(void) {
  return m_camera;
}
void Engine::drawRect(SDL_Rect rect) {
  rect.x -= m_camera->getBox().x;
  rect.y -= m_camera->getBox().y;
  SDL_SetRenderDrawColor(m_renderer, 255,0,0,255);
  SDL_RenderDrawRect( m_renderer, &rect);
  SDL_SetRenderDrawColor(m_renderer, 0,0,0,0);
}
