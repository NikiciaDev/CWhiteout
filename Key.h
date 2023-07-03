#pragma once
#include <SFML/Graphics.hpp>

class Key final {
public:
	unsigned long keycode { 0 };
	sf::Vector2f mouse_pos{ 0, 0 };

	Key();

	explicit Key(const unsigned long keyode, const sf::Vector2f mouse_pos);
};