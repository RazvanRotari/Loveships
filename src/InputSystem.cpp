#include "InputSystem.hpp"

namespace LoveShips {

const auto CameraUpKey = sf::Keyboard::Up;
const auto CameraDownKey = sf::Keyboard::Down;
const auto CameraRightKey = sf::Keyboard::Right;
const auto CameraLeftKey = sf::Keyboard::Left;

void InputSystem::update(entityx::EntityManager &entities,
                         entityx::EventManager &events, ex::TimeDelta dt) {
    sf::Event event;
    while (_target.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                _target.close();
                break;

            case sf::Event::Resized: {
                // update the view to the new size of the window
                auto currentView = _target.getView();
                sf::FloatRect visibleArea(currentView.getCenter().x,
                                          currentView.getCenter().y,
                                          event.size.width, event.size.height);

                _target.setView(sf::View(visibleArea));
                break;
            }

            case sf::Event::KeyReleased:
                std::cout << "KeyReleased" << std::endl;
                switch (event.key.code) {
                    case CameraUpKey:
                    case CameraDownKey:
                        moveEvent.y = 0;
                        break;
                    case CameraLeftKey:
                    case CameraRightKey:
                        moveEvent.x = 0;
                        break;
                    default:
                        break;
                }
                break;

            case sf::Event::KeyPressed: {
                std::cout << "KeyPress" << std::endl;
                switch (event.key.code) {
                    case CameraUpKey:
                        moveEvent.y = -1;
                        break;
                    case CameraDownKey:
                        moveEvent.y = 1;
                        break;
                    case CameraLeftKey:
                        moveEvent.x = -1;
                        break;
                    case CameraRightKey:
                        moveEvent.x = 1;
                        break;
                    default:
                        break;
                }
                break;
            }

            default:
                break;
        }
    }
    // This is stupid
    events.emit<CameraMoveEvent>(moveEvent.x, moveEvent.y);
}

}
