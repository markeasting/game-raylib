#include "./Sprite.h"

void Sprite::preload() {
    LoadTexture(m_resource);
}

void Sprite::draw(const Vector2& position) {
    DrawTextureV(m_texture, position, WHITE);
}
