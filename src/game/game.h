#ifndef GAME_H
#define GAME_H

#include <QtGui/QGuiApplication>

#include "gamewindow.h"
#include "coreengine.h"

class Game
{
public:
    static const int WINDOW_WIDTH = 640;
    static const int WINDOW_HEIGHT = 480;

    static Game& mainInstance(int argc, char **argv) {
        static Game gameInstance(argc, argv);
        return gameInstance;
    }

    int execute();

private:
    Game(int argc, char **argv);
    ~Game();

    Game(Game const&) = delete;
    Game& operator= (Game const&) = delete;

    void setWindowFormat(const int width, const int height);

    QGuiApplication *m_guiApp;
    GameWindow *m_gameWindow;
    CoreEngine *m_coreEngine;
};

#endif // GAME_H
