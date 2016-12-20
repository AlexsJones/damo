/*********************************************************************************
 *     File Name           :     /home/anon/Code/sdl/src/engine/engine.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-16 17:30]
 *     Last Modified       :     [2016-12-20 14:56]
 *     Description         :      
 **********************************************************************************/

#include "engine.hpp"
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

}
Engine::~Engine() {

  cleanup(m_window,m_renderer);

  SDL_Quit();
}
SDL_Texture *Engine::loadTextureFromFile(string filePath) {

  SDL_Texture *texture = IMG_LoadTexture(m_renderer,
      filePath.c_str());
  if(texture == NULL) {
    cerr << "loadTextureFromFile:" << SDL_GetError() << endl;
  }

  return texture;
}
void Engine::renderTexture(SDL_Texture *texture, SDL_Rect location,
    SDL_Rect *clip = NULL) {

  SDL_Rect dst;
  dst.x = location.x;
  dst.y = location.y;

  if(clip != NULL) {
    dst.w = clip->w;
    dst.h = clip->h;
  }else {
    SDL_QueryTexture(texture,NULL,NULL,&dst.w,&dst.h);
  }

  SDL_RenderCopy(m_renderer,texture,clip,&dst);
}
void Engine::renderActor(shared_ptr<IActor> a) {

  renderTexture(a->getTexture(),*a->getPosition());
}
void Engine::renderScene(shared_ptr<IScene> s) {

  for(auto a : s->getActors()) {
    renderActor(a); 
  }

}
void Engine::event() {

  SDL_Event e;
  while(SDL_PollEvent(&e)) {
    if(e.type == SDL_QUIT) {
      b_shouldExit = true;
    }
  }
}
void Engine::tick() {

  SDL_RenderClear(m_renderer);

  //Trap events
  event();

  for(auto s : m_scenes) {
    renderScene(s);
  }

  SDL_RenderPresent(m_renderer);
}
void Engine::addScene(shared_ptr<IScene> s) {

  m_scenes.push_back(s);
}
bool Engine::IsExiting(void) {

  return b_shouldExit;
}
