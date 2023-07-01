#pragma once
#include <SFML/Graphics.hpp>
#include "Key.h"

class DrawableSetting {
protected:
	const sf::Vector2f pos;

	DrawableSetting(const sf::Vector2f pos);

public:
	virtual ~DrawableSetting();

	// Returns the occupied height by the drawing.
	virtual float draw();

	// Returns true if the key was handled otherwise 0.
	virtual bool on_event(const Key key);
};