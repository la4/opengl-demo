#ifndef IEVENTHANDLER_H
#define IEVENTHANDLER_H

#include <QKeyEvent>

struct IEventHanler {
    virtual void keyDistributor(QEvent *);

    virtual void keyPressEvent(QKeyEvent *) = 0;
    virtual void keyReleaseEvent(QKeyEvent *) = 0;
    virtual void mousePressEvent(QMouseEvent *) = 0;
    virtual void mouseReleaseEvent(QMouseEvent *) = 0;
    virtual void mouseMoveEvent(QMouseEvent *) = 0;
    virtual void wheelEvent(QWheelEvent *) = 0;

    virtual void windowExposeEvent(QExposeEvent *) = 0;
    virtual void windowResizeEvent(QResizeEvent *) = 0;
    virtual void windowMoveEvent(QMoveEvent *) = 0;
    virtual void windowInFocusEvent(QFocusEvent *) = 0;
    virtual void windowOutFocusEvent(QFocusEvent *) = 0;
    virtual void windowShowEvent(QShowEvent *) = 0;
    virtual void windowHideEvent(QHideEvent *) = 0;
};

#endif // IEVENTHANDLER_H
