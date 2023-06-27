#pragma once
#include "SFML/Graphics.hpp"

namespace frr {
	extern sf::Font rmb, rmm, rmr, rmt;

	sf::Text text(const std::string string, const sf::Font& font, const sf::Vector2f position, const unsigned short size = 14, const sf::Uint32 style = sf::Text::Regular, const sf::Color color = sf::Color::White);

	void render(sf::RenderWindow& window, const std::string string, const sf::Font& font, const sf::Vector2f position, const unsigned short size = 14, const sf::Uint32 style = sf::Text::Regular, const sf::Color color = sf::Color::White);

	float width(sf::Text& text);

	float height(sf::Text& text);

	float width_g(sf::Text& text);

	float height_g(sf::Text& text);
}