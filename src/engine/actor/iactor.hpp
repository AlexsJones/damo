/*********************************************************************************
 *     File Name           :     src/engine/actor/iactor.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-19 11:51]
 *     Last Modified       :     [2016-02-19 14:42]
 *     Description         :      
 **********************************************************************************/

#ifndef __IACTOR_HPP__
#define __IACTOR_HPP__
#include <memory>
#include <SDL2/SDL.h>
using namespace std;

class IActor {

  public: 

    virtual void setPosition(int x, int y) = 0;

    virtual shared_ptr<SDL_Rect> getPosition(void) = 0;

    virtual SDL_Texture* getTexture(void) = 0;

    virtual shared_ptr<SDL_Rect> getSize(void) = 0;

    virtual string getUniqueIdentifier(void) = 0;


};

#endif