#include "CategorySelectionButton.h"

CategorySelectionButton::CategorySelectionButton(Whiteout& whiteout, sf::FloatRect pos) : Button(whiteout.window, pos) {
	this->whiteout = &whiteout;
	this->current = mdl::MODULE_CATEGORY::COMBAT;
}

sf::Text CategorySelectionButton::get_draw_text() {
	const float width = font::width(Module::mdcn[current], font::mb, 20, false, sf::Text::Bold, 5);
	const float height = font::height(Module::mdcn[current], font::mb, 20, true, sf::Text::Bold);
	this->pos = sf::FloatRect(whiteout->window.getSize().x - 30 - 5 - width, 15 - height / 2, width, height);
	return font::text(Module::mdcn[current], whiteout->window.mapPixelToCoords(sf::Vector2i(pos.getPosition().x, pos.getPosition().y)), font::mb, 20, sf::Text::Bold, Module::mdcc[current], 5);
}

void CategorySelectionButton::draw() {
	font::render(whiteout->window, get_draw_text());
}

bool CategorySelectionButton::on_mouse(const Key key) {
	bool b{ false };
	if (b = pos.contains(sf::Vector2f(key.mouse_pos.x, key.mouse_pos.y))) {
		current = (mdl::MODULE_CATEGORY) vul::next<std::string>(Module::mdcn, current, key.keycode == 2);
		whiteout->view.reset(sf::FloatRect(0, 0, whiteout->window.getSize().x, whiteout->window.getSize().y));
		return true;
	}
	return b;
}