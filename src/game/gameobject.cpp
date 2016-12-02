#include "gameobject.h"

GameObject::GameObject() {
    m_mesh = new Mesh();
    m_transform = new Transform();
}

GameObject::GameObject(std::vector<float> vertices,
           std::vector<GLubyte> indices,
           std::vector<float> colors,
           GLenum primitiveType) {
    m_mesh = new Mesh(vertices, indices, colors, primitiveType);
    m_transform = new Transform();
}

GameObject::~GameObject() {
}

Mesh *GameObject::getMesh() {
    return m_mesh;
}

void GameObject::setMesh(Mesh *mesh) {
    m_mesh = mesh;
}

Transform *GameObject::getTransform() {
    return m_transform;
}

void GameObject::setTransform(Transform *transform) {
    m_transform = transform;
}


