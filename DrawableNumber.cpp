#include "DrawableNumber.h"

DrawableNumber::DrawableNumber(const sf::Vector2f position, const setting::Type type, NumberSetting* setting, Whiteout& whiteout) : DrawableSetting(position, type, whiteout), setting(setting) { }

void DrawableNumber::draw(float& height, sf::Vector2f outline_r_w) {
	if (!setting->dependency()) return;
	font::render(whiteout.window, setting->name, pos);

	height += font::height() + 5;
}

bool DrawableNumber::on_event(const Key key) {
	return false;
}