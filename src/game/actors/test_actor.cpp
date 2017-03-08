/*********************************************************************************
*     File Name           :     /Users/jonesax/Work/damo/src/game/actors/test_actor.cpp
*     Created By          :     jonesax
*     Creation Date       :     [2017-01-03 22:18]
*     Last Modified       :     [2017-03-06 13:16]
*     Description         :      
**********************************************************************************/

#include "test_actor.hpp"
#include "physics.hpp"
#include <SDL2/SDL.h>
#include "animate.hpp"
TestActor::TestActor(int x, int y, SDL_Renderer *renderer):
	Actor(x,y,renderer,"resources/test/pog.png",{0,0,47,51}) {

	this->addComponent(make_shared<Physics>());
	SDL_Rect frame = {0,0,47,51};
	auto ani = make_shared<Animate>();
  	frame.w = 47;
    frame.h = 51;
  	ani->addAnimation(Animation({ frame }, LEFT));
  	frame.y += frame.h;
  	ani->addAnimation(Animation({ frame }, RIGHT));
  	frame.y += frame.h;
  	ani->addAnimation(Animation({ frame }, UP));
  	frame.y += frame.h;
  	//Set facing direction
  	setClip(frame);
  	ani->addAnimation(Animation({ frame }, DOWN));
  	frame.y += frame.h;
  	ani->addAnimation(Animation({ frame }, UP + LEFT));
  	frame.y += frame.h;
  	ani->addAnimation(Animation({ frame }, UP + RIGHT));
  	frame.y += frame.h;
  	ani->addAnimation(Animation({ frame }, DOWN + LEFT));
  	frame.y += frame.h;
  	ani->addAnimation(Animation({ frame }, DOWN + RIGHT));
  	this->addComponent(ani);
  	this->setEvent(true);

}

