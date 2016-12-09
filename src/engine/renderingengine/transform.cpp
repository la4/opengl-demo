#include "transform.h"

Transform::Transform() {
    m_scale = QVector3D(1.0, 1.0, 1.0);
    m_position = QVector3D(0.0, 0.0, 0.0);
}

void Transform::rotate(float angle, QVector3D rotation) {
    // Override += for RotationValue or find a built in class for this
}

void Transform::rotate(float angle, float x, float y, float z) {
    // Override += for RotationValue or find a built in class for this
}

/*void Transform::scale(QVector3D scaleFactor) {
    m_scale += scaleFactor;
}*/

void Transform::scale(float scaleFactor) {
    m_scale += QVector3D(scaleFactor, scaleFactor, scaleFactor);
}

void Transform::scale(float x, float y, float z) {
    m_scale += QVector3D(x, y, z);
}

RotationValue Transform::getRotation() {
    return m_rotation;
}

void Transform::setRotation(RotationValue rotation) {
    m_rotation = rotation;
}

void Transform::setRotation(float angle, QVector3D rotVec) {
    m_rotation = RotationValue(angle, rotVec);
}

void Transform::setRotation(float angle, float x, float y, float z) {
    m_rotation = RotationValue(angle, QVector3D(x, y, z));
}

QVector3D Transform::getScale() {
    return m_scale;
}

void Transform::setScale(QVector3D scaleFactor) {
    m_scale = scaleFactor;
}

void Transform::setScale(float scaleFactor) {
    m_scale = QVector3D(scaleFactor, scaleFactor, scaleFactor);
}

void Transform::setScale(float x, float y, float z) {
    m_scale = QVector3D(x, y, z);
}

QMatrix4x4 Transform::getTransformation() {
    QMatrix4x4 transformation;

    transformation.translate(m_position);
    transformation.rotate(m_rotation.angle, m_rotation.rotVec);
    transformation.scale(m_scale);

    return transformation;
}
