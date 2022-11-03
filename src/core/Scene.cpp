#include "./Scene.h"

Scene::Scene() {
    this->initCamera();
}

void Scene::initCamera() {
    m_camera = { 0 };
    m_camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };  // Camera position
    m_camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    m_camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    m_camera.fovy = 30.0f;                                // Camera field-of-view Y
    m_camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type
}
