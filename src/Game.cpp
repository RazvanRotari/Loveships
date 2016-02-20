#include "Game.hpp"
#include "Utils.hpp"
#include "ResourceManager.hpp"
#include "BasicComponents.hpp"
#include "World.hpp"

namespace LoveShips {

STATIC Game Game::newGame(WorldSize worldSize) {
    WorldFactory worldFactory(worldSize);
    return Game(std::move(worldFactory.generateWorld()));
}

sf::Vector2f convertPoint(const Point& point) {
    return sf::Vector2f(point.x, point.y);

}

void Game::addEntities(ex::EntityManager& entities,
                       ResourceManager& resourceManager) {
    for (auto solarSystem : _world.solarSystems) {
        auto sunEntity = entities.create();
        auto sun = solarSystem.sun;
        sunEntity.assign<Body>(convertPoint(sun.position));
        Sprite sunSprite(resourceManager.getTextureByName("sun.png"));
        sunEntity.assign<Renderable>(sunSprite);

        for (auto planet : solarSystem.planets) {
            auto planetEntity = entities.create();
            planetEntity.assign<Body>(convertPoint(planet.position));
            Sprite planetSprite(resourceManager.getTextureByName("planet.png"));
            planetEntity.assign<Renderable>(planetSprite);
            planetEntity.assign<Orbit>(convertPoint(solarSystem.position),
                                       solarSystem.systemRadius);
        }
    }
}
}
