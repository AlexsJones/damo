/*********************************************************************************
 *     File Name           :     /home/anon/Code/damo/src/engine/landscape.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-17 18:00]
 *     Last Modified       :     [2017-02-23 15:28]
 *     Description         :      
 **********************************************************************************/
#include "landscape.hpp"

Landscape::Landscape(int width, int height, int x, int y):
  m_width(width), m_height(height){
    m_currentPosition = make_shared<SDL_Rect>();
    m_currentPosition->x = x;
    m_currentPosition->y = y;

  }
shared_ptr<SDL_Rect> Landscape::getPosition(void) {

  return m_currentPosition;
}
shared_ptr<SDL_Rect> Landscape::getSize(void) {

  shared_ptr<SDL_Rect> r = make_shared<SDL_Rect>();
  r->w = m_width;
  r->h = m_height;

  return r;
}
void Landscape::setTexture(SDL_Texture *tex) {


}
shared_ptr<SDL_Rect> Landscape::getTextureSize(void) {

}
void Landscape::setPosition(int x, int y) {

}
void Landscape::setPosition(shared_ptr<SDL_Rect> pos) {


}
SDL_Texture* Landscape::getTexture(void) {

}
void Landscape::tickEvent(SDL_Event *e) {

}
bool Landscape::isEventEnabled(void) {

}


