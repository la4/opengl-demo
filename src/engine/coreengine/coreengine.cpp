#include "coreengine.h"

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

CoreEngine::CoreEngine() {
    m_renderingEngine = new RenderingEngine();
    m_physicsEngine = new PhysicsEngine();
}

void CoreEngine::initialize(const RenderSettingsInitializations& renderSettings) {
    m_renderingEngine->initialize(renderSettings);
    //m_physicsEngine->initialize();

    QCoreApplication::postEvent(this, new QEvent(QEvent::UpdateRequest)); // Starting point for rendering loop
}

/********************************************************************
 *                            GAME LOOP                             *
 ********************************************************************/

bool CoreEngine::event(QEvent *event) {
    switch (event->type()) {
    case QEvent::UpdateRequest:
        gameLoopCycle();
        return true;
    default:
        return QObject::event(event);
    }
}

void CoreEngine::postLoopEvent() {
    QCoreApplication::postEvent(this, new QEvent(QEvent::UpdateRequest));
}

void CoreEngine::gameLoopCycle() {
    // TODO: add proper game loop with frame skipping and vsync
    if (m_status != ACTIVE)
        return;

    m_renderingEngine->render();

    postLoopEvent();
}

/********************************************************************
 *                                END                               *
 ********************************************************************/

void CoreEngine::setStatus(engineStatus newStatus) {
    m_status = newStatus;
}

void CoreEngine::setScene(Scene *scene) {
    m_scene = scene;
    m_renderingEngine->setScene(scene);
}

void CoreEngine::passContextToRenderingEngine(QOpenGLContext *context) {
    m_renderingEngine->setContext(context);
}

void CoreEngine::passSurfaceToRenderingEngine(QSurface *surface) {
    m_renderingEngine->setSurface(surface);
}

// TODO: input handling should be probably delegated to PhysicsEngine as being related to modifying game logic
#pragma mark - IInputHandler // IInputHandler events
void CoreEngine::onKeyPress( QKeyEvent *event ) {
    //Q_UNUSED(event)
    // Currently not processing this event

    //Made for testing ONLY
    switch (event->key()) {
    case Qt::Key_W:
        this->m_renderingEngine->getScene()->getCameraSet().at(0)->getTransform()->translateByZ(-0.25);
        break;
    case Qt::Key_S:
        this->m_renderingEngine->getScene()->getCameraSet().at(0)->getTransform()->translateByZ(0.25);
        break;
    case Qt::Key_A:
        this->m_renderingEngine->getScene()->getCameraSet().at(0)->getTransform()->translateByX(-0.25);
        break;
    case Qt::Key_D:
        this->m_renderingEngine->getScene()->getCameraSet().at(0)->getTransform()->translateByX(0.25);
        break;

    default:
        break;
    }

}

void CoreEngine::onKeyRelease( QKeyEvent *event ) {
    Q_UNUSED(event)
    // Currently not processing this event
}

void CoreEngine::onMousePress( QMouseEvent *event ) {
    Q_UNUSED(event)
    // Currently not processing this event
}

void CoreEngine::onMouseRelease( QMouseEvent *event ) {
    Q_UNUSED(event)
    // Currently not processing this event
}

void CoreEngine::onMouseMove( QMouseEvent *event ) {
    Q_UNUSED(event)

    // Currently not processing this event
}

void CoreEngine::onWheelInteraction( QWheelEvent *event ) {
    Q_UNUSED(event)
    // Currently not processing this event
}
