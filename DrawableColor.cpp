#include "DrawableColor.h"

DrawableColor::DrawableColor(const sf::Vector2f position, ColorSetting* setting, Whiteout& whiteout) : DrawableSetting(position, whiteout), setting(setting) {}

float DrawableColor::draw() {
	return 0;
}

bool DrawableColor::on_event(const Key key) {
	return false;
}