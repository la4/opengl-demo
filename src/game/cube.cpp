#include "cube.h"
#include "transform.h"
#include "mesh.h"

//TODO: make all dependencies outside class
Cube::Cube(Transform *transform, Mesh *mesh) : GameObject(transform, mesh)
{
}

