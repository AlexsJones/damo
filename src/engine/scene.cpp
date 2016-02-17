/*********************************************************************************
*     File Name           :     /home/anon/Code/damo/src/engine/scene.cpp
*     Created By          :     anon
*     Creation Date       :     [2016-02-17 10:24]
*     Last Modified       :     [2016-02-17 18:03]
*     Description         :      
**********************************************************************************/

#include "scene.hpp"
    

void Scene::addActor(shared_ptr<Actor> a) {
  
  m_actorList.push_back(a);

}
list<shared_ptr<Actor>> Scene::getActors(void) {

  return m_actorList;
}
void Scene::removeActor(shared_ptr<Actor> a) {

    m_actorList.remove(a);
}

