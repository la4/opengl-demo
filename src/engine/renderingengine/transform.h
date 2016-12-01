#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <QMatrix4x4>

class RotationValue
{
public:
    RotationValue(float angle, QVector3D rotVec) {
        this->rotVec = rotVec;
        this->angle = angle;
    }

    QVector3D rotVec;
    float angle;
};

class Transform
{
public:
    Transform();

    void rotate(QVector3D rotation);
    void rotate(float x, float y, float z);

    void scale(QVector3D scaleFactor);
    void scale(float scaleFactor);
    void scale(float x, float y, float z);

    void move(QVector3D shift);
    void move(float x, float y, float z);

    RotationValue getRotation();
    void setRotation(RotationValue rotation);
    void setRotation(float angle, QVector3D rotVec);
    void setRotation(float angle, float x, float y, float z);

    QVector3D getScale();
    void setScale(QVector3D scaleFactor);
    void setScale(float scaleFactor);
    void setScale(float x, float y, float z);

    QVector3D getPosition();
    void setPosition(QVector3D position);
    void setPosition(float x, float y, float z);

    // TODO: add quaternions and pivot point

    QMatrix4x4 getTransformation();

private:
    QVector3D m_position;
    RotationValue m_rotation;
    QVector3D m_scale;
};

#endif // TRANSFORM_H
