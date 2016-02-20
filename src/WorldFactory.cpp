
#include "WorldFactory.hpp"
#include "World.hpp"

namespace LoveShips {

World WorldFactory::generateWorld() {
    size_t numberOfSystems = numberOfSolorSystemsForSize(_worldSize);
    World world;

    world.solarSystems.reserve(numberOfSystems);
    for (size_t i = 0; i < numberOfSystems; i++) {
        world.solarSystems.push_back(generateSolarSystem(world));
    }
}


SolarSystem WorldFactory::generateSolarSystem(World& world) {
    SolarSystem solarSystem;

    solarSystem.sun.radius = randomInt(20, 80);
    solarSystem.planets = generatePlanetsForSolorSystem(solarSystem);

    solarSystem.center = generateRandomPositionForSolarSystem(solarSystem, world);
    for (auto planet:solarSystem.planets) {
        float x = solarSystem.center.x + planet.position.x;
        float y = solarSystem.center.y + planet.position.y;
        planet.position = {x, y};
    }

    return solarSystem;
}

Point WorldFactory::generateRandomPositionForSolarSystem(
    const SolarSystem& solarSystem, const World& world) {
    Point center;
    Size size = sizeForWorldSize(_worldSize);
    float l = size.width;
    float L = size.height;

    bool ok;
    do {
        ok = true;

        // Generate SolarSystem position
        center = {
            randomFloat(0, (L - solarSystem.systemRadius)),
            randomFloat(0, (l - solarSystem.systemRadius))
        };
        if (center.x - solarSystem.systemRadius < 0) {
            Point point = center;
            point.x += solarSystem.systemRadius;
            center = point;
        }
        if (center.y - solarSystem.systemRadius < 0) {
            Point point = center;
            point.y += solarSystem.systemRadius;
            center = point;
        }

        // Verify other SolarSystems positions
        for (auto solarSystem:world.solarSystems) {
            float distance = center.distanceTo(solarSystem.center);
            if (distance <= (solarSystem.systemRadius + solarSystem.systemRadius)) {
                ok = false;
                break;
            }
        }
    } while (!ok);
    return center;
}
std::vector<Planet> WorldFactory::generatePlanetsForSolorSystem(
    SolarSystem& solarSystem) {
    // The number of planets will be between 1 and 8
    std::uniform_int_distribution<int> distribution(1, 8);

    int numberOfPlanets = distribution(_generator);

    float planetArc = 360 / (numberOfPlanets);

    float avgPlanetDistance =
        solarSystem.sun.radius + solarSystem.sun.radius / 1.5;
    float rangePlanetDistance = solarSystem.sun.radius / 2;  // can be /-

    std::vector<Planet> planets;
    planets.reserve(numberOfPlanets);

    for (int i = 0; i < numberOfPlanets; i++) {
        float planetRadius =
            generateRandomPlanetRadiusInSolarSystem(solarSystem);
        // Planet position
        float planetAngle = randomFloat(0, planetArc) + planetArc * i;

        float currentPlanetOffset = randomFloat(0, rangePlanetDistance);
        if (randomInt(0, 1) != 1) {
            currentPlanetOffset *= -1;
        }
        float planetDistanceFromSun =
            currentPlanetOffset + avgPlanetDistance * (i + 1) + planetRadius;
        if ((i == 0) && (planetDistanceFromSun < solarSystem.sun.radius)) {
            planetDistanceFromSun = solarSystem.sun.radius * 2;
        }
        float x = planetDistanceFromSun * sin(planetAngle);
        float y = planetDistanceFromSun * cos(planetAngle);
        Point planetPosition;
        planetPosition.x = x;
        planetPosition.y = y;

        Color planetColor = randomColor();

        Planet planet = createPlanet(planetPosition, planetColor, planetRadius);
        planets.push_back(planet);
        if (i == numberOfPlanets - 1) {
            solarSystem.systemRadius = planetDistanceFromSun + 2 * planetRadius;
        }
    }
    return planets;
}

float WorldFactory::generateRandomPlanetRadiusInSolarSystem(
    SolarSystem& solarSystem) {
    float planetRadiusGeneratedRandom =
        randomFloat(20, solarSystem.sun.radius / 3);
    float planetRadius = 20;

    for (int i = 20; i < 50; i = i + 4) {
        if (planetRadiusGeneratedRandom >= i) planetRadius = i;
    }

    return planetRadius;
}

Planet WorldFactory::createPlanet(Point planetPosition, Color color,
                                  float radius) const {
    Planet planet;
    planet.color = color;
    planet.position = planetPosition;
    planet.radius = radius;
    return planet;
}

float WorldFactory::randomFloat(float a, float b) {
    std::uniform_real_distribution<float> distribution(a, b);
    return distribution(_generator);
}

int WorldFactory::randomInt(int a, int b) {
    std::uniform_int_distribution<int> distribution(a, b);
    return distribution(_generator);
}

size_t WorldFactory::numberOfSolorSystemsForSize(
    const WorldSize worldSize) const {
    switch (worldSize) {
        case WorldSize::Huge:
            return 20;
        case WorldSize::Big:
            return 7;
        case WorldSize::Medium:
            return 3;
        case WorldSize::Small:
            return 2;
    }
}

Color WorldFactory::randomColor() {
    return Color(randomInt(0, 255), randomInt(0, 255), randomInt(0, 255));
}

Size WorldFactory::sizeForWorldSize(const WorldSize worldSize) const {
    switch (worldSize) {
        case WorldSize::Huge:
            return {12048, 12048};
        case WorldSize::Big:
            return {6024, 6024};
        case WorldSize::Medium:
            return {3012, 3012};
        case WorldSize::Small:
            return {1024,1024};
    }

}
}
