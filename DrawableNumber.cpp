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
		long double nr_val{ 0 }, val{ 0 };
		sf::Vector2i mp(liu::get_cursor_pos(true));
		mp.x += 10; // Idk why this is needed its retared.
		if (mp.x <= pos.x) {
			val = min;
			dragging = false;
		}if (mp.x >= pos.x + outline_r_w.x - 20 + 5) {
			val = max;
			dragging = false;
		}if (mp.y < pos.y + 2.5f - 5 || mp.y > pos.y + font::height() + 5) {
			dragging = false;
		} else {
			nr_val = (mp.x - pos.x - 5.0) / (outline_r_w.x - 20.0) * (max - min) + min;
			if (val == 0) val = math::round_to_increment<long double>(nr_val, inc);
			if (min <= val && max >= val) setting->force_set_any(setting->value, val);
		}
	}

	std::string value_rep;
	long double c_val = setting->force_any(setting->value);
	float p = (outline_r_w.x - 20) / (max - min);
	float bar_width = p * c_val - p * min;

	if (c_val == std::floor(c_val)) {
		value_rep = std::to_string((long long) c_val);
		if (setting->type >= num::F) value_rep += ".0";
	} else {
		value_rep = std::to_string(c_val);
		if (value_rep.find('.') != std::string::npos) {
			value_rep = value_rep.substr(0, value_rep.find_last_not_of('0') + 1);
			if (value_rep.find('.') == value_rep.size() - 1) {
				value_rep = value_rep.substr(0, value_rep.size() - 1);
			}
		}
	}

	render::rect(whiteout.window, sf::Vector2f(pos.x - 5, pos.y + 2.5f), sf::Vector2f(bar_width, font::height()), mdcc(setting->parent->category));
	font::render(whiteout.window, setting->name, pos);
	font::render(whiteout.window, value_rep, sf::Vector2f(pos.x + outline_r_w.x - 20 - 10 - font::width(value_rep), pos.y));

	height += font::height() + 5;
}

bool DrawableNumber::on_event(const Key key, const mdl::MODULE_CATEGORY current) {
	if (bounds_contain(key, setting, current)) {
		if (key.keycode == 1) {
			dragging = true;
		} else if (key.keycode == 3) {
			dragging = false;
		}
		return true;
	}
	return false;
}