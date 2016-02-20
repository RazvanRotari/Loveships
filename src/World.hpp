#pragma once

#include <vector>
#include "LoveTypes.hpp"

namespace LoveShips {
struct Point {
    float x;
    float y;
    float distanceTo(const Point& point);
};
struct SpaceObject {
    Point position;
};

struct World;
struct SolarSystem;
struct Sun;
struct Planet;
struct Size;

struct Size {
    Size(int width, int height) : width(width), height(height) {}
    int width;
    int height;
};

struct Sun : public SpaceObject {
    float radius;
};

struct Planet : public SpaceObject {
    Color color;
    float radius;
};

struct World {
    std::vector<SolarSystem> solarSystems;
    Size size = {0,0};
};

struct SolarSystem : public SpaceObject {
    Sun sun;
    std::vector<Planet> planets;
    float systemRadius;
    Point center = {0,0};
};



}
