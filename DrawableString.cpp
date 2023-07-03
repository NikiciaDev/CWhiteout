#include "DrawableString.h"

DrawableString::DrawableString(const sf::Vector2f position, const setting::Type type, StringSetting* setting, Whiteout& whiteout) : DrawableSetting(position, type, whiteout), setting(setting) {}

void DrawableString::draw(float& height, sf::Vector2f outline_r_w) {
	std::string render_s(setting->name);
	if (!setting->gv<std::string>().empty()) {
		render_s = setting->gv<std::string>();
	}
	font::render(whiteout.window, render_s, pos);
}

bool DrawableString::on_event(const Key key) {
	return false;
}