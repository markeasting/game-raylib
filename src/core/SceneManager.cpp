#include "../common.h"
#include "Scene.h"
#include "SceneManager.h"

SceneManager::SceneManager() : m_scenes(0), m_curScene(0) { }

void SceneManager::ProcessInput() {
    if(m_curScene)
        m_curScene->ProcessInput();
}

void SceneManager::Update(float deltaTime) {
    if(m_curScene)
        m_curScene->Update(deltaTime);

    // if(m_curScene)
    //     m_curScene->LateUpdate(deltaTime);
}

void SceneManager::Draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    if(m_curScene)
        m_curScene->Draw();
        
    EndDrawing();
}

unsigned int SceneManager::Add(std::shared_ptr<Scene> scene) {
    auto inserted = m_scenes.insert(std::make_pair(insertedSceneID, scene));

    inserted.first->second->OnCreate();

    return insertedSceneID++;
}

void SceneManager::Remove(unsigned int id) {
    auto it = m_scenes.find(id);

    if(it != m_scenes.end()) {
        if(m_curScene == it->second)
            m_curScene = nullptr;

        it->second->OnDestroy();

        m_scenes.erase(it);
    }
}

void SceneManager::SwitchTo(unsigned int id) {
    auto it = m_scenes.find(id);

    if(it != m_scenes.end()) {
        if(m_curScene)
            m_curScene->OnDeactivate();

        m_curScene = it->second;

        m_curScene->OnActivate();
    }
}
