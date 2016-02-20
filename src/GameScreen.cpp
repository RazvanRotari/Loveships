#include "GameScreen.hpp"
#include <iostream>
namespace LoveShips {

void GameScreen::run() {
    sf::Clock clock;
    while (_renderTarget.isOpen()) {
        sf::Event event;
        while (_renderTarget.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    _renderTarget.close();
                    break;

                default:
                    break;
            }
        }

        _renderTarget.clear();
        sf::Time elapsed = clock.restart();
        systems.update_all(elapsed.asSeconds());

        _renderTarget.display();
    }
}
}
