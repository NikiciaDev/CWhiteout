#pragma once
#include <SFML/Graphics.hpp>

class DrawableSetting {
protected:
	sf::Vector2f pos;

	DrawableSetting();

public:
	virtual ~DrawableSetting();

	virtual void draw();

	virtual void on_event();
};