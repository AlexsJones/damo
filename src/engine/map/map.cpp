/*********************************************************************************
 *     File Name           :     /Users/jonesax/Work/damo/src/engine/map/map.cpp
 *     Created By          :     jonesax
 *     Creation Date       :     [2017-03-06 11:25]
 *     Last Modified       :     [2017-03-06 13:08]
 *     Description         :      
 **********************************************************************************/
#include "map.hpp"

Map::Map() {

  chunks.reserve(m_chunksWide * m_chunksHigh * m_chunkSize * m_blockSize);
  m_box.w = m_chunksWide * m_chunkSize * m_blockSize;
  m_box.h = m_chunksHigh * m_chunkSize * m_blockSize;
  m_box.x = -(m_box.w / 2);
  m_box.y = -(m_box.h / 2);
}
SDL_Rect Map::getBox(void) {

  return m_box;
}
SDL_Rect Map::getView(SDL_Rect view) {
  view.x -= (view.x % m_blockSize) + m_blockSize;
  view.y -= (view.y % m_blockSize) + m_blockSize;
  view.w += (view.w % m_blockSize) + m_blockSize;
  view.h += (view.h % m_blockSize) + m_blockSize;            
  return view;

}
