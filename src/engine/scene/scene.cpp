/*********************************************************************************
 *     File Name           :     /home/anon/Code/damo/src/engine/scene.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-17 10:24]
 *     Last Modified       :     [2016-02-19 12:31]
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

