#include "openglwindow.h"

#include <QtCore/QCoreApplication>
#include <QtGui/QOpenGLContext>

OpenGLWindow::OpenGLWindow(QWindow *parent)
    : QWindow(parent)
    , needsInitialize(true)
    , m_context(NULL)
{
    setSurfaceType(QWindow::OpenGLSurface);

    m_gameEngine = new Engine();
}

void OpenGLWindow::initializeWindow()
{
    m_context = new QOpenGLContext(this);
    m_context->setFormat(requestedFormat());
    m_context->create();

    m_context->makeCurrent(this);

    initializeOpenGLFunctions();

    m_gameEngine->setContext(m_context);
    m_gameEngine->setSurface(this);
    m_gameEngine->initialize(width(), height(), devicePixelRatio(), screen()->refreshRate());

    if (isExposed())
        m_gameEngine->setStatus(ACTIVE);
    else
        m_gameEngine->setStatus(SUSPENDED);
}

void OpenGLWindow::exposeEvent(QExposeEvent *event)
{
    Q_UNUSED(event);

    if (isExposed()) {
        m_gameEngine->setStatus(ACTIVE);
        if (needsInitialize) {
            initializeWindow();
            needsInitialize = false;
        }
    }
    else {
        m_gameEngine->setStatus(SUSPENDED);
    }
}

void keyPressEvent(QKeyEvent *event)
{
    m_gameEngine->
}

void keyReleaseEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;


