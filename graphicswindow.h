#ifndef GRAPHICSWINDOW_H
#define GRAPHICSWINDOW_H

#include "openglwindow.h"

#include <QtGui/QGuiApplication>
#include <QtGui/QMatrix4x4>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QScreen>

#include <QtCore/qmath.h>
#include <QDir>
#include <QTime>

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <vector>

class GraphicsWindow : public OpenGLWindow
{
public:
    GraphicsWindow();

    void initialize() Q_DECL_OVERRIDE;
    void render() Q_DECL_OVERRIDE;

private:
    void initObjects();

    GLuint m_posAttr;
    GLuint m_colAttr;
    GLuint m_matrixUniform;
    
    QOpenGLShaderProgram *m_program;
    int m_frame;
};
#endif // GRAPHICSWINDOW_H
