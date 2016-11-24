#ifndef GAME_H
#define GAME_H

#include <QtGui/QGuiApplication>

#include "gamewindow.h"

class Game
    {
    public:
    static Game& mainInstance() {
        static Game gameInstance;
        return gameInstance;
    }

    int execute(int argc, char **argv);

private:
    Game();
    ~Game();

    Game(Game const&) = delete;
    Game& operator= (Game const&) = delete;
};

#endif // GAME_H
