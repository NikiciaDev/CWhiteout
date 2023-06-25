#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Whiteout final {
public:
	static std::string name;
	static std::string build;
	static std::string name_build;
	static sf::Color bg_color;
	static sf::Color base_color;
	static sf::Color sm_base_color;
	sf::RenderWindow* window;

	Whiteout(sf::RenderWindow* window);

	~Whiteout();
};