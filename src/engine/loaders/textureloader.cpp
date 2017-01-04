/*********************************************************************************
*     File Name           :     /Users/jonesax/Work/damo/src/engine/loaders/textureloader.cpp
*     Created By          :     jonesax
*     Creation Date       :     [2017-01-04 08:28]
*     Last Modified       :     [2017-01-04 09:03]
*     Description         :      
**********************************************************************************/

#include "textureloader.hpp"
#include "utilities.hpp"
#include <SDL2/SDL_image.h>
#include <jnxc_headers/jnx_log.h>

SDL_Texture* TextureLoader::load(std::string path,SDL_Renderer *renderer ) {

  auto resolvedPath = getResourcePath(path);
  JNXLOG(LDEBUG,"Loading texture...");
  SDL_Texture *texture = IMG_LoadTexture(renderer,
      resolvedPath.c_str());

  if(texture == NULL) {
    cerr << "loadTextureFromFile:" << SDL_GetError() << endl;
    return NULL;
  }
  return texture;
}
