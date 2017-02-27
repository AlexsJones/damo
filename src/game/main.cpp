/*********************************************************************************
 *     File Name           :     src/main/main.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-16 14:58]
 *     Last Modified       :     [2017-02-23 14:55]
 *     Description         :      
 **********************************************************************************/

#include <iostream>
#include <SDL2/SDL.h>
#include "engine.hpp"
#include "landscape.hpp"
#include "scene.hpp"
#include "test_actor.hpp"
#include <memory>
#include <thread>
using namespace std;

int main(int argc, char **argv) {

  shared_ptr<Engine> eng = make_shared<Engine>(800,800,false);

  shared_ptr<Actor> a = make_shared<Actor>(20,20,eng->getRenderer(),"resources/test/image.png");

  a->setEvent(true);

  eng->getCamera()->focusActor(a);

  shared_ptr<Actor> b = make_shared<Actor>(500,500,eng->getRenderer(),"resources/test/pattern.png");

  shared_ptr<Landscape> l = make_shared<Landscape>(0,0,eng->getRenderer(),"resources/test/damo.png");

  shared_ptr<IScene> s = make_shared<Scene>();

  s->addActor(a);

  s->addActor(b);

  s->addLandscape(l);

  eng->addScene(s);

  while(!eng->IsExiting()) {
    eng->tick();
  }
  return 0;
}
