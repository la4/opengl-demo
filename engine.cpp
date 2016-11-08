#include "engine.h"

#include <QtCore/QCoreApplication>
#include <QtGui/QGuiApplication>
#include <QtGui/QMatrix4x4>

#include <QtCore/qmath.h>
#include <QDir>
#include <QTime>

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <vector>

Engine::Engine()
    : m_context(NULL)
    , m_surface(NULL)
    , m_program(NULL)
    , m_frame(0)
{}

void Engine::initialize(int width, int height, qreal devicePixelRatio, qreal refreshRate)
{
    m_renderingWidth = width;
    m_renderingHeight = height;
    m_devicePixelRatio = devicePixelRatio;
    m_refreshRate = refreshRate;

    srand(time(NULL));
    QString vertexShaderPath = QDir(qApp->applicationDirPath()).absoluteFilePath("shaders/vertex_shader.vert");
    QString fragmentShaderPath = QDir(qApp->applicationDirPath()).absoluteFilePath("shaders/fragment_shader.frag");

    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, vertexShaderPath);
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, fragmentShaderPath);
    m_program->link();
    m_posAttr = m_program->attributeLocation("posAttr");
    m_colAttr = m_program->attributeLocation("colAttr");
    m_matrixUniform = m_program->uniformLocation("matrix");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    QCoreApplication::postEvent(this, new QEvent(QEvent::UpdateRequest)); // Starting point for rendering loop
}

void Engine::setStatus(engineStatus newStatus)
{
    m_status = newStatus;
}

void Engine::setContext(QOpenGLContext *context)
{
    m_context = context;
}

void Engine::setSurface(QSurface *surface)
{
    m_surface = surface;
}

bool Engine::event(QEvent *event)
{
    switch (event->type()) {
    case QEvent::UpdateRequest:
        renderNow();
        return true;
    default:
        return QObject::event(event);
    }
}


void Engine::renderLater()
{
    QCoreApplication::postEvent(this, new QEvent(QEvent::UpdateRequest));
}

void Engine::renderNow()
{
    if (m_status != ACTIVE)
        return;

    render();

    m_context->swapBuffers(m_surface);

    renderLater();
}

