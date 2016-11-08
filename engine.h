#ifndef ENGINE_H
#define ENGINE_H

#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/qsurface.h>

#include "irenderingengine.h"
#include "iinputhandler.h"

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

    void initialize(int width, int height, qreal devicePixelRatio, qreal refreshRate) Q_DECL_OVERRIDE;
    void render() Q_DECL_OVERRIDE;

    // TODO: think about setAnimating presense
    void updateAnimation(int timeStep) Q_DECL_OVERRIDE;
    void setAnimating(bool animating) Q_DECL_OVERRIDE;

    void renderLater();
    void renderNow();

private:
    bool event(QEvent *event) Q_DECL_OVERRIDE;

    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void keyReleaseEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;

private:
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
};

#endif // ENGINE_H
