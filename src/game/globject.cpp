#include "globject.h"

GLObject::GLObject(std::vector<float> vertices,
                   std::vector<GLubyte> indices,
                   std::vector<float> colors,
                   GLenum primitiveType, Transform *transform) : GameObject(transform) {
    this->m_mesh = new Mesh(vertices, indices, colors, primitiveType);
    this->m_transform = transform;
}

GLObject::GLObject(Mesh *mesh, Transform *transform): GameObject(transform) {
    this->m_mesh = mesh;
    this->m_transform = transform;
}

Mesh *GLObject::getMesh() {
    return m_mesh;
}

GLObject::~GLObject() {
    delete m_mesh;
}
