#include "FontRenderer.h"

namespace frr {
	sf::Text text(const std::string string, const sf::Font& font, const sf::Vector2f position, const unsigned short size, const sf::Uint32 style, const sf::Color color) {
		sf::Text text;
		text.setFont(font);
		text.setString(string);
		text.setCharacterSize(size);
		text.setStyle(style);
		text.setFillColor(color);
		text.setPosition(position);
		return text;
	}

	void render(sf::RenderWindow& window, const std::string string, const sf::Font& font, const sf::Vector2f position, const unsigned short size, const sf::Uint32 style, const sf::Color color) {
		window.draw(frr::text(string, font, position, size, style, color));
	}

	float width(sf::Text text) {
		return text.getLocalBounds().width;
	}

	float height(sf::Text text) {
		return text.getLocalBounds().height;
	}

	float width_g(sf::Text text) {
		return text.getGlobalBounds().width;
	}

	float height_g(sf::Text text) {
		return text.getGlobalBounds().height;
	}
}