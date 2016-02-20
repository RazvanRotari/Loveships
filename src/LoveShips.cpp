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
#include "ResourceManager.hpp"
#include "Game.hpp"

using std::cerr;
using std::cout;
using std::endl;

namespace ex = entityx;

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "LoveShips");
    LoveShips::ResourceManager resourceManager;
    LoveShips::Game game = LoveShips::Game::newGame(LoveShips::WorldSize::Medium);
    LoveShips::GameScreen app(window, resourceManager, game);
    app.run();

}
