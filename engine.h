#ifndef ENGINE_H
#define ENGINE_H

#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/qsurface.h>

#include "irenderingengine.h"
#include "iinputhandler.h"
#include  "iprimitiverenderobject.h"

enum engineStatus {
    ACTIVE,
    SUSPENDED
};

class Engine : public IRenderingEngine, public IInputHandler, public QObject {
public:
    Engine();

    void setStatus(engineStatus newStatus);
    void setContext(QOpenGLContext *context);
    void setSurface(QSurface *surface);

    void initialize( const RenderSettingsInitializations& settings ) Q_DECL_OVERRIDE;
    void render() Q_DECL_OVERRIDE;

    // TODO: think about setAnimating presense
    void updateAnimation(int timeStep) Q_DECL_OVERRIDE;
    void setAnimating(bool animating) Q_DECL_OVERRIDE;

    void renderLater();
    void renderNow();

    void onKeyPress(QKeyEvent *event) Q_DECL_OVERRIDE;
    void onKeyRelease(QKeyEvent *event) Q_DECL_OVERRIDE;
    void onMousePress(QMouseEvent *event) Q_DECL_OVERRIDE;
    void onMouseRelease(QMouseEvent *event) Q_DECL_OVERRIDE;
    void onMouseMove(QMouseEvent *event) Q_DECL_OVERRIDE;
    void onWheelInteraction(QWheelEvent *event) Q_DECL_OVERRIDE;

private:
    bool event(QEvent *event) Q_DECL_OVERRIDE;

    engineStatus m_status;

    QOpenGLContext *m_context;
    QSurface *m_surface;

    int m_renderingWidth;
    int m_renderingHeight;
    qreal m_refreshRate;
    qreal m_devicePixelRatio;

    GLuint m_posAttr;
    GLuint m_colAttr;
    GLuint m_matrixUniform;

    QOpenGLShaderProgram *m_program;
    int m_frame;

    // Render objects
    std::vector<IPrimitiveRenderObject*> m_renderingObjects;
};

#endif // ENGINE_H
