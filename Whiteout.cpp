#include "Whiteout.h"

std::string Whiteout::name = "Whiteout";
std::string Whiteout::build = "b0.0";
std::string Whiteout::name_build = "Whiteout | b0.0";
sf::Color Whiteout::bg_color = sf::Color(20, 20, 20);
sf::Color Whiteout::base_color = sf::Color(110, 69, 56);
sf::Color Whiteout::sm_base_color = sf::Color(255, 255, 255);

Whiteout::Whiteout(sf::RenderWindow* window) { 
	this->window = window;
}

Whiteout::~Whiteout() {
	delete window;
}