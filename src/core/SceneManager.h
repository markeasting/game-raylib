#pragma once

#include <memory>
#include <unordered_map>
#include "Scene.h"

class SceneManager
{
public:
    SceneManager();

    void ProcessInput();
    void Update(float deltaTime);

    void Draw();

    unsigned int Add(std::shared_ptr<Scene> scene);

    void SwitchTo(unsigned int id);

    void Remove(unsigned int id);

private:
    std::unordered_map<unsigned int, std::shared_ptr<Scene>> m_scenes;

    std::shared_ptr<Scene> m_curScene;

    unsigned int insertedSceneID;
};
