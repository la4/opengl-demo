#include "translatecomponent.h"

TranslateComponent::TranslateComponent() : TransformComponent() {
    this->m_position = IPositionHolder::defaultPosition();
}

TranslateComponent::~TranslateComponent() {

}

void TranslateComponent::translate(QVector3D position) {
    m_position += position;
}

void TranslateComponent::translate(float xValue, float yValue, float zValue) {
    m_position += QVector3D(xValue, yValue, zValue);
}

void TranslateComponent::translateByX(float xValue) {
    m_position = QVector3D(m_position.x() + xValue, m_position.y(), m_position.z());
}

void TranslateComponent::translateByY(float yValue) {
    m_position = QVector3D(m_position.x(), m_position.y() + yValue, m_position.z());
}

void TranslateComponent::translateByZ(float zValue) {
    m_position = QVector3D(m_position.x(), m_position.y(), m_position.z() + zValue);
}

QVector3D TranslateComponent::getPosition() {
    return m_position;
}

void TranslateComponent::setPosition(QVector3D position) {
    m_position = position;
}

void TranslateComponent::setPosition(float x, float y, float z) {
    m_position = QVector3D(x, y, z);
}
