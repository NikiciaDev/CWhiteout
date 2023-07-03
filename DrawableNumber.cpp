#include "DrawableNumber.h"

DrawableNumber::DrawableNumber(const sf::Vector2f position, const setting::Type type, NumberSetting* setting, Whiteout& whiteout) : DrawableSetting(position, type, whiteout), setting(setting) {
	max = setting->force_any(setting->max);
	min = setting->force_any(setting->min);
	inc = setting->force_any(setting->increment);
}

void DrawableNumber::draw(float& height, sf::Vector2f outline_r_w) {
	if (!setting->dependency()) return;
	this->outline_r_w = outline_r_w;

	if (dragging) {
		sf::Vector2i mp(liu::get_cursor_pos());
		if (mp.y < pos.y + 2.5f - 10 || mp.y > pos.y + font::height() + 10 || mp.x < pos.x - 5 - 10 || mp.x > pos.x + outline_r_w.x + 10) {
			dragging = false;
		} else {
			long double nr_val = (mp.x - pos.x - 5) * (max - min) / (outline_r_w.x - 20) + min;
			long double val = math::round_to_increment<long double>(nr_val, inc);
			if (min <= val && max >= val) setting->force_set_any(setting->value, val);
		}
	}

	std::string value_rep;
	long double d = setting->force_any(setting->value);
	long double perc = d / setting->force_any(setting->max);
	if (d == std::floor(d)) {
		value_rep = std::to_string((long long) d);
		if (setting->type >= num::F) value_rep += ".0";
	} else {
		value_rep = std::to_string(d);
	}

	render::rect(whiteout.window, sf::Vector2f(pos.x - 5, pos.y + 2.5f), sf::Vector2f((outline_r_w.x - 20) * perc, font::height()), Module::mdcc[setting->parent->category]);
	font::render(whiteout.window, setting->name, pos);
	font::render(whiteout.window, value_rep, sf::Vector2f(pos.x + outline_r_w.x - 20 - 10 - font::width(value_rep), pos.y));

	height += font::height() + 5;
}

bool DrawableNumber::on_event(const Key key) {
	if (bounds_contain(key, setting)) {
		if (key.keycode == 1) {
			dragging = true;
		} else if (key.keycode == 3) {
			dragging = false;
		}
		return true;
	}
	return false;
}