#pragma once

#include <entityx/entityx.h>

#include "WorldFactory.hpp"
#include "LoveTypes.hpp"
#include "ResourceManager.hpp"
#include "RenderSystem.hpp"
#include "InputSystem.hpp"
#include "CameraSystem.hpp"
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

        systems.add<InputSystem>(target);
        systems.add<CameraSystem>();
        systems.add<RenderSystem>(target, resourceManager.getDefaultFont());
        systems.configure();
        _game.addEntities(entities, _resourceManager);
        auto camera = entities.create();
        auto size = _renderTarget.getView().getSize();
        camera.assign<Camera>(sf::Vector2f(0,0), size);
    }

    void run();

private:
    sf::RenderWindow& _renderTarget;
    ResourceManager& _resourceManager;
    Game _game;
};
}
