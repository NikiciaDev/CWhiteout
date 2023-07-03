#pragma once
#include <SFML/Graphics.hpp>
#include "Setting.h"
#include "Key.h"
#include "Whiteout.h"
#include "FontRenderer.h"
#include "RenderUtil.h"

class DrawableSetting {
protected:
	bool dragging{ false };
	sf::Vector2f outline_r_w;
	Whiteout& whiteout;

	DrawableSetting(const sf::Vector2f pos, const setting::Type type, Whiteout& whiteout);

	bool bounds_contain(const Key key, const Setting* setting, const mdl::MODULE_CATEGORY current);

public:
	const setting::Type type;
	sf::Vector2f pos;

	virtual ~DrawableSetting();

	// Returns the occupied height by the drawing.
	virtual void draw(float& height, sf::Vector2f outline_r_w);

	// Returns true if the key was handled otherwise 0.
	virtual bool on_event(const Key key, const mdl::MODULE_CATEGORY current);
};