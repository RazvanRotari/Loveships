#include "GameScreen.hpp"
#include <iostream>

namespace LoveShips {

void GameScreen::run() {
    while (_renderTarget.isOpen()) {
        sf::Clock clock;

        _renderTarget.clear();
        sf::Time elapsed = clock.restart();
        systems.update_all(elapsed.asSeconds());
        _renderTarget.display();
    }
}
}
