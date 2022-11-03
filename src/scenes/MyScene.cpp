#include "./MyScene.h"
#include <iostream>
#include <cmath>

MyScene::MyScene() {}

void MyScene::create() {}

void MyScene::processInput() {} // @TODO some kind of input manager / singleton

void MyScene::update(float time, float deltaTime)
{
    m_cubePosition.x = 1 * sin(GetTime() * 2);
}

void MyScene::draw()
{
    BeginMode3D(m_camera);

        DrawCube(m_cubePosition, 2.0f, 2.0f, 2.0f, RED);
        DrawCubeWires(m_cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

        DrawGrid(10, 1.0f);

    EndMode3D();

    DrawText("Welcome to the third dimension!", 10, 40, 20, DARKGRAY);

    DrawFPS(10, 10);

}

void MyScene::destroy() {}

