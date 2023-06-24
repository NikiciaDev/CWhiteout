#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Whiteout final {
public:
	const std::string name = "Whiteout";
	const std::string build = "1.0";
	const std::string n_a_b = "Whiteout | b1.0";
	const sf::Vector2<const unsigned int> base_dimensions{800, 500};
	sf::RenderWindow* window{ nullptr };

	Whiteout();

	~Whiteout();

	void assign_window(sf::RenderWindow* window);
};