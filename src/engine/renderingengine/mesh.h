#ifndef PRIMITIVEMESH_H
#define PRIMITIVEMESH_H

#include <QtGui/QOpenGLContext>

class Mesh
{
public:
    Mesh(std::vector<float> vertices,
         std::vector<GLubyte> indices,
         std::vector<float> colors,
         GLenum primitiveType);

    std::vector<float> getVertices();
    void setVerticies(float getVertices[]);

    std::vector<GLubyte> getIndices();
    void setIndices(float indices[]);

    std::vector<float> getColors();
    void setColors(float colors[]);

    GLenum getPrimitiveType();
    void setPrimitiveType(GLenum type);

protected:
    std::vector<float> m_vertices;
    std::vector<GLubyte> m_indices;
    std::vector<float> m_colors;

    GLenum m_primitiveType;
};

#endif // PRIMITIVEMESH_H
