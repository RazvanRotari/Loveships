#pragma once

#include <entityx/entityx.h>

#include "WorldFactory.hpp"
#include "LoveTypes.hpp"
#include "ResourceManager.hpp"
#include "RenderSystem.hpp"
#include "Game.hpp"
#include "BasicComponents.hpp"

namespace LoveShips {

namespace ex = entityx;

class GameScreen : public ex::EntityX {
public:
    explicit GameScreen(sf::RenderWindow& target,
                        ResourceManager& resourceManager, Game& game)
        : _renderTarget(target),
          _resourceManager(resourceManager),
          _game(game) {

        systems.add<RenderSystem>(target, resourceManager.getDefaultFont());
        systems.configure();
        _game.addEntities(entities, _resourceManager);
    }

    void run();

private:
    sf::RenderWindow& _renderTarget;
    ResourceManager& _resourceManager;
    Game _game;
};
}
