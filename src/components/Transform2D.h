#pragma once
#include "../common.h"
#include "./Component.h"

struct Transform2D : Component {
    Vector2 position = { 0, 0 };
    float rotation = 0;
};
