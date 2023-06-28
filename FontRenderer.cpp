#include "FontRenderer.h"

namespace font {
	sf::Text text(const std::string string, const sf::Vector2f position, const sf::Font& font, const unsigned short size, const sf::Uint32 style, const sf::Color color, const float letter_spacing) {
		sf::Text text;
		text.setFont(font);
		text.setPosition(position);
		text.setString(string);
		text.setCharacterSize(size);
		text.setStyle(style);
		text.setFillColor(color);
		text.setLetterSpacing(letter_spacing);
		return text;
	}

	void render(sf::RenderWindow& window, const std::string string, const sf::Vector2f position, const sf::Font& font, const unsigned short size, const sf::Uint32 style, const sf::Color color) {
		window.draw(font::text(string, position, font, size, style, color));
	}

	void render(sf::RenderWindow& window, const sf::Text& text) {
		window.draw(text);
	}

	float height(const sf::Font& font, const unsigned short font_size, const bool smart, const std::string string, const sf::Uint32 style) {
		sf::Text text;
		text.setString(string);
		text.setFont(font);
		text.setCharacterSize(font_size);
		text.setStyle(style);
		if (smart) return text.getCharacterSize();
		return text.getLocalBounds().height;
	}

	float width(const sf::Font& font, const unsigned short font_size, const bool smart, const std::string string, const sf::Uint32 style, const float char_spacing) {
		sf::Text text;
		text.setString(string);
		text.setFont(font);
		text.setCharacterSize(font_size);
		text.setStyle(style);
		text.setLetterSpacing(char_spacing);
		if (smart) return text.findCharacterPos(text.getString().getSize()).x - text.findCharacterPos(0).x;
		return text.getLocalBounds().width;
	}

	float width(const sf::Text& text, const bool smart) {
		if (smart) return text.findCharacterPos(text.getString().getSize()).x - text.findCharacterPos(0).x;
		return text.getLocalBounds().width;
	}

	float height(const sf::Text& text, const bool smart) {
		if (smart) return text.getCharacterSize();
		return text.getLocalBounds().height;
	}

	float width_c(const sf::Text text, const bool smart) {
		if (smart) return text.findCharacterPos(text.getString().getSize()).x - text.findCharacterPos(0).x;
		return text.getLocalBounds().width;
	}

	float height_c(const sf::Text text, const bool smart) {
		if (smart) return text.getCharacterSize();
		return text.getLocalBounds().height;
	}
}