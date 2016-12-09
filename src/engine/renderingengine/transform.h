#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "translatecomponent.h"
#include <QMatrix4x4>

// Awful >.<
// You have to figure out what transformation at all
// I don't like the idea of aggregation, in all cases better to use abstract classes/interfaces
// In my case I have to implement own implementation of rotation, also i don't need scale
// In my opinion, there is better to use something like ITranslatable/IRotetable/IScallable
class RotationValue
{
public:
    RotationValue() {
        angle = 0.0f;
        rotVec = QVector3D(0.0, 0.0, 0.0);
    }

    RotationValue(float angle, QVector3D rotVec) {
        this->rotVec = rotVec;
        this->angle = angle;
    }

    QVector3D rotVec;
    float angle;
};

//TODO: expand Transform: make a bunch of constructors, setters, getter, etc.
// Bad idea at all, unreasoned implementaion >.<
class Transform : public TranslateComponent
{
public:
    Transform();

    void rotate(float angle, QVector3D rotation);
    void rotate(float angle, float x, float y, float z);

    //void scale(QVector3D scaleFactor);
    void scale(float scaleFactor);
    void scale(float x, float y, float z);

    RotationValue getRotation();
    void setRotation(RotationValue rotation);
    void setRotation(float angle, QVector3D rotVec);
    void setRotation(float angle, float x, float y, float z);

    QVector3D getScale();
    void setScale(QVector3D scaleFactor);
    void setScale(float scaleFactor);
    void setScale(float x, float y, float z);

    // TODO: add quaternions and pivot point

    QMatrix4x4 getTransformation();

private:
    RotationValue m_rotation; // OMG >.<
    QVector3D m_scale;
};

#endif // TRANSFORM_H
