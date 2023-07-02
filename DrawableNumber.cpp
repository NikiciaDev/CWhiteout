#include "DrawableNumber.h"

DrawableNumber::DrawableNumber(const sf::Vector2f position, const setting::Type type, NumberSetting* setting, Whiteout& whiteout) : DrawableSetting(position, type, whiteout), setting(setting) { }

void DrawableNumber::draw(float& height, sf::Vector2f outline_r_w) {
	if (!setting->dependency()) return;
	std::string value_rep;

	font::render(whiteout.window, setting->name, pos);
	long double d = setting->force_value();
	std::floor(d) == (int) d ? value_rep = std::to_string((int) d) : value_rep = std::to_string(d);
	font::render(whiteout.window, value_rep, sf::Vector2f(pos.x + outline_r_w.x - 20 - 10 - font::width(value_rep), pos.y));

	height += font::height() + 5;
}

bool DrawableNumber::on_event(const Key key) {
	return false;
}