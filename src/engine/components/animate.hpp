#ifndef __ANIMATE__HPP__
#define __ANIMATE__HPP__
#include "icomponent.hpp"
#include <iostream>
#include <vector>
class Animation {

	public:
	Animation(std::vector<SDL_Rect> clip, std::string name):
	m_name(name),m_clip(clip) {
	}

	std::string m_name;
	std::vector<SDL_Rect> m_clip;

};

class Animate : public IComponent {

	void tickEvent(IObject &actor, SDL_Event *event);

	void AddAnimation(shared_ptr<Animation> animation);
};
#endif