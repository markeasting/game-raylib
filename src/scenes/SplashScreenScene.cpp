#include "./SplashScreenScene.h"
#include <iostream>
#include <cmath>

SplashScreenScene::SplashScreenScene() {}

void SplashScreenScene::create() {}

void SplashScreenScene::processInput() {} // @TODO some kind of input manager / singleton

void SplashScreenScene::update(float time, float deltaTime)
{
    m_cubePosition.y = 1 * sin(GetTime() * 2);
}

void SplashScreenScene::draw()
{
    BeginMode3D(m_camera);

        DrawCube(m_cubePosition, 2.0f, 2.0f, 2.0f, GREEN);
        DrawCubeWires(m_cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

        DrawGrid(10, 1.0f);

    EndMode3D();

    DrawText("MOIIIIIII", 10, 40, 30, DARKGRAY);

    DrawFPS(10, 10);

}

void SplashScreenScene::destroy() {}

