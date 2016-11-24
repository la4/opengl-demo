#include "game.h"
#include "gamewindow.h"

Game::Game() {
}

Game::~Game() {
}

int Game::execute(int argc, char **argv) {
    QGuiApplication guiApp(argc, argv);

    QSurfaceFormat format;
    format.setSamples(16);
    format.setDepthBufferSize(24);
    format.setVersion(3, 3);

    GameWindow window;
    window.setFormat(format);
    window.resize(640, 480);
    window.show();

    return guiApp.exec();
}
