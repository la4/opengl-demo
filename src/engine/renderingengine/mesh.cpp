#include "mesh.h"

Mesh::Mesh(std::vector<float> vertices,
     std::vector<GLubyte> indices,
     std::vector<float> colors,
     GLenum primitiveType,
     GLenum indicesType){
    m_vertices = vertices;
    m_indices = indices;
    m_colors = colors;
    m_primitiveType = primitiveType;
    m_indicesType = indicesType;
}

float *Mesh::getVertices() {
    return m_vertices.data();
}

/*void Mesh::setVerticies(std::vector<float> vertices) {
    m_vertices = vertices;
}*/

GLubyte *Mesh::getIndices() {
    return m_indices.data();
}

/*void Mesh::setIndices( std::vector<GLubyte> indices) {
    m_indices = indices;
}*/

float *Mesh::getColors() {
    return m_colors.data();
}

/*void Mesh::setColors(std::vector<GLfloat> colors) {
    m_colors = colors;
}*/

GLenum Mesh::getPrimitiveType() {
    return m_primitiveType;
}

GLubyte Mesh::indicesCount() {
     return static_cast<GLubyte>(m_indices.size());
}

GLenum Mesh::getIndicesType() {
    return m_indicesType;
}

/*void Mesh::setPrimitiveType(const GLenum type) {
    m_primitiveType = type;
}*/
