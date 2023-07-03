#include "DrawableMode.h"

DrawableMode::DrawableMode(const sf::Vector2f position, const setting::Type type, ModeSetting* setting, Whiteout& whiteout) : DrawableSetting(position, type, whiteout), setting(setting) {}

void DrawableMode::draw(float& height, sf::Vector2f outline_r_w) {
	if (!setting->dependency()) return;
	this->outline_r_w = outline_r_w;

	font::render(whiteout.window, setting->name, pos);
	font::render(whiteout.window, setting->options[setting->gv<unsigned short>()], sf::Vector2f(pos.x + outline_r_w.x - 20 - 10 - font::width(setting->options[setting->gv<unsigned short>()]), pos.y));
	height += font::height() + 5;
}

bool DrawableMode::on_event(const Key key, const mdl::MODULE_CATEGORY current) {
	if (bounds_contain(key, setting, current)) {
		if (key.keycode == 3) return true;
		if (key.keycode == 1) {
			if (setting->gv<unsigned short>() >= setting->options.size() - 1) {
				setting->sv((unsigned short) 0);
			} else {
				setting->sv((unsigned short) (setting->gv<unsigned short>() + 1));
			}
		} else {
			if (setting->gv<unsigned short>() > 0) {
				setting->sv((unsigned short) (setting->gv<unsigned short>() - 1));
			} else {
				setting->sv((unsigned short) (setting->options.size() - 1));
			}
		}
		return true;
	}
	return false;
}