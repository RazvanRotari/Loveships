#pragma once

#include <entityx/entityx.h>

#include "WorldFactory.hpp"
#include "LoveTypes.hpp"

namespace LoveShips {

namespace ex = entityx;
class ResourceManager;

class Game {
public:
    static Game newGame(WorldSize worldSize);
public:
    void addEntities(ex::EntityManager& entities, ResourceManager& resourceManager);
    sf::Vector2f getSize() const {
        return _size;
    }

private:
    explicit Game(World&& world) : _world(world) {
        _size.x = world.size.width;
        _size.y = world.size.height;
    }
private:
    World _world;
    sf::Vector2f _size;
};

}
