#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <boost/filesystem.hpp>

namespace LoveShips {

using Font = sf::Font;
using Sprite = sf::Sprite;
using Texture = sf::Texture;
using Color = sf::Color;
using SoundBuffer = sf::SoundBuffer;

using Vector2f = sf::Vector2f;

using Path = boost::filesystem::path;
}
