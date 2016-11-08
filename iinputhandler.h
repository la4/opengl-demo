#ifndef IINPUTHANDLER_H
#define IINPUTHANDLER_H

#include <QKeyEvent>

/* USER INPUT HANDLING */
struct IInputHandler {
    virtual void keyPressEvent(QKeyEvent *event) = 0;
    virtual void keyReleaseEvent(QKeyEvent *event) = 0;
    virtual void mousePressEvent(QMouseEvent *event) = 0;
    virtual void mouseReleaseEvent(QMouseEvent *event) = 0;
    virtual void mouseMoveEvent(QMouseEvent *event) = 0;
    virtual void wheelEvent(QWheelEvent *event) = 0;
};

#endif // IINPUTHANDLER_H
