#include <cmath>
#include <unordered_set>
#include <sstream>
#include <cstdlib>
#include <memory>
#include <string>
#include <vector>
#include <iostream>

#include <entityx/entityx.h>

#include "GameScreen.hpp"
#include "LoveTypes.hpp"
#include "RenderSystem.hpp"
#include "ResourceManager.hpp"
#include "BasicComponents.hpp"

using std::cerr;
using std::cout;
using std::endl;

namespace ex = entityx;

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "LoveShips");
    LoveShips::ResourceManager resourceManager;
    LoveShips::Font& font = resourceManager.getDefaultFont();

    LoveShips::GameScreen app(window, resourceManager);

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
