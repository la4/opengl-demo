#ifndef ENGINE_H
#define ENGINE_H

#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/qsurface.h>

#include "iinputhandler.h"
#include "renderingengine.h"
#include "physicsengine.h"

enum engineStatus { // TODO: Do we need this?
    ACTIVE,
    SUSPENDED
};

// QObject inheritance needed for QOpenGLShaderProgram parent
class CoreEngine : public IInputHandler, public QObject {
public:
    CoreEngine();

    void initialize(const RenderSettingsInitializations& renderSettings);

    void setStatus(engineStatus newStatus);

    void passContextToRenderingEngine(QOpenGLContext *context);
    void passSurfaceToRenderingEngine(QSurface *surface);

    void onKeyPress(QKeyEvent *event) Q_DECL_OVERRIDE;
    void onKeyRelease(QKeyEvent *event) Q_DECL_OVERRIDE;
    void onMousePress(QMouseEvent *event) Q_DECL_OVERRIDE;
    void onMouseRelease(QMouseEvent *event) Q_DECL_OVERRIDE;
    void onMouseMove(QMouseEvent *event) Q_DECL_OVERRIDE;
    void onWheelInteraction(QWheelEvent *event) Q_DECL_OVERRIDE;

private:
    bool event(QEvent *event) Q_DECL_OVERRIDE;
    void postLoopEvent();
    void gameLoopCycle();

    engineStatus m_status;

    RenderingEngine *m_renderingEngine;
    PhysicsEngine *m_physicsEngine; // Currently it's a placeholder
};

#endif // ENGINE_H
