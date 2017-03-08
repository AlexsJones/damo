#include "animation.hpp"

Animation::Animation(std::vector<SDL_Rect> sequence, Uint8 action):
m_action(action),m_sequence(sequence) {

}
Uint8 Animation::getAction(void) {

	return m_action;
}
std::vector<SDL_Rect> Animation::getSequence(void) {

	return m_sequence;
}