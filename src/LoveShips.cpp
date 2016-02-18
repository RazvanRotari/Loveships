#include <cmath>
#include <unordered_set>
#include <sstream>
#include <cstdlib>
#include <memory>
#include <string>
#include <vector>
#include <iostream>

#include <entityx/entityx.h>

#include "LoveTypes.hpp"
#include "RenderSystem.hpp"
#include "ResourceManager.hpp"
#include "BasicComponents.hpp"

using std::cerr;
using std::cout;
using std::endl;

namespace ex = entityx;

namespace LoveShips {
class Application : public ex::EntityX {
public:
    explicit Application(sf::RenderTarget& target,
                         ResourceManager& resourceManager) {
        systems.add<RenderSystem>(target, resourceManager.getDefaultFont());
        systems.configure();
        entityx::Entity entity = entities.create();
        Sprite sprite(resourceManager.getTextureByName("bc2.png"));
        entity.assign<Body>(Vector2f(4, 4), Vector2f(5, 5), 0.0);
        entity.assign<Renderable>(sprite);
    }

    void update(ex::TimeDelta dt) { systems.update_all(dt); }
};
}
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "LoveShips");
    LoveShips::ResourceManager resourceManager;
    LoveShips::Font& font = resourceManager.getDefaultFont();

    LoveShips::Application app(window, resourceManager);

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    break;
            }
        }

        window.clear();
        sf::Time elapsed = clock.restart();
        app.update(elapsed.asSeconds());
        window.display();
    }
}
