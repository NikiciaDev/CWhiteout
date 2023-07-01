#pragma once
#include <SFML/Graphics.hpp>
#include "Key.h"

class DrawableSetting {
protected:
	sf::Vector2f pos;

	DrawableSetting(const sf::Vector2f pos);

public:
	virtual ~DrawableSetting();

	virtual void draw();

	// Returns true if the key was handled otherwise 0.
	virtual bool on_event(const Key key);
};