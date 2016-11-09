#ifndef CUBE_H
#define CUBE_H

#include "iprimitiverenderobject.h"
#include "gl.h"
#include <vector>

class Cube : public IPrimitiveRenderObject
{
public:
    Cube();
    Cube(std::vector<float> vertices,
               std::vector<GLubyte> indices,
               std::vector<float> colors,
               GLenum primitiveType);
    const virtual float* vertices() const override;
    const virtual GLubyte* indices() const override;
    const virtual float* colors() const override;

    virtual GLubyte indicesCount() const override;
    virtual GLubyte verticesCount() const override;

    virtual GLenum primitiveType() const override;

private:
    std::vector<float> m_vertices;
    std::vector<GLubyte> m_indices;
    std::vector<float> m_colors;
    GLenum m_primitiveType;
};

#endif // CUBE_H
