#pragma once

#include <entityx/entityx.h>

#include "WorldFactory.hpp"
#include "LoveTypes.hpp"
#include "ResourceManager.hpp"
#include "RenderSystem.hpp"

namespace LoveShips {

namespace ex = entityx

class GameScreen : public ex::EntityX {
public:
    explicit GameScreen(sf::RenderTarget& target,
                         ResourceManager& resourceManager);
    

    void update(ex::TimeDelta dt); 
};

}
