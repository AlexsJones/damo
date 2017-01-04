/*********************************************************************************
 *     File Name           :     src/engine/loaders/textureloader.hpp
 *     Created By          :     jonesax
 *     Creation Date       :     [2017-01-04 08:26]
 *     Last Modified       :     [2017-01-04 09:32]
 *     Description         :      
 **********************************************************************************/
#ifndef __TEXTURE_LOADER_HPP__
#define __TEXTURE_LOADER_HPP__
#include "tloader.hpp"
#include <SDL2/SDL.h>
class TextureLoader : public TLoader<SDL_Texture*> {

  public:
    SDL_Texture* load(std::string path, SDL_Renderer *renderer);
};

#endif
