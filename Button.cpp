#include "Button.h"

Button::Button(sf::RenderWindow& window, sf::FloatRect pos) : window(window), pos(pos) {}

void Button::draw() { }

bool Button::on_mouse(const Key key) { 
	return false;
}
