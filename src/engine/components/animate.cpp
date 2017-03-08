#include "animate.hpp"
#include "utilities.hpp"
void Animate::tickEvent(IObject &actor, SDL_Event *event) {

	auto ACTION = actor.getAction();

	auto t = m_hashmap.find(ACTION);
    if (t == m_hashmap.end()) return;
    	Animation value = t->second;
	 	actor.setClip(value.getSequence().front());

}
void Animate::addAnimation(Animation animation) {

	std::pair<Uint8,Animation> i(animation.getAction(),animation);

	m_hashmap.insert(i);
}
std::unordered_map<Uint8, Animation > Animate::getHashmap(void) {
	
	return m_hashmap;
}