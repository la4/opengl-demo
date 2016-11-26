#include "game.h"
#include "gamewindow.h"

Game::Game(int argc, char **argv) {
    m_guiApp = new QGuiApplication(argc, argv);

    m_gameWindow = new GameWindow();
    m_coreEngine = new CoreEngine();
}

Game::~Game() {
}

int Game::execute() {
    setWindowFormat(WINDOW_WIDTH, WINDOW_HEIGHT);
    m_gameWindow->connectEngine(m_coreEngine);

    m_gameWindow->show();

    return m_guiApp->exec();
}

void Game::setWindowFormat(const int width, const int height) {
    QSurfaceFormat format;
    format.setSamples(16);
    format.setDepthBufferSize(24);
    format.setVersion(3, 3);

    m_gameWindow->setFormat(format);
    m_gameWindow->resize(width, height);
}
