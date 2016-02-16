/*********************************************************************************
 *     File Name           :     /home/anon/Code/sdl/src/engine/engine.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-16 17:30]
 *     Last Modified       :     [2016-02-16 22:44]
 *     Description         :      
 **********************************************************************************/

#include "engine.hpp"

Engine::Engine(int width, int height):m_width(width),m_height(height) {

  if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    cout << "SDL_Init Error: " << SDL_GetError() << endl;
    exit(1);
  }

  m_window = SDL_CreateWindow("Damo",100, 100, width, height,
      SDL_WINDOW_SHOWN);

  if(m_window == NULL) {
    cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
    SDL_Quit();
    exit(1);
  }

  m_renderer = SDL_CreateRenderer(m_window, -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

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

  SDL_Texture *texture = NULL;

  SDL_Surface *loadedImage = SDL_LoadBMP(filePath.c_str());

  if(loadedImage != NULL) {

    texture = SDL_CreateTextureFromSurface(m_renderer,
        loadedImage);

    cleanup(loadedImage);

  }else {
    cerr << "load error: " << SDL_GetError() << endl;
  }

  return texture;
}
void Engine::renderTexture(SDL_Texture *texture, SDL_Rect location) {
  
  SDL_Rect dst;
  dst.x = location.x;
  dst.y = location.y;
  SDL_QueryTexture(texture,NULL,NULL,&dst.w,&dst.h);
  SDL_RenderCopy(m_renderer,texture,NULL,&dst);
}
void Engine::renderActor(shared_ptr<Actor> a) {

  renderTexture(a->getTexture(),*a->getPosition());
}
void Engine::Tick() {
  
    SDL_RenderClear(m_renderer);

    // Loop all scenes
    // Loop all actors

    SDL_RenderPresent(m_renderer);
}
