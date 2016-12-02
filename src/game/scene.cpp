#include "scene.h"

Scene::Scene() {
    m_gameObjects = new std::list<GLObject *>();
}

Scene::~Scene() {
    for (auto it : *m_gameObjects) {
        delete it;
    }

    delete m_gameObjects;
}

void Scene::addObject(GLObject *object) {
    m_gameObjects->push_back(object);
}

void Scene::removeObject(GLObject *object) {
    for (auto it = m_gameObjects->begin(); it != m_gameObjects->end(); ++it) {
        if (object == *it) {
            it = m_gameObjects->erase(it);
        }
    }
}

const ObjectsContainer *Scene::getObjectsContainer() {
    return m_gameObjects;
}
