#pragma once
#include "SFML/Graphics.hpp"
#include "Whiteout.h"

namespace font {
	extern sf::Font meb, mb, mm, mr;

	sf::Text text(const std::string string, const sf::Vector2f position, const sf::Vector2f scale = sf::Vector2f(1, 1), const sf::Font& font = font::mm, const unsigned short size = 16, const sf::Uint32 style = sf::Text::Regular, const sf::Color color = Whiteout::text_color, const float letter_spacing = 1);

	void render(sf::RenderWindow& window, const std::string string, const sf::Vector2f position, const sf::Vector2f scale = sf::Vector2f(1, 1), const sf::Font& font = font::mm, const unsigned short size = 16, const sf::Uint32 style = sf::Text::Regular, const sf::Color color = Whiteout::text_color);

	void render(sf::RenderWindow& window, const sf::Text& text);

	float height(const std::string string = "Whiteout", const sf::Font& font = font::mm, const unsigned short font_size = 16, const bool smart = false, const sf::Uint32 style = sf::Text::Regular);

	float width(const std::string string = "Whiteout", const sf::Font& font = font::mm, const unsigned short font_size = 16, const bool smart = false, const sf::Uint32 style = sf::Text::Regular, const float char_spacing = 1);

	float width(const sf::Text& text, const bool smart = false);

	float height(const sf::Text& text, const bool smart = false);

	float width_c(const sf::Text text, const bool smart = false);

	float height_c(const sf::Text text, const bool smart = false);
}