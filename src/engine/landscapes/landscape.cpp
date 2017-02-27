/*********************************************************************************
 *     File Name           :     /home/anon/Code/damo/src/engine/landscape.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-17 18:00]
 *     Last Modified       :     [2017-02-23 15:28]
 *     Description         :      
 **********************************************************************************/
#include "landscape.hpp"

Landscape::Landscape(int x, int y, SDL_Renderer *renderer):
Actor(x, y, renderer) {

}  
Landscape::Landscape(int x, int y, SDL_Renderer *renderer, SDL_Texture *texture):
Actor(x, y, renderer, texture) {

}
Landscape::Landscape(int x, int y, SDL_Renderer *renderer, string path):
Actor(x, y, renderer, path){

}
SDL_Texture *Landscape::getTexture(void) {

  return Actor::getTexture();
}
shared_ptr<SDL_Rect> Landscape::getPosition(void) {

  return Actor::getPosition();
}
void Landscape::tickEvent(SDL_Event *e) {

  Actor::tickEvent(e);
}
bool Landscape::isEventEnabled(void) {

  return false;
}
void Landscape::render(SDL_Rect *clip) {

  Actor::render(clip);
}
SDL_Rect Landscape::getTextureSize(void) {

	return Actor::getTextureSize();
}