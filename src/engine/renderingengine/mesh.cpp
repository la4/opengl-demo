#include "mesh.h"


Mesh::Mesh(std::vector<float> vertices,
     std::vector<GLubyte> indices,
     std::vector<float> colors,
     GLenum primitiveType){
}

std::vector<float> Mesh::getVertices() {
    return m_vertices;
}

void Mesh::setVerticies(float vertices[]) {
    m_vertices = vector<float>(vertices, vertices + sizeof(vertices) / sizeof(vertices[0]));
}

std::vector<GLubyte> Mesh::getIndices() {
    return m_indices;
}

void Mesh::setIndices(float indices[]) {
    m_indices = vector<GLubyte>(indices, indices + sizeof(indices) / sizeof(indices[0]));
}

std::vector<float> Mesh::getColors() {
    return m_colors;
}

void Mesh::setColors(float colors[]) {
    m_colors = vector<float>(colors, colors + sizeof(colors) / sizeof(colors[0]));
}

GLenum getPrimitiveType() {
    return m_primitiveType;
}

void setPrimitiveType(GLenum type) {
    m_primitiveType = type;
}
