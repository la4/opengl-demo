#include "scene.h"
#include "gameobject.h"

Scene::Scene() {
    m_gameObjects = std::list<GameObject *>();
    m_cameraSet = CameraSet();
    m_cameraSet.push_back(new Camera(new Transform, Mesh::createEmptyMesh()));
}

Scene::~Scene() {
    for (auto it : m_gameObjects) {
        delete it;
    }
}

void Scene::addObject(GameObject *object) {
    m_gameObjects.push_back(object);
}

void Scene::removeObject(GameObject *object) {
    for (auto it = m_gameObjects.begin(); it != m_gameObjects.end(); ++it) {
        if (object == *it) {
            it = m_gameObjects.erase(it);
        }
    }
}

const ObjectsContainer Scene::getObjectsContainer() {
    return m_gameObjects;
}

const CameraSet Scene::getCameraSet() {
    return m_cameraSet;
}
