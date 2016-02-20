#include "World.hpp"

#include <cmath>


namespace LoveShips {

float Point::distanceTo(const Point& point) {
    return sqrt(pow(point.x - x, 2) + std::pow(point.y - y, 2));
}

}
