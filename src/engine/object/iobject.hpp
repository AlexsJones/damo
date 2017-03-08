#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__
#include <memory>
#include <SDL2/SDL.h>

using namespace std;

class IObject {

public:
	virtual void setPosition(int x, int y) = 0;

    virtual void setPosition(shared_ptr<SDL_Rect> pos) = 0;

    virtual shared_ptr<SDL_Rect> getPosition(void) = 0;

    virtual Uint8 getAction(void) = 0;

    virtual void addAction(Uint8 a) = 0;

    virtual void removeAction(Uint8 a) = 0;


};

#endif