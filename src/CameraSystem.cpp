#include "CameraSystem.hpp"
#include <iostream>

const float moveSpeed = 1;

namespace LoveShips {
void CameraSystem::configure(entityx::EventManager& eventManager) {
    eventManager.subscribe<CameraMoveEvent>(*this);
}

void CameraSystem::update(entityx::EntityManager& entities,
                          entityx::EventManager& events, ex::TimeDelta dt) {
    if (_moveEvent.x != 0 || _moveEvent.y != 0) {
        /* std::cout << _moveEvent.x << " " << _moveEvent.y << " " << std::endl; */
    }
    entities.each<Camera>([this](ex::Entity entity, Camera& camera) {
        camera.center.x += _moveEvent.x * moveSpeed;
        camera.center.y += _moveEvent.y * moveSpeed;
    });
}

void CameraSystem::receive(const CameraMoveEvent& moveEvent) {
    _moveEvent.x = moveEvent.x;
    _moveEvent.y = moveEvent.y;
}
}
