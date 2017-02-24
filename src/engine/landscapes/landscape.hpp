/*********************************************************************************
*     File Name           :     src/engine/landscape.hpp
*     Created By          :     anon
*     Creation Date       :     [2016-02-17 18:00]
*     Last Modified       :     [2017-02-23 15:46]
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
    
        shared_ptr<SDL_Rect> getPosition(void);

        void tickEvent(SDL_Event *e);

        bool isEventEnabled(void);

        void render(void);
};

#endif
