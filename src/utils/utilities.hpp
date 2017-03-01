/*********************************************************************************
 *     File Name           :     src/utils/resourcefinder.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-16 15:19]
 *     Last Modified       :     [2016-12-18 18:25]
 *     Description         :      
 **********************************************************************************/

#ifndef __UTILITIES_HPP__
#define __UTILITIES_HPP__
#include <string>
#include <iostream>
#include <utility>
#include <jnxc_headers/jnx_log.h>
#include <SDL2/SDL.h>

using namespace std;

static string *m_baseRes = NULL;

#define flagOn(a,b) ( a |= b )
#define flagOff(a,b) ( a &= ~(b) )
#define hasFlag(a,b) ( ((a & b) == b) ? true : false )
#define hasFlags(a,b,c) ( ((a & (b | c)) == (b | c)) ? true : false )
#define excludesFlag(a,b) ( ((a & b) == 0) ? true : false ) //un-tested


static string  getResourcePath(const string &subdir ="") {
  const char path_sep = '/';

  if(m_baseRes == NULL) {
    char *basePath = SDL_GetBasePath();
    if(basePath) {

      m_baseRes = new string(basePath);
  
      SDL_free(basePath);
    }else {
      cerr << "Error getting resource path: " << SDL_GetError() << endl;
      return NULL;
    }

  }
  string str;
  str.append(*m_baseRes);
  str.append(subdir);

  JNXLOG(LDEBUG,"Base log path %s", str.c_str());
  return str;
} 
template<typename T, typename... Args>
static void cleanup(T *t, Args&&... args) {

  cleanup(t);

  cleanup(forward<Args>(args)...);
}

template<>
void  cleanup<SDL_Window>(SDL_Window *win){
  if (!win){
    return;
  }
  SDL_DestroyWindow(win);
}

template<>
void  cleanup<SDL_Renderer>(SDL_Renderer *ren){
  if (!ren){
    return;
  }
  SDL_DestroyRenderer(ren);
}

template<>
void  cleanup<SDL_Texture>(SDL_Texture *tex){
  if (!tex){
    return;
  }
  SDL_DestroyTexture(tex);
}

template<>
void  cleanup<SDL_Surface>(SDL_Surface *surf){
  if (!surf){
    return;
  }
  SDL_FreeSurface(surf);
}

#endif

