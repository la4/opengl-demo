#ifndef CUBE_H
#define CUBE_H

#include "iprimitiverenderobject.h"
#include "itsrobject.h"
#include "gl.h"
#include <vector>

class Cube : public IPrimitiveRenderObject, public ITSRObject
{
public:
    Cube(std::vector<float> vertices,
               std::vector<GLubyte> indices,
               std::vector<float> colors,
               GLenum primitiveType);

#pragma mark - IPrimitiveRenderObject
    const virtual float* vertices() const override;
    const virtual GLubyte* indices() const override;
    const virtual float* colors() const override;

    virtual GLubyte indicesCount() const override;
    virtual GLubyte verticesCount() const override;

    virtual GLenum primitiveType() const override;


#pragma mark - ITSRObject
    virtual void setEulerRotationInDegrees(int aroundX, int aroundY, int aroundZ) override;
    virtual void setEulerRotationInRadians(float aroundX, float aroundY, float aroundZ) override;
    virtual void setQuaternionRotation(QQuaternion quat) override;

    virtual void setScale(float scaleFactor) override;
    virtual void setScale(float xAxisScaleFactor, float yAxisScaleFactor, float zAxisScaleFactor) override;

    virtual void setTranslate(QVector3D byVector) override;
    virtual void setTranslate(float byX, float byY, float byZ) override;

    virtual QVector3D pivotPoint() override;
    virtual QVector3D position() override;

 protected:
    std::vector<float> m_vertices;
    std::vector<GLubyte> m_indices;
    std::vector<float> m_colors;
    GLenum m_primitiveType;

    QVector3D m_inWorldPos;
    QVector3D m_pivotPoint;
};

#endif // CUBE_H
