/*********************************************************************************
*     File Name           :     /Users/jonesax/Work/damo/src/game/actors/test_actor.cpp
*     Created By          :     jonesax
*     Creation Date       :     [2017-01-03 22:18]
*     Last Modified       :     [2017-03-06 13:16]
*     Description         :      
**********************************************************************************/

#include "test_actor.hpp"

TestActor::TestActor(int x, int y, SDL_Renderer *renderer):Actor(x,y,renderer){
}

TestActor::TestActor(int x, int y, SDL_Renderer *renderer, SDL_Texture *texture):Actor(x,y,renderer,texture) {

}
TestActor::TestActor(int x, int y, SDL_Renderer *renderer, string path):Actor(x,y,renderer,path) {

}
TestActor::TestActor(int x, int y, SDL_Renderer *renderer, string path, SDL_Rect custom_size):Actor(x,y,renderer,path,custom_size) {

}
