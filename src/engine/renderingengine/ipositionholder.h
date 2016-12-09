#ifndef IPOSITIONHOLDER_H
#define IPOSITIONHOLDER_H

#include <QVector3D>

struct IPositionHolder {
    virtual QVector3D getPosition() = 0;
    virtual void setPosition(QVector3D position) = 0;
    virtual void setPosition(float x, float y, float z) = 0;
    virtual ~IPositionHolder() {}

    static QVector3D defaultPosition() {
        return QVector3D(0.0, 0.0, 0.0);
    }
};

#endif // IPOSITIONHOLDER_H
