#include "./SceneManager.h"
#include "raylib.h"

struct GameConfig {
    const char* windowTitle = "MOI";
    int screenWidth = 800;
    int screenHeight = 450;
    int targetFPS = 60;
};

class Game {
public:
    Game();

    void Update();
    bool IsRunning() const;

    void close() const;

private:

    GameConfig m_config;

    // Window window;
    // WorkingDirectory workingDir;

    // sf::Clock clock;
    float m_deltaTime;

    SceneManager m_sceneManager;
};
