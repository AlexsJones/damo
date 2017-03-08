/*********************************************************************************
 *     File Name           :     src/game/actors/test_actor.hpp
 *     Created By          :     jonesax
 *     Creation Date       :     [2017-01-03 22:17]
 *     Last Modified       :     [2017-03-06 13:17]
 *     Description         :      
 **********************************************************************************/

#ifndef __TEST_ACTOR_HPP__
#define __TEST_ACTOR_HPP__
#include "actor.hpp"
#include <SDL2/SDl.h>
class TestActor : public Actor {

  public:

    TestActor(int x, int y, SDL_Renderer *renderer);

};
#endif
