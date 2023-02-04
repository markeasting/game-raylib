#pragma once
#include "../common.h"
#include "./Component.h"

struct Sprite : Component {
    const char* m_resource;
    Texture2D m_texture = { 0 }; // LoadTexture("resources/button.png"); // Load button texture

    void preload();
    void draw(const Vector2& position);
};
