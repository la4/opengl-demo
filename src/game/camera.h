#ifndef CAMERA_H
#define CAMERA_H

#include "gameobject.h"

//TODO: default camera method
// all dependecies outside!!!
class Camera : public GameObject
{
public:
    Camera(Transform *transform, Mesh *mesh);
    Camera(Transform *transform, Mesh *mesh, QVector3D viewDirection);

    QMatrix4x4 getViewProjection();

    QVector3D getViewDirection();
    void setViewDirection(QVector3D viewDirection);

    float getViewAngle();
    void setViewAngle(float viewAngle);

    float getAspectRatio();
    void setAspectRatio(float aspectRatio);
    void setAspectRatio(float width, float height);



    /********************* Static methods *********************/
    static QVector3D getUpVector() {
        return QVector3D(0.0, 1.0, 0.0);
    }

    static QVector3D defaultViewDirection() {
        return QVector3D(0.0, 0.0, -1.0);
    }

    static float defaultViewAngle() {
        return 60.f;
    }

    static float defaultAspectRatio() {
        return 4.f/3.f;
    }

protected:
    float m_viewAngle;
    float m_aspectRatio;
    QVector3D m_viewDirection;
};

#endif // CAMERA_H
