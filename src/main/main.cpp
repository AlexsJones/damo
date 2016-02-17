/*********************************************************************************
 *     File Name           :     src/main/main.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-16 14:58]
 *     Last Modified       :     [2016-02-17 17:57]
 *     Description         :      
 **********************************************************************************/

#include <iostream>
#include <SDL2/SDL.h>
#include "engine.hpp"
#include "scene.hpp"
#include <memory>
#include <thread>
using namespace std;
int main(int argc, char **argv) {


  shared_ptr<Engine> eng = make_shared<Engine>(640,480); 

  string imagePath = getResourcePath("test") + "/image.png";

  string backgroundPath = getResourcePath("test") + "/background.png";

  SDL_Texture *tex = eng->loadTextureFromFile(imagePath);

  SDL_Texture *textwo = eng->loadTextureFromFile(backgroundPath);


  shared_ptr<Actor> a = make_shared<Actor>(tex,0,100);
  
  shared_ptr<Actor> b = make_shared<Actor>(tex,50,50);

  shared_ptr<SDL_Rect> size = a->getSize();

  int x = 640 / 2 - size->w / 2;
  int y = 480 / 2 - size->h / 2;

  cout << "Setting for " << x << ":" << y << endl;

  a->setPosition(x,y);

  int xt = 640 / 40;
  int yt = 480 / 40;

  shared_ptr<Scene> s = make_shared<Scene>();

  s->addActor(a);
  s->addActor(b);
  eng->addScene(s);

  int c =0;

  cout << "Unique id: " << a->getUniqueIdentifier() << endl;

  while(c  < 100) {

    if(c == 50) {
      s->removeActor(a);
    }
    if(c == 75) {
      s->addActor(a);
    }
    eng->tick();
  ++c;
  }
  /*
     for(int x = 0; x < 300; ++x){
     SDL_RenderClear(eng->m_renderer);


     for(int i =0; i < xt  * yt; ++i) {
     int _x = i % xt;
     int _y = i / xt;

     eng->renderTexture(textwo,_x * 40, _y * 40, 40,40);
     }  

     eng->renderActor(a);

     SDL_RenderPresent(eng->m_renderer);
     }
     */

  return 0;
}
