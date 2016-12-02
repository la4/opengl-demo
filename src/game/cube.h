#ifndef CUBE_H
#define CUBE_H

#include "globject.h"

class Cube : public GLObject
{
public:
    Cube(Mesh *mesh, Transform *transform);
};

#endif // CUBE_H
