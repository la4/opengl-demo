#ifndef ITSROBJECT_H
#define ITSROBJECT_H

#include <QQuaternion>
#include <QVector>

struct ITSRObject {
    // Rotation
    virtual void setEulerRotationInDegrees(int aroundX, int aroundY, int aroundZ) = 0;
    virtual void setEulerRotationInRadians(float aroundX, float aroundY, float aroundZ) = 0;
    virtual void setQuaternionRotation(QQuaternion quat) = 0;

    // Scale
    virtual void setScale(float scaleFactor) = 0;
    virtual void setScale(float xAxisScaleFactor, float yAxisScaleFactor, float zAxisScaleFactor) = 0;

    // Translate
    virtual void setTranslate(QVector3D byVector) = 0;
    virtual void setTranslate(float byX, float byY, float byZ) = 0;

    // Position / Pivot point
    virtual QVector3D pivotPoint() = 0;
    virtual QVector3D position() = 0;

};

#endif // ITSROBJECT_H
