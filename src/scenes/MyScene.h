#pragma once
#include "../common.h"
#include "../core/Scene.h"
#include "../entity/Entity.h"

class MyScene final : public Scene
{
public:
    MyScene();

    void create() override;
    void destroy() override;

    void processInput() override;
    void update(float time, float deltaTime) override;
    void draw() override;

private:
    Vector3 m_cubePosition = { 0.0f, 0.0f, 0.0f };
    Entity m_entity = Entity();
};
