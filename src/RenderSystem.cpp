#include "RenderSystem.hpp"
#include "BasicComponents.hpp"

#include <sstream>
#include <iostream>

namespace LoveShips {

namespace ex = entityx;

void RenderSystem::update(ex::EntityManager &es, ex::EventManager &events,
                          ex::TimeDelta dt) {
    es.each<Camera>([this](ex::Entity entity, Camera &camera) {
        sf::Vector2f size = {(float)target.getSize().x, (float)target.getSize().y};
        target.setView(sf::View(camera.center, size));
    });
    es.each<Body, Renderable>(
        [this](ex::Entity entity, Body &body, Renderable &renderable) {
            renderable.sprite.setPosition(body.position);
            renderable.sprite.setRotation(body.rotation);
            target.draw(renderable.sprite);
        });
    drawFPS(es, dt);
}

void RenderSystem::drawFPS(ex::EntityManager &es, const ex::TimeDelta &dt) {
    last_update += dt;
    frame_count++;
    text.setPosition(-500,-500);
    if (last_update >= 0.5) {
        std::ostringstream out;
        const double fps = frame_count / last_update;
        out << es.size() << " entities (" << static_cast<int>(fps) << " fps)";
        text.setString(out.str());
        last_update = 0.0;
        frame_count = 0.0;
    }
    target.draw(text);
}
}
