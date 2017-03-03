/*********************************************************************************
 *     File Name           :     src/engine/actor.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-16 17:57]
 *     Last Modified       :     [2017-03-01 22:38]
 *     Description         :      
 **********************************************************************************/

#ifndef __ACTOR_HPP__
#define __ACTOR_HPP__
#include "iactor.hpp"
#include "utilities.hpp"
#include "textureloader.hpp"
#include <SDL2/SDL.h>
#include <memory>

using namespace std;

class Actor : public IActor, public TextureLoader  {

  public:
    void setTexture(SDL_Texture *tex);

    SDL_Rect getTextureSize(void);

    SDL_Texture *getTexture(void);

    SDL_Rect getBox(void);

    void setPosition(int x, int y);

    void setPosition(shared_ptr<SDL_Rect> pos);

    shared_ptr<SDL_Rect> getPosition(void);

    void tickEvent(SDL_Event *event);

    void render(const SDL_Rect *clip);

    bool isEventEnabled(void) {
      return m_event_enabled;
    }

    void setEvent(bool t) {
      m_event_enabled = t;
    }

    string getUniqueIdentifier(void) {
          jnx_char *str;
      jnx_guid_to_string(&m_guid,&str);
      string output(str);
      free(str);
      return output;
    };

    Actor(int x, int y, SDL_Renderer *renderer);

    Actor(int x, int y, SDL_Renderer *renderer, SDL_Texture *texture);

    Actor(int x, int y, SDL_Renderer *renderer, string path);

    ~Actor(void);

  private:

    Uint8 ACTION = 0;

    SDL_Rect m_box;

    bool m_event_enabled = false;

    SDL_Texture *m_texture;

    SDL_Renderer *ref_renderer;

    shared_ptr<SDL_Rect> m_currentPosition;

};

#endif
