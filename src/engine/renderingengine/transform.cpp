#include "transform.h"

Transform::Transform() {

}

void rotate(QVector3D rotation) {
    m_rotation += rotation;
}

void rotate(float x, float y, float z) {
    m_rotation += QVector3D(x, y, z);
}

void scale(QVector3D scaleFactor) {
    m_scale += scaleFactor;
}

void scale(float scaleFactor) {
    m_scale += QVector3D(scaleFactor, scaleFactor, scaleFactor);
}

void scale(float x, float y, float z) {
    m_scale += QVector3D(x, y, z);
}

void move(QVector3D shift) {
    m_position += shift;
}

void move(float x, float y, float z) {
    m_position += QVector3D(x, y, z);
}

RotationValue getRotation() {
    return m_rotation;
}

void setRotation(float angle, float x, float y, float z);

void setRotation(RotationValue rotation) {
    m_rotation = rotation;
}

void setRotation(float angle, QVector3D rotVec) {
    m_rotation = RotationValue(angle, rotVec);
}

void setRotation(float x, float y, float z) {
    m_rotation = RotationValue(angle, QVector3D(x, y, z));
}

QVector3D getScale() {
    return m_scale;
}

void setScale(QVector3D scaleFactor) {
    m_scale = scaleFactor;
}

void setScale(float scaleFactor) {
    m_scale = QVector3D(scaleFactor, scaleFactor, scaleFactor);
}

void setScale(float x, float y, float z) {
    m_scale = QVector3D(x, y, z);
}

QVector3D getPosition() {
    return m_position;
}

void setPosition(QVector3D position) {
    m_position = position;
}

void setPosition(float x, float y, float z) {
    m_position = QVector3D(x, y, z);
}

QMatrix4x4 getTransformation() {
    QMatrix4x4 transformation;
    transformation.translate(m_position);
    transformation.rotate(m_rotation.angle, m_rotation.rotVec);
    transformation.scale(m_scale);

    return transformation;
}
