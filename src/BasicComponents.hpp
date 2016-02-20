#pragma once

#include "LoveTypes.hpp"

namespace LoveShips {
struct Body {
    Body(const Vector2f &position, float rotationd = 0.0)
        : position(position), rotationd(rotationd) {}

    sf::Vector2f position;
    float rotation = 0.0, rotationd;
};

struct Orbit {
    explicit Orbit(const Vector2f &position, const float radius)
        : position(position), radius(radius) {}
    Vector2f position;
    float radius;
};

struct Renderable {
    explicit Renderable(Sprite &sprite) : sprite(sprite) {}

    sf::Sprite sprite;
};
}
