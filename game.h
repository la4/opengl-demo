#ifndef GAME_H
#define GAME_H

#include <QtGui/QGuiApplication>

#include "openglwindow.h"

class Game
{
public:
    Game();
    ~Game();

    static int execute(int argc, char **argv);
};

#endif // GAME_H
