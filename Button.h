#pragma once
#define NOMINMAX

#include "Key.h"
#include "SFML/Graphics.hpp"

class Button {
protected:
	sf::RenderWindow& window;
	Button(sf::RenderWindow& window, sf::FloatRect pos);

public:
	sf::FloatRect pos;

	virtual void draw();

	// Returns true if the button was beneth the mouse. Stop looping if so!
	virtual bool on_mouse(const Key key);
};