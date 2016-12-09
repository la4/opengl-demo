#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "transform.h"
#include "mesh.h"

class GameObject
{
public:
    GameObject(Transform *transform, Mesh *mesh);

    virtual ~GameObject();

    virtual Mesh *getMesh();
    virtual Transform *getTransform();

 protected:
    Mesh *m_mesh;
    Transform *m_transform;
};

#endif // GAMEOBJECT_H
