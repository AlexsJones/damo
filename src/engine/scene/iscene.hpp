/*********************************************************************************
 *     File Name           :     src/engine/scene/iscene.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-02-19 12:05]
 *     Last Modified       :     [2016-02-29 21:39]
 *     Description         :      
 **********************************************************************************/
#ifndef __ISCENE_HPP__
#define __ISCENE_HPP__
#include "iactor.hpp"
#include "ilandscape.hpp"
#include <memory>
#include <list>
#include <vector>
using namespace std;

class IScene {

  public:

    virtual ~IScene() {};
  
    virtual void addActor(shared_ptr<IActor> a) = 0;

    virtual void removeActor(shared_ptr<IActor> a) = 0;

    virtual void addLandscape(shared_ptr<ILandscape> l) =0;

    virtual void removeLandscape(shared_ptr<ILandscape> l) =0;
    
    virtual list<shared_ptr<IActor>> getActors(void) = 0;

};

#endif

