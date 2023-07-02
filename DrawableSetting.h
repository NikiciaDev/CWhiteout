#pragma once
#include <SFML/Graphics.hpp>
#include "Key.h"
#include "Whiteout.h"

class DrawableSetting {
protected:
	const sf::Vector2f pos;
	Whiteout& whiteout;

	DrawableSetting(const sf::Vector2f pos, Whiteout& whiteout);

public:
	virtual ~DrawableSetting();

	// Returns the occupied height by the drawing.
	virtual float draw();

	// Returns true if the key was handled otherwise 0.
	virtual bool on_event(const Key key);
};