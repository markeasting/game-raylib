#include "./MyScene.h"
#include <iostream>
#include <cmath>

#include "../components/Cube.h"

MyScene::MyScene() {}

void MyScene::create() {
    // m_entity.addComponent<Cube>();

    m_entityManager.add(m_entity);

    Transform2D t2d;
    m_entityManager.addComponent(m_entity, t2d);
}

void MyScene::processInput() {} // @TODO some kind of input manager / singleton

void MyScene::update(float time, float deltaTime)
{
    m_cubePosition.x = 1 * sin(GetTime() * 2);
}

void MyScene::draw()
{
    BeginMode3D(m_camera);

        // auto cube = m_entity.getComponent(0);
        // cube.draw.........

        DrawCube(m_cubePosition, 2.0f, 2.0f, 2.0f, RED);
        DrawCubeWires(m_cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

        DrawGrid(10, 1.0f);

    EndMode3D();

    DrawText("Welcome to the third dimension!", 10, 40, 20, DARKGRAY);

    DrawFPS(10, 10);

}

void MyScene::destroy() {}

