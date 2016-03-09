#pragma once

#include <entityx/entityx.h>

#include "BasicComponents.hpp"

namespace LoveShips {
namespace ex = entityx;

class InputSystem : public ex::System<InputSystem> {
public:
    explicit InputSystem(sf::RenderWindow &target) : _target(target) {}
    void update(entityx::EntityManager &entities, entityx::EventManager &events,
                ex::TimeDelta dt);

private:

private:
    CameraMoveEvent moveEvent;
    sf::RenderWindow &_target;
};
}
