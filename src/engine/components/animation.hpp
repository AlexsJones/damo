#ifndef __ANIMATION_HPP__
#define __ANIMATION_HPP__
#include <vector>
#include <SDL2/SDL.h>
#include <string>
#include "types.hpp"

class Animation {

	public:
		Animation(std::vector<SDL_Rect> sequence, Uint8 action);

		Uint8 getAction(void);

		std::vector<SDL_Rect> getSequence(void);

	private:
	Uint8 m_action;
	std::vector<SDL_Rect> m_sequence;

};

#endif