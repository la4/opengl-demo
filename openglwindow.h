#include <QtGui/QWindow>
#include <QtGui/QOpenGLFunctions>
#include <QScreen>
#include "engine.h"

QT_BEGIN_NAMESPACE
class QOpenGLContext;
class QOpenGLPaintDevice;
QT_END_NAMESPACE

class OpenGLWindow : public QWindow, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit OpenGLWindow(QWindow *parent = 0);

    virtual void initializeWindow();

protected:
    void exposeEvent(QExposeEvent *event) Q_DECL_OVERRIDE;

    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void keyReleaseEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;

private:
    bool needsInitialize;

    Engine *m_gameEngine;
    QOpenGLContext *m_context;
};
