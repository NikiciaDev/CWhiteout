#pragma once
#include "SFML/Graphics.hpp"
#include "Module.h"
#include "Button.h"
#include "FontRenderer.h"
#include "VecMapUtil.h"

extern std::vector<std::string> mdcn_a;
extern sf::Color mdcc(unsigned short index);

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