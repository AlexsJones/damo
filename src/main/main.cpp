/*********************************************************************************
 *     File Name           :     src/main/main.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-16 14:58]
 *     Last Modified       :     [2016-12-20 14:52]
 *     Description         :      
 **********************************************************************************/

#include <iostream>
#include <SDL2/SDL.h>
#include "engine.hpp"
#include "actor.hpp"
#include "scene.hpp"
#include <memory>
#include <thread>
using namespace std;

int main(int argc, char **argv) {

  shared_ptr<Engine> eng = make_shared<Engine>(640,480,false);

  string imagePath = getResourcePath("test") + "/image.png";

  SDL_Texture *tex = eng->loadTextureFromFile(imagePath);

  shared_ptr<Actor> a = make_shared<Actor>(tex,0,100);

  shared_ptr<SDL_Rect> size = a->getSize();

  int x = 640 / 2 - size->w / 2;
  int y = 480 / 2 - size->h / 2;

  a->setPosition(x,y);

  int xt = 640 / 40;
  int yt = 480 / 40;
  
  shared_ptr<IScene> s = make_shared<Scene>();
  s->addActor(a);
  eng->addScene(s);

  while(!eng->IsExiting()) {
    eng->tick();
  }
  return 0;
}
