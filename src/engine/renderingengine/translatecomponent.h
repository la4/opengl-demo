#ifndef TRANSLATECOMPONENT_H
#define TRANSLATECOMPONENT_H

#include "itranslatable.h"
#include "transformcomponent.h"
#include "ipositionholder.h"

class TranslateComponent : public TransformComponent, public ITranslatable, public IPositionHolder
{
public:
    TranslateComponent();
    virtual ~TranslateComponent();

    void translate(QVector3D position) override;
    void translate(float xValue, float yValue, float zValue) override;
    void translateByX(float xValue) override;
    void translateByY(float yValue) override;
    void translateByZ(float zValue) override;

    QVector3D getPosition() override;
    void setPosition(QVector3D position) override;
    void setPosition(float x, float y, float z) override;

protected:
    QVector3D m_position;
};

#endif // TRANSLATECOMPONENT_H
