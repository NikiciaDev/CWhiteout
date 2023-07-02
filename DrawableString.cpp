#include "DrawableString.h"

DrawableString::DrawableString(const sf::Vector2f position, StringSetting* setting, Whiteout& whiteout) : DrawableSetting(position, whiteout), setting(setting) {}

float DrawableString::draw() {
	return 0;
}

bool DrawableString::on_event(const Key key) {
	return false;
}