#pragma once
#include "SFML/Graphics.hpp"
#include "Module.h"
#include "Button.h"
#include "FontRenderer.h"
#include "VectorUtil.h"

class CategorySelectionButton final : public Button  {
private:
	Whiteout* whiteout;

public:
	mdl::MODULE_CATEGORY current;

	CategorySelectionButton(Whiteout& window, sf::FloatRect pos);

	sf::Text get_draw_text();

	void draw() override;

	bool on_mouse(const Key key) override;
};