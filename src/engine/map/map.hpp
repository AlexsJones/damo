/*********************************************************************************
 *     File Name           :     src/engine/map/map.hpp
 *     Created By          :     jonesax
 *     Creation Date       :     [2017-03-06 10:15]
 *     Last Modified       :     [2017-03-06 11:54]
 *     Description         :      
 **********************************************************************************/
#ifndef __MAP_HPP__
#define __MAP_HPP__
#include <vector>
#include <SDL2/SDL.h>

using namespace std;

class Block {
  public:
    int size;
};

class Chunk {
  public:
    vector<Block> tiles;
    Chunk() {};
};

class Map {

  public:
    Map();

    SDL_Rect getView(SDL_Rect view);

    SDL_Rect getBox(void);

  private:

    int m_blockSize = 32;
    int m_chunkSize = 32;
    int m_chunksWide = 4;
    int m_chunksHigh = 4;

    SDL_Rect m_box;
    
    vector<Chunk> chunks;
};

#endif
