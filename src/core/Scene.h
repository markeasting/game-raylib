#pragma once
#include "raylib.h"

class SceneManager; // forward declaration, prevent circular import

class Scene {
public:

    Camera3D m_camera = { 0 };

    Vector3 m_cubePosition = { 0.0f, 0.0f, 0.0f };

private:
    friend SceneManager;

    bool m_initialized = false;

    void init();
    void update();

};
