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

private:
    explicit Game(World&& world) : _world(world) {}
private:
    World _world;
};

}
