#ifndef ITRANSLATABLE_H
#define ITRANSLATABLE_H

class QVector3D;

struct ITranslatable {
    virtual void translate(QVector3D position) = 0;
    virtual void translate(float xValue, float yValue, float zValue) = 0;
    virtual void translateByX(float xValue) = 0;
    virtual void translateByY(float yValue) = 0;
    virtual void translateByZ(float zValue) = 0;
    virtual ~ITranslatable() {}
};

#endif // ITRANSLATABLE_H
