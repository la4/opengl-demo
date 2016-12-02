#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <vector>

#include "gl.h"
#include "mesh.h"
#include "transform.h"

class GameObject
{
public:
    GameObject();
    GameObject(std::vector<float> vertices,
               std::vector<GLubyte> indices,
               std::vector<float> colors,
               GLenum primitiveType);

    virtual ~GameObject();

    virtual Mesh *getMesh();
    virtual void setMesh(Mesh *mesh);

    virtual Transform *getTransform();
    virtual void setTransform(Transform *transform);

 protected:
    Mesh *m_mesh;
    Transform *m_transform;
};

#endif // GAMEOBJECT_H
