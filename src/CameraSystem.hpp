#pragma once
#include <entityx/entityx.h>
#include "LoveTypes.hpp"
#include "BasicComponents.hpp"

namespace LoveShips {

namespace ex = entityx;
class CameraSystem : public entityx::System<CameraSystem>,
                     public entityx::Receiver<CameraSystem> {
public:
    void configure(entityx::EventManager &eventManager);
    void update(entityx::EntityManager &entities, entityx::EventManager &events,
                ex::TimeDelta dt);

    void receive(const CameraMoveEvent &keyPress);
private:
    CameraMoveEvent _moveEvent;
};
}
