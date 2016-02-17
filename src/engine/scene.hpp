/*********************************************************************************
 *     File Name           :     src/engine/scene.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-17 10:23]
 *     Last Modified       :     [2016-02-17 18:05]
 *     Description         :      
 **********************************************************************************/

#ifndef __SCENE_HPP__
#define __SCENE_HPP__
#include <memory>
#include <list>
#include <vector>
#include "landscape.hpp"
#include "actor.hpp"
using namespace std;

class Scene {

  public:
    //The theory here might be that we are only adding a shared reference, so 
    //if the object is disposed the scene updates to remove that pointer, rather than
    //the scene dicating what is alive
    void addActor(shared_ptr<Actor> a);

    void removeActor(shared_ptr<Actor> a);

    list<shared_ptr<Actor>> getActors(void);

  private:

    //A scene contains many actors
    list<shared_ptr<Actor>> m_actorList;
    //A scene contains many landscapes that are built up
    vector<shared_ptr<Landscape>> m_landscapeVector;
};

#endif
