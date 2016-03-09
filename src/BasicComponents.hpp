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

struct Camera {
    explicit Camera(const Vector2f &center, const Vector2f &size)
        : center(center), size(size) {}
    sf::Vector2f center;
    sf::Vector2f size;
};

// Events
struct KeyPress {
    explicit KeyPress(sf::Keyboard::Key key) : key(key) {}
    sf::Keyboard::Key key;
};

struct CameraMoveEvent {
    explicit CameraMoveEvent(float x = 0, float y = 0)
        : x(x), y(y){}
    float x;
    float y;
};
}
