#pragma once
#include "SFML/Graphics.hpp"

class SentCommand final {
public:
	sf::Vector2f input_pos{ 35, 35 };
	std::string prompt{ "" };
	std::string response{ "" };

	SentCommand(sf::Vector2f input_pos, std::string prompt, std::string response);
};