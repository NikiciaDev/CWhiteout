#include "DrawableMode.h"

DrawableMode::DrawableMode(const sf::Vector2f position, const setting::Type type, ModeSetting* setting, Whiteout& whiteout) : DrawableSetting(position, type, whiteout), setting(setting) {}

void DrawableMode::draw(float& height, sf::Vector2f outline_r_w) {
	if (!setting->dependency()) return;

	font::render(whiteout.window, setting->name, pos);
	font::render(whiteout.window, setting->gv<std::string>(), sf::Vector2f(pos.x + outline_r_w.x - 20 - 10 - font::width(setting->gv<std::string>()), pos.y));
	height += font::height() + 5;
}

bool DrawableMode::on_event(const Key key, const mdl::MODULE_CATEGORY current) {
	return false;
}