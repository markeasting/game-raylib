#include "../common.h"
#include "Scene.h"
#include "SceneManager.h"

SceneManager::SceneManager() : scenes(0), curScene(0) { }

void SceneManager::ProcessInput() {
    if(curScene) {
        curScene->ProcessInput();
    }
}

void SceneManager::Update(float deltaTime) {
    if(curScene) {
        curScene->Update(deltaTime);
    }
}

void SceneManager::LateUpdate(float deltaTime) {
    if(curScene) {
        curScene->LateUpdate(deltaTime);
    }
}

void SceneManager::Draw() {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    if(curScene) {
        curScene->Draw();
    }
    EndDrawing();
}

unsigned int SceneManager::Add(std::shared_ptr<Scene> scene) {
    auto inserted = scenes.insert(std::make_pair(insertedSceneID, scene));

    inserted.first->second->OnCreate();

    return insertedSceneID++;
}

void SceneManager::Remove(unsigned int id) {
    auto it = scenes.find(id);

    if(it != scenes.end()) {
        if(curScene == it->second) {
            curScene = nullptr;
        }

        it->second->OnDestroy();

        scenes.erase(it);
    }
}

void SceneManager::SwitchTo(unsigned int id) {
    auto it = scenes.find(id);

    if(it != scenes.end()) {
        if(curScene) {
            curScene->OnDeactivate();
        }

        curScene = it->second;

        curScene->OnActivate();
    }
}
