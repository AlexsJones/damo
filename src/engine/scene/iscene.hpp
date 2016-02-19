/*********************************************************************************
 *     File Name           :     src/engine/scene/iscene.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-19 12:05]
 *     Last Modified       :     [2016-02-19 12:54]
 *     Description         :      
 **********************************************************************************/
#ifndef __ISCENE_HPP__
#define __ISCENE_HPP__
#include "iactor.hpp"
#include <memory>
#include <list>
#include <vector>
using namespace std;

class IScene {

  public:

    virtual ~IScene() {};

    virtual void addActor(shared_ptr<IActor> a) = 0;

    virtual void removeActor(shared_ptr<IActor> a) = 0;

    virtual list<shared_ptr<IActor>> getActors(void) = 0;

};

#endif

