#include "GameScreen.hpp"

namespace LoveShips {

explicit GameScreen::GameScreen(sf::RenderTarget& target,
                    ResourceManager& resourceManager) {
    systems.add<RenderSystem>(target, resourceManager.getDefaultFont());
    systems.configure();
    entityx::Entity entity = entities.create();
    Sprite sprite(resourceManager.getTextureByName("bc2.png"));
    entity.assign<Body>(Vector2f(4, 4), Vector2f(5, 5), 0.0);
    entity.assign<Renderable>(sprite);
}

void GameScreen::update(ex::TimeDelta dt) { systems.update_all(dt); }
}
