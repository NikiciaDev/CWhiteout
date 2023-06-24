#include "Whiteout.h"

Whiteout::Whiteout() {}

Whiteout::~Whiteout() {
	delete window;
}

void Whiteout::assign_window(sf::RenderWindow* window) {
	this->window = window;
}
