#pragma once

#include <vector>
#include "Scene.h"

class SceneManager {
public:

    void setActiveScene(Scene scene);
    // Scene getActiveScene() { return m_activeScene; }

    void update();

private:

    // Scene m_activeScene = NULL;

	std::vector<Scene> m_scenes = {};

};
