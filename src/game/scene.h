#ifndef SCENE_H
#define SCENE_H

#include <list>

#include "gameobject.h"

typedef std::list<GameObject *> ObjectsContainer;

/* Abstract class with function initialize needed to be overrided by concrete
 * scene instance. This approach allows us to create multiple scenes with
 * different set of objects. */
class Scene
{
public:
    Scene();
    virtual ~Scene();

    virtual void initialize() = 0;
    virtual void addObject(GameObject *object);
    virtual void removeObject(GameObject *object);

    virtual const ObjectsContainer *getObjectsContainer();

protected:
    ObjectsContainer *m_gameObjects; //TODO: should be a better way to encapsulate and ship objects
};

#endif // SCENE_H
