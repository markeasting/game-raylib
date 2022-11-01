#pragma once
#include "../common.h"
#include "../core/Scene.h"

class MyScene final : public Scene
{
public:
    MyScene();

    void OnCreate() override;
    void OnDestroy() override;

    void ProcessInput() override;
    void Update(float deltaTime) override;
    void Draw() override;

private:
    Camera3D m_camera;
    Vector3 m_cubePosition = { 0.0f, 0.0f, 0.0f };
};
