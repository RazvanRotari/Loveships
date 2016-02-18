#pragma once

#include "LoveTypes.hpp"

namespace LoveShips {
struct Body {
    Body(const Vector2f &position, const Vector2f &direction,
         float rotationd = 0.0)
        : position(position), direction(direction), rotationd(rotationd) {}

    sf::Vector2f position;
    sf::Vector2f direction;
    float rotation = 0.0, rotationd;
};
}
