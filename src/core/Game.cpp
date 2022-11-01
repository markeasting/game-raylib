#include "./Game.h"
#include "../scenes/MyScene.h"

Game::Game() {
    InitWindow(
        m_config.screenWidth,
        m_config.screenHeight,
        m_config.windowTitle
    );
    SetTargetFPS(m_config.targetFPS);

    // std::shared_ptr<SceneSplashScreen> splashScreen = std::make_shared<SceneSplashScreen>(workingDir, m_sceneManager, window);
    std::shared_ptr<MyScene> gameScene = std::make_shared<MyScene>();

    // unsigned int splashScreenID = m_sceneManager.Add(splashScreen);
    unsigned int gameSceneID = m_sceneManager.Add(gameScene);

    // splashScreen->SetSwitchToScene(gameSceneID);
    m_sceneManager.SwitchTo(gameSceneID);

    m_deltaTime = GetFrameTime();
}

void Game::Update() {
    // window.Update();

    m_sceneManager.ProcessInput();
    m_sceneManager.Update(m_deltaTime);
    m_sceneManager.LateUpdate(m_deltaTime);
    m_sceneManager.Draw();
}

// void Game::Calculatem_deltaTime() {
//     m_deltaTime = clock.restart().asSeconds();
// }

bool Game::IsRunning() const {
    return !WindowShouldClose();
}

void Game::close() const {
    CloseWindow();
}
