#include "gamewindow.h"

#include <QtCore/QCoreApplication>
#include <QtGui/QOpenGLContext>

GameWindow::GameWindow(QWindow *parent)
    : QWindow(parent)
    , m_needsInitialize(true)
    , m_context(NULL) {
    setSurfaceType(QWindow::OpenGLSurface);
}

/* Triggered when window first opened and on following exposures.
 * Initializing only on first exposure. */
void GameWindow::exposeEvent(QExposeEvent *event) {
    Q_UNUSED(event);

    if (isExposed()) {
        m_coreEngine->setStatus(ACTIVE);
        if (m_needsInitialize) {
            initialize();
            m_needsInitialize = false;
        }
    }
    else {
        m_coreEngine->setStatus(SUSPENDED);
    }
}

void GameWindow::initialize() {
    m_context = new QOpenGLContext(this);
    m_context->setFormat(requestedFormat());
    m_context->create();

    // Making context current against our surface (this window)
    m_context->makeCurrent(this);

    initializeOpenGLFunctions();

    /* TODO: surround with try catch, create a "missing rendering engine" exception,
     * throw in CoreEngine setter.*/
    m_coreEngine->passContextToRenderingEngine(m_context);
    m_coreEngine->passSurfaceToRenderingEngine(this);

    RenderSettingsInitializations engineSettings;
    engineSettings.setDevicePixelRatio(devicePixelRatio());
    engineSettings.setWidth(width());
    engineSettings.setHeight(height());
    engineSettings.setRefreshRate(screen()->refreshRate());

    m_coreEngine->initialize(engineSettings);

    if (isExposed())
        m_coreEngine->setStatus(ACTIVE);
    else
        m_coreEngine->setStatus(SUSPENDED);
}

void GameWindow::connectEngine(CoreEngine *engine) {
    // TODO: error handling
    m_coreEngine = engine;
}

#pragma mark - QWindow // Passing QWindow events to engine
void GameWindow::keyPressEvent(QKeyEvent *event) {
    m_coreEngine->onKeyPress(event);
}

void GameWindow::keyReleaseEvent(QKeyEvent *event) {
    m_coreEngine->onKeyRelease(event);
}

void GameWindow::mousePressEvent(QMouseEvent *event) {
    m_coreEngine->onMousePress(event);
}

void GameWindow::mouseReleaseEvent(QMouseEvent *event) {
    m_coreEngine->onMouseRelease(event);
}

void GameWindow::mouseMoveEvent(QMouseEvent *event) {
    m_coreEngine->onMouseMove(event);
}

void GameWindow::wheelEvent(QWheelEvent *event) {
    m_coreEngine->onWheelInteraction(event);
}
