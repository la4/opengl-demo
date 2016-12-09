#ifndef CUBE_H
#define CUBE_H

#include "gameobject.h"

class Cube : public GameObject
{
public:
    Cube(Transform *transform, Mesh *mesh);
};

#endif // CUBE_H
