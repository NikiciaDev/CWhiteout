#pragma once
#include <SFML/Graphics.hpp>

class DrawableSetting {
protected:
	sf::Vector2f pos;

	DrawableSetting(const sf::Vector2f pos);

public:
	virtual ~DrawableSetting();

	virtual void draw();

	virtual void on_event();
};