#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Whiteout final {
public:
	static std::string name;
	static std::string build;
	static std::string name_build;
	sf::RenderWindow* window;

	Whiteout(sf::RenderWindow* window);

	~Whiteout();
};