#ifndef OPENGL_WINDOW_H
#define OPENGL_WINDOW_H

#include <QtGui/QWindow>
#include <QtGui/QOpenGLFunctions>
#include <QScreen>
#include "coreengine.h"

QT_BEGIN_NAMESPACE
class QOpenGLContext;
QT_END_NAMESPACE

class GameWindow : public QWindow, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit GameWindow(QWindow *parent = 0);

    void initialize();
    void connectEngine(CoreEngine *engine);

protected:
    void exposeEvent(QExposeEvent *event) Q_DECL_OVERRIDE;

    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void keyReleaseEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;

private:
    bool m_needsInitialize;

    CoreEngine *m_coreEngine;
    QOpenGLContext *m_context;
};

#endif // OPENGL_WINDOW_H