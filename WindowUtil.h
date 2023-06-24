#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace wul {
	sf::RenderWindow* create_window(const std::string title, const unsigned short antialiasing_level, const unsigned short width, const unsigned short height);
}