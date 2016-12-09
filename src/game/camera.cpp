#include "camera.h"
#include "scene.h"

/********************* Constructors *********************/
Camera::Camera(Transform *transform, Mesh *mesh) : GameObject(transform, mesh) {
    this->m_viewAngle = Camera::defaultViewAngle();
    this->m_aspectRatio = Camera::defaultAspectRatio();
    this->m_viewDirection = Camera::defaultViewDirection();
}

Camera::Camera(Transform *transform, Mesh *mesh, QVector3D viewDirection) : Camera(transform, mesh) {
    this->m_viewDirection = viewDirection;
}


/********************* Methods *********************/
QMatrix4x4 Camera::getViewProjection() {
    QMatrix4x4 projection;
    projection.perspective(this->m_viewAngle, this->m_aspectRatio, 0.1f, 1000.f); // Near/Far plane must be outside dependency

    QMatrix4x4 view;
    view.lookAt(m_transform->getPosition(), m_transform->getPosition() + m_viewDirection, Camera::getUpVector());

    return projection * view;
}

QVector3D Camera::getViewDirection() {
    return m_viewDirection;
}
void Camera::setViewDirection(QVector3D viewDirection) {
    m_viewDirection = viewDirection;
}


float Camera::getViewAngle() {
    return m_viewAngle;
}
void Camera::setViewAngle(float viewAngle) {
    m_viewAngle = viewAngle;
}


float Camera::getAspectRatio() {
    return m_aspectRatio;
}
void Camera::setAspectRatio(float aspectRatio) {
    m_aspectRatio = aspectRatio;
}
void Camera::setAspectRatio(float width, float height) {
    m_aspectRatio = width/height;
}


