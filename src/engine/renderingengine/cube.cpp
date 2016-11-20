#include "cube.h"

Cube::Cube(std::vector<float> vertices,
           std::vector<GLubyte> indices,
           std::vector<float> colors,
           GLenum primitiveType) {
    this->m_vertices = vertices;
    this->m_indices = indices;
    this->m_colors = colors;
    this->m_primitiveType = primitiveType;
}

const float* Cube::vertices() const {
    const float* returnValue = this->m_vertices.data();
    return returnValue;
}

const GLubyte* Cube::indices() const {
    const GLubyte* returnValue = this->m_indices.data();
    return returnValue;
}

const float* Cube::colors() const {
    const float* returnValue = this->m_colors.data();
    return returnValue;
}

GLubyte Cube::indicesCount() const {
    auto returnValue = this->m_indices.size();
    return static_cast<GLubyte>(returnValue);
}
GLubyte Cube::verticesCount() const {
    auto returnValue = this->m_vertices.size();
    return static_cast<GLubyte>(returnValue);
}

GLenum Cube::primitiveType() const {
    return m_primitiveType;
}


#pragma mark - ITSRObject
void Cube::setEulerRotationInDegrees(int aroundX, int aroundY, int aroundZ) {
    Q_UNUSED(aroundX)
    Q_UNUSED(aroundY)
    Q_UNUSED(aroundZ)
}
void Cube::setEulerRotationInRadians(float aroundX, float aroundY, float aroundZ) {
    Q_UNUSED(aroundX)
    Q_UNUSED(aroundY)
    Q_UNUSED(aroundZ)
}

void Cube::setQuaternionRotation(QQuaternion quat) {
    Q_UNUSED(quat)
}


void Cube::setScale(float scaleFactor) {
    Q_UNUSED(scaleFactor)
}
void Cube::setScale(float xAxisScaleFactor, float yAxisScaleFactor, float zAxisScaleFactor) {
    Q_UNUSED(xAxisScaleFactor)
    Q_UNUSED(yAxisScaleFactor)
    Q_UNUSED(zAxisScaleFactor)
}


void Cube::setTranslate(QVector3D byVector) {
    Q_UNUSED(byVector)
}
void Cube::setTranslate(float byX, float byY, float byZ) {
    Q_UNUSED(byX)
    Q_UNUSED(byY)
    Q_UNUSED(byZ)
}


QVector3D Cube::pivotPoint() {
    return m_pivotPoint;
}
QVector3D Cube::position() {
    return m_inWorldPos;
}
