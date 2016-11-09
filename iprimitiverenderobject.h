#ifndef IPRIMITIVERENDEROBJECT_H
#define IPRIMITIVERENDEROBJECT_H

#include <gl.h>

struct IPrimitiveRenderObject{
    const virtual float* vertices() const = 0;
    const virtual GLubyte* indices() const = 0;
    const virtual float* colors() const = 0;

    virtual GLubyte verticesCount() const = 0;
    virtual GLubyte indicesCount() const = 0;

    virtual GLenum primitiveType() const = 0;

    virtual ~IPrimitiveRenderObject() {}
};

#endif // IPRIMITIVERENDEROBJECT_H
