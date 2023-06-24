#include "Whiteout.h"

std::string Whiteout::name = "Whiteout";
std::string Whiteout::build = "b0.0";
std::string Whiteout::name_build = "Whiteout | b0.0";

Whiteout::Whiteout(sf::RenderWindow* window) { 
	this->window = window;
}

Whiteout::~Whiteout() {
	delete window;
}