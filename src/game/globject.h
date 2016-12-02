#ifndef GLOBJECT_H
#define GLOBJECT_H

#include "gameobject.h"
#include "mesh.h"

class GLObject : public GameObject
{
public:
    GLObject(std::vector<float> vertices,
             std::vector<GLubyte> indices,
             std::vector<float> colors,
             GLenum primitiveType, Transform *transform);
    GLObject(Mesh* mesh, Transform *transform);

    virtual Mesh *getMesh();

    virtual ~GLObject();

protected:
    Mesh *m_mesh;
};

#endif // GLOBJECT_H
