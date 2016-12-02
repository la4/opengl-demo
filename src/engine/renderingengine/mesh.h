#ifndef PRIMITIVEMESH_H
#define PRIMITIVEMESH_H

#include <QtGui/QOpenGLContext>

class Mesh
{
public:
    Mesh();

    Mesh(std::vector<float> vertices,
         std::vector<GLubyte> indices,
         std::vector<float> colors,
         GLenum primitiveType);

    float *getVertices();
    void setVerticies(std::vector<float> getVertices);

    GLubyte *getIndices();
    void setIndices(std::vector<GLubyte> indices);

    float *getColors();
    void setColors(std::vector<GLfloat> colors);

    GLenum getPrimitiveType();
    void setPrimitiveType(GLenum type);

    GLubyte indicesCount();

protected:
    std::vector<float> m_vertices;
    std::vector<GLubyte> m_indices;
    std::vector<GLfloat> m_colors;

    GLenum m_primitiveType;
};

#endif // PRIMITIVEMESH_H
