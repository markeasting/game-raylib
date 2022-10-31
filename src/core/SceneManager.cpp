
#include "Scene.h"
#include "SceneManager.h"

void SceneManager::setActiveScene(Scene scene) {
    // m_activeScene = scene;
    m_scenes.push_back(scene);
}

void SceneManager::update() {

    for (Scene scene : m_scenes) {
        if (!scene.m_initialized)
            scene.init();

        scene.update();
    }

}
