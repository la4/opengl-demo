#include "cube.h"

Cube::Cube() {

}

Cube::Cube(std::vector<float> vertices,
           std::vector<GLubyte> indices,
           std::vector<float> colors,
           GLenum primitiveType) {
    this->m_vertices = vertices;
    this->m_indices = indices;
    this->m_colors = colors;
    this->m_primitiveType = primitiveType;
}

const float* Cube::vertices() const {
    const float* returnValue = this->m_vertices.data();
    return returnValue;
}

const GLubyte* Cube::indices() const {
    const GLubyte* returnValue = this->m_indices.data();
    return returnValue;
}

const float* Cube::colors() const {
    const float* returnValue = this->m_colors.data();
    return returnValue;
}

GLubyte Cube::indicesCount() const {
    auto returnValue = this->m_indices.size();
    return static_cast<GLubyte>(returnValue);
}
GLubyte Cube::verticesCount() const {
    auto returnValue = this->m_vertices.size();
    return static_cast<GLubyte>(returnValue);
}

GLenum Cube::primitiveType() const {
    return m_primitiveType;
}
