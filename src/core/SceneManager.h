#pragma once

#include <memory>
#include <unordered_map>
#include "Scene.h"

class SceneManager
{
public:
    SceneManager();

    void processInput();
    void update(float time, float deltaTime);

    void draw();

    unsigned int add(std::shared_ptr<Scene> scene);
    void remove(unsigned int id);

    void activate(unsigned int id);
    void deActivate(unsigned int id);
    void switchTo(unsigned int id);

private:
    std::unordered_map<unsigned int, std::shared_ptr<Scene>> m_scenes;

    // std::shared_ptr<Scene> m_curScene; // Render all 'active' scenes instead

    unsigned int m_insertedSceneIdx = 0;
};
