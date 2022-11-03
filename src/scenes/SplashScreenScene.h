#pragma once
#include "../common.h"
#include "../core/Scene.h"

class SplashScreenScene final : public Scene
{
public:
    SplashScreenScene();

    void create() override;
    void destroy() override;

    void processInput() override;
    void update(float time, float deltaTime) override;
    void draw() override;

private:
    Vector3 m_cubePosition = { 0.0f, 0.0f, 0.0f };
};
