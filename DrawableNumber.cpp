#include "DrawableNumber.h"

DrawableNumber::DrawableNumber(const sf::Vector2f position, const setting::Type type, NumberSetting* setting, Whiteout& whiteout) : DrawableSetting(position, type, whiteout), setting(setting) { }

void DrawableNumber::draw(float& height, sf::Vector2f outline_r_w) {
	if (!setting->dependency()) return;
	std::string value_rep;
	long double d = setting->force_value();
	long double perc = d / setting->force_max();

	render::rect(whiteout.window, sf::Vector2f(pos.x - 5, pos.y + 2.5f), sf::Vector2f((outline_r_w.x - 20) * perc, font::height()), Module::mdcc[setting->parent->category]);
	font::render(whiteout.window, setting->name, pos);
	std::floor(d) == (int) d ? value_rep = std::to_string((int) d) : value_rep = std::to_string(d);
	font::render(whiteout.window, value_rep, sf::Vector2f(pos.x + outline_r_w.x - 20 - 10 - font::width(value_rep), pos.y));

	height += font::height() + 5;
}

bool DrawableNumber::on_event(const Key key) {
	return false;
}