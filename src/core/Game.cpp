#include "./Game.h"
#include "../scenes/MyScene.h"
#include "../scenes/SplashScreenScene.h"

#include <iostream>

Game::Game()
{
    InitWindow(
        m_config.screenWidth,
        m_config.screenHeight,
        m_config.windowTitle);

    SetTargetFPS(m_config.targetFPS);

    this->registerScenes();
}

void Game::registerScenes()
{
    std::shared_ptr<SplashScreenScene> splashScreen = std::make_shared<SplashScreenScene>();
    std::shared_ptr<MyScene> gameScene = std::make_shared<MyScene>();

    unsigned int splashScreenID = m_sceneManager.add(splashScreen);
    unsigned int gameSceneID = m_sceneManager.add(gameScene);

    m_sceneManager.switchTo(splashScreenID);
}

void Game::update()
{
    m_sceneManager.processInput();
    m_sceneManager.update(m_time, m_deltaTime);
    m_sceneManager.draw();

    m_deltaTime = GetFrameTime();
    m_time = GetTime();

    if (m_time > 3)
    {
        m_sceneManager.deActivate(0);
        m_sceneManager.activate(1);
    }
}

SceneManager Game::getSceneManager() const
{
    return m_sceneManager;
}

bool Game::isRunning() const
{
    return !WindowShouldClose();
}

void Game::close() const
{
    CloseWindow();
}
