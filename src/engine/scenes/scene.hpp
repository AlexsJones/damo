/*********************************************************************************
 *     File Name           :     src/engine/scene.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-17 10:23]
 *     Last Modified       :     [2017-02-23 14:33]
 *     Description         :      
 **********************************************************************************/

#ifndef __SCENE_HPP__
#define __SCENE_HPP__
#include <memory>
#include <list>
#include <vector>
#include "iscene.hpp"
using namespace std;

class Scene : public IScene {

  public:

    ~Scene();

    void addActor(shared_ptr<IActor> a);

    void removeActor(shared_ptr<IActor> a);

    void addLandscape(shared_ptr<ILandscape> l);

    void removeLandscape(shared_ptr<ILandscape> l);
    
    list<shared_ptr<IActor>> getActors(void);

  private:

    //A scene contains many actors
    list<shared_ptr<IActor>> m_actorList;
    //A scene contains many landscapes that are built up
    list<shared_ptr<ILandscape>> m_landscapeList;
};

#endif
