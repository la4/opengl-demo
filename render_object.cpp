#include "render_object.h"

RenderObject::RenderObject(std::vector<GLfloat> vertices, std::vector<GLfloat> colors)
{
    this->vertices = std::vector<GLfloat>(vertices);
    this->colors = std::vector<GLfloat>(colors);
}

void RenderObject::render()
{

}

void RenderObject::initialize()
{

}
