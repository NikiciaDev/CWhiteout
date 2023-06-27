#pragma once
#include "SFML/Graphics.hpp"

namespace render {
	void rect_outline(sf::RenderWindow& window, const sf::Vector2f position, const sf::Vector2f size, const sf::Color color, const float thickness);

	void circle_outline(sf::RenderWindow& window, const sf::Vector2f position, const sf::Vector2f radius_points, const sf::Color color, const float thickness);

	// Draws a rectangle outline with a cutout at the top.
	void rect_outline_cutout(sf::RenderWindow& window, const sf::Vector2f position, const sf::Vector2f size, const sf::Color color, const float thickness, const float cutout_position, const float cutout_length);
}