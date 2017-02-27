/*********************************************************************************
 *     File Name           :     src/engine/camera/camera.hpp
 *     Created By          :     jonesax
 *     Creation Date       :     [2017-02-27 11:06]
 *     Last Modified       :     [2017-02-27 13:50]
 *     Description         :      
 **********************************************************************************/

#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__
#include <SDL2/SDL.h>
#include "iactor.hpp"

class Camera {

  public:
    Camera(SDL_Window *window);

    void focusActor(shared_ptr<IActor> a);

    SDL_Rect getBox(void);
    
    void update(void);

    shared_ptr<IActor> getFocus(void);

  private:
  	SDL_Rect m_bounds;
 
  	SDL_Rect m_box = {0,0,0,0};

  	shared_ptr<IActor> m_followed_actor;
};
#endif
