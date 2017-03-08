/*********************************************************************************
 *     File Name           :     src/engine/landscape.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-17 18:00]
 *     Last Modified       :     [2017-02-28 13:11]
 *     Description         :      
 **********************************************************************************/
#ifndef __LANDSCAPE_HPP__
#define __LANDSCAPE_HPP__
#include <memory>
#include <SDL2/SDL.h>
#include "actor.hpp"
#include "ilandscape.hpp"

using namespace std;

class Landscape : public Actor, public ILandscape{

  public:

    Landscape(int x, int y, SDL_Renderer *renderer);

    Landscape(int x, int y, SDL_Renderer *renderer, SDL_Texture *texture);

    Landscape(int x, int y, SDL_Renderer *renderer, string path);

    SDL_Texture *getTexture(void);

    Uint8 getAction(void) { 
        return 0;
    }
    void addAction(Uint8 a) {}

    void removeAction(Uint8 a){}

    void setPosition(int x, int y);

    void setPosition(shared_ptr<SDL_Rect> pos);

    shared_ptr<SDL_Rect> getPosition(void);

    void tickEvent(IObject &o, SDL_Event *e);

    bool isEventEnabled(void);

    void render(SDL_Rect *clip);

    SDL_Rect getTextureSize(void);

    void setClip(SDL_Rect c);

};

#endif
