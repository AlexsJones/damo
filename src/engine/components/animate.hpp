#ifndef __ANIMATE__HPP__
#define __ANIMATE__HPP__
#include "icomponent.hpp"
#include "types.hpp"
#include "animation.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>

class Animate : public IComponent {

public:

	void tickEvent(IObject &actor, SDL_Event *event);

	void addAnimation(Animation animation);

private:
	std::unordered_map<Uint8, Animation > m_hashmap;
};
#endif