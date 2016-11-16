#ifndef IINPUTHANDLER_H
#define IINPUTHANDLER_H

#include <QKeyEvent>

/* USER INPUT HANDLING */
struct IInputHandler {
    virtual void onKeyPress(QKeyEvent *event) = 0;
    virtual void onKeyRelease(QKeyEvent *event) = 0;
    virtual void onMousePress(QMouseEvent *event) = 0;
    virtual void onMouseRelease(QMouseEvent *event) = 0;
    virtual void onMouseMove(QMouseEvent *event) = 0;
    virtual void onWheelInteraction(QWheelEvent *event) = 0;
    virtual ~IInputHandler() {}
};

#endif // IINPUTHANDLER_H
