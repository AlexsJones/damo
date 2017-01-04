/*********************************************************************************
 *     File Name           :     /home/anon/Code/damo/src/engine/scene.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-17 10:24]
 *     Last Modified       :     [2016-12-27 01:30]
 *     Description         :      
 **********************************************************************************/

#include "scene.hpp"

Scene::~Scene() {

}
void Scene::addActor(shared_ptr<IActor> a) {

  m_actorList.push_back(a);

}
list<shared_ptr<IActor>> Scene::getActors(void) {

  return m_actorList;
}
void Scene::removeActor(shared_ptr<IActor> a) {

  m_actorList.remove(a);
}

void Scene::addLandscape(shared_ptr<ILandscape> l) {
  
  m_landscapeList.push_back(l);
}
void Scene::removeLandscape(shared_ptr<ILandscape> l) {

  m_landscapeList.remove(l);
}
