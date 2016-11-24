#ifndef RENDERINGENGINE_H
#define RENDERINGENGINE_H

#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/qsurface.h>

#include "iprimitiverenderobject.h"
#include "rendersettingsinitializations.h"

// QObject inheritance needed for QOpenGLShaderProgram parent
class RenderingEngine : public QObject
{
public:
    RenderingEngine();

    void initialize(const RenderSettingsInitializations& renderSettings);

    void render();

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

    QOpenGLShaderProgram *m_program;
    int m_frame;

    // Render objects
    std::vector<IPrimitiveRenderObject*> m_renderingObjects;
};

#endif // RENDERINGENGINE_H
