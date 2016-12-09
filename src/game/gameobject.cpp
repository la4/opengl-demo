#include "gameobject.h"
#include "mesh.h"
#include "transform.h"

GameObject::GameObject(Transform *transform, Mesh *mesh) {
    m_transform = transform;
    m_mesh = mesh;
}

GameObject::~GameObject() {
    delete m_transform;
    delete m_mesh;
}

//You may override these methods
Mesh *GameObject::getMesh() {
    return m_mesh;
}
Transform *GameObject::getTransform() {
    return m_transform;
}


