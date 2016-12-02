#ifndef GAME_H
#define GAME_H

#include <QtGui/QGuiApplication>

#include "gamewindow.h"
#include "coreengine.h"
#include "cubicscene.h"

class Game
{
public:
    static const int WINDOW_WIDTH = 1024;
    static const int WINDOW_HEIGHT = 768;

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
    Scene *m_scene;
};

#endif // GAME_H
