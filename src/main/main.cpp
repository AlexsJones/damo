/*********************************************************************************
 *     File Name           :     src/main/main.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-16 14:58]
 *     Last Modified       :     [2016-02-16 20:03]
 *     Description         :      
 **********************************************************************************/

#include <iostream>
#include <SDL2/SDL.h>
#include "engine.hpp"
#include <memory>
using namespace std;

int main(int argc, char **argv) {


  shared_ptr<Engine> eng = make_shared<Engine>(640,480); 

  string imagePath = getResourcePath("test") + "/image.bmp";

  string backgroundPath = getResourcePath("test") + "/background.bmp";

  SDL_Texture *tex = eng->loadTextureFromFile(imagePath);

  SDL_Texture *textwo = eng->loadTextureFromFile(backgroundPath);

  shared_ptr<Actor> a = make_shared<Actor>(tex,0,100);



  for(int x = 0; x < 300; ++x){
    SDL_RenderClear(eng->m_renderer);

    eng->renderActor(a);


    SDL_RenderPresent(eng->m_renderer);
  }



  return 0;
}
