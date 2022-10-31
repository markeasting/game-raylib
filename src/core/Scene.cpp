#include <iostream>
#include "raylib.h"
#include "Scene.h"

void Scene::init() {
    m_initialized = true;

    m_camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };  // Camera position
    m_camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    m_camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    m_camera.fovy = 30.0f;                                // Camera field-of-view Y
    m_camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type
}

void Scene::update() {

    BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(m_camera);

            DrawCube(m_cubePosition, 2.0f, 2.0f, 2.0f, RED);
            DrawCubeWires(m_cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

            DrawGrid(10, 1.0f);

        EndMode3D();

        DrawText("Welcome to the third dimension!", 10, 40, 20, DARKGRAY);

        DrawFPS(10, 10);

    EndDrawing();
}
