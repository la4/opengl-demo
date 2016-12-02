#include "gameobject.h"

GameObject::GameObject(Transform *transform) {
    m_transform = transform;
}

GameObject::~GameObject() {
    delete m_transform;
}

Transform *GameObject::getTransform() {
    return m_transform;
}


