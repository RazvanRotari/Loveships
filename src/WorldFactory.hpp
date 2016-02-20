#pragma once

#include <random>

#include "LoveTypes.hpp"
#include "World.hpp"

namespace LoveShips {

enum WorldSize {
    Small = 0,
    Medium,
    Big,
    Huge

};

class WorldFactory {
public:
    WorldFactory(const WorldSize worldSize) : _worldSize(worldSize) {
        std::random_device randomDevice;
        _generator.seed(randomDevice());
    }
    World generateWorld();

private:
    SolarSystem generateSolarSystem(World& world);
    float generateRandomPlanetRadiusInSolarSystem(SolarSystem& solarSystem);
    Point generateRandomPositionForSolarSystem(const SolarSystem& solarSystem, const World& world);

    std::vector<Planet> generatePlanetsForSolorSystem(SolarSystem& solarSystem);

    Planet createPlanet(Point planetPosition, Color color, float radius) const;

    //Random stuff
    float randomFloat(float a, float b);
    int randomInt(int a, int b);
    Color randomColor();

    size_t numberOfSolorSystemsForSize(const WorldSize worldSize) const;
    Size sizeForWorldSize(const WorldSize worldSize) const;

private:
    WorldSize _worldSize;
    std::default_random_engine _generator;
};
}
