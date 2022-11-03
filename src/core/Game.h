#include "../common.h"
#include "./SceneManager.h"

struct GameConfig {
    const char* windowTitle = "MOI";
    int screenWidth = 800;
    int screenHeight = 450;
    int targetFPS = 60;
};

class Game {
public:
    Game();

    void update();
    bool isRunning() const;

    void close() const;

    SceneManager getSceneManager() const;
    void registerScenes();

private:

    GameConfig m_config;

    // sf::Clock clock;
    float m_deltaTime = 0;
    float m_time = 0;

    SceneManager m_sceneManager;
};
