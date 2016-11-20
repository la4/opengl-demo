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

    RenderSettingsInitializations engineSettings;
    engineSettings.setDevicePixelRatio(devicePixelRatio());
    engineSettings.setWidth(width());
    engineSettings.setHeight(height());
    engineSettings.setRefreshRate(screen()->refreshRate());
    m_gameEngine->initialize(engineSettings);

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

void OpenGLWindow::keyPressEvent(QKeyEvent *event) {
    m_gameEngine->onKeyPress(event);
}
void OpenGLWindow::keyReleaseEvent(QKeyEvent *event) {
    m_gameEngine->onKeyRelease(event);
}
void OpenGLWindow::mousePressEvent(QMouseEvent *event) {
    m_gameEngine->onMousePress(event);
}
void OpenGLWindow::mouseReleaseEvent(QMouseEvent *event) {
    m_gameEngine->onMouseRelease(event);
}
void OpenGLWindow::mouseMoveEvent(QMouseEvent *event) {
    m_gameEngine->onMouseMove(event);
}
void OpenGLWindow::wheelEvent(QWheelEvent *event) {
    m_gameEngine->onWheelInteraction(event);
}

