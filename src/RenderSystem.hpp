#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include <entityx/entityx.h>

struct Renderable {
    explicit Renderable(sf::Sprite& sprite)
        : sprite(sprite) {}

    sf::Sprite sprite;
};

class RenderSystem : public entityx::System<RenderSystem> {
public:
    explicit RenderSystem(sf::RenderTarget &target, sf::Font &font)
        : target(target) {
        text.setFont(font);
        text.setPosition(sf::Vector2f(2, 2));
        text.setCharacterSize(18);
        text.setColor(sf::Color::White);
    }

    void update(entityx::EntityManager &es, entityx::EventManager &events,
                entityx::TimeDelta dt) override;

    void drawFPS(entityx::EntityManager &es, const entityx::TimeDelta &dt);

private:
    double last_update = 0.0;
    double frame_count = 0.0;
    sf::RenderTarget &target;
    sf::Text text;
};
