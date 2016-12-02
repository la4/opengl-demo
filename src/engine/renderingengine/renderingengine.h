#ifndef RENDERINGENGINE_H
#define RENDERINGENGINE_H

#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/qsurface.h>

#include "gameobject.h"
#include "rendersettingsinitializations.h"
#include "scene.h"

// QObject inheritance needed for QOpenGLShaderProgram parent
class RenderingEngine : public QObject
{
public:
    RenderingEngine();

    void initialize(const RenderSettingsInitializations& renderSettings);

    void render();

    void setScene(Scene *scene);
    void setContext(QOpenGLContext *context);
    void setSurface(QSurface *surface);

private:
    QOpenGLContext *m_context;
    QSurface *m_surface;

    int m_renderingWidth;
    int m_renderingHeight;
    qreal m_refreshRate;
    qreal m_devicePixelRatio;

    GLuint m_posAttr;
    GLuint m_colAttr;
    GLuint m_matrixUniform;

    QMatrix4x4 perspectiveMat;

    QOpenGLShaderProgram *m_program;
    int m_frame;

    Scene *m_scene;
};

#endif // RENDERINGENGINE_H
