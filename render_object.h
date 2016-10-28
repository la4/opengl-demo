#ifndef CUSTOMCUBE_H
#define CUSTOMCUBE_H

#include <QtGui/QOpenGLShaderProgram>

class RenderObject
{
public:
    RenderObject(std::vector<GLfloat> vertices, std::vector<GLfloat> colors);

    virtual void render();
    virtual void initialize();

private:
    std::vector<GLfloat> vertices;
    std::vector<GLfloat> colors;
};

#endif // CUSTOMCUBE_H