void Engine::render()
{
    const qreal retinaScale = m_devicePixelRatio;
    glViewport(0, 0, m_renderingWidth * retinaScale, m_renderingHeight * retinaScale);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /*const GLfloat color[] = {
        (float)((float)sin(QTime::currentTime().msecsSinceStartOfDay() / 100) * 0.5 + 0.5),
        (float)((float)cos(QTime::currentTime().msecsSinceStartOfDay() / 100) * 0.5 + 0.5),
        0.0, 1.0
    };

    std::cout << sin(QTime::currentTime().second()) * 0.5 + 0.5  << "\n";
    glClearColor(color[0], color[1], color[2], color[3]);
    glClear(GL_COLOR_BUFFER_BIT); */


    m_program->bind();

    QMatrix4x4 matrix;

    matrix.perspective(60.0f, 4.0f/3.0f, 0.1f, 100.0f);
    matrix.translate(0, -2, -3 - std::abs(50.0f * sin(m_frame / m_refreshRate)));
    matrix.rotate(100.0f * m_frame / m_refreshRate, 1, 0, 0);

    m_program->setUniformValue(m_matrixUniform, matrix);

    GLfloat vertices[] = { -1.0f,-1.0f,-1.0f,
                           -1.0f,-1.0f, 1.0f,
                           -1.0f, 1.0f, 1.0f,
                           1.0f, 1.0f,-1.0f,
                           -1.0f,-1.0f,-1.0f,
                           -1.0f, 1.0f,-1.0f,
                           1.0f,-1.0f, 1.0f,
                           -1.0f,-1.0f,-1.0f,
                           1.0f,-1.0f,-1.0f,
                           1.0f, 1.0f,-1.0f,
                           1.0f,-1.0f,-1.0f,
                           -1.0f,-1.0f,-1.0f,
                           -1.0f,-1.0f,-1.0f,
                           -1.0f, 1.0f, 1.0f,
                           -1.0f, 1.0f,-1.0f,
                           1.0f,-1.0f, 1.0f,
                           -1.0f,-1.0f, 1.0f,
                           -1.0f,-1.0f,-1.0f,
                           -1.0f, 1.0f, 1.0f,
                           -1.0f,-1.0f, 1.0f,
                           1.0f,-1.0f, 1.0f,
                           1.0f, 1.0f, 1.0f,
                           1.0f,-1.0f,-1.0f,
                           1.0f, 1.0f,-1.0f,
                           1.0f,-1.0f,-1.0f,
                           1.0f, 1.0f, 1.0f,
                           1.0f,-1.0f, 1.0f,
                           1.0f, 1.0f, 1.0f,
                           1.0f, 1.0f,-1.0f,
                           -1.0f, 1.0f,-1.0f,
                           1.0f, 1.0f, 1.0f,
                           -1.0f, 1.0f,-1.0f,
                           -1.0f, 1.0f, 1.0f,
                           1.0f, 1.0f, 1.0f,
                           -1.0f, 1.0f, 1.0f,
                           1.0f,-1.0f, 1.0f };

    GLfloat colors[] = { 0.583f,  0.771f,  0.014f,
                         0.609f,  0.115f,  0.436f,
                         0.327f,  0.483f,  0.844f,
                         0.822f,  0.569f,  0.201f,
                         0.435f,  0.602f,  0.223f,
                         0.310f,  0.747f,  0.185f,
                         0.597f,  0.770f,  0.761f,
                         0.559f,  0.436f,  0.730f,
                         0.359f,  0.583f,  0.152f,
                         0.483f,  0.596f,  0.789f,
                         0.559f,  0.861f,  0.639f,
                         0.195f,  0.548f,  0.859f,
                         0.014f,  0.184f,  0.576f,
                         0.771f,  0.328f,  0.970f,
                         0.406f,  0.615f,  0.116f,
                         0.676f,  0.977f,  0.133f,
                         0.971f,  0.572f,  0.833f,
                         0.140f,  0.616f,  0.489f,
                         0.997f,  0.513f,  0.064f,
                         0.945f,  0.719f,  0.592f,
                         0.543f,  0.021f,  0.978f,
                         0.279f,  0.317f,  0.505f,
                         0.167f,  0.620f,  0.077f,
                         0.347f,  0.857f,  0.137f,
                         0.055f,  0.953f,  0.042f,
                         0.714f,  0.505f,  0.345f,
                         0.783f,  0.290f,  0.734f,
                         0.722f,  0.645f,  0.174f,
                         0.302f,  0.455f,  0.848f,
                         0.225f,  0.587f,  0.040f,
                         0.517f,  0.713f,  0.338f,
                         0.053f,  0.959f,  0.120f,
                         0.393f,  0.621f,  0.362f,
                         0.673f,  0.211f,  0.457f,
                         0.820f,  0.883f,  0.371f,
                         0.982f,  0.099f,  0.879f };

    glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glDrawArrays(GL_TRIANGLES, 0, 12 * 3);

    QMatrix4x4 matrix2;

    matrix2.perspective(60.0f, 4.0f/3.0f, 0.1f, 100.0f);
    matrix2.translate(0, 2, -3 - std::abs(50.0f * cos(m_frame / m_refreshRate)));
    matrix2.rotate(100.0f * m_frame / m_refreshRate, 1, 0, 0);

    m_program->setUniformValue(m_matrixUniform, matrix2);

    glDrawArrays(GL_TRIANGLES, 0, 12 * 3);

    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);

    m_program->release();

    ++m_frame;
}

void Engine::updateAnimation(int timeStep)
{
    Q_UNUSED(timeStep)
}

void Engine::setAnimating(bool animating)
{
    Q_UNUSED(animating)
}

void Engine::keyPressEvent(QKeyEvent *event)
{
    Q_UNUSED(event)
    // Currently not processing this event
}

void Engine::keyReleaseEvent(QKeyEvent *event)
{
    Q_UNUSED(event)
    // Currently not processing this event
}

void Engine::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    // Currently not processing this event
}

void Engine::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    // Currently not processing this event
}

void Engine::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    // Currently not processing this event
}

void Engine::wheelEvent(QWheelEvent *event)
{
    Q_UNUSED(event)
    // Currently not processing this event
}
