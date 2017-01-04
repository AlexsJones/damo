/*********************************************************************************
 *     File Name           :     src/main/main.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-16 14:58]
 *     Last Modified       :     [2017-01-04 09:30]
 *     Description         :      
 **********************************************************************************/

#include <iostream>
#include <SDL2/SDL.h>
#include "engine.hpp"
#include "scene.hpp"
#include "test_actor.hpp"
#include <memory>
#include <thread>
using namespace std;

int main(int argc, char **argv) {

  shared_ptr<Engine> eng = make_shared<Engine>(640,480,false);

  string imagePath = getResourcePath("test/damo.png");

  SDL_Texture *tex = eng->loadTextureFromFile(imagePath);

  shared_ptr<Actor> a = make_shared<Actor>(20,20,eng->getRenderer(),"test/damo.png");

  shared_ptr<IScene> s = make_shared<Scene>();
  
  s->addActor(a);
  
  eng->addScene(s);

  while(!eng->IsExiting()) {
    eng->tick();
   }
  return 0;
}
