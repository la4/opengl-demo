#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <vector>

#include "gl.h"
#include "transform.h"
#include "mesh.h"

class GameObject
{
public:
    GameObject(Transform *transform);

    virtual ~GameObject();

    virtual Transform *getTransform();

 protected:
    Transform *m_transform;
};

#endif // GAMEOBJECT_H
