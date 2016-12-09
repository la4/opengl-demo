#ifndef PRIMITIVEMESH_H
#define PRIMITIVEMESH_H

#include <QtGui/QOpenGLContext>
#include <gl.h>

class Mesh
{
public:

    Mesh(std::vector<float> vertices,
         std::vector<GLubyte> indices,
         std::vector<float> colors,
         GLenum primitiveType,
         GLenum indicesType);

    static Mesh* createEmptyMesh() {
        return new Mesh(std::vector<float>(), std::vector<GLubyte>(), std::vector<float>(), GL_POINT, GL_UNSIGNED_BYTE);
    }

    float *getVertices();
    //void setVerticies(std::vector<float> getVertices);

    GLubyte *getIndices();
    //void setIndices(std::vector<GLubyte> indices);

    float *getColors();
    //void setColors(std::vector<GLfloat> colors);

    GLenum getPrimitiveType();
    //void setPrimitiveType(GLenum type);

    GLenum getIndicesType();

    GLubyte indicesCount();



protected:
    std::vector<float> m_vertices;
    std::vector<GLubyte> m_indices;
    std::vector<GLfloat> m_colors;

    GLenum m_indicesType;
    GLenum m_primitiveType;
};

#endif // PRIMITIVEMESH_H
